/*
 *
 * c_point_entity.h - Base for all point entities
 *
 */
#pragma once

#include "c_base_entity.h"

class CPointEntity : public CBaseEntity
{
public:
	void Spawn( void );
	virtual int ObjectCaps( void );
private:
};

#define MAX_MULTI_TARGETS	16 // maximum number of targets a single multi_manager entity may be assigned.
#define MS_MAX_TARGETS		32

class CMultiSource : public CPointEntity
{
public:
	void Spawn();
	void KeyValue( KeyValueData *pkvd );
	void Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	int ObjectCaps( void ) { return ( CPointEntity::ObjectCaps() | FCAP_MASTER ); }
	bool IsTriggered(CBaseEntity *pActivator );
	void EXPORT Register( void );

	virtual int Save( CSave &save );
	virtual int Restore( CRestore &restore );
	static TYPEDESCRIPTION m_SaveData[];

	EHANDLE m_rgEntities[MS_MAX_TARGETS];
	int m_rgTriggered[MS_MAX_TARGETS];

	int m_iTotal;
	string_t m_globalstate;
};
