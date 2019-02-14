//
//  Point.hpp
//  qparse
//
//  Created by Florent Jacquemard on 05/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "MusEvent.hpp"


/// @brief timestamped event.
///
/// event extended with realtime date (in seconds)
/// and optional [on-off] link.
///
/// every point has a realtime date (in seconds).
///
/// a point can be linked to a forward point
/// (with a realtime date larger or equal).
/// the link is an index in an input segment.
///
/// a linked point is also called onset or note-on.
/// an point without link (with link = MUSPOINTREF_NULL)
/// is called offset or note-off.
///
/// for the computation of realtime duration of points, see @ref InputSegment.
class Point
{
public:
    
    /// @brief link to a point in an input segment marking the end date of this point.
    ///
    /// the link is an index in an input segment structure:
    /// - a point of segment if >= 0,
    /// - or a floating point if < 0.
    /// if MUSPOINTREF_NULL, the duration of this point is zero.
    long linked;
    
    /// @brief timestamped monophonic or polyphonic event.
    Point(MusEvent* e,
          double rdate,
          double rdur, // @todo TBR
          bool on,
          long link=MUSPOINTREF_NULL);

    /// @warning event (if any) is cloned.
    Point(const Point&);

     /// @warning event is deallocated and matcher (linked) also.
    ~Point();
    
     /// @warning event (if any) is cloned.
    virtual Point& operator= (const Point&);
    
    virtual bool operator==(const Point&) const;
    
    /// @warning can be NULL.
    inline MusEvent* event() const
    { return _event; }
    
    inline double rdate() const
    { return _rdate; }

    /// @brief realtime duration of polyphonic events.
    ///
    /// is computed in input segment
    ///
    /// @todo TBR (only for backward compability)
    inline double rduration() const
    { return _rduration; }

    /// @brief is note on.
    inline bool noteon() const
    { return(linked != MUSPOINTREF_NULL); }

    /// @brief is note off.
    inline bool noteoff() const
    { return(! noteon()); }

    friend inline std::ostream& operator<<(std::ostream& o, const Point& rhs);
    
protected:
    /// @brief input event.
    MusEvent* _event;

    /// @brief timestamp in real-time (sec).
    double _rdate;

    /// @brief real duration computed using the matcher's rdate.
    ///
    /// @todo TBR (added for backward compatibility)
    double _rduration;

    /// @brief true if note-on, false if note-off.
    ///
    /// @todo TBR
    bool _onoff;
    
    virtual void print(std::ostream& o) const;
};


std::ostream& operator<<(std::ostream& o, const Point& rhs)
{
    rhs.print(o);
    return o;
}


#endif /* Point_hpp */


/// @}
