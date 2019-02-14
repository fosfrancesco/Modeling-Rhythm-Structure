//
//  equiv.cpp
//  qparse
//
//  Created by Florent Jacquemard on 16/11/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
// main for target equiv
// enumeration of rhythms of the same duration value

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
#include "trace.hpp"
#include "FloatWeight.hpp"
#include "TropicalWeight.hpp"
#include "ViterbiWeight.hpp"
#include "WTA.hpp"
#include "WTAFile.hpp"
#include "ValueWTA.hpp"
#include "CountingWTA.hpp"
#include "PtrSK.hpp"
#include "Rune.hpp"
#include "Table.hpp"
#include "ParserInputlessKbest.hpp"
#include "ValueList.hpp"
#include "Onsets.hpp"
#include "RT.hpp"
#include "OMRT.hpp"


// ==========================================================================
// Option handling with getop_long (stdlib)

static int verbosity = 0;

// number of K-best to compute   //was #define TEST_K 1
static size_t k = 1;

// input file option is present
static bool f_input = false;
// file name for reading quantized IOI list
static string _input_file;

// second input file option is present
static bool f_merge = false;
// file name for reading second quantized IOI list
static string _merge_file;

// file name for reading schema
static string _schema_file;
// schema file option is present
static bool f_schema = false;

// option: use the schema to do counting (grammar inference)
static int f_inference = false;

// file name for lilypond output
static string _output_file;
// output file option is present
static bool f_output = false;

// weight model in schema file
static int f_noweight = false;
static int f_penalty = false;
static int f_count = false;
static int f_proba = false;
static WeightDom _weight_type = WeightDom::UNDEF;

// config file (aka ini) option is present
static bool f_config = false;
// text file name for writing
static string _config_file;

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
    /*  8 */ { "schema",      required_argument, NULL, 'a' },
    /*  9 */ { "output",      required_argument, NULL, 'o' },
    /* 10 */ { "config",      required_argument, NULL, 'c' },

    // Options with no abbreviation
    
    /* 11 */ { "penalty",     no_argument,       &f_penalty,  true},
    /* 12 */ { "counting",    no_argument,       &f_count,    true },
    /* 13 */ { "proba",       no_argument,       &f_proba,    true },
    /* 14 */ { "probability", no_argument,       &f_proba,    true },
    /* 15 */ { "stochastic",  no_argument,       &f_proba,    true },
    /* 16 */ { "inference",   no_argument,       &f_inference, true },

    // last
    { NULL, 0, NULL, 0 }
};


static void setOptionArgs(int option_index)
{
    TRACE("setOptionArgs: {}", option_index);
    switch(option_index)
    {
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
            TRACE("setOptionArgs: {} model", long_options[option_index].name);
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
        ERROR("missing option: no schema file type");
        error = true;
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
    
    if (! f_schema)
    {
        ERROR("missing option: no schema file");
        error = true;
    }
    
    return error;
}


// k-best for initial states of ValueWTA
void print_bests(ParserInputlessKbest* parser, state_t init, size_t k)
{
    assert (parser);
    INFO("Printing {} bests :", k);
    for (size_t i = 1; i <= k; i++)
    {
        parser->printBest(std::cout, i);
        std::cout << "\n";
//        SKpointer p(init, i);
//        Run<SKpointer>* r = parser->table->best(p);
//        if (r)
//        {
//            RhythmTree* t = parser->best(i);
//            assert (t);
//            OMRhythmTree omt = OMRhythmTree(t);
//
//            INFO("{}-best: {} (weight={})", i, t->to_string(), r->weight);
//            //cout << " " << r.duration << "\n";
//            //cout << "       " << omt.to_string();
//            delete t;
//        }
    }
}


int count_best(ParserInputlessKbest* parser,
               state_t init,
               CountingWTA* cschema)
{
    // try 1-best (for duration list)
    SKpointer p(init, 1);
    
    Weight w1 = parser->bestWeight(1);
    Weight w2 = parser->bestWeight(2);

    if (w1.unknown())
    {
        ERROR("language empty, abort");
        return 1;
    }
    else if (w1 == w2)
    {
        ERROR("2 best trees have the same weight {}", w1);
        ERROR("t1 = {}", *(parser->best(1)));
        ERROR("t2 = {}", *(parser->best(2)));
        ERROR("abort");
        return 2;
    }
    
    RhythmTree* t1 = parser->best(1);
    
    if (t1 == NULL)
    {
        ERROR("cannot compute 1-best");
        return 3;
    }
    else
    {
        INFO("counting-eval best tree {}", *t1);
        assert(cschema);
        assert(cschema->hasWeightType("CountingWeight"));
        Weight w = cschema->eval(*t1);

        std::cout << w << "\n";
        
        return 0;
    }
}


int save_lily(ParserInputlessKbest* parser,
              state_t init,
              size_t k,
              string filename,
              string schema_name)
{
    INFO("LilyPond output for {}-best equiv, write to {}", k, filename);
    std::ofstream file;
    file.open(filename, std::ios_base::out);
    if(!file.is_open())
    {
        ERROR("Cannot open {} for output", filename);
        return 1;
    }
    
    // try 1-best (for duration list)
    SKpointer p(init, 1);
    Run<SKpointer>* r0 = parser->table->best(p);

    if (r0)
    {
        //assert(! r0->unknown());
        // LilyPond header
        file << "\\header{ \n";
        file << "  title = \"rhythm notations of value ";
        file << r0->duration;
        file << " (";
        file << schema_name;
        file << ")";
        file << "\"\n";
        file << "}\n";
        file << "\n";
        
        // beginning of score
        file << "\\score {\n";
        file << "<<\n";
        file << "\\new RhythmicStaff {\n";
        file << "\\time 1/4\n";
        
        // one best sol per bar
        for (size_t i = 1; i <= k; i++)
        {
            RhythmTree* t = parser->best(i);
            if (t)
            {
                // without dots
                file << t->lily(4);
                // file << "\n";
                // with dots (test)
                string d = t->lilydot(4);
                if (t->dot_flag) { file << "\n" << d; }
                file << " \\bar \"||\" ";
                file << "\n";
                //file << "}\n";
                delete t;
            }
        }
        
        // end of score
        file << "}\n";
        file << ">>\n";
        file << "}\n";
        file << "\n";
        file << "\\version \"2.18.2\"\n";
    }
    
    file.close();
    return 0;
}


//WTA* read_schema(const string filename)
//{
//    clock_t time_start;
//
//    INFO("Read schema WTA from {}", filename); // << '\n';
//    Weight seed;
//
//    if (f_penalty)
//        seed = TropicalWeight::make_zero();
//    else if (f_count)
//        seed = FloatWeight::make_zero();
//    else if (f_proba)
//        seed = ViterbiWeight::make_zero();
//
//    assert(! seed.unknown());
//
//    WTA* schema = new WTA(seed, filename);
//    INFO("input schema:");
//    schema->print(cout);
//
//#if  QP_WEIGHT == WEIGHT_STOCHASTIC
//    assert(schema);
//    if (f_penalty)
//    {
//        ERROR("This version is compiled for stochastic weight models.");
//        ERROR("Cannot cast weights from penalty into stochastic model. Abort");
//        return NULL;
//    }
//    else if (f_count)
//    {
//        WARN("Casting weights from counting into stochastic model.");
//        schema->CountingtoStochastic();
//        return schema;
//    }
//    else if (f_proba)
//    {
//        return schema;
//    }
//#elif QP_WEIGHT == WEIGHT_PENALTY
//    if (f_penalty)
//    {
//        return schema;
//    }
//    else if (f_count)
//    {
//        WARN("Casting weights from counting into penalty model.");
//        schema->CountingtoPenalty();
//        return schema;
//    }
//    else if (f_proba)
//    {
//        ERROR("This version is compiled for penalty weight models.");
//        ERROR("Impossible to cast weights from stochastic into penalty model. Abort");
//        return NULL;
//    }
//#else
//#error ERROR unknown weight model
//#endif
//
//    return schema;
//}


size_t compute_resolution(WTA* schema)
{
    assert (schema);
    clock_t time_start;
    
    INFO("\n====  Compute Resolution:");
    time_start = clock();
    size_t res = schema->resolution();
    INFO("resolution = {}", res);
    INFO("time to compute resolution : {}ms", duration(time_start));
    
    return res;
}


void usage()
{
    std::cout << "Usage: equiv [options...]";
    std::cout << std::endl;
    std::cout << "  -help -h";
    std::cout << std::endl;
    std::cout << "  -version -V";
    std::cout << std::endl;
    std::cout << "  -verbosity level -v level : level=0..6  (default is 0)";
    std::cout << std::endl;
    std::cout << "             levels: 0=trace, 1=debug, 2=info, 3=warn";
    std::cout << std::endl;
    std::cout << "                     4=err,   5=critical,      6=off";
    std::cout << std::endl;
    std::cout << "  -trace -t : same as -verbosity 6";
    std::cout << std::endl;
    std::cout << "  -debug -d : same as -verbosity 5";
    std::cout << std::endl;
    std::cout << "  -quiet -q : same as -verbosity 0";
    std::cout << std::endl;
    std::cout << "  --kbest N -k N : compute the N best trees";
    std::cout << std::endl;
    std::cout << "  -input filename -i filename : filename is a text file";
    std::cout << std::endl;
    std::cout << "           with one fraction (IOI) per line";
    std::cout << std::endl;
    std::cout << "  -input filename -i filename : second IOI file to merge (optional)";
    std::cout << std::endl;
    std::cout << "  -schema filename -a filename : filename contains \
         the text description of a WTA";
    std::cout << std::endl;
    std::cout << "  -counting filename -g filename : filename contains \
    the text description of a WTA for counting the best tree (grammatical inference)";
    std::cout << std::endl;
    std::cout << "  -output filename -o filename : lilypond output in filename";
    std::cout << std::endl;
    std::cout << "  -config file.ini -c file.ini : configuration file";
    std::cout << std::endl;
    std::cout << "  -tree string : text description of a RT";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "schema weight model (mutually exclusive options):";
    std::cout << std::endl;
    std::cout << "  -counting";
    std::cout << std::endl;
    std::cout << "  -penalty";
    std::cout << std::endl;
    std::cout << "  -probability -stochastic";
    std::cout << std::endl;
    std::cout << "  -noweight -nw : ignore weights in input file";
    std::cout << std::endl;
    std::cout << " " << std::endl;
    std::cout << "-probability -stochastic are equivalent";
    std::cout << std::endl;
    std::cout << "-counting -penalty -probability -stochastic are mutualy exclusive";
    std::cout << std::endl;
    std::cout << "-trace has priority over -verbosity";
    std::cout << std::endl;
}


void version()
{
    INFO("equiv: command line version 0.1");
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
        
        c = getopt_long_only(argc, argv, "hVv:dtk:i:a:o:",
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
                k = atoi(optarg);
                TRACE("Option {} : {}",
                      long_options[option_index].name, k);
                if (k == 0)
                {
                    ERROR("option error: k={} must be > 0", k);
                    std::exit(1);
                }
                break;
                
            case 'i':
                if (f_input)
                {
                    if (f_merge)
                    {
                        ERROR("two many input files (max 2)");
                        std::exit(1);
                    }
                    else
                    {
                        f_merge = true;
                        _merge_file = std::string(optarg);
                        TRACE("Option {}: {}",
                              long_options[option_index].name, _input_file);
                    }
                }
                else
                {
                    f_input = true;
                    _input_file = std::string(optarg);
                    TRACE("Option {}: {}",
                          long_options[option_index].name, _input_file);
                }
                break;
                
            case 'a':
                f_schema = true;
                _schema_file = std::string(optarg);
                TRACE("Option {}: {}",
                      long_options[option_index].name,
                      _schema_file);
                break;

            case 'o':
                f_output = true;
                _output_file = std::string(optarg);
                TRACE("Option {}: {}",
                      long_options[option_index].name,
                      _output_file);
                break;

            case 'c':
                f_config = true;
                _config_file = std::string(optarg);
                TRACE("Option {}: {}", long_options[option_index].name,
                      _config_file);
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
    INFO("schema file: {} ({} weight model)",
         _schema_file,
         (f_count?"Counting":
                  (f_proba?"Stochastic":(f_penalty?"Penalty":"???"))));
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
   
    clock_t time_start;
    //clock_t time_end;
    
    // WTA file
    WTA* schema = new WTAFile(_schema_file, _weight_type);
    
    if (schema == NULL || schema->empty())
    {
        ERROR("error importing schema from {}, abort", _schema_file);
        return 2;
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
 
    
    // resolution
    //size_t res = compute_resolution(schema);
    
    // read rhythmic value (2 options)
    DurationList seg;

    // one schema, no rythmic value
    if (! f_input)
    {
        INFO("no input (enumeration of schema)");
    }
    // one schema, one rythmic value
    else if (f_input && (! f_merge))
    {
        INFO("Read rhythmic value from {}", _input_file);
        // string valuename = string(argv[2])+".txt";
        seg = DurationList(_input_file);
        INFO("length rhythmic value: {}", seg.size());
        INFO("rhythmic value = {}", seg);    }
    // one schema, first rythmic value, second rythmic value
    else
    {
        INFO("Read first rhythmic first from {}", _input_file);
        //string valuename1 = string(argv[2])+".txt";
        Onsets on1 = Onsets(DurationList(_input_file));
        INFO("Read second rhythmic first from {}", _merge_file);
        //string valuename2 = string(argv[3])+".txt";
        Onsets on2 = Onsets(DurationList(_merge_file));
        Onsets on = on1+on2;
        seg = (on1+on2).ioi();
        INFO("length merged rhythmic value: {}", seg.size());
        INFO("merged rhythmic value = {}", seg);
    }
       
    assert (schema);
    ParserInputlessKbest* parser;
    state_t init;
    
//    size_t lastindex = _schema_file.find_last_of(".");
//    string schemaprefix = _schema_file.substr(0, lastindex);
//    string filename;
//    size_t dotindex = filename.find_last_of(".");
//    string prefix = filename.substr(0, dotindex);
//    string suffix = filename.substr(dotindex + 1);
    
    // enumeration of schema
    if (! f_input)
    {
        time_start = clock();
        // true : ascending order
        // @todo : enumeration ordering in command-line option
        parser = new ParserInputlessKbest(schema, true);
        init = schema->initial();

        //filename = schemaprefix+".ly";
        
        if (f_output)
        {
            INFO("enumerating schema {} in {}", _schema_file, _output_file);
            save_lily(parser, init, k, _output_file, _schema_file);
        }
        else
        {
            INFO("enumerating schema {}", _schema_file);
            print_bests(parser, init, k);
        }
        
        TRACE("time for computing {}-best : {}ms", k, time_start);
    }
    // enumeration of schema inter rhythmic values
    else
    {
        TRACE("Construction of ValueWTA");
        time_start = clock();
        ValueWTA* vwta = new ValueWTA(seg, *schema);

        TRACE("time to compute ValueWTA : {}ms", duration(time_start));
        TRACE("ValueWTA:");
        if (verbosity >= 4) // info
        {
            vwta->print(std::cout);
            std::cout << *vwta;
        }
        
//        TRACE("Cleaning ValueWTA");
//        TRACE("Debug1");
//        time_start = clock();
//        TRACE("Debug2");
//        vwta->clean();
//        TRACE("Debug after clean");
//        TRACE("time to clean ValueWTA : {}ms", duration(time_start));
//        if (verbosity >= 4) // info
//        {
//            vwta->print(std::cout);
//            std::cout << *vwta;
//        }

        // true : ascending order
        // @todo : enumeration ordering in command-line option
        // @todo : create a quantified segment from input
        // and pass it to a Parser1barKbestSKIP
        parser = new ParserInputlessKbest(vwta, true);
        init = vwta->initial();
        assert(parser->wta);
        assert(parser->table);
        
        time_start = clock();

//      //one input file
//      filename = string(argv[2])+"-"+schemaprefix+".ly";
//      //two merged input files
//      filename = string(argv[2])+"+"+string(argv[3])+"-"+schemaprefix+".ly";

        if (f_output)
        {
            save_lily(parser, init, k, _output_file, _schema_file);
        }
        // get the 1-best and apply counting grammar
        // tmp grammar weight inference algo
        else if (f_inference)
        {
            assert (schema);
            DEBUG("casting weights to vectors of counters.");
            CountingWTA* cschema = new CountingWTA(*schema);
            assert (cschema->hasWeightType("CountingWeight"));
            if (verbosity >= 4) // level INFO
            {
                TRACE("counting schema:");
                std::cout << *cschema;
                cschema->print(std::cout);
            }

            assert (cschema);
            if (cschema->empty())
            {
                ERROR("error: empty schema after casting weight to counting, abort");
                return(2);
            }

            count_best(parser, init, cschema);

            delete cschema;
        }
        else
        {
            print_bests(parser, init, k);
        }

        TRACE("time to compute {}-best : {}ms", k, duration(time_start));

        delete vwta;
    }

    delete parser;
    delete schema;

    return 0;
}
