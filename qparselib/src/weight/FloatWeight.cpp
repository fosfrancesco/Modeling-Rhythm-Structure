//
//  FloatWeight.cpp
//  qparse
//
//  Created by Florent Jacquemard on 08/10/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup weight
/// @{


#include "FloatWeight.hpp"


// default null, known
FloatWeight::FloatWeight(double d):_val(d)
{ }


FloatWeight::FloatWeight(const FloatWeight& d):_val(d._val)
{ };


FloatWeight& FloatWeight::operator= (const FloatWeight& rhs)
{
    if (this != &rhs)
    {
        _val = rhs._val;
    }
    return *this;
}

FloatWeight& FloatWeight::operator= (const LetterWeight& rhs)
{
    assert(rhs.hasType("FloatWeight"));
    
    if(this != &rhs)
    {
        const FloatWeight* float_rhs = dynamic_cast<const FloatWeight*>(&rhs);
        
        assert (float_rhs);
        _val = float_rhs->_val;
    };
    return *this;
}


FloatWeight* FloatWeight::clone() const
{
    return (new FloatWeight(_val));
}

void FloatWeight::scalar(double d)
{
    _val *= d;
}

void FloatWeight::invert()
{
    assert (_val != 0);
    
    // when no assert, invert zero leaves weight unchanged
    if (_val != 0) { _val = 1.0/_val; }
}

bool FloatWeight::zero() const
{
    //assert (0.0 <= _val);
    return (_val == 0.0);
}

bool FloatWeight::one() const
{
    //assert (0.0 <= _val);
    return (_val == 1.0);
}

bool FloatWeight::equal(const FloatWeight& rhs) const
{
    return (_val == rhs._val);
}

bool FloatWeight::equal(const LetterWeight* rhs) const
{
    assert(rhs);
    assert(rhs->hasType("FloatWeight"));
    return (_val == rhs->norm());
}

bool FloatWeight::smaller(const FloatWeight& rhs) const
{
    return (_val < rhs._val);
}

bool FloatWeight::smaller(const LetterWeight* rhs) const
{
    assert(rhs);
    assert(rhs->hasType("FloatWeight"));
    return (_val < rhs->norm());
}

void FloatWeight::add(const FloatWeight& rhs)
{
    _val += rhs._val;
}

void FloatWeight::add(const LetterWeight* rhs)
{
    assert(rhs);
    assert(rhs->hasType("FloatWeight"));
    _val += rhs->norm();
}

void FloatWeight::mult(const FloatWeight& rhs)
{
    _val *= rhs._val;
}

void FloatWeight::mult(const LetterWeight* rhs)
{
    assert(rhs);
    assert(rhs->hasType("FloatWeight"));
    _val *= rhs->norm();
}

void FloatWeight::print(std::ostream& o) const
{
    o << _val;
}


std::ostream& operator<<(std::ostream& o, const FloatWeight& rhs)
{
    o << rhs._val;
    return o;
}


/// @}
