/**
 * Utilities to test and run MEI functionalities
 */


#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>     // handling commandline options
#include <assert.h>

#include "init.hpp"
#include "trace.hpp"
#include "QPconfig.h" // check compile flags

using namespace std;
namespace ScoreModel{};
namespace sm = ScoreModel;

#include "MEI.hpp"

#include "Score.hpp"
#include "Event.hpp"
#include "Measure.hpp"
#include "Note.hpp"

#ifdef QP_PARSING
#undef QP_PARSING
#endif
#define QP_PARSING PARSING_VITERBI // 1-best parsing, alt   PARSING_KBEST


// switch options for WTA weight
#include "FloatWeight.hpp"
#if QP_WEIGHT == WEIGHT_PENALTY
#include "TropicalWeight.hpp"
#elif QP_WEIGHT == WEIGHT_STOCHASTIC
#include "ViterbiWeight.hpp"
#endif

#include "WTA.hpp"
#include "PtrSIP.hpp"
#include "DurationList.hpp"
#include "Atable.hpp"
#include "Table.hpp"
#include "Rune.hpp"
#include "Brecord.hpp"

#include "RT.hpp"  // output rhythm trees
#include "PointedRT.hpp"



// ==========================================================================
// Option handling with getop_long (stdlib)

static int verbosity = 0;

// number of K-best to compute   //was #define TEST_K 1
static size_t k = 1;

// TODO set as options
// toplevel PRE value #define TEST_PRE    0
//static const size_t pre = 0;

// toplevel POST value #define TEST_POST   0
//static const size_t post = 0;

// file name for reading input segment
static string input_file;
// input file is text or midi
static bool f_input = false;
// input file is midi
static bool f_midi = false;

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
static string output_file;

// file name for reading schema
static string schema_file;
// schema file is present
static bool f_schema = false;

// flag: clean WTA
static int f_clean = false;

// flag: parse entry as one single bar
static int f_bars = false;
// argument of bars option
static size_t bars = 1;

// flag: pre value
static int f_pre = false;
// argument of pre option
static size_t pre = 0;

// flag: post value
static int f_post = false;
// argument of post option
static size_t post = 0;


// weight type for WTA
static int f_penalty = false;
static int f_count = false;
static int f_proba = false;

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

    // Options with no abbreviation
    
    /* 11 */ { "penalty",     no_argument,       &f_penalty, true},
    /* 12 */ { "counting",    no_argument,       &f_count,   true },
    /* 13 */ { "proba",       no_argument,       &f_proba,   true },
    /* 14 */ { "probability", no_argument,       &f_proba,   true },
    /* 15 */ { "stochastic",  no_argument,       &f_proba,   true },
    /* 16 */ { "clean",       no_argument,       &f_clean,   true },
    /* 17 */ { "norest",      no_argument,       &f_norest,  true },
    /* 18 */ { "start",       required_argument, &f_start,   true },
    /* 19 */ { "end",         required_argument, &f_end,     true },
    /* 20 */ { "bars",        required_argument, &f_bars,    true },
    /* 21 */ { "pre",         required_argument, &f_pre,     true },
    /* 22 */ { "post",        required_argument, &f_post,    true },
    /* last */ { NULL, 0, NULL, 0 }
};

#define check_index_is(NAME) \
assert(0 == strcmp(long_options[option_index].name, NAME))

static void setOptionArgs(int option_index)
{
    TRACE("setOptionArgs: {}", option_index);
    
    // long options without abbreviation and with argument
    switch(option_index)
    {
        case 18:
            check_index_is("start");
            assert (f_start);
            d_start = strtod(optarg, NULL);
            TRACE("setOptionArgs {}: {}", long_options[option_index].name, d_start);
            break;
            
        case 19:
            check_index_is("end");
            assert (f_end);
            d_end = strtod(optarg, NULL);
            TRACE("setOptionArgs {}: {}", long_options[option_index].name, d_end);
            break;
            
        case 20:
            check_index_is("bars");
            assert (f_bars);
            bars = strtol(optarg, NULL, 10);
            TRACE("setOptionArgs {}: {}",
                  long_options[option_index].name, bars);
            break;
            
        case 21:
            check_index_is("pre");
            assert (f_pre);
            pre = strtol(optarg, NULL, 10);
            TRACE("setOptionArgs {}: {}", long_options[option_index].name, pre);
            break;
            
        case 22:
            check_index_is("post");
            assert (f_post);
            pre = strtol(optarg, NULL, 10);
            TRACE("setOptionArgs {}: {}", long_options[option_index].name, post);
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
        ERROR("missing option: schema file type");
        error = true;
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
        if (d_end <= d_start)
        {
            ERROR("start date must be before end date");
            error = true;
        }
    }
    
    return error;
}






WTA* read_schema(const string filename,
                 bool clean_flag=true,
                 bool norm_flag=true)
{
    clock_t time_start;
    
    INFO("==== Read schema WTA from {}", filename);
    Weight seed;
    
    // see constant.h for the pb of compile variable for WEIGHT
    if (f_count)
        seed = FloatWeight::make_zero();
#if QP_WEIGHT == WEIGHT_PENALTY
    assert(f_penalty);
    seed = TropicalWeight::make_zero();
#endif
#if QP_WEIGHT == WEIGHT_STOCHASTIC
    assert(f_proba);
    seed = ViterbiWeight::make_zero();
#endif
    
    assert(! seed.unknown());
    
    WTA* schema = new WTA(seed, filename);
    if (verbosity >= 4) // info
    {
        std::cout << *schema;
        schema->print(std::cout);
    }
    
    // TBC remove 0 weighted transitions
    if (clean_flag)
    {
        INFO("==== Cleaning schema");
        time_start = clock();
        schema->clean();
        //time_end = clock();
        INFO("clean schema:");
        if (verbosity >= 4) // info
        {
            schema->print(std::cout);
        }
    }
    
#if QP_WEIGHT == WEIGHT_STOCHASTIC
    assert(schema);
    if (f_penalty)
    {
        WARN("This version is compiled for stochastic weight models.");
        WARN("Casting weights from penalty into stochastic model, via counting model.");
        WARN("The outcome is not guaranteed.");
        TRACE("Casting weights from penalty into counting model.");
        schema->PenaltytoCounting();
        TRACE("Casting weights from counting into stochastic model.");
        schema->CountingtoStochastic();
        return schema;
    }
    else if (f_count)
    {
        WARN("Casting weights from counting into stochastic model.");
        schema->CountingtoStochastic();
        return schema;
    }
    else if (f_proba)
    {
        return schema;
    }
#elif QP_WEIGHT == WEIGHT_PENALTY
    if (f_penalty)
    {
        return schema;
    }
    else if (f_count)
    {
        WARN("Casting weights from counting into penalty model.");
        schema->CountingtoPenalty();
        return schema;
    }
    else if (f_proba)
    {
        ERROR("This version is compiled for penalty weight models.");
        ERROR("Impossible to cast weights from stochastic into penalty model. Abort");
        return NULL;
    }
#else
#error ERROR unknown weight model
#endif
    
    return schema;
}



size_t compute_resolution(WTA* schema)
{
    assert (schema);
    clock_t time_start;
    
    INFO("====  Compute Resolution:");
    time_start = clock();
    size_t res = schema->resolution();
    INFO("resolution = {}", res);
    
    return res;
}

// TODO InputSegment*
InputSegment* read_segment(const string filename,
                           size_t res,
                           size_t bars,
                           bool norest)
{
    InputSegment* seg;
    
    assert (res > 0);
    assert (bars > 0);
    assert(filename.size() > 0);
    
    INFO("==== Read input segment from {} ", filename);
    if (norest)
    {
        INFO("ignore rests");
    }
    
    if (f_midi)
    {
        MidiFile  midifile;
        int status = midifile.read(filename);
        if (status == 0)
        {
            ERROR("Error in MIDI file: {}", filename);
            exit(1);
        }
        else
        {
            seg = new InputSegment(midifile, true, 1, bars, norest);
        }
    }
    else
    {
        assert(f_input);
        // monophonic, resolution=res, 1 bloc
        seg = new InputSegment(filename, true, bars, norest);
    }

    seg.set_resolution(res);

    INFO("segment: size = {}", seg->size());
    INFO("segment :");
    if (verbosity >= 4) // info
    {
        seg->print(std::cout);
    }
    return seg;
}





void usage()
{
    INFO("Usage: quant [options...]");
    INFO("  -help -h");
    INFO("  -version -V");
    INFO("  -verbosity level -v level : level=0..6  (default is 0)");
    INFO("             levels: 0=trace, 1=debug, 2=info, 3=warn, \
         4=err,   5=critical, 6=off");
    INFO("  -trace -t : same as -verbosity 6");
    INFO("  -debug -d : same as -verbosity 5");
    INFO("  -quiet -q : same as -verbosity 0");
    INFO("  -kbest N -k N : compute the N best trees");
    INFO("input files:");
    INFO("  -input filename -i filename : \
         filename is either a text file or midifile \
         (characterized by extension .mid or .midi)");
    INFO("  -midi midifilename -m midifilename : filename is a midi file");
    INFO("  -schema filename -a filename : \
         filename contains the text description of a WTA");
    INFO("  -output filename -o filename : output score file");
    INFO("  ");
    INFO("schema weight model (mutually exclusive options):");
    INFO("  -counting");
    INFO("  -penalty");
    INFO("  -probability -stochastic");
    INFO("  ");
    INFO("  -clean  : clean input schema");
    INFO("  -norest  : ignore rests in input midifile");
    INFO("  -start D : set start date for input segment");
    INFO("  -end D   : set end date for input segment");
    INFO("  -pre I : number of notes added (as grace notes)\
         at the begining of the segment to quantize,\
         e.g. originating from another precedent segment");
    INFO("  -post I : number of notes that will be aligned to right bound\
         in quantization solutions");
    INFO("   -bar I : number of bars in the input segment (default 1)");
    INFO(" ");
    INFO("-input and -midi are mutualy exclusive");
    INFO("-probability -stochastic are equivalent");
    INFO("-counting -penalty -probability -stochastic are mutualy exclusive");
    INFO("-trace has priority over -verbosity");
}


void version()
{
    INFO("meiutil: version 0.1");
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
                
            case 'k':
                //k = strtoul(optarg, NULL, 10);
                k = atoi(optarg);
                TRACE("Option {} : {}",
                      long_options[option_index].name, k);
                if (k == 0)
                {
                    ERROR("option error: k={} must be > 0", k);
                    exit(1);
                }
                break;
                
            case 'i':
                f_input = true;
                input_file = std::string(optarg);
                TRACE("Option {}: {}",
                      long_options[option_index].name, input_file);
                break;
                
            case 'o':
                f_output = true;
                output_file = std::string(optarg);
                TRACE("Option {}: {}", long_options[option_index].name,
                      output_file);
                break;
                
            case 'm':
                f_midi = true;
                input_file = std::string(optarg);
                TRACE("Option {}: {}",
                      long_options[option_index].name, input_file);
                break;
                
            case 'a':
                f_schema = true;
                schema_file = std::string(optarg);
                TRACE("Option {}: {}",
                      long_options[option_index].name, schema_file);
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
        std::exit(1);
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
    
#if   QP_WEIGHT == WEIGHT_STOCHASTIC
    INFO("qparse quantization with stochastic weight model");
#elif QP_WEIGHT == WEIGHT_PENALTY
    INFO("qparse quantization with penalty weight model (alpha={})", CST_ALPHA);
#else
#error ERROR unknown weight model
#endif
    
    INFO("input file: {}", input_file);
    INFO("schema file: {} ({} weight model)",
         schema_file,
         (f_count?"counting":(f_proba?"stochastic":(f_penalty?"penalty":"???"))));

    //
    // read WTA from file
    // TODO: remove normalize flag
    //
    WTA* schema = read_schema(schema_file, f_clean, true);
    if (schema == NULL)
    {
        ERROR("error importing schema, exit");
        exit (1);
    }
    else
    {
        INFO("Schema (after cleaning and casting):");
        if (verbosity >= 4) // info
        {
            std::cout << *schema;
            schema->print(cout);
        }
    }
    
    //
    // compute resolution
    //
    size_t res = compute_resolution(schema);
    
    //
    // read input segment
    //
    InputSegment* iseg = read_segment(input_file, res, bars, f_norest);
    assert(iseg);
    
    if (iseg->size() == 0)
    {
        ERROR("empty segment, stopping");
        exit(2);
    }
    
    if (f_start)
    {
        iseg->set_begin(d_start);
    }
    
    if (f_end)
    {
        iseg->set_end(d_end);
    }
    
    // WTA used in parse table
    WTA* wta;
    
    // input segment used in parse table
    InputSegment* seg;
    
    INFO("use given WTA as schema");

    wta = schema;
    seg = iseg;
    assert(wta);
    assert (wta->hasType("WTA"));
    assert(iseg);
    
    
    typedef SIPpointer         PtrType;
    typedef SIPpointerHasher   HashType;

    // defined in Rune.hpp
    RunCompare<PtrType> weightOrdering;
    
    // ordering for BPointer or KPointer is the same
#if   QP_WEIGHT == WEIGHT_STOCHASTIC
    TRACE("Weight Ordering: Max");
    weightOrdering = weightMax<PtrType>;
#elif QP_WEIGHT == WEIGHT_PENALTY
    TRACE("Weight Ordering: Min");
    weightOrdering = weightMin<PtrType>;
#else
#error ERROR unknown weight model
#endif
    
    
    assert (wta);
    // pre, post ignored for std WTA, only for Combo WTA
    state_t init = wta->initial(pre, post);
    // parse table
    Atable<PtrType>* cont =
    new Table<PtrType, Brecord<PtrType>, HashType>(wta, weightOrdering, seg);
    assert(cont);
    assert(cont->environment);

    std::vector<const PointedRhythmTree*> quantizedbars =
        std::vector<const PointedRhythmTree*>(); // result of parsing
    
    // 1-best parsing
    Run<PtrType>* r = cont->best(pre, post, (bars == 1));

    // fill results vector with bars obtained by parsing
    if (r)
    {
        PtrType p(cont->environment, pre, post, (bars == 1));
        
        // one-bar run
        if (State::isWTA(p.state()))
        {
            RhythmTree* t = cont->bestTree(p);
            quantizedbars.push_back(new PointedRhythmTree(t, seg, 0));
            delete t;
        }
        // multiple bars run, print each bar
        else
        {
            assert(State::isMeta(p.state()));
            bool vazy = true;
            Run<PtrType>* rtail = r;
            Run<PtrType>* rhead = NULL;
            size_t next = 0;
        
            while (vazy)
            {
                assert(rtail);
                assert(rtail->inner());
                assert(rtail->arity() == 2);
                const PtrType& phead = (*rtail)[0];
                assert(phead.has_S());
                assert(State::isWTA(phead.state()));
                rhead = cont->best(phead);
                assert(rhead);
                RhythmTree* t = cont->bestTree(phead);
                PointedRhythmTree* pt = new PointedRhythmTree(t, seg, next);
                quantizedbars.push_back(pt);
                delete t;

                next = pt->next();
                const PtrType& ptail = (*rtail)[1];
                assert(ptail.has_S());
                assert(State::isMeta(ptail.state()));
                rtail = cont->best(ptail);
                vazy = ptail.divisible();
            }
        }
    }


    // (f_output == true) if an output file was given in option
    // output_file is the output filename
    

    cout << "Create the symbolic score from the best tree" << std::endl;

    ScoreModel::ScoreMeter sMeter = ScoreModel::ScoreMeter(2, 4);
    ScoreModel::Score myScore = ScoreModel::Score("test", sMeter);
    ScoreModel::Voice* voice = myScore.getVoice("test", "test");

	for (const PointedRhythmTree* pointedRT : quantizedbars) {
	    // First measure
		ScoreModel::Measure measure = myScore.addMeasure();
		cout << endl <<  "Found a pointedRTree. Add measure  " << measure.getId() << endl;
	   voice->addFromRhythmTree(measure, pointedRT, measure.getDuration());
	}


   cout << std::endl << "Serialize in MEI and store in" << output_file << std::endl;

    MEI meiProcessor = MEI();
    meiProcessor.createFromScore(myScore);
    meiProcessor.writeInFile(output_file);

    
#if QP_PARSING == PARSING_VITERBI
    delete (Table<PtrType, Brecord<PtrType>, HashType>*) cont;
#elif QP_PARSING == PARSING_KBEST
    delete (Table<PtrType, Krecord<PtrType>, HashType>*) cont;
#endif
    delete wta;
    delete seg;
    
    exit(0);
}

    
