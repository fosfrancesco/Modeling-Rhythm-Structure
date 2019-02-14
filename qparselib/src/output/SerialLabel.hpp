//
//  SerialLabel.hpp
//  qparse
//
//  Created by Florent Jacquemard on 20/06/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


#ifndef SerialLabel_hpp
#define SerialLabel_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

#include "init.hpp"
#include "trace.hpp"
#include "Label.hpp"
#include "AlignedInterval.hpp"


/// static functions for serializable int encoding of
/// input and output leaf symbols containing the following info:
/// - [input info]
///   - pre value: number of events from previous segment aligned
///     to left of current input segment
///   - post value: number of events aligned to right of current input segment
/// - [output info]
///   - number of grace notes in output
///   - number of events in output (notes + grace notes)
///
/// the encoding is
/// @code
/// pre * (MAX_GRACE+1)^2 + post * (MAX_GRACE+1) + number_events
/// @endcode
class SerialLabel
{
public:
    
    // serialize(pre, post, nb)
    /// return the leaf label encoding the given
    /// @param pre value in 0..MAX_GRACE
    /// @param post value in 0..MAX_GRACE
    /// @param nb number of events
    static label_t serialize(pre_t pre, pre_t post, size_t nb);
    
    /// return the pre value of the given leaf label
    static pre_t pre(label_t);
    
    /// return the post value of the given leaf label
    static pre_t post(label_t);
    
    /// return the number of grace node encoded in given leaf label
    static size_t nbGraceNotes(label_t);
    
    /// the given leaf label is a continuation (no event, no grace note)
    static bool continuation(label_t);
    
    /// number of note + grace notes encoded in given leaf label
    static size_t nbEvents(label_t);
    
    // compatible(lab, al)
    // the content of the alignment
    // (sub-segment of initial input corr. to an interval)
    // is compatible with the encoding expressed in the label lab
//     static bool compatible(label_t, AlignedInterval*);
    
private:
    
    static inline label_t _base() { return CST_MAX_GRACE+1; }
    static inline label_t _base2() { return (_base() * _base()); }
    
};


#endif /* SerialLabel_hpp */


/// @}
