//
//  Pitch.cpp
//  qparse
//
//  Created by Florent Jacquemard on 10/05/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#include "Pitch.hpp"

const unsigned int Pitch::UNDEF_MIDICENT        = 12800;
const char         Pitch::UNDEF_NOTE_NAME       = 'X';
const int          Pitch::UNDEF_NOTE_OCTAVE     = 128;
const float        Pitch::UNDEF_NOTE_ALTERATION = 11;

const char Pitch::NAMES[12] =
{'C', 'C', 'D', 'D', 'E', 'F', 'F', 'G', 'G', 'A', 'A', 'B'};
const int  Pitch::SHARP[12] =
{ 0 ,  1 ,  0 ,  1 ,  0 ,  0 ,  1 ,  0 ,  1 ,  0 ,  1 ,  0 };


Pitch::Pitch():
_midi(UNDEF_MIDICENT),
name(UNDEF_NOTE_NAME),
octave(UNDEF_NOTE_OCTAVE),
alteration(UNDEF_NOTE_ALTERATION)
{ };


Pitch::Pitch(char n,
             float alt,
             int oct):
name(n),
alteration(alt),
octave(oct)
{
    assert (('A' <= n) && (n <= 'G'));
    assert ((-10 <= oct) && (oct <= 10));
    assert ((-2.0 <= alt) && (alt <= 2.0));
    
    _midi = name_to_midi(n,alt,oct)*100;
}


Pitch::Pitch(unsigned int k, PitchUnit u):
_midi((u==MIDI)?k*100:k)
{
    assert ((u == MIDI) || (u == MIDICENT));
    assert ((0 <= k) && (k < 12800));
    
    name = midi_to_name(_midi);
    alteration = midi_to_alt(_midi);
    assert ((-2 <= alteration) && (alteration <= 2));
    octave = midi_to_oct(_midi);
    assert ((-1 <= octave) && (octave <= 9));
}


Pitch::Pitch(const Pitch& p):
name(p.name),
alteration(p.alteration),
octave(p.octave),
_midi(p._midi)
{
    // @todo sanity check?
}


Pitch& Pitch::operator= (const Pitch& p)
{
    if(this != &p)
    {
        name = p.name;
        alteration = p.alteration;
        octave = p.octave;
        _midi = p._midi;
    };
    return *this;
}

bool Pitch::operator== (const Pitch& p) const
{
    return (_midi == p._midi);
}
    
// revise to MIDIcent
char Pitch::midi_to_name(unsigned int c)
{
    unsigned int p = int(floor(c / 100));
    assert ((0 <= p) && (p <= 127));
    return NAMES[p%12];
}

float Pitch::midi_to_alt(unsigned int c)
{
    unsigned int p = int(floor(c / 100));
    assert ((0 <= p) && (p <= 127));
    
    return (float(SHARP[p%12]) + ( float(c-(p*100))/100));
}

// C4 is MIDI key 60
int Pitch::midi_to_oct(unsigned int c)
{
    int oct = int(floor(c/1200)) - 1;
    assert ((-1 <= oct) && (oct <= 9));
    return oct;
}


unsigned int Pitch::name_to_int(char n)
{
    char c = toupper(n);
    for (unsigned int i = 0; i < 12; i++)
    {
        if (NAMES[i] == c)
            return i;
    }
    throw std::runtime_error("wrong note name\n");
}

// TBC
unsigned int Pitch::name_to_midi(char n, float alt, int oct)
{
    assert ((-2.0 <= alt) && (alt <= 2.0));
    assert ((-1 <= oct) && (oct <= 9));
    
    char i = name_to_int(n);
    int falt = int(floor(alt));
    int r = (i + falt)%12;
    assert ((0 <= r) && (r <= 11));
    unsigned int p = ((oct+1) * 12) + r;
    assert ((0 <= p) && (p <= 127));
    
    return ((p*100)+ int((alt-falt)*100));
}


std::ostream& operator<<(std::ostream& o, const Pitch& p)
{
    if ( p.name == Pitch::UNDEF_NOTE_NAME) o << "x";
    else o << p.name;
    if ( p.alteration == Pitch::UNDEF_NOTE_ALTERATION) o << "";
    else if ( p.alteration == 0.0) o << "";
    else if ( p.alteration == 1.0) o << "#";
    else if ( p.alteration == 2.0) o << "##";
    else if ( p.alteration == -1.0) o << "b";
    else if ( p.alteration == -2.0) o << "bb";
    if ( p.octave == Pitch::UNDEF_NOTE_OCTAVE) o << "";
    else o << p.octave;
    o << " (" << p.midi() << ")";
    return o;
}


/// @}
