//
//  Distance.hpp
//  qparse
//
//  Created by Florent Jacquemard on 04/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup weight
/// @{


#ifndef Distance_hpp
#define Distance_hpp

#include <stdio.h>

#include "init.hpp"
#include "trace.hpp"
#include "AlignedInterval.hpp"
#include "Weight.hpp"
#include "TropicalWeight.hpp"

/// @brief concrete Weight domain identical to TropicalWeight
/// with an additional constructor to compute
/// a distance value from an Alignement,
/// obtained as the sum of the pointwise distances.
///
/// @warning a Distance hasType "TropicalWeight"
///
/// ALT: implement as vector of pointwise distances
class Distance: public TropicalWeight
{
public:
    /// defaut = null distance - not unknown
    Distance(double d=0.0):TropicalWeight(d) { }
    
    /// weight which is the distance defined by alignment for input segment
    /// not unknown.
    Distance(const InputSegment* s, const AlignedInterval* p);

    Distance(const Distance& d):TropicalWeight(d) { }

    ~Distance() { }
    
    Distance& operator= (const Distance&);

    virtual Distance* clone() const;
    
    inline virtual Weight make(double v) const
    { assert (v > 0); return Weight(new Distance(v)); }
    
    inline static Weight make_zero()
    { return Weight(new Distance(-1.0)); }

    inline virtual Weight get_zero() const
    { return Distance::make_zero(); }
    
    inline static Weight make_one()
    { return Weight(new Distance(0.0)); }
    
    inline virtual Weight get_one() const
    { return Distance::make_one(); }

protected:
    
    // @todo TBR
    // linear combination of this distance value and the given weight
    // different from += (Weight&) car utilise le facteur alpha
    //  void combine(const Weight&);

    virtual void print(std::ostream&) const;
    
    
    // OLD version
    // A Distance is a Weight measure made of
    // - a vector of pointwise distances to an input onset vector
    // - a mask (bitvector)
    // - the dimension is the length of the input onset vector
    // - the length (Euclidean) of the vector (norm) = Weight's val
    
    // vector length
    //int _dim;
    
    //vector<double> _dist;
    
private:
    /// distance to the closest point before j not at the same rdate as j.
    double dist_prev(const InputSegment* s, size_t j);

    /// distance to the closest point after j not at the same rdate as j.
    double dist_next(const InputSegment* s, size_t j);
    
    /// sum of the 2 above or 1 if sum is null.
    double distcoeff(const InputSegment* s, size_t j);
};


#endif /* Distance_hpp */


/// @}
