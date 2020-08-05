#include "game_shared.h"
#include "c_point_entity.h"
#include "base_defs.h"
#include "c_base_entity.h"

void CPointEntity::Spawn( void )
{
#ifdef SERVER_DLL
	pev->solid = SOLID_NOT;
#endif
}

int CPointEntity::ObjectCaps()
{
	return CBaseEntity::ObjectCaps() & ~FCAP_ACROSS_TRANSITION;
}

//================================================================================================================================================//
// CMultiSource
void CMultiSource::Register( void )
{
	edict_t *pentTarget = NULL;

	m_iTotal = 0;
	memset( m_rgEntities, 0, MS_MAX_TARGETS * sizeof(EHANDLE) );

	SetThink( &CBaseEntity::SUB_DoNothing );

	// search for all entities which target this multisource (pev->targetname)
	pentTarget = FIND_ENTITY_BY_STRING( NULL, "target", STRING( pev->targetname ) );

	while( !FNullEnt( pentTarget ) && ( m_iTotal < MS_MAX_TARGETS ) )
	{
		CBaseEntity *pTarget = CBaseEntity::Instance( pentTarget );
		if( pTarget )
			m_rgEntities[m_iTotal++] = pTarget;

		pentTarget = FIND_ENTITY_BY_STRING( pentTarget, "target", STRING( pev->targetname ) );
	}

	pentTarget = FIND_ENTITY_BY_STRING( NULL, "classname", "multi_manager" );
	while( !FNullEnt( pentTarget ) && ( m_iTotal < MS_MAX_TARGETS ) )
	{
		CBaseEntity *pTarget = CBaseEntity::Instance( pentTarget );
		if( pTarget && pTarget->HasTarget( pev->targetname ) )
			m_rgEntities[m_iTotal++] = pTarget;

		pentTarget = FIND_ENTITY_BY_STRING( pentTarget, "classname", "multi_manager" );
	}
	pev->spawnflags &= ~SF_MULTI_INIT;
}

#ifdef SERVER_DLL
TYPEDESCRIPTION CMultiSource::m_SaveData[] =
{
		//!!!BUGBUG FIX
	DEFINE_ARRAY( CMultiSource, m_rgEntities, FIELD_EHANDLE, MS_MAX_TARGETS ),
	DEFINE_ARRAY( CMultiSource, m_rgTriggered, FIELD_INTEGER, MS_MAX_TARGETS ),
	DEFINE_FIELD( CMultiSource, m_iTotal, FIELD_INTEGER ),
	DEFINE_FIELD( CMultiSource, m_globalstate, FIELD_STRING ),
};
#endif

IMPLEMENT_SAVERESTORE( CMultiSource, CBaseEntity )

LINK_ENTITY_TO_CLASS( multisource, CMultiSource )

//
// Cache user-entity-field values until spawn is called.
//
void CMultiSource::KeyValue( KeyValueData *pkvd )
{
	if( FStrEq( pkvd->szKeyName, "style" ) ||
	    FStrEq( pkvd->szKeyName, "height" ) ||
	    FStrEq( pkvd->szKeyName, "killtarget" ) ||
	    FStrEq( pkvd->szKeyName, "value1" ) ||
	    FStrEq( pkvd->szKeyName, "value2" ) ||
	    FStrEq( pkvd->szKeyName, "value3" ) )
		pkvd->fHandled = TRUE;
	else if( FStrEq( pkvd->szKeyName, "globalstate" ) )
	{
		m_globalstate = ALLOC_STRING( pkvd->szValue );
		pkvd->fHandled = TRUE;
	}
	else
		CPointEntity::KeyValue( pkvd );
}

void CMultiSource::Spawn()
{
	// set up think for later registration

	pev->solid = SOLID_NOT;
	pev->movetype = MOVETYPE_NONE;
	pev->nextthink = gpGlobals->time + 0.1;
	pev->spawnflags |= SF_MULTI_INIT;	// Until it's initialized
	SetThink( &CMultiSource::Register );
}

void CMultiSource::Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value )
{
#ifdef SERVER_DLL
	int i = 0;

	// Find the entity in our list
	while( i < m_iTotal )
		if( m_rgEntities[i++] == pCaller )
			break;

	// if we didn't find it, report error and leave
	if( i > m_iTotal )
	{
		ALERT( at_console, "MultiSrc:Used by non member %s.\n", STRING( pCaller->pev->classname ) );
		return;
	}

	// CONSIDER: a Use input to the multisource always toggles.  Could check useType for ON/OFF/TOGGLE
	m_rgTriggered[i - 1] ^= 1;

	//
	if( IsTriggered( pActivator ) )
	{
		ALERT( at_aiconsole, "Multisource %s enabled (%d inputs)\n", STRING( pev->targetname ), m_iTotal );
		useType = USE_TOGGLE;
		if( m_globalstate )
			useType = USE_ON;
		SUB_UseTargets( NULL, useType, 0 );
	}
#else

#endif
}

bool CMultiSource::IsTriggered(CBaseEntity * )
{
#ifdef SERVER_DLL
	// Is everything triggered?
	int i = 0;

	// Still initializing?
	if( pev->spawnflags & SF_MULTI_INIT )
		return 0;

	while( i < m_iTotal )
	{
		if( m_rgTriggered[i] == 0 )
			break;
		i++;
	}

	if( i == m_iTotal )
	{
		if( !m_globalstate || gGlobalState.EntityGetState( m_globalstate ) == GLOBAL_ON )
			return 1;
	}

	return 0;
#else
	return false;
#endif
}
//================================================================================================================================================//
