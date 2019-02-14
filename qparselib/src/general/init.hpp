//
//  init.hpp
//  squant
//
//  Created by Florent Jacquemard on 21/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup general
/// @{


#ifndef init_hpp
#define init_hpp

#include <stdio.h>
#include <assert.h>
#include <limits.h>

#include "inih/INIReader.h"

#include "trace.hpp"
#include "Rational.hpp"


/// type for MIDI event numbers
extern int EVENTNB_UNKNOWN;

/// type for musical time values
extern Rational MUSTIME_UNKNOWN;

extern long MUSPOINTREF_NULL;

/// type for pre post values in Runs
typedef long pre_t;
#define PP_UNKNOWN -1
#define PP_KNOWN(x) (x >= 0)

/// weight types
enum class WeightDom
{
    UNDEF,       /// to be specified
    PENALTY,     /// tropical semiring
    STOCHASTIC,  /// Viterbi semiring
    COUNTING     /// int vectors for corpus stat
};

std::ostream& operator<<(std::ostream&, const WeightDom&);


/// read the constant and optimisation flag values in a config file
/// INI file, see https://en.wikipedia.org/wiki/INI_file
/// return 0 if reading the values succeded
/// -1 in case of file open error
/// or a number of line in case of parse error in .ini file.
int read_config(const std::string  filename);

/// weight type.
/// value specified in grammar file
/// or default value WeightDom::UNDEF
extern WeightDom CST_WEIGHT_TYPE;

/// max number of grace notes specified in grammar
/// used for abstraction of terminal transition labels
/// see Label.hpp
/// value specified in grammar file
/// or default 0 (there is no abstraction of labels)
extern long CST_MAX_GRACE;

/// coefficient for combining weight and distance in pernalty weight model
extern double CST_ALPHA;

/// constant for computing performance weight
/// see PerformanceModel.hpp
extern double CST_SIGMA2;

/// symbols for labeling RT and WTA terminal transitions
/// max arity
extern long MAX_AR;

/// precision for floting point unit calculations
extern double CST_PRECISION;

/// hash function parameters
/// Bernstein hash
/// http://www.eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx
/// see also Josh Bloch, Effective Java
/// see http://stackoverflow.com/a/1646913/126995
/// and also http://stackoverflow.com/questions/17016175
///
/// see also https://stackoverflow.com/a/1646913/6930643
///constexpr int HASH_SEED = 17;
///constexpr int HASH_FACTOR = 31;
/// see also https://stackoverflow.com/a/34006336/6930643
extern long HASH_SEED;
extern long HASH_FACTOR;


/// optimization flag
/// compute at most one best run for a duration sequence in each record.
/// it is the first best run added, i.e. the best with that duration sequence.
/// OPT_RUN_DUR must be set.
/// value specified in ini file
/// or default: false
extern bool OPT_RUN_STRICT;

/// optimization flag
/// do not add non-terminal runs with duration sequences of the form [0…0, 1].
/// they correspond to reducible runs of the form p(x, _,…, _)
/// where x is a leaf and _ is a continuation (tie).
/// OPT_RUN_DUR must be set.
/// value specified in ini file
/// or default: true
extern bool OPT_RUN_UNIT;

/// optimization flag
/// compute the duration sequences of runs.
/// if unset, OPT_RUN_UNIT must be automatically unset
/// value specified in ini file
/// or default: true
extern bool OPT_RUN_DUR;

/// option flag
/// ignore rests in MIDI input file
/// where a rest is the duration between a note off and the next note on msg.
extern bool OPT_NOREST;

extern double duration(clock_t start);

#endif /* init_hpp */


/// @}
