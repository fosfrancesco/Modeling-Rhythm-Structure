//
//  AlignedInterval.hpp
//  qparse
//
//  Created by Florent Jacquemard on 07/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#ifndef AlignedInterval_hpp
#define AlignedInterval_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>
#include <map>
#include <algorithm>    // std::min

#include "Rational.hpp"
#include "InputSegment.hpp"
#include "Interval.hpp"


/// @brief Extension of Interval with computed alignment of InputSegment points
/// onto left- and right-bounds.
///
/// The result of aligment can be consulted with function l/rsize, l/rfirst.
/// alignement is computed by function align.
///
/// The alignement is computed automatically for newly created intervals,
/// the other created intervals (multiple-bars intervals) are not aligned.
class AlignedInterval : public Interval
{
    friend class IntervalHeap;

public:
    
    //AlignedInterval();
    
    /// @brief Interval covering the whole length of the given input segment
    /// with given musical time length (number of bars).
    ///
    /// @param s given input segment
    /// @param mend given musical time length
    /// @param f_align flag says wether alignement must be computed for the interval.
    AlignedInterval(const InputSegment* s,
                    Rational mend=Rational(1),
                    bool f_align=false);
    
    // @todo TBR, replace by sub
    // Interval of the given input segment s
    // starting at the (real) begin date of s
    // of real duration the given value rdur
    // of musical duration 1 bar
    // bar of given number (default 0)
    // interval must fit in the given input segment
    // aligned
    //AlignedInterval(const InputSegment* s, double rdur, size_t bar=0);
    
    // next inside-bar interval in input segment.
    // musical duration is 1 bar
    // real duration is the same as the given interval
    // real begin bound is the real end bound of the given interval
    // the given interval must be inside-bar
    // interval must fit in the given input segment
    //AlignedInterval(const InputSegment*, const AlignedInterval&);
    
     /** @brief copy. */
    AlignedInterval(const AlignedInterval&);
    
     /** @warning do not deallocate the segment here. */
    ~AlignedInterval() {}
    
    virtual AlignedInterval& operator= (const AlignedInterval&);

    virtual bool operator==(const AlignedInterval&) const;

    /// @brief number of elements of input segment
    /// in the first half of this interval.
    ///
    /// @warning the interval must have been aligned.
    inline size_t lsize() const { assert(aligned()); return _seg_llen; }
    
    /// @brief index of the first element of input segment
    /// inside the fist half of this interval.
    ///
    /// @return out_of_range (= size of segment) if l_size() == 0.
    /// @warning the interval must have been aligned.
    inline size_t lfirst() const { assert(aligned()); return _seg_lbeg; }
    
    /// @brief number of elements of input segment
    /// in the second half of this interval.
    ///
    /// @warning the interval must have been aligned.
    inline size_t rsize() const { assert(aligned()); return _seg_rlen; }
    
    /// @brief index of the first element of input segment
    /// inside the second half of this interval.
    ///
    /// @return out_of_range (= size of segment) if r_size() == 0.
    /// @warning the interval must have been aligned.
    inline size_t rfirst() const { assert(aligned()); return _seg_rbeg; }
    
    /// @brief number of elements of input segment in this interval.
    ///
    /// @warning the interval must have been aligned.
    inline size_t size() const
    {  assert(aligned()); return (_seg_llen+_seg_rlen); }
    
    /// @brief index of the first element of input segment
    /// after the right bound of this interval
    /// (i.e. inside or after this interval).
    ///
    /// @return out_of_range (= size of segment) if there is none.
    inline size_t first() const { return _seg_first; }
    
    /// @brief index of the first element of input segment
    /// ouside this interval (= after the right bound).
    ///
    /// @return out_of_range (= size of segment) if there is none.
    /// @warning the interval must have been aligned.
    inline size_t next() const { assert(aligned()); return _seg_next; }
    
    /// @brief this interval contains at least an element of the input segment
    ///
    /// @warning the interval must have been aligned.
    inline bool inhabited() const
    { assert(aligned()); return ((_seg_llen + _seg_rlen) > 0); }
    
    /// @brief set the alignment parameters,
    /// starting from index b of input segment point
    /// and return the next index of point in input segment to be processed
    /// (first index at right of this interval)
    /// or the size of input segment (total # points) if end of segment is reached.
    ///
    /// @param s input segment processed
    /// @param b must be the index of a segment's point.
    /// it must be after the left bound of the interval (begin).
    /// it can be out of the interval, i.e. after the right bound (end).
    /// _seg_first is replaced by b.
    ///
    /// @warning The realtime begin date of this interval
    /// can be out of the input segment bounds.
    /// @warning The realtime end date of this interval
    /// can be out of the input segment bounds.
    /// In the later case, alignement is done like the input segment
    /// is padded with empty space up to the end of this interval.
    size_t align(const InputSegment* s, size_t b);
    
     /// @brief same as previous but uses _seg_first instead of argument b.
    size_t align(const InputSegment* s);

    /// @brief compute only the value of the next point
    /// (the first element of input segment after the right bound of this interval)
    /// starting from index b of input segment point.
    ///
    /// @param b same preconditions on b as for align.
    size_t rewind(const InputSegment* s, size_t b);

     /// @brief same as previous but uses _seg_first instead of arg. b.
    size_t rewind(const InputSegment*);
    
    /// @brief this interval has been aligned.
    bool aligned() const;
    
    friend std::ostream& operator<<(std::ostream&, const AlignedInterval&);
    
protected:
    /// @brief aligned interval with
    /// musical-time bounds [mbegin, mbegin+mdur[ and
    /// real-time bounds [rbegin, rbegin+rdur[
    /// for the input segment s.
    ///
    /// @param first must be the first element of input segment
    /// after the beginning of this interval.
    ///
    /// @param f_align flag says wether alignement must be computed for the interval.
    AlignedInterval(const InputSegment* s,
                    Rational mbeg, Rational mend,
                    double rbeg, double rend,
                    size_t first,
                    bool f_align=false);
    
private:
    /// @brief number of elements of input segment
    /// in the first half of this interval.
    size_t _seg_llen;
    
    /// @brief index of the first element of input segment
    /// inside the fist half of this interval
    /// or out_of_range (= size of segment) is there are none.
    ///
    /// zero if alignment has not been computed for this interval.
    size_t _seg_lbeg;
    
    /// @brief number of elements of input segment
    /// in the second half of this interval.
    size_t _seg_rlen;
    
    /// @brief index of the first element of input segment
    /// inside the second half of this interval
    /// or out_of_range (= size of segment) is there are none.
    ///
    /// zero if alignment has not been computed for this interval.
    size_t _seg_rbeg;
    
    /// @brief index of the first element of input segment
    /// ouside this interval (= after the right bound)
    /// or out_of_bound (= segment size) is there are none.
    size_t _seg_next;
    
    /// @brief index of the first element of input segment
    /// after the right bound of this interval
    /// (i.e. inside or after this interval).
    size_t _seg_first;
    
    bool _check_first(const InputSegment*);

    bool _check_next(const InputSegment*);
    
};



#endif /* AlignedInterval_hpp */


/// @}
