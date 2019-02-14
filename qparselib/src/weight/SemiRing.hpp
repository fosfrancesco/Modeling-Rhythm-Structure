//
//  SemiRing.h
//  qparse
//
//  Created by Florent Jacquemard on 26/04/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//

#ifndef SemiRing_h
#define SemiRing_h

/// @brief semiring structure.
///
/// - add  is associative, commutative
/// - zero is neutral element for plus
/// - mult is associative
/// - one  is neutral element for mult
/// - zero is absorbing element for mult
/// - mult distributes over plus
///
/// @ingroup weight
template<typename T> class SemiRing
{
    friend bool operator==(const T& lhs, const T& rhs)
    { return lhs.equal(rhs);}
    
    friend bool operator!=(const T& lhs, const T& rhs)
    { return !operator==(lhs,rhs); } //    { return !lhs.equal(rhs);}
    
    friend bool  operator<(const T& lhs, const T& rhs)
    { return (lhs.smaller(rhs)); }
    
    friend bool  operator>(const T& lhs, const T& rhs)
    { return  operator< (rhs,lhs); }
    
    friend bool  operator<=(const T& lhs, const T& rhs)
    { return !operator> (lhs,rhs); }
    
    friend bool  operator>=(const T& lhs, const T& rhs)
    { return !operator< (lhs,rhs); }
    
    void operator+=(const T& rhs)
    { add(rhs); }
    
    void operator*=(const T& rhs)
    { mult(rhs); }
    
    friend std::ostream& operator<<(std::ostream& o, const T& rhs)
    { rhs.print(o); return o; }
};


#endif /* SemiRing_h */


