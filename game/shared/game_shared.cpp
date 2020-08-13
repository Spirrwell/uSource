/**
 *
 * Functions and definitions shared between the client and server
 *
 */

#include "game_shared.h"

#include "networksystem/networksystem.h"
#include "public/appframework.h"
#include "tier1/concommand.h"
#include "tier1/convar.h"
#include "tier1/tier1.h"

void GameSharedInit()
{
	/* Load our global interfaces from the engine */
	ConnectTier1Libraries();

	/* Lod the networksystem libraries */
	ConnectNetsystemLibraries();

	/* Init networksystem */
	NetworksystemInit();

#ifdef CLIENT_DLL
	NetworksystemInit_Client();
#else
	NetworksystemInit_Server();
#endif
}

#ifdef CLIENT_DLL
CONCOMMAND(CL_SendServerCommand, "Sends a server a test command", 0) { NetworkSystem::SendToServer(100, CNetworkMessage()); }

CClientUserMessageHook __cl_testhook(10, [](const CNetworkMessage& msg) { printf("%u\n", msg.ReadInt()); });
#else

CONCOMMAND(SV_SendTestCommand, "Sends a test command", 0)
{
	CNetworkMessage msg(4);
	msg.InitStorage();
	msg.WriteInt(69);
	NetworkSystem::SendToClient(10, UTIL_PlayerByIndex(1)->edict(), msg);
}

#endif