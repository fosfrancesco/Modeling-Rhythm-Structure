//
//  Transition.cpp
//  qparse
//
//  Created by Florent Jacquemard on 25/01/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup schemata
/// @{


#include "Transition.hpp"


// initial counter value
size_t Transition::_cpt = 0;


Transition::Transition():
_weight(),
_body(),
_id(_cpt++)
{ }


Transition::Transition(const Weight& w):
_weight(w),
_body(),
_id(_cpt++)
{
    assert (_body.empty());
}

Transition::Transition(LetterWeight* lw):
_weight(lw),
_body(),
_id(_cpt++)
{
    assert(lw);
    assert (_body.empty());
}

Transition::Transition(std::vector<state_t> v, const Weight& w):
_weight(w),
_body(v),
_id(_cpt++)
{
    assert(v.size() > 0);
    assert (! _body.empty());
}

Transition::Transition(std::vector<state_t> v, LetterWeight* lw):
_weight(lw),
_body(v),
_id(_cpt++)
{
    assert(lw);
    assert(v.size() > 0);
    assert (! _body.empty());
}

Transition::Transition(state_t s, const Weight& w):
_weight(w),
_body(),
_id(_cpt++)
{
    assert (_body.empty());
    _body.push_back(s);
}

Transition::Transition(state_t s, LetterWeight* lw):
_weight(lw),
_body(),
_id(_cpt++)
{
    assert(lw);
    assert (_body.empty());
    _body.push_back(s);
}


Transition::~Transition()
{
    _body.clear();
}


bool Transition::inner() const
{
    //    assert(_weight);
    return ((_body.size() > 1) && (! _weight.unknown()));
}


bool Transition::terminal() const
{
    //    assert(_weight);
    return ((_body.size() == 1) && (! _weight.unknown()));
}


label_t Transition::label() const
{
    assert (terminal());
    return (_body[0]);
}


void Transition::scalar(double d)
{
    _weight.scalar(d);
}


void Transition::invert()
{
    _weight.invert();
}


size_t Transition::size() const
{
    assert (inner());
    return (_body.size());
}

size_t Transition::arity() const
{
    if (terminal())
        return 0;
    else
        return (_body.size());
}


state_t Transition::at(size_t i) const
{
    assert (0 <= i);
    assert (i < _body.size());
    return (_body[i]);
}


void Transition::push(state_t s)
{
    _body.push_back(s);
}


bool Transition::member(state_t s) const
{
    assert (! State::isMeta(s));
    if (terminal())
        return false;
    
    assert (inner());
    
    for (state_t i : _body)
        if (i == s) return true;
    
    //    for (vector<state_t>::const_iterator i = _body.begin(); i != _body.end(); i++)
    //        if (*i == s) return true;
    
    return false;
}


bool Transition::allin(const std::set<state_t>& e) const
{
    //the singleton body of terminal transition contains terminal symbol
    if (terminal()) return false;
    assert (inner());
    
    //    for (vector<state_t>::const_iterator i = _body.begin(); i != _body.end(); ++i)
    for (state_t i : _body)
    {
        if (e.count(i) == 0) return false;
    }
    return true;
}


bool Transition::nonein(const std::set<state_t>& e) const
{
    //the singleton body of terminal transition contains terminal symbol
    if (terminal()) return true;
    assert (inner());
    
    //    for (vector<state_t>::const_iterator i = _body.begin(); i != _body.end(); ++i)
    for (state_t i : _body)
    {
        if (e.count(i) != 0) return false;
    }
    return true;
}



std::ostream& operator<<(std::ostream& o, const Transition& t)
{
    if (t.terminal())
    {
        o << "<" << t.label() << "> " << t.weight();
    }
    else if (t.inner())
    {
        o << "( ";
        for(Transition_const_iterator i = t._body.cbegin();
            i != t._body.cend();
            ++i)
            o << *i << " ";
        
        o << ") " << t.weight();
    }
    else
    {
        ERROR("transition not terminal nor inner");
    }
    return o;
}


/// @}
