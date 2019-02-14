//
//  MusPoint.hpp
//  qparse
//
//  Created by Florent Jacquemard on 10/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.

/// @addtogroup segment
/// @{


#ifndef MusPoint_hpp
#define MusPoint_hpp

#include <stdio.h>

#include "Rational.hpp"
#include "Point.hpp"

/// @brief Point extended with mutable musical time date and duration
/// (expressed in fraction of bars).
///
/// @todo redefine musical time duration as realtime duration, with links.
/// @todo replace _mduration by mduration computed from linked point's date
/// @warning mduration is reset in InputSegment.quantize()
class MusPoint : public Point
{
public:

    MusPoint(MusEvent* e,
             double rdate,
             double rdur, // @todo TBR
             bool on,
             long link=MUSPOINTREF_NULL,
             Rational mdate=MUSTIME_UNKNOWN,
             Rational mduration=MUSTIME_UNKNOWN);
    
    /// @brief copy of point.
    ///
    /// extended with given onset and duration values (in fraction of bars)
    MusPoint(const Point& p,
             Rational mdate=MUSTIME_UNKNOWN,
             Rational mduration=MUSTIME_UNKNOWN);
    
    /// @brief event (if any) is cloned.
    MusPoint(const MusPoint&);
    
    ~MusPoint();
    
    /// @brief event (if any) is cloned.
    MusPoint& operator= (const MusPoint&);
    
    bool operator==(const Point&) const;
    
    /// @warning can be modified.
    inline Rational& mdate()
    { return _mdate; }
    
    /// @warning only for polyphonic events.
    /// @warning can be modified.
    inline Rational& mduration()
    { return _mduration; }
    
    friend inline std::ostream& operator<<(std::ostream& o, const Point& rhs);
    
protected:
    /// @brief timestamp in musical time (number of bars).
    Rational _mdate;
    
    Rational _mduration;
    
    virtual void print(std::ostream& o) const;
};


#endif /* MusPoint_hpp */


/// @}
