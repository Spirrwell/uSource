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
#include "common.h"
#include "crtlib.h"
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

void platform::FatalError(const char *fmt, ...)
{
	char tmp[4096];
	va_list va;
	va_start(va, fmt);
	vsnprintf(tmp, sizeof(tmp), fmt, va);
	va_end(va);
	fprintf(stderr, "%s", tmp);
	abort();
}

int Win32_ExecProgram(const char *prog, const char *args, const char **env)
{
#ifdef _WIN32
	STARTUPINFO info = {sizeof(info)};
	PROCESS_INFORMATION pinfo;
	if(CreateProcessA(prog, (LPSTR)args, NULL, NULL, TRUE, 0, env, NULL, &info, &pinfo))
	{
		DWORD exitCode = WaitForSingleObject(pinfo.hProcess, INFINITE);
		CloseHandle(pinfo.hProcess);
		CloseHandle(pinfo.hThread);
		return exitCode;
	}
	return -1;
#endif
	return 0;
}

int platform::ExecProgram(const char *prog, char *const *args, const char **env)
{
#ifdef _WIN32
	char cmdline[8192];
	cmdline[0] = 0;
	for(int i = 0; args[i]; i++)
		Q_strncat(cmdline, args[i], sizeof(cmdline));
	return Win32_ExecProgram(prog, cmdline, env);
#else
	return execve(prog, args, const_cast<char *const *>(env));
#endif
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
