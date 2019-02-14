//
//  SerialLabel.cpp
//  qparse
//
//  Created by Florent Jacquemard on 20/06/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


#include "SerialLabel.hpp"


// static function
size_t SerialLabel::nbEvents(label_t n)
{
    return (n / _base2());
}


// static function
pre_t SerialLabel::pre(label_t n)
{
    return (n % _base());
}


// static function
pre_t SerialLabel::post(label_t n)
{
    return ((n / _base()) % _base());
}


// static function
//size_t SerialLabel::nbGraceNotes(label_t);
size_t SerialLabel::nbGraceNotes(label_t n)
{
    size_t e = nbEvents(n);
    if (e > 0)
        return e - 1;
    else return 0;
}


// static function
//bool SerialLabel::continuation(label_t);
bool SerialLabel::continuation(label_t n)
{
    return (nbEvents(n) == 0);
}


// static function
label_t SerialLabel::serialize(pre_t pre, pre_t post, size_t nb)
{
    return ((nb * _base2()) + (post * _base()) + pre);
}



// static function
//bool SerialLabel::compatible(label_t label, AlignedInterval* p)
//{
//    assert(p);
//    bool c = continuation(label);
//    pre_t pre_lab = pre(label);
//    pre_t post_lab = post(label);
//
//    bool r;
//
//    if (c)
//    {
//        // if it is a continuation (tie) then
//        // there must be no point aligned to the left (of this Path):
//        // no point of previous Path aligned to left,
//        // no point of this Path aligned to left.
//        r = ((pre_lab == 0) && (p->lsize() == 0));
//    }
//    else
//    {
//        // if it contains note and grace notes (not continuation):
//        // the label must be consistent with
//        // the info in guess (# grace notes)
//        // ATTENTION: pre_lab + p->l_size() n'est pas la valeur concrete
//        // de la feuille car pre_lab est abstraite
//        r = Label::abstract((SerialLabel::nbGraceNotes(label)+1),
//                     (pre_lab + p->lsize()));
//    }
//
//    // and check the guessed post value is compatible with
//    // the info in current Path (# points aligned on right)
//    // (must be true in both cases (continuation or not)
//    r = r && Label::abstract(post_lab, p->rsize());
//
//    return(r);
//}


/// @}
