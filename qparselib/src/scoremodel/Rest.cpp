// Implementation of Rest functions

#include "Rest.hpp"

namespace ScoreModel {

	// pitched note
	Rest::Rest(Duration duration):
	Event (duration)
	{
	}

	Event* Rest::clone()
	{
	    return new Rest(getDuration());
	}


	void Rest::print(std::ostream& o) const
	{
	    o << "Rest event";
	}
}
