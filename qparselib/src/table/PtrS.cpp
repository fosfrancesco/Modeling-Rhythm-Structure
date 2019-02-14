//
//  PtrS.cpp
//  squant
//
//  Created by Florent Jacquemard on 10/12/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{


#include "PtrS.hpp"

Spointer::Spointer():
_state(State::MetaState(1))
{ }


// TBC warning conversion of label type into state
Spointer::Spointer(label_t s):
_state(s)
{ }


Spointer::Spointer(WTA* a,
                   Environment* env,
                   pre_t pre,     // ignored
                   pre_t post,    // ignored
                   Rational mlen, // ignored
                   size_t k):     // ignored
Pointer(),
_state(a->initial(pre,post))
{
    // pre, post values for Combo WTA. ignored by plain WTA.
    assert(a);
    assert(env);
    // quantization of a single bar (only inside-bar runs)
    //assert(bar == true);
    // k should not be passed as arg. here.
    assert(k == 1);
}


Spointer::Spointer(Environment* env,
                   const Spointer& p, size_t a, size_t i,
                   state_t s):
Pointer(),
_state(((a>0)&&(i==0))?p._state:s) // first case = copy of p
{
    // generic preconditions
    assert((a > 0) ||  (i == 0));
    assert((a == 0) || ((0 <= i) && (i <= a)));
    // specific preconditions
    assert(env);
    assert(State::isWTA(s));
}


Spointer::Spointer(const Spointer& p):
_state(p._state)
{ }


// should not be called: all Spointers are complete
Spointer::Spointer(const Spointer& p0, const Spointer& p1):
_state(p1._state)
{
    assert(p0.complete());
    assert(p1.partial());
}


// should not be called: all Spointers are complete
Spointer::Spointer(const Spointer& p, const Spointer& p0, const Spointer& p1):
_state(p._state)
{
    assert(p.partial());
    assert(p0.complete());
    assert(p1.complete());
}


Spointer& Spointer::operator= (const Spointer& p)
{
    if(this != &p)
    {
        _state = p._state;
    };
    return *this;
}


bool Spointer::operator==(const Spointer& p) const
{
    return (p._state == _state);
}


bool Spointer::operator<(const Spointer& p) const
{
    return (_state < p._state);
}


// always complete
bool Spointer::instance(const Spointer& p) const
{
    return (p._state == _state);
}


// always complete
bool Spointer::subsume(const Spointer& p) const
{
    return (p._state == _state);
}


bool Spointer::complete() const
{
    return true;
}


bool Spointer::dummy() const
{
    return (_state == State::MetaState(1));
}


label_t Spointer::label(const Transition& t) const
{
    assert(t.terminal());
    return t.label();
}


bool Spointer::divisible() const
{
    assert(State::isWTA(_state));
    return true;
}


std::ostream& operator<<(std::ostream& o, const Spointer& p)
{
    o << PTR_LPAR << p._state << PTR_RPAR;
    return o;
}


/// @}
