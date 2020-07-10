/**
 * platform.cpp - Platform specific code
 */ 
#include "platformspec.h"
#include "common/port.h"

#ifndef _WIN32 
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>
#else
#include <windows.h>
#endif 

using namespace platform;

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
	#error Implement me
#endif 
}

unsigned long long platform::GetCurrentThreadId()
{
#ifndef _WIN32
	return (unsigned long long)pthread_self();
#else
	#error Implement me
#endif 
}