// Implementation of Score functions

#include "Score.hpp"



namespace ScoreModel {
// Main constructor
Score::Score(): _name("score"), _meter(4,4)
{
}

// Main constructor
Score::Score (std::string name, ScoreMeter meter): _name(name), _meter(meter)
{
    ScoreModel::Part* part = new ScoreModel::Part(*this, name);
    ScoreModel::Voice* voice = new ScoreModel::Voice(part, name);
    part->addVoice(voice);
    this->addPart(part);
}

Voice* Score::getVoice (std::string partName, std::string voiceName)
{
	for (Part*  part : _parts) {
	    if (part->getName() == partName) {
	    	return part->getVoice (voiceName);
	    }
	}

	//Gloup
	throw std::string("UNKNOWN PART ");
}

ScoreMeter Score::getMeter() const
{
	return _meter;
}

std::string Score::getName() const {return _name;}

std::vector<Part*> Score::getParts() const
{
	return _parts;
}

 void Score::addPart(Part* p)
 {
	 _parts.push_back(p);
 }

 Measure* Score::addMeasure()
 {
	 // Increment id
	 int id = _measures.size() + 1;
	Measure* measure =  new Measure (id, _meter);
	_measures.push_back(measure);
	 return _measures.back();
 }

std::vector<Measure*> Score::getMeasures() const
{
	return _measures;
}

// Destructor

Score::~Score()
{

}

}
