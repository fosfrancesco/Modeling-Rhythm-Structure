// Implementation of MyEvent functions

#include "Event.hpp"

namespace ScoreModel {

// Main constructor
Event::Event(Duration duration):
		_duration(duration), _startBeam(NULL), _endBeam(NULL), _isGrace(false)
{
	// We add the event to the voice: this means that events have to be added in sequence for each voice
}

// Destructor

Event::~Event()
{

}
}
