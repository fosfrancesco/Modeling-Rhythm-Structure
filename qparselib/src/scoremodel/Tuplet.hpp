/**
 * Representation of yuplets
 *
 * @author Philippe Rigaux
 */


#ifndef Tuplet_hpp
#define Tuplet_hpp

#include <stdio.h>


/**
 * A tuplet encompasses n events, and covers a regular duration
 *
 */

#include "Duration.hpp"
#include "Event.hpp"
#include "Sequence.hpp"

namespace ScoreModel {

class Tuplet
{

public:
	/**
	 * Main constructor.
	 */
    Tuplet(Duration duration, Sequence events, int arity);
    
    /**
     * Destructor
     */
    ~Tuplet();
    

	/**
	 * Duration of the tuplet
	 */
	Duration getDuration() const;

	/**
	 * Nb events
	 */
	int nbEvents() const;

	/**
	 * Base duration = duration of regular tuplet events, before applying the ratoi
	 *
	 * Example: a triplet of eigthth, the base duration is the eighth
	 */
	Duration getBaseDuration() const;

	/**
	 * Arity = the number of duration-equal timespans the tuplet is decomposed in
	 */
	int getArity() const;

	/**
	 * Numbase = the regular number of  base duration in the tuplet
	 *
	 * Example: a triplet of eigthth correspond to 2 (two) regular eigthth
	 */
	int getNumBase() const;


	/**
     * Get the first event of the tuplet sequence
     */
	Event* getFirstEvent() const;

	/**
	 * Last event
	 */
	Event* getLastEvent() const;

	/**
	 * Get events
	 */
	std::vector<Event*> getEvents() const;


private:
    Duration _duration;
    Sequence _events;
	int _arity;
};

}
#endif /* Duration_hpp */
