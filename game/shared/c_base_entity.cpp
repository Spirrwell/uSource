/*
 *
 * base_entity.cpp - Stubs and basic implementation of base entity stuff
 *
 */
#include "game_shared.h"
#include "c_base_entity.h"

#ifdef SERVER_DLL
#include "weapons.h"
#include "info_node.h"
#else

#endif

#ifdef SERVER_DLL
extern DLL_GLOBAL Vector g_vecAttackDir;
extern CGraph WorldGraph;
#endif

// give health
int CBaseEntity::TakeHealth( float flHealth, int bitsDamageType )
{
#ifdef SERVER_DLL
	if( !pev->takedamage )
		return 0;

	// heal
	if( pev->health >= pev->max_health )
		return 0;

	pev->health += flHealth;

	if( pev->health > pev->max_health )
		pev->health = pev->max_health;

	return 1;
#else
	return 1;
#endif
}

// inflict damage on this entity.  bitsDamageType indicates type of damage inflicted, ie: DMG_CRUSH

int CBaseEntity::TakeDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType )
{
#ifdef SERVER_DLL
	Vector vecTemp;

	if( !pev->takedamage )
		return 0;

	// UNDONE: some entity types may be immune or resistant to some bitsDamageType

	// if Attacker == Inflictor, the attack was a melee or other instant-hit attack.
	// (that is, no actual entity projectile was involved in the attack so use the shooter's origin).
	if( pevAttacker == pevInflictor )
	{
		vecTemp = pevAttacker->origin - VecBModelOrigin( pev );
	}
	else
		// an actual missile was involved.
	{
		vecTemp = pevInflictor->origin - VecBModelOrigin( pev );
	}

	// this global is still used for glass and other non-monster killables, along with decals.
	g_vecAttackDir = vecTemp.Normalize();

	// save damage based on the target's armor level
	// figure momentum add (don't let hurt brushes or other triggers move player)
	if( ( !FNullEnt( pevInflictor ) ) && (pev->movetype == MOVETYPE_WALK || pev->movetype == MOVETYPE_STEP ) && ( pevAttacker->solid != SOLID_TRIGGER ) )
	{
		Vector vecDir = pev->origin - ( pevInflictor->absmin + pevInflictor->absmax ) * 0.5;
		vecDir = vecDir.Normalize();

		float flForce = flDamage * ( ( 32 * 32 * 72.0 ) / ( pev->size.x * pev->size.y * pev->size.z ) ) * 5;

		if( flForce > 1000.0 )
			flForce = 1000.0;
		pev->velocity = pev->velocity + vecDir * flForce;
	}

	// do the damage
	pev->health -= flDamage;
	if( pev->health <= 0 )
	{
		Killed( pevAttacker, GIB_NORMAL );
		return 0;
	}

	return 1;
#else
	return 1;
#endif
}

void CBaseEntity::Killed( entvars_t *pevAttacker, int iGib )
{
#ifdef SERVER_DLL
	pev->takedamage = DAMAGE_NO;
	pev->deadflag = DEAD_DEAD;
	UTIL_Remove( this );
#else
	pev->effects |= EF_NODRAW;
#endif
}

CBaseEntity *CBaseEntity::GetNextTarget( void )
{
#ifdef SERVER_DLL
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

// Global Savedata for Delay
BEGIN_SAVE_DATA(CBaseEntity)
	DEFINE_SAVE_FIELD( CBaseEntity, m_pGoalEnt, FIELD_CLASSPTR )
	DEFINE_SAVE_FIELD( CBaseEntity, m_pfnThink, FIELD_FUNCTION )		// UNDONE: Build table of these!!!
	DEFINE_SAVE_FIELD( CBaseEntity, m_pfnTouch, FIELD_FUNCTION )
	DEFINE_SAVE_FIELD( CBaseEntity, m_pfnUse, FIELD_FUNCTION )
	DEFINE_SAVE_FIELD( CBaseEntity, m_pfnBlocked, FIELD_FUNCTION )
END_SAVE_DATA()

int CBaseEntity::Save( CSave &save )
{
#ifdef SERVER_DLL
	if( save.WriteEntVars( "ENTVARS", pev ) )
		return save.WriteFields( "BASE", this, m_SaveData, ARRAYSIZE( m_SaveData ) );
	return 0;
#else
	return 1;
#endif
}

int CBaseEntity::Restore( CRestore &restore )
{
#ifdef SERVER_DLL
	int status;

	status = restore.ReadEntVars( "ENTVARS", pev );
	if( status )
		status = restore.ReadFields( "BASE", this, m_SaveData, ARRAYSIZE( m_SaveData ) );

	if( pev->modelindex != 0 && !FStringNull( pev->model ) )
	{
		Vector mins, maxs;
		mins = pev->mins;	// Set model is about to destroy these
		maxs = pev->maxs;

		PRECACHE_MODEL( STRING( pev->model ) );
		SET_MODEL( ENT( pev ), STRING( pev->model ) );
		UTIL_SetSize( pev, mins, maxs );	// Reset them
	}
	return status;
#else
	return 1;
#endif
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

void CBaseEntity::SetObjectCollisionBox( void )
{
#ifdef SERVER_DLL
	::SetObjectCollisionBox( pev );
#endif
}

int CBaseEntity::Intersects( CBaseEntity *pOther )
{
	if( pOther->pev->absmin.x > pev->absmax.x ||
	    pOther->pev->absmin.y > pev->absmax.y ||
	    pOther->pev->absmin.z > pev->absmax.z ||
	    pOther->pev->absmax.x < pev->absmin.x ||
	    pOther->pev->absmax.y < pev->absmin.y ||
	    pOther->pev->absmax.z < pev->absmin.z )
		return 0;
	return 1;
}

void CBaseEntity::MakeDormant( void )
{
	SetBits( pev->flags, FL_DORMANT );

	// Don't touch
	pev->solid = SOLID_NOT;
	// Don't move
	pev->movetype = MOVETYPE_NONE;
	// Don't draw
	SetBits( pev->effects, EF_NODRAW );
	// Don't think
	pev->nextthink = 0;
	// Relink
	UTIL_SetOrigin( pev, pev->origin );
}

int CBaseEntity::IsDormant( void )
{
	return FBitSet( pev->flags, FL_DORMANT );
}

bool CBaseEntity::IsInWorld( void )
{
#ifdef SERVER_DLL
	// position
	if( pev->origin.x >= 4096 )
		return FALSE;
	if( pev->origin.y >= 4096 )
		return FALSE;
	if( pev->origin.z >= 4096 )
		return FALSE;
	if( pev->origin.x <= -4096 )
		return FALSE;
	if( pev->origin.y <= -4096 )
		return FALSE;
	if( pev->origin.z <= -4096 )
		return FALSE;
	// speed
	if( pev->velocity.x >= 2000 )
		return FALSE;
	if( pev->velocity.y >= 2000 )
		return FALSE;
	if( pev->velocity.z >= 2000 )
		return FALSE;
	if( pev->velocity.x <= -2000 )
		return FALSE;
	if( pev->velocity.y <= -2000 )
		return FALSE;
	if( pev->velocity.z <= -2000 )
		return FALSE;

	return true;
#else
	return true;
#endif
}

int CBaseEntity::ShouldToggle( USE_TYPE useType, bool currentState )
{
#ifdef SERVER_DLL
	if( useType != USE_TOGGLE && useType != USE_SET )
	{
		if( ( currentState && useType == USE_ON ) || ( !currentState && useType == USE_OFF ) )
			return 0;
	}
	return 1;
#else
	return 0;
#endif
}

int CBaseEntity::DamageDecal( int bitsDamageType )
{
#ifdef SERVER_DLL
	if( pev->rendermode == kRenderTransAlpha )
		return -1;

	if( pev->rendermode != kRenderNormal )
		return DECAL_BPROOF1;

	return DECAL_GUNSHOT1 + RANDOM_LONG( 0, 4 );
#else
	return -1;
#endif
}

// NOTE: szName must be a pointer to constant memory, e.g. "monster_class" because the entity
// will keep a pointer to it after this call.
CBaseEntity *CBaseEntity::Create( const char *szName, const Vector &vecOrigin, const Vector &vecAngles, edict_t *pentOwner )
{
#ifdef SERVER_DLL
	edict_t	*pent;
	CBaseEntity *pEntity;

	pent = CREATE_NAMED_ENTITY( MAKE_STRING( szName ) );
	if( FNullEnt( pent ) )
	{
		ALERT ( at_console, "NULL Ent in Create!\n" );
		return NULL;
	}
	pEntity = Instance( pent );
	pEntity->pev->owner = pentOwner;
	pEntity->pev->origin = vecOrigin;
	pEntity->pev->angles = vecAngles;
	DispatchSpawn( pEntity->edict() );
	return pEntity;
#else
	return nullptr;
#endif
}

void CBaseEntity::RemoveThis(float time)
{
#ifdef SERVER_DLL
	pev->nextthink = pev->ltime + time;
	m_bShouldRemove = true;
#else
	// TODO: Client impl
#endif
}

bool CBaseEntity::FVisible(CBaseEntity *pEntity)
{
#ifdef SERVER_DLL
	TraceResult tr;
	Vector		vecLookerOrigin;
	Vector		vecTargetOrigin;

	if( !pEntity )
		return FALSE;
	if( !pEntity->pev )
		return FALSE;

	if( FBitSet( pEntity->pev->flags, FL_NOTARGET ) )
		return FALSE;

	// don't look through water
	if( ( pev->waterlevel != 3 && pEntity->pev->waterlevel == 3 )
		|| ( pev->waterlevel == 3 && pEntity->pev->waterlevel == 0 ) )
		return FALSE;

	vecLookerOrigin = pev->origin + pev->view_ofs;//look through the caller's 'eyes'
	vecTargetOrigin = pEntity->EyePosition();

	UTIL_TraceLine( vecLookerOrigin, vecTargetOrigin, ignore_monsters, ignore_glass, ENT( pev )/*pentIgnore*/, &tr );

	if( tr.flFraction != 1.0 )
	{
		return FALSE;// Line of sight is not established
	}
	else
	{
		return TRUE;// line of sight is valid.
	}
#else
	return false;
#endif
}

bool CBaseEntity::FVisible(const Vector &vecOrigin)
{
#ifdef SERVER_DLL
	TraceResult tr;
	Vector		vecLookerOrigin;

	vecLookerOrigin = EyePosition();//look through the caller's 'eyes'

	UTIL_TraceLine( vecLookerOrigin, vecOrigin, ignore_monsters, ignore_glass, ENT( pev )/*pentIgnore*/, &tr );

	if( tr.flFraction != 1.0 )
	{
		return FALSE;// Line of sight is not established
	}
	else
	{
		return TRUE;// line of sight is valid.
	}
#else
	return false;
#endif
}

void CBaseEntity::Use(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value)
{

	if( m_pfnUse )
		( this->*m_pfnUse )( pActivator, pCaller, useType, value );
}

// This updates global tables that need to know about entities being removed
void CBaseEntity::UpdateOnRemove( void )
{
#ifdef SERVER_DLL
	int i;

	if( FBitSet( pev->flags, FL_GRAPHED ) )
	{
		// this entity was a LinkEnt in the world node graph, so we must remove it from
		// the graph since we are removing it from the world.
		for( i = 0; i < WorldGraph.m_cLinks; i++ )
		{
			if( WorldGraph.m_pLinkPool[i].m_pLinkEnt == pev )
			{
				// if this link has a link ent which is the same ent that is removing itself, remove it!
				WorldGraph.m_pLinkPool[i].m_pLinkEnt = NULL;
			}
		}
	}

	if( pev->globalname )
		gGlobalState.EntitySetState( pev->globalname, GLOBAL_DEAD );

	// tell owner ( if any ) that we're dead.This is mostly for MonsterMaker functionality.
	//Killtarget didn't do this before, so the counter broke. - Solokiller
	if( CBaseEntity* pOwner = pev->owner ? Instance( pev->owner ) : 0 )
	{
		pOwner->DeathNotice( pev );
	}
#else

#endif
}

/*
================
TraceAttack
================
*/
void CBaseEntity::TraceAttack(entvars_t *pevAttacker, float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType)
{
#ifdef SERVER_DLL
	Vector vecOrigin = ptr->vecEndPos - vecDir * 4;

	if( pev->takedamage )
	{
		AddMultiDamage( pevAttacker, this, flDamage, bitsDamageType );

		int blood = BloodColor();

		if( blood != DONT_BLEED )
		{
			SpawnBlood( vecOrigin, blood, flDamage );// a little surface blood.
			TraceBleed( flDamage, vecDir, ptr, bitsDamageType );
		}
	}
#else

#endif
}

void CBaseEntity::TraceBleed( float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType )
{
#ifdef SERVER_DLL
	if( BloodColor() == DONT_BLEED )
		return;

	if( flDamage == 0 )
		return;

	if( !( bitsDamageType & ( DMG_CRUSH | DMG_BULLET | DMG_SLASH | DMG_BLAST | DMG_CLUB | DMG_MORTAR ) ) )
		return;

	// make blood decal on the wall!
	TraceResult Bloodtr;
	Vector vecTraceDir;
	float flNoise;
	int cCount;
	int i;

/*
	if( !IsAlive() )
	{
		// dealing with a dead monster.
		if( pev->max_health <= 0 )
		{
			// no blood decal for a monster that has already decalled its limit.
			return;
		}
		else
		{
			pev->max_health--;
		}
	}
*/
	if( flDamage < 10 )
	{
		flNoise = 0.1;
		cCount = 1;
	}
	else if( flDamage < 25 )
	{
		flNoise = 0.2;
		cCount = 2;
	}
	else
	{
		flNoise = 0.3;
		cCount = 4;
	}

	for( i = 0; i < cCount; i++ )
	{
		vecTraceDir = vecDir * -1;// trace in the opposite direction the shot came from (the direction the shot is going)

		vecTraceDir.x += RANDOM_FLOAT( -flNoise, flNoise );
		vecTraceDir.y += RANDOM_FLOAT( -flNoise, flNoise );
		vecTraceDir.z += RANDOM_FLOAT( -flNoise, flNoise );

		UTIL_TraceLine( ptr->vecEndPos, ptr->vecEndPos + vecTraceDir * -172, ignore_monsters, ENT( pev ), &Bloodtr );

		if( Bloodtr.flFraction != 1.0 )
		{
			UTIL_BloodDecalTrace( &Bloodtr, BloodColor() );
		}
	}
#else

#endif
}


// Convenient way to delay removing oneself
void CBaseEntity::SUB_Remove( void )
{
#ifdef SERVER_DLL
	UpdateOnRemove();
	if( pev->health > 0 )
	{
		// this situation can screw up monsters who can't tell their entity pointers are invalid.
		pev->health = 0;
		ALERT( at_aiconsole, "SUB_Remove called on entity with health > 0\n" );
	}

	REMOVE_ENTITY( ENT( pev ) );
#endif 
}