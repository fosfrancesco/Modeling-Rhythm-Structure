//
//  TropicalWeight.cpp
//  qparse
//
//  Created by Florent Jacquemard on 11/03/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup weight
/// @{


#include "TropicalWeight.hpp"


TropicalWeight::TropicalWeight(const TropicalWeight& w):
_val(w._val)
{ }


TropicalWeight& TropicalWeight::operator= (const TropicalWeight& rhs)
{
    if (this != &rhs)
    {
        _val = rhs._val;
    }
    assert ((_val == -1) || (_val >= 0));
    return *this;
}

TropicalWeight& TropicalWeight::operator= (const LetterWeight& rhs)
{
    assert(rhs.hasType("TropicalWeight"));

    if (this != &rhs)
    {
        const TropicalWeight* tropical_rhs =
            dynamic_cast<const TropicalWeight*>(&rhs);

        assert (tropical_rhs);
        _val = tropical_rhs->_val;
        assert ((_val == -1) || (_val >= 0));
    };
    return *this;
}


TropicalWeight* TropicalWeight::clone() const
{
    assert ((_val == -1) || (_val >= 0));

    return (new TropicalWeight(_val));
}


double TropicalWeight::norm() const
{
    assert (_val >= 0);

    return (_val);
}


void TropicalWeight::scalar(double d)
{
    //assert (_val >= 0);
    assert (d >= 0);

    if (! zero())
    {
        _val *= d;
    }
}


void TropicalWeight::invert()
{
    assert (_val >= 0);

    // when no assert, invert zero leaves weight unchanged
    if (_val != -1) { _val = - _val; }
}


bool TropicalWeight::zero() const
{
    assert ((_val == -1) || (_val >= 0));

    return (_val == -1);
}


bool TropicalWeight::one() const
{
    assert ((_val == -1) || (_val >= 0));
    
    return (_val == 0);
}


bool TropicalWeight::equal(const LetterWeight* rhs) const
{
    assert(rhs);
    assert(rhs->hasType("TropicalWeight"));
    return ((zero() && rhs->zero()) || (_val == rhs->norm()));
}


bool TropicalWeight::smaller(const LetterWeight* rhs) const
{
    assert(rhs);
    assert(rhs->hasType("TropicalWeight"));
    return ((! this->zero()) && (rhs->zero() || (_val < rhs->norm())));
}


// sum is min
void TropicalWeight::add(const LetterWeight* rhs)
{
    assert(rhs);
    assert(rhs->hasType("TropicalWeight"));
    if (rhs->zero())
    {}  // do nothing
    else if (this->zero())
    {
        _val = rhs->norm();
    }
    else
    {
        double rhs_val = rhs->norm();
        if (rhs_val < _val)
            _val = rhs_val;
    }

    assert ((_val == -1) || (_val >= 0));
}


// product is plus
void TropicalWeight::mult(const LetterWeight* rhs)
{
    assert(rhs);
    assert(rhs->hasType("TropicalWeight"));
    if (rhs->zero() || zero())
    {
        _val = -1; // zero
    }
    else
    {
        _val += rhs->norm();
    }
    
    assert ((_val == -1) || (_val >= 0));
}


void TropicalWeight::print(std::ostream& o) const
{
    if (this->zero())
    {
        o << "+∞";
    }
    else
    {
        o << _val;
    }
}


// static members
// definition or fixed penality coefficients
//
// xp = coeff penalty for arity p
//
// ordering defined in Kant paper
// x2 < x4 < x3 < x6 < x8 < x5 < x7 < x9 < x12 < x10 < x11  < x13
//
// constraints
//
// x4  = 3 x2
// x6  = x2 + 2 x3
// x6  = x3 + 3 x2
// x8  = 7 x2
// x8  = x2 + 2 x4
// x8  = x4 + 4 x2
// x9  = 4 x3
// x10 = x2 + 2 x5
// x10 = x5 + 5 x2
// x12 = 3 x2 + 4 x3
// x12 = x3 + 9 x2
// x12 = x3 + 6 x2 + x4
// x12 = x3 + 3 x2 + 2 x4
// x12 = x3 + 3 x4
// x12 = x4 + 4 x3
// x12 = x2 + 2 x6
// x14 = x2 + 2 x7
// x14 = x7 + 7 x2
// x15 = x3 + 3 x5
// x15 = x5 + 5 x3
//
// solutions
//
// x2
// x4  = 3 x2
// x3  = 2 x2        (eqs for x6)
// x6  = 5 x2
// x8  = 7 x2
// x5  = 4 x2        (eqs for x10)
// x5  = 2 x3 = 4 x2 (eqs for x15)
// x7  = 6 x2        (eqs for x14)
// x9  = 8 x2
// x12 = 11 x2
// x10 = 9 x2
// x11
// x13
// x14 = 13 x2
// x15 = 14 x2

TropicalWeight TropicalWeight::penalty[18] =
{
    TropicalWeight(0.01),  // x2
    TropicalWeight(0.02),  // x3
    TropicalWeight(0.03),  // x4
    TropicalWeight(0.04),  // x5
    TropicalWeight(0.05),  // x6
    TropicalWeight(0.06),  // x7
    TropicalWeight(0.07),  // x8
    TropicalWeight(0.08),  // x9
    TropicalWeight(0.09),  // x10
    TropicalWeight(0.10),  // x11
    TropicalWeight(0.11),  // x12
    TropicalWeight(0.12),  // x13
    TropicalWeight(0.13),  // x14
    TropicalWeight(0.14),  // x15
    TropicalWeight(0.15),  // x16
    TropicalWeight(0.16),  // x17
    TropicalWeight(0.17),  // x18
    TropicalWeight(0.18)   // x19
};

TropicalWeight TropicalWeight::inner(size_t arity)
{
    assert (arity > 1);
    
    if (arity < 10)
    {
        switch (arity)
        {
            case 2:
                return TropicalWeight(0.05);
            case 4:
                return TropicalWeight(0.10);
            case 3:
                return TropicalWeight(0.15);
            case 6:
                return TropicalWeight(0.20);
            case 8:
                return TropicalWeight(0.25);
            case 5:
                return TropicalWeight(0.35);
            case 7:
                return TropicalWeight(0.40);
            case 9:
                return TropicalWeight(0.45);
            default:
                assert (false);
        }
    }
    else
    {
        return TropicalWeight(0.05 + (0.05 * arity));
    }
    
}


TropicalWeight TropicalWeight::tie()
{
    return TropicalWeight(0.10);
}

TropicalWeight TropicalWeight::gracenote(size_t n)
{
    return TropicalWeight(0.05 * exp(0.9 * n));
}


/// @}
