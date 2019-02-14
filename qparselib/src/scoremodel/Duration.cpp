// Implementation of Duration functions

#include "Duration.hpp"


namespace ScoreModel {
// Main constructor
Duration::Duration(Rational ratio): _value (ratio)
{
}


int Duration::getCMN() const
{
	for (int i=0; i <=8; i++) {
	   // EG: 3/4 = 3  quarters, 1/4 = 1 quarter, 2/8 = 2 eigth = 1 quarter, etc.
	      int duration = _value.denominator() /  _value.numerator() ;
	      
	   // @todo check whether the note is dotted or not 
		if (pow(2, i) <=  duration &&  duration < pow(2, i+1)) {
			return pow(2, i);
		}
	}
   // Not found??
	return 1;

}

// Destructor

Duration::~Duration()
{

}

}

