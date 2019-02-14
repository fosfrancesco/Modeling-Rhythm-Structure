/**
 * MEI interface. Can be used to output MEI document from a transcription result
 *
 * @author Philippe Rigaux
 */

/// @addtogroup output
/// @{


#ifndef MEI_hpp
#define MEI_hpp

#include <stdio.h>
#include <vector>

#include "init.hpp"
#include "trace.hpp"
#include "ValueList.hpp"

#include "RT.hpp"

#include "Score.hpp"
#include "Measure.hpp"
#include "Note.hpp"
#include "Beam.hpp"
#include "Tuplet.hpp"

#include <mei/mei.h>
#include <mei/meielement.h>
#include <mei/shared.h>
#include <mei/cmn.h>
#include <mei/xmlexport.h>

using mei::Note;
using mei::TupletSpan;
using mei::Tie;

/**
 * The main MEI class.
 *
 * Takes a Rhythm tree as input, and creates a MEI score
 */


class MEI
{

public:
	/**
	 * Main constructor
	 */
    MEI();
    
    /*
     * Create a MEI document from a Score object
     *
     */
    void createFromScore(const ScoreModel::Score &s);

    /**
     * Create the score definition part
     */
    void createScoreDef(const ScoreModel::Score &s);

    /**
     * Find whether a beam start on an event
     */
    void findStartingBeam(const ScoreModel::Score &s);

    /**
    * Save in file
    */
    
    void writeInFile(const string fname);

    /**
     * Choose a clef based on range
     */
    std::pair<string, int> chooseClef (std::pair<Pitch, Pitch> range);

    /****
     * Static method to instantiate MEI element fromt ScoreModel objects
     */
    static Note* makeNote(const ScoreModel::Note* noteEvent);
    static TupletSpan* makeTupletSpan(const ScoreModel::Tuplet* tuplet);
    static Tie* makeTie(const ScoreModel::Tie* tie);

    /**
     * Destructor
     */
    ~MEI();
    
private:
    /**
     * The MEI document
     */
    
    mei::MeiDocument _document;
    
    /**
     * The score element: contains the music
     *
     */
    mei::Score *_scoreElement;

};

#endif /* MEI_hpp */


/// @}
