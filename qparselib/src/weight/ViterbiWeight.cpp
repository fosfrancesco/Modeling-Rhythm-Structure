//
//  ViterbiWeight.cpp
//  qparse
//
//  Created by Florent Jacquemard on 27/04/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup weight
/// @{


#include "ViterbiWeight.hpp"

ViterbiWeight::ViterbiWeight(double v):_val(v)
{
    assert(0.0 <= _val);
    assert(_val <= 1.0);
}


ViterbiWeight::ViterbiWeight(const ViterbiWeight& w):
_val(w._val)
{
    assert(0.0 <= _val);
    assert(_val <= 1.0);
}


ViterbiWeight& ViterbiWeight::operator= (const ViterbiWeight& rhs)
{
    if (this != &rhs)
    {
        _val = rhs._val;
    }
    return *this;
}

// @todo TBR ?
ViterbiWeight& ViterbiWeight::operator= (const LetterWeight& rhs)
{
    if(this != &rhs)
    {
        const ViterbiWeight* viterbi_rhs =
            dynamic_cast<const ViterbiWeight*>(&rhs);

        assert (viterbi_rhs);
        _val = viterbi_rhs->_val;
    };
    return *this;
}

LetterWeight* ViterbiWeight::clone() const
{
    return (new ViterbiWeight(_val));
}


double ViterbiWeight::norm() const
{
    return (_val);
}


void ViterbiWeight::scalar(double d)
{
    _val *= d;
}


void ViterbiWeight::invert()
{
    assert (0.0 < _val);
    assert (_val <= 1.0);

    // when no assert, invert zero leaves weight unchanged
    if (_val != 0) { _val = 1.0/_val; }
}


bool ViterbiWeight::zero() const
{
    assert(0.0 <= _val);
    assert(_val <= 1.0);

    return (_val == 0.0);
}


bool ViterbiWeight::one() const
{
    assert(0.0 <= _val);
    assert(_val <= 1.0);

    return (_val == 1.0);
}


bool ViterbiWeight::equal(const LetterWeight* rhs) const
{
    assert(rhs);
    assert(rhs->hasType("ViterbiWeight"));
    return (_val == rhs->norm());
}


bool ViterbiWeight::smaller(const LetterWeight* rhs) const
{
    assert(rhs);
    assert(rhs->hasType("ViterbiWeight"));
    return (_val < rhs->norm());
}


// sum is max
void ViterbiWeight::add(const LetterWeight* rhs)
{
    assert(rhs);
    assert(rhs->hasType("ViterbiWeight"));
    double rhs_val = rhs->norm();
    if (rhs_val > _val)
        _val = rhs_val;
}


// product is times
void ViterbiWeight::mult(const LetterWeight* rhs)
{
    assert(rhs);
    assert(rhs->hasType("ViterbiWeight"));
    _val *= rhs->norm();
}


void ViterbiWeight::print(std::ostream& o) const
{
    o << _val;
}


/// @}
