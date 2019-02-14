//
//  Weight.cpp
//  qparse
//
//  Created by Florent Jacquemard on 04/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup weight
/// @{


#include "Weight.hpp"

//LetterWeight* LetterWeight::clone() const
//{
//    return new LetterWeight();
//}
//
//Weight LetterWeight::make(double v) const
//{
//    return Weight(new LetterWeight());
//}

//double LetterWeight::norm() const
//{
//    assert(false);
//    return 0;
//}
//
//void LetterWeight::scalar(double)
//{
//    assert(false);
//}

bool LetterWeight::equal(const LetterWeight*) const
{
    assert(false);
    return false;
}

bool LetterWeight::smaller(const LetterWeight*) const
{
    assert(false);
    return false;
}

void LetterWeight::add(const LetterWeight*)
{
    assert(false);
}

void LetterWeight::mult(const LetterWeight*)
{
    assert(false);
}

bool LetterWeight::zero() const
{
    assert(false);
}

bool LetterWeight::one() const
{
    assert(false);
}

void LetterWeight::print(std::ostream& o) const
{
    assert(false);
}







Weight::Weight(const Weight& w)//:_letter((w._letter)?((w._letter)->clone()):NULL)
{
    if (w._letter)
    {
        _letter = (w._letter)->clone();
    }
    else
    {
        _letter = NULL;
    }
}


Weight::~Weight()
{
    if (_letter)
        delete _letter;
    _letter = NULL;
}

Weight& Weight::operator= (const Weight& rhs)
{
    if(this != &rhs)
    {
        if(_letter)
            delete _letter;
        
        if (rhs._letter)
            _letter = rhs._letter->clone();
        else
            _letter = NULL;
    };
    return *this;
}

Weight* Weight::clone() const
{
    Weight* r = new Weight();
    if (_letter)
    {
        r->_letter = _letter->clone();
    }
    else
    {
        r->_letter = NULL;
    };
    return r;
};


Weight Weight::make(double v) const
{
    if (_letter)
    {
        return _letter->make(v);
    }
    else
    {
        return (Weight());
    }
}


Weight Weight::get_zero() const
{
    if (_letter)
    {
        return _letter->get_zero();
    }
    else
    {
        return (Weight());
    }
}


Weight Weight::get_one() const
{
    if (_letter)
    {
        return _letter->get_one();
    }
    else
    {
        return (Weight());
    }
}


bool Weight::unknown() const
{
    return (_letter == NULL);
}


bool Weight::hasType(std::string code) const
{
    if (_letter)
    {
        return _letter->hasType(code);
    }
    else
    {
        return (code == "UNKNOWN");
    }
}


double Weight::norm()
{
    assert(_letter);
    return (_letter->norm());
}


void Weight::scalar(double d)
{
    assert(_letter);
    _letter->scalar(d);
}


void Weight::invert()
{
    assert(_letter);
    _letter->invert();
}


void Weight::clear()
{
    if (_letter)
    {
        delete _letter;
        _letter = NULL;
    }
}


bool Weight::zero() const
{
    if (_letter)
        return _letter->zero();
    else
        return false;
}


bool Weight::one() const
{
    if (_letter)
        return _letter->one();
    else
        return false;
}


bool Weight::equal(const Weight& rhs) const
{
    if (_letter) // non-empty envelop: dispatch the letter
    {
        if (rhs._letter) // rhs is non-empty envelop: peel off
            return (_letter->equal(rhs._letter));
        else // rhs is unknown weight
            return false;
    }
    else // it is an unknown weight
    {
        return (rhs.unknown());
    }
}

// unknown weight is the smallest
bool Weight::smaller(const Weight& rhs) const
{
    if (_letter) // non-empty envelop: dispatch the letter
    {
        if (rhs._letter) // rhs is non-empty envelop: peel off
            return (_letter->smaller(rhs._letter));
        else // rhs is unknown weight
            return false;
    }
    else // it is an unknown weight
    {
        return (! rhs.unknown());
    }
}


// this and rhs must not be unknown
void Weight::add(const Weight& rhs)
{
    assert(_letter);
    assert(rhs._letter);
     _letter->add(rhs._letter);

//    // ALT: unknown is absorbing element for add
//    // if this Weight is unknown, then do nothing
//    // if rhs is unknown, then this weight is set unknown
//
//    if (_letter) // non-empty envelop: dispatch the letter
//    {
//        if (rhs._letter)
//        {
//            _letter->add(rhs._letter);
//        }
//        // unknown weight is absorbing element for add
//        else
//        {
//            delete _letter;
//            _letter = NULL;
//        }
//    }
//   // else do nothing: it is an unknown weight, absorbing
};


// this and rhs must not be unknown
void Weight::mult(const Weight& rhs)
{
    assert(_letter);
    assert(rhs._letter);
    _letter->mult(rhs._letter);

    // ALT: unknown is absorbing element for add (see add)
    // if this Weight is unknown, then do nothing
    // if rhs is unknown, then this weight is set unknown
    // if rhs is unknown, do nothing
    // if this Weight is unknown, then copy rhs
};


void Weight::print(std::ostream& o) const
{
    // must be overloaded in derived class
    if (_letter)
        _letter->print(o);
    else
        o << "UkW";
}

std::string Weight::save_to_string()
{
    return "ciao";
}


/// @}
