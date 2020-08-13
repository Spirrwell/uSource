/**
 *
 * platformspec.h - Platform specific code
 *
 */
#pragma once

namespace platform
{
struct time_t
{
	unsigned long long sec;
	unsigned long long ns;

	unsigned long long to_ns() const { return ns + (sec * 1000000000); };
};

time_t GetCurrentTime();

unsigned long long GetCurrentThreadId();

/* Allows the engine to hook basic printing and error functions for log to console operations */
void HookFatalError(void (*fnHook)(const char*));

/* Fatal error function */
void FatalError(const char* fmt, ...);
} // namespace platform