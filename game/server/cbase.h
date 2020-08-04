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
#pragma once
#include "base_defs.h"

/*

Class Hierachy

CBaseEntity
	CBaseDelay
		CBaseToggle
			CBaseItem
			CBaseMonster
				CBaseCycler
				CBasePlayer
				CBaseGroup
*/

// #include "saverestore.h"

class CSave;
class CRestore;

#ifndef CLIENT_DLL
#include "saverestore.h"
#endif

#include "game/server/ai/ai_schedule.h"

#ifndef MONSTEREVENT_H
#include "game/server/ai/ai_monsterevent.h"
#endif

#include "tier1/dbg.h"

// C functions for external declarations that call the appropriate C++ methods
#include "exportdef.h"

/* Entity base classes */
#include "c_base_entity.h"

extern "C" EXPORT int GetEntityAPI( DLL_FUNCTIONS *pFunctionTable, int interfaceVersion );
extern "C" EXPORT int GetEntityAPI2( DLL_FUNCTIONS *pFunctionTable, int *interfaceVersion );
extern "C" EXPORT int Server_GetPhysicsInterface( int iVersion, server_physics_api_t *pfuncsFromEngine, physics_interface_t *pFunctionTable );

#ifndef CLIENT_DLL
extern int DispatchSpawn( edict_t *pent );
extern void DispatchKeyValue( edict_t *pentKeyvalue, KeyValueData *pkvd );
extern void DispatchTouch( edict_t *pentTouched, edict_t *pentOther );
extern void DispatchUse( edict_t *pentUsed, edict_t *pentOther );
extern void DispatchThink( edict_t *pent );
extern void DispatchBlocked( edict_t *pentBlocked, edict_t *pentOther );
extern void DispatchSave( edict_t *pent, SAVERESTOREDATA *pSaveData );
extern int DispatchRestore( edict_t *pent, SAVERESTOREDATA *pSaveData, int globalEntity );
extern void DispatchObjectCollsionBox( edict_t *pent );
extern void SaveWriteFields( SAVERESTOREDATA *pSaveData, const char *pname, void *pBaseData, TYPEDESCRIPTION *pFields, int fieldCount );
extern void SaveReadFields( SAVERESTOREDATA *pSaveData, const char *pname, void *pBaseData, TYPEDESCRIPTION *pFields, int fieldCount );
extern void SaveGlobalState( SAVERESTOREDATA *pSaveData );
extern void RestoreGlobalState( SAVERESTOREDATA *pSaveData );
extern void ResetGlobalState( void );
#endif

#ifndef CLIENT_DLL
extern void FireTargets( const char *targetName, CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
#endif

typedef void(CBaseEntity::*BASEPTR)( void );
typedef void(CBaseEntity::*ENTITYFUNCPTR)( CBaseEntity *pOther );
typedef void(CBaseEntity::*USEPTR)( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );

class CBaseEntity;
class CBaseMonster;
class CBasePlayerItem;
class CSquadMonster;

//
// EHANDLE. Safe way to point to CBaseEntities who may die between frames
//
class EHANDLE
{
private:
	edict_t *m_pent;
	int m_serialnumber;
public:
	edict_t *Get( void );
	edict_t *Set( edict_t *pent );

	operator int ();

	operator CBaseEntity *();

	CBaseEntity *operator = ( CBaseEntity *pEntity );
	CBaseEntity *operator ->();
};

#define MAX_DELAY_CALLS 4

#if 0
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

	// initialization functions
	virtual void Spawn( void ) { return; }
	virtual void Precache( void ) { return; }
	virtual void KeyValue( KeyValueData* pkvd ) { pkvd->fHandled = FALSE; }
	virtual int Save( CSave &save );
	virtual int Restore( CRestore &restore );
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
	virtual int BloodColor( void ) { return DONT_BLEED; }
	virtual void TraceBleed( float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType );
	virtual bool IsTriggered(CBaseEntity *pActivator ) {return TRUE; }
	virtual CBaseMonster *MyMonsterPointer( void ) { return NULL; }
	virtual CSquadMonster *MySquadMonsterPointer( void ) { return NULL; }
	virtual	int GetToggleState( void ) { return TS_AT_TOP; }
	virtual void AddPoints(int score, bool bAllowNegativeScore ) {}
	virtual void AddPointsToTeam(int score, bool bAllowNegativeScore ) {}
	virtual bool AddPlayerItem(CBasePlayerItem *pItem ) { return 0; }
	virtual bool RemovePlayerItem(CBasePlayerItem *pItem ) { return 0; }
	virtual int GiveAmmo( int iAmount, const char *szName, int iMax ) { return -1; };
	virtual float GetDelay( void ) { return 0; }
	virtual int IsMoving( void ) { return pev->velocity != g_vecZero; }
	virtual void OverrideReset( void ) {}
	virtual int DamageDecal( int bitsDamageType );
	// This is ONLY used by the node graph to test movement through a door
	virtual void SetToggleState( int state ) {}
	virtual void StartSneaking( void ) {}
	virtual void StopSneaking( void ) {}
	virtual bool OnControls(entvars_t *pev ) { return FALSE; }
	virtual bool IsSneaking(void ) { return FALSE; }
	virtual bool IsAlive(void ) { return (pev->deadflag == DEAD_NO) && pev->health > 0; }
	virtual bool IsBSPModel(void ) { return pev->solid == SOLID_BSP || pev->movetype == MOVETYPE_PUSHSTEP; }
	virtual bool ReflectGauss(void ) { return (IsBSPModel() && !pev->takedamage ); }
	virtual bool HasTarget(string_t targetname ) { return FStrEq(STRING(targetname), STRING(pev->targetname) ); }
	virtual bool IsInWorld(void );
	virtual bool IsPlayer(void ) { return FALSE; }
	virtual bool IsNetClient(void ) { return FALSE; }
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


	virtual void Touch( CBaseEntity *pOther ) { if( m_pfnTouch ) (this->*m_pfnTouch)( pOther ); }
	virtual void Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value )
	{ 
		if( m_pfnUse )
			( this->*m_pfnUse )( pActivator, pCaller, useType, value );
	}
	virtual void Blocked( CBaseEntity *pOther ) { if( m_pfnBlocked ) ( this->*m_pfnBlocked )( pOther ); };

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
	int ShouldToggle(USE_TYPE useType, bool currentState );
	void FireBullets( ULONG cShots, Vector  vecSrc, Vector	vecDirShooting,	Vector	vecSpread, float flDistance, int iBulletType, int iTracerFreq = 4, int iDamage = 0, entvars_t *pevAttacker = NULL  );
	Vector FireBulletsPlayer( ULONG cShots, Vector  vecSrc, Vector	vecDirShooting,	Vector	vecSpread, float flDistance, int iBulletType, int iTracerFreq = 4, int iDamage = 0, entvars_t *pevAttacker = NULL, int shared_rand = 0 );

	virtual CBaseEntity *Respawn( void ) { return NULL; }

	void SUB_UseTargets( CBaseEntity *pActivator, USE_TYPE useType, float value );
	// Do the bounding boxes of these two intersect?
	int Intersects( CBaseEntity *pOther );
	void MakeDormant( void );
	int IsDormant( void );
	bool IsLockedByMaster(void ) { return FALSE; }

	static CBaseEntity *Instance( edict_t *pent )
	{
		if( !pent )
			pent = ENT( 0 );
		CBaseEntity *pEnt = (CBaseEntity *)GET_PRIVATE( pent ); 
		return pEnt; 
	}

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
	// virtual functions used by a few classes
	
	// used by monsters that are created by the MonsterMaker
	virtual	void UpdateOwner( void ) { return; };

	static CBaseEntity *Create( const char *szName, const Vector &vecOrigin, const Vector &vecAngles, edict_t *pentOwner = NULL );

	virtual bool FBecomeProne(void ) {return FALSE;};
	edict_t *edict() { return ENT( pev ); };
	EOFFSET eoffset() { return OFFSET( pev ); };
	int entindex() { return ENTINDEX( edict() ); };

	virtual Vector Center() { return ( pev->absmax + pev->absmin ) * 0.5; }; // center point of entity
	virtual Vector EyePosition() { return pev->origin + pev->view_ofs; };			// position of eyes
	virtual Vector EarPosition() { return pev->origin + pev->view_ofs; };			// position of ears
	virtual Vector BodyTarget( const Vector &posSrc ) { return Center(); };		// position to shoot at

	virtual int Illumination() { return GETENTITYILLUM( ENT( pev ) ); };

	virtual bool FVisible(CBaseEntity *pEntity );
	virtual bool FVisible(const Vector &vecOrigin );

	//We use this variables to store each ammo count.
	int ammo_9mm;
	int ammo_357;
	int ammo_bolts;
	int ammo_buckshot;
	int ammo_rockets;
	int ammo_uranium;
	int ammo_hornets;
	int ammo_argrens;
	//Special stuff for grenades and satchels.
	float m_flStartThrow;
	float m_flReleaseThrow;
	int m_chargeReady;
	int m_fInAttack;

	enum EGON_FIRESTATE { FIRE_OFF, FIRE_CHARGE };
	int m_fireState;
};
#endif

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

class CPointEntity : public CBaseEntity
{
public:
	void Spawn( void );
	virtual int ObjectCaps( void ) { return CBaseEntity::ObjectCaps() & ~FCAP_ACROSS_TRANSITION; }
private:
};

typedef struct locksounds			// sounds that doors and buttons make when locked/unlocked
{
	string_t	sLockedSound;		// sound a door makes when it's locked
	string_t	sLockedSentence;	// sentence group played when door is locked
	string_t	sUnlockedSound;		// sound a door makes when it's unlocked
	string_t	sUnlockedSentence;	// sentence group played when door is unlocked

	int		iLockedSentence;		// which sentence in sentence group to play next
	int		iUnlockedSentence;		// which sentence in sentence group to play next

	float	flwaitSound;			// time delay between playing consecutive 'locked/unlocked' sounds
	float	flwaitSentence;			// time delay between playing consecutive sentences
	BYTE	bEOFLocked;				// true if hit end of list of locked sentences
	BYTE	bEOFUnlocked;			// true if hit end of list of unlocked sentences
} locksound_t;

void PlayLockSounds( entvars_t *pev, locksound_t *pls, int flocked, int fbutton );

//
// MultiSouce
//

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


//
// generic Delay entity.
//
class CBaseDelay : public CBaseEntity
{
public:
	float m_flDelay;
	string_t m_iszKillTarget;

	virtual void KeyValue( KeyValueData *pkvd );
	virtual int Save( CSave &save );
	virtual int Restore( CRestore &restore );
	static TYPEDESCRIPTION m_SaveData[];
	// common member functions
	void SUB_UseTargets( CBaseEntity *pActivator, USE_TYPE useType, float value );
	void EXPORT DelayThink( void );
};

class CBaseAnimating : public CBaseDelay
{
public:
	virtual int Save( CSave &save );
	virtual int Restore( CRestore &restore );
	static TYPEDESCRIPTION m_SaveData[];

	// Basic Monster Animation functions
	float StudioFrameAdvance( float flInterval = 0.0 ); // accumulate animation frame time from last time called until now
	int GetSequenceFlags( void );
	int LookupActivity( int activity );
	int LookupActivityHeaviest( int activity );
	int LookupSequence( const char *label );
	void ResetSequenceInfo();
	void DispatchAnimEvents( float flFutureInterval = 0.1 ); // Handle events that have happend since last time called up until X seconds into the future
	virtual void HandleAnimEvent( MonsterEvent_t *pEvent ) { return; };
	float SetBoneController( int iController, float flValue );
	void InitBoneControllers( void );
	float SetBlending( int iBlender, float flValue );
	void GetBonePosition( int iBone, Vector &origin, Vector &angles );
	void GetAutomovement( Vector &origin, Vector &angles, float flInterval = 0.1 );
	int FindTransition( int iEndingSequence, int iGoalSequence, int *piDir );
	void GetAttachment( int iAttachment, Vector &origin, Vector &angles );
	void SetBodygroup( int iGroup, int iValue );
	int GetBodygroup( int iGroup );
	int ExtractBbox( int sequence, float *mins, float *maxs );
	void SetSequenceBox( void );

	// animation needs
	float m_flFrameRate;		// computed FPS for current sequence
	float m_flGroundSpeed;	// computed linear movement rate for current sequence
	float m_flLastEventCheck;	// last time the event list was checked
	BOOL m_fSequenceFinished;// flag set when StudioAdvanceFrame moves across a frame boundry
	BOOL m_fSequenceLoops;	// true if the sequence loops
};

//
// generic Toggle entity.
//
#define	SF_ITEM_USE_ONLY	256 //  ITEM_USE_ONLY = BUTTON_USE_ONLY = DOOR_USE_ONLY!!! 

class CBaseToggle : public CBaseAnimating
{
public:
	CBaseToggle() :
		m_bAngMoveDone(false),
		m_bLinearMoveDone(false)
	{

	}


	virtual void		KeyValue( KeyValueData *pkvd ) override;

	virtual void            Think() override
	{
		CBaseEntity::Think();
#ifndef CLIENT_DLL
		if(m_bAngMoveDone) AngularMoveDone();
		if(m_bLinearMoveDone) LinearMoveDone();
#endif
	}

	TOGGLE_STATE		m_toggle_state;
	float				m_flActivateFinished;//like attack_finished, but for doors
	float				m_flMoveDistance;// how far a door should slide or rotate
	float				m_flWait;
	float				m_flLip;
	float				m_flTWidth;// for plats
	float				m_flTLength;// for plats

	Vector				m_vecPosition1;
	Vector				m_vecPosition2;
	Vector				m_vecAngle1;
	Vector				m_vecAngle2;

	int					m_cTriggersLeft;		// trigger_counter only, # of activations remaining
	float				m_flHeight;
	EHANDLE				m_hActivator;
	void (CBaseToggle::*m_pfnCallWhenMoveDone)(void);
	Vector				m_vecFinalDest;
	Vector				m_vecFinalAngle;

	int					m_bitsDamageInflict;	// DMG_ damage type that the door or tigger does

	virtual int		Save( CSave &save ) override;
	virtual int		Restore( CRestore &restore ) override;

	static	TYPEDESCRIPTION m_SaveData[];

	virtual int		GetToggleState( void ) override { return m_toggle_state; }
	virtual float	GetDelay( void ) override { return m_flWait; }

	// common member functions
	void LinearMove( Vector	vecDest, float flSpeed );
	void EXPORT LinearMoveDone( void );
	void AngularMove( Vector vecDestAngle, float flSpeed );
	void EXPORT AngularMoveDone( void );
	bool IsLockedByMaster(void );

	/* Override this in place of SetMoveDone */
	virtual void MoveDone() {};

	static float		AxisValue( int flags, const Vector &angles );
	static void			AxisDir( entvars_t *pev );
	static float		AxisDelta( int flags, const Vector &angle1, const Vector &angle2 );

	string_t m_sMaster;		// If this button has a master switch, this is the targetname.
							// A master switch must be of the multisource type. If all 
							// of the switches in the multisource have been triggered, then
							// the button will be allowed to operate. Otherwise, it will be
							// deactivated.
	bool m_bAngMoveDone : 1;
	bool m_bLinearMoveDone : 1;
};


#define	ROUTE_SIZE			8 // how many waypoints a monster can store at one time
#define MAX_OLD_ENEMIES		4 // how many old enemies to remember


class CBaseMonster;
class CCineMonster;
class CSound;

#include "game/server/ai/ai_basemonster.h"

const char *ButtonSound( int sound );				// get string of button sound number

//
// Generic Button
//
class CBaseButton : public CBaseToggle
{
public:
	void Spawn( void );
	virtual void Precache( void );
	void RotSpawn( void );
	virtual void KeyValue( KeyValueData* pkvd);

	void ButtonActivate();
	void SparkSoundCache( void );

	void EXPORT ButtonShot( void );
	void EXPORT ButtonTouch( CBaseEntity *pOther );
	void EXPORT ButtonSpark( void );
	void EXPORT TriggerAndWait( void );
	void EXPORT ButtonReturn( void );
	void EXPORT ButtonBackHome( void );
	void EXPORT ButtonUse( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	virtual int TakeDamage( entvars_t* pevInflictor, entvars_t* pevAttacker, float flDamage, int bitsDamageType );
	virtual int Save( CSave &save );
	virtual int Restore( CRestore &restore );
	
	enum BUTTON_CODE { BUTTON_NOTHING, BUTTON_ACTIVATE, BUTTON_RETURN };
	BUTTON_CODE ButtonResponseToTouch( void );
	
	static	TYPEDESCRIPTION m_SaveData[];
	// Buttons that don't take damage can be IMPULSE used
	virtual int ObjectCaps( void ) { return (CBaseToggle:: ObjectCaps() & ~FCAP_ACROSS_TRANSITION) | (pev->takedamage?0:FCAP_IMPULSE_USE); }

	BOOL m_fStayPushed;	// button stays pushed in until touched again?
	BOOL m_fRotating;		// a rotating button?  default is a sliding button.

	string_t m_strChangeTarget;	// if this field is not null, this is an index into the engine string array.
							// when this button is touched, it's target entity's TARGET field will be set
							// to the button's ChangeTarget. This allows you to make a func_train switch paths, etc.

	locksound_t m_ls;			// door lock sounds
	
	BYTE m_bLockedSound;		// ordinals from entity selection
	BYTE m_bLockedSentence;	
	BYTE m_bUnlockedSound;	
	BYTE m_bUnlockedSentence;
	int m_sounds;
};

//
// Weapons 
//
#define	BAD_WEAPON 0x00007FFF

//
// Converts a entvars_t * to a class pointer
// It will allocate the class and entity if necessary
//
template <class T> T * GetClassPtr( T *a )
{
	entvars_t *pev = (entvars_t *)a;

	// allocate entity if necessary
	if( pev == NULL )
		pev = VARS( CREATE_ENTITY() );

	// get the private data
	a = (T *)GET_PRIVATE( ENT( pev ) );

	if( a == NULL ) 
	{
		// allocate private data 
		a = new( pev ) T;
		a->pev = pev;
	}
	return a;
}

/*
bit_PUSHBRUSH_DATA | bit_TOGGLE_DATA
bit_MONSTER_DATA
bit_DELAY_DATA
bit_TOGGLE_DATA | bit_DELAY_DATA | bit_MONSTER_DATA
bit_PLAYER_DATA | bit_MONSTER_DATA
bit_MONSTER_DATA | CYCLER_DATA
bit_LIGHT_DATA
path_corner_data
bit_MONSTER_DATA | wildcard_data
bit_MONSTER_DATA | bit_GROUP_DATA
boid_flock_data
boid_data
CYCLER_DATA
bit_ITEM_DATA
bit_ITEM_DATA | func_hud_data
bit_TOGGLE_DATA | bit_ITEM_DATA
EOFFSET
env_sound_data
env_sound_data
push_trigger_data
*/

#define TRACER_FREQ		4			// Tracers fire every 4 bullets

typedef struct _SelAmmo
{
	BYTE Ammo1Type;
	BYTE Ammo1;
	BYTE Ammo2Type;
	BYTE Ammo2;
} SelAmmo;

// this moved here from world.cpp, to allow classes to be derived from it
//=======================
// CWorld
//
// This spawns first when each level begins.
//=======================
#ifndef CLIENT_DLL
class CWorld : public CBaseEntity
{
public:
	void Spawn( void );
	void Precache( void );
	void KeyValue( KeyValueData *pkvd );
};
#endif
