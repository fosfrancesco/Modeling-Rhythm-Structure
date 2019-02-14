// Implementation of Sequence functions

#include "Sequence.hpp"

namespace ScoreModel {

// Main constructor
Sequence::Sequence()  {

}

// Add an event
void Sequence::addEvent(Event* event) {
	_events.push_back(event);
}


std::vector<Event*> Sequence::getEvents() const {
	return _events;
}

void Sequence::concatenate(Sequence seq)
{
	for (Event* event : seq.getEvents()) {
		_events.push_back(event);
	}
}

int Sequence::nbEvents() const
{
return _events.size();
}

/**
 * First event
 */
Event* Sequence::getFirstEvent() const
{
	return _events.front();
}

/**
 * Last event
 */
Event* Sequence::getLastEvent() const
{
	return _events.back();
}


// Destructor

Sequence::~Sequence() {

}
}
