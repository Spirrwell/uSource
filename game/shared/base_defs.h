/*
 *
 * base_defs.h - Base macros and enums for client and server
 *
 */
#pragma once

typedef enum
{
	USE_OFF = 0,
	USE_ON = 1,
	USE_SET = 2,
	USE_TOGGLE = 3
} USE_TYPE;
typedef USE_TYPE EUseType;

// More explicit than "int"
typedef int EOFFSET;

// In case it's not alread defined
typedef int BOOL;


//================================================================================================================================================//
#define		MAX_PATH_SIZE	10 // max number of nodes available for a path.
//================================================================================================================================================//


//================================================================================================================================================//
// These are caps bits to indicate what an object's capabilities (currently used for save/restore and level transitions)
#define		FCAP_CUSTOMSAVE				0x00000001
#define		FCAP_ACROSS_TRANSITION			0x00000002		// should transfer between transitions
#define		FCAP_MUST_SPAWN				0x00000004		// Spawn after restore
#define		FCAP_DONT_SAVE				0x80000000		// Don't save this
#define		FCAP_IMPULSE_USE			0x00000008		// can be used by the player
#define		FCAP_CONTINUOUS_USE			0x00000010		// can be used by the player
#define		FCAP_ONOFF_USE				0x00000020		// can be used by the player
#define		FCAP_DIRECTIONAL_USE			0x00000040		// Player sends +/- 1 when using (currently only tracktrains)
#define		FCAP_MASTER				0x00000080		// Can be used to "master" other entities (like multisource)

// UNDONE: This will ignore transition volumes (trigger_transition), but not the PVS!!!
#define		FCAP_FORCE_TRANSITION		0x00000080		// ALWAYS goes across transitions
//================================================================================================================================================//


//================================================================================================================================================//
// For CLASSIFY
#define	CLASS_NONE			0
#define CLASS_MACHINE			1
#define CLASS_PLAYER			2
#define	CLASS_HUMAN_PASSIVE		3
#define CLASS_HUMAN_MILITARY		4
#define CLASS_ALIEN_MILITARY		5
#define CLASS_ALIEN_PASSIVE		6
#define CLASS_ALIEN_MONSTER		7
#define CLASS_ALIEN_PREY		8
#define CLASS_ALIEN_PREDATOR		9
#define CLASS_INSECT			10
#define CLASS_PLAYER_ALLY		11
#define CLASS_PLAYER_BIOWEAPON		12 // hornets and snarks.launched by players
#define CLASS_ALIEN_BIOWEAPON		13 // hornets and snarks.launched by the alien menace
#define	CLASS_BARNACLE			99 // special because no one pays attention to it, and it eats a wide cross-section of creatures.
//================================================================================================================================================//


#define	SF_NORESPAWN	( 1 << 30 )// !!!set this bit on guns and stuff that should never respawn.

//================================================================================================================================================//
#define DMG_GENERIC			0			// generic damage was done
#define DMG_CRUSH			(1 << 0)	// crushed by falling or moving object
#define DMG_BULLET			(1 << 1)	// shot
#define DMG_SLASH			(1 << 2)	// cut, clawed, stabbed
#define DMG_BURN			(1 << 3)	// heat burned
#define DMG_FREEZE			(1 << 4)	// frozen
#define DMG_FALL			(1 << 5)	// fell too far
#define DMG_BLAST			(1 << 6)	// explosive blast damage
#define DMG_CLUB			(1 << 7)	// crowbar, punch, headbutt
#define DMG_SHOCK			(1 << 8)	// electric shock
#define DMG_SONIC			(1 << 9)	// sound pulse shockwave
#define DMG_ENERGYBEAM		(1 << 10)	// laser or other high energy beam
#define DMG_NEVERGIB		(1 << 12)	// with this bit OR'd in, no damage type will be able to gib victims upon death
#define DMG_ALWAYSGIB		(1 << 13)	// with this bit OR'd in, any damage type can be made to gib victims upon death.
#define DMG_DROWN			(1 << 14)	// Drowning
// time-based damage
#define DMG_TIMEBASED		(~(0x3fff))	// mask for time-based damage
#define DMG_PARALYZE		(1 << 15)	// slows affected creature down
#define DMG_NERVEGAS		(1 << 16)	// nerve toxins, very bad
#define DMG_POISON			(1 << 17)	// blood poisioning
#define DMG_RADIATION		(1 << 18)	// radiation exposure
#define DMG_DROWNRECOVER	(1 << 19)	// drowning recovery
#define DMG_ACID			(1 << 20)	// toxic chemicals or acid burns
#define DMG_SLOWBURN		(1 << 21)	// in an oven
#define DMG_SLOWFREEZE		(1 << 22)	// in a subzero freezer
#define DMG_MORTAR			(1 << 23)	// Hit by air raid (done to distinguish grenade from mortar)
// these are the damage types that are allowed to gib corpses
#define DMG_GIB_CORPSE		( DMG_CRUSH | DMG_FALL | DMG_BLAST | DMG_SONIC | DMG_CLUB )
// these are the damage types that have client hud art
#define DMG_SHOWNHUD		(DMG_POISON | DMG_ACID | DMG_FREEZE | DMG_SLOWFREEZE | DMG_DROWN | DMG_BURN | DMG_SLOWBURN | DMG_NERVEGAS | DMG_RADIATION | DMG_SHOCK)

#define PARALYZE_DURATION	2		// number of 2 second intervals to take damage
#define PARALYZE_DAMAGE		1.0		// damage to take each 2 second interval

#define NERVEGAS_DURATION	2
#define NERVEGAS_DAMAGE		5.0

#define POISON_DURATION		5
#define POISON_DAMAGE		2.0

#define RADIATION_DURATION	2
#define RADIATION_DAMAGE	1.0

#define ACID_DURATION		2
#define ACID_DAMAGE			5.0

#define SLOWBURN_DURATION	2
#define SLOWBURN_DAMAGE		1.0

#define SLOWFREEZE_DURATION	2
#define SLOWFREEZE_DAMAGE	1.0

#define	itbd_Paralyze		0
#define	itbd_NerveGas		1
#define	itbd_Poison			2
#define	itbd_Radiation		3
#define	itbd_DrownRecover	4
#define	itbd_Acid			5
#define	itbd_SlowBurn		6
#define	itbd_SlowFreeze		7
#define CDMG_TIMEBASED		8

// people gib if their health is <= this at the time of death
#define	GIB_HEALTH_VALUE	-30

// when calling KILLED(), a value that governs gib behavior is expected to be
// one of these three values
#define GIB_NORMAL			0// gib if entity was overkilled
#define GIB_NEVER			1// never gib, no matter how much death damage is done ( freezing, etc )
#define GIB_ALWAYS			2// always gib ( Houndeye Shock, Barnacle Bite )
//================================================================================================================================================//


//================================================================================================================================================//
#define	bits_CAP_DUCK			( 1 << 0 )// crouch
#define	bits_CAP_JUMP			( 1 << 1 )// jump/leap
#define bits_CAP_STRAFE			( 1 << 2 )// strafe ( walk/run sideways)
#define bits_CAP_SQUAD			( 1 << 3 )// can form squads
#define	bits_CAP_SWIM			( 1 << 4 )// proficiently navigate in water
#define bits_CAP_CLIMB			( 1 << 5 )// climb ladders/ropes
#define bits_CAP_USE			( 1 << 6 )// open doors/push buttons/pull levers
#define bits_CAP_HEAR			( 1 << 7 )// can hear forced sounds
#define bits_CAP_AUTO_DOORS		( 1 << 8 )// can trigger auto doors
#define bits_CAP_OPEN_DOORS		( 1 << 9 )// can open manual doors
#define bits_CAP_TURN_HEAD		( 1 << 10)// can turn head, always bone controller 0
#define bits_CAP_RANGE_ATTACK1	( 1 << 11)// can do a range attack 1
#define bits_CAP_RANGE_ATTACK2	( 1 << 12)// can do a range attack 2
#define bits_CAP_MELEE_ATTACK1	( 1 << 13)// can do a melee attack 1
#define bits_CAP_MELEE_ATTACK2	( 1 << 14)// can do a melee attack 2
#define bits_CAP_FLY			( 1 << 15)// can fly, move all around
#define bits_CAP_DOORS_GROUP    (bits_CAP_USE | bits_CAP_AUTO_DOORS | bits_CAP_OPEN_DOORS)
//================================================================================================================================================//

//================================================================================================================================================//
// New damage type enums

enum class EDamageType
{
	GENERIC			= 0,		// generic damage was done
	CRUSH			= (1 << 0),	// crushed by falling or moving object
	BULLET			= (1 << 1),	// shot
	SLASH			= (1 << 2),	// cut, clawed, stabbed
	BURN			= (1 << 3),	// heat burned
	FREEZE			= (1 << 4),	// frozen
	FALL			= (1 << 5),	// fell too far
	BLAST			= (1 << 6),	// explosive blast damage
	CLUB			= (1 << 7),	// crowbar, punch, headbutt
	SHOCK			= (1 << 8),	// electric shock
	SONIC			= (1 << 9),	// sound pulse shockwave
	ENERGYBEAM		= (1 << 10),	// laser or other high energy beam
	NEVERGIB		= (1 << 12),	// with this bit OR'd in, no damage type will be able to gib victims upon death
	ALWAYSGIB		= (1 << 13),	// with this bit OR'd in, any damage type can be made to gib victims upon death.
	DROWN			= (1 << 14),	// Drowning
	TIMEBASED		= (~(0x3fff)),	// mask for time-based damage
	PARALYZE		= (1 << 15),    // slows affected creature down
	NERVEGAS		= (1 << 16),    // nerve toxins, very bad
	POISON			= (1 << 17),    // blood poisioning
	RADIATION		= (1 << 18),    // radiation exposure
	DROWNRECOVER	        = (1 << 19),    // drowning recovery
	ACID			= (1 << 20),    // toxic chemicals or acid burns
	SLOWBURN		= (1 << 21),    // in an oven
	SLOWFREEZE		= (1 << 22),    // in a subzero freezer
	MORTAR			= (1 << 23),    // Hit by air raid (done to distinguish grenade from mortar)
	GIB_CORPSE		= ( CRUSH | FALL | BLAST | SONIC | CLUB ),
	SHOWNHUD		= ( POISON | ACID | FREEZE | SLOWFREEZE | DROWN | BURN | SLOWBURN | NERVEGAS | RADIATION | SHOCK),
};

//================================================================================================================================================//

