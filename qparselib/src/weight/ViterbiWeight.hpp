//
//  ViterbiWeight.hpp
//  qparse
//
//  Created by Florent Jacquemard on 27/04/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
//
/// @addtogroup weight
/// @{


#ifndef ViterbiWeight_hpp
#define ViterbiWeight_hpp

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <iostream>


#include "Weight.hpp"


/// @brief Viterbi semifield.
/// concrete Weight defined as a scalar value: probability of the best derivation
///
/// - domain : positive or null rational numbers in [0, 1]
/// - operators:
/// - add is max
/// - zero is 0
/// - mult is *
/// - one is 1
class ViterbiWeight : public LetterWeight
{
public:
    
    ViterbiWeight(const ViterbiWeight&);
    
    ~ViterbiWeight() { }
    
    ViterbiWeight& operator= (const ViterbiWeight&);

    /// @param rvalue must be a ViterbiWeight
    ViterbiWeight& operator= (const LetterWeight& rvalue);
    
    virtual LetterWeight* clone() const;
//    ViterbiWeight* clone() const;
    
    inline virtual Weight make(double v) const
    { return Weight(new ViterbiWeight(v)); }
    
    inline static Weight make_zero()
    { return Weight(new ViterbiWeight(0.0)); }

    inline virtual Weight get_zero() const
    { return ViterbiWeight::make_zero(); }

    inline static Weight make_one()
    { return Weight(new ViterbiWeight(1.0)); }

    inline virtual Weight get_one() const
    { return ViterbiWeight::make_one(); }

    virtual double norm() const; 
    
    // @todo TBR
    virtual void scalar(double);
    
    /// @brief multiplicative inverse.
    /// @warning this weight must not be zero.
    /// @todo TBR
    virtual void invert();
    
    virtual bool zero() const;
    
    virtual bool one() const;    
    
    virtual bool hasType(std::string code) const
    { return (code == "ViterbiWeight"); }
    
    friend std::ostream& operator<<(std::ostream& o, const ViterbiWeight& rhs)
    {
        o << rhs._val;
        return o;
    }
    
protected:
    
    double _val;
    
    /// @brief default is one
    //ViterbiWeight(double v=1.0):_val(v) {}
    ViterbiWeight(double);

    /// @brief rhs must be a ViterbiWeight.
    bool equal(const LetterWeight* rhs) const;
    
    /// @brief rhs must be a ViterbiWeight.
    bool smaller(const LetterWeight* rhs) const;
    
    /// @brief sum is min.
    /// @param rhs must be a ViterbiWeight.
    /// set this to the min of this and rhs.
    void add(const LetterWeight* rhs);
    
    /// @brief product is sum.
    /// @param rhs must be a ViterbiWeight.
    /// set this to the sum of this and rhs.
    void mult(const LetterWeight* rhs);
    
    void print(std::ostream&) const;
        
};



#endif /* ViterbiWeight_hpp */


/// @}
