//
//  Environment.hpp
//  qparse
//
//  Created by Florent Jacquemard on 15/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#ifndef Environment_hpp
#define Environment_hpp

#include <stdio.h>

#include "init.hpp"
#include "trace.hpp"
#include "InputSegment.hpp"
#include "IntervalHeap.hpp"
#include "WTA.hpp"

template<class P> class Record;


/// @brief wrapper abstract class
/// embedding a standard input environment for parsing algos.
///
/// it encapsulates some input data and structures for memory management.
class Environment
{
public:
   
    /// @brief input points to quantize.
    ///
    /// NULL when not given
    InputSegment* segment;
    
    /// @brief table of aligned input interval recorded.
    ///
    /// NULL when not needed
    /// (if there are no input points to process).
    IntervalHeap* iheap;
    
    /// @param s input segment can be :
    /// - NULL :
    /// e.g. for simple enumeration of the given wta
    /// - non-NULL:
    ///  e.g. for quantization of the points of given input segment
    ///  using a given wta
    Environment(InputSegment* s = NULL);
    
    ~Environment();
    
};

#endif /* Environment_hpp */


/// @}
