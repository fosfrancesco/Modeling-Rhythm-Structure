// Implementation of ScoreMeter functions


#include "ScoreMeter.hpp"


namespace ScoreModel {

Duration ScoreMeter::getMeasureDuration() const {
	return Duration (Rational (_meter_count, _meter_unit));
}

}
