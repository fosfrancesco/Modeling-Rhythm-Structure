//
//  State.cpp
//  qparse
//
//  Created by Florent Jacquemard on 21/12/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup schemata
/// @{


#include <stdio.h>

#include "State.hpp"


bool State::isMeta(state_t s)
{
    return (s < 0);
}

bool State::isWTA(state_t s)
{
    return (! State::isMeta(s));
}

bool State::isLabel(state_t s)
{
    return ((! State::isMeta(s)) &&
            (s < numeric_limits<int>::max()));
}

state_t State::MetaState(size_t barnb)
{
    assert(barnb > 0);
    return -barnb;
}

// @todo TBR unused
//state_t State::nextMeta(state_t s)
//{
//    assert(State::isMeta(s));
//    return (s - 1);
//}

// @todo TBR unused
//size_t State::getBar(state_t s)
//{
//    assert (State::isMeta(s));
//    return (-s);
//}


/// @}
