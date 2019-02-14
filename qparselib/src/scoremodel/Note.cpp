// Implementation of Note functions


#include "Note.hpp"

namespace ScoreModel {

	// pitched note
	Note::Note(Duration duration, Pitch p):
	Event (duration),
	_pitch(p)
	{
	}

	Event* Note::clone()
	{
	    return new Note(getDuration(), _pitch);
	}


	void Note::print(std::ostream& o) const
	{
	    o << _pitch;
	}


}
