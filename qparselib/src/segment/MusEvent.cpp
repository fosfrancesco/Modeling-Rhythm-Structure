//
//  Event.cpp
//  qparse
//
//  Created by Florent Jacquemard on 06/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#include "MusEvent.hpp"


const unsigned int MusEvent::UNDEF_VELOCITY = 128;


MusEvent::MusEvent(int nb):
number(nb)
{
    assert (nb = EVENTNB_UNKNOWN || nb >= 0);
}


MusEvent::MusEvent(const MusEvent& e):
number(e.number)
{}








RestEvent::RestEvent(int nb):
MusEvent(nb)
{ }

RestEvent::RestEvent(const RestEvent& e):
MusEvent(e)
{ }

MusEvent* RestEvent::clone() const
{
    return (new RestEvent(this->number));
}

void RestEvent::print(std::ostream& o) const
{
    o << "R";
    if (number != EVENTNB_UNKNOWN)
        o << " (#" << number << ")";
    else
        o << " (#UNKNOWN)";
}





// unpitched note
NoteEvent::NoteEvent(unsigned int v, int nb):
MusEvent(nb),
_velocity(v),
_pitch()
{ }

// pitched note
NoteEvent::NoteEvent(Pitch p, unsigned int v, int nb):
MusEvent(nb),
_pitch(p),
_velocity(v)
{}

NoteEvent::NoteEvent(unsigned int p, unsigned int v, int nb):
MusEvent(nb),
_pitch(Pitch(p, Pitch::MIDI)),
_velocity(v)
{}

NoteEvent::NoteEvent(const NoteEvent& e):
MusEvent(e),
_velocity(e._velocity),
_pitch(e._pitch)
{}

MusEvent* NoteEvent::clone() const
{
    return new NoteEvent(_pitch, _velocity, number);
}


void NoteEvent::print(std::ostream& o) const
{
    o << _pitch;
    if (_velocity != MusEvent::UNDEF_VELOCITY)
    {
        o << " vel=" << _velocity;
    }
    if (number != EVENTNB_UNKNOWN)
        o << " (#" << number << ")";
    else
        o << " (#UNKNOWN)";

}


/// @}
