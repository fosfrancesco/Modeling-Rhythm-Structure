//
//  PtrSI.hpp
//  squant
//
//  Created by Florent Jacquemard on 19/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{


#ifndef PtrSI_hpp
#define PtrSI_hpp

#include <stdio.h>
#include <assert.h>

#include "init.hpp"
#include "trace.hpp"
#include "Rational.hpp"
//#include "InputSegment.hpp"
//#include "State.hpp"
//#include "Transition.hpp"
//#include "Weight.hpp"
#include "PerformanceModel.hpp"
#include "Distance.hpp"
#include "IntervalTree.hpp"
#include "IntervalHeap.hpp"
//#include "Environment.hpp"
#include "PtrS.hpp"


struct SIpointerHasher;


class SIpointer : public Spointer
{
public:
    
    /// dummy ptr
    /// @see description in Ptr.hpp
    SIpointer();
    
    /// fake ptr for terminal run, contains only a label symbol
    /// it is considered as complete
    /// see description in Ptr.hpp
    SIpointer(label_t);

    /// class specific
    /// top ptr (covering the whole input segment + given extension in realtime,
    /// of given musical duration.
    /// @param env must contain an input segment and interval heap.
    SIpointer(Environment* env,
              state_t s,
              Rational mdur=Rational(1),
              double rext=0);
    
    /// split ptr p in 2 parts.
    ///
    /// if position = 0, first part has (real-time/musical-time)
    /// durations rdur/mdur
    ///
    /// if position = 1, second part has (real-time/musical-time)
    /// durations rdur/mdur
    /// construct part number i (1 or 2)
    /// @param env must contain an input segment and interval heap
    /// @param rdur must be strictly positive.
    /// @param mdur must be strictly positive.
    /// @param i must be 1 or 2.
    /// @param s can be WTA state or Meta state.
    SIpointer(Environment*,
              const SIpointer& p,
              double rdur, Rational mdur,
              bool position,
              size_t i,
              state_t s);
    
    /// sub-pointer or instance as leaf.
    /// @see description in Ptr.hpp
    SIpointer(Environment*,
              const SIpointer& p,
              size_t a, size_t i,
              state_t s);
    
    /// copy.
    SIpointer(const SIpointer&);
    
    /// instance as parent.
    /// @see description in Ptr.hpp
    SIpointer(const SIpointer& p,
               const SIpointer& p0,
               const SIpointer& p1);
    
    /// instance as next sibling.
    /// @see description in Ptr.hpp
    SIpointer(const SIpointer& p0, const SIpointer& p1);
    
    /// @see description in Ptr.hpp
    virtual SIpointer& operator= (const SIpointer&);
    
    /// for use as key in a unordered_multimap.
    /// @see description in Ptr.hpp
    virtual bool operator==(const SIpointer&) const;
    virtual bool operator!=(const SIpointer&) const;
    
    /// for use as key in a multimap.
    /// @see description in Ptr.hpp
    virtual bool operator<(const SIpointer&) const;
    
    /// @see description in Ptr.hpp
    virtual bool instance(const SIpointer& p) const;
    
    /// @see description in Ptr.hpp
    virtual bool subsume(const SIpointer& p) const;
    
    virtual bool has_I() const { return true; }
    virtual bool has_P() const { return false; }
    
    inline IntervalTree* interval() const { return _node; }
    
    /// @see description in Ptr.hpp
    virtual bool complete() const;
    
    /// @see description in Ptr.hpp
    /// the _pre value must be known
    /// _node must be set
    virtual label_t label(const Transition& t) const;
    
    /// @see description in Ptr.hpp
    ///
    /// if this pointer has a WTA state:
    ///   it is not worth descending when this pointer corresponds to
    ///   an input sub-segment not inhabited.
    ///
    /// if this pointer has a Meta state:
    ///   it is not worth descending when this ptr corresponds to
    ///   an empty segment.
    virtual bool divisible() const;
    
    /// @see description in Ptr.hpp
    virtual bool compatible(const label_t, bool abstract=true) const;
    
    /// @see description in Ptr.hpp
    virtual bool dummy() const;
    
    /// @see description in Ptr.hpp
    /// @warning input segment must not be NULL.
    virtual Weight terminalWeight(const InputSegment*,
                                  const Transition&) const;
    
    friend std::ostream& operator<<(std::ostream& o, const SIpointer& p);
    
protected:
    IntervalTree* _node;  // should not be modified
    
    bool equal_node(const SIpointer&) const;
};



/// hash function for using as key in a table.
/// rank is ignoreds : same as SpointerHasher
struct SIpointerHasher
{
    std::size_t operator()(const SIpointer& p) const
    {
        using std::size_t;
        using std::hash;
        assert(p.interval());
        
        // see constant.h
        std::size_t h = HASH_SEED;
        h = h * HASH_FACTOR + hash<state_t>()(p.state());
        h = h * HASH_FACTOR + hash<double>()(p.interval()->rbegin);
        h = h * HASH_FACTOR + hash<double>()(p.interval()->rduration());
        h = h * HASH_FACTOR + hash<Rational>()(p.interval()->mbegin);
        h = h * HASH_FACTOR + hash<Rational>()(p.interval()->mduration());
        return h;
    }
};


#endif /* PtrSI_hpp */


/// @}
