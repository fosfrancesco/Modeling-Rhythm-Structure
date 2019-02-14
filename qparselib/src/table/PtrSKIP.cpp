//
//  PtrSKIP.cpp
//  qparse
//
//  Created by Florent Jacquemard on 14/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{


#include "PtrSKIP.hpp"

SKIPpointer::SKIPpointer():
SIPpointer(),
_rank(1)
{ }


SKIPpointer::SKIPpointer(label_t s, size_t k):
SIPpointer(s),
_rank(k)
{ }


// @todo TBR
SKIPpointer::SKIPpointer(Environment* env,
                         pre_t pre,
                         pre_t post,
                         bool bar,
                         size_t k):
SIPpointer(env, pre, post, bar),
_rank(k)
{
    assert(env);
    assert(k > 0);
}


SKIPpointer::SKIPpointer(Environment* env,
                         state_t s,
                         pre_t pre,
                         pre_t post,
                         Rational mdur,
                         size_t k):
SIPpointer(env, s, pre, post, mdur),
_rank(k)
{
    assert(env);
    assert(k > 0);
}


SKIPpointer::SKIPpointer(Environment* env,
                         const SKIPpointer& p,
                         size_t a, size_t i,
                         state_t s):
SIPpointer(env, p, a, i, s),
_rank(1)
{
    assert(env);
}


SKIPpointer::SKIPpointer(const SKIPpointer& p):
SIPpointer(p),
_rank(p._rank)
{ }


// should not be called: all SKIPpointers are complete
SKIPpointer::SKIPpointer(const SKIPpointer& p0, const SKIPpointer& p1):
SIPpointer(p0, p1),
_rank(p1._rank)
{ }


// should not be called: all Spointers are complete
SKIPpointer::SKIPpointer(const SKIPpointer& p,
                         const SKIPpointer& p0, const SKIPpointer& p1):
SIPpointer(p, p0, p1),
_rank(p._rank)
{ }


SKIPpointer& SKIPpointer::operator= (const SKIPpointer& p)
{
    if(this != &p)
    {
        _state = p._state;
        _node  = p._node;  // no clone, we share ptrs to intervals
        _pre   = p._pre;
        _post  = p._post;
        _rank = p._rank;
    };
    
    return *this;
}

bool SKIPpointer::operator==(const SKIPpointer& p) const
{
    return ((_state == p._state) &&
            (_pre == p._pre) &&
            (_post == p._post) &&
            this->equal_node(p));
    // ignore rank for indexing in table
    // p._rank == _rank
}


// always complete
bool SKIPpointer::instance(const SKIPpointer& p) const
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
                (p._rank == _rank) &&
                ((p._pre == PP_UNKNOWN) || (p._pre == _pre)) &&
                ((p._post == PP_UNKNOWN) || (p._post == _post)) &&
                equal_node(p));
    }
}



// always complete
bool SKIPpointer::subsume(const SKIPpointer& p) const
{
    return p.instance(*this);
}


void SKIPpointer::incr()
{
    _rank++;
}


std::ostream& operator<<(std::ostream& o, const SKIPpointer& p)
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
        o << "[],";
    }
    o << (PP_KNOWN(p._pre)?std::to_string(p._pre):"_") << ", ";
    o << (PP_KNOWN(p._post)?std::to_string(p._post):"_");
    o << PTR_RPAR;
    
    return o;
}


/// @}
