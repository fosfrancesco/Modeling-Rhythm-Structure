//
//  TropicalWeight.hpp
//  qparse
//
//  Created by Florent Jacquemard on 11/03/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup weight
/// @{


#ifndef TropicalWeight_hpp
#define TropicalWeight_hpp

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <iostream>

#include "Weight.hpp"


/// @brief concrete Weight defined as a scalar value: non-negative weights.
///
/// - domain : positive or null double + infinity
/// - operators of tropical algebra:
/// - add is min
/// - zero is infinity
/// - mult is +
/// - one is 0
class TropicalWeight : public LetterWeight
{
public:
    
    TropicalWeight(const TropicalWeight&);
    
    ~TropicalWeight() { }
    
    TropicalWeight& operator= (const TropicalWeight&);

    /// @warning rvalue must be a TropicalWeight
    TropicalWeight& operator= (const LetterWeight&);

    TropicalWeight* clone() const;

    ///  @warning value must be positive
    ///
    /// @todo TBR : stricly positive
    inline virtual Weight make(double v) const
    { assert (v >= 0); return Weight(new TropicalWeight(v)); }

    inline static Weight make_zero()
    { return Weight(new TropicalWeight(-1.0)); }

    inline virtual Weight get_zero() const
    { return TropicalWeight::make_zero(); }

    inline static Weight make_one()
    { return Weight(new TropicalWeight(0.0)); }

    inline virtual Weight get_one() const
    { return TropicalWeight::make_one(); }

    /// @warning must not be zero (infinity)
    virtual double norm() const;
    
    virtual void scalar(double);
    
    /// @brief multiplicative inverse.
    /// @warning this weight must not be zero.
    virtual void invert();
    
    virtual bool zero() const;
    
    virtual bool one() const;

    
    
    
    
    // Generic weight values for construction of schemas
    
    /// @brief penalty by arity.
    static TropicalWeight penalty[18];
    
    /// @brief penalty for an inner node.
    static TropicalWeight inner(size_t);
    
    /// @brief penalty for a tie.
    static TropicalWeight tie();
    
    /// @brief penalty for given number of grace notes in a leaf.
    ///
    /// - 0 = 1 event, no grace note
    /// - 1 = 1 event, 1 grace note
    /// - 2 = 1 event, 2 grace notes
    /// - etc
    static TropicalWeight gracenote(size_t);
    
    virtual bool hasType(std::string code) const
    { return (code == "TropicalWeight"); }

    friend std::ostream& operator<<(std::ostream& o, const TropicalWeight& rhs)
    {
        if (rhs.zero())
        {
            o << "+∞";
        }
        else
        {
            o << rhs._val;
        }
        return o;
    }
    
protected:
    double _val;
    
    /// default is one
    TropicalWeight():_val(0) {}
    
    TropicalWeight(double v):_val(v) {  }
    
    /// @param rhs must be a TropicalWeight
    virtual bool equal(const LetterWeight* rhs) const;
    
    /// @param rhs must be a TropicalWeight
    virtual bool smaller(const LetterWeight* rhs) const;
    
    /// @brief sum is min.
    /// @param rhs must be a TropicalWeight
    /// set this to the min of this and rhs
    virtual void add(const LetterWeight* rhs);
    
    /// @brief product is sum.
    /// @param rhs must be a TropicalWeight
    /// set this to the sum of this and rhs
    virtual void mult(const LetterWeight* rhs);
    
    virtual void print(std::ostream&) const;
       
};


#endif /* TropicalWeight_hpp */


/// @}
