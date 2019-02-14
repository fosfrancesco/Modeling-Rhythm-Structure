//
//  DurationList.hpp
//  qparse
//
//  Created by Florent Jacquemard on 02/11/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{



#ifndef DurationList_hpp
#define DurationList_hpp

#include <stdio.h>
#include <assert.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <map>
#include <vector>

#include "Rational.hpp"


/// list of rational durations to label nodes of WTA Runs for Kbest enum.
///
/// Duration is either
/// positive (event w or wo continuations -ties)
/// or null (grace note).
///
/// a duration list is made of 2 parts:
/// - _cont : initial duration (possibly null) tied to the previous duration list
/// - _main : main list of the other events (without ties)
/// it is represented by _cont[_main]
///
/// to speed up processing, every DurationList is associated a state value,
/// wich is one of the following:
///
/// - 0: empty list initial   0[]       _cont=0, _main empty
///     empty list assigned to a run at creation
///     before appending of children's run lists.
/// - 1: single continuation  1[]       _cont=1, _main empty
/// - 2: only-gn              0[0..0]   _cont=0, _main = [0,...,0]
/// - 3: single event         0[1]      _cont=0, _main = [1]
/// - 4: event                0[0..01]  _cont=0, _main = [0,...,0,1]
/// - 5: other incomplete
/// - 6: other complete
/// - 7: empty non initial
///      empty but other (children's) list have been appened already
///
/// - 0, 2, 5 are incomplete (sum != _summed)
/// - 1, 3, 4, 6, 7 are complete
/// - 1, 3, 4 are unit: the duration list represents one event and some grace notes
///
/// in quantization the length of list for a run correspoding
/// to a segment is equal to the length of the segment.
class DurationList
{
    friend class ValueList;
    
public:
    /// empty duration list.
    DurationList();
    
    DurationList(const DurationList&);

    /// copy of duration list l
    /// where all elements are multiplied by given Ratio q.
    /// @param l suration list to copy and update
    /// @param q given ratio for update
    DurationList(const DurationList& l, Rational q);
    
    /// read duration list from file.
    ///
    /// one ratio per line
    /// if the first line is negative ratio, it is a continuation
    /// all other line must contain positive or null ratios.
    /// @warning the file must not be empty.
    ///
    /// @todo TBR only for testing.
    DurationList(std::string);
    
    ~DurationList() {}
    
    DurationList& operator=(const DurationList&);

    bool empty() const;
    
    bool unit() const;
    
    size_t size() const { return (_main.size() + ((_continuation > 0)?1:0)); }
    
    Rational cont() const { return _continuation; }
    
    /// for checking.
    inline size_t summed() const { return _summed + _dummy; }
    
    std::list<Rational>::const_iterator begin() const { return _main.cbegin(); }
    std::list<Rational>::const_iterator end() const   { return _main.cend(); }
    
    bool complete() const;
    
    /// one (non null) continuation and no event in the main list.
    bool single_continuation() const;

    /// no continuation and only one event in the main list.
    bool single_event() const;

    /// no continuation and some grace notes (dur=0) + one event (dur>0)
    /// in the main list.
    bool event() const;
    
    /// number of grace note
    /// must be an event()
    size_t nbgn() const;
    
    /// sum of the elements of the duration list (including continuation)
    Rational length() const;
    
    /// add the event at the end of the main list.
    /// @warning fail if event cannot be added (makes sum > 1).
    /// @warning this list must not have have been summed with others.
    void add(Rational);

    /// push a continuation value.
    /// @warning fail if cont cannot be added (makes sum > 1).
    /// @warning this list must not have been summed with others.
    void addcont(Rational);
    
    /// divide by the number of lists summed.
    void normalize();
    
    // multiply all elements by given Ratio
    // @todo TBR
    //void mult(Rational);
    
    /// concatenation.
    /// @param rhs duration list to concatenate,  must not be empty,
    /// and must not be the summation of several duration lists.
    DurationList& operator+=(const DurationList& rhs);
    
    friend std::ostream& operator<<(std::ostream&, const DurationList&);
    
    friend inline bool operator==(const DurationList&, const DurationList&);
    friend inline bool operator!=(const DurationList&, const DurationList&);
    
private:
    /// duration to tie when appending to other list
    /// - zero if there is no continuation
    /// - positive rational otherwise
    Rational _continuation;

    /// list of events (without ties).
    std::list<Rational> _main;

    /// maintain the total duration of the list.
    /// for checking.
    Rational _sum;
    
    /// number of non-dummy (i.e. non empty) duration lists summed into this list.
    size_t _summed;

    /// number of dummy (i.e. empty) duration lists summed into this list.
    size_t _dummy;

    /// @see description of class DurationList for state values.
    unsigned int _state;
    
    /// for asserts (check _state  correctness).
    bool _check_empty() const;
    bool _check_complete() const;
    bool _check_single_continuation() const;
    bool _check_single_event() const;
    bool _check_event() const;
    bool _check_gracenotes() const;
    bool _check_unit() const;
    Rational _compute_length() const;

    /// the state value is correct.
    bool _check_state() const;
    
};


// hash function
//struct DurationListHasher
//{
//    std::size_t operator()(const DurationList& dl) const
//    {
//        using std::size_t;
//        using std::hash;
//        
//        size_t h = HASH_SEED;
//        h = h * HASH_FACTOR + hash<size_t>()(dl.size());
//        h = h * HASH_FACTOR + hash<double>()(toDouble(dl.cont()));
//        return h;
//    }
//};

namespace std {
    template <> struct hash<DurationList>
    {
        size_t operator()(const DurationList& d) const
        {
            return (hash<size_t>()(d.size()) ^
                    hash<double>()(toDouble(d.cont())));
        }
    };
}


inline bool operator==(const DurationList& lhs, const DurationList& rhs)
{
    if ((lhs._continuation == rhs._continuation) &&
        (lhs._main.size() == rhs._main.size()))
    {
        std::list<Rational>::const_iterator il = lhs._main.begin();
        std::list<Rational>::const_iterator ir = rhs._main.begin();
        while (il != lhs._main.end())
        {
            assert (ir != lhs._main.end());
            if (*il != *ir) { return false; }
            il++;
            ir++;
        }
        return true;
    }
    else
        return false;
}

inline bool operator!=(const DurationList& lhs, const DurationList& rhs)
{
    return !operator==(lhs,rhs);
}


#endif /* DurationList_hpp */


/// @}
