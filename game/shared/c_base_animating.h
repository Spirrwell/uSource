#pragma once

#include "game_shared.h"
#include "c_base_entity.h"
#include "c_point_entity.h"
#include "ai_shared.h"

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