#ifndef SM_Note_hpp
#define SM_Note_hpp

#include "Event.hpp"
#include "Voice.hpp"
#include "Measure.hpp"
#include "Duration.hpp"

namespace ScoreModel {


	class Note : public Event
	{
	public:
		// pitched note
		Note(Duration duration, Pitch p);

		~Note() {}

		virtual Event* clone() ;

		virtual bool isRest() const
		{	return false;}

		virtual bool isNote() const
		{	return true;}

		inline Pitch pitch() const {return _pitch;}
		virtual void print(std::ostream& o) const;

		//friend std::ostream& operator<<(std::ostream&, const Note&);

	protected:
		Pitch _pitch;
	};

}

#endif /* SM_Note_hpp */
