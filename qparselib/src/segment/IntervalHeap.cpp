//
//  IntervalHeap.cpp
//  qparse
//
//  Created by Florent Jacquemard on 06/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#include "IntervalHeap.hpp"


IntervalHeap::IntervalHeap():
_interval_heap(),
_added(0),
_found(0)
{ }


IntervalHeap::~IntervalHeap()
{
    TRACE("delete interval heap");
    INFO("iheap: size={} interval added={} hit={}",
          _interval_heap.size(), _added, _found);

    for (IntervalSet::iterator it = _interval_heap.begin();
         it != _interval_heap.end(); ++it )
    {
        assert(*it);
        delete(*it);
    }
         
    _interval_heap.clear();
}


bool IntervalHeap::empty() const
{
    return _interval_heap.empty();
}


size_t IntervalHeap::size() const
{
    return _interval_heap.size();
}


IntervalTree* const IntervalHeap::make(const InputSegment* s,
                                       Rational me,
                                       double rext)
{
    assert(s);
    assert(me >= Rational(0));
    assert(rext >= 0);

    IntervalTree* p = new IntervalTree(s,
                                       Rational(0), me,
                                       s->rbegin(), s->rduration()+rext,
                                       0,
                                       NULL, NULL);

    return push(p);
}


IntervalTree* const IntervalHeap::make(const InputSegment* s,
                                       Rational mb, Rational me,
                                       double rb, double re,
                                       size_t first,
                                       IntervalTree* par,
                                       IntervalTree* ps)
{
    IntervalTree* p = new IntervalTree(s,
                                       mb, me,
                                       rb, re,
                                       first,
                                       par, ps);
    
    return push(p);
}

IntervalTree* const IntervalHeap::push(IntervalTree* p)
{
    assert(p);
    
    std::pair<IntervalSet::iterator, bool> ret = _interval_heap.insert(p);
    
    // inserted to heap
    if (ret.second)
    {
        assert(p == *(ret.first));
        TRACE("new IntervalTree {}", *(p));
        _added++;   // stat
    }
    // already in heap, not inserted
    else
    {
        TRACE("found IntervalTree {}", **(ret.first));
        _found++;
        delete p;
    }
    assert(*(ret.first));
    return *(ret.first);
}


/// @}
