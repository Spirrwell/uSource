/**
 * 
 * tier1
 * 	Helper library for engine users
 *
 */ 
#pragma once 

#include "engine_int.h"
#include "log_int.h"

extern IEngineCvar* g_pEngineCvar;
extern ILogSystem* g_pLogSystem;
extern IEngineDebug* g_pEngineDebug;

namespace tier1
{
	void Connect();
}