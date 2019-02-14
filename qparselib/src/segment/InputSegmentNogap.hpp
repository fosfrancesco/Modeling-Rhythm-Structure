//
//  InputSegmentNogap.hpp
//  qparse
//
//  Created by Florent Jacquemard on 13/06/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//

/// @addtogroup segment
/// @{


#ifndef InputSegmentNogap_hpp
#define InputSegmentNogap_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>         // std::vector

#include "InputSegment.hpp"


class InputSegmentNogap : public InputSegment
{
public:
    
    /// @brief transform the given input segment into a new input segment without gaps.
    ///
    /// by prolongations of some notes (option norest = true)
    /// or insertion of rests events (option norest = false)
    InputSegmentNogap(const InputSegment& s, bool norest=true);
    
};

#endif /* InputSegmentNogap_hpp */


/// @}
