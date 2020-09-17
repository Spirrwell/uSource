/*
 *
 * logger.h - Fallback logging system for use during game startup/shutdown periods when the engine's logger is not available
 *
 */
#pragma once

#include "common.h"

#define COLOR_NORMAL "^1"
#define COLOR_RED "^2"
#define COLOR_GREEN "^3"
#define COLOR_BLUE "^4"
#define COLOR_PURPLE "^5"
#define COLOR_YELLOW "^6"
#define COLOR_BOLD "^7"
#define COLOR_STRIKE "^8"

namespace logger
{
	EXPORT void Printf(const char* fmt, ...);
	EXPORT void Errorf(const char* fmt, ...);
	EXPORT void Warnf(const char* fmt, ...);
}
