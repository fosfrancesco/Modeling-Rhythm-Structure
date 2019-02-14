//
//  Pitch.hpp
//  qparse
//
//  Created by Florent Jacquemard on 10/05/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#ifndef Pitch_hpp
#define Pitch_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

#include "init.hpp"
#include "trace.hpp"


/// @brief internal representation of a pitch value.
///
/// can be unknown value
/// @todo extend conversions to MIDIcent (import OM)
class Pitch
{
public:
    enum PitchUnit { MIDI, MIDICENT };
    
    static const unsigned int UNDEF_MIDICENT;
    static const char         UNDEF_NOTE_NAME;
    static const int          UNDEF_NOTE_OCTAVE;
    static const float        UNDEF_NOTE_ALTERATION;

    /// @brief undef pitch value.
    Pitch();
    
    /// @brief construct pitch from name+alteration+octave.
    /// @param name see table NAMES in constant.h
    /// @param alt in [-2, 2] where 1.0 is half tone
    /// @param oct in -10..10
    Pitch(char name,
          float alt = 0.0,
          int oct = 0);
    
    /// @brief construct note from MIDI pitch
    /// @param pitch in 0..127
    Pitch(unsigned int pitch, PitchUnit u = MIDI);
    
    Pitch(const Pitch&);
    
    ~Pitch() {}
    
    Pitch& operator= (const Pitch&);
    
    bool operator==(const Pitch&) const;
    
    bool undef() const { return (_midi == UNDEF_MIDICENT); }
    
    /// @brief value in MIDIcent.
    unsigned int midicent() const { return _midi; };
    
    /// @brief value in MIDI.
    unsigned int midi() const { return (_midi/100); };
    
    friend std::ostream& operator<<(std::ostream&, const Pitch&);
    
    /// @brief note name betwen 'A' and 'G'.
    char name;

    /// @brief alteration in [-2, 2] where 1.0 is half tone.
    float alteration;
    
    /// @brief octave in -10..10.
    int octave;    
    
private:
    /// @brief in MIDI cent.
    unsigned int _midi;
    
    /// @brief conversion MIDI to note names.
    static const char NAMES[12];
    static const int  SHARP[12];
    
    static char midi_to_name(unsigned int);
    static float midi_to_alt(unsigned int);
    static int midi_to_oct(unsigned int);
    static unsigned int name_to_midi(char, float, int);
    static unsigned int name_to_int(char);
};


#endif /* Pitch_hpp */


/// @}
