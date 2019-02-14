//
//  Distance.cpp
//  qparse
//
//  Created by Florent Jacquemard on 04/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup weight
/// @{

#include "Distance.hpp"


Distance::Distance(const InputSegment* s, const AlignedInterval* p):
TropicalWeight(0)
{
    assert(s);
    assert(p);
    assert(p->aligned());
    assert (s->rbegin() <= p->rbegin);
//    assert (p->rbegin <= s->rend());
    assert (p->rbegin <= p->rend);
    
    const size_t ll = p->lsize();
    const size_t rl = p->rsize();
    
//    _val = 0;
    
    if (ll > 0)
    {
        size_t j = p->lfirst();
        assert (j < s->size());
        for(int i = 0; i < ll; i++)
        {
            assert (p->rbegin <= s->rdate(j));
            assert (s->rdate(j) < p->rend);
            double val1 = s->rdate(j) - p->rbegin;
            
            // Old version
            DEBUG("distance (ll={}, interval={}): point:{} dist={}+{}",
                  ll, *p, j, _val, val1);
            //_val += CST_ALPHA * val1;
            // new version with calibration
            _val += CST_ALPHA * val1 * distcoeff(s, j);
            j++;
        }
    }
    
    if (rl > 0)
    {
        size_t j = p->rfirst();
        assert (j < s->size());
        for(int i = 0; i < rl; i++)
        {
            assert (p->rbegin <= s->rdate(j));
            assert (s->rdate(j) <= p->rend);
            double val1 = p->rend - s->rdate(j);
            DEBUG("distance (rl={}, interval={}): point:{} dist={}+{}", rl, *p, j, _val, val1);
            // Old version
            //_val += CST_ALPHA * val1;
            // new version with calibration
            _val += CST_ALPHA * val1 * distcoeff(s, j);
            assert ((_val == -1) || (_val >= 0));
            j++;
        }
    }
    
    //normalization
    // TBC
    //const double d = s->size();
    //_val *= (2.0 / d); // TBC
    //    _val *= (2.0 / (d*r)); // TBC
    // MOD. was for distance in # samples
    //    const double r = p->input().resolution();

    // it shpould be a Trpical Weight
    assert ((_val == -1) || (_val >= 0));
}


double Distance::distcoeff(const InputSegment* s, size_t j)
{
    assert(s);
    assert(s->size() != 0); // non empty input seg
    assert(0 <= j);
    assert(j < s->size());

//    double distprev;
//    double distnext;
//
//    // singleton input segment
//    if ((j == 0) && (j == s->size()-1))
//    {
//        distprev = 1/2;
//        distnext = 1/2;
//    }
//    // first, not last
//    else if (j == 0)
//    {
//        distprev = 0;
//        distnext = dist_next(s, j);
//    }
//    // last, not first
//    else if (j == s->size()-1)
//    {
//        distprev = dist_prev(s, j);
//        distnext = 0;
//    }
//    // not first, not last
//    else
//    {
//        distprev = dist_prev(s, j);
//        distnext = dist_next(s, j);
//    }
//    assert(distprev + distnext != 0);
//    return (distprev + distnext);
    
    double d = (dist_prev(s, j) + dist_next(s, j));
    assert(d >= 0);
    return (d == 0)?1:d;
}


// distance to closets point before j not at the same date as j
double Distance::dist_prev(const InputSegment* s, size_t j)
{
//    assert(s);
//    assert(0 <= j);
//    assert(j < s->size());
    
    double d;
    size_t i = j;

    for (d = 0; d == 0 && i > 0; i--)
    {
        assert(s->rdate(j) >= s->rdate(i-1));
        d = s->rdate(j) - s->rdate(i-1);
    }
    assert(d >= 0);
    return (d == 0)?0:(1/d);
}


// distance to the closest point after j not at the same rdate as j
double Distance::dist_next(const InputSegment* s, size_t j)
{
//    assert(s);
//    assert(0 <= j);
//    assert(j < s->size());
    
    double d;
    size_t i = j;
    for (d = 0; d == 0 && i < s->size()-1; i++)
    {
        assert(s->rdate(i+1) >=  s->rdate(j));
        d = s->rdate(i+1) - s->rdate(j);
    }
    assert(d >= 0);
    return (d == 0)?0:(1/d);
}


Distance& Distance::operator= (const Distance& rhs)
{
    if (this != &rhs)
    {
        _val = rhs._val;
    }
    return *this;
}


Distance* Distance::clone() const
{
    assert ((_val == -1) || (_val >= 0));

    return (new Distance(_val));
}


void Distance::print(std::ostream& o) const
{
    o << _val;
}


/// @}
