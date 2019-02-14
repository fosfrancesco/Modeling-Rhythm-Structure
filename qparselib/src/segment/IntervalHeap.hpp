//
//  IntervalHeap.hpp
//  qparse
//
//  Created by Florent Jacquemard on 06/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#ifndef IntervalHeap_hpp
#define IntervalHeap_hpp

#include <stdio.h>
#include <utility>      // std::pair, std::make_pair
//#include <unordered_map>
//#include <map>
#include <unordered_set>

#include "Rational.hpp"
#include "InputSegment.hpp"
#include "Interval.hpp"
#include "AlignedInterval.hpp"
#include "IntervalTree.hpp"


//class AlignedInterval;
//class IntervalTree;


struct PointedIntervalEq
{
    bool operator () (IntervalTree const* lhs,
                      IntervalTree const* rhs) const
    {
        return
            lhs->rbegin == rhs->rbegin &&
            lhs->rend   == rhs->rend   &&
            lhs->mbegin == rhs->mbegin &&
            lhs->mend   == rhs->mend;
    }
};


struct PointedIntervalHash
{
    std::size_t operator()(const IntervalTree* p) const
    {
        using std::size_t;
        using std::hash;
        
        // see constant.h
        size_t h = HASH_SEED;
        h = h * HASH_FACTOR + hash<double>()(p->rbegin);
        h = h * HASH_FACTOR + hash<double>()(p->rend);
        h = h * HASH_FACTOR + hash<Rational>()(p->mbegin);
        h = h * HASH_FACTOR + hash<Rational>()(p->mend);
        return h;
    }
};


typedef std::unordered_set<IntervalTree*,
                           PointedIntervalHash,
                           PointedIntervalEq>
IntervalSet;


/// @brief table for storage of aligned intervals
/// to avoid recomputation of alignments.
///
/// the aligned interval are indexed (in table) as intervals
/// (i.e. indexed with bound of real-time and musical-time interval bounds).
class IntervalHeap
{
public:
    IntervalHeap();
    
    ~IntervalHeap();
    
    //static void init(InputSegment*);
    
    // input segment
    //static InputSegment* segment;
    
    bool empty() const;
    
    size_t size() const;
    
    /// @brief find or create (and push) a top interval
    /// of real-time duration covering the whole length
    /// of the given input segment s (root of interval tree) + the given extension.
    ///
    /// - inside-bar interval (musical time duration of 1 bar) if flag bar is true
    /// - multiple interval if flag bar is false (default).
    ///
    /// @warning not aligned.
    IntervalTree* const make(const InputSegment* s,
                             Rational mend,
                             double rext = 0);

    /// @brief get interval from heap,
    /// build it if not present.
    ///
    /// @warning not aligned (when built).
    IntervalTree* const make(const InputSegment* s,
                             Rational mbeg, Rational mend,
                             double rbeg, double rend,
                             size_t first,
                             IntervalTree* p,
                             IntervalTree* ps);

protected:
     /// @brief table of nodes in interval tree.
    IntervalSet _interval_heap;
    
    int _added;
    int _found;
    
private:
    IntervalTree* const push(IntervalTree* p);
    
};



#endif /* IntervalHeap_hpp */


/// @}
