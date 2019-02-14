///
//  InputSegmentMIDI.hpp
//  squant
//
//  Created by Florent Jacquemard on 06/04/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//

#ifndef InputSegmentMIDI_hpp
#define InputSegmentMIDI_hpp

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

#include "MidiFile.h"

#include "init.hpp"
#include "Rational.hpp"
#include "InputSegment.hpp"

/// @brief import an InputSegment from a MIDI file.
///
/// - The segment contains the NOTE-ON and NOTE-OFF events
/// in the MIDI file, with the realtime dates.
///
/// - The musical dates and duration as set to unknown.
///
/// - Every NOTE_ON event is linked to the closest posteroir NOTE-OFF
/// event with the same MIDI key.
/// It is left unmatched (without warning) if there is no such
/// matching NOTE-OFF.
///
/// - Several NOTE-ON with the same key may be linked to the same NOTE-OFF
/// (a warning is displayed in this case).
///
/// - Unmatched NOTE-OFF are added with a warning.
///
/// @ingroup input
class InputSegmentMIDI : public InputSegment
{
public:
    /// @brief read input segment from a MIDI file.
    ///
    /// The musical onsets and durations are all set to UNKNOWN.
    /// @param filename name of input MIDI file
    /// @param tracknb MIDI track read
    InputSegmentMIDI(const std::string filename, int tracknb=1);

    /// @brief read input segment from a MIDI file.
    ///
    /// The musical onsets and durations are all set to UNKNOWN.
    /// @param midifile a MIDIfile object
    /// @param tracknb MIDI track read
    InputSegmentMIDI(MidiFile& midifile, int tracknb=1);
    
    /// @brief read input segment from a MIDI file.
    ///
    /// the musical onsets and durations are all set to -1
    /// for backward compatibility.
    /// @param mono flag : set if we want a monophonic input segment.
    /// @param norest flag : if set, rests in MIDI file are ignored.
    ///
    /// @todo TBR
    InputSegmentMIDI(const std::string filename,
                     bool mono=true,
                     bool norest=false,
                     int tracknb=1);


    InputSegmentMIDI(const InputSegmentMIDI&);
                         
    virtual ~InputSegmentMIDI() {}
    
    inline std::string filename() const { return _filename; }
    
    //void save(const std::string filename);
    
    //export_midifile_mono(output_midifile, beatperbar)

    /// @brief copy input midifile into output_midifile.
    ///
    /// update the onsets / offsets to the quantized values in this segment.
    /// @warning this segment must have been created from a midi file.
    /// @warning the musical date and duration must have been set in this segment.
    ///
    /// @todo TBR mv export to segment/InputSegment* classes
    size_t export_midifile(std::string, Rational);

    /// @brief exit status code for MIDI import
    /// @return 0 if import or export worked well
    /// @return error code > 0 otherwise
    inline size_t status() const { return _status; }
    
    // midifile_export(output_midifile, beatperbar)

    /// @brief copy input midifile into output_midifile.
    ///
    /// update the onsets / offsets to the quantized values in this segment.
    /// @param midifile MIDIfile struct
    /// @param midiout name of output midifile
    /// @param beatperbar number of beats per bar (for producing output midifile)
    /// @warning this segment must have been created from a midi file.
    /// @warning the musical date and duration must have been set in this segment.
    ///
    /// @todo TBR mv export to segment/InputSegment* classes
    size_t export_midifile(MidiFile& midifile,
                           std::string midiout,
                           Rational beatperbar);

    /// @brief copy input midifile into output_midifile, monophonic case.
    ///
    /// update the onsets / offsets to the quantized values in this segment.
    /// @param midifile MIDIfile struct
    /// @param midiout name of output midifile
    /// @param beatperbar number of beats per bar (for producing output midifile)
    /// @warning this segment must have been created from a midi file.
    /// @warning the musical date and duration must have been set in this segment.
    ///
    /// @todo TBR mv export to segment/InputSegment* classes
    size_t export_midifile_mono(MidiFile& midifile,
                                std::string midiout,
                                Rational beatperbar);

private:
    /// @brief name of text file read for building this input segment
    ///
    /// @todo TBR mv export to segment/InputSegment* classes
    std::string _filename;
    
    /// @brief track number used for importing from MIDI file
    ///
    /// @todo TBR mv export to segment/InputSegment* classes.
    int _tracknb;
    
    /// @brief status code returned by import.
    size_t _status;
    
    /// @brief import input segment from MIDI file
    /// second arguent is track number.
    size_t import_midifile(MidiFile& midifile, int tracknb);
    
    /// @brief import monophonic input segment from MIDIfile
    /// second arguent is track number.
    void import_midifile_mono(MidiFile& midifile, int tracknb, bool norest);
    
    /// @brief add new timestamped polyphonic event.
    ///
    /// @todo TBR (tmp, for compatibility)
    void push(MusEvent* e, double onset, double duration);
    
    
    // search backward in segment for a muspoint with the given key nb
    // vector<MusPoint>::iterator find_back(const vector<MusPoint>::iterator i
    //                                      unsigned int key);
    
    // return the musevent find in this input segment  with the given MIDI number.
    // return NULL if there is none.
    // return the first if there are several.
    // @todo TBR
    //MusPoint* findMIDI(int);
    
//    size_t quantize_midievent(MidiEvent& event,
//                              int i, size_t j,
//                              Rational tpb);
    
};


#endif /* InputSegmentMIDI_hpp */

