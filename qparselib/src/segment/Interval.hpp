//
//  Interval.hpp
//  qparse
//
//  Created by Florent Jacquemard on 06/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#ifndef Interval_hpp
#define Interval_hpp

#include <stdio.h>

#include <assert.h>
#include <vector>
#include <map>

#include "init.hpp"
#include "Rational.hpp"
#include "InputSegment.hpp"
//#include "IntervalHeap.hpp"

 /// @brief an Interval in an input segment
 /// with realtime bounds (seconds)
 /// and musical bounds (fraction of bars).
class Interval
{
    friend class IntervalHeap;
    
public:
    
    //Interval();
    
     /// @brief  top interval constructed from an input segment.
     ///
     /// Interval covering the whole length of the given input segment s
     /// with given musical time length (number of bars)
    Interval(const InputSegment* s, Rational mend=Rational(1));

    // @todo TBR, replace by sub
    // Interval of the given input segment s
    // starting at the (real) begin date of s
    // of real duration the given value rdur
    // of musical duration 1 bar
    // bar of given number (default 0)
    // interval must fit in the given input segment
    //Interval(const InputSegment* s, double len, size_t bar=0);

    // @todo TBR use sub
    // next inside-bar interval in input segment.
    // musical duration is 1 bar
    // real duration is the same as the given interval
    // real begin bound is the real end bound of the given interval
    // the given interval must be inside-bar
    // interval must fit in the given input segment
    //Interval(const InputSegment*, const Interval&);

    /// @brief copy.
    Interval(const Interval&);

    /// @brief used for copy of downcasted IntervalTree.
    Interval(Interval*);
    
    /// @warning do not deallocate the segment here.
    ~Interval() {}
    
    virtual Interval& operator= (const Interval&);
    
    /// @brief for using Interval as key in map.
    virtual bool operator==(const Interval&) const;
    
    // number of bars (in input segment)
    // before the begining of this interval
    // @todo TBR
    //size_t bars;
    
    /// @brief musical-time start.
    /// starting date of interval, in musical-time (number of bars)
    /// relatively (shift) to current bar start.
    Rational mbegin;

    /// @brief musical-time end.
    ///
    /// ending date of interval, in musical-time (number of bars)
    /// relatively (shift) to current bar start.
    ///
    /// 0 for meta interval (in this case begin must be 0).
    ///
    /// @warning must be >= begin.
    Rational mend;
    
    inline Rational mduration() const
    { return (mend - mbegin);  }
    
    /// @brief real-time start.
    ///
    /// starting date of interval, in real-time (seconds)
    /// i.e. real-time date aligned with the musical date bars + begin
    double rbegin;
    
    /// @brief real-time end.
    ///
    /// ending date of interval, in real-time (seconds)
    /// i.e. real date aligned with he musical date bars + end.
    /// must be > rbegin.
    double rend;
    
    inline double rduration() const
    { return (rend - rbegin);  }
    
    bool insideBar() const;
    
    friend std::ostream& operator<<(std::ostream&, const Interval&);
    
protected:
    
    /// @brief build an interval with
    /// musical-time bounds [mbegin, mbegin+mdur[ and
    /// real-time bounds [rbegin, rbegin+rdur[
    /// for the input segment s.
    ///
    /// @warning not aligned.
    Interval(const InputSegment* s,
             Rational mbeg, Rational mend,
             double rbeg, double rend);
    
private:
    bool sanity_check(const InputSegment*);
    bool sanity_check();

};




/// @brief hash function for using interval as key in a unordered map.
///
/// musical time bounds are ignored here
/// @todo TBR
struct IntervalHasher
{
    std::size_t operator()(const Interval& p) const
    {
        using std::size_t;
        using std::hash;

        // see constant.h
        size_t h = HASH_SEED;
        h = h * HASH_FACTOR + hash<double>()(p.rbegin);
        h = h * HASH_FACTOR + hash<double>()(p.rend);
        h = h * HASH_FACTOR + hash<Rational>()(p.mbegin);
//        h = h * HASH_FACTOR + hash<long>()(p.mbegin.numerator());
//        h = h * HASH_FACTOR + hash<long>()(p.mbegin.denominator());
        h = h * HASH_FACTOR + hash<Rational>()(p.mend);
//        h = h * HASH_FACTOR + hash<long>()(p.mduration().numerator());
//        h = h * HASH_FACTOR + hash<long>()(p.mduration().denominator());
        return h;
    }
};


//namespace std {
//    template <> struct hash<Interval>
//    {
//        size_t operator()(const Interval& p) const
//        {
//            return std::hash<size_t>()(p.rbegin) ^
//                   std::hash<size_t>()(p.rend);
//        }
//    };
//}



#endif /* Interval_hpp */


/// @}
