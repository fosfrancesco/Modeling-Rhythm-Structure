//
//  InputSegmentMono.hpp
//  qparse
//
//  Created by Florent Jacquemard on 31/05/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#ifndef InputSegmentMono_hpp
#define InputSegmentMono_hpp

#include <stdio.h>
#include <assert.h>
#include <queue>          // std::queue (FIFO), std::priority_queue
#include <vector>         // std::vector
#include <math.h>

#include "InputSegment.hpp"


/// @brief conversion of InputSegment to remove overlapping notes.
///
/// if NOTEON1 is linked to NOTEOFF1
/// and NOTEON2 occurs between NOTEON1 and NOTEOFF1
/// (including NOTEON1, excluding NOTEOFF1)
/// then NOTEON1 is relinked to NOTEON2,
/// and NOTEOFF1 is ignored if it is not linked.
///
/// In the case where NOTEON1 = NOTEON2,
/// we move the NOTEOFF of the shortest note (in real duration).
/// This note becomes a grace note (duration 0).
class InputSegmentMono : public InputSegment
{
public:
    
    /// @brief transform the given input segment into a monophonic input segment
    /// (no two notes in the same time).
    ///
    /// by moving note-off events
    InputSegmentMono(const InputSegment& s);
    

    
private:
// variables for import

    
// functions for import

// restart reading
//    void _seg_start();
//    bool _seg_end();
//    void _seg_incr();

};


#endif /* InputSegmentMono_hpp */


/// @}
