/**
 * 
 * Functions and definitions shared between the client and server
 * 
 */ 
#pragma once

#define NO_VECTOR_FUNCTIONS
#include "mathlib/mathlib.h"

#include "public/appframework.h"
#include "engine_int.h"
#include "log_int.h"
#include "tier1/tier1.h"

#include "common.h"
#include "cdll_dll.h"
#include "base_defs.h"
#include "extdll.h"

#ifdef CLIENT_DLL
#include "util_vector.h"
#include "cl_dll.h"
#include "hud.h"
#include "cl_util.h"
#include "hud_iface.h"
#else
#include "util.h"
#include "vector.h"
#include "progdefs.h"
#include "cbase.h"
#endif

/* Called to initialize the shared stuff */
extern void GameSharedInit();