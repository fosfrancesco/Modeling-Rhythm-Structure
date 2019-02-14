//
//  trace.cpp
//  qparse
//
//  Created by Florent Jacquemard on 19/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup general
/// @{


#include "trace.hpp"


#if QP_PLATFORM == PLATFORM_DARWIN
const auto console = spd::stdout_color_mt("console");
#elif QP_PLATFORM == PLATFORM_LINUX
//const std::shared_ptr<spd::logger> console = spd::stdout_color_mt("console");
const std::shared_ptr<spd::logger> console = spdlog::stdout_logger_mt("console");
#elif QP_PLATFORM == PLATFORM_FREEBSD
const std::shared_ptr<spd::logger> console = spdlog::stdout_logger_mt("console");
#elif QP_PLATFORM == PLATFORM_CYGWIN
const std::shared_ptr<spd::logger> console = spdlog::stdout_logger_mt("console");
#endif


/// @}
