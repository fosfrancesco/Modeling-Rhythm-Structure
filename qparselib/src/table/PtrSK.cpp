//
//  PtrSK.cpp
//  squant
//
//  Created by Florent Jacquemard on 15/12/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{


#include "PtrSK.hpp"

SKpointer::SKpointer():
Spointer(),
_rank(1)
{ }

SKpointer::SKpointer(label_t s, size_t k):
Spointer(s),
_rank(k)
{ }


SKpointer::SKpointer(WTA* a, Environment* env,
                     pre_t pre,
                     pre_t post,
                     Rational mlen,
                     size_t k):
Spointer(a, env, pre, post, mlen),
_rank(k)
{
    assert(env);
    assert(k > 0);
}


SKpointer::SKpointer(Environment* env,
                     const SKpointer& p,
                     size_t a, size_t i,
                     state_t s):
Spointer(env, p, a, i, s),
_rank(1)
{ }


SKpointer::SKpointer(const SKpointer& p):
Spointer(p),
_rank(p._rank)
{ }


// should not be called: all SKpointers are complete
SKpointer::SKpointer(const SKpointer& p0, const SKpointer& p1):
Spointer(p0, p1),
_rank(p1._rank)
{ }


// should not be called: all Spointers are complete
SKpointer::SKpointer(const SKpointer& p,
                     const SKpointer& p0, const SKpointer& p1):
Spointer(p, p0, p1),
_rank(p._rank)
{ }


SKpointer& SKpointer::operator= (const SKpointer& p)
{
    if(this != &p)
    {
        _state = p._state;
        _rank = p._rank;
    };
    return *this;
}

bool SKpointer::operator==(const SKpointer& p) const
{
    return (p._state == _state);
    // ignore rank (ignored for indexing in table)
    // p._rank == _rank
}


// always complete
bool SKpointer::instance(const SKpointer& p) const
{
    return ((p._state == _state) && (p._rank == _rank));
}


// always complete
bool SKpointer::subsume(const SKpointer& p) const
{
    return ((p._state == _state) && (p._rank == _rank));
}


void SKpointer::incr()
{
    _rank++;
}


std::ostream& operator<<(std::ostream& o, const SKpointer& p)
{
    o << PTR_LPAR << p.state() << "," << p.rank() << PTR_RPAR;
    return o;
}


/// @}
