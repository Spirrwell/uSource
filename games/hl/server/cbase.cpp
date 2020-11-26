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

#include	"extdll.h"
#include	"util.h"
#include	"cbase.h"
#include	"saverestore.h"
#include	"client.h"
#include	"decals.h"
#include	"gamerules.h"
#include	"game.h"
#include	"engine/server_int.h"
#include	"game_shared.h"

void EntvarsKeyvalue( entvars_t *pev, KeyValueData *pkvd );

void PM_Move ( struct playermove_s *ppmove, int server );
void PM_Init ( struct playermove_s *ppmove  );
char PM_FindTextureType( char *name );

extern Vector VecBModelOrigin( entvars_t* pevBModel );
extern DLL_GLOBAL Vector g_vecAttackDir;
extern DLL_GLOBAL int g_iSkillLevel;

class CServerInterface : public IServerInterface
{
public:
	virtual const char* GetParentInterface() { return ISERVER_INTERFACE; };

	virtual const char* GetName() { return "CHL1Server001"; }

	virtual bool PreInit() { return true; }

	virtual bool Init() { return true; }

	virtual void Shutdown() { };

	virtual void	GameInit( void )
	{
		::GameDLLInit();
	}	

	virtual int	Spawn( edict_t *pent )
	{
		return ::DispatchSpawn(pent);
	}
	
	virtual void	Think( edict_t *pent )
	{
		::DispatchThink(pent);
	} 

	virtual void	Use( edict_t *pentUsed, edict_t *pentOther )
	{
		::DispatchUse(pentUsed, pentOther);
	}
	
	virtual void	Touch( edict_t *pentTouched, edict_t *pentOther )
	{
		::DispatchTouch(pentTouched, pentOther);
	}
	
	virtual void	Blocked( edict_t *pentBlocked, edict_t *pentOther )
	{
		::DispatchBlocked(pentBlocked, pentOther);
	}

	virtual void	KeyValue( edict_t *pentKeyvalue, KeyValueData *pkvd )
	{
		::DispatchKeyValue(pentKeyvalue, pkvd);
	}
	
	virtual void	Save( edict_t *pent, SAVERESTOREDATA *pSaveData )
	{
		::DispatchSave(pent, pSaveData);
	} 

	virtual int 	Restore( edict_t *pent, SAVERESTOREDATA *pSaveData, int globalEntity )
	{
		return ::DispatchRestore(pent, pSaveData, globalEntity);
	}

	virtual void	SetAbsBox( edict_t *pent )
	{
		::DispatchObjectCollsionBox(pent);
	}
 
	virtual void	SaveWriteFields( SAVERESTOREDATA* pSaveData, const char* pname, void* pBaseData, TYPEDESCRIPTION* pFields, int cnt )
	{
		::SaveWriteFields(pSaveData, pname, pBaseData, pFields, cnt);
	}

	virtual void	SaveReadFields( SAVERESTOREDATA* data, const char* c, void* v, TYPEDESCRIPTION* pFields, int cnt)
	{
		::SaveReadFields(data, c, v, pFields, cnt);
	}
	
	virtual void	SaveGlobalState( SAVERESTOREDATA * data )
	{
		::SaveGlobalState(data);
	}
	
	virtual void	RestoreGlobalState( SAVERESTOREDATA * data )
	{
		::RestoreGlobalState(data);
	}
	
	virtual void	ResetGlobalState( void )
	{
		::ResetGlobalState();
	}
 
	virtual qboolean	ClientConnect( edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[128] )
	{
		return ::ClientConnect(pEntity, pszName, pszAddress, szRejectReason);
	}

	virtual void	ClientDisconnect( edict_t *pEntity )
	{
		::ClientDisconnect(pEntity);
	}
	
	virtual void	ClientKill( edict_t *pEntity )
	{
		::ClientKill(pEntity);
	}
	
	virtual void	ClientPutInServer( edict_t *pEntity )
	{
		::ClientPutInServer(pEntity);
	}
	
	virtual void	ClientCommand( edict_t *pEntity )
	{
		::ClientCommand(pEntity);
	} 

	virtual void	ClientUserInfoChanged( edict_t *pEntity, char *infobuffer )
	{
		::ClientUserInfoChanged(pEntity, infobuffer);
	}
	
	virtual void	ServerActivate( edict_t *pEdictList, int edictCount, int clientMax )
	{
		::ServerActivate(pEdictList, edictCount, clientMax);
	}
	
	virtual void	ServerDeactivate( void )
	{
		::ServerDeactivate();
	} 

	virtual void	PlayerPreThink( edict_t *pEntity )
	{
		::PlayerPreThink(pEntity);
	}
	
	virtual void	PlayerPostThink( edict_t *pEntity )
	{
		::PlayerPostThink(pEntity);
	}

	virtual void	StartFrame( void )
	{
		::StartFrame();
	}
	
	virtual void	ParmsNewLevel( void )
	{
		::ParmsNewLevel();
	} 

	virtual void	ParmsChangeLevel( void )
	{
		::ParmsChangeLevel();
	}
 
	// Returns string describing current .dll.  E.g., TeamFotrress 2, Half-Life
	virtual const char     *GetGameDescription( void ) 
	{
		return ::GetGameDescription();
	}


	// Notify dll about a player customization.
	virtual void	PlayerCustomization( edict_t *pEntity, customization_t *pCustom )
	{
		::PlayerCustomization(pEntity, pCustom);
	}

	virtual void	SpectatorConnect( edict_t *pEntity )
	{
		::SpectatorConnect(pEntity);
	}
	
	virtual void	SpectatorDisconnect( edict_t *pEntity )
	{
		::SpectatorDisconnect(pEntity);
	}

	virtual void	SpectatorThink( edict_t *pEntity ) 
	{
		::SpectatorThink(pEntity);
	}

	// Notify game .dll that engine is going to shut down. Allows mod authors to set a breakpoint.
	virtual void	Sys_Error( const char *error_string )
	{
		::Sys_Error(error_string);
	}

	virtual void	PM_Move( struct playermove_s *ppmove, qboolean server )
	{
		::PM_Move(ppmove, server);
	}
	
	virtual void	PM_Init( struct playermove_s *ppmove )
	{
		::PM_Init(ppmove);
	}

	virtual char	PM_FindTextureType( char *name )
	{
		return ::PM_FindTextureType(name);
	}
	
	virtual void	SetupVisibility( struct edict_s *pViewEntity, struct edict_s *pClient, unsigned char **pvs, unsigned char **pas )
	{
		::SetupVisibility(pViewEntity, pClient, pvs, pas);
	}

	virtual void	UpdateClientData( const struct edict_s *ent, int sendweapons, struct clientdata_s *cd )
	{
		::UpdateClientData(ent, sendweapons, cd);
	}

	virtual int	AddToFullPack( struct entity_state_s *state, int e, edict_t *ent, edict_t *host, int hostflags, int player, unsigned char *pSet )
	{
		return ::AddToFullPack(state, e, ent, host, hostflags, player, pSet);
	}

	virtual void	CreateBaseline( int player, int eindex, struct entity_state_s *baseline, struct edict_s *entity, int playermodelindex, float* player_mins, float* player_maxs ) 
	{
		::CreateBaseline(player, eindex, baseline, entity, playermodelindex, player_mins, player_maxs);
	}

	virtual void	RegisterEncoders( void )
	{
		::RegisterEncoders();
	} 

	virtual int	GetWeaponData( struct edict_s *player, struct weapon_data_s *info )
	{
		return ::GetWeaponData(player, info);
	}
 
	virtual void	CmdStart( const edict_t *player, const struct usercmd_s *cmd, unsigned int random_seed )
	{
		::CmdStart(player, cmd, random_seed);
	}

	virtual void	CmdEnd( const edict_t *player )
	{
		::CmdEnd(player);
	}

	virtual int	ConnectionlessPacket ( const struct netadr_s *net_from, const char *args, char *response_buffer, int *response_buffer_size )
	{
		return ::ConnectionlessPacket(net_from, args, response_buffer, response_buffer_size);
	}

	virtual int	GetHullBounds( int hullnumber, float *mins, float *maxs )
	{
		return ::GetHullBounds(hullnumber, mins, maxs);
	}
 
	virtual void	CreateInstancedBaselines ( void )
	{
		::CreateInstancedBaselines();
	}

	virtual int	InconsistentFile( const struct edict_s *player, const char *filename, char *disconnect_message )
	{
		return ::InconsistentFile(player, filename, disconnect_message);
	}
 
	virtual int	AllowLagCompensation( void )
	{
		return ::AllowLagCompensation();
	}
}; 

EXPOSE_INTERFACE(CServerInterface);
MODULE_INTERFACE_IMPL();

static void SetObjectCollisionBox( entvars_t *pev );

int DispatchSpawn( edict_t *pent )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE( pent );

	if( pEntity )
	{
		// Initialize these or entities who don't link to the world won't have anything in here
		pEntity->pev->absmin = pEntity->pev->origin - Vector( 1, 1, 1 );
		pEntity->pev->absmax = pEntity->pev->origin + Vector( 1, 1, 1 );

		pEntity->Spawn();

		// Try to get the pointer again, in case the spawn function deleted the entity.
		// UNDONE: Spawn() should really return a code to ask that the entity be deleted, but
		// that would touch too much code for me to do that right now.
		pEntity = (CBaseEntity *)GET_PRIVATE( pent );

		if( pEntity )
		{
			if( g_pGameRules && !g_pGameRules->IsAllowedToSpawn( pEntity ) )
				return -1;	// return that this entity should be deleted
			if( pEntity->pev->flags & FL_KILLME )
				return -1;
		}

		// Handle global stuff here
		if( pEntity && pEntity->pev->globalname ) 
		{
			const globalentity_t *pGlobal = gGlobalState.EntityFromTable( pEntity->pev->globalname );
			if( pGlobal )
			{
				// Already dead? delete
				if( pGlobal->state == GLOBAL_DEAD )
					return -1;
				else if( !FStrEq( STRING( gpGlobals->mapname ), pGlobal->levelName ) )
					pEntity->MakeDormant();	// Hasn't been moved to this level yet, wait but stay alive
				// In this level & not dead, continue on as normal
			}
			else
			{
				// Spawned entities default to 'On'
				gGlobalState.EntityAdd( pEntity->pev->globalname, gpGlobals->mapname, GLOBAL_ON );
				//ALERT( at_console, "Added global entity %s (%s)\n", STRING( pEntity->pev->classname ), STRING( pEntity->pev->globalname ) );
			}
		}

	}

	return 0;
}

void DispatchKeyValue( edict_t *pentKeyvalue, KeyValueData *pkvd )
{
	if( !pkvd || !pentKeyvalue )
		return;

	EntvarsKeyvalue( VARS( pentKeyvalue ), pkvd );

	// If the key was an entity variable, or there's no class set yet, don't look for the object, it may
	// not exist yet.
	if ( pkvd->fHandled || pkvd->szClassName == NULL )
		return;

	// Get the actualy entity object
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE( pentKeyvalue );

	if( !pEntity )
		return;

	pEntity->KeyValue( pkvd );
}

// HACKHACK -- this is a hack to keep the node graph entity from "touching" things (like triggers)
// while it builds the graph
BOOL gTouchDisabled = FALSE;

void DispatchTouch( edict_t *pentTouched, edict_t *pentOther )
{
	if( gTouchDisabled )
		return;

	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE( pentTouched );
	CBaseEntity *pOther = (CBaseEntity *)GET_PRIVATE( pentOther );

	if( pEntity && pOther && ! ( ( pEntity->pev->flags | pOther->pev->flags ) & FL_KILLME ) )
		pEntity->Touch( pOther );
}

void DispatchUse( edict_t *pentUsed, edict_t *pentOther )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE( pentUsed );
	CBaseEntity *pOther = (CBaseEntity *)GET_PRIVATE( pentOther );

	if( pEntity && !( pEntity->pev->flags & FL_KILLME ) )
		pEntity->Use( pOther, pOther, USE_TOGGLE, 0 );
}

void DispatchThink( edict_t *pent )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE( pent );
	if( pEntity )
	{
		if( FBitSet( pEntity->pev->flags, FL_DORMANT ) )
			ALERT( at_error, "Dormant entity %s is thinking!!\n", STRING( pEntity->pev->classname ) );

		pEntity->Think();
	}
}

void DispatchBlocked( edict_t *pentBlocked, edict_t *pentOther )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE( pentBlocked );
	CBaseEntity *pOther = (CBaseEntity *)GET_PRIVATE( pentOther );

	if( pEntity )
		pEntity->Blocked( pOther );
}

void DispatchSave( edict_t *pent, SAVERESTOREDATA *pSaveData )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE( pent );

	if( pEntity && pSaveData )
	{
		ENTITYTABLE *pTable = &pSaveData->pTable[pSaveData->currentIndex];

		if( pTable->pent != pent )
			ALERT( at_error, "ENTITY TABLE OR INDEX IS WRONG!!!!\n" );

		if( pEntity->ObjectCaps() & FCAP_DONT_SAVE )
			return;

		// These don't use ltime & nextthink as times really, but we'll fudge around it.
		if( pEntity->pev->movetype == MOVETYPE_PUSH )
		{
			float delta = pEntity->pev->nextthink - pEntity->pev->ltime;
			pEntity->pev->ltime = gpGlobals->time;
			pEntity->pev->nextthink = pEntity->pev->ltime + delta;
		}

		pTable->location = pSaveData->size;		// Remember entity position for file I/O
		pTable->classname = pEntity->pev->classname;	// Remember entity class for respawn

		CSave saveHelper( pSaveData );
		pEntity->Save( saveHelper );

		pTable->size = pSaveData->size - pTable->location;	// Size of entity block is data size written to block
	}
}

// Find the matching global entity.  Spit out an error if the designer made entities of
// different classes with the same global name
CBaseEntity *FindGlobalEntity( string_t classname, string_t globalname )
{
	edict_t *pent = FIND_ENTITY_BY_STRING( NULL, "globalname", STRING( globalname ) );
	CBaseEntity *pReturn = CBaseEntity::Instance( pent );
	if( pReturn )
	{
		if( !FClassnameIs( pReturn->pev, STRING( classname ) ) )
		{
			ALERT( at_console, "Global entity found %s, wrong class %s\n", STRING( globalname ), STRING( pReturn->pev->classname ) );
			pReturn = NULL;
		}
	}

	return pReturn;
}

int DispatchRestore( edict_t *pent, SAVERESTOREDATA *pSaveData, int globalEntity )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE( pent );

	if( pEntity && pSaveData )
	{
		entvars_t tmpVars;
		Vector oldOffset;

		CRestore restoreHelper( pSaveData );
		if( globalEntity )
		{
			CRestore tmpRestore( pSaveData );
			tmpRestore.PrecacheMode( 0 );
			tmpRestore.ReadEntVars( "ENTVARS", &tmpVars );

			// HACKHACK - reset the save pointers, we're going to restore for real this time
			pSaveData->size = pSaveData->pTable[pSaveData->currentIndex].location;
			pSaveData->pCurrentData = pSaveData->pBaseData + pSaveData->size;
			// -------------------

			const globalentity_t *pGlobal = gGlobalState.EntityFromTable( tmpVars.globalname );

			// Don't overlay any instance of the global that isn't the latest
			// pSaveData->szCurrentMapName is the level this entity is coming from
			// pGlobla->levelName is the last level the global entity was active in.
			// If they aren't the same, then this global update is out of date.
			if( !FStrEq( pSaveData->szCurrentMapName, pGlobal->levelName ) )
				return 0;

			// Compute the new global offset
			oldOffset = pSaveData->vecLandmarkOffset;
			CBaseEntity *pNewEntity = FindGlobalEntity( tmpVars.classname, tmpVars.globalname );
			if( pNewEntity )
			{
				//ALERT( at_console, "Overlay %s with %s\n", STRING( pNewEntity->pev->classname ), STRING( tmpVars.classname ) );
				// Tell the restore code we're overlaying a global entity from another level
				restoreHelper.SetGlobalMode( 1 );	// Don't overwrite global fields
				pSaveData->vecLandmarkOffset = ( pSaveData->vecLandmarkOffset - pNewEntity->pev->mins ) + tmpVars.mins;
				pEntity = pNewEntity;// we're going to restore this data OVER the old entity
				pent = ENT( pEntity->pev );
				// Update the global table to say that the global definition of this entity should come from this level
				gGlobalState.EntityUpdate( pEntity->pev->globalname, gpGlobals->mapname );
			}
			else
			{
				// This entity will be freed automatically by the engine.  If we don't do a restore on a matching entity (below)
				// or call EntityUpdate() to move it to this level, we haven't changed global state at all.
				return 0;
			}
		}

		if( pEntity->ObjectCaps() & FCAP_MUST_SPAWN )
		{
			pEntity->Restore( restoreHelper );
			pEntity->Spawn();
		}
		else
		{
			pEntity->Restore( restoreHelper );
			pEntity->Precache();
		}

		// Again, could be deleted, get the pointer again.
		pEntity = (CBaseEntity *)GET_PRIVATE( pent );
#if 0
		if( pEntity && pEntity->pev->globalname && globalEntity ) 
		{
			ALERT( at_console, "Global %s is %s\n", STRING( pEntity->pev->globalname ), STRING( pEntity->pev->model ) );
		}
#endif
		// Is this an overriding global entity (coming over the transition), or one restoring in a level
		if( globalEntity )
		{
			//ALERT( at_console, "After: %f %f %f %s\n", pEntity->pev->origin.x, pEntity->pev->origin.y, pEntity->pev->origin.z, STRING( pEntity->pev->model ) );
			pSaveData->vecLandmarkOffset = oldOffset;
			if( pEntity )
			{
				UTIL_SetOrigin( pEntity->pev, pEntity->pev->origin );
				pEntity->OverrideReset();
			}
		}
		else if( pEntity && pEntity->pev->globalname ) 
		{
			const globalentity_t *pGlobal = gGlobalState.EntityFromTable( pEntity->pev->globalname );
			if( pGlobal )
			{
				// Already dead? delete
				if( pGlobal->state == GLOBAL_DEAD )
					return -1;
				else if( !FStrEq( STRING( gpGlobals->mapname ), pGlobal->levelName ) )
				{
					pEntity->MakeDormant();	// Hasn't been moved to this level yet, wait but stay alive
				}
				// In this level & not dead, continue on as normal
			}
			else
			{
				ALERT( at_error, "Global Entity %s (%s) not in table!!!\n", STRING( pEntity->pev->globalname ), STRING( pEntity->pev->classname ) );
				// Spawned entities default to 'On'
				gGlobalState.EntityAdd( pEntity->pev->globalname, gpGlobals->mapname, GLOBAL_ON );
			}
		}
	}
	return 0;
}

void DispatchObjectCollsionBox( edict_t *pent )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE( pent );
	if( pEntity )
	{
		pEntity->SetObjectCollisionBox();
	}
	else
		SetObjectCollisionBox( &pent->v );
}

void SaveWriteFields( SAVERESTOREDATA *pSaveData, const char *pname, void *pBaseData, TYPEDESCRIPTION *pFields, int fieldCount )
{
	CSave saveHelper( pSaveData );
	saveHelper.WriteFields( pname, pBaseData, pFields, fieldCount );
}

void SaveReadFields( SAVERESTOREDATA *pSaveData, const char *pname, void *pBaseData, TYPEDESCRIPTION *pFields, int fieldCount )
{
	CRestore restoreHelper( pSaveData );
	restoreHelper.ReadFields( pname, pBaseData, pFields, fieldCount );
}

// Initialize absmin & absmax to the appropriate box
void SetObjectCollisionBox( entvars_t *pev )
{
	if( ( pev->solid == SOLID_BSP ) && 
		 ( pev->angles.x || pev->angles.y || pev->angles.z ) )
	{
		// expand for rotation
		float max, v;
		int i;

		max = 0;
		for( i = 0; i < 3; i++ )
		{
			v = fabs( ( (float *)pev->mins )[i] );
			if( v > max )
				max = v;
			v = fabs( ( (float *)pev->maxs )[i] );
			if( v > max )
				max = v;
		}
		for( i = 0; i < 3; i++ )
		{
			( (float *)pev->absmin )[i] = ( (float *)pev->origin )[i] - max;
			( (float *)pev->absmax )[i] = ( (float *)pev->origin )[i] + max;
		}
	}
	else
	{
		pev->absmin = pev->origin + pev->mins;
		pev->absmax = pev->origin + pev->maxs;
	}

	pev->absmin.x -= 1;
	pev->absmin.y -= 1;
	pev->absmin.z -= 1;
	pev->absmax.x += 1;
	pev->absmax.y += 1;
	pev->absmax.z += 1;
}