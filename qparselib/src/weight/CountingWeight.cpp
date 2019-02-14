//
//  CountingWeight.cpp
//  schemas
//
//  Created by Florent Jacquemard on 23/11/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup weight
/// @{


#include "CountingWeight.hpp"


//CountingWeight::CountingWeight():
//_type(FAIL),
//_counters()
//{}


CountingWeight::CountingWeight(CWType t, size_t dim):
_type(t),
_dim(dim),
_counters()
{
    assert (dim >0 );
    assert ( (t == VECTOR) || (t == FAIL) || (t == ERROR));

    if (t == VECTOR)
        _counters = std::vector<size_t>(dim, 0);
}


CountingWeight::CountingWeight(const CountingWeight& w):
_type(w._type),
_dim(w._dim),
_counters(w._counters)
{
    assert ( (_type == VECTOR) || (_type == FAIL) || (_type == ERROR) );
    assert (_dim > 0);
}


CountingWeight::~CountingWeight()
{
    _counters.clear();
}


CountingWeight& CountingWeight::operator= (const CountingWeight& rhs)
{
    if (this != &rhs)
    {
        _type = rhs._type;
        _dim = rhs._dim;
        if (_type == VECTOR)
            _counters = rhs._counters;
    }
    return *this;
}

// @todo TBR ?
CountingWeight& CountingWeight::operator= (const LetterWeight& rhs)
{
    assert(rhs.hasType("CountingWeight"));
    
    if (this != &rhs)
    {
        const CountingWeight* counting_rhs =
            dynamic_cast<const CountingWeight*>(&rhs);
        
        assert (counting_rhs);
        _type = counting_rhs->_type;
        _dim = counting_rhs->_dim;

        if (_type == VECTOR)
            _counters = counting_rhs->_counters;
    };
    return *this;
}


CountingWeight* CountingWeight::clone() const
{
    return (new CountingWeight(*this));
}


Weight CountingWeight::make(double x) const
{
    return Weight(new CountingWeight(ERROR, x));
}


//Weight CountingWeight::make_zero()
//{
//    return Weight(new CountingWeight());
//}


Weight CountingWeight::make_one(size_t dim)
{
    assert (dim > 0);
    return Weight(new CountingWeight(VECTOR, dim));
}

Weight CountingWeight::make_unit(size_t dim, size_t i)
{
    assert (dim > 0);
    assert (i >= 0);
    assert (i < dim);

    CountingWeight* cw = new CountingWeight(VECTOR, dim);
    cw->_counters[i] = 1;

    return Weight(cw);
}

Weight CountingWeight::get_zero() const
{
    assert (_dim > 0);
    
    return Weight(new CountingWeight(FAIL, this->_dim));
}

Weight CountingWeight::get_one() const
{
    assert (_dim > 0);
    
    return CountingWeight::make_one(this->_dim);
}

bool CountingWeight::zero() const
{
    assert (_dim > 0);
    return (_type == FAIL);
}

bool CountingWeight::error() const
{
    assert (_dim > 0);
    return (_type == ERROR);
}

bool CountingWeight::one() const
{
    assert (_dim > 0);
    
    if (_type != VECTOR)
    {
        return (false);
    }
    else
    {
        for (size_t i = 0; i < _counters.size(); i++)
        {
            assert (_counters[i] >= 0);
            if (_counters[i] > 0)
                return false;
        }

        return true;
    }
}


double CountingWeight::norm() const
{
    if (_type == ERROR)
    {
        return -2;
    }
    if (_type == FAIL)
    {
        return -1;
    }
    else
    {
        assert (_type == VECTOR);
        double res = 0;
        for (size_t i = 0; i < _dim; i++)
        {
            assert (_counters[i] >= 0);
            res += _counters[i];
        }
        return res;
    }
}


void CountingWeight::scalar(double d)
{
    for (size_t i = 0; i < _counters.size(); i++)
    {
        _counters[i] *= d;
    }
}


bool CountingWeight::equal(const LetterWeight* rhs) const
{
    assert(rhs);
    assert(rhs->hasType("CountingWeight"));

    const CountingWeight* counting_rhs =
        dynamic_cast<const CountingWeight*>(rhs);
    assert (counting_rhs);

    if (_type == FAIL)
    {
        return (counting_rhs->_type == FAIL);
    }
    else if (_type == ERROR)
    {
        return (counting_rhs->_type == ERROR);
    }
    else
    {
        assert (_type == VECTOR);
        if (counting_rhs->_type != VECTOR)
        {
            return false;
        }
        else
        {
            assert (_dim > 0);
            if (_dim != counting_rhs->_dim)
            {
                return false;
            }
            else
            {
                assert (_dim == _counters.size());
                assert (counting_rhs->_dim == counting_rhs->_counters.size());

                for (size_t i = 0; i < _dim; i++)
                {
                    assert (_counters[i] >= 0);
                    if (_counters[i] != counting_rhs->_counters[i])
                        return false;
                }
                return true;
            }
        }
    }
}


bool CountingWeight::smaller(const LetterWeight* rhs) const
{
    assert(rhs);
    assert(rhs->hasType("CountingWeight"));
    
    const CountingWeight* counting_rhs =
    dynamic_cast<const CountingWeight*>(rhs);
    assert (counting_rhs);

    // min
    if (_type == ERROR)
    {
        return (counting_rhs->_type != ERROR);
    }
    else if (_type == FAIL)
    {
        return ((counting_rhs->_type != ERROR) &&
                (counting_rhs->_type != FAIL));
    }
    else
    {
        assert (_type == VECTOR);
        if (counting_rhs->_type != VECTOR)
        {
            return false;
        }
        else
        {
            assert (_dim > 0);
            // incomparable
            if (_dim != counting_rhs->_dim)
            {
                return false;
            }
            // lexico
            else
            {
                assert (_dim == _counters.size());
                assert (counting_rhs->_dim == counting_rhs->_counters.size());
                
                for (size_t i = 0; i < _dim; i++)
                {
                    assert (_counters[i] >= 0);
                    if (_counters[i] < counting_rhs->_counters[i])
                        return true;
                    else if (_counters[i] > counting_rhs->_counters[i])
                        return false;
                    // else continue
                }
                // equal
                return false;
            }
        }
    }
}


void CountingWeight::add(const LetterWeight* rhs)
{
    assert(rhs);
    assert(rhs->hasType("CountingWeight"));
    const CountingWeight* counting_rhs =
        dynamic_cast<const CountingWeight*>(rhs);
    assert (counting_rhs);
    assert (_dim == counting_rhs->_dim);
    
    // FAIL neutral
    if (_type == FAIL)
    {
        _type = counting_rhs->_type;
        // copy vector content
        if (_type == VECTOR)
        {
            _counters = std::vector<size_t>(counting_rhs->_counters);
            assert (_counters.size() == _dim);
        }
    }
    // ERROR absorbing
    else if (_type == ERROR)
    { }
    else
    {
        assert (_type == VECTOR);
        
        // ERROR absorbing
        // VECTOR + VECTOR = ERROR
        if ((counting_rhs->_type == ERROR) || (counting_rhs->_type == VECTOR))
        {
            WARN("countingWeight: {} + {} = ERROR", *this, *counting_rhs);
            _type = ERROR;
            _counters.clear();
        }
        // FAIL is neutral, do nothing
        else
        {
            assert (counting_rhs->_type == FAIL);
        }
    }
}


void CountingWeight::mult(const LetterWeight* rhs)
{
    assert(rhs);
    assert(rhs->hasType("CountingWeight"));
    const CountingWeight* counting_rhs =
        dynamic_cast<const CountingWeight*>(rhs);
    assert (counting_rhs);
    assert (_dim == counting_rhs->_dim);
    
    // ERROR absorbing
    if (_type == ERROR)
    { }
    else if (_type == FAIL)
    {
        // ERROR absorbing
        if (counting_rhs->_type == ERROR)
        {
            _type = ERROR;
            _counters.clear();
        }
        // else do nothing (FAIL absorbs)
    }
    else
    {
        assert (_type == VECTOR);
        
        // ERROR absorbing
        if (counting_rhs->_type == ERROR)
        {
            _type = ERROR;
            _counters.clear();
        }
        // FAIL absorbs
        else if (counting_rhs->_type == FAIL)
        {
            _type = FAIL;
            _counters.clear();
        }
        // VECTOR + VECTOR = VECTOR with component-wise sum
        else
        {
            assert (counting_rhs->_type == VECTOR);
            assert (counting_rhs->_dim == counting_rhs->_counters.size());
            assert (_dim == _counters.size());

            for (size_t i = 0; i < _dim; i++)
                _counters[i] += counting_rhs->_counters[i];
        }
    }
}


void CountingWeight::print(std::ostream& o) const
{
    o << *this;
}

void CountingWeight::rawprint(std::ostream& o) const
{
    if (error())
    {
        o << "ERROR";
    }
    else if (zero())
    {
        o << "FAIL";
    }
    else
    {
        size_t dim = _counters.size();
        assert (dim > 0);
        o << "[" << _counters[0];
        for (size_t i = 1; i < dim; i++)
        {
            o << ", " << _counters[i];
        }
        o << "]";
    }
    
//    return o;
}

std::ostream& operator<<(std::ostream& o, const CountingWeight& rhs)
{
    if (rhs.error())
    {
        o << "ERROR";
    }
    else if (rhs.zero())
    {
        o << "FAIL";
    }
    else
    {   
        std::string out_string = "{";
        size_t dim = rhs._counters.size();
        assert (dim > 0);

        for (size_t i = 0; i < dim; i++)
        {
            size_t temp_count= rhs._counters[i];
            if (temp_count != 0)
            {
                out_string += "\""+ std::to_string(i) +"\"" +":"+  std::to_string(temp_count) +",";
            }
        }
        out_string.pop_back();
        out_string += "}";
        o << out_string;
    }
    
   return o;
}


/// @}
