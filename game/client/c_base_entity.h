/**
 *
 * c_base_entity.h - Client's base entity class
 *
 */
#pragma once

#include "base_defs.h"
#include "eiface.h"
#include "progdefs.h"
#include "vector.h"

class C_BaseMonster;
class C_SquadMonster;
class C_BasePlayerItem;

class C_BaseEntity
{
public:
	entvars_t *pev;

	C_BaseEntity();
	~C_BaseEntity();

	// initialization functions
	virtual void Spawn( void ) { return; }
	virtual void Precache( void ) { return; }
	virtual void KeyValue( KeyValueData* pkvd ) { }
	virtual int ObjectCaps( void ) { return FCAP_ACROSS_TRANSITION; }
	virtual void Activate( void ) {}

	// Setup the object->object collision box (pev->mins / pev->maxs is the object->world collision box)
	virtual void SetObjectCollisionBox( void );

	// Classify - returns the type of group (i.e, "houndeye", or "human military" so that monsters with different classnames
	// still realize that they are teammates. (overridden for monsters that form groups)
	virtual int Classify( void ) { return CLASS_NONE; };
	virtual void DeathNotice( entvars_t *pevChild ) {}// monster maker children use this to tell the monster maker that they have died.

	static TYPEDESCRIPTION m_SaveData[];

	virtual void TraceAttack( entvars_t *pevAttacker, float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType);
	virtual int TakeDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType );
	virtual int TakeHealth( float flHealth, int bitsDamageType );
	virtual void Killed( entvars_t *pevAttacker, int iGib );
	virtual int BloodColor( void ) { return 0; }
	virtual void TraceBleed( float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType );
	virtual bool IsTriggered( C_BaseEntity *pActivator ) {return true; }
	virtual C_BaseMonster *MyMonsterPointer( void ) { return NULL; }
	virtual C_SquadMonster *MySquadMonsterPointer( void ) { return NULL; }
	virtual	int GetToggleState( void ) { return 0; }
	virtual void AddPoints( int score, BOOL bAllowNegativeScore ) {}
	virtual void AddPointsToTeam( int score, BOOL bAllowNegativeScore ) {}
	virtual bool AddPlayerItem( C_BasePlayerItem *pItem ) { return 0; }
	virtual bool RemovePlayerItem( C_BasePlayerItem *pItem ) { return 0; }
	virtual int GiveAmmo( int iAmount, const char *szName, int iMax ) { return -1; };
	virtual float GetDelay( void ) { return 0; }
	virtual int IsMoving( void ) { return pev->velocity == Vector(0,0,0); };
	virtual void OverrideReset( void ) {}
	virtual int DamageDecal( int bitsDamageType );
	// This is ONLY used by the node graph to test movement through a door
	virtual void SetToggleState( int state ) {}
	virtual void StartSneaking( void ) {}
	virtual void StopSneaking( void ) {}
	virtual bool OnControls( entvars_t *pev ) { return false; }
	virtual bool IsSneaking( void ) { return false; }
	virtual bool IsAlive( void ) { return (pev->deadflag == DEAD_NO) && pev->health > 0; }
	virtual bool IsBSPModel( void ) { return pev->solid == SOLID_BSP || pev->movetype == MOVETYPE_PUSHSTEP; }
	virtual bool ReflectGauss( void ) { return ( IsBSPModel() && !pev->takedamage ); }
	virtual bool HasTarget( string_t targetname ) { return false; }
	virtual bool IsInWorld( void );
	virtual	bool IsPlayer( void ) { return false; }
	virtual bool IsNetClient( void ) { return false; }
	virtual const char *TeamID( void ) { return ""; }

	/* Utility functions */
	void RemoveThis(float time = 0.1);

	virtual void Think( void ) {};


	virtual void Touch( C_BaseEntity *pOther ) {};
	virtual void Use( C_BaseEntity *pActivator, C_BaseEntity *pCaller, USE_TYPE useType, float value ) {};
	virtual void Blocked( C_BaseEntity *pOther ) {};

	virtual void UpdateOnRemove( void );

	int ShouldToggle( USE_TYPE useType, BOOL currentState );
	void FireBullets( ULONG cShots, Vector  vecSrc, Vector	vecDirShooting,	Vector	vecSpread, float flDistance, int iBulletType, int iTracerFreq = 4, int iDamage = 0, entvars_t *pevAttacker = NULL  );
	Vector FireBulletsPlayer( ULONG cShots, Vector  vecSrc, Vector	vecDirShooting,	Vector	vecSpread, float flDistance, int iBulletType, int iTracerFreq = 4, int iDamage = 0, entvars_t *pevAttacker = NULL, int shared_rand = 0 );

	virtual C_BaseEntity *Respawn( void ) { return NULL; }

	// Do the bounding boxes of these two intersect?
	int Intersects( C_BaseEntity *pOther );
	void MakeDormant( void );
	int IsDormant( void );
	bool IsLockedByMaster( void ) { return false; }

	static C_BaseEntity *Instance( edict_t *pent )
	{
		if( !pent )
			pent = ENT( 0 );
		C_BaseEntity *pEnt = (C_BaseEntity *)GET_PRIVATE( pent );
		return pEnt;
	}

	static C_BaseEntity *Instance( entvars_t *pev ) { return Instance( ENT( pev ) ); }
	static C_BaseEntity *Instance( int eoffset) { return Instance( ENT( eoffset) ); }

	C_BaseMonster *GetMonsterPointer( entvars_t *pevMonster )
	{
		C_BaseEntity *pEntity = Instance( pevMonster );
		if( pEntity )
			return pEntity->MyMonsterPointer();
		return NULL;
	}
	C_BaseMonster *GetMonsterPointer( edict_t *pentMonster )
	{
		C_BaseEntity *pEntity = Instance( pentMonster );
		if( pEntity )
			return pEntity->MyMonsterPointer();
		return NULL;
	}

	// virtual functions used by a few classes

	// used by monsters that are created by the MonsterMaker
	virtual	void UpdateOwner( void ) { return; };

	static C_BaseEntity *Create( const char *szName, const Vector &vecOrigin, const Vector &vecAngles, edict_t *pentOwner = NULL );

	virtual BOOL FBecomeProne( void ) {return FALSE;};
	edict_t *edict() { return ENT( pev ); };
	EOFFSET eoffset() { return OFFSET( pev ); };
	int entindex() { return ENTINDEX( edict() ); };

	virtual Vector Center() { return ( pev->absmax + pev->absmin ) * 0.5; }; // center point of entity
	virtual Vector EyePosition() { return pev->origin + pev->view_ofs; };			// position of eyes
	virtual Vector EarPosition() { return pev->origin + pev->view_ofs; };			// position of ears
	virtual Vector BodyTarget( const Vector &posSrc ) { return Center(); };		// position to shoot at

	virtual int Illumination() { return GETENTITYILLUM( ENT( pev ) ); };

	virtual	BOOL FVisible( C_BaseEntity *pEntity );
	virtual	BOOL FVisible( const Vector &vecOrigin );
};