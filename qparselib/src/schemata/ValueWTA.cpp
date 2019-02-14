//
//  ValueWTA.cpp
//  qparse
//
//  Created by Florent Jacquemard on 15/11/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup schemata
/// @{


#include "ValueWTA.hpp"


//ValueState::ValueState():_state(0)
//{
//    _tree = new DurationTree();
//}


ValueState::ValueState(state_t s, DurationTree* t):
_state(s),
_tree(t)
{
    assert(t);
}


ValueState::~ValueState()
{
    // TBC delete _tree externaly to avoid double delete?
    // delete _tree;
}


bool ValueState::compatible(label_t label) const
{
    ValueList vl = this->value();
    return (
            // case of a continuation (tie)
            (Label::continuation(label) &&
             vl.single_continuation())
            ||
            // case of single note (no grace notes, no continuation)
            ((! Label::continuation(label)) &&
             (Label::nbGraceNotes(label) == 0) &&
             vl.single_event())
            ||
            // case of 1 note and grace notes (no continuation)
            ((! Label::continuation(label)) && vl.event() &&
             (Label::nbGraceNotes(label) == vl.nbgn())));
}


bool ValueState::operator==(const ValueState& rhs) const
{
    return ((_state == rhs._state) && (_tree->top == rhs._tree->top));
}


std::ostream& operator<<(std::ostream& o, const ValueState& vs)
{
    o << vs._state << "," << vs._tree->top;
    return o;
}


state_t ValueWTA::addValueState(const ValueState& vs, bool initial)
{
    // value state found in map: value state has been treated already
    Valuemap::const_iterator it = _statemap.find(vs);
    
    if (it != _statemap.end())
    {
        TRACE("old ValueState: {} = state {} (already added)", vs, it->second);
        return it->second;
    }
    
    // otherwise, create new state
    state_t s = _cpt++;
    TRACE("new ValueState {} = {}", s, vs);
    
    // add map of current ComboState to new state
    _statemap[vs] = s;
    //register state
    TransitionList& tv = add(s, initial); // empty vector of Transitions
    
    state_t q = vs.state();               // current state in schema

    // add transitions to new state s
    // vs._tree is the current node in tree of duration lists
    
    // enumerate the transitions to q in schema
    for (TransitionList_const_iterator it = _schema.cbegin(q);
         it != _schema.cend(q); ++it)
    {
        const Transition& t = *it;    // transition of schema
        assert(t.inner() || t.terminal());
        size_t a = t.arity();          //  arity of schema transition

        //const Weight& w = t.weight(); // weight of schema transition
        
        // leaf schema transition:
        // add at most one leaf transition to ValueWTA
        if (t.terminal())
        {
            assert (a == 0);
            // for such transition, the body is a singleton containing a label
            label_t label = t.label();
            
            if (vs.compatible(label))
            {
                TRACE("  {} -> <{}> {} {} {}   compatible,\
                         add terminal tr.",
                      s,
                      label,
                      (vs.value().single_continuation())?"(single cont)":"",
                      (vs.value().single_event())?"(single event)":"",
                      (vs.value().event())?"(event)":"");
                // add terminal transition from (leaf) label to s
                // clone letter weight of schema transition
                Transition newt = Transition(label, t.weight());
                assert(newt.terminal());
                tv.add(newt);
            }
            // otherwise add no transition
            else
            {
                TRACE("  {} -> <{}> {} {} {} incompatible,\
                      ignore terminal tr.",
                      s,
                      label,
                      (vs.value().single_continuation())?"(single cont)":"",
                      (vs.value().single_event())?"(single event)":"",
                      (vs.value().event())?"(event)":"");
            }
        }
        
        // inner schema transition:
        // add one inner transition to ValueWTA
        else if (t.inner() &&
                 (! vs.tree()->top.single_continuation()) &&
                 (! vs.tree()->top.single_event()) &&
                 (! vs.tree()->top.event()))
        {
            assert (a > 1);
            // new transition for ValueWTA
            // clone letter weight of schema transition
            Transition newt = Transition(t.weight());
            for(size_t i = 0; i < a; i++)
            {
                // recursive registration of new ComboState i of transition
                // cannot be initial (@todo AV)
                state_t news = addValueState(ValueState(t.at(i), vs.tree()->sub(a,i)));
                newt.push(news);
            }
            assert(newt.inner());
            assert(newt.size() == a);
            tv.add(newt);
            TRACE("  {} -> {} \
                  add inner tr.",
                  s, newt);
        }
    }
    return s;
}


ValueWTA::ValueWTA(const DurationList& dl, const WTA& schema):
WTA(schema.weight_zero()),
_schema(schema)
{
    _statemap.clear();
    _cpt = 0;
    _tree = new DurationTree(dl);
    
    _initial = addValueState(ValueState(_schema.initial(), _tree), true);
    
    // end of construction
    // destroy tmp tree of duration lists
    delete _tree;
    // destroy all ValueStates
    _statemap.clear();
}


/// @}
