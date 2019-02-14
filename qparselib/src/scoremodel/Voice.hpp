/**
 * Abstract model of voice
 *
 * @author Philippe Rigaux
 */

#ifndef Voice_hpp
#define Voice_hpp

#include <stdio.h>

#include <vector>

#include "Event.hpp"
#include "Measure.hpp"
#include "PointedRT.hpp"
#include "Sequence.hpp"
#include "Tuplet.hpp"
#include "Beam.hpp"

/**
 * A voice is a sequence of event, belonging to a Part
 */

namespace ScoreModel {

class Part;
class Score;
class Note;

typedef std::pair<Pitch, Pitch> VoiceRange;

typedef std::pair<Note*, Note*> Tie;


class Voice {

public:
	/**
	 * Main constructor.
	 */
	Voice(Part* part, std::string name);

	inline std::string getName() const {
		return _name;
	}
	;

	Part* getPart() const;

	Score& getScore() const;

	/**
	 * Add an event
	 */
	void addEvent(Event* event);

	/**
	 * Add a tie between two notes
	 */
	void addTie(Note* e1, Note* e2);

	/**
	 * Add a tuplet
	 */
	void addTuplet(Tuplet *tuplet);

    /**
     * Add a beam
     */
    void addBeam(Beam *beam);

	/**
	 * Add a new measure or part of a measure from a rhythm tree
	 *
	 * The method return a sub-voice containing the added elements
	 */
	Sequence addFromRhythmTree(Measure* measure, const PointedRhythmTree* pointedRT,
			Duration rtDuration, int level=0);

	/**
	 * Extract the part that belongs to a measure
	 */
	Voice trimMeasure(Measure* m);

	/**
	 * get the range of a voice a a pair of pitches
	 */
	VoiceRange getRange() const;

	/**
	 * Get events
	 */
	std::vector<Event*> getEvents() const;

	/**
	 * Get ties
	 */
	std::vector<Tie*> getTies() const;

	/**
	 * Get tuplets
	 */
	std::vector<Tuplet*> getTuplets() const;

    /**
     * Get beams
     */
    std::vector<Beam*> getBeams() const;

	/**
	 * Destructor
	 */
	~Voice();

private:

	/**
	 * The part the voice belongs to
	 */
	Part* _part;

	/**
	 * A voice has a name
	 */
	std::string _name;

	/**
	 * A score is a sequence of events
	 */
	std::vector<Event*> _events;

	/**
	 * Ties between events
	 */
	std::vector<Tie*> _ties;

	/**
	 * Tuplets
	 */
	std::vector<Tuplet*> _tuplets;

    /**
     * Beams
     */
    std::vector<Beam*> _beams;

};
}
#endif /* Voice_hpp */
