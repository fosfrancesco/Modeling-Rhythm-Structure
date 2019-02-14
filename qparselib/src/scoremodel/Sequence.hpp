/**
 * A sequence = a list of events
 *
 * Utility class used for sequential calculations
 *
 * @author Philippe Rigaux
 */

#ifndef Sequence_hpp
#define Sequence_hpp

#include <stdio.h>

#include <vector>

#include "Event.hpp"

/**
 * A sequence is a list of events
 */

namespace ScoreModel {

class Part;
class Score;
class Note;


class Sequence {

public:
	/**
	 * Main constructor.
	 */
	Sequence();


	/**
	 * Add an event
	 */
	void addEvent(Event* event);

	/**
	 * Get events
	 */
	std::vector<Event*> getEvents() const;

	/**
	 * Concatenate a sub-sequence
	 */
	void concatenate(Sequence seq) ;

	/**
	 * Nb events
	 */
	int nbEvents() const;

	/**
	 * First event
	 */
	Event* getFirstEvent() const;

	/**
	 * Last event
	 */
	Event* getLastEvent() const;

	/**
	 * Destructor
	 */
	~Sequence();

private:

	/**
	 * A sequence is a sequence of events
	 */
	std::vector<Event*> _events;


};
}
#endif /* Sequence_hpp */
