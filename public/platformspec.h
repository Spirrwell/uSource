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
}