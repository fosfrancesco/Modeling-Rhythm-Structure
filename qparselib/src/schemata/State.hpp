//
//  State.h
//  qparse
//
//  Created by Florent Jacquemard on 14/11/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup schemata
/// @{


#ifndef State_h
#define State_h

#include <assert.h>

#include "init.hpp"
#include "trace.hpp"
#include "Rational.hpp"


typedef long state_t;
//typedef long state_t;
//typedef unsigned int State;


/// @brief States.
///
/// - positive of null long: state of WTA              (wta state)
/// - positive of null int:  state of WTA or label     (label symbol)
/// - negative long:         inverse of number of bars (meta state)
namespace State
{
    bool isWTA(state_t);

    bool isLabel(state_t);

    bool isMeta(state_t);

    /// Meta state corresponding to bar nb barnb
    state_t MetaState(size_t barnb);
    
    // @todo TBR unused
    //state_t nextMeta(state_t);
    //size_t getBar(state_t);
}


#endif /* State_h */


/// @}
