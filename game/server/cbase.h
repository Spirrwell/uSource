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
#include "c_point_entity.h"

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

#define MAX_DELAY_CALLS 4

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
