/**
 * Abstract model of Events
 *
 * @author Philippe Rigaux
 */

#ifndef SM_Event_hpp
#define SM_Event_hpp

#include <stdio.h>

#include "Measure.hpp"
#include "Duration.hpp"

/**
 * An Event is anything that has a duration
 */
namespace ScoreModel {
class Voice;
class Beam;
class Event {

public:
	static const unsigned int UNDEF_VELOCITY;

	/**
	 * Main constructor.
	 */
	Event(Duration duration);


    virtual bool isRest() const
    { return true; }

    virtual bool isNote() const
    { return false; }


	inline void setGraceNote()  {_isGrace = true;}
	inline bool isGraceNote()  const {return _isGrace;}

	/**
	 * Get the duration of the Event
	 */
	inline Duration getDuration() const {
		return _duration;
	}
	;

	/**
	 * Set the duration of the Event
	 */
	inline void setDuration(Duration dur)  {
		 _duration = dur;
	}
	;

	inline void setVoice(Voice* voice)  {
		 _voice = voice;
	};

	inline Voice* getVoicePtr()  {
		return _voice;
	}
	;

	inline void setMeasure(Measure* measure)  {
		 _measure = measure;
	};

	inline Measure* getMeasure()  {
		return _measure;
	}
	;

    inline void setStartBeam(Beam *beam)  {
       _startBeam = beam;
    }
    ;
       inline Beam* getStartBeam()  {
       return _startBeam ;
    }
    ;

   inline void setEndBeam(Beam *beam)  {
       _endBeam = beam;
    }
    ;
      inline Beam* getEndBeam()  {
       return _endBeam ;
    }
    ;

	inline string getId() const {
		return _id;
	};

	inline void  setId(string id) {
		_id = id;
	};

	/**
	 * Destructor
	 */
	~Event();

private:

	/**
	 * An event always belongs to a voice
	 */
	Voice* _voice;

	/**
	 * An event always starts in a measure
	 */
	Measure* _measure;

	/**
	 * Each Event has a duration
	 */
	Duration _duration;

    /**
     * A beam can start at an event ; a beam can end on an event
     */
    Beam *_startBeam, *_endBeam;

	/**
	 * Id as a string for XML output
	 */
	string _id;

	/** Grace note or chord indicator
	 */
	bool _isGrace = false;
};
}

#endif /* Event_hpp */
