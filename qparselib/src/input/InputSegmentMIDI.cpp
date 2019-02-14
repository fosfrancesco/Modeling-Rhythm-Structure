//
//  InputSegmentMIDI.cpp
//  squant
//
//  Created by Florent Jacquemard on 06/04/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//

#include "InputSegmentMIDI.hpp"


InputSegmentMIDI::InputSegmentMIDI(const std::string filename,
                                   int tracknb):
InputSegment(0, 0),
_filename(filename),
_tracknb(tracknb),
_status(0)
{
        MidiFile file;
        int status = file.read(filename);
        if (status == 0)
        {
            ERROR("could not read MIDI file: {}", filename);
            _filename = "";
            // input segment will be empty
            _status = 1;
        }
        else
        {
            _status = import_midifile(file, tracknb);
        }

    assert(0 <= _begin);
    assert(_begin <= _end);
    _len = _end - _begin;
    //    assert(_bars > 0);
    //    _period = _len/_bars;
}


InputSegmentMIDI::InputSegmentMIDI(MidiFile& midifile,
                                   int tracknb):
InputSegment(0, 0),
_filename(""), // @todo TBR
_tracknb(tracknb),
_status(0)
{
    _status = import_midifile(midifile, tracknb);
    
    assert(0 <= _begin);
    assert(_begin <= _end);
    _len = _end - _begin;
    //    assert(_bars > 0);
    //    _period = _len/_bars;
}


InputSegmentMIDI::InputSegmentMIDI(const InputSegmentMIDI& s):
InputSegment(s),
_filename(s._filename),
_tracknb(s._tracknb),
_status(s._status)
{ }


size_t InputSegmentMIDI::import_midifile(MidiFile& midifile, int tracknb)
{
    midifile.absoluteTicks();
    midifile.joinTracks();
    midifile.linkNotePairs();
    
    int eventcount = midifile.getEventCount(0);
    int track;
    // ticks per quarter note
    double tpqn = (double) midifile.getTicksPerQuarterNote();
    int timeinticks = 0;
    double timeinsecs = 0;
    bool init = true;
    unsigned int lastkey = 128; // 0-127 = MIDI key number
    
    // one stack of indexes of note-on events for each MIDI key
    std::vector<std::stack<long>> noteons;
    noteons.resize(128);
    // @todo assert size noteons <= 1
    
    INFO("midifile has {} tracks, hasJoinedTracks={}, Ticks per Quarter Note={}",
         midifile.getNumTracks(),
         midifile.hasJoinedTracks(),
         midifile.getTicksPerQuarterNote());
    
    // all tracks merged into tracks 0
    if (! midifile.hasJoinedTracks())
    {
        WARN("MIDIfile has not joined tracks");
        tracknb = 0;
    }
    
    // one pass to
    // set input segment start date and
    // import MIDIfile events to input segment.
    for (int i = 0; i < eventcount; i++)
    {
        MidiEvent& e = midifile[0][i];
        lastkey = e.getKeyNumber();
        track = e.track;
        timeinticks = e.tick;
        //time in seconds
        //timeinsecs = midifile.getTimeInSeconds(0, i);
        //timeinsecs = midifile.getTimeInSeconds(timeinticks);
        //time in quarter notes
        timeinsecs  = ((double) timeinticks) / tpqn;
        assert(0 <= lastkey);
        assert(lastkey < 128);

        // ignore messages on other tracks
        if (track != tracknb)
        {
            WARN("{}: event {} track {} ignored", timeinsecs, i, track);
            continue;
        }

        NoteEvent* event =
            new NoteEvent(lastkey, e.getVelocity(), i);

        // NOTE ON
        if (e.isNoteOn())
        {
            if (init)
            {
                _begin = timeinsecs;
                init = false;
            }
            
            // add note-on to segment.
            // link to note-off will be completed later.
            long it = add_back(event, timeinsecs, 0, false);
            //                 other args default
            //                 MUSPOINTREF_NULL
            //                 MUSTIME_UNKNOWN
            //                 MUSTIME_UNKNOWN
            assert(0 <= it);
            assert(it < _events.size());
            TRACE("{}: add note-on {}", timeinsecs, *event);

            // stack this note-on
            if (! noteons[lastkey].empty())
            {
                WARN("{}: multiple successive NOTEON (without OFF) on same key {} (event {} track {})",
                     timeinsecs, lastkey, i, track);
            }
            noteons[lastkey].push(it);
        }
        // NOTE OFF
        else if (e.isNoteOff())
        {
            if (init)
            {
                WARN("{}: event {} track {} : initial pending NOTEOFF",
                     timeinsecs, i, track);
                _begin = timeinsecs;
                init = false;
            }

            // add note-off without link.
            long it = add_back(event, timeinsecs, 0, false);
            assert(0 <= it);
            assert(it < _events.size());
            TRACE("{}: add note-off {}", timeinsecs, *event);

            // link the last matching note on
            if ( noteons[lastkey].empty() )
            {
                WARN("{}: event {} track {} : pending note-off (key={})",
                     timeinsecs, i, track, lastkey);
            }
            if ( noteons[lastkey].size() > 0 )
            {
                WARN("{}: event {} track {} : 1 note-off for {} note-on (key={})",
                     timeinsecs, i, track, noteons[lastkey].size(), lastkey);
            }
            while (! noteons[lastkey].empty())
            {
                long linkon = noteons[lastkey].top();
                noteons[lastkey].pop();
                assert(0 <= linkon);
                assert(linkon < _events.size());
                link(linkon, it);
                MusPoint& mpon = _events[linkon];
                assert(mpon.event());
                TRACE("add link {}:{}s-{}:{}s (key={})",
                      mpon.event()->number, mpon.rdate(),
                      i, _events[it].rdate(), lastkey);
            }
        }
        // OTHER EVENT (ignore)
        else
        {
            if (init)
            {
                TRACE("{}: initial event {} track {}", timeinsecs, i, track);
                _begin = timeinsecs;
                init = false;
            }
            else
            {
                TRACE("{}: event {} track {} ignored", timeinsecs, i, track);
            }
        }
    }
    
    TRACE("{}: EOF of MIDI file ", timeinsecs);
    
    // EOF: set input segment end date and
    if (init)
    {
        WARN("no note in MIDIfile");
        // create empty segment
        _begin = 0;
        _end = 0;
        _len = 0;
    }
    else
    {
        assert (0 <= _begin);
        _end = timeinsecs; // date of last MIDI message
        assert (_begin <= _end);
    }
    
    return 0;
}


size_t InputSegmentMIDI::export_midifile(string output_midifile,
                                         Rational beatperbar)
{
    assert(beatperbar > Rational(0));
    
    DEBUG("MIDI export: read MIDI info from input MIDIfile: {}", _filename);
    
    if (_filename.empty())
    {
        ERROR("name of input MIDIfile missing, cannot export as midifile");
        return 1;
    }
    
    MidiFile input_midifile;
    input_midifile.read(_filename);
    
    if (input_midifile.status() == 0)
    {
        ERROR("Error reading input MIDI file {}", _filename);
        return 1;
    }
    else
    {
        return export_midifile_mono(input_midifile, output_midifile, beatperbar);
    }
}



// TBC
size_t InputSegmentMIDI::export_midifile_mono(MidiFile& input_midifile,
                                              std::string output_midifile,
                                              Rational beatperbar)
{
    //convert delta ticks values for all MidiEvents into absolute tick times
    input_midifile.absoluteTicks();
    input_midifile.joinTracks();
    input_midifile.linkNotePairs();
    
    // delta time ticks units occuring during a bar
    // TBC
    Rational tpb = Rational(input_midifile.getTicksPerQuarterNote()) * beatperbar;
    
    int eventcount = input_midifile.getEventCount(0);
    int track;
    
    // index in event list of input segment
    size_t j = 0;
    unsigned int lastkey = 128; // 0-127 = MIDI key number
    
    INFO("input midifile has {} tracks, hasJoinedTracks={}, Ticks per Quarter Note={}",
         input_midifile.getNumTracks(),
         input_midifile.hasJoinedTracks(),
         input_midifile.getTicksPerQuarterNote());
    
    // all tracks merged into tracks 0
    if (! input_midifile.hasJoinedTracks())
    {
        WARN("MIDIfile has not joined tracks");
        _tracknb = 0;
    }
    
    
    // index in event list of input_midifile
    TRACE("# MIDI events={}", eventcount);
    int i = 0;
    while (i < eventcount)
    {
        TRACE("process MIDI event #{}", i);
        MidiEvent& e = input_midifile[0][i];
        track = e.track;
        
        // ignore messages on other tracks
        if (track != _tracknb)
        {
            WARN("event {} track {} ignored", i, track);
            i++;
            continue;
        }
        
        // new note
        if (e.isNoteOn())
        {
            if ( j >= _events.size() )
            {
                WARN("MIDI note {} missing in input segment", i);
                i++;
                continue;
            }
            
            MusPoint& point = _events[j];
            assert(point.event());
            // MIDI note is skip in input segment
            if (point.event()->number != i)
            {
                WARN("event {} not present in inputseg, skip", i);
                i++;
                continue;
            }
            // MIDI note synchronized with input segment
            // quantize the note on and corresponding note off MIDI events
            else
            {
                assert(point.mdate() != MUSTIME_UNKNOWN);
                assert(point.mduration() != MUSTIME_UNKNOWN);
                TRACE("quantize NOTEON[{}] {}: {}->{}",
                      i, e.getKeyNumber(),
                      e.tick,
                      floor(point.mdate()*tpb));
                e.tick = floor(point.mdate()*tpb);
                MidiEvent* elink = e.getLinkedEvent();
                if (elink == NULL)
                {
                    WARN("unlinked note-on event {}[{}]", _filename, i);
                }
                else
                {
                    TRACE("quantize NOTEOFF[{}] {}: {}->{}",
                          i, elink->getKeyNumber(),
                          elink->tick,
                          floor(point.mdate()*tpb + point.mduration()*tpb));
                    elink->tick =
                    floor(point.mdate()*tpb + point.mduration()*tpb);
                }
                i++;
                j++;
            }
            lastkey = e.getKeyNumber();
            continue;
        }
        // new rest
        else if (e.isNoteOff() && e.getKeyNumber() == lastkey)
        {
            assert (0 <= lastkey);
            assert (lastkey <= 127);
            // may be a rest event in cast of no norest
            if ( j < _events.size() )
            {
                MusPoint& point = _events[j];
                assert(point.event());
                if (point.event()->isRest() && point.event()->number == i)
                {
                    j++;
                }
            }
            i++;
            continue;
        }
        // event ignored
        else
        {
            TRACE("MIDI event {} track {} ignored", i, track);
            i++;
            continue;
        }
    }
    
    input_midifile.splitTracks();
    input_midifile.sortTracks();
    input_midifile.write(output_midifile);
    
    return 0;
}





///////////////////
//    STUBS
//  @todo TBR
///////////////////

// @todo TBR - stub for backward compatibility.
InputSegmentMIDI::InputSegmentMIDI(const std::string filename,
                                   bool mono,
                                   bool norest,
                                   int tracknb):
InputSegment(0, 0),
_filename(filename),
_tracknb(tracknb),
_status(0)
{
    MidiFile file;
    int status = file.read(filename);
    if (status == 0)
    {
        ERROR("could not read MIDI file: {}", filename);
        _filename = "";
        // input segment will be empty
        _status = 1;
    }
    else
    {
        import_midifile_mono(file, tracknb, norest);
    }
    
    assert(0 <= _begin);
    assert(_begin <= _end);
    _len = _end - _begin;
    //    assert(_bars > 0);
    //    _period = _len/_bars;
}


// @todo TBR - stub (dur ignored)
void InputSegmentMIDI::push(MusEvent* e, double rdate, double rdur)
{
    _events.push_back(MusPoint(e, rdate, rdur, true));
}


void InputSegmentMIDI::import_midifile_mono(MidiFile& midifile,
                                            int tracknb,
                                            bool norest)
{
    midifile.absoluteTicks();
    midifile.joinTracks();
    midifile.linkNotePairs();
    
    int eventcount = midifile.getEventCount(0);
    int track;
    // ticks per quarter note
    double tpqn = (double) midifile.getTicksPerQuarterNote();
    int timeinticks = 0;
    double timeinsecs = 0;
    
    vector<std::pair<MusEvent*,double>>
    tmpevents = vector<std::pair<MusEvent*, double>>();
    bool init = true;
    bool firstnote = true;
    unsigned int lastkey = 128; // 0-127 = MIDI key number
    
    INFO("midifile has {} tracks, hasJoinedTracks={}, Ticks per Quarter Note={}",
         midifile.getNumTracks(),
         midifile.hasJoinedTracks(),
         midifile.getTicksPerQuarterNote());
    
    // all tracks merged into tracks 0
    if (! midifile.hasJoinedTracks())
    {
        WARN("MIDIfile has not joined tracks");
        tracknb = 0;
    }
    
    // one pass to
    // set input segment start date and
    // import MIDIfile events to input segment.
    int i;
    for (i = 0; i < eventcount; i++)
    {
        MidiEvent& e = midifile[0][i];
        track = e.track;
        timeinticks = e.tick;
        //timeinsecs = midifile.getTimeInSeconds(0, i);
        //timeinsecs = midifile.getTimeInSeconds(timeinticks);
        //time in quarter notes
        timeinsecs  = ((double) timeinticks) / tpqn;
        
        // ignore messages on other tracks
        if (track != tracknb)
        {
            WARN("{}: event {} track {} ignored", timeinsecs, i, track);
            continue;
        }
        
        // new note
        if (e.isNoteOn())
        {
            MusEvent* event = NULL;
            if (init)
            {
                _begin = timeinsecs;
                init = false;
            }
            if (firstnote && e.getKeyNumber() == 36)
            {
                event = new RestEvent(i);
            }
            else
            {
                event = new NoteEvent(e.getKeyNumber(), e.getVelocity(), i);
            }
            assert(event);
            //tmppoints.emplace_back(event, timeinsecs, 0);
            tmpevents.push_back(std::make_pair(event, timeinsecs));
            TRACE("{}: add note {}, dur={}", timeinsecs, *event);
            
            lastkey = e.getKeyNumber();
            if (firstnote)
                firstnote = false;
        }
        // new rest
        else if (e.isNoteOff() && e.getKeyNumber() == lastkey)
        {
            assert (0 <= lastkey);
            assert (lastkey <= 127);
            assert(init == false);
            
            if (norest)
            {
                // ignore the NOTEOFF:
                // the time between between current note and the next
                // is added to current note.
            }
            else
            {
                // new rest
                // the MIDI nb of rest is NOTE-OFF nb
                RestEvent* event =
                new RestEvent(i);
                //tmppoints.emplace_back(event, timeinsecs, 0);
                tmpevents.push_back(std::make_pair(event, timeinsecs));
                TRACE("{}: add rest {}", timeinsecs, *event);
            }
        }
        // note off ignored
        else if (e.isNoteOff())
        {
            if (init)
            {
                WARN("{}: event {} track {} : unmatched NOTEOFF",
                     timeinsecs, i, track);
                _begin = timeinsecs;
                init = false;
            }
            else
            {
                WARN("{}: event {} track {} : pending NOTEOFF (note {} was cut)",
                     timeinsecs, i, track, lastkey);
            }
        }
        else // ignore other events
        {
            if (init)
            {
                TRACE("{}: initial event {} track {}", timeinsecs, i, track);
                _begin = timeinsecs;
                init = false;
            }
            else
            {
                TRACE("{}: event {} track {} ignored", timeinsecs, i, track);
            }
        }
    }
    
    TRACE("{}: EOF of MIDI file ", timeinsecs);
    
    // EOF: set input segment end date and
    if (init)
    {
        WARN("no note in MIDIfile");
        // create empty segment
        _begin = 0;
        _end = 0;
        _len = 0;
    }
    else
    {
        assert (0 <= _begin);
        _end = timeinsecs; // date of last MIDI message
        assert (_begin <= _end);
    }
    
    // one pass on tmp event list
    // to compute real-duration values of events of input segment.
    vector<std::pair<MusEvent*,double>>::iterator curpoint = tmpevents.begin();
    vector<std::pair<MusEvent*,double>>::iterator nextpoint = curpoint;
    
    while (curpoint != tmpevents.end())
    {
        nextpoint++;
        assert(curpoint->first);
        double rdur = 0;
        
        // compute current real-duration
        if (nextpoint == tmpevents.end())
        {
            assert(curpoint->second <= _end);
            rdur = _end - curpoint->second;
            // last note is unfinished. warn but keep it.
            if (curpoint->first->isNote())
            {
                WARN("last note unfinished, onset={}, last MIDI message at {}",
                     curpoint->second, _end);
            }
        }
        else
        {
            assert(curpoint->second <= nextpoint->second);
            rdur = nextpoint->second - curpoint->second;
        }
        
        // do not import rests with zero real-duration
        if (rdur == 0 && curpoint->first->isRest())
        {
            WARN("{}: zero-duration rest, ignored", curpoint->second);
        }
        // warn but import to this input segment (future grace note?)
        else if (rdur == 0 && curpoint->first->isNote())
        {
            WARN("{}: zero-duration note, MIDI nb={}. should not happen",
                 curpoint->second,
                 curpoint->first->number);
            push(curpoint->first, curpoint->second, rdur);
        }
        // import to this input segment
        else
        {
            assert (rdur > 0); // should not be negative!
            // do not clone event
            push(curpoint->first, curpoint->second, rdur);
        }
        
        curpoint++;
    }
}


// old version : all in 1 pass
//
//void InputSegment::import_midifile_mono_1pass(MidiFile& midifile,
//                                              int tracknb,
//                                              bool norest)
//{
//    midifile.absoluteTicks();
//    midifile.joinTracks();
//    midifile.linkNotePairs();
//
//    const int ST_INIT = 0;
//    const int ST_NOTE = 1;
//    const int ST_REST = 2;
//
//    int state = 0;
//    int eventcount = midifile.getEventCount(0);
//    int track;
//    // ticks per quarter note
//    double tpqn = (double) midifile.getTicksPerQuarterNote();
//    int timeinticks = 0;
//    double timeinsecs = 0;
//    MidiEvent* e;
//
//    double lastonset = 0.0;
//    unsigned int lastpitch = 128; // 0-127 = key
//    unsigned int lastvelocity = 128;
//    int lastnb = 0;
//
//    INFO("midifile has {} tracks, hasJoinedTracks={}, Ticks per Quarter Note={}",
//         midifile.getNumTracks(),
//         midifile.hasJoinedTracks(),
//         midifile.getTicksPerQuarterNote());
//
//    // all tracks merged into tracks 0
//    if (! midifile.hasJoinedTracks())
//    {
//        WARN("MIDIfile has not kjoined tracks");
//        tracknb = 0;
//    }
//
//    int i;
//    for (i = 0; i < eventcount; i++)
//    {
//        e = &(midifile[0][i]);
//        assert (e);
//        track = e->track;
//        timeinticks = e->tick;
//        //timeinsecs = midifile.getTimeInSeconds(0, i);
//        //timeinsecs = midifile.getTimeInSeconds(timeinticks);
//        // time in quarter notes
//        timeinsecs  = ((double) timeinticks) / tpqn;
//
//        TRACE("event {}: track {}", i, track);
//
//        // ignore messages on other tracks
//        if (track != tracknb)
//        {
//            continue;
//        }
//
//        // state INIT
//        else if (state == ST_INIT)
//        {
//            if (e->isNoteOn())
//            {
//                _begin = timeinsecs;
//                lastpitch = e->getKeyNumber();
//                lastvelocity = e->getVelocity();
//                lastonset = timeinsecs;
//                lastnb = i;
//                state = ST_NOTE;
//                continue;
//            }
//            else if (e->isNoteOff())
//            {
//                WARN("event {} track {} : unparsed NOTEOFF", i, track);
//                continue;
//            }
//            else // ignore other events
//            {
//                TRACE("{}: IGNORE[ST_INIT]", timeinsecs);
//                continue;
//            }
//        }
//
//        // state PARSING NOTE
//        else if (state == ST_NOTE)
//        {
//            // new note
//            if ( e->isNoteOn() )
//            {
//                // add last detected note
//                assert (0 <= lastpitch);
//                assert (lastpitch <= 127);
//                assert (0 <= lastvelocity);
//                assert (lastvelocity <= 127);
//                assert (lastonset <= timeinsecs);
//                NoteEvent* event =
//                new NoteEvent(lastpitch, lastvelocity, lastnb);
//                push(event, lastonset, timeinsecs-lastonset);
//                TRACE("{}: ADD[ST_NOTE] {}, dur={}",
//                      lastonset, *event, timeinsecs-lastonset);
//                WARN("overlap, note is cut");
//                lastonset = timeinsecs;
//                // end of current note and beginning of new note
//                lastpitch = e->getKeyNumber();
//                lastvelocity = e->getVelocity();
//                lastnb = i;
//
//                state = ST_NOTE;
//                continue;
//            }
//            // new rest
//            else if ( e->isNoteOff() && (e->getKeyNumber() == lastpitch) )
//            {
//                if (! norest)
//                {
//                    // add last detected note
//                    assert (0 <= lastpitch);
//                    assert (lastpitch <= 127);
//                    assert (0 <= lastvelocity);
//                    assert (lastvelocity <= 127);
//                    assert (lastonset <= timeinsecs);
//                    NoteEvent* event =
//                    new NoteEvent(lastpitch, lastvelocity, lastnb);
//                    push(event, lastonset, timeinsecs-lastonset);
//                    TRACE("{}: ADD[ST_NOTE] {}, dur={}", lastonset, *event, timeinsecs-lastonset);
//                    // and start detecting rest
//                    lastonset = timeinsecs;
//                    lastnb = i;  // the number of rest is the number of NOTEOFF
//                }
//                // if norest, ignore the OFF:
//                // the time between between this note and the next
//                // is added to this note.
//
//                // end of current note and beginning of rest
//                state = ST_REST;
//                continue;
//            }
//            // ignore pendig note off and other messages
//            else
//            {
//                TRACE("{}: IGNORE[ST_NOTE]", timeinsecs);
//                continue;
//            }
//        }
//
//        // state PARSING REST
//        else if (state == ST_REST)
//        {
//            // new note
//            if (e->isNoteOn())
//            {
//                assert (lastonset <= timeinsecs);
//                // the rest is ignored
//                if (norest)
//                {
//                    // add last detected note, with its duration and dur of rest
//                    assert (0 <= lastpitch);
//                    assert (lastpitch <= 127);
//                    assert (0 <= lastvelocity);
//                    assert (lastvelocity <= 127);
//                    assert (lastonset <= timeinsecs);
//                    NoteEvent* event =
//                    new NoteEvent(lastpitch, lastvelocity, lastnb);
//                    push(event, lastonset, timeinsecs-lastonset);
//                    TRACE("{}: ADD[ST_REST] {}, dur={}", lastonset,
//                          *event,
//                          timeinsecs-lastonset);
//                    // end of current note and beginning of new note
//                }
//                // parsed rest is not empty
//                else if (timeinsecs != lastonset)
//                {
//                    // lastnb is the MIDI nb of last NOTE-OFF
//                    RestEvent* event =
//                    new RestEvent(lastnb);
//                    // ignore last onset and velocity
//                    push(event, lastonset, timeinsecs-lastonset);
//                    TRACE("{}: ADD[ST_REST] {} dur={}", lastonset,
//                          *event,
//                          timeinsecs-lastonset);
//                }
//                else
//                {
//                    WARN("empty rest");
//                }
//
//                // start new note detection
//                lastpitch = e->getKeyNumber();
//                lastvelocity = e->getVelocity();
//                lastonset = timeinsecs;
//                lastnb = i;
//                state = ST_NOTE;
//                continue;
//            }
//            // ignore other messages
//            else
//            {
//                TRACE("{}: IGNORE[ST_REST]", timeinsecs);
//                continue;
//            }
//        }
//    }
//
//    //timeinsecs = midifile.getTimeInSeconds(timeinticks);
//    // time in quarter notes
//    timeinsecs  = ((double) timeinticks) / tpqn;
//
//    TRACE("InputSegment: EOF at {} (lastonset={})", timeinsecs, lastonset);
//
//    // EOF
//    if (state == ST_INIT)
//    {
//        WARN("no note in midifile");
//        // create empty segment
//        _begin = 0;
//        _end = 0;
//        _len = 0;
//    }
//    else if (state == ST_NOTE)
//    {
//        // last note is unfinished, ignore.
//        WARN("unfinished note. last onset={}, last message at{}",
//             lastonset,
//             timeinsecs);
//        assert (0 <= _begin);
//        _end = lastonset; // or timeinsecs for date of last message ?
//        assert (_begin <= _end);
//    }
//    // TBC: we cannot finish with a rest
//    else if (state == ST_REST)
//    {
//        assert (0 <= _begin);
//        // parsed rest is not empty
//        if ((timeinsecs != lastonset))
//        {
//            // add note (before last rest)
//            if (norest)
//            {
//                assert (0 <= lastpitch);
//                assert (lastpitch <= 127);
//                assert (0 <= lastvelocity);
//                assert (lastvelocity <= 127);
//                assert (lastonset <= timeinsecs);
//                NoteEvent* event =
//                new NoteEvent(lastpitch, lastvelocity, lastnb);
//                push(event, lastonset, timeinsecs-lastonset);
//                TRACE("{}: ADD[EOF,ST_REST] {}, dur={}", lastonset,
//                      *event,
//                      timeinsecs-lastonset);
//            }
//            // add rest
//            else
//            {
//                RestEvent* event =
//                new RestEvent(lastnb);
//                push(event, lastonset, timeinsecs-lastonset);
//                TRACE("{}: ADD[EOF,ST_REST] {} dur={}", lastonset,
//                      *event,
//                      timeinsecs-lastonset);
//            }
//        }
//        // end of rest or end or previous message
//        // or timeinsecs for date of last message ?
//        _end = timeinsecs;
//        TRACE("InputSegment: end={}", timeinsecs);
//
//        assert (_begin <= _end);
//    }
//    else
//    {
//        ERROR ("unknown state in MIDI file parsing");
//        assert(false);
//    }
//}



// @todo TBR
//MusPoint* InputSegmentMIDI::findMIDI(int nb)
//{
//    for (vector<MusPoint>::iterator i = _events.begin();
//         i != _events.end(); i++)
//    {
//        if (i->event() && i->event()->number == nb)
//        {
//            return &(*i);
//        }
//    }
//    // not found
//    return NULL;
//}




//size_t InputSegmentMIDI::quantize_midievent(MidiEvent& event,
//                                            int i, size_t j,
//                                            Rational tpb)
//{
//    assert(j < this->size());
//
//    MusPoint& point = _events[j];
//    assert(point.event());
//    assert(point.event()->number == i);
//
//    if ((point.mdate() == MUSTIME_UNKNOWN) ||
//        (point.mduration() == MUSTIME_UNKNOWN))
//    {
//        ERROR("unquantized event {}, midifile export failed.", j);
//        return 3;
//    }
//
//    TRACE("quantize event[{}] : {}->{}",
//          i, event.tick, point.mdate()*tpb);
//
//    event.tick = floor(point.mdate()*tpb);
//
//    return 0;
//}


