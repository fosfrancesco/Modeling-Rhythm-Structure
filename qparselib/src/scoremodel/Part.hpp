/**
 * Model of a part
 *
 * @author Philippe Rigaux
 */


#ifndef Part_hpp
#define Part_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "Voice.hpp"

/**
 * A part is a set of voices, to be played by a single instrument/performer
 */

namespace ScoreModel {

class Score;

class Part
{

public:
	/**
	 * Main constructor. Builds an empty part
	 */
    Part(Score& score, std::string name);
    
    inline std::string getName() const {return _name;};

    Score& getScore() const;

    /**
     * Add a voice
     */
    void addVoice (Voice* voice);

	/**
	 * Get a voice from its name
	 */
	Voice* getVoice (std::string voiceName);

	/**
	 * Get all voices
	 */
	inline std::vector<Voice*> getVoices() {return _voices;};

    /**
     * Destructor
     */
    ~Part();
    
private:

    /**
     * A part has a name
     */
    std::string _name;

    /**
     * A part belongs to a score
     */
    Score&  _score;

    /**
     * A part is a sequence of voices
     */
    std::vector<Voice*> _voices;

};
}

#endif /* Part_hpp */
