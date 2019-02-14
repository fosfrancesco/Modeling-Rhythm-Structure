//
//  CountingWeight.hpp
//  schemas
//
//  Created by Florent Jacquemard on 23/11/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup weight
/// @{


#ifndef CountingWeight_hpp
#define CountingWeight_hpp

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <iostream>
#include <vector>

#include "init.hpp"
#include "trace.hpp"
#include "Weight.hpp"


/// domain :
///   vectors of fixed dim k > 0
/// + FAIL = stuck (0 run in state s for 1 tree)
/// + ERROR = ambiguity in grammar (2 runs for 1 tree)
///
/// zero = FAIL
/// add : for all x, y vectors dim k
///       x + y = ERROR
///       ERROR absorbing for +
/// one = null vector of dim k
/// mult : for all x, y vectors dim k
///        x . y = component-wise sum
///        x . FAIL = FAIL . x = FAIL
///        FAIL . FAIL = FAIL
///        ERROR absorbing for .
class CountingWeight : public LetterWeight
{
public:
    CountingWeight(const CountingWeight&);

    ~CountingWeight();
    
    CountingWeight& operator= (const CountingWeight&);
    
    /// @param rhs must be a CountingWeight
    CountingWeight& operator= (const LetterWeight& rhs);
    
    CountingWeight* clone() const;
    
    /// @return ERROR
    /// should not be used
    virtual Weight make(double v) const;
    
//    static Weight make_zero();
    
    static Weight make_one(size_t);

    /// @param dim must be > 0
    /// @param i must be >=0
    /// @param i must be < dim
    static Weight make_unit(size_t dim, size_t i);

    virtual Weight get_zero() const;
    
    virtual Weight get_one() const;

    
    /// @warning do not use
    virtual double norm() const;
    
    /// @brief add to each component.
    virtual void scalar(double);
    
    /// @warning do not use
    virtual void invert() {}
    
    /// @warning this weight is zero (FAIL)
    virtual bool zero() const;

    /// @warning this weight is the error value
    bool fail() const { return zero(); }
    
    /// @warning this weight is the error value
    bool error() const;

    /// @warning this weight is one (null vector)
    virtual bool one() const;

    virtual size_t dim() const { return _dim; }
    
    virtual bool hasType(std::string code) const
    { return (code == "CountingWeight"); }
    
    friend std::ostream& operator<<(std::ostream& o, const CountingWeight& rhs);
    
protected:
    enum CWType { VECTOR, FAIL, ERROR };
    
    //size_t _dim;
    CWType _type;
    
    size_t _dim;
    
    std::vector<size_t> _counters;

    // zero
    //    CountingWeight();
    
    /// @warning must dim > 0
    CountingWeight(CWType t, size_t dim);
   
    /// @param rhs must be a CountingWeight
    virtual bool equal(const LetterWeight* rhs) const;
    
    /// @param rhs must be a CountingWeight
    /// @warning do not use
    virtual bool smaller(const LetterWeight* rhs) const;
    
    /// - FAIL is neutral
    /// - ERROR absorbing
    /// - VECTOR + VECTOR = ERROR
    /// @warning this and rhs must have same dimension
    virtual void add(const LetterWeight* rhs);
    
    /// - VECTOR . VECTOR = VECTOR with component-wise sum
    /// - VECTOR . FAIL = FAIL . VECTOR = FAIL
    /// - FAIL . FAIL = FAIL
    /// - ERROR absorbing
    /// @warning this and rhs must have same dimension
    virtual void mult(const LetterWeight* rhs);
    
    virtual void print(std::ostream&) const;
    virtual void rawprint(std::ostream&) const;
    
};


#endif /* CountingWeight_hpp */


/// @}
