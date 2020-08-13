/**
 *
 * Functions and definitions shared between the client and server
 *
 */
#pragma once

#define NO_VECTOR_FUNCTIONS
#include "mathlib/mathlib.h"

#include "engine_int.h"
#include "log_int.h"
#include "public/appframework.h"
#include "tier1/tier1.h"

#include "base_defs.h"
#include "cdll_dll.h"
#include "common.h"
#include "extdll.h"

#ifdef CLIENT_DLL
#include "cl_dll.h"
#include "cl_util.h"
#include "hud.h"
#include "hud_iface.h"
#include "util_vector.h"
#else
#include "cbase.h"
#include "progdefs.h"
#include "util.h"
#include "vector.h"
#endif

/* Called to initialize the shared stuff */
extern void GameSharedInit();