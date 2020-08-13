/**
 * dbg.h
 *
 * Common debug functions
 */
#pragma once

#include "tier1.h"

const char* _vpaste(const char* fmt, ...);

#undef Assert
#undef AssertMsg
#undef AssertM
#undef AssertF
#undef AssertFMsg
#undef Msg
#undef Warn
#undef Error
#undef FatalError
#undef MsgC

#ifdef _DEBUG
#define AssertM(_x)                                                                                                                                  \
	if (!(_x))                                                                                                                                   \
	{                                                                                                                                            \
		if (g_pLogSystem)                                                                                                                    \
			g_pLogSystem->Log(LOGCHAN_ERROR, LOGVERBO_HIGHEST, _vpaste("Assertion failed: %s %s:%u\n", #_x, __FILE__, __LINE__));        \
		else                                                                                                                                 \
		{                                                                                                                                    \
			printf("Assertion failed: %s %s: %u\n", #_x, __FILE__, __LINE__);                                                            \
		}                                                                                                                                    \
	}

#define Assert(_x)                                                                                                                                   \
	{                                                                                                                                            \
		if (g_pEngineDebug)                                                                                                                  \
			g_pEngineDebug->AssertFunction((_x), #_x, __FILE__, __LINE__, "");                                                           \
		else                                                                                                                                 \
		{                                                                                                                                    \
			if (!(_x))                                                                                                                   \
				printf("Assertion failed: %s %s: %u\n", #_x, __FILE__, __LINE__);                                                    \
		}                                                                                                                                    \
	}
#define AssertMsg(_x, ...)                                                                                                                           \
	{                                                                                                                                            \
		if (g_pEngineDebug)                                                                                                                  \
			g_pEngineDebug->AssertFunction((_x), #_x, __FILE__, __LINE__, _vpaste(__VA_ARGS__));                                         \
		else                                                                                                                                 \
		{                                                                                                                                    \
			if (!(_x))                                                                                                                   \
				printf("Assertion failed: %s %s: %u\n", #_x, __FILE__, __LINE__);                                                    \
		}                                                                                                                                    \
	}
#else
#define AssertM(_x)
#define Assert(_x)
#define AssertMsg(_x, ...)
#endif

/* Absolutely fatal assertions regardless of debug build status */
#define AssertF(_x)                                                                                                                                  \
	if (!(_x))                                                                                                                                   \
	{                                                                                                                                            \
		if (g_pEngineDebug)                                                                                                                  \
			g_pEngineDebug->HostError(_vpaste("Assertion failed: %s %s:%u", #_x, __FILE__, __LINE__));                                   \
		else                                                                                                                                 \
		{                                                                                                                                    \
			printf("Assertion failed: %s: %s:%u\n", #_x, __FILE__, __LINE__);                                                            \
			abort();                                                                                                                     \
		}                                                                                                                                    \
	}

#define AssertFMsg(_x, ...)                                                                                                                          \
	if (!(_x))                                                                                                                                   \
	{                                                                                                                                            \
		if (g_pLogSystem)                                                                                                                    \
			g_pLogSystem->Log(LOGCHAN_ERROR, LOGVERBO_HIGHEST, _vpaste("Assertion failed: %s %s:%u\n", #_x, __FILE__, __LINE__));        \
		else                                                                                                                                 \
			printf("Assertion failed: %s %s:%u\n", #_x, __FILE__, __LINE__);                                                             \
		if (g_pEngineDebug)                                                                                                                  \
			g_pEngineDebug->HostError(_vpaste(__VA_ARGS__));                                                                             \
		else                                                                                                                                 \
			abort();                                                                                                                     \
	}

void Msg(const char* fmt, ...);
void Warn(const char* fmt, ...);
void Error(const char* fmt, ...);
void FatalError(const char* fmt, ...);
void MsgC(const char color[3], const char* fmt, ...);
