//
//  qpconfig.h
//  qparse
//
//  Created by Florent Jacquemard on 01/11/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup general
/// @{


/// Here we check that the compile flags are set and correct:
/// QP_PLATFORM = PLATFORM_xxx
/// QP_TARGET = TARGET_xxx
/// where the possibles values for PLATFORM_xxx (target platform)
/// and TARGET_xxx (executable) are defined by compiler flags.
///
/// in Xcode,
/// the flags are defined.

#ifndef qpconfig_h
#define qpconfig_h


// ----- Platform : execution architecture -----

#ifndef PLATFORM_DARWIN
#error ERROR qpconfig.h : no tag PLATFORM_DARWIN
#endif

#ifndef PLATFORM_LINUX
#error ERROR qpconfig.h : no tag PLATFORM_LINUX
#endif

#ifndef PLATFORM_CYGWIN
#error ERROR qpconfig.h : no tag PLATFORM_CYGWIN
#endif

#ifndef PLATFORM_FREEBSD
#error ERROR qpconfig.h : no tag PLATFORM_FREEBSD
#endif

#ifndef QP_PLATFORM
#error ERROR qpconfig.h : flag QP_PLATFORM undefined
#endif

//extern const char* configuration_qparse_archi;

#if QP_PLATFORM == PLATFORM_DARWIN
// OK we are on MAC OS
#elif QP_PLATFORM == PLATFORM_LINUX
// OK, we are on a Linux plateform
#elif QP_PLATFORM == PLATFORM_CYGWIN
// OK, we are on a Windows plateform
#elif QP_PLATFORM == PLATFORM_FREEBSD
// OK, we are on a Free BSD plateform
#else
#error ERROR qpconfig.h : invalid QP_PLATFORM
#endif


// ----- Target: executable or library -----

#ifndef TARGET_QUANT
#error ERROR qpconfig.h : no tag TARGET_QUANT
#endif

#ifndef TARGET_EQUIV
#error ERROR qpconfig.h : no tag TARGET_EQUIV
#endif

#ifndef TARGET_SCHEMA
#error ERROR qpconfig.h : no tag TARGET_SCHEMA
#endif

#ifndef TARGET_MIDI
#error ERROR qpconfig.h : no tag TARGET_MIDI
#endif

#ifndef TARGET_MEI
#error ERROR qpconfig.h : no tag TARGET_MEI
#endif


// QP_TARGET not used anymore
// @todo TBR?
//#ifndef QP_TARGET
//#error ERROR qpconfig.h : flag QP_TARGET undefined
//#endif

//extern const char* configuration_qparse_target;

// QP_TARGET not used anymore
// @todo TBR?
//#if   QP_TARGET == TARGET_QUANT   // command line for quantization command line
//#elif QP_TARGET == TARGET_EQUIV   // command line for rhythm equivalence
//#elif QP_TARGET == TARGET_SCHEMA  // command line for processing schemas (WTAs)
//#elif QP_TARGET == TARGET_MIDI    // command line for midi utils
//#elif QP_TARGET == TARGET_MEI     // command line for testing MEI integration
//#else
//#error ERROR qpconfig.h : invalid QP_TARGET
//#endif




// ----- Parsing algorithm -----
// @todo TBR

//#ifndef PARSING_VITERBI
//#error ERROR qpconfig.h : no tag PARSING_VITERBI
//#endif
//
//#ifndef PARSING_KBEST
//#error ERROR qpconfig.h : no tag PARSING_KBEST
//#endif
//
//#ifndef QP_PARSING
//#error ERROR qpconfig.h : no tag QP_PARSING
//#endif
//
//#if   QP_PARSING == PARSING_VITERBI   // 1-best parsing
//#elif QP_PARSING == PARSING_KBEST     // k-best parsing
//#else
//#error ERROR qpconfig.h : invalid QP_PARSING
//#endif



// --- System information -------------------

extern long virtual_memory_size();
extern long resident_memory_size();


#endif /* qpconfig_h */


/// @}
