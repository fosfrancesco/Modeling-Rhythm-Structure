//
//  mididump.cpp
//  qparse
//
// example from Craig Sapp for using his MIDIfile lib
// see https://github.com/craigsapp/midifile
//
// The following program lists all MidiEvents in an input MIDI file.
// The program iterates over each track, printing a list of MIDI events in the track.
// For each event, the tick timestamp for the performance time of the MIDI message is given, f
// followed by the message itself as a list of hex bytes.
//

#include <stdio.h>

#include "MidiFile.h"
#include "Options.h"
#include <iostream>
#include <iomanip>


#include "Event.hpp"


using namespace std;

int testEvent()
{
    for (unsigned int i = 0; i < 128; i++)
    {
        cout << i;
        Pitch p = Pitch(i*100+45, Pitch::MIDICENT);
        cout << " midi=" << p.midi();
        cout << " name=" << p.name << p.octave << "+" << p.alteration << "\n";
    }
    
    return 0;
}


int main(int argc, char** argv)
{
    Options options;
    options.process(argc, argv);
    MidiFile midifile;

//    return testEvent();
    

    if (options.getArgCount() > 0)
    {
        midifile.read(options.getArg(1));
    }
    else
    {
        midifile.read(cin);
    }
    
    int tracks = midifile.getTrackCount();
    cout << "Ticks per quarternote:" << midifile.getTicksPerQuarterNote() << endl;
    if (tracks > 1)
    {
        cout << "TRACKS: " << tracks << endl;
    }
    for (int track=0; track < tracks; track++)
    {
        if (tracks > 1)
        {
            cout << "\nTrack " << track << endl;
        }
        for (int event=0; event < midifile[track].size(); event++)
        {
            cout << dec << midifile[track][event].tick;
            cout << '\t' << hex;
            for (int i=0; i<midifile[track][event].size(); i++)
            {
                cout << (int)midifile[track][event][i] << ' ';
            }
            cout << endl;
        }
    }
    
    return 0;
}
