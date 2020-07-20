/*
 *
 * entity_system.cpp - Implementation of the entity subsystem
 *
 */
#include "netvar.h"

#include "public/containers/array.h"
#include "public/containers/list.h"
#include "public/static_helpers.h"

#ifdef CLIENT_DLL
// #include "cl_dll.h"
// #include "cl_util.h"
#else

#endif

using namespace NetvarSystem;

bool g_bNetvarInit = false;

void InitNetvarSystem_Client();

void NetvarSystem::InitNetvarSystem()
{
	InitNetvarSystem_Client();
	g_bNetvarInit = true;
}



int NetvarSystem_MessageHook(const char *pszName, int iSize, void *pbuf)
{
	return 0;
}

void InitNetvarSystem_Client()
{
#ifdef CLIENT_DLL
	// gEngfuncs.pfnHookUserMsg("netvar_update", NetvarSystem_MessageHook);
#endif
}