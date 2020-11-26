/**
 * Commands for the server
 */ 
#include "public/appframework.h"
#include "tier1/tier1.h"
#include "tier1/convar.h"
#include "tier1/concommand.h"

#include "game_shared.h"
#include "c_base_entity.h"

CONCOMMAND(ent_create, "Creates an entity", FCVAR_CHEAT)
{
	if(argc < 2) return;
	CBaseEntity* player = UTIL_PlayerByIndex(1);
	if(!player) return;
	CBaseEntity::Create(argv[1], player->Center(), Vector(0,0,0), player->edict());
}