//
//  main.cpp
//  squant
//
//  Created by Florent Jacquemard on 10/12/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
// command line for quantization of input segment according to schema.
// Different scenarios defined in Parser classes
// by combination of the following options
// - inputless or with input segment
// - 1-best (Viterbi algo) or k-best (enumeration algo)
// - construction of runs for combining several bars


// parsing/enumeration scenari
// each scenario is defined in a Parser

// workflow inputless, 1 best :
// enumeration of language of a WTA
#define QUANT_INPUTLESS_1BEST        1

// workflow inputless, 1 best :
// enumeration of language of a WTA
#define QUANT_INPUTLESS_KBEST        2

// input segment of musical duration 1 bar
// first prototype with construction of a ComboWTA
#define QUANT_1BAR_COMBO             3

// input segment of musical duration 1 bar
// second prototype with construction of a PreWTA
#define QUANT_1BAR_PRE               4

// input segment of musical duration 1 bar, 1 best
// construction of a table indexed by SIP pointers
// (state, interval, pre/post values)
#define QUANT_1BAR_1BESTSIP          5

// input segment of musical duration 1 bar, K best
// construction of a table indexed by SIP pointers
// (state, interval, pre/post values)
#define QUANT_1BAR_KBESTSKIP         6

// input segment of musical duration several bars, 1 best
// construction of a table indexed by SIP pointers
// (state, interval, pre/post values)
// runs for sequences of bars constructed as binary trees
#define QUANT_MULTIBAR_1BEST_SIPBU   7

// input segment of musical duration several bars, 1 best
// construction of a table indexed by SIP pointers
// (state, interval, pre/post values)
// runs for sequences of bars constructed as lists (flat)
#define QUANT_MULTIBAR_1BEST_SIPFLAT 8


#define QUANT_SCENARIO QUANT_MULTIBAR_1BEST_SIPBU



#include <stdio.h>
#include <iostream>
#include <time.h>
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

// switch options for WTA weight
#include "FloatWeight.hpp"
#include "TropicalWeight.hpp"
#include "ViterbiWeight.hpp"

#include "WTA.hpp"
#include "WTAFile.hpp"
//#include "DurationList.hpp"

#include "InputSegment.hpp"
#include "InputSegmentSerial.hpp"
#include "InputSegmentMIDI.hpp"

// definition of parser and demo function
#if QUANT_SCENARIO == QUANT_INPUTLESS_1BEST
#include "ParserInputless1best.hpp"
#elif QUANT_SCENARIO == QUANT_INPUTLESS_KBEST
#include "ParserInputlesskbest.hpp"
#elif QUANT_SCENARIO == QUANT_1BAR_COMBO
#include "ParserCombo.hpp"
#elif QUANT_SCENARIO == QUANT_1BAR_PRE
#include "ParserPre.hpp"
#elif QUANT_SCENARIO == QUANT_1BAR_1BESTSIP
#include "Parser1bar1bestSIP.hpp"
#elif QUANT_SCENARIO == QUANT_1BAR_KBESTSKIP
#include "Parser1barKbestSKIP.hpp"
#elif QUANT_SCENARIO == QUANT_MULTIBAR_1BEST_SIPBU
#include "ParserMultibar1bestSIPBU.hpp"
#elif QUANT_SCENARIO == QUANT_MULTIBAR_1BEST_SIPFLAT
#include "ParserMultibar1bestSIPflat.hpp"
#else
#error ERROR squant.zpp : invalid QUANT_SCENARIO
#endif

// output
#include "RT.hpp"



// ==========================================================================
// Option handling with getop_long (stdlib)

static int verbosity = 0;

// number of K-best to compute   //was #define TEST_K 1
static size_t _k = 1;

// file name for reading input segment
static string _input_file;
// input file is text or midi
static bool f_input = false;
// input file is midi
static bool f_midi = false;
// input segment
static InputSegment* _iseg;

// ignore rests in input midi file
static int f_norest = false;

// start date option is present
static int f_start = false;
// argument of start date option
static double d_start;

// end date option is present
static int f_end = false;
// argument of end date option
static double d_end;

// output file option is present
static bool f_output = false;
// text file name for writing
static string _output_file;

// config file (aka ini) option is present
static bool f_config = false;
// text file name for writing
static string _config_file;

// file name for reading schema
static string _schema_file;
// schema file is present
static bool f_schema = false;
// input schema
static WTAFile* _schema;

// flag: clean WTA
static int f_clean = false;

// flag: number of bars specified (otherwise default = 1)
static int f_bars = false;
// number of bars in input
static size_t _bars = 1;

// flag: bar real-time dur specified (otherwise default = 1)
static int f_barsec = false;
//  real-time duration of bar
static double _barsec = 1;

// flag: bar musical-time dur specified (otherwise default = 1)
static int f_barbeat = false;
//  musical-time duration of bar
static size_t _barbeat = 1;

// flag: time signature specified
static int f_timesig = false;
// time signature
static ScoreModel::ScoreMeter _ts(4,4);
//static int _ts_num;
//static int _ts_den;

// flag: pre value
static int f_pre = false;
// argument of pre option
static pre_t _pre = 0;

// flag: post value
static int f_post = false;
// argument of post option
static pre_t _post = 0;

// forced weight type for WTA (given in command line options)
static int f_penalty = false;
static int f_count = false;
static int f_proba = false;
static WeightDom _weight_type = WeightDom::UNDEF;

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
    
    /*  6 */ { "kbest",       required_argument, NULL, 'k' },
    
    /*  7 */ { "input",       required_argument, NULL, 'i' },
    /*  8 */ { "midi",        required_argument, NULL, 'm' },
    /*  9 */ { "schema",      required_argument, NULL, 'a' },
    /* 10 */ { "output",      required_argument, NULL, 'o' },
    /* 11 */ { "config",      required_argument, NULL, 'c' },

    // Options with no abbreviation
    
    /* 12 */ { "penalty",     no_argument,       &f_penalty, true},
    /* 13 */ { "counting",    no_argument,       &f_count,   true },
    /* 14 */ { "proba",       no_argument,       &f_proba,   true },
    /* 15 */ { "probability", no_argument,       &f_proba,   true },
    /* 16 */ { "stochastic",  no_argument,       &f_proba,   true },
    /* 17 */ { "clean",       no_argument,       &f_clean,   true },
    /* 18 */ { "norest",      no_argument,       &f_norest,  true },
    /* 19 */ { "start",       required_argument, &f_start,   true },
    /* 20 */ { "end",         required_argument, &f_end,     true },
    /* 21 */ { "bars",        required_argument, &f_bars,    true },
    /* 22 */ { "pre",         required_argument, &f_pre,     true },
    /* 23 */ { "post",        required_argument, &f_post,    true },
    /* 24 */ { "barsec",      required_argument, &f_barsec,  true },
    /* 25 */ { "barbeat",     required_argument, &f_barbeat, true },
    /* 26 */ { "ts",          required_argument, &f_timesig, true },
    /* last */ { NULL, 0, NULL, 0 }
};


// ==========================================================================
// Definition of demo

//#include "Inputless1best.hpp"
//#include "InputlessKbest.hpp"
//#include "1bar1bestSIP.hpp"
//#include "1barKbestSIP.hpp"
//#include "Multibar1bestSIPBU.hpp"
//#include "MEIutil.hpp"
//#include "Multibar1bestSIPflat.hpp"

// ==========================================================================
// Option handling with getop_long (stdlib)

#define check_index_is(NAME) \
assert(0 == strcmp(long_options[option_index].name, NAME))

static void setOptionArgs(int option_index)
{
    TRACE("setOptionArgs: {}", option_index);
    string _arg;
    size_t sepindex;
    
    // long options without abbreviation and with argument
    switch(option_index)
    {
        case 19:
            check_index_is("start");
            assert (f_start);
            d_start = strtod(optarg, NULL);
            TRACE("setOptionArgs {}: {}", long_options[option_index].name, d_start);
            break;
            
        case 20:
            check_index_is("end");
            assert (f_end);
            d_end = strtod(optarg, NULL);
            TRACE("setOptionArgs {}: {}", long_options[option_index].name, d_end);
            break;
            
        case 21:
            check_index_is("bars");
            assert (f_bars);
            _bars = strtol(optarg, NULL, 10);
            TRACE("setOptionArgs {}: {}",
                  long_options[option_index].name, _bars);
            break;
            
        case 22:
            check_index_is("pre");
            assert (f_pre);
            _pre = strtol(optarg, NULL, 10);
            TRACE("setOptionArgs {}: {}", long_options[option_index].name, _pre);
            break;
            
        case 23:
            check_index_is("post");
            assert (f_post);
            _post = strtol(optarg, NULL, 10);
            TRACE("setOptionArgs {}: {}",
                  long_options[option_index].name,
                  _post);
            break;
            
        case 24:
            check_index_is("barsec");
            assert (f_barsec);
            _barsec = strtod(optarg, NULL);
            TRACE("setOptionArgs {}: {}",
                  long_options[option_index].name, _barsec);
            break;

        case 25:
            check_index_is("barbeat");
            assert (f_barbeat);
            _barbeat = strtol(optarg, NULL, 10);
            TRACE("setOptionArgs {}: {}",
                  long_options[option_index].name, _barsec);
            break;
            
        case 26:
            check_index_is("ts");
            assert (f_timesig);
            _arg = string(optarg);
            sepindex = _arg.find_last_of("/");
            // prefix
            _ts = ScoreModel::ScoreMeter(  // prefix, suffix
                std::stoi(_arg.substr(0, sepindex)),
                std::stoi(_arg.substr(sepindex + 1, _arg.size() - sepindex)));
            TRACE("setOptionArgs {}: {}",
                  long_options[option_index].name, optarg);
            break;
            
        default:
            ; // ignore
    }
}

bool checkOptions()
{
    bool error = false;
    
    if (f_penalty || f_count || f_proba)
    {
        if ((f_penalty && f_count) || ((f_penalty || f_count) == f_proba))
        {
            ERROR("options conflict: more than one schema file type");
            error = true;
        }
    }
    else
    {
        TRACE("no schema file type in option");
    }
    
    // set forced weight type value
    if (f_penalty)
    {
        _weight_type = WeightDom::PENALTY;
    }
    else if (f_count)
    {
        _weight_type = WeightDom::COUNTING;
    }
    else if (f_proba)
    {
        _weight_type = WeightDom::STOCHASTIC;
    }
    else
    {
        _weight_type = WeightDom::UNDEF;
    }

    if (f_input == f_midi)
    {
        TRACE("f_input={}, f_midi={}", f_input, f_midi);
        if (f_midi)
        {
            ERROR("options conflict: 2 input files");
            error = true;
        }
        else
        {
            ERROR("missing option: input file");
            error = true;
        }
    }
    
    if (! f_schema)
    {
        ERROR("missing option: schema file");
        error = true;
    }
    
    if (f_start && f_end)
    {
        if (d_end < d_start)
        {
            ERROR("start date must be before end date");
            error = true;
        }
        if (! f_input)
        {
            ERROR("set start or end date without input");
            error = true;
        }
    }
    
    if (f_bars && f_barsec)
    {
        ERROR("options bars and barsec are mutually exclusive");
        error = true;
    }
    
    return error;
}


void usage()
{
    std::cout << "Usage: squant [options...]";
    std::cout << std::endl;
    std::cout << "  -help -h";
    std::cout << std::endl;
    std::cout << "  -version -V";
    std::cout << std::endl;
    std::cout << "  -verbosity level -v level : level=0..6  (default is 0)";
    std::cout << std::endl;
    std::cout << "             levels: 0=off, 1=critical, 2=err, 3=warn";
    std::cout << std::endl;
    std::cout << "                     4=info, 5=debug, 6=trace";
    std::cout << std::endl;
    std::cout << "  -trace -t : same as -verbosity 6";
    std::cout << std::endl;
    std::cout << "  -debug -d : same as -verbosity 5";
    std::cout << std::endl;
    std::cout << "  -quiet -q : same as -verbosity 0";
    std::cout << std::endl;
    std::cout << "  --kbest N -k N : compute the N best trees";
    std::cout << std::endl;
    std::cout << "  -input filename -i filename : \
    filename is either a text file or midifile \
    (characterized by extension .mid or .midi)";
    std::cout << std::endl;
    std::cout << "  -midi midifilename -m midifilename : filename is a midi file";
    std::cout << std::endl;
    std::cout << "  -norest  : ignore rests in input midifile";
    std::cout << std::endl;
    std::cout << "  -start D : set start date for input segment";
    std::cout << std::endl;
    std::cout << "  -end D   : set end date for input segment";
    std::cout << std::endl;
    std::cout << "  -schema filename -a filename : filename contains \
    the text description of a WTA";
    std::cout << std::endl;
    std::cout << "  -clean  : clean input schema";
    std::cout << std::endl;
    std::cout << "  -output filename -o filename : output file \
    .mei for a MEI score output,\
    .mid for a MIDI file";
    std::cout << std::endl;
    std::cout << "  -config file.ini -c file.ini : configuration file";
    std::cout << std::endl;
    std::cout << "schema weight models (mutually exclusive options):";
    std::cout << std::endl;
    std::cout << "  -counting";
    std::cout << std::endl;
    std::cout << "  -penalty";
    std::cout << std::endl;
    std::cout << "  -probability -stochastic (equivalent)";
    std::cout << std::endl;
    std::cout << "  -pre I : number of notes added (as grace notes)\
         at the begining of the segment to quantize,\
         e.g. originating from another precedent segment";
    std::cout << std::endl;
    std::cout << "  -post I : number of notes that will be aligned to right bound\
    in quantization solutions";
    std::cout << std::endl;
    std::cout << "   -bar I : number of bars in the input segment (default 1)";
    std::cout << std::endl;
    std::cout << "   -barsec D : assumed real-time duration of 1 bar, in seconds (default 1)";
    std::cout << std::endl;
    std::cout << "   -barbeat I : musical-ime duration of 1 bar, in beats (default 1)";
    std::cout << std::endl;
    std::cout << "   -ts \"n/d\" : time signature (default 4/4)";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "-input and -midi are mutualy exclusive";
    std::cout << std::endl;
    std::cout << "-bar and -barsec are mutualy exclusive";
    std::cout << std::endl;
    std::cout << "-probability -stochastic are equivalent";
    std::cout << std::endl;
    std::cout << "-counting -penalty -probability -stochastic are mutually exclusive";
    std::cout << std::endl;
    std::cout << "-trace has priority over -verbosity";
    std::cout << std::endl;
}

void version()
{
    INFO("qparse: debug version");
}




int main(int argc, char** argv)
{
    //clock_t time_start;     // chrono
    //clock_t time_end;
    
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
    spd::set_level(spd::level::debug);
    
    // index of the current option
    //int index = 0;
    
    
    //
    // read command line options
    //
    
    // character of option
    int c;
    
    while(1)
    {
        /* getopt_long stores the option index here. */
        int option_index = 0;
        
        c = getopt_long_only(argc, argv, "hVv:dtk:i:m:a:",
                             long_options, &option_index);
        
        
        // end of the options
        if (c == -1)
            break;
        
        switch (c)
        {
                // long option with flag pointer
            case 0:
                setOptionArgs(option_index);
                break;
                
            case 'h':
                usage();
                return(0);
                
            case 'V':
                version();
                return(0);
                
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
                
            case 'k':
                //k = strtoul(optarg, NULL, 10);
                _k = atoi(optarg);
                TRACE("Option {} : {}",
                      long_options[option_index].name, _k);
                if (_k == 0)
                {
                    ERROR("option error: k={} must be > 0", _k);
                    return(1);
                }
                break;
                
            case 'i':
                f_input = true;
                _input_file = std::string(optarg);
                TRACE("Option {}: {}",
                      long_options[option_index].name, _input_file);
                break;
                
            case 'o':
                f_output = true;
                _output_file = std::string(optarg);
                TRACE("Option {}: {}", long_options[option_index].name,
                      _output_file);
                break;

            case 'c':
                f_config = true;
                _config_file = std::string(optarg);
                TRACE("Option {}: {}", long_options[option_index].name,
                      _config_file);
                break;

            case 'm':
                f_midi = true;
                _input_file = std::string(optarg);
                TRACE("Option {}: {}",
                      long_options[option_index].name, _input_file);
                break;
                
            case 'a':
                f_schema = true;
                _schema_file = std::string(optarg);
                TRACE("Option {}: {}",
                      long_options[option_index].name, _schema_file);
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
    INFO("schema file: {} ({} weight model option)",
         _schema_file,
         (f_count?"counting":(f_proba?"stochastic":(f_penalty?"penalty":"???"))));
    
    if (f_output) { INFO("output file: {}", _output_file); }
    if (f_config) { INFO("config file: {}", _config_file); }
    
    // initialize running environment from INI file
    if (f_config)
    {
        INFO("loading config. parameters from {}", _config_file);
        int res = read_config(_config_file);
        if (res == 0)
        {
            INFO("reading config from {} OK", _config_file);
        }
        else if (res == -1)
        {
            ERROR("error opening config file {}", _config_file);
            return 1;
        }
        else
        {
            ERROR("parse error in config file {} line {}", _config_file, res);
            return 2;
        }
    }

    
    // adjust options after reading config file
    // (possible redundancies between config.ini file and options)
    if ((! f_norest) && OPT_NOREST)
    {
        f_norest = true;
    }

    // input schema (global)
    // read from file
    _schema = new WTAFile(_schema_file, _weight_type);

    if (_schema == NULL || _schema->empty())
    {
        ERROR("error reading schema {}, abort", _schema_file);
        return(2);
    }
    
    
    if (f_timesig)
    {
        INFO("Time Signature (from command line option) {}/{}",
             _ts.getCount(), _ts.getUnit());
    }
    else
    {
        if (WTAFile::readTimesignature(_schema_file, _ts))
        {
            INFO("Time Signature (from file {}) {}/{}",
                 _schema_file, _ts.getCount(), _ts.getUnit());
        }
        else
        {
            INFO("could not find time signature in {}, default to 4/4",
                 _schema_file);
        }
    }
    
    
    if (CST_WEIGHT_TYPE == WeightDom::UNDEF)
    {
        ERROR("no weight type found for {}, abort", _schema_file);
        return(3);
    }
    
    switch(CST_WEIGHT_TYPE)
    {
        case WeightDom::UNDEF:
            ERROR("weight type undef after importing grammar. abort.");
            return(4); break;
        case WeightDom::PENALTY:
            INFO("weight model: penalty (alpha = {})", CST_ALPHA);
            break;
        case WeightDom::STOCHASTIC:
            INFO("weight type: stochastic (sigma2 = {})", CST_SIGMA2);
            break;
        case WeightDom::COUNTING:
            ERROR("weight type counting not supported for quantization. abort.");
            return(4);
    }

    // TBC remove 0 weighted transitions
    if (f_clean)
    {
        INFO("Cleaning schema");
        _schema->clean();
    }
    
    // TBC normalization flag ?

    if (! _schema->isClean())
    {
        ERROR("schema {} is not clean, abort.", _schema_file);
        set<state_t> empty = _schema->emptyStates();
        for (set<state_t>::iterator i = empty.begin(); i != empty.end(); i++)
        {
            ERROR("empty state : {}", *i);
        }
        
        return 2;    
    }
    
    INFO("WTAFile (after casting and cleaning):");
    if (verbosity >= 4) // info
    {
        std::cout << *(_schema);
        _schema->print(cout);
    }
    
    
    // input segment (global)
    _iseg = NULL;

    // the input file is parsed as a midifile
    // if one of the following condition holds:
    // - the flag f_midi is set
    // - the file has suffix .mid or .ID or .midi or .MIDI
    // otherwise is it parsed as a plain text file
    // describing monophonic segment.
    if (f_input || f_midi)
    {
        size_t dotindex = _input_file.find_last_of(".");
        //string prefix = filename.substr(0, dotindex);
        string suffix = _input_file.substr(dotindex + 1);
        std::transform(suffix.begin(), suffix.end(), suffix.begin(), ::toupper);

        if (f_midi || (suffix == "MID") || (suffix == "MIDI"))
        {
            // TBC (uses stubs)
            _iseg = new InputSegmentMIDI(_input_file,
                                         true,
                                         f_norest,
                                         1);  // track nb
        }
        else
        {
            _iseg = new InputSegmentSerial(_input_file, true);
        }
    }
    
    if (f_start || f_end)
    {
        assert(_iseg);
        double begin = f_start?d_start:_iseg->rbegin();
        double end = f_end?d_end:_iseg->rend();
        INFO("reset input segment start to {}, end to {}", begin, end);
        InputSegment* save = _iseg;
        // copy and resize
        _iseg = new InputSegment((*save), begin, end);
        //delete save;
    }
    
    if (_iseg && _iseg->size() == 0)
    {
        ERROR("empty segment, stopping");
        return(2);
    }
    else if (_iseg && verbosity >= 4) // info
    {
        INFO("segment : {} events", _iseg->size());
        _iseg->print(std::cout);
    }

    // demo(_schema, _schema_file, _iseg, _input_file, true, k);
    //demo();

    // ParserXXX* parser = new ParserXXX(static variables);
    // parser->demo(other static vars)
    // delete parser; // do not delete yes schema and input segment
   
#if QUANT_SCENARIO == QUANT_INPUTLESS_1BEST
    // flag : ordering for enumeration
    // @todo pass as user option.
    ParserInputless1best* parser = new ParserInputless1best(_schema, true);
    parser->demo(_schema_file);
    delete parser; // do not delete yes schema and input segment

#elif QUANT_SCENARIO == QUANT_INPUTLESS_KBEST
    // flag : ordering for enumeration
    // @todo pass as user option.
    ParserInputlessKbest* parser = new ParserInputlessKbest(_schema, true);
    parser->demo(_schema_file, _k);
    delete parser;

#elif QUANT_SCENARIO == QUANT_1BAR_COMBO
    // @todo for memo
    ERROR("missing");

#elif QUANT_SCENARIO == QUANT_1BAR_PRE
    // @todo for memo
    ERROR("missing");

#elif QUANT_SCENARIO == QUANT_1BAR_1BESTSIP
    Parser1bar1bestSIP* parser = new Parser1bar1bestSIP(_schema, _iseg, true);
    parser->demo(_schema_file, _input_file, _pre, _post);
    delete parser;
    
#elif QUANT_SCENARIO == QUANT_1BAR_KBESTSKIP
    Parser1barKbestSKIP* parser = new Parser1barKbestSKIP(_schema,
                                                          _iseg,
                                                          true);
    parser->demo(_schema_file, _input_file, _pre, _post, _k);
    delete parser;

#elif QUANT_SCENARIO == QUANT_MULTIBAR_1BEST_SIPBU
    INFO("compute best tree sequence for {} and input in {}",
         _schema_file, _input_file);
    // adjust options
    // (options bars and barsec are mutualy exclusive)
    assert(f_barsec || f_bars);
    if (f_bars)
    {
        assert(_iseg);
        assert(_bars > 0);
        _barsec = _iseg->rduration()/_bars;
    }
    else
    {
        assert(f_barsec);
        assert(_iseg);
        assert(_barsec > 0);
        _bars = std::ceil(_iseg->rduration() / _barsec);
    }
    if (! f_barbeat)
    {
        // @todo adjust according to grammar (options)
        _barbeat = 3;
    }
    
    // create parser (don't parse)
    ParserMultibar1bestSIPBU* parser =
    new ParserMultibar1bestSIPBU(_schema,
                                 _iseg,
                                 true,
                                 _pre,
                                 _post,
                                 _barsec,
                                 _bars,
                                 _ts);  //nbbars

    if (f_output)
    {
        if(_output_file.size() == 0)
        {
            ERROR("empty output file name");
            return 1;
        }
        // barbeat for MIDI file output
        INFO("write quantified MIDI output in {}", _output_file);
        parser->demo(_schema_file, _input_file,
                     _output_file, Rational(_barbeat));
    }
    else
    {
        parser->demo(_schema_file, _input_file);
    }

    delete parser;
    
#elif QUANT_SCENARIO == QUANT_MULTIBAR_1BEST_SIPFLAT
    // @todo : command line options
    double _tempo_min = 50;
    double _tempo_max = 60;
    size_t _steps = 10;
    if (! f_barbeat)
    {
        // @todo adjust according to grammar (options)
        _barbeat = 3;
    }
    
    ParserMultibar1bestSIPflat* parser;
    clock_t time_start = clock();
    
    if (_tempo_min == _tempo_max)
    {
        double barlen_min =
            ParserMultibar1bestSIPflat::barlen(_tempo_max, _barbeat);
        INFO("start parsing segment [{}-{}], rdur={}, tempo={}, bar length={}",
             _iseg->begin(),
             _iseg->end(),
             _iseg->length(),
             _tempo_min,
             barlen_min);
        
        // use above static variables
        parser = new ParserMultibar1bestSIPflat(_schema,
                                                _iseg,
                                                barlen_min,
                                                true,
                                                _pre,
                                                _post);
    }
    else
    {
        double barlen_min =
            ParserMultibar1bestSIPflat::barlen(_tempo_max, _barbeat);
        double barlen_max =
            ParserMultibar1bestSIPflat::barlen(_tempo_min, _barbeat);
        INFO("start parsing segment [{}-{}], rdur={}, tempo={}-{}, {} steps",
             _iseg->begin(),
             _iseg->end(),
             _iseg->length(),
             _tempo_min,
             _tempo_max,
             _steps);
        
        // use global variables of main
        parser = new ParserMultibar1bestSIPflat(_schema,
                                                _iseg,
                                                barlen_min,
                                                barlen_max,
                                                _steps,
                                                true,
                                                _pre,
                                                _post);
    }
    INFO("parse time : {}ms", duration(time_start));

    if (f_output)
    {
        if(_output_file.size() == 0)
        {
            ERROR("empty output file name");
            return 1;
        }
        // barbeat for MIDI file output
        parser->demo(_schema_file, _input_file,
                     _output_file, Rational(_barbeat));
    }
    else
    {
        parser->demo(_schema_file, _input_file);
    }
    
#else
#error ERROR squant.cpp : invalid QUANT_SCENARIO
#endif

    
    if (_schema)
        delete _schema;
    
    if (_iseg)
        delete _iseg;
    
    
    return(0);
}


