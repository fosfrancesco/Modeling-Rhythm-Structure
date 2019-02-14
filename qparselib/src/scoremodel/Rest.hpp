#ifndef SM_Rest_hpp
#define SM_Rest_hpp

#include "Event.hpp"
#include "Measure.hpp"
#include "Duration.hpp"

namespace ScoreModel {


	class Rest : public Event
	{
	public:
		Rest(Duration duration);

		~Rest() {}

		virtual Event* clone() ;

		virtual bool isRest() const
		{	return true;}

		virtual bool isNote() const
		{	return false;}

		virtual void print(std::ostream& o) const;

		//friend std::ostream& operator<<(std::ostream&, const Note&);

	protected:
	};

}

#endif /* SM_Rest_hpp */
