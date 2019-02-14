//
//  init.cpp
//  squant
//
//  Created by Florent Jacquemard on 21/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup general
/// @{


#include "init.hpp"

double duration(clock_t start)
{
    return ((double)(clock() - start)/CLOCKS_PER_SEC * 1000);
}


// default values for constants

int EVENTNB_UNKNOWN = -1;

Rational MUSTIME_UNKNOWN = Rational(-1);

long MUSPOINTREF_NULL = LONG_MIN; // limits.h

WeightDom CST_WEIGHT_TYPE = WeightDom::UNDEF;

long CST_MAX_GRACE = 0;

//double CST_ALPHA = 0.5;
double CST_ALPHA = 1.0;

double CST_SIGMA2 = 0.5;

long MAX_AR = 13;

double CST_PRECISION = 0.0000001;

long HASH_SEED = 1009;
long HASH_FACTOR = 9176;


// default values for optimisation flags

bool OPT_RUN_DUR = true;

bool OPT_RUN_STRICT = false;

bool OPT_RUN_UNIT = true;

bool OPT_NOREST = false;

int read_config(const std::string  filename)
{
    assert(filename.size() > 0);
    
    TRACE("open config ini file: {}", filename);
    INIReader reader(filename);
    
    if (reader.ParseError() < 0)
    {
        ERROR("Can't load config file {}", filename);
        return -1;
    }

    TRACE("read config ini file: {}", filename);
    
    OPT_RUN_DUR = reader.GetBoolean("options", "run_dur", true);
    OPT_RUN_UNIT = reader.GetBoolean("options", "run_unit", true);
    OPT_RUN_STRICT = reader.GetBoolean("options", "run_strict", false);
    if (OPT_RUN_DUR == false) { OPT_RUN_UNIT = false; OPT_RUN_STRICT = false; }
    OPT_RUN_STRICT = reader.GetBoolean("options", "norest", false);

//    CST_ALPHA = reader.GetReal("params", "alpha", 0.5);
    CST_ALPHA = reader.GetReal("params", "alpha", 1.0);
    CST_SIGMA2 = reader.GetReal("params", "sigma2", 0.5);
    MAX_AR = reader.GetInteger("params", "maxarity", 11);
    CST_PRECISION = reader.GetReal("params", "precision", 0.0000001);
    HASH_SEED = reader.GetInteger("hash", "seed", 1009);
    HASH_FACTOR = reader.GetInteger("hash", "factor", 9176);
    
    return reader.ParseError();
}



std::ostream& operator<<(std::ostream& o, const WeightDom& t)
{
    switch (t)
    {
        case WeightDom::UNDEF:
            o << "UNDEF";
            break;
        case WeightDom::PENALTY:
            o << "PENALTY";
            break;
        case WeightDom::STOCHASTIC:
            o << "STOCHASTIC";
            break;
        case WeightDom::COUNTING:
            o << "COUNTING";
            break;
        default:
            ERROR("Unknown weight type");
            o << "?UNKNOWN?";
            break;
    }
    
    
    return o;
}


/// @}
