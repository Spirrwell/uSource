//========= Copyright (c) 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose:
//
// $NoKeywords: $
//=============================================================================

#pragma once
#if !defined(HUD_IFACEH)
#define HUD_IFACEH

#include "exportdef.h"

typedef int (*pfnUserMsgHook)(const char* pszName, int iSize, void* pbuf);
#include "../engine/client_int.h"
#include "wrect.h"
extern cl_enginefunc_t gEngfuncs;
#endif
