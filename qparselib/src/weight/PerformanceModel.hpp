//
//  PerformanceModel.hpp
//  qparse
//
//  Created by Florent Jacquemard on 10/05/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup weight
/// @{


#ifndef PerformanceModel_hpp
#define PerformanceModel_hpp

#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <math.h>       /* erf */

#include "init.hpp"
#include "Interval.hpp"
#include "AlignedInterval.hpp"
#include "ViterbiWeight.hpp"


/// @brief extention of ViterbiWeight with a model of performance.
///
/// compute probabilities of alignement of input points to a score
/// following a truncated Gaussian distribution
/// with parameters mu (default 0) and sigma (default 1)
/// and is truncated on the interval [a,b] (values in samples)
/// and shifted.
class PerfoWeight : public ViterbiWeight
{
public:

    PerfoWeight(double v):ViterbiWeight(v) {}
    
    // probability of alignement at given position (in samples)
    // in the interval defined by the given path
    // following a truncated normal distribution shifted to the bounds of the path
    // @todo TBR
    //PerfoWeight(size_t, const Interval&);

    /// @brief probability of positions in the given alignement
    /// in the interval defined by the given path.
    ///
    /// = product of the probabilities for the points in the alignement,
    /// + the pre points on the left bound
    /// - the post rightmost points in the right half of the alignment
    PerfoWeight(const InputSegment* s,
                const AlignedInterval* p,
                pre_t pre = 0, pre_t post = 0);
    
    PerfoWeight& operator= (const PerfoWeight&);
    
    /// @param rhs must be a PerfoWeight
    PerfoWeight& operator= (const LetterWeight& rhs);
    

    ~PerfoWeight() { }
    
    PerfoWeight* clone() const;
    
    inline virtual Weight make(double v) const
    { return Weight(new PerfoWeight(v)); }

    /// @warning type code is still "ViterbiWeight"
    virtual bool hasType(std::string code) const
    { return (code == "ViterbiWeight"); }
    
    static void set_sigma2(double);
    
    friend std::ostream& operator<<(std::ostream& o, const PerfoWeight& rhs)
    {
        o << rhs._val;
        return o;
    }
    
protected:
    
    // @todo perf. weight separated from _val
    
private:
    
    static const double sq2;     // sqrt(2)
    static const double sqpi;    // = sqrt(pi)
    
    static double mu;
    static double sigma2;
    static double sigma;
    static double a;
    static double b;
    static double Z;
    
    double scale = 1;
    
    /// @brief Gaussian pr. density distribution truncated to [a,b].
    static double trnorm(double x);
    
    // align(x, a, b)
    // probability of alignement at position x in interval [a, b[
    // (a and b are the bounds of a Path)
    //
    // defined as Gaussian distribution truncated to [a,b] by
    // setting mean as center of [a,b] and
    // switching both halves of [a,b]
    // @todo TBR
    //static double align(double, size_t, size_t, const double sigma);
  
};


#endif /* PerformanceModel_hpp */


/// @}
