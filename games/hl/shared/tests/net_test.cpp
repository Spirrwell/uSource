#include "common.h"
#include "tier1/concommand.h"
#include "tier1/convar.h"
#include "tier1/dbg.h"
#include "networksystem/networksystem.h"

#ifdef CLIENT_DLL
#include "hud.h"
#include "cl_dll.h"
#include "cl_util.h"

CONCOMMAND(cl_net_test, "Client network test", FCVAR_DEV)
{
	CNetworkMessage msg(4);
	msg.WriteInt(42069);
	NetworkSystem::SendToServer(201, msg);
}

HANDLE_SERVER_USERMESSAGE(201, recv_201)
{
	Msg("Received 201\n");
	Msg("\tData: %u\n", msg.ReadInt());
}

#else

CONCOMMAND(sv_net_test, "Server network test", FCVAR_DEV)
{

}

HANDLE_CLIENT_USERMESSAGE(201, recv_201)
{
	Msg("Received 201\n");
	Msg("\tData: %u\n", msg.ReadInt());
}

#endif