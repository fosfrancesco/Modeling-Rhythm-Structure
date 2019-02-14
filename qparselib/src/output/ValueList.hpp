//
//  ValueList.hpp
//  qparse
//
//  Created by Florent Jacquemard on 29/07/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{



#ifndef ValueList_hpp
#define ValueList_hpp

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
#include "DurationList.hpp"


/// list of rational durations as components of value states.
///
/// Each duration is either
/// positive (event w or wo continuations -ties)
/// or null (grace note).
///
/// a value list is made of 2 parts:
/// - _cont : initial duration (possibly null) tied to the previous duration list
/// - _main : main list of the other events (without ties)
/// it is represented by _cont[_main]
class ValueList
{
    friend class DurationTree;
    
public:
    // empty duration list of given potential length
    // length cannot be changed afterwards
    ValueList(Rational);
    
    ValueList(const DurationList&);
    
    ValueList(const ValueList&);
    
    // read value list from file
    // one ratio per line
    // if the first line is negative ratio, it is a continuation
    // all other line must contain positive or null ratios
    // the file must not be empty
    ValueList(std::string);
    
    ~ValueList() {}
    
    ValueList& operator=(const ValueList&);
    
    bool empty() const;
    
    size_t size() const { return (_main.size() + ((_continuation > 0)?1:0)); }
    
    inline Rational length() const { return _length; }
    
    inline Rational cont() const { return _continuation; }
    
    std::list<Rational>::const_iterator begin() const { return _main.cbegin(); }
    std::list<Rational>::const_iterator end() const   { return _main.cend(); }
    
    bool complete() const;

    // one (non null) continuation and no event in the main list.
    bool single_continuation() const;
    
    // no continuation and only one event in the main list.
    bool single_event() const;
    
    //bool unit() const;
    
    // no continuation and some grace notes (dur=0) + one event (dur>0) in the main list.
    bool event() const;
    
    // number of grace note
    // must be an event()
    inline size_t nbgn() const { return _nbgn; };
    
    // add the event at the end of the main list
    // fail if event cannot be added (makes sum > 1)
    // this list must not have have been summed with others
    void add(Rational);
    
    // push a continuation value
    // fail if cont cannot be added (makes sum > 1)
    // this list must not have been summed with others
    void addcont(Rational);

    // return first element of main event list
    // main event list must not be empty.
    Rational front() const;
    
    // remove front element of main event list
    // return this element.
    // event list must not be empty.
    // continuation must not be null.
    Rational pop();

    // reset continuation.
    // return the former continuation value.
    Rational popcont();
    
    // remove value from continuation.
    // given value must be smaller than continuation.
    void popcont(Rational);
    
    
    friend std::ostream& operator<<(std::ostream&, const ValueList&);
    
    friend inline bool operator==(const ValueList&, const ValueList&);
    friend inline bool operator!=(const ValueList&, const ValueList&);
    
private:
    // duration to tie when appending to other list
    // zero if there is no continuation
    // positive rational otherwise
    Rational _continuation;
    
    // list of events (without ties)
    std::list<Rational> _main;
    
    // total duration that the list can contain, including continuation
    Rational _length;
    
    // sum of durations already added to list
    Rational _accu;

    // number of events added (excl. continuation)
    size_t _nbevt;

    // number of grace notes added
    size_t _nbgn;

};


// hash function
//struct ValueListHasher
//{
//    std::size_t operator()(const ValueList& dl) const
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
    template <> struct hash<ValueList>
    {
        size_t operator()(const ValueList& d) const
        {
            return (hash<size_t>()(d.size()) ^
                    hash<double>()(toDouble(d.cont())));
        }
    };
}


inline bool operator==(const ValueList& lhs, const ValueList& rhs)
{
    if ((lhs._continuation == rhs._continuation) &&
        // approx
        (lhs._length == rhs._length) &&
        (lhs._accu == rhs._accu) &&
        (lhs._nbevt == rhs._nbevt) &&
        (lhs._nbgn == rhs._nbgn) &&
        // exact
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

inline bool operator!=(const ValueList& lhs, const ValueList& rhs)
{
    return !operator==(lhs,rhs);
}


#endif /* ValueList_hpp */


/// @}
