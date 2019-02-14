//
//  PtrSK.hpp
//  squant
//
//  Created by Florent Jacquemard on 15/12/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{




#ifndef PtrSK_hpp
#define PtrSK_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <assert.h>

#include "Rational.hpp"
//#include "State.hpp"
//#include "Ptr.hpp"
#include "PtrS.hpp"

template <class P> class Atable;

struct SKpointerHasher;

/// pointer to a (best) run.
/// for k-best parsing with standard WTA
/// a SKpointer contains
/// - a state symbol (see Spointer)
/// - a rank:
///     - 0 if the state symbol is a leaf label,
///     - > 0 otherwise
///   in the case of Viterbi algo (1-best), the rank is defaulted to 1
///
/// all SKpointer's are complete.
class SKpointer : public Spointer
{
public:
    /// specific
    SKpointer();
    
    /// specific
    SKpointer(label_t, size_t k=1);
    
    /// top ptr.
    /// @see description in Ptr.hpp
    /// @param bar must be true
    /// @todo TBR deprecated (replace by specific constructor)
    SKpointer(WTA* a, Environment* env,
              pre_t pre=0,
              pre_t post=0,
              Rational mlen=Rational(1),
              size_t k=1);
    
    /// sub-pointer or instance as leaf.
    /// @see description in Ptr.hpp
    /// @warning no default duration for ambiguity reasons.
    SKpointer(Environment*,
              const SKpointer& p,
              size_t a, size_t i,
              state_t s);

    /// copy.
    SKpointer(const SKpointer&);
    

    /// next sibling.
    /// @see description in Ptr.hpp
    /// @warning should not be called since p1 must be partial
    SKpointer(const SKpointer& p0, const SKpointer& p1);

    /// instance as parent.
    /// @see description in Ptr.hpp
    /// @warning should not be called since p must be partial
    SKpointer(const SKpointer& p, const SKpointer& p0, const SKpointer& p1);
    
    /// @see description in Ptr.hpp
    virtual SKpointer& operator= (const SKpointer&);
    
    /// @see description in Ptr.hpp
    virtual bool operator==(const SKpointer&) const;
    
    /// @see description in Ptr.hpp
    virtual bool instance(const SKpointer& p) const;
    
    /// @see description in Ptr.hpp
    virtual bool subsume(const SKpointer& p) const;
    
    virtual bool has_K() const { return true; }
    
    inline virtual size_t rank() const { return _rank; }

    virtual void incr();    
    
    friend std::ostream& operator<<(std::ostream& o, const SKpointer& p);

protected:
    /// k as in k-best
    size_t  _rank;
};



/// hash function for using as key in a table
/// rank is ignoreds : same as SpointerHasher
struct SKpointerHasher
{
    std::size_t operator()(const Spointer& p) const
    {
        using std::size_t;
        using std::hash;
        return std::hash<size_t>()(p.state());
    }
};


#endif /* PtrSK_hpp */


/// @}
