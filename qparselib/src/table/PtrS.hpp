//
//  PtrS.hpp
//  squant
//
//  Created by Florent Jacquemard on 10/12/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{


#ifndef PtrS_hpp
#define PtrS_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <assert.h>

#include "Rational.hpp"
#include "State.hpp"
//#include "Environment.hpp"
#include "Ptr.hpp"


//template <class P> class Run;
template <class P> class Atable;

struct SpointerHasher;

/// key in a parse table.
///
/// pointer to a (best) run for 1-best parsing for standard WTA.
///
/// a Spointer contains
/// - a state symbol: either
///    - a WTA state or
///    - a leaf label or
///    - a meta state
///
/// that defines two kind of pointers
/// - state pointer : points to a state of a WTA
/// - bar pointer : points to a solution for the n first bars in an input segment
///   = a sequence of n solutions pointing to the initial state of WTA.
///
/// all Spointers are complete
class Spointer : public Pointer
{
public:
    /// specific
    Spointer();    
    
    /// specific
    Spointer(label_t);
    
    // Spointer(state_t);
    
    /// top ptr (head of the main Run).
    /// @see description in Ptr.hpp
    /// @param bar must be true
    /// @param k must be 1
    /// @todo TBR deprecated (replace by specific constructor)
    Spointer(WTA* a, Environment* env,
             pre_t pre=0, pre_t post=0,
             Rational mlen=Rational(1),
             size_t k=1);

    /// sub-pointer or instance as leaf.
    /// @see description in Ptr.hpp
    /// @param p must have a wta state
    /// @param a
    /// @param i
    /// if a>0 and i=0, construct a copy of p.
    /// if a>0 and 0<i<=a, construct a copy a ptr with state s.
    Spointer(Environment* env,
             const Spointer& p, size_t a, size_t i, state_t s);
    
    /// copy.
    Spointer(const Spointer&);
    
    /// next sibling.
    /// @see description in Ptr.hpp
    /// @warning should not be called since p1 must be partial.
    Spointer(const Spointer& p0, const Spointer& p1);
    
    /// instance as parent.
    /// @see description in Ptr.hpp
    /// @warning should not be called since p must be partial.
    Spointer(const Spointer& p, const Spointer& p0, const Spointer& p1);
    
    /// @see description in Ptr.hpp
    virtual Spointer& operator= (const Spointer&);
    
    /// for use as key in a unorered_multimap.
    /// @see description in Ptr.hpp
    virtual bool operator==(const Spointer&) const;
    
    /// for use as key in a multimap.
    /// @see description in Ptr.hpp
    virtual bool operator<(const Spointer&) const;

    /// @see description in Ptr.hpp
    virtual bool instance(const Spointer& p) const;
    /// @see description in Ptr.hpp
    virtual bool subsume(const Spointer& p) const;

    virtual bool has_S() const { return true; }

    inline state_t state() const { return _state; }

    virtual bool complete() const;
    
    virtual label_t label(const Transition& t) const;

    virtual bool dummy() const;
    
    /// @warning this pointer must have a WTA state
    /// always return true in that case
    virtual bool divisible() const;
    
    friend std::ostream& operator<<(std::ostream& o, const Spointer& p);
    
protected:
    state_t  _state;
};




struct SpointerHasher
{
    std::size_t operator()(const Spointer& p) const
    {
        using std::size_t;
        using std::hash;
        return std::hash<size_t>()(p.state());
    }
};

#endif /* PtrS_hpp */


/// @}
