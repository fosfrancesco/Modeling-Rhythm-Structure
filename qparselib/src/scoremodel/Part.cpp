// Implementation of Part functions

#include "Part.hpp"
#include "Score.hpp"

namespace ScoreModel {

// Main constructor
Part::Part(Score& score, std::string name) : _score(score),
		_name(name)
{
}


Score& Part::getScore() const
{
	return _score;
}


Voice* Part::getVoice(std::string voiceName) {
	for (Voice* voice : _voices) {
		// Loop on voices
		if (voice->getName() == voiceName) {
			return voice;
		}
	}
	//Gloup
	throw std::string("UNKNOWN VOICE ");

}

void Part::addVoice(Voice* v) {
	_voices.push_back(v);
}

// Destructor

Part::~Part() {

}
}
