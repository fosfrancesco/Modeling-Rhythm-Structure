//
//  MusPoint.cpp
//  qparse
//
//  Created by Florent Jacquemard on 10/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#include "MusPoint.hpp"

// event can be NULL
MusPoint::MusPoint(MusEvent* e,
                   double rdate,
                   double rdur, // @todo TBR
                   bool on,
                   long link,
                   Rational mdate,
                   Rational mduration):
Point(e, rdate, rdur, on, link),
_mdate(mdate),
_mduration(mduration)
{
    assert (mdate == MUSTIME_UNKNOWN || mdate >= Rational(0));
    assert (mduration == MUSTIME_UNKNOWN || mduration >= Rational(0));
}


// event can be NULL
MusPoint::MusPoint(const Point& p, Rational mdate, Rational mduration):
Point(p),
_mdate(mdate),
_mduration(mduration)
{
    assert (mdate >= 0);
    assert (mduration >= 0);
}


MusPoint::MusPoint(const MusPoint& p):
Point(p),
_mdate(p._mdate),
_mduration(p._mduration)
{
    // event cloned in Point copy
}


MusPoint::~MusPoint()
{
    // event deleted by Point destructor
}


MusPoint& MusPoint::operator= (const MusPoint& p)
{
    if(this != &p)
    {
        MusPoint::operator=(p);
// Point assignement
//        if (p._event)
//            _event = p._event->clone();
//        else
//            _event = NULL;
//        _onset = p._onset;
//        _duration = p._duration;
        _mdate = p._mdate;
        _mduration = p._mduration;
    };
    
    return *this;
}


bool MusPoint::operator==(const Point& p) const
{
    if (!Point::operator==(p))
        return false;
    
    return ((_mdate == static_cast<const MusPoint&>(p)._mdate) &&
            (_mduration == static_cast<const MusPoint&>(p)._mduration));
}


void MusPoint::print(std::ostream& o) const
{
    //INFO(":<15", _onset); // left justify, width=15
    o << std::setw(8) << std::setiosflags(std::ios::left);
    o << _rdate << "s ";

    if (_event)
    {
        o << *_event;
    }
    else
    {
        o << "no_event";
    }
//    o << " (rdur=";
//    o << std::setw(8) << std::setiosflags(std::ios::left);
//    o << rduration() << "s)";
    if (_mdate != MUSTIME_UNKNOWN)
    {
        o << " monset= ";
        _mdate.printint(o);
        o << " bars";
    }
    if (_mduration != MUSTIME_UNKNOWN)
    {
        o << " mdur= ";
        _mduration.printint(o);
        o << " bars";
    }
}


/// @}
