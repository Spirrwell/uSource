/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/
//
//  cl_dll.h
//

// 4-23-98  JOHN

//
//  This DLL is linked by the client when they first initialize.
// This DLL is responsible for the following tasks:
//		- Loading the HUD graphics upon initialization
//		- Drawing the HUD graphics every frame
//		- Handling the custum HUD-update packets
//
#pragma once
#ifndef CL_DLL_H
#define CL_DLL_H
typedef unsigned char byte;
typedef unsigned short word;
typedef float vec_t;
typedef int ( *pfnUserMsgHook )( const char *pszName, int iSize, void *pbuf );

#include "util_vector.h"

#include "client_int.h"
#include "cdll_dll.h"

#ifndef __MSC_VER
#define _cdecl
#endif
#include "exportdef.h"
#include <string.h>

#if defined(__LP64__) || defined(__LLP64__) || defined(_WIN64) || (defined(__x86_64__) && !defined(__ILP32__) ) || defined(_M_X64) || defined(__ia64) || defined (_M_IA64) || defined(__aarch64__) || defined(__powerpc64__)
	#undef XASH_64BIT 	
	#define XASH_64BIT
#endif

/* Various interfaces */
#include "net_int.h"
#include "efx_int.h"
#include "event_int.h"
#include "demo_int.h"

extern IEngineDemo* g_pDemoAPI;
extern IEngineEvents* g_pEventAPI;
extern IEngineEfx* g_pEfxAPI;
extern IEngineNetAPI* g_pNetAPI;

extern cl_enginefunc_t gEngfuncs;
#include "../engine/mobility_int.h"
extern mobile_engfuncs_t *gMobileEngfuncs;
#endif
