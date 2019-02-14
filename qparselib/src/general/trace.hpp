//
//  trace.hpp
//  qparse
//
//  Created by Florent Jacquemard on 19/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup general
/// @{



#ifndef trace_hpp
#define trace_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h" // must be included


/// trace levels:
/// - 0: off
/// - 1: critical
/// - 2: error
/// - 3: warn
/// - 4: info
/// - 5: debug
/// - 6: trace


#if QP_PLATFORM == PLATFORM_LINUX
/// to patch a bug in g++
/// see https://stackoverflow.com/questions/12975341/to-string-is-not-a-member-of-std-says-g-mingw
namespace patch
{
    template < typename T > std::string to_string(const T& n)
    {
        std::ostringstream os;
        os << n ;
        return os.str() ;
    }
}
#endif


//
// debug log trace
//

/// @todo TBR
const int TRACE_LEVEL = 2;

#define TRACE_ON
#define DEBUG_ON

// specialized traces can be switched off individualy

/// addition of candidates
#define _TRACE_CAND 1

/// addition of best runs
#define _TRACE_BEST

/// initialization and construction of tables
#define _TRACE_TBL


namespace spd = spdlog;

/// Console logger with color
///const std::shared_ptr<spd::logger> console = spd::stdout_color_mt("console");
extern const std::shared_ptr<spd::logger> console;

#define ERROR(...) console->error(__VA_ARGS__)
#define WARN(...) console->warn(__VA_ARGS__)
#define INFO(...) console->info(__VA_ARGS__)

#ifdef TRACE_ON
// __FUNCTION__ or __func__ not supported in c++?
//#define TRACE(...) console->trace("[" __FUNCTION_NAME__ "] " __VA_ARGS__)
#define TRACE(...) console->trace(__VA_ARGS__)
#else
#define TRACE(...)
#endif

#ifdef DEBUG_ON
#define DEBUG(...) console->debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#ifdef _TRACE_CAND
#define TRACE_CAND(...) TRACE(__VA_ARGS__)
#else
#define TRACE_CAND(...)
#endif

#ifdef _TRACE_BEST
#define TRACE_BEST(...) TRACE(__VA_ARGS__)
#else
#define TRACE_BEST(...)
#endif

#ifdef _TRACE_TBL
#define TRACE_TBL(...) TRACE(__VA_ARGS__)
#else
#define TRACE_TBL(...)
#endif


// ALT
//std::cout << "[" << __FILE__ << "][" << __FUNCTION__ << "][Line " << __LINE__ << "] " << str << std::endl;\

#endif /* trace_hpp */


/// @}
