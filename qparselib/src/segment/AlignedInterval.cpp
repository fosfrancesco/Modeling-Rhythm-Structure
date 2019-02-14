//
//  AlignedInterval.cpp
//  qparse
//
//  Created by Florent Jacquemard on 07/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#include "AlignedInterval.hpp"
#include "IntervalHeap.hpp"


AlignedInterval::AlignedInterval(const InputSegment* s,
                                 Rational me,
                                 bool f_align):
Interval(s, me),
_seg_llen(0),
_seg_lbeg(0),
_seg_rlen(0),
_seg_rbeg(0),
_seg_next(0),
_seg_first(0)
{
    assert(s->size() > 0);
    if (f_align)
        align(s);
    else
        assert(_check_first(s));
}


// internal use only
AlignedInterval::AlignedInterval(const InputSegment* s,
                                 Rational mb, Rational me,
                                 double rb, double re,
                                 size_t first,
                                 bool f_align):
Interval(s, mb, me, rb, re),
_seg_llen(0),
_seg_lbeg(0),
_seg_rlen(0),
_seg_rbeg(0),
_seg_next(0),
_seg_first(first)
{
    //assert(first < s->size());
    if (f_align)
        align(s);
    else
        assert(_check_first(s));
}


AlignedInterval::AlignedInterval(const AlignedInterval& p):
Interval(p),
_seg_llen(p._seg_llen),
_seg_lbeg(p._seg_lbeg),
_seg_rlen(p._seg_rlen),
_seg_rbeg(p._seg_rbeg),
_seg_next(p._seg_next),
_seg_first(p._seg_first)
{ }


AlignedInterval& AlignedInterval::operator= (const AlignedInterval& p)
{
    if(this != &p)
    {
        Interval::operator=(p);
        _seg_llen = p._seg_llen;
        _seg_lbeg = p._seg_lbeg;
        _seg_rlen = p._seg_rlen;
        _seg_rbeg = p._seg_rbeg;
        _seg_next = p._seg_next;
        _seg_first = p._seg_first;
    };
    return *this;
}


bool AlignedInterval::operator==(const AlignedInterval& p) const
{
    if (! Interval::operator==(p))
        return false;
    
    // compare as interval (for table iheap)
    return true;

    //    return ((rbegin == p.rbegin) &&
    //            (rend   == p.rend)   &&
    //            (mbegin == p.mbegin) &&
    //            (mend   == p.mend));
}


bool AlignedInterval::aligned() const
{    
    return ((_seg_lbeg > 0) || (_seg_rbeg > 0));
}


size_t AlignedInterval::align(const InputSegment* s, size_t b)
{
    _seg_first = b;
    return align(s);
}


// we assume rbegin and rend are set
size_t AlignedInterval::align(const InputSegment* s)
{
    assert(s);
    // don't recompute alignment
    if (aligned())
    {
        WARN("align called twice on the same interval {}", *this);
        assert(_check_next(s));
        return _seg_next;
    }
    // the realtime begin date of this interval
    // is not necessarly in the input segment bounds.
    assert(s->rbegin() <= rbegin);
    // assert(rbegin <= s->rend());

    // correctness of seg_first
    assert(_check_first(s));
    
    size_t segend = s->size();
    double rlen = rend - rbegin;
    double rmid = rbegin + (rlen / 2.0);
    int c;
    size_t i = _seg_first;
    
    // count # segment points from b on in the first half of Interval
    for(c=0; (i < segend) && (s->rdate(i) < rmid); i++)
    { c++; }
    
    _seg_llen = c;
    // no segment points in first half of interval
    if (_seg_llen == 0)
        _seg_lbeg = segend;  // out_of_range (should not be used)
    else
        _seg_lbeg = _seg_first;       // rbegin <= rdate(b) < rmid
    
    // end of segment reached, no segment points in second half of interval
    if (i >= segend)
    {
        _seg_rlen = 0;
        _seg_rbeg = segend;
    }
    else
    {
        assert (s->rdate(i) >= rmid);
        _seg_rbeg = i;
        // count # segment points from i on in the second half of Interval
        for(c=0; (i < segend) && (s->rdate(i) < rend); i++)
        { c++; }
        
        _seg_rlen = c;
        
        // no segment points in second half of interval
        if (_seg_rlen == 0)
            _seg_rbeg = segend;
    }
    
    // post-conds:
    assert (_seg_llen >= 0);
    assert (_seg_llen <= segend);
    assert (_seg_lbeg >= 0);
    
    assert ((_seg_llen >  0) || (_seg_lbeg >= segend));
    assert ((_seg_llen == 0) || (_seg_lbeg < segend));
    assert ((_seg_llen == 0) || (_seg_lbeg+_seg_llen-1 < segend));
    assert ((_seg_llen == 0) || (s->rdate(_seg_lbeg) >= rbegin));
    assert ((_seg_llen == 0) || (s->rdate(_seg_lbeg) < rmid));
    assert ((_seg_llen == 0) || (s->rdate(_seg_lbeg+_seg_llen-1) >= rbegin));
    assert ((_seg_llen == 0) || (s->rdate(_seg_lbeg+_seg_llen-1) < rmid));
    
    assert (_seg_rlen >= 0);
    assert (_seg_rlen <= segend);
    assert (_seg_rbeg >= 0);
    
    assert ((_seg_rlen >  0) || (_seg_rbeg >= segend));
    assert ((_seg_rlen == 0) || (_seg_rbeg < segend));
    assert ((_seg_rlen == 0) || (_seg_rbeg+_seg_rlen-1 < segend));
    assert ((_seg_rlen == 0) || (s->rdate(_seg_rbeg) >= rmid));
    assert ((_seg_rlen == 0) || (s->rdate(_seg_rbeg) < rend));
    assert ((_seg_rlen == 0) || (s->rdate(_seg_rbeg+_seg_rlen-1) >= rmid));
    assert ((_seg_rlen == 0) || (s->rdate(_seg_rbeg+_seg_rlen-1) < rend));
    
    // i (next point) out of interval
    assert ((i >= segend) || (i == _seg_first + _seg_llen + _seg_rlen));

    // consistency of first wrt alignement
    assert((_seg_first < segend) ||
           (_seg_first == std::min(_seg_lbeg, _seg_rbeg)));
    assert((_seg_first == segend) ||
           (s->rdate(_seg_first) < rend) ||
           (std::min(_seg_lbeg, _seg_rbeg) == segend));
    assert((_seg_first == segend) ||
           (s->rdate(_seg_first) >= rend) ||
           (std::min(_seg_lbeg, _seg_rbeg) == _seg_first));
    
    _seg_next = i;
    assert(_check_next(s));    // correctness of seg_next
    
    return i;
}


size_t AlignedInterval::rewind(const InputSegment* s, size_t b)
{
    _seg_first = b;
    return rewind(s);
}


// we assume rbegin and rend are set
size_t AlignedInterval::rewind(const InputSegment* s)
{
    assert(s);
    // don't recompute alignment
    //assert (! aligned());
    if (aligned())
    {
        WARN("rewind called on aligned interval {}", *this);
        assert(_check_next(s));
        return _seg_next;
    }
    // correctness of seg_first
    assert(_check_first(s));
    
    size_t segend = s->size();
    size_t i = _seg_first;
    
    // advances until finding a point out of the Interval
    for(; (i < segend) && (s->rdate(i) < rend); i++)
    {  }
    
    _seg_next = i;
    assert(_check_next(s));    // correctness of seg_next
    
    return i;
}


bool AlignedInterval::_check_first(const InputSegment* s)
{
    // there is no first after the left bound
    if ((_seg_first >= s->size()) && (s->rdate(s->size()-1) >= rbegin))
        return false;

    // first is after the left bound
    // if first index is not out of bounds,
    // the first point must be after the left bound of the interval (rbegin)
    // (it can be out of the interval, i.e. after the right bound (rend))
    if ((_seg_first < s->size()) && (s->rdate(_seg_first) < rbegin))
        return false;
    
    // first is the min
    if ((_seg_first < s->size()) && (_seg_first > 0) &&
        (s->rdate(_seg_first-1) >= rbegin))
        return false;
    
    return true;
}


bool AlignedInterval::_check_next(const InputSegment* s)
{
    if (_seg_next > s->size())
        return false;
    
    // there is no next after the right bound
    if ((_seg_next == s->size()) && (s->rdate(s->size()-1) >= rend))
        return false;
    
    // next is after the right bound
    if ((_seg_next < s->size()) && (s->rdate(_seg_next) < rend))
        return false;
    
    // next is the min
    if ((_seg_next < s->size()) && (_seg_next > 0) &&
        (s->rdate(_seg_next-1) >= rend))
        return false;
    
    return true;
}


std::ostream& operator<<(std::ostream& o, const AlignedInterval& p)
{
    
//    o << "[";
//    p.mbegin.printint(o);
//    o << "-";
//    p.mend.printint(o);
//    o << "]";
//    o << " [" << p.rbegin << "-" << p.rend << "]";
    o << static_cast<const Interval&>(p);
    
    o << " { ";
    //    if (p._seg_lbeg < segend)
    {
        for (size_t i = p._seg_lbeg; i < p._seg_lbeg + p._seg_llen; i++)
        {
            o << i << " ";
        }
    }
    o << "| ";
    //    if (p._seg_rbeg < segend)
    {
        for (size_t i = p._seg_rbeg; i < p._seg_rbeg + p._seg_rlen; i++)
        {
            o << i << " ";
        }
    }
    o << "} ";
    
    return o;
}


/// @}
