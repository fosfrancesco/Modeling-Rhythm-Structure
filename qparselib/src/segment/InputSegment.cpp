//
//  InputSegment.cpp
//  qparse
//
//  Created by Florent Jacquemard on 06/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{

// segment of points (events) in input
//
// @todo suppr.  samplestosec
// @todo suppr. member _res (resolution)

#include "InputSegment.hpp"


InputSegment::InputSegment(double b, double e):
_begin(b),
_end(e),
_len(e-b),
_mduration(MUSTIME_UNKNOWN),
_events(), // empty list of timestamped events
_heap()
{
    assert(0 <= b);
    assert(b <= e);
}


InputSegment::InputSegment(const InputSegment& s):
_begin(s._begin),
_end(s._end),
_len(s._len),
_mduration(s._mduration),
_events(s._events), // copy all MusPoint's
_heap(s._heap)
{ }


InputSegment::InputSegment(const InputSegment& s, double b, double e):
_begin(b),
_end(e),
_len(e-b),
_mduration(MUSTIME_UNKNOWN), // must be requantized
_events(),
_heap(s._heap) // copy all heap points to preserve references
               // (some may be out of the new time interval)
{
    assert(0 <= b);
    assert(b <= e);
    
    // copy only the points in the new time interval
    for (size_t i=0; i < s._events.size(); i++)
    {
        if ((b <= s._events[i].rdate()) && (s._events[i].rdate() <= e))
            _events.emplace_back(s._events[i]); // copy
    }
    
//    for (size_t i=0; i < s._heap.size(); i++)
//    {
//        _events.emplace_back(s._heap[i]); // copy
//    }
}


// TBC
InputSegment::~InputSegment()
{
    _events.clear();
    _heap.clear();
}


size_t InputSegment::size() const
{
    return _events.size();
}


std::vector<MusPoint>::iterator InputSegment::begin()
{
    return _events.begin();
}

std::vector<MusPoint>::iterator InputSegment::end()
{
    return _events.end();
}

std::vector<MusPoint>::const_iterator InputSegment::cbegin() const
{
    return _events.cbegin();
}

std::vector<MusPoint>::const_iterator InputSegment::cend() const
{
    return _events.cend();
}


//std::vector<MusPoint>::iterator
//InputSegment::emplace(const std::vector<MusPoint>::iterator i,
//                      MusEvent* e,
//                      double rdate, bool on,
//                      Point* link,
//                      Rational mdate,
//                      Rational mduration)
//{
//    std::vector<MusPoint>::iterator p = i;
//    if (p == _events.end())
//    {
//        // non empty segment: go to last point of segment
//        if (p != _events.begin())
//        {
//            p--;
//        }
//        // else: empty segment: don't move p
//    }
//    // move p to its correct position.
//    for (; (p !=  _events.end()) && (rdate >= p->rdate()); p++);
//    for (; (p !=  _events.begin()) && (rdate < (p-1)->rdate()); p--);
//    // now p is at the right position; insert.
//    assert(((p == _events.begin()) && (p == _events.end()))    ||
//           ((p == _events.begin()) && (rdate < p->rdate()))    ||
//           ((p == _events.end()) && ((p-1)->rdate() <= rdate)) ||
//           (((p-1)->rdate() <= rdate) && ( rdate < p->rdate())));
//    return _events.emplace(p, e, rdate, on, link, mdate, mduration);
//}

bool InputSegment::check_index(long i) const
{
    if (i == MUSPOINTREF_NULL)
        return true;
    else if ((0 <= i) && (i < _events.size()))
        return true;
    else if ((-_heap.size() <= i) && (i < 0))
        return true;
    else
        return false;
}


void InputSegment::link(long i, long j)
{
    assert(check_index(j));
    assert(point(i).linked == MUSPOINTREF_NULL);
    assert((j == MUSPOINTREF_NULL) || (point(i).rdate() <= point(i).rdate()));
    ncpoint(i).linked = j;
}


long InputSegment::add_back(MusEvent* e,
                            double rdate,
                            double rdur, // @todo TBR
                            bool on,
                            long link,
                            Rational mdate,
                            Rational mduration)
{
    assert(check_index(link));
    // preserve ordering
    assert(_events.empty() || _events.back().rdate() <= rdate);
    _events.emplace(_events.end(), e, rdate, rdur, on, link, mdate, mduration);
    return (_events.size() - 1);
}


long InputSegment::add_back(const MusPoint& p)
{
    _events.emplace(_events.end(), p);
    return (_events.size() - 1);
}

long InputSegment::add_floating(MusEvent* e,
                                double rdate,
                                double rdur, // @todo TBR
                                bool on,
                                long link,
                                Rational mdate,
                                Rational mduration)
{
    assert(check_index(link));
    assert(_events.empty() || _events.back().rdate() <= rdate);
    _heap.emplace(_heap.end(), e, rdate, rdur, on, link, mdate, mduration);
    return (- _heap.size());
}


long InputSegment::add_floating(const MusPoint& p)
{
    _heap.emplace(_heap.end(), p);
    return (- _heap.size());
}


const MusPoint& InputSegment::point(long i) const
{
    assert(i != MUSPOINTREF_NULL);
    if (i >= 0)
    {
        assert(i < _events.size());
        return _events[i];
    }
    else
    {
        long j = -(i+1);
        assert(0 <= j);
        assert(j < _heap.size());
        return _heap[i];
    }
}


// non-const version
MusPoint& InputSegment::ncpoint(long i)
{
    assert(i != MUSPOINTREF_NULL);
    if (i >= 0)
    {
        assert(i < _events.size());
        return _events[i];
    }
    else
    {
        long j = -(i+1);
        assert(0 <= j);
        assert(j < _heap.size());
        return _heap[i];
    }
}


MusEvent* InputSegment::event(long i) const
{
    return point(i).event();
}


double InputSegment::rdate(long i) const
{
    return point(i).rdate();
}


double InputSegment::rduration(const MusPoint& p) const
{
// STUB @todo TBR by following
    return p.rduration();
    
//    if (p.linked == MUSPOINTREF_NULL)
//    {
//        return 0;
//    }
//    else
//    {
//        // calling rdate asserts that p.linked is correct index
//        assert(p.rdate() <= rdate(p.linked));
//        return (rdate(p.linked) - p.rdate());
//    }
}


double InputSegment::rduration(long i) const
{
    // calling point asserts that i is a correct index
    return rduration(point(i));
}


Rational& InputSegment::mdate(long i)
{
    return ncpoint(i).mdate();
}


// @todo compute like rduration
Rational& InputSegment::mduration(long i)
{
    return ncpoint(i).mduration();
}


//bool InputSegment::point_comp(long lhs, long rhs)
//{
//    double lrdate = rdate(lhs);
//    double rrdate = rdate(rhs);
//    if (lrdate < rrdate)
//        return true;
//    else if (lrdate > rrdate)
//        return false;
//    else
//    {
//        assert(lrdate == rrdate);
//        double lrduration = rduration(lhs);
//        double rrduration = rduration(rhs);
//        if (lrduration < rrduration)
//            return true;
//        else if (lrduration > rrduration)
//            return false;
//        else
//        {
//            assert(lrduration== rrduration);
//            assert(event(lhs));
//            assert(event(rhs));
//            // prioterize according to position in MIDI file
//            return (event(lhs)->number < event(rhs)->number);
//        }
//    }
//}


void InputSegment::close(double e)
{
    _end = e;
}


void InputSegment::respell(int k)
{
    TRACE("respell segment (h={}, r={}", NoteName::h, NoteName::r);

// dump the table of synonym notes
//    for (size_t i = 0; i < 12; i++)
//    {
//        for (size_t j = 0; j < 3; j++)
//        {
//            INFO("syn[{}][{}] = {}", i, j, NoteName::synonyms[i][j]);
//        }
//    }
    
    assert(_mduration != MUSTIME_UNKNOWN);
    //const NoteName& current = NoteName::ofkey(k);
    // unwindowed: centroid of all pitches so far.
    SpiralPoint centroid(NoteName::ofkey(k));
    
    for (std::vector<MusPoint>::iterator i = _events.begin();
         i != _events.end(); i++)
    {
        MusPoint& p = *i;
        MusEvent* e = p.event();
        assert(e);
        if (e->isNote())
        {
            NoteEvent* ne = dynamic_cast<NoteEvent*>(e);
            assert(ne);
            if (ne->unpitched())
            {
                continue;
            }
            else
            {
                const NoteName& nn =
                    NoteName::closest(ne->pitch().midi(), centroid);
                // update musevent
                INFO("respell {} to {}", *e, nn);
//                      ne->pitch().name, ne->pitch().alteration,
//                      nn.name, nn.alteration);
                ne->pitch().name = nn.name;
                ne->pitch().alteration = nn.alteration;
                SpiralPoint update(nn);
                // segment is quantized
                assert(p.mduration() != MUSTIME_UNKNOWN);
                // TBC: update = zero for grace-notes (ignored)
                update *= toDouble(p.mduration()/_mduration);
                centroid += update;
                TRACE("new point: {} centroid={}", nn, centroid);
            }
        }
        else
        {
            continue;
        }
    }
}


void InputSegment::respell(Rational wlength, int k)
{
    
}


void InputSegment::print(std::ostream& o) const
{
    for (size_t i = 0; i < _events.size(); i++)
    {
        o << point(i);
        o << " rdur=" << rduration(i);
        o << "\n";
    }
}


std::ostream& operator<<(std::ostream& o, const InputSegment& s)
{
//    o << s.size() << "events: ";
    s.print(o);
    return o;
}


/// @}
