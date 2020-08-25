/*
 *
 * logger.h - Fallback logging system for use during game startup/shutdown periods when the engine's logger is not available
 *
 */
#pragma once

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
	void Printf(const char* fmt, ...);
	void Errorf(const char* fmt, ...);
	void Warnf(const char* fmt, ...);
}