//
//  WTA.cpp
//  qparse
//
//  Created by Florent Jacquemard on 04/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup schemata
/// @{


#include "WTA.hpp"
#include "FloatWeight.hpp"
#include "ViterbiWeight.hpp"
#include "TropicalWeight.hpp"
#include "CountingWeight.hpp"


TransitionList::~TransitionList()
{
    clear();
}


bool TransitionList::empty() const
{
    return (_table.empty());
}


size_t TransitionList::size() const
{
    return _table.size();
}


void TransitionList::add(const Transition& t)
{
    assert(t.inner() || t.terminal());
    _table.push_back(t);
    _cpt_size += t.arity() + 1;
    
    assert (_parent);
    _parent->_cpt_tr++;
    _parent->_cpt_size += (t.arity() + 1);
}


void TransitionList::clear()
{
    //for(vector<Transition*>::iterator i = _table.begin(); i != _table.end(); ++i)
    //    delete *i;
    
    _table.clear();
}


TransitionList_iterator TransitionList::remove(TransitionList_iterator i)
{
    _cpt_size -= ((*i).size() + 1);
    return _table.erase(i);
}


void TransitionList::remove(state_t s)
{
    assert (! State::isMeta(s));
    
    TransitionList_iterator i = _table.begin();
    while(i != _table.end())
    {
        TRACE("DebugInsideFor");
        Transition& t = *i;
        // we do not remove transition to terminal symbols
        if (t.inner() && (t.member(s)))
        {
            _cpt_size -= (t.size() + 1);
            TRACE("DebugBeforeTableErase state={}, transition={}", s, t);
            // remove transition from vector (destructor called)
            i = _table.erase(i); // C++11
            TRACE("DebugAfterTableErase");
        }
        else
        {
            ++i;
        }
    }
}


//nullary constructor for cython
WTA::WTA()
{}


// empty automaton
WTA::WTA(Weight seed, pre_t pre, pre_t post):
_max_pre(pre),
_max_post(post),
_next_id(0),
_cpt_tr(0),
_cpt_size(0),
_seed(seed)
{
    assert (! seed.unknown());
}


WTA::~WTA()
{
    TRACE("clear  WTA transition table (size={})", _table.size());
    
    for (std::map<state_t,TransitionList>::iterator i = _table.begin();
         i != _table.end(); ++i)
    {
        TransitionList& tl = i->second;
        tl.clear();
    }
    // TBC destroy the TransitionList contents?
    _table.clear();
}


size_t WTA::size() const
{
    return _table.size();
}


bool WTA::empty() const
{
    return _table.empty();
}


bool WTA::isRegistered(state_t s) const
{
    assert (! State::isMeta(s));
    
    return (_table.count(s) > 0);
}


bool WTA::isInitial(state_t s) const
{
    return (s == _initial);
    //    return (initials.count(s));
}


TransitionList& WTA::add(state_t s, bool initial)
{
    assert (! State::isMeta(s));
    
    // _table[s]:
    // if there is an entry for s, return it
    // if there is no entry for s, one is created with empty transition list
    // (see stl::map)
    TransitionList& tl = _table[s];
    tl._parent = this;
    if (initial)
    {
        _initial = s;
        initials.insert(s);
    }
    
    return(tl);
}


TransitionList& WTA::add(state_t s, const Transition& t, bool initial)
{
    assert(t.inner() || t.terminal());
    // updates the counters _cpt_tr and _cpt_size
    TransitionList& tl = add(s, initial);
    tl.add(t);
    return tl;
}


void WTA::remove(state_t s)
{
    assert (! State::isMeta(s));
    TRACE("remove from WTA all transitions containing state {}", s);
    
    size_t s_nb = 0;   // number of transitions headed to s
    size_t s_size = 0; // sum of sizes of transitions headed to s
    
    // first traversal transition map:
    // to remove transition with s occurring in body
    // and to update size counters
    std::map<state_t, TransitionList>::iterator i = _table.begin();
    
    while (i != _table.end())
    {
        state_t q = i->first;
        TransitionList& tl = i->second;
        
        // list of transitions headed to s
        // remove the whole list (table entry)
        // save for later the sizes of the TransitionList with head s
        if (q == s)
        {
            s_nb = tl.size();
            s_size = tl.fullsize();
            TRACE("remove from WTA all transitions headed with {}", q);
            i = _table.erase(i); // C++11
        }
        // delete the transitions containing s in the TransitionList of q
        else
        {
            TRACE("DebugInsideElse");
            _cpt_tr -= tl.size();
            _cpt_size -= tl.fullsize();
            TRACE("remove from WTA all transitions with {} in body", s);
            tl.remove(s);
            TRACE("DebugAfterTvRemove");
            _cpt_tr += tl.size();
            _cpt_size += tl.fullsize();
         
            // all transitions in the list have been removed
            if (tl.empty())
            {
                i = _table.erase(i); // C++11
            }
            else
            {
                ++i;
            }
        }
    }
    
    // the elements removed are destroyed,
    // destructor of transition list of s is called
    // _table.erase(s);  // should not be present
    _cpt_tr -= s_nb;
    _cpt_size -= s_size;
    
    initials.erase(s);
}


TransitionList_const_iterator WTA::cbegin(state_t s) const
{
    assert (! State::isMeta(s));
    
    std::map<state_t,TransitionList>::const_iterator it = _table.find(s);
    assert(it != _table.end());
    return it->second.cbegin();
}

TransitionList_const_iterator WTA::cend(state_t s) const
{
    assert (! State::isMeta(s));
    
    std::map<state_t,TransitionList>::const_iterator it = _table.find(s);
    assert(it != _table.end());
    return it->second.cend();
}


size_t WTA::countStates() const
{
    return _table.size();
}


size_t WTA::countTransitions() const
{
    return _cpt_tr;
}


size_t WTA::countAll() const
{
    return _cpt_size;
}


size_t WTA::oftarget(state_t s) const
{
    assert (! State::isMeta(s));
    
    std::map<state_t,TransitionList>::const_iterator it = _table.find(s);
//    assert(it != _table.end());
    return (it->second.size());
}


//Transition* WTA::at(state_t s, size_t i) const
//{
//    map<state_t,TransitionList>::const_iterator it = _table.find(s);
//    assert(it != _table.end());
//    assert(i < it->second.size());
//    return (it->second.at(i));
//}


size_t gcd(size_t a, size_t b)
{
    if( b == 0 )
        return a;
    return gcd(b, a%b);
}


size_t lcm(size_t a, size_t b)
{
    return a*b / gcd(a,b);
}


// over approx.
// could be optimized
size_t WTA::resolution() const
{
    // start with copy of initial state set
    std::set<state_t>* from = new std::set<state_t>(initials);
    // initialy empty
    std::set<state_t>* reach = new std::set<state_t>();
    
    size_t res = 1;
    
    while (! from->empty())
    {
        size_t res1 = 1;
        // for all state in reached set
        for (std::set<state_t>::iterator is = from->begin();
             is != from->end(); ++is)
        {
            state_t s = *is;
            // for all transition headed by the current state
            for (TransitionList_const_iterator it = cbegin(s);
                 it != cend(s); ++it)
            {
                const Transition& t = *it;
                size_t a = t.arity();
                if (t.inner()) // exclude leaf transitions (to terminal symbol)
                {
                    res1 = lcm(res1, a);
                    // add states in the body of the transition to reach set
                    for (Transition_const_iterator i = t.cbegin();
                         i != t.cend(); i++)
                        reach->insert(*i);
                }
            }
        }
        std::set<state_t>* aux = from;
        from = reach;
        reach = aux;
        reach->clear();
        res *= res1;
    }
    delete from;
    delete reach;
    return res;
}


std::set<state_t> WTA::step(const std::set<state_t>& sin)
{
    std::set<state_t> sout; // empty set
    assert (sout.empty());
    // for all state in given set
    for (state_t s : sin)
        //for (set<state_t>::iterator is = sin.begin(); is != sin.end(); ++is)
    {
        //state_t s = *is;
        // for all transition headed by the current state
        for (TransitionList_const_iterator it = cbegin(s); it != cend(s); ++it)
        {
            const Transition& t = *it;
            if (t.inner()) // exclude leaf transition (to terminal symbol)
            {
                // for all state in the body of the transition
                for (Transition_const_iterator i = t.cbegin();
                     i != t.cend(); i++)
                    sout.insert(*i);
            }
        }
    }
    return sout;
}


//set of all states occuring in wta (in head or body)
//exclude terminal symcols of terminal (leaf) transitions
std::set<state_t> WTA::allStates() const
{
    std::set<state_t> res;
    
    for (std::map<state_t, TransitionList>::const_iterator i = _table.cbegin();
         i != _table.end(); ++i)
    {
        
        res.insert(i->first);
        for (TransitionList_const_iterator it = (i->second).cbegin();
             it != (i->second).cend(); ++it)
        {
            const Transition& t = *it;
            if (t.inner())
            {
                for (Transition_const_iterator is = t.cbegin();
                     is != t.cend(); is++)
                    res.insert(*is);
            }
        }
    }
    
    return res;
}


// return the set of empty states
std::set<state_t> WTA::emptyStates() const
{
    // first determine the set of empty states
    std::set<state_t> empty = allStates();
   
    bool change = true;
    while(change)
    {
        change = false;
        // for all state s
        for (std::map<state_t,TransitionList>::const_iterator i = _table.cbegin();
             i != _table.end(); ++i)
        {
            state_t s = i->first;
            // the state is already marked nonempty
            if (empty.count(s) == 0) continue;
            // otherwise try to mark s
            // for all transition headed by s
            for (TransitionList_const_iterator it = (i->second).cbegin();
                 it != (i->second).cend(); ++it)
            {
                const Transition& t = *it;
                // transition from terminal symbol or from a body of all nonempty states
                if ((t.terminal()) || (t.nonein(empty)))
                {
                    empty.erase(s); // in this case s is not empty
                    change = true;
                }
            }
        }
    }
    
    return empty;
}


bool WTA::isClean() const
{
    std::set<state_t> empty = emptyStates();

    return empty.empty();
}


void WTA::clean()
{
    // compute the set of empty states
    TRACE("Debug3");
    std::set<state_t> empty = emptyStates();
    TRACE("Debug4");
    // erase empty states
    for (state_t s : empty){
        TRACE("Debug removing states");
        remove(s);
    //    for (std::set<state_t>::iterator i = empty.begin();
    //         i != empty.end(); ++i)
    //        remove(*i);
    }
    TRACE("Debug5allremoved");

}


// TBR
void WTA::abstract(bool flag)
{
    for (std::map<state_t,TransitionList>::iterator i = _table.begin();
         i != _table.end(); ++i)
    {
        state_t s = i->first;
        TransitionList& tl = i->second;
        
        if (tl.empty())
        {
            break;
        }
        
        Weight w;
        state_t label = 0;
        double sum = 0;  // @todo USE SUM OP OF SEMIRING
        bool visited = false;
        
        // compute sum of weights of transitions to leaf values >= MAX_GRACE
        // remove transitions to leaf values > MAX_GRACE
        // tmax points to the transition of leaf value == MAX_GRACE
        TransitionList_iterator j = tl.begin();
        while (j != tl.end())
        {
            if (j->terminal() &&
                (Label::nbEvents((*j).label()) >= CST_MAX_GRACE))
            {
                if (flag)
                {
                    sum += j->weight().norm();
                }
                else
                {
                    j->invert();
                    sum += j->weight().norm();
                }
                
                if ((Label::nbEvents(j->label()) == CST_MAX_GRACE) &&
                    (! visited))
                {
                    w = j->weight(); // copy
                    label = j->label();
                    visited = true;
                }

                tl.remove(j);
            }
            else
            {
                ++j;
            }
        }

        if (visited)
        {
            Transition newt = w.make(sum);
            if (! flag) { newt.invert(); }
            tl.add(newt);
        }
    }
}


void WTA::CountingtoStochastic()
{
    assert (hasWeightType("FloatWeight"));
    Weight newseed = ViterbiWeight::make_zero();
    
    // for all state
    for (std::map<state_t,TransitionList>::iterator i = _table.begin();
         i != _table.end(); ++i)
    {
        state_t s = i->first;
        TransitionList& tl = i->second;
        TRACE("cast Counting-Stochastic: state {} ({}  transitions).",
              s, tl.size());
        
        // TBC : float sum ?
        // Weight sum = _seed.get_zero(); // 0 of FloatWeights
        // assert (sum.hasType("FloatWeight"));
        double sum = 0;
        
        // compute sum of weights
        // weight of first transition
        for (TransitionList_iterator j = tl.begin(); j != tl.end(); ++j)
        {
            sum += j->weight().norm();
        }
        
        double d;

        //assert (sum.hasType("FloatWeight"));
        if (sum == 0) //(sum.zero())
        {
            WARN("cast Counting-Stochastic: state {}, sum=0", s);
            d = sum;
        }
        else
        {
            d = 1/sum; // sum.invert();
        }
        // float d = sum.norm();
        
        for (TransitionList_iterator j = tl.begin(); j != tl.end(); ++j)
        {
            j->setWeight(newseed.make((*j).weight().norm() * d));
        }
    }
    
    _seed = newseed;
    assert(_seed.hasType("ViterbiWeight"));
}


void WTA::CountingtoPenalty()
{
    CountingtoStochastic();
    StochastictoPenalty();
}


void WTA::PenaltytoCounting()
{
    assert (hasWeightType("TropicalWeight"));
    Weight newseed = FloatWeight::make_zero();
    
    // for all state
    for (std::map<state_t,TransitionList>::iterator i = _table.begin();
         i != _table.end(); ++i)
    {
        state_t s = i->first;
        TransitionList& tl = i->second;

        TRACE("cast Penalty-Counting: state {} ({}  transitions).",
              s, tl.size());
        
        // for all transition heading to state
        for (TransitionList_iterator j = tl.begin(); j != tl.end(); ++j)
        {
            float v = (*j).weight().norm();
            if (v == 0)
            {
                WARN("cast Penalty-Counting: state {}, tr. with weight=0", s);
                j->setWeight(newseed.get_zero());
            }
            else
            {
                j->setWeight(newseed.make(1/v));
            }
            
            assert (j->weight().hasType("FloatWeight"));
        }
    }
    _seed = newseed;
    assert(_seed.hasType("FloatWeight"));
}


void WTA::StochastictoPenalty()
{
    assert (hasWeightType("ViterbiWeight"));
    Weight newseed = TropicalWeight::make_zero();
    
    // for all state
    for (std::map<state_t,TransitionList>::iterator i = _table.begin();
         i != _table.end(); ++i)
    {
        state_t s = i->first;
        TransitionList& tl = i->second;
        
        TRACE("cast Stochastic-Penalty: state {} ({}  transitions).",
              s, tl.size());
        
        for (TransitionList_iterator j = tl.begin(); j != tl.end(); ++j)
        {
            float v = j->weight().norm();
            assert(0 <= v);
            assert(v <= 1);
            if (v == 0)
            {
                WARN("cast Stochastic-Penalty: state {}, tr. with weight=0", s);
                j->setWeight(newseed.get_zero());
            }
//            else if (v == 1)
//            {
//                j->setWeight(newseed.make(0.00000000000001));
//            }
            else
            {
                j->setWeight(newseed.make(- log10(v)));
            }
            
            assert (j->weight().hasType("TropicalWeight"));
        }
    }
    _seed = newseed;
    assert(_seed.hasType("TropicalWeight"));
}


bool WTA::hasWeightType(std::string code) const
{
    return _seed.hasType(code);
}


Weight WTA::weight_zero() const
{
    assert (! _seed.unknown());
    return _seed.get_zero();
}


Weight WTA::weight_one() const
{
    assert (! _seed.unknown());
    return _seed.get_one();
}


Weight WTA::eval(const RhythmTree& t) const
{
    return eval(t, _initial);
}


// TBC factor ALPHA ?
Weight WTA::eval(const RhythmTree& t, state_t s) const
{
    assert (! State::isMeta(s));    
    
    size_t tar = t.arity();
    // convention: empty sum is zero
    Weight res = weight_zero();

    //TRACE("WTA::eval {}", t);

    // enumeration of transitions of target s
    for (TransitionList_const_iterator i = cbegin(s); i != cend(s); ++i)
    {
        Weight  w = i->weight();
        
        if (i->arity() == tar)
        {
            // TBC treatment of grace-note (arb. number)
            if (i->terminal() && Label::abstract(i->label(), t.label()))
            //if ((*i).terminal() && (i->label() == t.label()))
            {
                res += w;
            }
            else if (i->inner())
            {
                for (size_t j = 0; j < tar; j++)
                {
                    w *= eval(*(t.child(j)), i->at(j));
                }
                res += w;
            }
        }
    }
    
    return res;
}


std::ostream& operator<<(std::ostream& o, const WTA& a)
{
    for (std::map<state_t,TransitionList>::const_iterator i = a._table.begin();
         i != a._table.end(); ++i)
    {
        state_t s = i->first;
        TransitionList tl = i->second;
        for(TransitionList_const_iterator j = tl.cbegin(); j != tl.cend(); j++)
        {
            const Transition& t = *j;
            o << s << " -> " << t << " \n";
        }
    }
    return o;
}


void WTA::print(std::ostream& o) const
{
    o << '\n';
    o << this->countStates() << " states\n";
    o << this->countTransitions() << " transitions\n";
    o << this->countAll() << " total symbols\n\n";
    //o << *this;
}


void DepthMarking::mark_rec(state_t s, int d, const WTA& wta)
{
    assert (d >= 0);
    mark(s, d);
    
    // enumerate the transitions pointing to state s
    for (TransitionList_const_iterator i = wta.cbegin(s);
         i != wta.cend(s);
         i++)
    {
        // enumerate the states in the body of the current transition
        for (Transition_const_iterator j = i->cbegin();
             j != i->cend();
             j++)
        {
            // recursive marking
            mark_rec(*j, d+1, wta);
        }
    }
}


DepthMarking::DepthMarking(const WTA& wta)
{
    mark_rec(wta.initial(), 0, wta);
}


int DepthMarking::depth(state_t s) const
{
    std::map<state_t, int>::const_iterator it = _marks.find(s);
    
    if (it != _marks.end()) // found
    {
        assert (it->second >= 0);
        return it->second;
    }
    else
    {
        return -1;
    }
}


bool DepthMarking::multiple(state_t s) const
{
    std::map<state_t, bool>::const_iterator it = _multi.find(s);
    
    if (it != _multi.end()) // found
    {
        return it->second;
    }
    else
    {
        return false;
    }
}


int DepthMarking::mark(state_t s, int d)
{
    assert (d >= 0);
    std::pair<std::map<state_t,int>::iterator, bool> ret;
    
    // if s not marked, just add its mark
    // if s already marked, ret.first contains a iterator to mark
    ret = _marks.insert(std::pair<state_t,int>(s, d));
    
    // s already marked (found)
    if (ret.second == false)
    {
        // stored depth
        int ds = ret.first->second;
        
        assert (ds >= 0);
        if (ds == d)
        {
            // do nothing, keep depth value
            return d;
        }
        else
        {
            int max = std::max(d, ds);
            
            _multi[s] = true;
            if (ds > d)
            {
                // insert the max value in place of the old value
                _marks.insert(ret.first, std::pair<state_t,int>(s, max));
                return ds;
            }
            else
            {
                // keep the same value stored
                return d;
            }
        }
    }
    // s had not been marked before
    else
    {
        return d;
    }
}


/// @}
