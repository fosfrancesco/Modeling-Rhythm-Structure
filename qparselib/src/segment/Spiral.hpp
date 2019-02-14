//
//  Spiral.hpp
//  squant
//
//  Created by Florent Jacquemard on 04/07/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//


/// @addtogroup segment
/// @{


#ifndef Spiral_hpp
#define Spiral_hpp

#include <stdio.h>
#include <cmath> // = <math.h>

#include "Pitch.hpp"

/// @brief Elaine Chew's spiral of fifths.
///
/// for pitch spelling.
struct SpiralPoint
{
public:
    double x;
    double y;
    double z;
    
    SpiralPoint(double, double, double);
    
    SpiralPoint(const SpiralPoint& rhs);
    
    SpiralPoint& operator= (const SpiralPoint&);
    
    /// @return wether coordinate are not NAN. */
    bool isnormal() const;
    
    void operator+=(const SpiralPoint& rhs);
    void operator-=(const SpiralPoint& rhs);

    void operator*=(double a);
    
    friend inline bool operator==(const SpiralPoint&, const SpiralPoint&);
    friend inline bool operator!=(const SpiralPoint&, const SpiralPoint&);
    
    /// @return Euclidian distance to given point.
    double distance(const SpiralPoint& rhs) const;

    friend inline std::ostream& operator<<(std::ostream& o, const SpiralPoint& rhs);
};


inline bool operator==(const SpiralPoint& lhs, const SpiralPoint& rhs)
{
    return ((lhs.x == rhs.x) &&
            (lhs.y == rhs.y) &&
            (lhs.z == rhs.z));
}


inline bool operator!=(const SpiralPoint& lhs, const SpiralPoint& rhs)
{
    return !operator==(lhs,rhs);
}


inline std::ostream& operator<<(std::ostream& o, const SpiralPoint& rhs)
{
    o << "(";
    o << rhs.x;
    o << ", ";
    o << rhs.y;
    o << ", ";
    o << rhs.z;
    o << ")";
    return o;
}


struct NoteName : public SpiralPoint
{
public:
    static const int UNDEF_NOTE_INDEX;
    
    /// @brief z distance between two successive points of the spiral (one fifth apart).
    static const double h;
    
    /// @brief radius of the cylinder in which the spiral is embedded.
    static const double r;

    /// @brief note name.
    /// 'A' to 'G' or Pitch::UNDEF_NOTE_NAME
    /// @see same has in class Pitch
    char name;
    
    /// @brief note alteration.
    ///
    /// in [-2.0, 2.0] where 1.0 is half tone or Pitch::UNDEF_NOTE_ALTERATION
    /// same has in class Pitch.
    float alteration;
    
    /// @brief position in the line of fifths relative to C
    ///
    /// - C has index 0 and index increases in the direction of sharps:
    /// - G has index 1,  D  has index 2, F# has index 6...
    /// - F has index -1, Bb has index -2...
    ///
    /// values between -15 (Fbb) and 19 (B##)
    ///
    /// TBC: it is redundant with name and alteration
    /// maybe should replace them?
    int index;
    
    NoteName():
    SpiralPoint(NAN, NAN, NAN),
    name(Pitch::UNDEF_NOTE_NAME),
    alteration(Pitch::UNDEF_NOTE_ALTERATION),
    index(UNDEF_NOTE_INDEX)
    {}
    
    /// @brief notename object from name, alteration and index.
    /// @param n must be between 'A' and 'G'
    /// @param alt must be between -2.0 and 2.0
    /// @param id must be between -15 and 19
    NoteName(char n, float alt, int id);
    
    // @brief notename from key signature.
    // (number of sharps - positive or number of flats - negative).
    //NoteName(int tonality);

    NoteName(const NoteName& rhs);
    
    NoteName& operator=(const NoteName& rhs);
    
    inline bool unknown() const { return (index == UNDEF_NOTE_INDEX); };
    
    static const NoteName synonyms[12][3];

    /// @brief ref to a NoteName in table synonyms. */
    static const NoteName& ofkey(int k);
    
    /// @brief note name (ref in table synonyms) corresponding to given midi pitch
    /// and closest to given point.
    /// @param p point in spiral
    /// @param pitch must be in 0..128
    static const NoteName& closest(unsigned int pitch, const SpiralPoint& p);

    friend inline bool operator==(const NoteName&, const NoteName&);
    friend inline bool operator!=(const NoteName&, const NoteName&);

    friend inline std::ostream& operator<<(std::ostream& o, const NoteName& rhs);

};


inline bool operator==(const NoteName& lhs, const NoteName& rhs)
{
    return ((((const SpiralPoint&) lhs) == ((const SpiralPoint&) rhs)) &&
            (lhs.name == rhs.name) &&
            (lhs.alteration == rhs.alteration) &&
            (lhs.index == rhs.index));
}


inline bool operator!=(const NoteName& lhs, const NoteName& rhs)
{
    return !operator==(lhs,rhs);
}

inline std::ostream& operator<<(std::ostream& o, const NoteName& p)
{
    if ( p.name == Pitch::UNDEF_NOTE_NAME) o << "x";
    else o << p.name;
    if ( p.alteration == Pitch::UNDEF_NOTE_ALTERATION) o << "";
    else if ( p.alteration == 0.0) o << "";
    else if ( p.alteration == 1.0) o << "#";
    else if ( p.alteration == 2.0) o << "##";
    else if ( p.alteration == -1.0) o << "b";
    else if ( p.alteration == -2.0) o << "bb";
    o << " " << (SpiralPoint&) p;
    return o;
}

namespace Spiral
{
   
    const NoteName& ofkey(int k);
    
    /// @brief note name corresponding to the given midi pitch and closest to given point.
    /// @param p point in spiral
    /// @param pitch must be in 0..128
    const NoteName& closest(unsigned int pitch, const SpiralPoint& p);
}


#endif /* Spiral_hpp */


/// @}
