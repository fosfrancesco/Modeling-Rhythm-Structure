//
//  CountingWTA.cpp
//  schemas
//
//  Created by Florent Jacquemard on 28/11/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup schemata
/// @{


#include "CountingWTA.hpp"



bool trcomp(std::pair<state_t, Transition&> lhs,
            std::pair<state_t, Transition&> rhs)
{
    return lhs.second.id() < rhs.second.id();
}

bool(*CountingWTA::_trcomp_ptr)(std::pair<state_t, Transition&>,
                                std::pair<state_t, Transition&>) = &trcomp;

CountingWTA::CountingWTA() {}

CountingWTA::CountingWTA(const WTA& a):
WTA(a),
_tableids(&trcomp)
{
    size_t dim = this->_cpt_tr; // number of transitions

    // built the ordered table (copy)
    // for all state
    for (std::map<state_t,TransitionList>::iterator i = _table.begin();
         i != _table.end(); ++i)
    {
        // for all transition heading to state
        for (TransitionList_iterator j = i->second.begin();
             j != i->second.end(); ++j)
        {
            state_t s = i->first;
            _tableids.emplace(s, *j);
        }
    }
    assert(_tableids.size() == dim); // double check nb transitions

    resetCounting(dim);
};



void CountingWTA::resetCounting(size_t dim)
{
    TRACE("CoutingWTA::resetCounting dimension = {}", dim);
    
    assert(dim > 0);
    assert(_tableids.size() == dim); // the tableids was built
    size_t cpt = 0;
    
    //Weight newseed = CountingWeight::make_one(dim);
    _seed = CountingWeight::make_one(dim);
    assert(_seed.hasType("CountingWeight"));

    // for all state
    for (OTransitionTable::iterator i = _tableids.begin();
         i != _tableids.end(); ++i)
    {
        assert(cpt < dim);
        i->second.setWeight(CountingWeight::make_unit(dim, cpt));
        cpt++;
    }
}


Weight CountingWTA::eval(const RhythmTree& t) const
{
    assert (this->hasWeightType("CountingWeight"));
    Position p = Position();
    Weight w = evalCountingVerbose(t, _initial, p);
    if (w.zero())
    {
        WARN("FAIL in evaluating tree {}", t);
    }
    
    return (w);

//    CountingWeight* cw = evalCountingVerbose(t, _initial, p);
//    assert (cw);
//    return (Weight(cw));
}


Weight CountingWTA::evalCountingVerbose(const RhythmTree& t,
                                        state_t s,
                                        Position p) const
{
    size_t tar = t.arity();
    Weight res = this->weight_zero();
    assert (! res.unknown());
    assert (res.zero());
    assert (res.hasType("CountingWeight"));
    //TRACE("EVAL t={} p={} state={}", t, p, s);
    
    
    // res.operator->() is res LetterWeight* content
    const CountingWeight* cres =
        dynamic_cast<const CountingWeight*>(res.operator->());
    assert (cres);
    
    // enumeration of transitions of target s
    for (TransitionList_const_iterator i = cbegin(s); i != cend(s); ++i)
    {
        Weight  w = (*i).weight();
        assert (! w.unknown());
        assert (w.hasType("CountingWeight"));
                
        // case inner
        if ((*i).arity() == tar)
        {
            if ((*i).terminal() && ((*i).label() == t.label()))
            {
                res += w;
            }
            else if ((*i).inner())
            {
                for (size_t j = 0; j < tar; j++)
                {
                    w *= evalCountingVerbose(*(t.child(j)), (*i).at(j), (p+j));
                }
                res += w;
            }
        }
    }

    // evaluation failed (no rule appliable)
    if (res.zero())
    {
        WARN("FAIL in tree evaluation state = {} position = {} subtree = {}",
             s, p, t);
    }
    
    return res;
}


std::ostream& operator<<(std::ostream& o, const CountingWTA& a)
{
    for (std::map<state_t,TransitionList>::const_iterator i = a._table.begin();
         i != a._table.end(); ++i)
    {
        state_t s = i->first;
        TransitionList tv = i->second;
        for(TransitionList_const_iterator j = tv.cbegin();
            j != tv.cend(); ++j)
        {
            const Transition& t = *j;
            o << s << " -> " << t << " \n";
        }
    }
    return o;
}


/// @}
