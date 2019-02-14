/**
 * Measures
 *
 * @author Philippe Rigaux
 */


#ifndef SM_Measure_hpp
#define SM_Measure_hpp

#include <stdio.h>

#include "ScoreMeter.hpp"

namespace ScoreModel {

/**
 * An measure is a container of fixed duration, defined by a ScoreMeter
 */

class Measure
{

public:
	/**
	 * Main constructor.
	 */
    Measure(int id, ScoreMeter meter);
    
    /**
     * Get the measure id
     */
    inline int getId() const {return _id;};

    /**
     * Get the duration of a measure
     */
    inline Duration getDuration() const {return _meter.getMeasureDuration();};


    /**
     * Destructor
     */
    ~Measure();
    
private:

    /**
     * Id  of the measure, should be unique for a score
     */
    int _id;

    /**
     * Each measure knows its ScoreMeter, usually the global score meter
     */
    ScoreMeter _meter;

};

}
#endif /* measure_hpp */
