//
//  FloatWeight.hpp
//  qparse
//
//  Created by Florent Jacquemard on 08/10/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup weight
/// @{


#ifndef FloatWeight_hpp
#define FloatWeight_hpp

#include <stdio.h>

#include "init.hpp"
#include "trace.hpp"
#include "Weight.hpp"

/// @brief concrete Weight defined as a scalar value.
///
/// - domain : double
/// - operators
/// - add is +
/// - zero is 0.0
/// - mult is *
/// - one is 1.0
class FloatWeight: public LetterWeight
{
public:
    /// defaut = null weight - not unknown
    FloatWeight(double d=0.0);
    
    FloatWeight(const FloatWeight&);
        
    FloatWeight& operator= (const FloatWeight&);

    FloatWeight& operator= (const LetterWeight&);    

    virtual FloatWeight* clone() const;
    
    inline virtual Weight make(double v) const
    { return Weight(new FloatWeight(v)); }
    
    inline static Weight make_zero()
    { return Weight(new FloatWeight(0.0)); }

    inline virtual Weight get_zero() const
    { return FloatWeight::make_zero(); }

    inline static Weight make_one()
    { return Weight(new FloatWeight(1.0)); }

    inline virtual Weight get_one() const
    { return FloatWeight::make_one(); }

    inline virtual double norm() const
    { return (_val); }
    
    virtual void scalar(double);
    
    /// @brief multiplicative inverse.
    /// @warning this weight must not be zero.
    virtual void invert();
    
    virtual bool zero() const;
    
    virtual bool one() const;
    
    friend std::ostream& operator<<(std::ostream& o, const FloatWeight& rhs);
    
    bool equal(const FloatWeight& rhs) const;
    
    bool smaller(const FloatWeight& rhs) const;
    
    void add(const FloatWeight& rhs);
    
    void mult(const FloatWeight& rhs);
    
    inline virtual bool hasType(std::string code) const
    { return (code == "FloatWeight"); }
    
protected:
    
    double _val;
    
    /// @param rhs must be a FloatWeight.
    virtual bool equal(const LetterWeight* rhs) const;
    
    /// @param rhs must be a FloatWeight.
    virtual bool smaller(const LetterWeight* rhs) const;
    
    /// @param rhs must be a FloatWeight.
    virtual void add(const LetterWeight* rhs);
    
    /// @param rhs must be a FloatWeight.
    virtual void mult(const LetterWeight* rhs);
    
    virtual void print(std::ostream&) const;
};

#endif /* FloatWeight_hpp */


/// @}
