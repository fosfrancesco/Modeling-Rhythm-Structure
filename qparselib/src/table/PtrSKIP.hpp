//
//  PtrSKIP.hpp
//  qparse
//
//  Created by Florent Jacquemard on 14/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{


#ifndef PtrSKIP_hpp
#define PtrSKIP_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <assert.h>

//#include "State.hpp"
//#include "Ptr.hpp"
#include "PtrSIP.hpp"

//template <class P> class Atable;

struct SKIPpointerHasher;


class SKIPpointer : public SIPpointer
{
public:
    /// dummy ptr.
    /// @see description in Ptr.hpp
    SKIPpointer();
    
    /// specific
    /// fake ptr for terminal run, contains only a label symbol.
    /// it is considered as complete
    /// @see description in Ptr.hpp
    SKIPpointer(label_t, size_t k=1);
    
    /// @todo TBR deprecated
    SKIPpointer(Environment* env,
                pre_t pre=0,
                pre_t post=0,
                bool bar=false,
                size_t k=1);
    
    /// class specific
    /// top ptr (covering the whole input segment.
    /// @warning env must contain an input segment and interval heap.
    SKIPpointer(Environment* env,
                state_t s,
                pre_t pre=0,
                pre_t post=0,
                Rational mdur=Rational(1),
                size_t k=1);
    
    /// sub-pointer or instance as leaf.
    /// @see description in Ptr.hpp
    /// @warning no default duration for ambiguity reasons
    SKIPpointer(Environment* env,
                const SKIPpointer& p,
                size_t a, size_t i,
                state_t s);
    
    /// copy.
    SKIPpointer(const SKIPpointer&);
    
    
    /// next sibling.
    /// @see description in Ptr.hpp
    /// @warning should not be called since p1 must be partial
    SKIPpointer(const SKIPpointer& p0, const SKIPpointer& p1);
    
    /// instance as parent.
    /// @see description in Ptr.hpp
    /// @warning should not be called since p must be partial
    SKIPpointer(const SKIPpointer& p, const SKIPpointer& p0, const SKIPpointer& p1);
    
    /// @see description in Ptr.hpp
    virtual SKIPpointer& operator= (const SKIPpointer&);
    
    /// @see description in Ptr.hpp
    virtual bool operator==(const SKIPpointer&) const;
    
    /// @see description in Ptr.hpp
    virtual bool instance(const SKIPpointer& p) const;

    /// @see description in Ptr.hpp
    virtual bool subsume(const SKIPpointer& p) const;
    
    virtual bool has_K() const { return true; }
    
    inline virtual size_t rank() const { return _rank; }
    
    virtual void incr();
    
    friend std::ostream& operator<<(std::ostream& o, const SKIPpointer& p);
    
protected:
    /// k as in k-best.
    size_t _rank;
};



/// hash function for using as key in a table.
/// @warning rank is ignored : same as SpointerHasher
struct SKIPpointerHasher
{
    std::size_t operator()(const Spointer& p) const
    {
        using std::size_t;
        using std::hash;
        return std::hash<size_t>()(p.state());
    }
};


#endif /* PtrSKIP_hpp */


/// @}
