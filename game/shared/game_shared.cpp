/**
 * 
 * Functions and definitions shared between the client and server
 * 
 */ 

// this needs to be included early here
// otherwise you get a bunch of stupid syntax errors from this later
#include <cmath>

#include "game_shared.h"

#include "public/appframework.h"
#include "tier1/tier1.h"
#include "tier1/convar.h"
#include "tier1/concommand.h"
#include "networksystem/networksystem.h"

void GameSharedInit() 
{
	/* Load our global interfaces from the engine */
	tier1::Connect();

	/* Lod the networksystem libraries */
	ConnectNetsystemLibraries();

	/* Init networksystem */
	NetworksystemInit();
}