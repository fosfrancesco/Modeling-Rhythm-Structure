//
//  PtrSIP.cpp
//  qparse
//
//  Created by Florent Jacquemard on 05/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{


#include "PtrSIP.hpp"


SIPpointer::SIPpointer(pre_t pre, pre_t post):
SIpointer(),
_pre(pre),
_post(post)
{ }


// TBC conversion of label type into state
SIPpointer::SIPpointer(label_t s):
SIpointer(s),
_pre(PP_UNKNOWN),
_post(PP_UNKNOWN)
{ }


// top - specific version
// @todo align node when needed (flag?)
SIPpointer::SIPpointer(Environment* env,
                       state_t s,
                       pre_t pre,
                       pre_t post,
                       Rational mdur,
                       double rext):
SIpointer(env, s, mdur,rext),
_pre(pre),
_post(post)  // default //_post(PP_UNKNOWN)
{
    // top pre value must be set (no way to infer it otherwise)
    assert(PP_KNOWN(pre));
}


// split or back_split
SIPpointer::SIPpointer(Environment* env,
                       const SIPpointer& p,
                       double rdur, Rational mdur,
                       bool position,
                       size_t i,
                       state_t s):
SIpointer(env, p, rdur, mdur, position, i, s) 
{
    // node is set in SIpointer cstr
    
    // propagation parent-child of pre/post values
    if (i == 1)
    {
        _pre = p._pre;
        _post = PP_UNKNOWN;
    }
    else
    {
        assert(i == 2);
        _pre = PP_UNKNOWN;
        _post = p._post;
    }
}


// for construction of inside-the-beat runs
// split (in a parts, for building inner Run of terget p)
// or instance as leaf (of p)
// see conditions in Ptr.hpp
SIPpointer::SIPpointer(Environment* env,
                       const SIPpointer& p,
                       size_t a, size_t i,
                       state_t s):
SIpointer(env, p, a, i, s) // p downcasted
{
    assert(env);
    assert(env->segment);
    assert(env->iheap);
    assert(p._node);
    
    // children
    if (a > 0) // inner
    {
        // node set in SIpointer cstr

        // pre of first
         if (i == 1) _pre = p._pre;
         else _pre = PP_UNKNOWN;

         // post of last
         if (i == a) _post = p._post;
          else _post = PP_UNKNOWN;
    }
    // copy and instanciate as leaf
    else // a == 0, instance as leaf. complete the ptr
    {
        assert(i == 0);
        assert(State::isLabel(s));
        assert(p.partial());
        //assert(p.compatible(s)); // s can be abstract or concrete

        // state, node set in SIpointer cstr

        // we cannot instanciate into complete ptr if _pre not set
        assert(PP_KNOWN(p._pre));
        _pre = p._pre;
        if (PP_KNOWN(p._post))
        {
            ERROR("PtrSIP : instance as leaf of complete ptr {}", p);
            assert(p._post == _node->rsize());
            _post = p._post;
        }
        else
        {
            _post = _node->rsize();
        }
    }
}


// state, node set in SIpointer cstr
SIPpointer::SIPpointer(const SIPpointer& p):
SIpointer(p),   // downcast p
_pre(p._pre),
_post(p._post)
{ }


// update (instanciate) pre and post
// the interval is unchanged
// state, node set in SIpointer cstr
SIPpointer::SIPpointer(const SIPpointer& p,
                       const SIPpointer& p0,
                       const SIPpointer& p1):
SIpointer(p, p0, p1)  // TBC fail if p, p0, p1 downcasted
{
    assert(p.partial());
    assert(p0.complete());
    assert(p1.complete());

    assert((p._pre == PP_UNKNOWN) || (p._pre == p0._pre));
    _pre = p0._pre;

    assert((p._post == PP_UNKNOWN) || (p._post == p1._post));
    _post = p1._post;
}


// state, node set in SIpointer cstr
SIPpointer::SIPpointer(const SIPpointer& p0,
                       const SIPpointer& p1):
SIpointer(p0, p1),
_post(p1._post)
{
    assert(p0.complete());
    assert(p1.partial());
    // p1 can be instanciated as the next sibling of p0.
    assert((p1._pre == PP_UNKNOWN) || (p1._pre == p0._post));
    _pre = p0._post;
}


SIPpointer& SIPpointer::operator= (const SIPpointer& p)
{
    if(this != &p)
    {
        _state = p._state;
        _node  = p._node;  // no clone, we share ptrs to intervals
        _pre   = p._pre;
        _post  = p._post;
    };
    return *this;
}


bool SIPpointer::operator==(const SIPpointer& p) const
{            
    return ((_state == p._state) &&
            (_pre == p._pre) &&
            (_post == p._post) &&
            this->equal_node(p));
}


bool SIPpointer::operator!=(const SIPpointer& p) const
{
    return (! (*this == p));
}


bool SIPpointer::operator<(const SIPpointer& p) const
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

    if (_pre < p._pre)
        return true;
    else if (_pre > p._pre)
        return false;
    // _pre == p._pre
    if (_post < p._post)
        return true;
    else if (_post > p._post)
        return false;
    // _post == p._post
    
    // equality
    return false;
}


// this is instance of p
bool SIPpointer::instance(const SIPpointer& p) const
{
    if (p.complete())
    {
        return (*this == p);
    }
    else
    {
        // it is not a fake ptr containing only label
        assert(_node);
        assert(p._node);
        return ((p._state == _state) &&
                ((p._pre == PP_UNKNOWN) || (p._pre == _pre)) &&
                ((p._post == PP_UNKNOWN) || (p._post == _post)) &&
                equal_node(p));
    }
}


bool SIPpointer::subsume(const SIPpointer& p) const
{
    return p.instance(*this);
}


bool SIPpointer::complete() const
{
    return ((_node == NULL) // case of fake ptr containing only label
            ||
            (PP_KNOWN(_pre) && PP_KNOWN(_post)));
}


label_t SIPpointer::label(const Transition& t) const
{
    assert(PP_KNOWN(_pre));
    assert(_node);
    
    label_t clabel = _pre + _node->lsize();
    assert(compatible(clabel, false));

    return (clabel);
}


// can be instanciated into pre-post values compatible with the label
bool SIPpointer::compatible(const label_t label, bool abstract) const
{
    assert(_node);
    assert(_node->aligned());

    // condition for post
    // _post contain concrete value
    if ((_post != PP_UNKNOWN) && (_post != _node->rsize()))
        return false;
    
    // if label is a continuation (tie):
    // there must be no point aligned to the left (of this Interval)
    // rem: no distinction between abstract or concrete value for continuation.
    if (Label::continuation(label))
    {
        if ((_pre != PP_UNKNOWN) && (_pre != 0))
            return false;
        else
            return (_node->lsize() == 0);
    }
    // if label contains note and grace notes (no continuation):
    // the label must be consistent with
    // the info in guess (# grace notes)
    else
    {
        if (abstract)
        {
            if (_pre == PP_UNKNOWN)
                // exists pre such that label abstract _node->lsize() + pre
                return (Label::leqabstract(label, _node->lsize()));
            else
                return Label::abstract(label, _pre + _node->lsize());
        }
        else
        {
            if (_pre == PP_UNKNOWN)
                // exists pre such that label = _node->lsize() + pre
                return (_node->lsize() <= label);
            else
                return label == (_pre + _node->lsize());
        }
    }
}


bool SIPpointer::dummy() const
{
    return ((_state == State::MetaState(1)) &&
            (_node == NULL) &&
            (_pre == PP_UNKNOWN) &&
            (_post == PP_UNKNOWN));
}


// @todo TBC
Weight SIPpointer::terminalWeight(const InputSegment* s,
                                  const Transition& tr) const
{
    assert(s);
    assert(! tr.weight().unknown());
    assert(tr.terminal());
    assert(this->compatible(tr.label()));
    //  return (tr.weight().get_one()); // neutral element for *
    
    // tweight = transition weight = complexity
    Weight tweight = tr.weight();
    assert (! tweight.unknown());
    assert(CST_WEIGHT_TYPE == WeightDom::STOCHASTIC ||
           CST_WEIGHT_TYPE == WeightDom::PENALTY);
    
    // QP_WEIGHT == WEIGHT_STOCHASTIC
    if ( CST_WEIGHT_TYPE == WeightDom::STOCHASTIC )
    {
        assert (tweight.hasType("ViterbiWeight"));
        // this pointer maybe partial but pre must be known
        assert(PP_KNOWN(_pre));
        assert(_node);
        // already checkd in compatibler
        assert((_post == PP_UNKNOWN) || (_post == _node->rsize()));
        tweight *= Weight(new PerfoWeight(s, _node, _pre, _node->rsize()));
    }
    // QP_WEIGHT == WEIGHT_PENALTY
    else if ( CST_WEIGHT_TYPE == WeightDom::PENALTY )
    {
        assert (tweight.hasType("TropicalWeight"));
        assert(_node);
        
        // ALPHA applied to dist only (not complexity)
        // compute distance to input segment
        Weight dist = Weight(new Distance(s, _node));
        TRACE("terminal weight for {} tr={} dist={}", *(this), tr, dist);
        // new transition weight =
        // (1 - alpha) * former transition weight + alpha * distance
        tweight *= dist; // tropical weight product is a sum
    }
    else
    {
        ERROR("PtrSIP: unxepected weight type");
    }
    
    return tweight;
}


std::ostream& operator<<(std::ostream& o, const SIPpointer& p)
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
    o << (PP_KNOWN(p._pre)?std::to_string(p._pre):"_") << ", ";
    o << (PP_KNOWN(p._post)?std::to_string(p._post):"_");
    o << PTR_RPAR;

    return o;
}


/// @}
