//
//  PtrSI.cpp
//  squant
//
//  Created by Florent Jacquemard on 19/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{


#include "PtrSI.hpp"


SIpointer::SIpointer():
Spointer(State::MetaState(1)),
_node(NULL)
{ }


// TBC conversion of label type into state
SIpointer::SIpointer(label_t s):
Spointer(s),
_node(NULL)
{ }


// top - specific version
// @todo align node when needed (flag?)
SIpointer::SIpointer(Environment* env,
                     state_t s,
                     Rational mdur,
                     double rext):
Spointer(s),
_node(env->iheap->make(env->segment, mdur, rext))
{
    assert(env);
    assert(env->segment);
    assert(env->iheap);
    assert(rext >= 0);
    assert(_node);
}


// split or back_split
SIpointer::SIpointer(Environment* env,
                     const SIpointer& p,
                     double rdur, Rational mdur,
                     bool position,
                     size_t i,
                     state_t s):
Spointer(s)
{
    assert(env);
    assert(env->segment);
    assert(env->iheap);
    assert(p._node);
    // assert(rdur > 0);
    // assert(mdur > Rational(0));
    assert((i == 1) || (i == 2));
    
    // back_split / split interval
    if (position)
    {
        _node = p._node->split_back(env->segment, env->iheap, rdur, mdur, i);
    }
    else
    {
        _node = p._node->split(env->segment, env->iheap, rdur, mdur, i);
    }
}


// for construction of top-down runs
// see conditions in Ptr.hpp
SIpointer::SIpointer(Environment* env,
                     const SIpointer& p,
                     size_t a, size_t i,
                     state_t s):
Spointer(s) // assert preconditions of Ptr.hpp
{
    assert(env);
    assert(env->segment);
    assert(env->iheap);
    assert(p._node);
    
    // children
    if (a > 0) // inner
    {
        assert((1 <= i) && (i <= a));
        assert(p.divisible());
        _node = p._node->sub(env->segment, env->iheap, a, i);
    }
    // copy and instanciate as leaf
    // should not be called because SIpointers always complete
    else // a == 0, instance as leaf. complete the ptr
    {
        assert(i == 0);
        assert(State::isLabel(s));
        assert(p.partial());
        //assert(p.compatible(s)); // s can be abstract or concrete
        
        _state = p._state; // copy p (not s)
        _node = p._node;   // no clone (share intervals)
    }
}


SIpointer::SIpointer(const SIpointer& p):
Spointer(p._state),
_node(p._node) // do not clone, share intervals in tree structure.
{ }


// should not be called: all SIpointers are complete
SIpointer::SIpointer(const SIpointer& p,
                     const SIpointer& p0,
                     const SIpointer& p1):
Spointer(p._state),
_node(p._node) // do not clone.
{
    assert(p.partial());
    assert(p0.complete());
    assert(p1.complete());
}


// should not be called: all SIpointers are complete
SIpointer::SIpointer(const SIpointer& p0,
                     const SIpointer& p1):
Spointer(p1._state),
_node(p1._node)
{
    assert(p0.complete());
    assert(p1.partial());
}


SIpointer& SIpointer::operator= (const SIpointer& p)
{
    if(this != &p)
    {
        _state = p._state;
        _node  = p._node;  // no clone
    };
    return *this;
}


bool SIpointer::equal_node(const SIpointer& p) const
{
    if ((_node == NULL) && (p._node == NULL))
        return true;
    
    if ((_node == NULL) || (p._node == NULL))
    {
        return false;
    }
    else // both _node non null
    {
        return ((_node->rbegin == p._node->rbegin) &&
                (_node->rend   == p._node->rend)   &&
                (_node->mbegin == p._node->mbegin)  &&
                (_node->mend   == p._node->mend));
    }
    //  ( *((Interval*) _node) == *((Interval*) p._node)) &&
}


bool SIpointer::operator==(const SIpointer& p) const
{
    return ((_state == p._state) &&
            this->equal_node(p));
}


bool SIpointer::operator!=(const SIpointer& p) const
{
    return (! (*this == p));
}


bool SIpointer::operator<(const SIpointer& p) const
{
    if (_state < p._state)
        return true;
    else if (_state > p._state)
        return false;
    // _state == p._state
    if ((_node == NULL) && (p._node != NULL))
        return true;
    else if ((_node != NULL) && (p._node == NULL))
        return false;
    else if ((_node != NULL) && (p._node != NULL))
    {
        if (_node->rbegin < p._node->rbegin)
            return true;
        else if (_node->rbegin > p._node->rbegin)
            return false;
        else if (_node->rend < p._node->rend)
            return true;
        else if (_node->rend > p._node->rend)
            return false;
        else if (_node->mbegin < p._node->mbegin)
            return true;
        else if (_node->mbegin > p._node->mbegin)
            return false;
        else if (_node->mend < p._node->mend)
            return true;
        else if (_node->mend > p._node->mend)
            return false;
    }
    // _node and p._node both NULL or equal
        
    // equality
    return false;
}


// is equality because all SIpointers are complete
bool SIpointer::instance(const SIpointer& p) const
{
    return ((p._state == _state) && equal_node(p));
}


bool SIpointer::subsume(const SIpointer& p) const
{
    return p.instance(*this);
}


bool SIpointer::complete() const
{
    return true;
}


label_t SIpointer::label(const Transition& t) const
{
    assert(_node);

    // concrete label
    label_t clabel = _node->lsize();
    assert(compatible(clabel, false));
    
    return (clabel);
}


bool SIpointer::divisible() const
{
    if(State::isWTA(_state))
    {
        return ((_node != NULL) && _node->inhabited());
    }
    else
    {
        assert(State::isMeta(_state));
        return ((_node != NULL) && (_node->rduration() > 0));
    }
}


// ptr is a leaf:
// the interval must be set (non null)
// all the points in the interval are aligned to left bound
bool SIpointer::compatible(const label_t label, bool abstract) const
{
    assert(_node);
    assert(_node->aligned());
    
    // condition post == 0
    if (_node->rsize() > 0)
        return false;
    
    // if label is a continuation (tie):
    // there must be no point aligned to the left (of this Interval)
    // rem: no distinction between abstract or concrete value for continuation.
    if (Label::continuation(label))
    {
        return (_node->lsize() == 0);
    }
    // if label contains note and grace notes (no continuation):
    // the label must be consistent with
    // the info in guess (# grace notes)
    else
    {
        if (abstract)
        {
            return Label::abstract(label, _node->lsize());
        }
        else
        {
            return label == _node->lsize();
        }
    }
}


bool SIpointer::dummy() const
{
    return ((_state == State::MetaState(1)) &&
            (_node == NULL));
}


Weight SIpointer::terminalWeight(const InputSegment* s,
                                 const Transition& tr) const
{
    assert(s);
    assert(! tr.weight().unknown());
    assert(tr.terminal());
    assert(this->compatible(tr.label()));
    
    Weight tweight = tr.weight(); // copy
    assert (! tweight.unknown());
    
    assert(CST_WEIGHT_TYPE == WeightDom::STOCHASTIC ||
           CST_WEIGHT_TYPE == WeightDom::PENALTY);
    // QP_WEIGHT == WEIGHT_STOCHASTIC
    if ( CST_WEIGHT_TYPE == WeightDom::STOCHASTIC )
    {
        // tweight = transition weight = complexity
        assert (tweight.hasType("ViterbiWeight"));
        //  pre = post = 0
        tweight *= Weight(new PerfoWeight(s, _node, 0, 0));
    }
    // QP_WEIGHT == WEIGHT_PENALTY
    else if ( CST_WEIGHT_TYPE == WeightDom::PENALTY )
    {
        assert (tweight.hasType("TropicalWeight"));
        assert(_node);
        
        // ALPHA applied to dist only (not to complexity)

        // compute distance to input segment
        Weight dist = Weight(new Distance(s, _node));
        TRACE("terminal weight for {} tr={} dist={}", *(this), tr, dist);
        // new weight =
        // (1 - alpha) . former transition weight * alpha . distance
        tweight *= dist; // tropical weight product is a sum
    }
    else
    {
        ERROR("PtrSI: unxepected weight type");
    }

    return tweight;
}


std::ostream& operator<<(std::ostream& o, const SIpointer& p)
{
    if (p._node == NULL)
    {
        o << PTR_LPAR << p._state << PTR_RPAR;
        return o;
    }
    
    o << PTR_LPAR;
    o << p._state << ", ";
    
    // short version
    if (p._node)
    {
        o << *(p._node) << ", ";
    }
    else
    {
        o << "[], ";
    }
    o << PTR_RPAR;
    
    return o;
}


/// @}
