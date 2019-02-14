//
//  constant.h
//  qparse
//
//  Created by Florent Jacquemard on 21/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
///
/// @defgroup general General module
///
/// The `general` module contains reusable tools and utilities,
/// initialization of constants, and tracing functions.
///
/// @addtogroup general
/// @{


// @todo TBR
// moved to init.hpp


#ifndef Constant_h
#define Constant_h

#pragma once

#include <stdio.h>

//#if QP_PLATFORM == PLATFORM_CYGWIN
//#define stat64 stat
//#define fstat64 fstat
//#endif

//#include "Rational.hpp"

// these variable should be moved as
// compile options
// to compile only the needed files

// parsing algo
// @todo TBR
//#define PARSING_VITERBI 1
//#define PARSING_KBEST   2
// default parsing algo
//#define QP_PARSING PARSING_VITERBI

// @todo TBR
//#define _TARGET_QUANTIZATION 1

#endif /* Constant_h */


/// @}
