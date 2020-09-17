#include "common/common.h"
#include "common.h"
#include "rcs.h"
#include "tier1/tier1.h"
#include "tier1/convar.h"
#include "tier1/concommand.h"
#include "common/cvar.h"
#include "public/platformspec.h"
#include "public/cmdline.h"

#undef IMPORT

#include <google/protobuf/service.h>

#include "common.pb.h"

using namespace google::protobuf;

#define TOKEN_LENGTH 16

Convar rcs_enabled("rcs_enabled", "0", 0, "If set to 1, the RCS is enabled");
Convar rcs_require_auth("rcs_require_auth", "0", FCVAR_ARCHIVE, "If set to 1, incoming connections must use an auth token");
Convar rcs_token("rcs_token", "0", FCVAR_PROTECTED | FCVAR_READ_ONLY);
Convar rcs_protocol_version("rcs_protocol_version", "1", FCVAR_PROTECTED | FCVAR_READ_ONLY);

bool g_bRcsConnected = false;


/* Forward decls */
static void NewRCSToken();
class CRcsService;


CONCOMMAND(rcs_new_token, "Generate a new RCS token", 0)
{
	NewRCSToken();
}

void rcs::Init()
{
	/* Start by generating a new RCS token */
	NewRCSToken();

	/* If running with -tools, enable RCS */
	if(GlobalCommandLine().Find("-tools"))
		rcs_enabled.SetInt(1);


}


//------------------------------------------------------------------------------------------------------------------------//
// RpcController Implementation
class CRpcController : public google::protobuf::RpcController
{
public:

};
//------------------------------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------------------------------//
// RpcChannel implementation
class CRpcChannel : public google::protobuf::RpcChannel
{
public:
};



//------------------------------------------------------------------------------------------------------------------------//
// Primary RCS Service
class CRcsService : public rcs::RCSService
{
public:
	virtual void Connect(RpcController* controller, const rcs::ConnectRequest* req,
		      rcs::ConnectResponse* resp, Closure* done)
	{
		if(req->token() == rcs_token.GetString() && req->protocol_version() == RCS_PROTOCOL_VERSION)
		{
			resp->set_connected(true);
			g_bRcsConnected = true;
			NewRCSToken(); // Generate a new token as soon as we connect
		}
		else
		{
			resp->set_connected(false);
			resp->set_reason(req->token() != rcs_token.GetString() ? rcs::ConnectionFailureReason::BAD_TOKEN : rcs::ConnectionFailureReason::WRONG_VERSION);
		}
		resp->set_protocol_version(RCS_PROTOCOL_VERSION);
		done->Run();
	}
};
//------------------------------------------------------------------------------------------------------------------------//




static char g_TokenTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvxyz0123456789#$%&";

static void NewRCSToken()
{
	srand(platform::GetCurrentTime().sec + platform::GetCurrentTime().ns);
	char token[TOKEN_LENGTH+1];
	for(int i = 0; i < TOKEN_LENGTH; i++)
		token[i] = g_TokenTable[rand() % sizeof(g_TokenTable)];
	token[TOKEN_LENGTH] = 0;
	Cvar_DirectSet(Cvar_FindVar("rcs_token"), token, true);
}