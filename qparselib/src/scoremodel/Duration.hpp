/**
 * Representation of duration
 *
 * @author Philippe Rigaux
 */


#ifndef Duration_hpp
#define Duration_hpp

#include <stdio.h>

#include "Rational.hpp"


/**
 * A duration has an internal representation as a rational.
 *
 * Value 1 is a whole note
 *
 * Several utility methods allow to get the symbolic representation
 */

namespace ScoreModel {

class Duration
{

public:
	/**
	 * Main constructor.
	 */
    Duration(Rational ratio);
    
    /**
     * Get the duration value as a rational: nb beats / beat unit
     */
    inline Rational getValue() const {return _value;};

    /**
     * Set the duration value as a rational: nb beats / beat unit
     */
    inline void setValue(Rational value)  { _value = value;};

    /**
     * Get the CMN code
     *
     * The CMN code is a value ranging from 1 (whole note) to 256, and is always a power of 2.
     * In the score output, intermediate durations (eg triplets) are usually obtained by
     * applying a tuplet ratio to the CMN code.
     */
    int getCMN() const;

    /**
     * Destructor
     */
    ~Duration();
    
    /**
    * Some constants
    */
    static const int QUARTER_DURATION=4;
private:

    Rational _value;

};
}
#endif /* Duration_hpp */
