/**
 * Representation and management of beams
 *
 * @author Philippe Rigaux
 */


#ifndef Beam_hpp
#define Beam_hpp

#include <stdio.h>

/**
 * A beam encompasses n events
 */

#include "Sequence.hpp"

namespace ScoreModel {

class Beam : public Sequence
{

public:
	/**
	 * Main constructor.
	 */
    Beam(Sequence events);
    
    /**
     * Destructor
     */
    ~Beam();
    
};

}
#endif /* Beam_hpp */
