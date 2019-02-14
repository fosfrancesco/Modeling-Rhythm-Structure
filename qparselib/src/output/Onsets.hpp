//
//  Onsets.hpp
//  qparse
//  equiv
//
//  Created by Florent Jacquemard on 18/11/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


#ifndef Onsets_hpp
#define Onsets_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

#include "Rational.hpp"
#include "DurationList.hpp"


/// sequence of onsets
/// used for merge of duration lists.
class Onsets
{
public:
    Onsets() {}
    
    /// the list of onsets defined by the given duration list (IOI's)
    /// the first onset is 0.
    /// @warning a continuation in duration list will be treated like other events
    Onsets(const DurationList&);
    
    friend const Onsets operator+(const Onsets& lhs, const Onsets& rhs);

    inline void add(Rational r) { _content.push_back(r); }
    
    /// the list of IOI associated to this list of onsets.
    DurationList ioi() const;
    
private:
    /// ordered list of onsets (without continuation)
    std::list<Rational> _content;
    
};

/// ordered merge
const Onsets operator+(const Onsets& lhs, const Onsets& rhs);


#endif /* Onsets_hpp */


/// @}
