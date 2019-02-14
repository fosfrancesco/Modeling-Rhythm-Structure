//
//  Environment.cpp
//  qparse
//
//  Created by Florent Jacquemard on 15/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#include "Environment.hpp"

Environment::Environment(InputSegment* is):
segment(is),
iheap((is == NULL)?NULL:new IntervalHeap())
{ }


Environment::~Environment()
{
    if (iheap)
        delete iheap;
    // do not delete WTA and segment :
    // they must be deallocated externaly
}

/// @}
