/*
 *
 * base_entity.cpp - Stubs and basic implementation of base entity stuff
 *
 */
#include "base_entity.h"

#ifndef CLIENT_DLL
#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "saverestore.h"
#include "info_node.h"
#include "func_door.h"
#include "saverestore.h"
#include "game/server/ai/ai_schedule.h"
#ifndef MONSTEREVENT_H
#include "game/server/ai/ai_monsterevent.h"
#endif

#endif

void CBaseEntity::Killed( entvars_t *pevAttacker, int iGib )
{
#ifndef CLIENT_DLL
	pev->takedamage = DAMAGE_NO;
	pev->deadflag = DEAD_DEAD;
	UTIL_Remove( this );
#endif
}

CBaseEntity *CBaseEntity::GetNextTarget( void )
{
#ifndef CLIENT_DLL
	if( FStringNull( pev->target ) )
		return NULL;
	edict_t *pTarget = FIND_ENTITY_BY_TARGETNAME( NULL, STRING( pev->target ) );
	if( FNullEnt( pTarget ) )
		return NULL;

	return Instance( pTarget );
#else
	return nullptr;
#endif
}