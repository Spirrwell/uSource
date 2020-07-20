#include "appframework.h"
#include "networksystem.h"

IEngineNetsystem* g_pNetworkSystem;

void ConnectNetsystemLibraries()
{
	g_pNetworkSystem = static_cast<IEngineNetsystem*>(AppFramework::FindInterface(INETSYSTEM_INTERFACE));
}