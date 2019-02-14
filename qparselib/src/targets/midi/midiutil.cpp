//
//  midiutil.cpp
//  midi
//
//  Created by Florent Jacquemard on 11/11/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>

#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>     // handling commandline options
#include <assert.h>

#include "init.hpp"
#include "QPconfig.h" // check compile flags
#include "trace.hpp"
#include "Rational.hpp"
#include "InputSegment.hpp"
#include "InputSegmentMIDI.hpp"
#include "InputSegmentSerial.hpp"


// ==========================================================================
// Option handling with getop_long (stdlib)

static int verbosity = 0;

// input file option is present
static bool f_input = false;
// midifile name for reading
static string _input_file;

// ignore rests in input midifile
static int f_norest = false;

// output file option is present
static bool f_output = false;
// text file name for writing
static string _output_file;

// start date option is present
static int f_start = false;
// argument of start date option
static double d_start;

// end date option is present
static int f_end = false;
// argument of end date option
static double d_end;

// dump midifile flag
static bool f_print = false;


static struct option long_options[] =
{
    // Options with an abbreviation
    // we dont use flags here, we set them after calling getopt instead
    
    /*  0 */ { "help",        no_argument,       NULL, 'h' },
    /*  1 */ { "version",     no_argument,       NULL, 'V' },
    
    /*  2 */ { "verbosity",   required_argument, NULL, 'v' },
    /*  3 */ { "debug",       no_argument,       NULL, 'd' },
    /*  4 */ { "trace",       no_argument,       NULL, 't' },
    /*  5 */ { "quiet",       no_argument,       NULL, 'q' },

    /*  6 */ { "print",       no_argument,       NULL, 'p' },

    /*  7 */ { "input",       required_argument, NULL, 'i' },
    /*  8 */ { "output",      required_argument, NULL, 'o' },

    // Options with no abbreviation
    /*  9 */ { "norest",      no_argument,       &f_norest, true },
    /* 10 */ { "start",       required_argument, &f_start, true },
    /* 11 */ { "end",         required_argument, &f_end, true },

    // last
    { NULL, 0, NULL, 0 }
};


#define check_index_is(NAME) \
assert(0 == strcmp(long_options[option_index].name, NAME))

static void setOptionArgs(int option_index)
{
    TRACE("setOptionArgs: {}", option_index);
    
    switch(option_index)
    {
        case 9:
            check_index_is("norest");
            assert (f_norest);
            TRACE("setOptionArgs {}", long_options[option_index].name);
            break;

        case 10:
            check_index_is("start");
            assert (f_start);
            d_start = strtod(optarg, NULL);
            TRACE("setOptionArgs {}: {}", long_options[option_index].name, d_start);
            break;

        case 11:
            check_index_is("end");
            assert (f_end);
            d_end = strtod(optarg, NULL);
            TRACE("setOptionArgs {}: {}", long_options[option_index].name, d_end);
            break;

        default:
            ; // ignore
    }
}

bool checkOptions()
{
    bool error = false;
    
    if (! f_input)
    {
        ERROR("missing midifile in input");
        error = true;
    }
    
    if (f_start && f_end)
    {
        if (d_end <= d_start)
        {
            ERROR("start date must be before end date");
            error = true;
        }
    }
    
    return error;
}


InputSegment* read_segment(const string filename, bool norest)
{
    InputSegment* seg;
    
    assert(filename.size() > 0);
    INFO("==== Read input segment from {} ", filename);
    if (norest) { INFO("ignore rests"); }
    
    seg = new InputSegmentMIDI(filename, true, f_norest, 1);
    
    INFO("segment: size = {}", seg->size());
    INFO("segment :");
    seg->print(cout);
    
    return seg;
}


void print(string filename, std::ostream& o)
{
    MidiFile midifile;
    midifile.read(filename);
    
    int tracks = midifile.getTrackCount();
    o << "ticks per quarter note: " << midifile.getTicksPerQuarterNote() << endl;
    if (tracks > 1)
    {
        o << "nb racks: " << tracks << endl;
    }
    for (int track=0; track < tracks; track++)
    {
        if (tracks > 1)
        {
            o << "\nTrack " << track << endl;
        }
        for (int event=0; event < midifile[track].size(); event++)
        {
            o << dec << midifile[track][event].tick;
            o << '\t' << hex;
            for (int i=0; i<midifile[track][event].size(); i++)
            {
                o << (int)midifile[track][event][i] << ' ';
            }
            o << endl;
        }
    }
}




void usage()
{
    INFO("Usage: midi [options...]");
    INFO("  -help -h");
    INFO("  -version -V");
    INFO("  -verbosity level -v level : level=0..6  (default is 0)");
    INFO("  -trace -t : same as -verbosity 6");
    INFO("  -debug -d : same as -verbosity 5");
    INFO("  -quiet -q : same as -verbosity 0");
    INFO("  -input filename -i filename  : input midifile");
    INFO("  -output filename -o filename : output text file");
    INFO("  -print   : dump midifile content");
    INFO("  -norest  : ignore rests in midifile");
    INFO("  -start D : set start date for input segment");
    INFO("  -end D   : set end date for input segment");
}

void version()
{
    INFO("midiutils: version 0.1");
}









int main(int argc, char** argv)
{
    // set for tracing the parsing of options
    //
    // log levels:
    // trace = 0,
    // debug = 1,
    // info = 2,
    // warn = 3,
    // err = 4,
    // critical = 5,
    // off = 6
    spd::set_level(spd::level::trace);
    
    // character of option
    int c;
    
    while(1)
    {
        /* getopt_long stores the option index here. */
        int option_index = 0;
        
        c = getopt_long_only(argc, argv, "hVv:dtpi:o:",
                             long_options, &option_index);
        
        
        // end of the options
        if (c == -1)
            break;
        
        switch (c)
        {
                // long option with flag pointer. there are none.
            case 0:
		setOptionArgs(option_index);
                break;
                
            case 'h':
                usage();
                exit(0);
                
            case 'V':
                version();
                exit(0);
                
            case 'v':
                if (optarg)
                    //verbosity = strtol(optarg, NULL, 10);
                    verbosity = atoi(optarg);
                else
                    verbosity = 4;
                TRACE("Option {}: {}", long_options[option_index].name,
                      verbosity);
                break;
                
            case 'd':
                verbosity = 5;
                TRACE("Option {}: verbosity={}",
                      long_options[option_index].name,
                      verbosity);
                break;
                
            case 't':
                verbosity = 6;
                TRACE("Option {}: verbosity={}",
                      long_options[option_index].name,
                      verbosity);
                break;

            case 'q':
                verbosity = 0;
                TRACE("Option {}: verbosity={}",
                      long_options[option_index].name,
                      verbosity);
                break;

            case 'i':
                f_input = true;
                _input_file = std::string(optarg);
                TRACE("Option {}: {}", long_options[option_index].name,
                     _input_file);
                break;

            case 'o':
                f_output = true;
                _output_file = std::string(optarg);
                TRACE("Option {}: {}", long_options[option_index].name,
                      _output_file);
                break;
                
            case 'p':
                f_print = true;
                TRACE("Option {}", long_options[option_index].name);
                break;
                
                //  missing option argument. Error already signaled by getopt
            case ':':
                ERROR("Missing option argument");
                break;
                
                // unknown or ambiguous option  Error already signaled by getopt
            case '?':
                WARN("unkown or ambiguous option argument");
                break;
                
                // Do nothing for the options that are not flag-managed but without arguments
            default:
                break;
        }
    }
    
    if (checkOptions())
    {
        ERROR("option error. exit");
        std::cerr << "option error. exit";
        return(1);
    }

    INFO("verbosity level = {}", verbosity);
    switch (verbosity)
    {
        case 0: spd::set_level(spd::level::off); break;
        case 1: spd::set_level(spd::level::critical); break;
        case 2: spd::set_level(spd::level::err); break;
        case 3: spd::set_level(spd::level::warn); break;
        case 4: spd::set_level(spd::level::info); break;
        case 5: spd::set_level(spd::level::debug); break;
        case 6: spd::set_level(spd::level::trace); break;
        default: spd::set_level(spd::level::trace);
    }

    if (f_input) { INFO("input file: {}", _input_file); }

    TRACE("output file: {}", _output_file);

    
    
    // read input segment
    InputSegment* seg = read_segment(_input_file, f_norest);
    assert(seg);

    if (seg->size() == 0)
    {
        ERROR("empty segment, stopping");
        exit(2);
    }

    if (f_start || f_end)
    {
        double begin = f_start?d_start:seg->begin();
        double end = f_end?d_end:seg->end();
        INFO("reset input segment start to {}, end to {}", begin, end);

        InputSegment* save = seg;
        // copy and resize
        seg = new InputSegment((*save), begin, end);
        //delete save;
    }
    

    if (f_print)
    {
        print(_input_file, cout);
    }
    
    if (f_output)
    {
        INFO("saving to {}", _output_file);
        seg->save(_output_file);
    }
    
    assert(seg);
    delete(seg);
    
    
    exit(0);
}

    
