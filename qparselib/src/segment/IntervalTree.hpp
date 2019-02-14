//
//  IntervalTree.hpp
//  qparse
//
//  Created by Florent Jacquemard on 11/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#ifndef IntervalTree_hpp
#define IntervalTree_hpp

#include <stdio.h>
#include <utility>      // std::pair, std::make_pair
#include <unordered_map>
#include <map>

#include "Rational.hpp"
#include "InputSegment.hpp"
#include "AlignedInterval.hpp"
//#include "IntervalHeap.hpp"

class IntervalHeap;


/// @brief extension of Aligned Interval
/// to define a tree of nested Alignements with sharing
/// using hash table to store all alignment constructed.
///
/// to construct IntervalTree use IntervalHeap.make
/// and the members top, split, split_back and sub.
class IntervalTree: public AlignedInterval
{
    friend class IntervalHeap;

public:

    //IntervalTree():Interval() {}
    
    ~IntervalTree();
    
    /// @return the embedding Interval in the Interval tree.
    /// @return NULL if this Interval is the root of the tree.
    virtual inline IntervalTree* parent()
    { return _parent; }
    
    /// @return the previous sibling Interval in the Interval tree.
    /// @return NULL if this Interval is the leftmost sibling.
    virtual inline IntervalTree* previous_sibling()
    { return _previous_sibling; };
    
    /// @brief top interval (root of interval tree)
    /// covering the whole length of the given input segment s.
    ///
    /// inside-bar interval of musical time duration of 1 bar if flag bar is true.
    /// multi-bar interval if flag bar is false.
    IntervalTree* top(const InputSegment* s,
                      IntervalHeap* h,
                      Rational mend=Rational(1));
    
    
    /// @brief return a sub interval.
    ///
    /// - if i = 1
    ///   first sub-interval starting at same point as this interval
    ///   of realtime duration rdur
    ///   of musical duration mdur bar.
    ///   it not is aligned.
    /// - if i = 2
    ///   second sub-interval (rest)
    ///   starting at this interval realtime start + rdur
    ///   and this interval musical time start + mdur
    ///   of realtime duration this realtime duration - rdur.
    ///   if the real starting date is out of this interval,
    ///   then the real duration of the returned second sub-interval is zero.
    ///   the musical starting date must be inside this interval.
    ///   it is not aligned.
    ///
    /// @param rdur must be strictly positive.
    /// @param mdur must be strictly positive.
    IntervalTree* split(const InputSegment*,
                        IntervalHeap*,
                        double rdur, Rational mdur,
                        size_t i);
    
    
    /// @brief return a sub interval.
    ///
    /// - if i = 1
    ///   first sub-interval starts at same point as this interval
    ///   of realtime duration : duration of this interval - rdur
    ///   of musical duration : musical duration of this interval - mdur bars.
    ///   if the starting date is out of the input segment,
    ///   then the real duration of the returned first sub-interval is zero.
    ///   it is not aligned.
    ///
    /// - if i = 2
    ///   second sub-interval (rest)
    ///   starts at this interval realtime end - rdur
    ///   and this interval musical time end - mdur
    ///   of realtime duration rdur.
    ///   it is not aligned.
    ///
    /// @param rdur must be strictly positive.
    /// @param mdur must be strictly positive.
    IntervalTree* split_back(const InputSegment*,
                             IntervalHeap*,
                             double rdur, Rational mdur,
                             size_t i);
    
    /// @brief return a the i-1th sub-interval
    /// of the division of this interval in n equal parts.
    /// the sub-interval returned is aligned.
    ///
    /// @param a must be > 1
    /// @param i must be smaller than a.
    /// @warning this interval must be aligned.
    IntervalTree* sub(const InputSegment*,
                      IntervalHeap*,
                      size_t a, size_t i);
    
protected:
    
    IntervalTree* _parent;
    
    /// @brief previous sibling Interval in the Interval tree.
    ///
    /// NULL if this Interval is the leftmost sibling
    IntervalTree* _previous_sibling;
    
    /// @brief direct access to subtrees.
    ///
    /// every entry in this map associate to
    /// an arity a a partition t1,...,ta of the root interval.
    std::map<size_t, std::vector<IntervalTree*>> _children;
    
    /// @brief top interval (root of interval tree).
    ///
    /// covering the whole length of the given input segment s
    /// inside-bar interval of musical time duration of 1 bar if flag bar is true
    /// multi-bar interval if flag bar is false.
    ///
    /// @warning the interval tree created is not registered to an interval heap.
    /// @warning not aligned.
    IntervalTree(const InputSegment* s,
                 Rational mend=Rational(1));
    
    /// @brief build an interval tree with
    /// musical-time bounds [mbegin, mbegin+mdur[ and
    /// real-time bounds [rbegin, rbegin+rdur[
    /// for the input segment s.
    ///
    /// @param p pointer to the parent.
    /// @param ps pointer to the previous sibling.
    /// @warning not aligned - must be aligned afterwards.
    /// @warning use only internaly construction of recursive paths.
    IntervalTree(const InputSegment* s,
                 Rational mbeg, Rational mend,
                 double rbeg, double rend,
                 size_t first,
                 IntervalTree* p = NULL,
                 IntervalTree* ps = NULL);
    
};


#endif /* IntervalTree_hpp */


/// @}
