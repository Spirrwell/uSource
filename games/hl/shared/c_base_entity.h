/*
 *
 * base_entity.h - Base entity class
 *
 */
#pragma once

#include "game_shared.h"
#include "util.h"
#include "base_defs.h"

class CSave;
class CRestore;
class CBaseMonster;
class CSquadMonster;
class CBasePlayerItem;

/* Temporary save data stuff before we move to the new reflection system */
#ifdef SERVER_DLL
#define BEGIN_SAVE_DATA(_class) TYPEDESCRIPTION _class::m_SaveData[] = {
#define DEFINE_SAVE_FIELD(_x, _y, _z) DEFINE_FIELD(_x, _y, _z),
#define END_SAVE_DATA() };
#else
#define BEGIN_SAVE_DATA(_class)
#define DEFINE_SAVE_FIELD(x,y,z)
#define END_SAVE_DATA()
#endif

//
// Base Entity.  All entity types derive from this
//
class CBaseEntity
{
private:
	bool m_bShouldRemove;

public:
	// Constructor.  Set engine to use C/C++ callback functions
	// pointers to engine data
	entvars_t *pev;		// Don't need to save/restore this pointer, the engine resets it

	// path corners
	CBaseEntity *m_pGoalEnt;// path corner we are heading towards
	CBaseEntity *m_pLink;// used for temporary link-list operations.

	/* Event functions */
	virtual void Activate() {}
	virtual void Spawn() { return; }
	virtual void Precache() { return; }
	virtual void KeyValue(KeyValueData* pkvd) { pkvd->fHandled = FALSE; }
	virtual int Save( CSave &save );
	virtual int Restore( CRestore &restore );
	virtual void Killed( entvars_t *pevAttacker, int iGib );
	virtual int TakeDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType );
	virtual int TakeHealth( float flHealth, int bitsDamageType );
	virtual void SetToggleState( int state ) {}
	virtual void StartSneaking( void ) {}
	virtual void StopSneaking() {}
	virtual bool OnControls(entvars_t *pev) { return FALSE; }
	virtual void Touch(CBaseEntity *pOther) { if( m_pfnTouch ) (this->*m_pfnTouch)( pOther ); }
	virtual void Use(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	virtual void Blocked(CBaseEntity *pOther) { if( m_pfnBlocked ) ( this->*m_pfnBlocked )( pOther ); };
	virtual void DeathNotice( entvars_t *pevChild ) {};

	/* Entity type checking */
	virtual bool IsBSPModel() { return pev->solid == SOLID_BSP || pev->movetype == MOVETYPE_PUSHSTEP; }
	virtual	bool IsPlayer() { return false; }
	virtual bool IsNetClient() { return false; }
	virtual bool IsNPC() { return false; }
	virtual bool IsItem() { return false; }
	virtual bool IsWeapon() { return false; }

	/* State checks */
	virtual bool IsTriggered( CBaseEntity *pActivator ) { return false; }
	virtual bool IsSneaking() { return false; }
	virtual bool IsAlive() { return (pev->deadflag == DEAD_NO) && pev->health > 0; }
	virtual int IsMoving() { return pev->velocity != Vector(0.0f, 0.0f, 0.0f); }
	virtual bool IsInWorld();
	int IsDormant();
	bool IsLockedByMaster() { return false; }
	virtual bool HasTarget( string_t targetname ) { return FStrEq(STRING(targetname), STRING(pev->targetname) ); }

	/* Internal Utils */
	virtual CBaseMonster *MyMonsterPointer( void ) { return NULL; }
	virtual CSquadMonster *MySquadMonsterPointer( void ) { return NULL; }


	virtual int ObjectCaps( void ) { return FCAP_ACROSS_TRANSITION; }


	// Setup the object->object collision box (pev->mins / pev->maxs is the object->world collision box)
	virtual void SetObjectCollisionBox( void );
	virtual int Classify( void ) { return CLASS_NONE; };

	static TYPEDESCRIPTION m_SaveData[];

	virtual void TraceAttack( entvars_t *pevAttacker, float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType);


	virtual int BloodColor( void ) { return DONT_BLEED; }
	virtual void TraceBleed( float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType );


	virtual	int GetToggleState( void ) { return TS_AT_TOP; }
	virtual void AddPoints( int score, bool bAllowNegativeScore ) {}
	virtual void AddPointsToTeam( int score, bool bAllowNegativeScore ) {}
	virtual bool AddPlayerItem( CBasePlayerItem *pItem ) { return 0; }
	virtual bool RemovePlayerItem( CBasePlayerItem *pItem ) { return 0; }
	virtual int GiveAmmo( int iAmount, const char *szName, int iMax ) { return -1; };
	virtual float GetDelay( void ) { return 0; }
	virtual void OverrideReset( void ) {}
	virtual int DamageDecal( int bitsDamageType );


	virtual bool ReflectGauss( void ) { return ( IsBSPModel() && !pev->takedamage ); }

	virtual const char *TeamID( void ) { return ""; }

	/* Utility functions */
	void RemoveThis(float time = 0.1);

	//virtual void SetActivator( CBaseEntity *pActivator ) {}
	virtual CBaseEntity *GetNextTarget( void );

	// fundamental callbacks
	void ( CBaseEntity ::*m_pfnThink )( void);
	void ( CBaseEntity ::*m_pfnTouch )( CBaseEntity *pOther );
	void ( CBaseEntity ::*m_pfnUse )( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	void ( CBaseEntity ::*m_pfnBlocked )( CBaseEntity *pOther );

	virtual void Think( void )
	{
		if( m_pfnThink ) ( this->*m_pfnThink )();
		if(m_bShouldRemove) SUB_Remove();
		m_bShouldRemove = false;
	}




	// allow engine to allocate instance data
	void *operator new( size_t stAllocateBlock, entvars_t *pev )
	{
		return (void *)ALLOC_PRIVATE( ENT( pev ), stAllocateBlock );
	};

	// don't use this.
#if _MSC_VER >= 1200 // only build this code if MSVC++ 6.0 or higher
	void operator delete( void *pMem, entvars_t *pev )
	{
		pev->flags |= FL_KILLME;
	};
#endif

	virtual void UpdateOnRemove( void );

	// common member functions
	void EXPORT SUB_Remove( void );
	void EXPORT SUB_DoNothing( void );
	void EXPORT SUB_StartFadeOut ( void );
	void EXPORT SUB_FadeOut( void );
	void EXPORT SUB_CallUseToggle( void ) { this->Use( this, this, USE_TOGGLE, 0 ); }
	int ShouldToggle( USE_TYPE useType, bool currentState );
	void FireBullets( ULONG cShots, Vector  vecSrc, Vector	vecDirShooting,	Vector	vecSpread, float flDistance, int iBulletType, int iTracerFreq = 4, int iDamage = 0, entvars_t *pevAttacker = NULL  );
	Vector FireBulletsPlayer( ULONG cShots, Vector  vecSrc, Vector	vecDirShooting,	Vector	vecSpread, float flDistance, int iBulletType, int iTracerFreq = 4, int iDamage = 0, entvars_t *pevAttacker = NULL, int shared_rand = 0 );

	virtual CBaseEntity *Respawn( void ) { return NULL; }

	void SUB_UseTargets( CBaseEntity *pActivator, USE_TYPE useType, float value );
	// Do the bounding boxes of these two intersect?
	int Intersects( CBaseEntity *pOther );
	void MakeDormant( void );

	static CBaseEntity *Instance( edict_t *pent )
	{
		if( !pent )
			pent = ENT( 0 );
		CBaseEntity *pEnt = (CBaseEntity *)GET_PRIVATE( pent );
		return pEnt;
	}

	/* Returns the instance of this class */
	static CBaseEntity *Instance( entvars_t *pev ) { return Instance( ENT( pev ) ); }
	static CBaseEntity *Instance( int eoffset) { return Instance( ENT( eoffset) ); }

	CBaseMonster *GetMonsterPointer( entvars_t *pevMonster )
	{
		CBaseEntity *pEntity = Instance( pevMonster );
		if( pEntity )
			return pEntity->MyMonsterPointer();
		return NULL;
	}
	CBaseMonster *GetMonsterPointer( edict_t *pentMonster )
	{
		CBaseEntity *pEntity = Instance( pentMonster );
		if( pEntity )
			return pEntity->MyMonsterPointer();
		return NULL;
	}

	virtual	void UpdateOwner( void ) { return; };

	static CBaseEntity *Create( const char *szName, const Vector &vecOrigin, const Vector &vecAngles, edict_t *pentOwner = NULL );

	virtual bool FBecomeProne() {return false; }
	edict_t *edict() { return ENT( pev ); }
	EOFFSET eoffset() { return OFFSET( pev ); }
	int entindex() { return ENTINDEX( edict() ); }

	/* Camera and Ear Positioning */
	virtual Vector Center() { return ( pev->absmax + pev->absmin ) * 0.5; }
	virtual Vector EyePosition() { return pev->origin + pev->view_ofs; }
	virtual Vector EarPosition() { return pev->origin + pev->view_ofs; }
	virtual Vector BodyTarget( const Vector &posSrc ) { return Center(); }

	virtual int Illumination() { return GETENTITYILLUM( ENT( pev ) ); }

	virtual	bool FVisible( CBaseEntity *pEntity );
	virtual	bool FVisible( const Vector &vecOrigin );
};


// Ugly technique to override base member functions
// Normally it's illegal to cast a pointer to a member function of a derived class to a pointer to a
// member function of a base class.  static_cast is a sleezy way around that problem.
/* What on fucking earth valve? Seriously? what the fuck are you guys even doing??? */
/* I'm in awe at this. It's the most clever yet the most lazy and dumb thing ever */
/* Why the fuck are you changing think and touch functions on the fly!? */
#if 1 /*I swear to god, one day this 1 will be changed to 0!!! */
#define SetThink( a ) m_pfnThink = static_cast <void (CBaseEntity::*)(void)> (a)
#define SetTouch( a ) m_pfnTouch = static_cast <void (CBaseEntity::*)(CBaseEntity *)> (a)
#define SetUse( a ) m_pfnUse = static_cast <void (CBaseEntity::*)( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value )> (a)
#define SetBlocked( a ) m_pfnBlocked = static_cast <void (CBaseEntity::*)(CBaseEntity *)> (a)
#define ResetThink( ) m_pfnThink = static_cast <void (CBaseEntity::*)(void)> (NULL)
#define ResetTouch( ) m_pfnTouch = static_cast <void (CBaseEntity::*)(CBaseEntity *)> (NULL)
#define ResetUse( ) m_pfnUse = static_cast <void (CBaseEntity::*)( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value )> (NULL)
#define SetMoveDone( a ) m_pfnCallWhenMoveDone = static_cast <void (CBaseToggle::*)(void)> (a)
#define ResetBlocked( ) m_pfnBlocked = static_cast <void (CBaseEntity::*)(CBaseEntity *)> (NULL)
#endif