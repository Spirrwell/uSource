/**
 * dbg.h
 * 
 * Common debug functions
 */ 
#pragma once 

#include "tier1.h"

/* From libpublic */
#include "logger.h"
#include "debug.h"

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

#define _AssertM(_x, _exp, _msg) \
do {                 \
           if(!(_x)) {           \
                if(!dbg::FireAssertion(__FILE__, __LINE__, _exp)) break;                 \
                if(g_pLogSystem){ \
                        g_pLogSystem->Log(LOGCHAN_ERROR, LOGVERBO_HIGHEST, _msg);     \
                } else {         \
                        logger::Errorf(_msg); \
                }          \
           }         \
} while(0)

#ifdef _DEBUG

#define Assert(_x) _AssertM(_x, #_x, _vpaste("Assertion failed: %s %s: %u\n", #_x, __FILE__, __LINE__))
#define AssertMsg(_x, ...) _AssertM(_x, #_x, _vpaste(__VA_ARGS__))

#else
#define Assert(_x)
#define AssertMsg(_x, ...)
#endif 

/* Absolutely fatal assertions regardless of debug build status */
#define AssertF(_x) if(!(_x)) { \
if(g_pEngineDebug) g_pEngineDebug->HostError(_vpaste("Assertion failed: %s %s:%u", #_x, __FILE__, __LINE__)); \
else { \
	printf("Assertion failed: %s: %s:%u\n", #_x, __FILE__, __LINE__); \
	abort(); \
}}

#define AssertFMsg(_x, ...) if(!(_x)) { \
	if(g_pLogSystem) g_pLogSystem->Log(LOGCHAN_ERROR, LOGVERBO_HIGHEST, _vpaste("Assertion failed: %s %s:%u\n", #_x, __FILE__, __LINE__));\
	else printf("Assertion failed: %s %s:%u\n", #_x, __FILE__, __LINE__); \
	if(g_pEngineDebug) g_pEngineDebug->HostError(_vpaste(__VA_ARGS__)); \
	else abort();}

void Msg(const char* fmt, ...);
void Warn(const char* fmt, ...);
void Error(const char* fmt, ...);
void FatalError(const char* fmt, ...);
void MsgC(const char color[3], const char* fmt, ...);
