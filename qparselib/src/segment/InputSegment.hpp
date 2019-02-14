//
//  InputSegment.hpp
//  qparse
//
//  Created by Florent Jacquemard on 06/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @defgroup segment Segment module
///
/// The `segment` module contains classes for abstract representation of data
/// in input processed by parsing.

/// @addtogroup segment
/// @{


#ifndef InputSegment_hpp
#define InputSegment_hpp

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>          // std::priority_queue
//#include <math.h>
//#include <cmath>

#include "init.hpp"
#include "Rational.hpp"
#include "MusEvent.hpp"
#include "MusPoint.hpp"
#include "Spiral.hpp"
#include "Label.hpp"


template<class P> class Atable;
template<class P> class Run;


// used to manage heaps of MusPoint* in subclasses
//class InputSegmentMusPointcomp
//{
//public:
//    InputSegmentMusPointcomp(const bool& revparam=false)
//    {
//        reverse = revparam;
//    }
//
//    bool operator() (const MusPoint* lhs, const MusPoint* rhs) const
//    {
//        if (reverse)
//            return (MusPointcomp(rhs, lhs));
//        else
//            return (MusPointcomp(lhs, rhs));
//    }
//
//private:
//    bool reverse;
//
//    static bool MusPointcomp(const MusPoint* lhs, const MusPoint* rhs);
//};
//
//typedef
//std::priority_queue<MusPoint*, std::vector<MusPoint*>, InputSegmentMusPointcomp>
//MusPointHeap;


/// @brief intermediate representation for input performance data
/// (sequence of timestamped events).
///
/// an input segment is made of:
/// - a time interval containing some timed events (muspoints),
///   always sorted by increasing realtime date (vector of events).
/// - a heap of floating points.
///
/// The links in points are indexes in the input segment,
/// where an index is a unique identifier of a point
/// in either of the two above structures.
///
/// The realtime duration of a linked point is the difference
/// of realtime dates (between the link and the point).
/// the realtime duration of a point without link (with unknown link) is zero.
///
/// @todo do the same think with musical time duration.
/// @todo suppr.  samplestosec
/// @todo suppr. member _res (resolution)
class InputSegment
{
public:
 
    /// @brief constructs an empty input segment (no events)
    /// @param b start date (in seconds)
    /// @param e end date (in seconds)
    InputSegment(double b=0, double e=0);
    
    InputSegment(const InputSegment&);
    
    /// @brief copy and resize.
    /// @param s input segment to copy.
    /// @param b new start date (in seconds)
    /// @param e new end date (in seconds)
    /// @warning copy only the events inside the new bounds.
    InputSegment(const InputSegment& s, double b, double e);
    
    virtual ~InputSegment();
    
    /// @brief real-time start date (in seconds) of segment.
    inline double rbegin() const { return _begin; }
    
    /// @brief real-time end date (in seconds) of segment.
    inline double rend() const { return _end; }
    
    /// @brief real-time total duration (in seconds) of segment.
    inline double rduration() const { return _len; }

    /// @brief musical total duration (in bars) of segment.
    ///
    /// will return MUSTIME_UNKNOWN if segment was not quantized.
    inline Rational mduration() const { return _mduration; }

    // resolution for quantization = number of samples in each bloc
    // @todo TBR (useless here)
    //inline size_t resolution() const { return _res; }
    
    /// @brief number of non-floating points in segment.
    size_t size() const;

    /// @brief iterators to the segment's contents.
    std::vector<MusPoint>::iterator begin();
    std::vector<MusPoint>::iterator end();
    std::vector<MusPoint>::const_iterator cbegin() const;
    std::vector<MusPoint>::const_iterator cend() const;
    
    /// @brief return a ref to the point of index i.
    /// - ith point in this input segment if 0 <= i < input segment size
    /// - or the -i-1th floating point    if heap size <= i < 0.
    /// @param i must be in the above range of values.
    const MusPoint& point(long i) const;
    
    /// @brief return the event of the point of index i.
    MusEvent* event(long i) const;
    
    /// @brief return the real-time date (in seconds)
    /// of the point of index i
    double rdate(long i) const;
    
    /// @brief return the real-time duration (in seconds)
    /// of the point of index i.
    double rduration(long i) const;

    /// @brief return the real-time duration (in seconds)
    /// of the given point.
    double rduration(const MusPoint& p) const;

    /// @brief return a reference to the musical-time date (in fraction of bar)
    /// of the point of index i.
    Rational& mdate(long i);
    
    /// @brief return a reference to the musical-time duration (in fraction of bar)
    /// of the point of index i.
    Rational& mduration(long i);
    
    // compare the points of index i and j
    // lexicographicaly by rdate, rduration, event MIDI number
    // return wether point[i] < point[j]
    //static bool point_comp(long i, long j);

    
    /// @brief insert new timestamped muspoint created from the parameters,
    /// at the end of the segment.
    ///
    /// @warning The realtime dateof the point must be after the current last point
    /// of this segment.
    /// @return the index of the inserted point (can be used as link).
    long add_back(MusEvent* e,
                  double rdate,
                  double rdur, // @todo TBR
                  bool on,
                  long link=MUSPOINTREF_NULL,
                  Rational mdate=MUSTIME_UNKNOWN,
                  Rational mduration=MUSTIME_UNKNOWN);
    
    long add_back(const MusPoint&);

    /// @brief create new timestamped muspoint from the parameters,
    /// and add the the heap of floating points (not in segment).
    ///
    /// (allocated and freed by this segment)
    /// @return the index of the new point (can be used as link).
    long add_floating(MusEvent* e,
                      double rdate,
                      double rdur,
                      bool on,
                      long link=MUSPOINTREF_NULL,
                      Rational mdate=MUSTIME_UNKNOWN,
                      Rational mduration=MUSTIME_UNKNOWN);

    long add_floating(const MusPoint&);
    
    // r must be strictly positive
    //void set_resolution(size_t r);
    
    /// @brief set end date.
    void close(double e);
    
    /// @brief quantization has been applied at least once.
    inline bool quantized() const { return (_mduration != MUSTIME_UNKNOWN); }
    
    /// @brief set the musical time date and duration of events
    /// in this given input segment,
    /// according to the best run for p in given table.
    ///
    /// @warning ptr type P must have interval.
    /// @warning all the musical dates and durations of events in this segment will be changed.
    template<class P>
    void quantize(Atable<P>* table, const P& p);
    
    /// @brief set the musical time date and duration of events
    /// in this given input segment,
    /// according to the best run for p in given table,
    /// starting from point number b in interval.
    ///
    /// @return the next point of input segment with musical date
    /// and duration yet unset after processing p.
    /// @warning ptr type P must have interval.
    /// @warning all the musical date of events must be unknown in seg.
    /// @warning all the musical durations of events must be unknown in seg.
    ///
    /// @todo TBR (replaced by quantize)
    template<class P>
    size_t quantizu(Atable<P>* table, const P& p, size_t b = 0);
    
    /// @brief pitch spelling. unwindowed.
    /// @warning this segment must have been quantized.
    void respell(int k=0);

    /// @brief pitch spelling
    /// with a sliding window of given musical duration.
    /// @warning this segment must have been quantized.
    void respell(Rational ws, int k=0);
    
    // save to text file
    // size_t save(std::string);
        
    // set resolution
    //void setResolution(size_t);
    
    /// @brief return wether the segment has the type of the code.
    ///
    /// type InputSegment:
    /// plain InputSegment imported from MIDI file (or text) without filters.
     virtual bool hasType(std::string code) const
    { return (code == "InputSegment"); }
    
    /// @brief write segment content to output stream.
    friend std::ostream& operator<<(std::ostream&, const InputSegment&);
    
    /// @brief print size to output stream.
    void print(std::ostream&) const;
    
protected:
    // resolution for quantization
    // = number of samples in each bloc
    // @todo TBR (useless here)
    //size_t _res;
    
    /// @brief start date (in seconds) of segment.
    double _begin;
    
    /// @brief start date (in seconds) of segment.
    double _end;
    
    /// @brief length (in seconds) of segment.
    double _len;
    
    /// @brief length (in bars) of segment.
    ///
    ///  is set at quantization
    Rational _mduration;
    
    // _index_events
    // _index_floating
    
    // segment is monophonic
    //bool _mono;
    
    /// @brief event list.
    ///
    /// polymorphic (mono or poly)
    std::vector<MusPoint> _events;

    /// @brief floating events.
    ///
    /// not in the list but can be linked by events on the list
    std::vector<MusPoint> _heap;

    /// @brief same as point but not const.
    MusPoint& ncpoint(long i);

    bool check_index(long i) const;
    
    /// @brief the event of index i is linked to the event of index j.
    ///
    /// @param j must be a valid index,
    /// @param i must be a valid and not NULL index,
    /// @warning both i and j can be in heap (negative index).
    /// @warning the point at i must not be linked (NULL link index).
    /// @warning the realtime date of i must be <= realtime date of j (if not NULL).
    void link(long i, long j);
    
private:
    template<class P>
    size_t quantize_assert(Atable<P>* table, const P& p, size_t b);
    
};




// these template methods cannot be defined in the cpp
// see e.g. https://stackoverflow.com/questions/115703/storing-c-template-function-definitions-in-a-cpp-file

template<class P>
void InputSegment::quantize(Atable<P>* table, const P& p)
{
    quantize_assert(table, p, 0);
}

/// @todo TBR
template <class P>
size_t InputSegment::quantizu(Atable<P>* table, const P& p, size_t b)
{
    // TBC. dirty. quantize(table, p) is public, with b private
    if (b == 0)
    {
        assert(this->size() > 0);
        // reset total musical length
        if (_mduration != MUSTIME_UNKNOWN)
        {
            WARN("reset musical length of input segment");
            _mduration = MUSTIME_UNKNOWN;
        }
    }
    
    return quantize_assert(table, p, b);
}


template <class P>
size_t InputSegment::quantize_assert(Atable<P>* table, const P& p, size_t b)
{
    assert(table);
    Run<P>* r = table->best(p);
    size_t j = b;
    
    if (r)
    {
        assert (! r->null());
        assert(r->complete());
        
        if (r->terminal())
        {
            label_t lab = r->label();
            assert(p.has_I());
            assert(p.interval());
            Rational onset = p.interval()->mbegin;
            Rational dur = p.interval()->mduration();
            assert(dur > Rational(0));
            assert(j < this->size());
            
            // contiuation : accumulate in current note
            if (Label::continuation(lab))
            {
                // skip an initial continuation
                if (this->mdate(j) == MUSTIME_UNKNOWN)
                {
                    assert(j == 0);
                    assert(this->mduration(j) == MUSTIME_UNKNOWN);
                    //this->mdate(j) = onset;
                    //this->mduration(j) = dur;
                }
                // continuation added to previous event
                else
                {
                    assert(onset == this->mdate(j) + this->mduration(j));
                    this->mduration(j) += dur;
                    _mduration += dur; // TBC dirty. must be set only once for j.
                }
            }
            else // grace notes + note
            {
                // current event unset, process it
                if (this->mdate(j) == MUSTIME_UNKNOWN)
                {
                    assert(this->mduration(j) == MUSTIME_UNKNOWN);
                }
                // current event set, start processing the next one
                else
                {
                    assert(this->mduration(j) != MUSTIME_UNKNOWN);
                    j++;
                }
                
                // grace notes
                for (size_t i=0; i < Label::nbGraceNotes(lab); i++)
                {
                    if (j < this->size())
                    {
                        assert (this->mdate(j) == MUSTIME_UNKNOWN);
                        assert(this->mduration(j) == MUSTIME_UNKNOWN);
                        this->mdate(j) = onset;
                        this->mduration(j) = Rational(0);
                    }
                    else
                    {
                        WARN("quantize: event {} (grace note) missing in input segment", j);
                    }
                    j++;
                }
                // note
                if (j < this->size())
                {
                    assert(this->mdate(j) == MUSTIME_UNKNOWN);
                    assert(this->mduration(j) == MUSTIME_UNKNOWN);
                    this->mdate(j) = onset;
                    this->mduration(j) = dur;
                    _mduration += dur; // TBC dirty. must be set only once for j.
                }
                else
                {
                    WARN("quantize: event {} (note) missing in input segment", j);
                }
            }
        }
        else
        {
            assert (r->inner());
            size_t a = r->arity();
            assert (a > 0);
            
            for (size_t i = 0; i < a; i++)
            {
                j = quantize_assert(table, (*r)[i], j);
            }
        }
    }
    else
    {
        ERROR("cannot quantize input segment wrt {}: no run", p);
    }
    
    return j;
}


#endif /* InputSegment_hpp */


/// @}
