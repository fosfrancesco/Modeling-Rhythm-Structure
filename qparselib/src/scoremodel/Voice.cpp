// Implementation of Part functions

#include "Voice.hpp"
#include "Score.hpp"
#include "Note.hpp"
#include "Rest.hpp"
#include "Part.hpp"

namespace ScoreModel {

// Last note met during a voice creation. Used for ties.
// Try to find better
static Event* lastEvent = NULL;

// Main constructor
Voice::Voice(Part* part, std::string name) :
		_part(part), _name(name) {

}

Score& Voice::getScore() const {
	return _part->getScore();
}

Part* Voice::getPart() const {
	return _part;
}
;

// Add an event
void Voice::addEvent(Event* event) {
	event->setVoice(this);
	_events.push_back(event);
}

// Add a tie
void Voice::addTie(Note* e1, Note* e2) {
	Tie* tie = new Tie(e1, e2);
	_ties.push_back(tie);
}

// Add a tuplet
void Voice::addTuplet(Tuplet* tuplet) {
	_tuplets.push_back(tuplet);
}

// Add a beam
void Voice::addBeam(Beam* beam) {
	_beams.push_back(beam);
}

std::vector<Event*> Voice::getEvents() const {
	return _events;
}

Voice Voice::trimMeasure(Measure* m) {
	Voice measVoice = Voice(_part, _name + "-" + std::to_string(m->getId()));

	for (Event* event : _events) {
		if (event->getMeasure()->getId() == m->getId()) {
			measVoice.addEvent(event);
		}
	}

	return measVoice;
}

Sequence Voice::addFromRhythmTree(Measure* measure,
		const PointedRhythmTree* pointedRT, Duration rtDuration, int level) {
	// OK, now scan the rhythm tree to extract the measure content

	Sequence seq = Sequence();

	if (pointedRT->terminal()) {
		label_t a = pointedRT->label();
		size_t g = Label::nbGraceNotes(a);

		// tie
		if (Label::continuation(a)) {
			// Found a continuation mark
			for (int i = 0; i < level; i++) {
				std::cout << "\t";
			}
			std::cout << "Found a continuation mark level = " << level
					<< std::endl;
			// Prepare the next note in case of continuation
			if (lastEvent != NULL) {
				Event *newEvent = NULL;
				if (lastEvent->isNote()) {
					Note *newNote = new Note(rtDuration, ((Note*)lastEvent)->pitch());
					// Add a a tie betwwen the last note and the new note
					addTie(((Note*)lastEvent), newNote);
					newEvent = newNote;
				}
				else {
					newEvent = new Rest(rtDuration);
				}
				newEvent->setMeasure(measure);
				addEvent(newEvent);
				lastEvent = newEvent;
				// Add to the sequence
				seq.addEvent(newEvent);
			}
		} else // [grace notes +] note
		{
			for (int i = 0; i < level; i++) {
				std::cout << "\t";
			}
			std::cout << "Found a note or rest. Nb graces = " << g
					<< " Label = " << a << " duration " << rtDuration.getValue()
					<< std::endl;
			int iNote = 0;
			for (const MusEvent* musEvent : pointedRT->events) {
				if (musEvent->isNote()) {
					NoteEvent* noteEvent = (NoteEvent*) musEvent;
					Pitch pitch = noteEvent->pitch();
					// Add the note
					Note* note = new Note(rtDuration, pitch);
					note->setMeasure(measure);
					addEvent(note);
					lastEvent = note;

					if (iNote < g) {
						// Grace note
						note->setGraceNote();
					}
					// Add to the sequence
					seq.addEvent(note);
				} else if (musEvent->isRest()) {
					Rest* rest = new Rest(rtDuration);
					rest->setMeasure(measure);
					addEvent(rest);
					lastEvent = rest;
				}
				iNote++;
			}
		}
	} else // inner()
	{
		size_t a = pointedRT->arity();
		Duration childDuration = Rational(rtDuration.getValue().numerator(),
				rtDuration.getValue().denominator() * a);
		assert(a > 1);
		for (int i = 0; i < level; i++) {
			std::cout << "\t";
		}
		std::cout << "Inner node with duration " << rtDuration.getCMN()
				<< " Nb children = " << a << " duration of each child "
				<< childDuration.getValue() << std::endl;
		for (size_t i = 0; i < a; i++) {
			// Recursive call
			const PointedRhythmTree* child =
					(const PointedRhythmTree*) pointedRT->child(i);
			seq.concatenate(
					addFromRhythmTree(measure, child, childDuration,
							level + 1));
		}

		if (rtDuration.getCMN() == Duration::QUARTER_DURATION
				&& seq.nbEvents() > 1 && !seq.getFirstEvent()->isRest()) {
			for (int i = 0; i < level; i++) {
				std::cout << "\t";
			}
			std::cout << "FOUND A BEAM " << std::endl;
			// @todo we should check that we did not already added inner beams for tuplets
			// Can be done in Beam.cpp
			Beam* beam = new Beam(seq);
			addBeam(beam);
		}

		if (a > 2 && rtDuration.getValue().numerator() != 3
				&& rtDuration.getValue().numerator() != 9) {
			// Tuplet
			if (seq.nbEvents() > 1) {
				std::cout << "FOUND A TUPLET with  " << a
						<< " events with duration " << rtDuration.getValue()
						<< std::endl;
				Tuplet* tuplet = new Tuplet(rtDuration, seq, a);
				addTuplet(tuplet);
				// Add a beam for the tuplet.
				Beam* beam = new Beam(seq);
				addBeam(beam);
			}
		}
	}

	return seq;
}

VoiceRange Voice::getRange() const {
	std::pair<Pitch, Pitch> range(Pitch(127, Pitch::MIDI),
			Pitch(0, Pitch::MIDI));

	for (Event* event : _events) {
		if (event->isNote()) {
			Note* noteEvent = (Note*) event;
			Pitch pitch = noteEvent->pitch();
			if (pitch.midi() < range.first.midi()) {
				range.first = pitch;
			}
			if (pitch.midi() > range.second.midi()) {
				range.second = pitch;
			}
		}
	}

	return range;
}

std::vector<Tie*> Voice::getTies() const {
	return _ties;
}

std::vector<Tuplet*> Voice::getTuplets() const {
	return _tuplets;
}

std::vector<Beam*> Voice::getBeams() const {
	return _beams;
}

// Destructor

Voice::~Voice() {

}
}
