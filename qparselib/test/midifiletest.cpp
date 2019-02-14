//
//  midifiletest.cpp
//  
//
//  Created by Florent Jacquemard on 19/10/2017.
//
// from
// Filename:      ...sig/doc/examples/all/miditime/miditime.cpp
// Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
// Description:   Displays the absolute tick time and absolute time
//                in seconds for MIDI events in a MIDI file, along with
//                the track information.

#include <stdio.h>

#include "init.hpp"
#include "trace.hpp"
#include "Options.h"
#include "MidiFile.h"
#include <stdlib.h>
#include <iostream>
#include <assert.h>


//using namespace std;

// function declarations:
void   checkOptions        (Options& opts);
void   example             (void);
void   usage               (const char* command);

void   processMidiFile(MidiFile& midifile);
void   importMonoMidiFile(MidiFile& midifile, int tracknb);

// user interface variables:
double starttime = 0.0;    // used with -s option
double endtime   = 0.0;    // used with -e option
int    onsetQ    = 0;      // used with -o option

///////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
    int       status;
    MidiFile  inputfile;
    Options   options(argc, argv);
    
    checkOptions(options);
    
    status = inputfile.read(options.getArg(1));
    if (status == 0)
    {
        cout << "Syntax error in file: " << options.getArg(1) << "\n";
    }
    
    importMonoMidiFile(inputfile, 1);
    return 0;
}


void importMonoMidiFile(MidiFile& midifile, int tracknb)
{
    midifile.absoluteTicks();
    midifile.joinTracks();
    
    const int ST_INIT = 0;
    const int ST_NOTE = 1;
    const int ST_REST = 2;
    const int ST_END = 3;

    int state = 0;
    int eventcount = midifile.getEventCount(0);
    int track;
    int timeinticks;
    double timeinsecs;
    double startDate;
    MidiEvent* e;
    
    double lastOnset = 0.0;
    unsigned int lastPitch; // 0-127 = key
    unsigned int lastVelocity;
    
    for (int i = 0; i < eventcount; i++)
    {
        e = &(midifile[0][i]);
        assert (e);
        track = e->track;
        timeinticks = e->tick;
        //timeinsecs = midifile.getTimeInSeconds(0, i);
        timeinsecs = midifile.getTimeInSeconds(timeinticks);
        
        // ignore messages on other tracks
        if (track != tracknb)
            continue;
        else if (state == ST_INIT)
        {
            if (e->isNoteOn())
            {
                startDate = timeinsecs;
                lastPitch = e->getKeyNumber();
                lastVelocity = e->getVelocity();
                lastOnset = timeinsecs;
                state = ST_NOTE;
                continue;
            }
            else if (e->isNoteOff())
            {
                WARN("event {} track {} : unparsed NOTEOFF", i, track);
                continue;
            }
            else // ignore other events
                continue;
        }
        else if (state == ST_NOTE)
        {
            // new note
            if (e->isNoteOn())
            {
                cout << timeinsecs << " NOTE " << lastPitch << "\n";
                WARN("overlap, note is cut");
                lastPitch = e->getKeyNumber();
                lastVelocity = e->getVelocity();
                lastOnset = timeinsecs;
                continue;
            }
            // end of current note: beginning of rest
            else if (e->isNoteOff() && (e->getKeyNumber() == lastPitch))
            {
                cout << timeinsecs << " NOTE " << lastPitch << "\n";
                // lastPitch and lastVelocity not used in ST_REST
                lastOnset = timeinsecs;
                state = ST_REST;
                continue;
            }
            // ignore pedig ote off and other messages
            else
                continue;
        }
        else if (state == ST_REST)
        {
            // new note
            if (e->isNoteOn())
            {
                lastPitch = e->getKeyNumber();
                lastVelocity = e->getVelocity();
                // empty rest
                if (timeinsecs != lastOnset)
                {
                    cout << timeinsecs << " REST " << "\n";
                    lastOnset = timeinsecs;
                }
                state = ST_NOTE;
                continue;
            }
            // ignore other messages
            else
                continue;
        }
    }
    // EOF
    if (state == ST_INIT)
    {
        WARN("empty midifile");
        // return empty segment
    }
    if (state == ST_NOTE)
    {
        WARN("unfinished note");
        // new segment startDate timeinsecs;
    }
    if (state == ST_REST)
    {
        // new segment startDate timeinsecs;
    }
}


//////////////////////////////
//
// processMidiFile -- extract track and timing information from the MIDI file.
//

void processMidiFile(MidiFile& midifile)
{
    midifile.absoluteTicks();
    midifile.joinTracks();

    int i, j;
    int eventcount = midifile.getEventCount(0);
    int track;
    int timeinticks;
    double timeinsecs;
    MidiEvent *ptr;
    int attack;

    for (i=0; i<eventcount; i++)
    {
        ptr = &(midifile[0][i]);
        assert (ptr);
        track       = ptr->track;
        timeinticks = ptr->tick;
        timeinsecs  = midifile.getTimeInSeconds(0, i);
        attack = ((*ptr)[0] & 0xf0) == 0x90;
        if (onsetQ && !attack)
        {
            continue;
        }
        if (onsetQ && attack)
        {
            if ((*ptr)[2] == 0)
            {
                continue;
            }
        }
        
        cout << timeinticks << "ticks\t";
        cout << timeinsecs << "sec\t";
        cout << "track:" << track << "\t";
        cout << "event:" << i << "\t";
        for (j=0; j < (int)ptr->size(); j++)
        {
            if (j == 0)
            {
                cout << "0x" << hex << (int)(*ptr)[j] << dec << " ";
            }
            else
            {
                cout << (int)(*ptr)[j] << " ";
            }
        }
        cout << endl;
    }
}



//////////////////////////////
//
// checkOptions -- handle command-line options.
//

void checkOptions(Options& opts) {
    
    opts.define("author=b");
    opts.define("version=b");
    opts.define("example=b");
    opts.define("help=b");
    opts.define("o|on|onset=b");
    opts.process();
    
    if (opts.getBoolean("author")) {
        cout << "Written by Craig Stuart Sapp, "
        << "craig@ccrma.stanford.edu, July 2010" << endl;
        exit(0);
    }
    if (opts.getBoolean("version")) {
        cout << "midiextract version 1.0" << endl;
        cout << "compiled: " << __DATE__ << endl;
    }
    if (opts.getBoolean("help")) {
        usage(opts.getCommand().data());
        exit(0);
    }
    if (opts.getBoolean("example")) {
        example();
        exit(0);
    }
    
    onsetQ = opts.getBoolean("onset");
}



//////////////////////////////
//
// example -- gives example calls to the midiexcerpt program.
//

void example(void) {
    cout <<
    "#                                                                        \n"
    << endl;
}



//////////////////////////////
//
// usage -- how to run the midiexcerpt program on the command line.
//

void usage(const char* command) {
    cout <<
    "                                                                         \n"
    << endl;
}



