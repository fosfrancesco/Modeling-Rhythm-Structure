/**
 * Abstract class for spanning elements
 *
 * @author Philippe Rigaux
 */


#ifndef SpanningElement_hpp
#define SpanningElement_hpp

#include <stdio.h>

/**
 * A spanning element provides a notation for a sequence of events. 
 *
 * Examples of sub-classes are: slurs, beams, tuplets
 */

#include "Event.hpp"
#include "Sequence.hpp"

namespace ScoreModel {

class SpanningElement: public Sequence
{

public:
	/**
	 * Main constructor.
	 */
    SpanningElement();
 
};
}
#endif /* SpanningElement_hpp */
