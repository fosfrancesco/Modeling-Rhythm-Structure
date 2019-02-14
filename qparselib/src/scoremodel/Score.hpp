/**
 * Model of a score
 *
 * @author Philippe Rigaux
 */

#ifndef Score_hpp
#define Score_hpp

#include <stdio.h>

#include <vector>

#include "ScoreMeter.hpp"
#include "Part.hpp"
#include "Measure.hpp"


/**
 * The score class: models a score content
 *
 */

namespace ScoreModel {

class Score {

public:
	/**
	 * Main constructor. Builds an empty score in 4/4
	 */
	Score();

	/**
	 * Monody score constructor.
	 *
	 * takes the single part/name voice, and the meter
	 */
	Score(std::string name, ScoreMeter meter);

	/**
	 * Getter/setter for meter
	 */
	ScoreMeter getMeter() const;

	std::string getName() const;

	/**
	 * Get a voice from the part and voice name
	 */
	Voice* getVoice (std::string partName, std::string voiceName);

	/**
	 * Get all parts
	 */
	std::vector<Part*> getParts() const;

	/**
	 * Add a new part
	 */
	void addPart(Part* p);

	/**
	 * Add a new measure
	 */
	Measure* addMeasure();

	/**
	 * Iterator to scan measures
	 */
	std::vector<Measure*> getMeasures() const;

	/**
	 * Destructor
	 */
	~Score();

private:
	/**
	 * A score has a name
	 */

	std::string _name;

	/**
	 * A score has a meter
	 */

	ScoreMeter _meter;

	/**
	 * A score is a set of Parts
	 */
	std::vector<Part*> _parts;

	/**
	 * A score is organized as a list of measures, common to all parts
	 */
	std::vector<Measure*> _measures;

};

}
#endif /* Score_hpp */
