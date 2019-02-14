/// @addtogroup output
/// @{

// Implementation of MEI functions



#include "MEI.hpp"

using mei::documentToFile;
using mei::MeiDocument;
using mei::MeiElement;
using mei::MeiAttribute;
using mei::Note;
using mei::Rest;
using mei::Tie;
using mei::Beam;

namespace ScoreModel {
}
;
namespace sm = ScoreModel;

// Main constructor
MEI::MEI() :
		_document() {

	_scoreElement = new mei::Score();

	// Create the first levels of the document, down to the "Score" element
	MeiElement *root = new mei::Mei();
	MeiElement *music = new mei::Music();
	MeiElement *body = new mei::Body();
	MeiElement *mdiv = new mei::Mdiv();

	mdiv->addChild(_scoreElement);
	body->addChild(mdiv);
	music->addChild(body);
	root->addChild(music);
	_document.setRootElement(root);
}

// Create the document from a score
void MEI::createFromScore(const ScoreModel::Score &score) {

	// Create the score definition, as a child of the Score element
	createScoreDef(score);

	// Now create a new section, and add it to the score
	MeiElement *section = new mei::Section();
	_scoreElement->addChild(section);

	// OK, now we are ready to add measures to the section
	std::vector<sm::Measure*> measures = score.getMeasures();
	std::vector<sm::Measure*>::const_iterator measuresIt;

	int iTuplet = 0;

	for (measuresIt = measures.begin(); measuresIt != measures.end();
			measuresIt++) {
		std::cout << "Found measure  " << (*measuresIt)->getId() << std::endl;

		MeiElement *measure = new mei::Measure();
		measure->setId(std::to_string((*measuresIt)->getId()));

		// @todo : manage staves
		mei::Staff *staff = new mei::Staff();
		staff->setN("1");

		// List of tuplet spans
		std::vector<TupletSpan*> listSpans;

		// Loop on the voices, extract events that belong to the measure
		// NB quite stupid algorithm, repeatedly scan the voice.

		for (sm::Part* part : score.getParts()) {
			std::cout << part->getName() << ' ';
			for (sm::Voice* voice : part->getVoices()) {
				// Loop on voices
				std::cout << "Found voice " << voice->getName() << std::endl;
				std::pair<Pitch, Pitch> range = voice->getRange();
				sm::Voice trimmedVoice = voice->trimMeasure(*measuresIt);

				// A voice = a layer in MEI terms
				MeiElement *layer = new mei::Layer();
				Beam *currentBeam = NULL;
				// Loop on events
				for (sm::Event* event : trimmedVoice.getEvents()) {
					//std::cout << "new event " << std::endl;
					// Does a beam start here?
					if (event->getStartBeam() != NULL) {
						// std::cout << "A beam starts here " << std::endl;
						currentBeam = new Beam();
					}

					MeiElement *newElement = NULL;
					if (event->isNote()) {
						// Create the MEI element
						Note* note =  MEI::makeNote( (sm::Note*) event);
						newElement = note;
					}
					else if (event->isRest()) {
						Rest *rest = new Rest();
						rest->m_DurationMusical.setDur(std::to_string(event->getDuration().getCMN()));
						newElement = rest;
					}

					// Keep the id of the MEI element in the event
					event->setId(newElement->getId());

					// Add to the layer or to the beam
					if (currentBeam != NULL && !event->isGraceNote()) {
						//std::cout << "The beam starts here " << std::endl;
						currentBeam->addChild(newElement);
					} else {
						layer->addChild(newElement);
					}

					// Does a beam end here?
					if (event->getEndBeam() != NULL) {
						//std::cout << "The beam ends here " << std::endl;
						if (currentBeam == NULL) {
							/// Check with eth Spiritual example: case of a
							// tuplet followed by a single note
							//std::cout << "BEAM NULL" << std::endl;
						}
						else {
							layer->addChild(currentBeam);
							currentBeam = NULL;
						}
					}
					// std::cout << "end event " << std::endl;
				}

				// Loop on ties
				for (const sm::Tie* tie : voice->getTies()) {
					// {Put the tie element in the measure that contains the last note
					if (tie->second->getMeasure()->getId()
							== (*measuresIt)->getId()) {
						measure->addChild(MEI::makeTie(tie));
					}
				}

				// Tuplets
				for (const sm::Tuplet* tuplet : voice->getTuplets()) {
					if (tuplet->getFirstEvent()->getMeasure()->getId()
							== (*measuresIt)->getId()) {
						listSpans.push_back(MEI::makeTupletSpan(tuplet));
					}
				}
				staff->addChild(layer);
			}
			std::cout << '\n';
		}
		measure->addChild(staff);

		// Add the tuplets and beams
		for (TupletSpan* meiTuplet : listSpans) {
			measure->addChild(meiTuplet);
		}
		listSpans.clear();

		section->addChild(measure);
	}
}

// Create the score definition part
void MEI::createScoreDef(const ScoreModel::Score &score) {
	MeiElement *scoreDef = new mei::ScoreDef();
	MeiElement *staffGrp = new mei::StaffGrp();
	mei::StaffDef *staffDef = new mei::StaffDef();

	int iStaff = 1;
	for (sm::Part* part : score.getParts()) {
		std::cout << part->getName() << ' ';
		for (sm::Voice* voice : part->getVoices()) {
			// Loop on voices
			std::cout << "Found voice " << voice->getName() << std::endl;
			std::pair<Pitch, Pitch> range = voice->getRange();
			std::cout << "Voice range : " << range.first.midi() << " "
					<< range.second.midi() << std::endl;

			// Clef
			std::pair<string, int> clef = chooseClef(voice->getRange());
			MeiAttribute *cLine = new MeiAttribute("clef.line",
					std::to_string(clef.second));
			MeiAttribute *cShape = new MeiAttribute("clef.shape", clef.first);
			MeiAttribute *staffLines = new MeiAttribute("lines", "5");
			staffDef->addAttribute(cLine);
			staffDef->addAttribute(cShape);
			staffDef->addAttribute(staffLines);
			staffDef->setN(std::to_string(iStaff++));
			staffGrp->addChild(staffDef);
		}
	}

	// The meter
	ScoreModel::ScoreMeter meter = score.getMeter();
	MeiAttribute *mCount = new MeiAttribute("meter.count",
			std::to_string(meter.getCount()));
	MeiAttribute *mUnit = new MeiAttribute("meter.unit",
			std::to_string(meter.getUnit()));
	scoreDef->addAttribute(mCount);
	scoreDef->addAttribute(mUnit);
	scoreDef->addChild(staffGrp);

	// Add the score definition to the MEI score element
	_scoreElement->addChild(scoreDef);
}

// Choose the clef from the range opf the voice
std::pair<string, int> MEI::chooseClef(std::pair<Pitch, Pitch> range) {
	std::pair<string, int> clef("G", 2);

	if (range.second.midi() < 65) {
		clef.first = "F";
		clef.second = 4;
	} else if (range.first.midi() >= 57) {
		clef.first = "G";
		clef.second = 2;
	} else if (range.second.midi() < 74) {
		clef.first = "C";
		clef.second = 3;
	}

	return clef;
}

// Save in file
void MEI::writeInFile(const string fname) {
	documentToFile(&_document, fname);
}

// Static method to create a note
Note* MEI::makeNote(const sm::Note* noteEvent) {
	Note *n1 = new Note();
	string name;

	//std::cout << "Found event with duration "
	//		<< event->getDuration().getValue() << std::endl;

	name += tolower(noteEvent->pitch().name);
	n1->m_Pitch.setPname(name);
	if (noteEvent->pitch().alteration > 0) {
		n1->m_Accidental.setAccid("s");
	}
	else if (noteEvent->pitch().alteration < 0) {
		n1->m_Accidental.setAccid("f");
	}

	n1->m_Octave.setOct(std::to_string(noteEvent->pitch().octave));
	n1->m_DurationMusical.setDur(std::to_string(noteEvent->getDuration().getCMN()));

	// Grace node
	if (noteEvent->isGraceNote()) {
		MeiAttribute *grace = new MeiAttribute("grace", "acc");
		n1->addAttribute(grace);
	}

	return n1;
}

// Static method to create a tie
Tie* MEI::makeTie(const sm::Tie* tie) {
	//std::cout << "Found a tie between " << tie->first->getId() << " and "
	//		<< tie->second->getId() << std::endl;
	Tie* meiTie = new Tie();
	MeiAttribute *startId = new MeiAttribute("startid", tie->first->getId());
	meiTie->addAttribute(startId);
	MeiAttribute *endId = new MeiAttribute("endid", tie->second->getId());
	meiTie->addAttribute(endId);
	return meiTie;
}

// Static method to create a tuplet span
TupletSpan* MEI::makeTupletSpan(const sm::Tuplet* tuplet) {

	std::cout << "Create a tuplet with " << tuplet->nbEvents() << " events "
			<< std::endl;

	TupletSpan* meiTuplet = new TupletSpan();
	MeiAttribute *startId = new MeiAttribute("startid",
			tuplet->getFirstEvent()->getId());
	meiTuplet->addAttribute(startId);
	MeiAttribute *endId = new MeiAttribute("endid",
			tuplet->getLastEvent()->getId());
	meiTuplet->addAttribute(endId);
	string listEventsId = "";
	for (sm::Event* event : tuplet->getEvents()) {
		listEventsId.append(event->getId()).append(" ");
	}
	MeiAttribute *plist = new MeiAttribute("plist", listEventsId);
	meiTuplet->addAttribute(plist);

	MeiAttribute *num = new MeiAttribute("num",
			std::to_string(tuplet->getArity()));
	meiTuplet->addAttribute(num);
	MeiAttribute *numbase = new MeiAttribute("numbase",
			std::to_string(tuplet->getNumBase()));
	meiTuplet->addAttribute(numbase);

	return meiTuplet;
}

// Destructor

MEI::~MEI() {

}


/// @}
