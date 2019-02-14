//
//  Spiral.cpp
//  squant
//
//  Created by Florent Jacquemard on 04/07/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#include "Spiral.hpp"



SpiralPoint::SpiralPoint(double vx, double vy, double vz):
x(vx),
y(vy),
z(vz)
{ }


SpiralPoint::SpiralPoint(const SpiralPoint& rhs):
x(rhs.x),
y(rhs.y),
z(rhs.z)
{}


SpiralPoint& SpiralPoint::operator=(const SpiralPoint& rhs)
{
    if (this != &rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
    }
    return *this;
}


bool SpiralPoint::isnormal() const
{
    return (! (std::isnan(x) || std::isnan(y) || std::isnan(z)));
}

void SpiralPoint::operator+=(const SpiralPoint& rhs)
{
    assert(rhs.isnormal());
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
}


void SpiralPoint::operator-=(const SpiralPoint& rhs)
{
    assert(rhs.isnormal());
    x -= rhs.x;
    y -= rhs.y;
    z += rhs.z;
}


void SpiralPoint::operator*=(double a)
{
    assert(! std::isnan(a)); // not zero, subnormal, infinite, nor NaN.
    assert(isnormal());
    x *= a;
    y *= a;
    z *= a;
}


double SpiralPoint::distance(const SpiralPoint& rhs) const
{
    //assert(std::isnormal(rhs.x)); // not NAN
    //assert(std::isnormal(x));
    assert(isnormal());
    assert(rhs.isnormal());

    double dx = x - rhs.x;
    double dy = y - rhs.y;
    double dz = z - rhs.z;
    
    return (std::sqrt(dx*dx + dy*dy + dz*dz));
}


const int NoteName::UNDEF_NOTE_INDEX = 99;

// Chew and Chen set r/h (aspect ratio) to square-root of 15/2 = 2.73861278753
// this ensures that the major thirds and perfect fifths are equidistant
const double NoteName::h = 1.0;
const double NoteName::r = std::sqrt(7.5) * h;

// const double PI = std::atan(1.0)*4;


// in math.h M_PI_2 is the value of pi/2
NoteName::NoteName(char n, float alt, int id):
SpiralPoint(r * std::sin(id * M_PI_2),
            r * std::cos(id * M_PI_2),
            h * id),
name(n),
alteration(alt),
index(id)
{
    assert('A' <= n);
    assert(n <= 'G');
    assert(-2.0 <= alt);
    assert(alt <= 2.0);
    assert(-15 <= id);
    assert(id <= 19);
}


//NoteName::NoteName(int tonality)
//{
//    assert(-7 <= tonality);
//    assert(tonality <= 7);
//    
//    
//}
//
//NoteName::NoteName(const NoteName& n)
//{
//    
//}


NoteName::NoteName(const NoteName& rhs):
SpiralPoint(rhs),
name(rhs.name),
alteration(rhs.alteration),
index(rhs.index)
{ }


NoteName& NoteName::operator=(const NoteName& rhs)
{
    if (this != &rhs)
    {
        SpiralPoint::operator=(rhs);
        name = rhs.name;
        alteration = rhs.alteration;
        index = rhs.index;
    }
    return *this;
}

/*
 const NoteName Fbb = NoteName('F', -2.0, -15);
 const NoteName Cbb = NoteName('C', -2.0, -14);
 const NoteName Gbb = NoteName('G', -2.0, -13);
 const NoteName Dbb = NoteName('D', -2.0, -12);
 const NoteName Abb = NoteName('A', -2.0, -11);
 const NoteName Ebb = NoteName('E', -2.0, -10);
 const NoteName Bbb = NoteName('B', -2.0,  -9);
 const NoteName Fb  = NoteName('F', -1.0,  -8);
 const NoteName Cb  = NoteName('C', -1.0,  -7);
 const NoteName Gb  = NoteName('G', -1.0,  -6);
 const NoteName Db  = NoteName('D', -1.0,  -5);
 const NoteName Ab  = NoteName('A', -1.0,  -4);
 const NoteName Eb  = NoteName('E', -1.0,  -3);
 const NoteName Bb  = NoteName('B', -1.0,  -2);
 const NoteName F   = NoteName('F',  0.0,  -1);
 const NoteName C   = NoteName('C',  0.0,   0);
 const NoteName G   = NoteName('G',  0.0,   1);
 const NoteName D   = NoteName('D',  0.0,   2);
 const NoteName A   = NoteName('A',  0.0,   3);
 const NoteName E   = NoteName('E',  0.0,   4);
 const NoteName B   = NoteName('B',  0.0,   5);
 const NoteName Fs  = NoteName('F',  1.0,   6);
 const NoteName Cs  = NoteName('C',  1.0,   7);
 const NoteName Gs  = NoteName('G',  1.0,   8);
 const NoteName Ds  = NoteName('D',  1.0,   9);
 const NoteName As  = NoteName('A',  1.0,  10);
 const NoteName Es  = NoteName('E',  1.0,  11);
 const NoteName Bs  = NoteName('B',  1.0,  12);
 const NoteName Fss = NoteName('F',  2.0,  13);
 const NoteName Css = NoteName('C',  2.0,  14);
 const NoteName Gss = NoteName('G',  2.0,  15);
 const NoteName Dss = NoteName('D',  2.0,  16);
 const NoteName Ass = NoteName('A',  2.0,  17);
 const NoteName Ess = NoteName('E',  2.0,  18);
 const NoteName Bss = NoteName('B',  2.0,  19);
 const NoteName UNK = NoteName();
 */


/*
 // row number is MIDI pitch modulo 12
 const NoteName synonyms[12][3] =
 {
 { Bs,  C,  Dbb },   // 0
 { Cs,  Db, Bss },   // 1
 { Css, D,  Ebb },   // 2
 { Ds,  Eb, Fbb },   // 3
 { Dss, E,  Fb  },   // 4
 { Es,  F,  Gbb },   // 5
 { Ess, Fs, Gb  },   // 6
 { Fss, G,  Abb },   // 7
 { Gs,  Ab, UNK },   // 8
 { Gss, A,  Bbb },   // 9
 { As,  Bb, Cbb },   // 10
 { Ass, B,  Cb  }    // 11
 };
 */

// row number is MIDI pitch modulo 12
const NoteName NoteName::synonyms[12][3] =
{
    // 0    { B#,  C,  Dbb },
    { NoteName('B',  1.0,  12), NoteName('C',  0.0,   0), NoteName('D', -2.0, -12) },
    // 1    { C#,  Db, B## },
    { NoteName('C',  1.0,   7), NoteName('D', -1.0,  -5), NoteName('B',  2.0,  19) },
    // 2    { C##, D,  Ebb },
    { NoteName('C',  2.0,  14), NoteName('D',  0.0,   2), NoteName('E', -2.0, -10) },
    // 3    { D#,  Eb, Fbb },
    { NoteName('D',  1.0,   9), NoteName('E', -1.0,  -3), NoteName('F', -2.0, -15) },
    // 4    { D##, E,  Fb  },
    { NoteName('D',  2.0,  16), NoteName('E',  0.0,   4), NoteName('F', -1.0,  -8) },
    // 5    { E#,  F,  Gbb },
    { NoteName('E',  1.0,  11), NoteName('F',  0.0,  -1), NoteName('G',  2.0,  15) },
    // 6    { E##, F#, Gb  },
    { NoteName('E',  2.0,  18), NoteName('F',  1.0,   6), NoteName('G', -1.0,  -6) },
    // 7    { F##, G,  Abb },
    { NoteName('F',  2.0,  13), NoteName('G',  0.0,   1), NoteName('A', -2.0, -11) },
    // 8    { G#,  Ab, UNK },
    { NoteName('G',  1.0,   8), NoteName('A', -1.0,  -4), NoteName() },
    // 9    { G##, A,  Bbb },
    { NoteName('G',  2.0,  15), NoteName('A',  0.0,   3), NoteName('B', -2.0,  -9) },
    // 10   { A#,  Bb, Cbb },
    { NoteName('A',  1.0,  10), NoteName('B', -1.0,  -2), NoteName('C',  2.0,  14) },
    // 11   { A##, B,  Cb  }
    { NoteName('A',  2.0,  17), NoteName('B',  0.0,   5), NoteName('C', -1.0,  -7) }
};

const NoteName& NoteName::ofkey(int k)
{
    assert(-7 <= k);
    assert(k <= 7);
    
    switch (k)
    {
        case -7:  // Cb
            return synonyms[11][2];
        case -6:  // Gb
            return synonyms[6][2];
        case -5:  // Db
            return synonyms[1][1];
        case -4:  // Ab
            return synonyms[8][1];
        case -3:  // Eb
            return synonyms[3][1];
        case -2:  // Bb
            return synonyms[10][1];
        case -1:  // F
            return synonyms[5][1];
        case 0:   // C
            return synonyms[0][1];
        case 1:   // G
            return synonyms[7][1];
        case 2:   // D
            return synonyms[2][1];
        case 3:   // A
            return synonyms[9][1];
        case 4:   // E
            return synonyms[4][1];
        case 5:   // B
            return synonyms[11][1];
        case 6:   // F#
            return synonyms[6][1];
        case 7:   // C#
            return synonyms[1][0];
        default:
            ERROR("unexpected key {}", k);
            return synonyms[0][0];
    }
}

const NoteName& NoteName::closest(unsigned int m, const SpiralPoint& p)
{
    assert(0 <= m);
    assert(m < 128);
    assert(p.isnormal());

    unsigned int k = m % 12;
    const NoteName& p0 = synonyms[k][0];
    const NoteName& p1 = synonyms[k][1];
    const NoteName& p2 = synonyms[k][2];
    double d0 = p.distance(p0);
    double d1 = p.distance(p1);

    if (d0 <= d1)
    {
        if (p2.unknown())
        {
            return p0;
        }
        else if (d0 <= p.distance(p2))
        {
            return p0;
        }
        else
        {
            return p2;
        }
    }
    else
    {
        if (p2.unknown())
        {
            return p1;
        }
        else if (d1 <= p.distance(p2))
        {
            return p1;
        }
        else
        {
            return p2;
        }
    }
}


/// @}
