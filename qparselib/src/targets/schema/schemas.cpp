//
//  schemas.cpp
//  qparse
//
//  Created by Florent Jacquemard on 17/11/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
// management of schema files

#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>     // handling commandline options
#include <assert.h>

#include "init.hpp"
#include "trace.hpp"
#include "Rational.hpp"

#include "FloatWeight.hpp"
#include "TropicalWeight.hpp"
#include "ViterbiWeight.hpp"
#include "CountingWeight.hpp"

#include "WTA.hpp"
#include "WTAFile.hpp"
#include "SubdivisionSchema.hpp"
#include "CountingWTA.hpp"
#include "DurationList.hpp"

#include "RT.hpp"



// ==========================================================================
// Option handling with getop_long (stdlib)
// the values of these variables is set by command line option

static int verbosity = 0;

// input file option is present
static bool f_input = false;
// file name for reading grammar
static string _input_file;

// output file option is present
static bool f_output = false;
// text file name for writing
static string _output_file;

// tree option is present
static int f_tree = false;
// argument of tree option (string rep. of input tree)
static string s_tree;
// trees option is present
static int f_trees = false;
// argument of trees option
// file name for reading string rep. of input trees
static string tree_file;

// config file (aka ini) option is present
static bool f_config = false;
// text file name for writing
static string _config_file;

static int f_noweight = false;
static int f_clean = false;
static int f_penalty = false;
static int f_count = false;
static int f_proba = false;
static WeightDom weight_type = WeightDom::UNDEF;

static struct option long_options[] =
{
    // Options with an abbreviation
    // we dont use flags here, we set them after calling getopt instead
    
    /*  0 */ { "help",        no_argument,       NULL,   'h' },
    /*  1 */ { "version",     no_argument,       NULL,   'V' },
    
    /*  2 */ { "verbosity",   required_argument, NULL,   'v' },
    /*  3 */ { "debug",       no_argument,       NULL,   'd' },
    /*  4 */ { "trace",       no_argument,       NULL,   't' },
    /*  5 */ { "quiet",       no_argument,       NULL,   'q' },

    /*  6 */ { "print",       no_argument,       NULL,   'p' },
    
    /*  7 */ { "input",       required_argument, NULL,   'i' },
    /*  8 */ { "output",      required_argument, NULL,   'o' },
    /*  9 */ { "config",      required_argument, NULL, 'c' },
    
    // Options with no abbreviation
    
    /* 10 */ { "tree",        required_argument, &f_tree,     true },
    /* 11 */ { "trees",       required_argument, &f_trees,    true },
    /* 12 */ { "penalty",     no_argument,       &f_penalty,  true},
    /* 13 */ { "counting",    no_argument,       &f_count,    true },
    /* 14 */ { "proba",       no_argument,       &f_proba,    true },
    /* 15 */ { "probability", no_argument,       &f_proba,    true },
    /* 16 */ { "stochastic",  no_argument,       &f_proba,    true },
    /* 17 */ { "noweight",    no_argument,       &f_noweight, true },
    /* 18 */ { "nw",          no_argument,       &f_noweight, true },
    /* 19 */ { "clean",       no_argument,       &f_clean,    true },

    // last
    { NULL, 0, NULL, 0 }
};


#define check_index_is(NAME) \
assert(0 == strcmp(long_options[option_index].name, NAME))

static void setOptionArgs(int option_index)
{
    TRACE("setOptionArgs: {}", option_index);
    
    // long options without abbreviation and with argument
    switch(option_index)
    {
        case 10:
            check_index_is("tree");
            assert (f_tree);
            s_tree = std::string(optarg);
            TRACE("setOptionArgs: {} {}",
                  long_options[option_index].name, s_tree);
            break;

        case 11:
            check_index_is("trees");
            assert (f_trees);
            tree_file = std::string(optarg);
            TRACE("setOptionArgs: {} {}",
                  long_options[option_index].name, tree_file);
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
        ERROR("missing grammar in input");
        error = true;
    }
    
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
        TRACE("no schema file type in option (checking it is in grammar file)");
    }
    
    // set forced weight type value
    if (f_penalty)
    {
        weight_type = WeightDom::PENALTY;
    }
    else if (f_count)
    {
        weight_type = WeightDom::COUNTING;
    }
    else if (f_proba)
    {
        weight_type = WeightDom::STOCHASTIC;
    }
    else
    {
        weight_type = WeightDom::UNDEF;
    }

    
    if (f_tree && f_trees)
    {
        ERROR("option conflict -tree and -trees");
        error = true;
    }
        
    return error;
}


//double duration(clock_t start)
//{
//    return ((double)(clock() - start)/CLOCKS_PER_SEC * 1000);
//}


//WTA* read_schema(const string filename, bool norm_flag=true)
//{
//    clock_t time_start;
//
//    INFO("==== Read schema WTA from {}", filename);
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
//
//    if (verbosity >= 4) // level INFO
//    {
//        std::cout << *schema;
//        schema->print(cout);
//    }
//
//    // TBC remove 0 weighted transitions
//    if (f_clean)
//    {
//        INFO("==== Cleaning schema");
//        time_start = clock();
//        schema->clean();
//        //time_end = clock();
//        INFO("time to clean WTA : {} ms", duration(time_start));
//        if (verbosity >= 4) // level INFO
//        {
//            TRACE("clean schema:");
//            schema->print(cout);
//        }
//    }
//
//    // QP_WEIGHT == WEIGHT_STOCHASTIC
//    if ( CST_WEIGHT_TYPE == WeightDom::STOCHASTIC )
//    {
//        assert(schema);
//        if (f_penalty)
//        {
//            WARN("This version is compiled for stochastic weight models.");
//            WARN("Casting weights from penalty into stochastic model, via counting model.");
//            WARN("The outcome is not guaranteed.");
//            TRACE("Casting weights from penalty into counting model.");
//            schema->PenaltytoCounting();
//            TRACE("Casting weights from counting into stochastic model.");
//            schema->CountingtoStochastic();
//            return schema;
//        }
//        else if (f_count)
//        {
//            WARN("Casting weights from counting into stochastic model.");
//            schema->CountingtoStochastic();
//            return schema;
//        }
//        else if (f_proba)
//        {
//            return schema;
//        }
//    }
//    // QP_WEIGHT == WEIGHT_PENALTY
//    else if ( CST_WEIGHT_TYPE == WeightDom::PENALTY )
//    {
//        if (f_penalty)
//        {
//            return schema;
//        }
//        else if (f_count)
//        {
//            WARN("Casting weights from counting into penalty model.");
//            schema->CountingtoPenalty();
//            return schema;
//        }
//        else if (f_proba)
//        {
//            ERROR("This version is compiled for penalty weight models.");
//            ERROR("Impossible to cast weights from stochastic into penalty model. Abort");
//            return NULL;
//        }
//    }
//    else
//    {
//        ERROR("unxepected weight type");
//    }
//
//    return schema;
//}



Weight read_tree(CountingWTA* schema, string s)
{
    RhythmTree t(s_tree);
    INFO("eval tree {} ({})", s, t);
    assert(schema);
    assert(schema->hasWeightType("CountingWeight"));
    return schema->eval(t);
}


Weight read_trees(WTA* schema, const string filename)
{
    std::ifstream file;
    file.open(filename, std::ios_base::in);
    if(!file.is_open())
    {
        ERROR("cannot open file: {}", filename);
        exit(1);
    }
    int ln = 0;

    assert (schema);
    RhythmTree t;
    Weight w = schema->weight_one();
    
    for(string line; getline(file, line); )
    {
        ln++;
        // skip empty line
        if (line.size() == 0) continue;

        t = RhythmTree(line);
        Weight u = schema->eval(t);
        INFO("{}: eval tree {} ({}): {}", ln, line, t, u);
        w *= u;
    }

    return w;
}


size_t compute_resolution(WTA* schema)
{
    assert (schema);
    clock_t time_start;
    
    INFO("====  Compute Resolution:");
    time_start = clock();
    size_t res = schema->resolution();
    INFO("resolution = {}", res);
    INFO("time to compute resolution : {}ms", duration(time_start));
    
    return res;
}

// compute run of max weight for given schema
void max(WTA* schema)
{
//    assert (schema);
//    cout << "\n==== 1-best for all of " << schema->initials.size() << " initials\n";
//    clock_t time_start = clock();
//    Ktable kt0 = Ktable(schema, weightMax);
//    Run r = kt0.Kcontainer::bestinit(1);
//    cout << "time to 1-best (max) for initial state of schema : ";
//    cout << duration(time_start) << "ms \n";
//    cout << "1-best (max) = ";
//    if (r.unknown()) { cout << "NaN\n"; }
//    else
//    {
//        RhythmTree t = RhythmTree(r, &kt0);
//        cout << t.to_string() << " weight = ";
//        cout << r.weight << "\n";
//    }
}



void usage()
{
    std::cout << "Usage: schema [options...]";
    std::cout << std::endl;
    std::cout << "  -help -h";
    std::cout << std::endl;
    std::cout << "  -version -V";
    std::cout << std::endl;
    std::cout << "  -verbosity level -v level : level=0..6  (default is 0)";
    std::cout << std::endl;
    std::cout << "             levels: 6=trace, 5=debug, 4=info, 3=warn";
    std::cout << std::endl;
    std::cout << "                     2=err,   1=critical,      0=off";
    std::cout << std::endl;
    std::cout << "  -trace -t : same as -verbosity 6";
    std::cout << std::endl;
    std::cout << "  -debug -d : same as -verbosity 5";
    std::cout << std::endl;
    std::cout << "  -quiet -q : same as -verbosity 0";
    std::cout << std::endl;
    std::cout << "  -input filename -i filename : filename is a plain text file";
    std::cout << std::endl;
    std::cout << "   containing the text description of a WTA";
    std::cout << std::endl;
    std::cout << "  -clean   : clean input schema";
    std::cout << std::endl;
    std::cout << "  -output filename -o filename : output schema file";
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
    INFO("schema: version 0.2");
}




int main(int argc, char** argv)
{
    // set for tracing the parsing of options
    //
    // log levels:
    // trace =    6,
    // debug =    5,
    // info =     4,
    // warn =     3,
    // err =      2,
    // critical = 1,
    // off =      0
    spd::set_level(spd::level::debug);

    // index of the current option
    //int index = 0;
    
    // character of option
    int c;
    
    while(1)
    {
        /* getopt_long stores the option index here. */
        int option_index = 0;
        
        c = getopt_long_only(argc, argv, "hVv:dti:o:",
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

            case 'i':
                f_input = true;
                _input_file = std::string(optarg);
                TRACE("Option: {} {}",
                      long_options[option_index].name, _input_file);
                break;
                
            case 'o':
                f_output = true;
                _output_file = std::string(optarg);
                TRACE("Option: {} {}",
                      long_options[option_index].name, _output_file);
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
                ERROR("unkown or ambiguous option argument");
                break;
                
                // Do nothing for the options that are not flag-managed but without arguments
            default:
                break;
        }
    }
    
    if (checkOptions())
    {
        ERROR("option error. exit");
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

    if (f_input) { INFO("input file: {}", _input_file); }
    
    INFO("schema input file: {} ({} weight model option)",
         _input_file,
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
    
    // input schema (global)
    // read from file
    WTAFile* schema = new WTAFile(_input_file, weight_type);
    
    if (schema == NULL || schema->empty())
    {
        ERROR("error reading schema {}, abort", _input_file);
        exit (2);
    }
    if (CST_WEIGHT_TYPE == WeightDom::UNDEF)
    {
        ERROR("no weight type found for {}, abort", _input_file);
        exit (3);
    }
    
    switch(CST_WEIGHT_TYPE)
    {
        case WeightDom::UNDEF:
            ERROR("weight type undef after importing grammar");
            exit(4); break;
        case WeightDom::PENALTY:
            INFO("weight model: penalty (alpha = {})", CST_ALPHA);
            break;
        case WeightDom::STOCHASTIC:
            INFO("weight type: stochastic (sigma2 = {})", CST_SIGMA2);
            break;
        case WeightDom::COUNTING:
            ERROR("weight type counting not supported for quantization");
            exit(4);
    }
    
    // TBC remove 0 weighted transitions
    if (f_clean)
    {
        INFO("Cleaning schema");
        schema->clean();
    }
    
    INFO("Schema (after casting and cleaning):");
    if (verbosity >= 4) // info
    {
        std::cout << *(schema);
        schema->print(std::cout);
    }
    
    if (f_trees || f_tree)
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

        if (f_trees)
        {
            Weight w = read_trees(cschema, tree_file);
            INFO("eval trees in {}: {}", tree_file, w);
            if (verbosity < 4)
            {
                std::cout << "eval trees in " << tree_file << ":\n";
                std::cout << w << "\n";
            }
        }
        else if (f_tree)
        {
            Weight w = read_tree(cschema, s_tree);
            INFO("eval tree {}: {}", s_tree, w);
            if (verbosity < 4)
            {
                std::cout << "eval tree " << s_tree << ":\n";
                std::cout << w << "\n";
            }
        }
        delete cschema;
        delete schema;
        exit(0);
    }
    
    
    // resolution
    //size_t res = compute_resolution(schema);
    
    // test 1-best (compute max weight of schema)
    //max(schema);
    
    
    // test normalization schema
    // max(schema);
    
    // test WTA file output
    if (f_output)
    {
        std::cout << "\n==== Write normalized WTA to " << argv[2] << '\n';
        schema->save(_output_file);
    }
    
    if (schema)
        delete schema;
    
    return 0;
}






