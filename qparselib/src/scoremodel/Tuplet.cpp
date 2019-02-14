// Implementation of Tuplet functions

#include "Tuplet.hpp"


namespace ScoreModel {
// Main constructor
Tuplet::Tuplet(Duration duration, Sequence events, int arity): _duration (duration), _events(events), _arity(arity)
{
}

Duration Tuplet::getDuration() const
{
return _duration;
}


std::vector<Event*> Tuplet::getEvents() const {
	return _events.getEvents();
}

int Tuplet::nbEvents() const
{
return _events.nbEvents();
}


int Tuplet::getArity() const
{
return _arity;
}

Duration Tuplet::getBaseDuration() const{
	Duration dur(1);

	for (const Event* event : _events.getEvents()) {
		if (dur.getValue() > event->getDuration().getValue()) {
			dur.setValue(event->getDuration().getValue());
		}
	}
	return dur;
}

int Tuplet::getNumBase() const
{
  return  getBaseDuration().getCMN() / getDuration().getCMN() ;
}



/**
 * First event
 */
Event* Tuplet::getFirstEvent() const
{
	return _events.getFirstEvent();
}

/**
 * Last event
 */
Event* Tuplet::getLastEvent() const
{
	return _events.getLastEvent();
}


// Destructor

Tuplet::~Tuplet()
{

}

}
