//
//  Point.cpp
//  qparse
//
//  Created by Florent Jacquemard on 05/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#include "Point.hpp"


// event and link can be NULL
// @todo TBR noteon
Point::Point(MusEvent* e,
             double rdate,
             double rdur,
             bool noteon,
             long link):
_event(e),
_rdate(rdate),
_rduration(rdur),
_onoff(noteon),
linked(link)
{
//    assert (linked == NULL || linked->_rdate >= _rdate);
}


// event can be NULL
// @todo TBR _onoff
Point::Point(const Point& p):
_rdate(p._rdate),
_rduration(p._rduration), // @todo TBR
_onoff(p._onoff),
linked(p.linked)
{
    // TBC: not nec. to clone if input events are never modified
    if (p._event)
        _event = p._event->clone();
    else
        _event = NULL;
}


Point::~Point()
{
    if (_event)
    {
        delete _event;
        _event = NULL;
    }
}


// @todo TBR _onoff
Point& Point::operator= (const Point& p)
{
    if(this != &p)
    {
        _rdate = p._rdate;
        _rduration = p._rduration; // @todo TBR
        _onoff = p._onoff;
        linked = p.linked;
        
        // TBC: not nec. to clone if input events are never modified
        if (p._event)
            _event = p._event->clone();
        else
            _event = NULL;
    };
    
    return *this;
}


bool Point::operator==(const Point& p) const
{
    if (typeid(*this) != typeid(p))
        return false;
    
    if ((_rdate != p._rdate) || (noteon() != p.noteon()))
    {
        return false;
    }
    // cannot compare durations without input segment
    // @todo TBR
    else if (rduration() != p.rduration())
    {
        return false;
    }
    else if (linked!= p.linked)
    {
            return false;
    }
    else if (_event == NULL)
    {
        return (p._event == NULL);
    }
    else if (p._event == NULL)
    {
        return false;
    }
    else if (_event->isRest())
    {
        return (p._event->isRest());
    }
    else
    {
        assert(_event->isNote());
        if (p._event->isNote())
        {
            NoteEvent* ne = dynamic_cast<NoteEvent*>(_event);
            NoteEvent* pne = dynamic_cast<NoteEvent*>(p._event);
            assert(ne);
            assert(pne);
            return ((ne->pitch() == pne->pitch()) &&
                    (ne->velocity() == pne->velocity()));
        }
        else
        {
            return false;
        }
    }
}


//double Point::rduration() const
//{
//    if (linked == NULL)
//    {
//        return 0;
//    }
//    else
//    {
//        assert(linked->_rdate >= _rdate);
//        return(linked->_rdate - _rdate);
//    }
//}


void Point::print(std::ostream& o) const
{
    //INFO(":<15", _rdate); // left justify, width=15
    o << std::setw(12) << std::setiosflags(std::ios::left);
    o << _rdate << " ";
    
    if (_event)
    {
        o << *_event;
    }
    else
    {
        o << "_";
    }
}


/// @}
