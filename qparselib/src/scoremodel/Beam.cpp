// Implementation of Beam functions

#include "Beam.hpp"


namespace ScoreModel {

// Main constructor
Beam::Beam(Sequence events): Sequence() 
{
    // Copy the references to the set of events
     this->concatenate(events) ;
     // Inform the first and last event that the beam starts/ends 
     events.getFirstEvent()->setStartBeam(this);
     events.getLastEvent()->setEndBeam(this);
}

}
