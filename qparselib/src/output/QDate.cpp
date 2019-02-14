//
//  QDate.cpp
//  qparse
//
//  Created by Florent Jacquemard on 23/10/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


#include "QDate.hpp"

QDate::QDate():
_quotient(0),
_modulo(0)
{ }

QDate::QDate(size_t blocs, size_t rel):
_quotient(blocs),
_modulo(rel)
{ }

QDate::QDate(const QDate& d):
_quotient(d._quotient),
_modulo(d._modulo)
{ }

QDate& QDate::operator= (const QDate& d)
{
    if(this != &d)
    {
        _quotient = d._quotient;
        _modulo = d._modulo;
    };
    return *this;
}

QDate* QDate::clone() const
{
    return new QDate(*this);
}

Rational QDate::absolute(size_t res) const
{
    assert (res > 0);
    return (Rational(_quotient) + Rational(_modulo, res));
}

void QDate::print(std::ostream& o) const
{
    o << _quotient << "." << _modulo;
}

void QDate::print(std::ostream& o, size_t res) const
{
    if (_quotient == 0)
    {
        o << Rational(_modulo, res);
    }
    else
    {
        o << _quotient << "+" << Rational(_modulo, res);
    }

}


/// @}
