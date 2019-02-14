//
//  PerformanceModel.cpp
//  qparse
//
//  Created by Florent Jacquemard on 10/05/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup weight
/// @{


#include "PerformanceModel.hpp"


const double PerfoWeight::sq2 = 1.41421356237;
const double PerfoWeight::sqpi = 1.772453850905516;

double PerfoWeight::mu = 0.0;
double PerfoWeight::sigma2 = CST_SIGMA2;
double PerfoWeight::sigma = sqrt(PerfoWeight::sigma2);

double PerfoWeight::a = -4.0;
double PerfoWeight::b = 4.0;
double PerfoWeight::Z = sq2 * sqpi * sigma * erf(b/(sq2 * sigma));
//const double Z = sq2 * sqpi * sigma * (erf(b/(sq2 * sigma)) - erf(a/(sq2 * sigma)));


// @todo TBR?
//PerfoWeight::PerfoWeight(size_t x, const Interval& p):
//ViterbiWeight(1)
//{
//    double lbound = p.rbegin;
//    double rbound = p.rend;
//    double xd = x;
//
//    assert (lbound <= xd);
//    assert (xd < rbound);
//    
//    double len = p.rduration();
//    double scale = len / (b - a);
//    
//    if (xd <= len/2.0)
//    {
//        _val = trnorm((xd - lbound)/scale);
//    }
//    else
//    {
//        _val = trnorm((x - rbound)/scale);
//    }
//    if (_val == 0)
//        ERROR("null perfo weight [{} {}]", lbound, rbound);
//}


//PerfoWeight::PerfoWeight(const Alignment& p, size_t pre, size_t post):
//ViterbiWeight(1)
//{
//    double lbound = p.rbegin;
//    double rbound = p.rend;
//    assert (lbound >= p.input().begin());
//    assert (lbound <= p.input().end());
//    assert (rbound >= p.input().begin());
//    assert (rbound <= p.input().end());
//    assert (lbound <= rbound);
//
//    double scale = p.length() / (b - a);
//
//    // pre points on the leftmost value of the interval
//    _val *= pow(trnorm(0), pre);
//
//    // p.l_size() points in the left hal of the interval
//    size_t i = p.l_first();
//    for (size_t j = 0; j < p.l_size(); j++)
//    {
//        double x = p.input().rdate(i+j);
//        assert (lbound <= x);
//        assert (x < rbound);
//        // positive  (lbound <= x <= center)
//        _val *= trnorm((x - lbound)/scale);
//    }
//
//    // p.r_size() points in the left hal of the interval,
//    // minus the post rightmost points of this half
//    assert (post <= p.r_size());
//    i = p.r_first();
//    for (size_t j = 0; j < (p.r_size()-post); j++)
//    {
//        double x = p.input().rdate(i+j);
//        assert (lbound <= x);
//        assert (x < rbound);
//        // negative  (center < x < rbound)
//        _val *= trnorm((x - rbound) / scale);
//    }
//    if (_val == 0)
//        ERROR("null perfo weight [{} {}]", lbound, rbound);
//}


PerfoWeight::PerfoWeight(const InputSegment* s,
                         const AlignedInterval* p,
                         pre_t pre, pre_t post):
ViterbiWeight(1)
{
    assert(s);
    assert(p);
    assert(PP_KNOWN(pre));
    assert(PP_KNOWN(post));
    double lbound = p->rbegin;
    double rbound = p->rend;
    assert (s->rbegin() <= lbound);
    //assert (lbound <= s->rend());  // can be out
    assert (s->rbegin() <= rbound);
    //assert (rbound <= s->rend());
    assert (lbound <= rbound);
    
    double scale = p->rduration() / (b - a);
    
    // pre points on the leftmost value of the interval
    _val *= pow(trnorm(0), pre);
    
    // p.l_size() points in the left hal of the interval
    size_t i = p->lfirst();
    for (size_t j = 0; j < p->lsize(); j++)
    {
        double x = s->rdate(i+j);
        assert (lbound <= x);
        assert (x < rbound);
        // positive  (lbound <= x <= center)
        _val *= trnorm((x - lbound)/scale);
    }
    
    // p.r_size() points in the left hal of the interval,
    // minus the post rightmost points of this half
    assert (post <= p->rsize());
    i = p->rfirst();
    for (size_t j = 0; j < (p->rsize() - post); j++)
    {
        double x = s->rdate(i+j);
        assert (lbound <= x);
        assert (x < rbound);
        // negative  (center < x < rbound)
        _val *= trnorm((x - rbound) / scale);
    }

    // DEBUG
    if (_val == 0.0)
    {
        ERROR("perfo weight=1 rt=[{} {}] mt=[{} {}] size={}",
              lbound, rbound,
              p->mbegin, p->mend, p->size());
    }

    assert(0 < _val);
    assert(_val <= 1);
}


PerfoWeight& PerfoWeight::operator= (const PerfoWeight& rhs)
{
    if (this != &rhs)
    {
        _val = rhs._val;
    }
    return *this;
}

PerfoWeight& PerfoWeight::operator= (const LetterWeight& rhs)
{
    if(this != &rhs)
    {
        const PerfoWeight* perf_rhs =
        dynamic_cast<const PerfoWeight*>(&rhs);
        
        assert (perf_rhs);
        _val = perf_rhs->_val;
    };
    return *this;
}

PerfoWeight* PerfoWeight::PerfoWeight::clone() const
{
    return (new PerfoWeight(_val));
}


void PerfoWeight::set_sigma2(double s)
{
    assert (s > 0);
    PerfoWeight::sigma2 = s;
    PerfoWeight::sigma = sqrt(PerfoWeight::sigma2);
}


double PerfoWeight::trnorm(double x)
{
    // exp(- (x/sigma)**2 / 2) / Z
    return exp(-pow(x/sigma,2)/2) / Z;
}

// @todo TBR
//double PerfoWeight::align(double x, size_t a, size_t b, double sigma) const
//{
//    assert (a < b);
//    assert (a <= x);
//    assert (x < b);
//    
//    double m = a + (b-a)/2;
//    if ( (a <= x) && (x <= m) )
//        return trnorm(x-a, a, b, sigma); // positive
//    else // (m < x) && (x < b)
//        return trnorm(x-b, a, b, sigma); // negative
//}


/// @}
