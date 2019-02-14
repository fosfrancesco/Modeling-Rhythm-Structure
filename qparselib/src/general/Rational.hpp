//
//  Rational.hpp
//  qparse
//
//  Created by Florent Jacquemard on 02/11/16.
//
/// @addtogroup general
/// @{


#ifndef Rational_hpp
#define Rational_hpp

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <math.h>

#include "trace.hpp"

#if defined(__GNUC__) && (__GNUC__ < 3) && !defined(__SPSL__)
#include <limits.h>

template <class T> class numeric_limits
{
public:
    static T min() {return T();}
    static T max() {return T();}
};

template<> class numeric_limits <char>
{
public:
    static long min() { return CHAR_MIN; }
    static long max() { return CHAR_MAX; }
};

template<> class numeric_limits <short>
{
public:
    static long min() { return SHRT_MIN; }
    static long max() { return SHRT_MAX; }
};

template<> class numeric_limits <int>
{
public:
    static long min() { return INT_MIN; }
    static long max() { return INT_MAX; }
};

template<> class numeric_limits <long>
{
public:
    static long min() { return LONG_MIN; }
    static long max() { return LONG_MAX; }
};

template<> class numeric_limits <long long>
{
public:
    static long long min() {
        return -1-(long long)((~(unsigned long long)0)>>1); }
    static long long max() {
        return (long long)((~(unsigned long long)0)>>1); }
};

#else
#include <limits>
using std::numeric_limits;
#endif

/// class of rational numbers
class Rational
{
public:
    Rational() : num(0), den(1) {}

    /// default constructor
    Rational(long n, long d = 1);
    
    /// copy constructor
    Rational(const Rational& rhs) : num(rhs.num), den(rhs.den) {}
    
    ~Rational(void) {}
    
    long numerator(void) const { return num; }
    long denominator(void) const { return den; }
    
    bool null(void) const { return (num == 0); }
    bool integral(void) const { return (den == 1L); }
    
    // assignment operators
    Rational& operator=(const Rational& rhs);
    Rational& operator=(long rhs);
    
    // unary operators
    Rational operator+(void) const { return *this; }
    Rational operator-(void) const { return Rational(-num, den); }
    Rational invert(void) const { return Rational(den, num); }
    
    // binary shortcut operators
    const Rational& operator+=(const Rational& rhs);
    const Rational& operator-=(const Rational& rhs);
    const Rational& operator*=(const Rational& rhs);
    const Rational& operator/=(const Rational& rhs);
    const Rational& operator+=(long rhs);
    const Rational& operator-=(long rhs);
    const Rational& operator*=(long rhs);
    const Rational& operator/=(long rhs);
    
    // increment/decrement iterators
    const Rational& operator++();
    const Rational operator++(int);
    const Rational& operator--();
    const Rational operator--(int);
    
    // -- better implemented as explicit conversion
    // -- function toDouble (see below)
    // operator double(void) const { return double(num)/den; }

    /// print in format int+rat
    void printint(std::ostream&) const;
    
private:
    // Data

    /// numerator
    long num;

    /// denominator (keep > 0!)
    long den;
    
    /// auxillary helper function to normalize the rationals
    long gcd(long, long);
};


/// assignment operators
inline Rational& Rational::operator=(const Rational& rhs)
{
    num = rhs.num;
    den = rhs.den;
    return *this;
}

inline Rational& Rational::operator=(long rhs)
{
    num = rhs;
    den = 1;
    return *this;
}

/// Rational -> double conversion
inline double toDouble(const Rational& r)
{
    return double(r.numerator())/r.denominator();
}

/// Rational -> long conversions
inline long trunc(const Rational& r)
{
    return r.numerator() / r.denominator();
}

inline long floor(const Rational& r)
{
    long q = r.numerator() / r.denominator();
    return (r.numerator() < 0 && r.denominator() != 1) ? --q : q;
}

inline long ceil(const Rational& r)
{
    long q = r.numerator() / r.denominator();
    return (r.numerator() >= 0 && r.denominator() != 1) ? ++q : q;
}

/// double -> Rational conversion
Rational toRational(double x, int iterations = 5);

// binary operators
const Rational operator+(const Rational& lhs, const Rational& rhs);
const Rational operator-(const Rational& lhs, const Rational& rhs);
const Rational operator*(const Rational& lhs, const Rational& rhs);
const Rational operator/(const Rational& lhs, const Rational& rhs);
Rational rabs(const Rational& rhs);

// boolean operators
bool operator==(const Rational& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const Rational& rhs);

// output operator
std::ostream& operator<< (std::ostream& ostr, const Rational& r);
std::istream& operator>> (std::istream& istr, Rational& r);

namespace std
{
    template<>
    class hash<Rational>
    {
    public:
        std::size_t operator()(const Rational& x) const
        {
            using std::hash;
         
            return std::hash<long>()(x.numerator()) ^ std::hash<long>()(x.denominator());
//            size_t h = 17;
//            h = h * 31 + std::hash<long>()(x.numerator());
//            h = h * 31 + std::hash<long>()(x.denominator());
//            return h;
        }
    };
}


#endif /* Rational_hpp */


/// @}
