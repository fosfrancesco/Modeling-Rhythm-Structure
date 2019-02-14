/**
 * Representation of a score meter
 *
 * @author Philippe Rigaux
 */


#ifndef ScoreMeter_hpp
#define ScoreMeter_hpp

#include <stdio.h>

#include "init.hpp"
#include "trace.hpp"

#include "Duration.hpp"


namespace ScoreModel {

/**
 * The score class: models a score content
 *
 *
 */


class ScoreMeter
{

public:
	/**
	 * Main constructor.
	 */
    ScoreMeter(int meter_count, int meter_unit) {
    	_meter_count = meter_count;
    	_meter_unit = meter_unit;
    }

    /***
     * Accessors
     */
    inline int getCount() const {return _meter_count;}
    inline int getUnit() const {return _meter_unit;}

    Duration getMeasureDuration() const;

    /**
     * Destructor
     */
    ~ScoreMeter() {};
    
private:
    /**
     * A score has a meter
     */
    
    int _meter_count, _meter_unit;

};
}

#endif /* ScoreMeter_hpp */
