/**
 * platform.cpp - Platform specific code
 */ 
#include "platformspec.h"
#include "common/port.h"
#include "containers/list.h"

#include <stdlib.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef _WIN32 
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>
#else
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#endif 

using namespace platform;

#undef GetCurrentTime
platform::time_t platform::GetCurrentTime()
{
#ifndef _WIN32
	timespec time; 
	clock_gettime(CLOCK_REALTIME, &time);
	platform::time_t _time;
	_time.ns = time.tv_nsec;
	_time.sec = time.tv_sec;
	return _time;
#else
	LARGE_INTEGER time;
	if(QueryPerformanceCounter(&time))
	{
		LARGE_INTEGER	 freq;
		QueryPerformanceFrequency(&freq);
		platform::time_t outtime;
		outtime.sec = time.QuadPart / freq.QuadPart;
		outtime.ns  = time.QuadPart - ((time.QuadPart / freq.QuadPart) * freq.QuadPart);
		return outtime;
	}
	return platform::time_t();
#endif 
}

unsigned long long platform::GetCurrentThreadId()
{
#ifndef _WIN32
	return (unsigned long long)pthread_self();
#else
	return ::GetCurrentThreadId();
#endif 
}

typedef void(*fnFatalHook_t)(const char*);
List<fnFatalHook_t> g_fatal_hooks;

void platform::HookFatalError(void (*fnHook)(const char *))
{
	g_fatal_hooks.push_back(fnHook);
}

void platform::FatalError(const char *fmt, ...)
{
	char tmp[4096];
	va_list va;
	va_start(va, fmt);
	vsnprintf(tmp, sizeof(tmp), fmt, va);
	va_end(va);
	for(auto x : g_fatal_hooks)
		x(tmp);
	fprintf(stderr, "%s", tmp);
	abort();
}

bool platform::time_t::operator<(const platform::time_t &other) const
{
	return (this->sec < other.sec) || (this->sec == other.sec && this->ns < other.ns);
}

bool platform::time_t::operator<=(const platform::time_t &other) const
{
	return (this->sec <= other.sec) || (this->sec == other.sec && this->ns <= other.ns);
}

bool platform::time_t::operator>(const platform::time_t &other) const
{
	return (this->sec > other.sec) || (this->sec == other.sec && this->ns > other.ns);
}

bool platform::time_t::operator>=(const platform::time_t &other) const
{
	return (this->sec >= other.sec) || (this->sec == other.sec && this->ns >= other.ns);
}

bool platform::time_t::operator==(const platform::time_t &other) const
{
	return (this->sec == other.sec) && (this->ns == other.ns);
}

bool platform::time_t::operator!=(const platform::time_t &other) const
{
	return (this->sec != other.sec) || (this->ns != other.ns);
}
