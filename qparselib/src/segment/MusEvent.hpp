//
//  MusEvent.hpp
//  qparse
//
//  Created by Florent Jacquemard on 06/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#ifndef MusEvent_hpp
#define MusEvent_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

#include "init.hpp"
#include "trace.hpp"
#include "Pitch.hpp"


/// @brief input events
///
/// input interface to MIDI, OpenMusic, MEI etc
/// keep track of input event list
/// event are not stored internaly (in WTA). we just preserve the order.
/// and remap afterwards to input event list (with dfs).


/// @brief abstract class to built polymorphic event lists (in input or output).
///
/// can be downcasted to descendant class with dynamic_cast
/// for using particular operations
class MusEvent
{
public:
    static const unsigned int UNDEF_VELOCITY;

    // event number (e.g. MIDI event number)
    int number;
    
    MusEvent(int nb = EVENTNB_UNKNOWN);

    MusEvent(const MusEvent&);

    virtual ~MusEvent() {}
    
    virtual MusEvent* clone() const = 0;
    
    virtual bool isRest() const = 0;
    virtual bool isNote() const = 0;

    virtual void print(std::ostream& o) const = 0;

    friend inline std::ostream& operator<<(std::ostream& o, const MusEvent& rhs);

protected:    
};


inline std::ostream& operator<<(std::ostream& o, const MusEvent& rhs)
{
    rhs.print(o);
    return o;
}



class RestEvent : public MusEvent
{
public:
    RestEvent(int nb = EVENTNB_UNKNOWN);

    RestEvent(const RestEvent&);
    
    ~RestEvent() {}
    
    virtual MusEvent* clone() const;
    
    virtual bool isRest() const
    { return true; }

    virtual bool isNote() const
    { return false; }

    virtual void print(std::ostream& o) const;

    //friend std::ostream& operator<<(std::ostream&, const RestEvent&);
    
protected:
};


class NoteEvent : public MusEvent
{
public:
     /// @brief unpitched note (drums).
    NoteEvent(unsigned int vel=MusEvent::UNDEF_VELOCITY,
              int nb = EVENTNB_UNKNOWN);
    
    /// @brief pitched note.
    NoteEvent(Pitch p,
              unsigned int vel=MusEvent::UNDEF_VELOCITY,
              int nb = EVENTNB_UNKNOWN);
    
    /// @brief pitched note with MIDI pitch in 0..127.
    NoteEvent(unsigned int p,
              unsigned int vel=MusEvent::UNDEF_VELOCITY,
              int nb = EVENTNB_UNKNOWN);

    NoteEvent(const NoteEvent&);
    
    ~NoteEvent() {}

    virtual MusEvent* clone() const;

    virtual bool isRest() const
    { return false; }
    
    virtual bool isNote() const
    { return true; }
    
    bool unpitched() const
    { return _pitch.undef(); }
    
    inline unsigned int velocity() const { return _velocity; }
    
    /// can be modified.
    Pitch& pitch() { return _pitch; }
    
    virtual void print(std::ostream& o) const;

    //friend std::ostream& operator<<(std::ostream&, const NoteEvent&);

protected:
    Pitch _pitch;
    
    /// @brief  MIDI velocity.
    unsigned int _velocity;
    
};


#endif /* MusEvent_hpp */


/// @}
