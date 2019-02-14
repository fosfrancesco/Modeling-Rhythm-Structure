//
//  miditest.cpp
//  qparse
//
//  Created by Clement Poncelet on 03/07/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//

#include <stdio.h>

#include "midifile.hpp"
#include "Options.h"

#include "rtmidi.hpp"

/* data for output a midifile */
MidiFile out_midifile; //used to store the received midi datas
double out_time = -1.;
double QPM = -1.;

/**    **  **  *** **  **
 main
 **    **  **  *** **  **/
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
    
    //dump file
    printMidifile(midifile);
    
    /* [rtmidi] Test2 Midi Output */
    // RtMidiOut constructor
    RtMidiOut* midiout = openRtMidiOut(); //-> to free
    
    // *** *** Send out a series of MIDI messages. *** *** //
    cerr << "We'll play " << midifile.getFilename() << endl;
    playMidifile(midiout, midifile, true);
    
    /** free time **/
    delete midiout;
    
    /* [rtmidi] Test3 Midi Input */
    // we do the reverse (get midi from input port and write a new midifile)
#define NAMEMIDIFILE "/tmp/test.mid"
    
    //prepare midifile
    MidiEvent tempo_set = *new MidiEvent();
    
    tempo_set.setMetaTempo(60.);
    out_midifile[0].append(tempo_set); // a clone is done into the list
    out_midifile.addTrack(); // the received data are stored into track 1
    
    /* Since we listen from on-the-fly input we have a 60BPM tempo
    // tempo in quarter per micro-second [QPM] (50,0000 for 120BPM)
    // [formula: 60,000,000 / BPM] */
    QPM = 60000 / 60.; //We manage here milliseconds
    out_time = 0.;
    
    // RtMidiIn constructor
    RtMidiIn* midiin = openRtMidiIn(); //-> to free
        
    cerr << "midi received" << endl;
    printMidifile(out_midifile);
    out_midifile.write(NAMEMIDIFILE); //create .mid file
    
    
    //this test should play the same midi events written in NAMEMIDIFILE
    MidiFile midifile2;
    midifile2.read(NAMEMIDIFILE);
    //dump file
    printMidifile(midifile2);
    
    // RtMidiOut constructor
    midiout = openRtMidiOut(); //-> to free
    
    // *** *** Send out a series of MIDI messages. *** *** //
    cerr << "We'll play " << midifile2.getFilename() << endl;
    playMidifile(midiout, midifile2, true);
    
    /** free time **/
    delete midiin;
    out_midifile.clear(); //(global is bad)
    
    delete midiout;
    midifile2.clear();
    /** free time **/
    
    return EXIT_SUCCESS;
}
