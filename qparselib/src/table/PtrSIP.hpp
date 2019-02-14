//
//  PtrSIP.hpp
//  qparse
//
//  Created by Florent Jacquemard on 05/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{



#ifndef PtrSIP_hpp
#define PtrSIP_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <assert.h>

#include "init.hpp"
#include "trace.hpp"
#include "Rational.hpp"
//#include "Weight.hpp"
//#include "State.hpp"
//#include "Transition.hpp"
#include "PerformanceModel.hpp"
#include "Distance.hpp"
//#include "InputSegment.hpp"

//#include "IntervalTree.hpp"
//#include "IntervalHeap.hpp"
//#include "Environment.hpp"
#include "PtrSI.hpp"


struct SIPpointerHasher;

/// key in a parse table.
/// pointer to a (best) run for 1-best parsing for WTA and input segment.
///
/// a SIPpointer contains
/// - a state symbol:
///   either a WTA state or a meta state or a leaf label
/// - an aligned interval in the input segment
/// - pre and post values, known or not (partial ptr)
class SIPpointer : public SIpointer
{
public:

    /// dummy ptr.
    /// @see description in Ptr.hpp
    SIPpointer(pre_t pre=PP_UNKNOWN, pre_t post=PP_UNKNOWN);

    /// fake ptr for terminal run, contains only a label symbol.
    /// it is considered as complete
    /// @see description in Ptr.hpp
    SIPpointer(label_t);

    
    /// class specific
    /// top ptr (covering the whole input segment
    /// + given extension in realtime.
    ///
    /// @param env must contain an input segment and interval heap
    SIPpointer(Environment* env,
               state_t s,
               pre_t pre=0,
               pre_t post=0,
               Rational mdur=Rational(1),
               double rext=0);

    /// split ptr p in 2 parts.
    ///
    /// if position = 0, first part has (real-time/musical-time)
    /// durations rdur/mdur
    ///
    /// if position = 1, second part has (real-time/musical-time)
    /// durations rdur/mdur
    ///
    /// construct part number i (1 or 2)
    /// @param env must contain an input segment and interval heap
    /// @param rdur must be strictly positive.
    /// @param mdur must be strictly positive.
    /// @param i must be 1 or 2.
    /// @param s (state) can be WTA or Meta.
    SIPpointer(Environment*,
               const SIPpointer& p,
               double rdur, Rational mdur,
               bool position,
               size_t i,
               state_t s);
    
    /// sub-pointer or instance as leaf.
    /// @see description in Ptr.hpp
    SIPpointer(Environment*,
               const SIPpointer& p,
               size_t a, size_t i,
               state_t s);
    
    /// copy.
    SIPpointer(const SIPpointer&);
    
    /// instance as parent.
    /// @see description in Ptr.hpp
    SIPpointer(const SIPpointer& p,
               const SIPpointer& p0,
               const SIPpointer& p1);
    
    /// instance as next sibling.
    /// @see description in Ptr.hpp
    SIPpointer(const SIPpointer& p0, const SIPpointer& p1);
    
    /// @see description in Ptr.hpp
    virtual SIPpointer& operator= (const SIPpointer&);
    
    /// for use as key in a unordered_multimap.
    /// @see description in Ptr.hpp
    virtual bool operator==(const SIPpointer&) const;
    virtual bool operator!=(const SIPpointer&) const;

    /// for use as key in a multimap.
    /// @see description in Ptr.hpp
    virtual bool operator<(const SIPpointer&) const;
    
    /// @see description in Ptr.hpp
    virtual bool instance(const SIPpointer& p) const;
    
    /// @see description in Ptr.hpp
    virtual bool subsume(const SIPpointer& p) const;
    
    virtual bool has_I() const { return true; }
    virtual bool has_P() const { return true; }

    inline IntervalTree* interval() const { return _node; }
    inline pre_t pre() const { return _pre; }
    inline pre_t post() const { return _post; }

    /// @see description in Ptr.hpp
    virtual bool complete() const;
    
    /// @see description in Ptr.hpp
    /// @warning the _pre value must be known
    /// @warning _node must be set
    label_t label(const Transition& t) const;
    
    // see description in Ptr.hpp
    // = SIpointer
    //virtual bool divisible() const;
    
    /// @see description in Ptr.hpp
    virtual bool compatible(const label_t, bool abstract=true) const;

    /// @see description in Ptr.hpp
    virtual bool dummy() const;
    
    /// @see description in Ptr.hpp
    /// @param s input segment must not be NULL.
    virtual Weight terminalWeight(const InputSegment* s,
                                  const Transition& t) const;
    
    friend std::ostream& operator<<(std::ostream& o, const SIPpointer& p);
    
protected:
    //IntervalTree* _node;  // in SIpointer

    /// pre and post contain concrete labels (number of events)
    /// @see Label.hpp
    pre_t _pre;

    /// pre and post contain concrete labels (number of events)
    /// @see Label.hpp
    pre_t _post;
    
    // in SIpointer
    // bool equal_node(const SIPpointer&) const;
    
};



/// hash function for using as key in a table
/// rank is ignoreds : same as SpointerHasher
/// @see constant.h
struct SIPpointerHasher
{
    std::size_t operator()(const SIPpointer& p) const
    {
        using std::size_t;
        using std::hash;
      
        
        std::size_t h = HASH_SEED;
        h = h * HASH_FACTOR + hash<state_t>()(p.state());
        if (p.interval())
        {
            h = h * HASH_FACTOR + hash<double>()(p.interval()->rbegin);
            h = h * HASH_FACTOR + hash<double>()(p.interval()->rduration());
            h = h * HASH_FACTOR + hash<Rational>()(p.interval()->mbegin);
            h = h * HASH_FACTOR + hash<Rational>()(p.interval()->mduration());
        }
        h = h * HASH_FACTOR + hash<pre_t>()(p.pre());
        h = h * HASH_FACTOR + hash<pre_t>()(p.post());
        return h;
    }
};


#endif /* PtrSIP_hpp */


/// @}
