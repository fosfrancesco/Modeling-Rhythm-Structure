//
//  Label.cpp
//  qparse
//
//  Created by Florent Jacquemard on 04/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


#include <assert.h>

#include "Label.hpp"


Label::Label(int a): _ar(a)
{
    assert (a >= 0);
    if(a > 0)
        _type = INNER;
    else
        _type = TIE;
};


size_t Label::arity() const
{
    assert(_ar >= 0);
    assert(_ar <= MAX_AR);
    return _ar;
}


// static function
size_t Label::nbGraceNotes(label_t e)
{
    if (e > 0)
        return e - 1;
    else return 0;
}


// static function
size_t Label::nbEvents(label_t e)
{
    return e;
}


// static function
bool Label::continuation(label_t e)
{
    return (e == 0);
}


bool Label::abstract(label_t a)
{
    return (CST_MAX_GRACE == 0) || (a <= CST_MAX_GRACE);
}


bool Label::abstract(label_t a, label_t n)
{
    // no abstraction
    if (CST_MAX_GRACE == 0)
    {
        return (a == n);
    }

    assert(CST_MAX_GRACE > 0);
    if (a < CST_MAX_GRACE)
    {
        return (a == n);
    }
    else
    {
        assert (a == CST_MAX_GRACE);
        return (a <= n);
    }
}


bool Label::leqabstract(label_t a, label_t n)
{
    // no abstraction
    if (CST_MAX_GRACE == 0)
    {
        return (n <= a);
    }
    
    assert(CST_MAX_GRACE > 0);
    
    if (a < CST_MAX_GRACE)
    {
        return (n <= a);
    }
    else
    {
        assert (a == CST_MAX_GRACE);
        // TBC      return (a <= n);
        // for all n, exists c such that n+c >= CST_MAX_GRACE
        return true;
    }
}


// static function
//bool Label::compatible(label_t label, AlignedInterval* p,
//                       pre_t pre, pre_t post)
//{
//    assert(p);
//    assert (label >= 0);
//    assert (pre >= 0);
//    assert (post >= 0);
//    assert (p->lsize() >= 0);
//    
//    return ((post <= p->rsize()) &&
//            (label == pre + p->lsize() + p->rsize() - post));
//}


// from ComboWTA
//bool Label::compatible(label_t label, const Alignment* p, pre_t pre, pre_t post)
//{
//    assert(p);
//
//    return(
//           (
//            (
//             // if it is a continuation (tie): there must be no point aligned to the left (of this Path)
//             Label::continuation(label) &&
//             (pre == 0) &&   // no point of previous Path aligned to left
//             (p->l_size() == 0)  // no point of this Path aligned to left
//             )
//            ||
//            // if it contains note and grace notes (no continuation):
//            // the label must be consistent with
//            // the info in guess (# grace notes)
//            (
//             (! Label::continuation(label)) &&
//             Label::abstract(label, pre + p->l_size())
//             //      (Label::nbGraceNotes(label) == (cs.cs_pre + p->l_size() - 1))
//             )
//            )
//           &&
//           // and check the info in current Path (# points aligned on right)
//           // (must be true in both cases (continuation or not)
//           (post == p->r_size()));
//}



InnerLabel::InnerLabel(unsigned int a)
{
    _type = INNER;
    _ar = a;
}


EventLabel::EventLabel():_nbe(0)
{
    _type = TIE;
    _ar = 0;
}

EventLabel::EventLabel(unsigned int n):_nbe(n)
{
    _ar = 0;
    if (n == 0)
        _type = TIE;
    else
        _type = EVENT;
}

size_t EventLabel::nbGraceNotes() const
{
    assert(isLeaf());
    return (Label::nbGraceNotes(_nbe));
}

void EventLabel::addGraceNotes(unsigned int g)
{
    assert (_type == EVENT);
    assert (g >=0);
    _nbe += g;
}

void EventLabel::pushEvent(Event* e)
{
    assert(e);
    assert(_events.size() < _nbe);
    _events.push_back(e);
}


/// @}
