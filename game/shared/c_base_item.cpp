#include "c_base_item.h"
#include "c_base_player.h"

#ifdef SERVER_DLL
#include "gamerules.h"
extern int gEvilImpulse101;
#endif

void CBasePlayerItem::SetObjectCollisionBox( void )
{
	pev->absmin = pev->origin + Vector( -24, -24, 0 );
	pev->absmax = pev->origin + Vector( 24, 24, 16 );
}

//=========================================================
// Sets up movetype, size, solidtype for a new weapon.
//=========================================================
void CBasePlayerItem::FallInit( void )
{
	pev->movetype = MOVETYPE_TOSS;
	pev->solid = SOLID_BBOX;

	UTIL_SetOrigin( pev, pev->origin );
	UTIL_SetSize( pev, Vector( 0, 0, 0 ), Vector( 0, 0, 0 ) );//pointsize until it lands on the ground.

	SetTouch( &CBasePlayerItem::DefaultTouch );
	SetThink( &CBasePlayerItem::FallThink );

	pev->nextthink = gpGlobals->time + 0.1;
}

//=========================================================
// FallThink - Items that have just spawned run this think
// to catch them when they hit the ground. Once we're sure
// that the object is grounded, we change its solid type
// to trigger and set it in a large box that helps the
// player get it.
//=========================================================
void CBasePlayerItem::FallThink( void )
{
#ifdef SERVER_DLL
	pev->nextthink = gpGlobals->time + 0.1;

	if( pev->flags & FL_ONGROUND )
	{
		// clatter if we have an owner (i.e., dropped by someone)
		// don't clatter if the gun is waiting to respawn (if it's waiting, it is invisible!)
		if( !FNullEnt( pev->owner ) )
		{
			int pitch = 95 + RANDOM_LONG( 0, 29 );
			EMIT_SOUND_DYN( ENT( pev ), CHAN_VOICE, "items/weapondrop1.wav", 1, ATTN_NORM, 0, pitch );
		}

		// lie flat
		pev->angles.x = 0;
		pev->angles.z = 0;

		Materialize();
	}
#endif
}

//=========================================================
// Materialize - make a CBasePlayerItem visible and tangible
//=========================================================
void CBasePlayerItem::Materialize( void )
{
	if( pev->effects & EF_NODRAW )
	{
		// changing from invisible state to visible.
		EMIT_SOUND_DYN( ENT( pev ), CHAN_WEAPON, "items/suitchargeok1.wav", 1, ATTN_NORM, 0, 150 );
		pev->effects &= ~EF_NODRAW;
		pev->effects |= EF_MUZZLEFLASH;
	}

	pev->solid = SOLID_TRIGGER;

	UTIL_SetOrigin( pev, pev->origin );// link into world.
	SetTouch( &CBasePlayerItem::DefaultTouch );
	SetThink( NULL );
}

//=========================================================
// AttemptToMaterialize - the item is trying to rematerialize,
// should it do so now or wait longer?
//=========================================================
void CBasePlayerItem::AttemptToMaterialize( void )
{
#ifdef SERVER_DLL
	float time = g_pGameRules->FlWeaponTryRespawn( this );

	if( time == 0 )
	{
		Materialize();
		return;
	}

	pev->nextthink = gpGlobals->time + time;
#endif
}

//=========================================================
// CheckRespawn - a player is taking this weapon, should
// it respawn?
//=========================================================
void CBasePlayerItem::CheckRespawn( void )
{
#ifdef SERVER_DLL
	switch( g_pGameRules->WeaponShouldRespawn( this ) )
	{
		case GR_WEAPON_RESPAWN_YES:
			Respawn();
			break;
		case GR_WEAPON_RESPAWN_NO:
			return;
			break;
	}
#endif
}

//=========================================================
// Respawn- this item is already in the world, but it is
// invisible and intangible. Make it visible and tangible.
//=========================================================
CBaseEntity* CBasePlayerItem::Respawn( void )
{
#ifdef SERVER_DLL
	// make a copy of this weapon that is invisible and inaccessible to players (no touch function). The weapon spawn/respawn code
	// will decide when to make the weapon visible and touchable.
	CBaseEntity *pNewWeapon = CBaseEntity::Create( STRING( pev->classname ), g_pGameRules->VecWeaponRespawnSpot( this ), pev->angles, pev->owner );

	if( pNewWeapon )
	{
		pNewWeapon->pev->effects |= EF_NODRAW;// invisible for now
		pNewWeapon->SetTouch( NULL );// no touch
		pNewWeapon->SetThink( &CBasePlayerItem::AttemptToMaterialize );

		DROP_TO_FLOOR( ENT( pev ) );

		// not a typo! We want to know when the weapon the player just picked up should respawn! This new entity we created is the replacement,
		// but when it should respawn is based on conditions belonging to the weapon that was taken.
		pNewWeapon->pev->nextthink = g_pGameRules->FlWeaponRespawnTime( this );
	}
	else
	{
		ALERT( at_console, "Respawn failed to create %s!\n", STRING( pev->classname ) );
	}

	return pNewWeapon;
#else
	return nullptr;
#endif
}

void CBasePlayerItem::DefaultTouch( CBaseEntity *pOther )
{
#ifdef SERVER_DLL
	// if it's not a player, ignore
	if( !pOther->IsPlayer() )
		return;

	CBasePlayer *pPlayer = (CBasePlayer *)pOther;

	// can I have this?
	if( !g_pGameRules->CanHavePlayerItem( pPlayer, this ) )
	{
		if( gEvilImpulse101 )
		{
			UTIL_Remove( this );
		}
		return;
	}

	if( pOther->AddPlayerItem( this ) )
	{
		AttachToPlayer( pPlayer );
		EMIT_SOUND( ENT( pPlayer->pev ), CHAN_ITEM, "items/gunpickup2.wav", 1, ATTN_NORM );
	}

	SUB_UseTargets( pOther, USE_TOGGLE, 0 ); // UNDONE: when should this happen?
#endif
}


void CBasePlayerItem::DestroyItem( void )
{
	if( m_pPlayer )
	{
		// if attached to a player, remove.
		m_pPlayer->RemovePlayerItem( this, false );
	}

	Kill();
}

int CBasePlayerItem::AddToPlayer( CBasePlayer *pPlayer )
{
	m_pPlayer = pPlayer;

	return TRUE;
}

void CBasePlayerItem::Drop( void )
{
	SetTouch( NULL );
	SetThink( &CBaseEntity::SUB_Remove );
	pev->nextthink = gpGlobals->time + .1;
}

void CBasePlayerItem::Kill( void )
{
	SetTouch( NULL );
	SetThink( &CBaseEntity::SUB_Remove );
	pev->nextthink = gpGlobals->time + .1;
}

void CBasePlayerItem::Holster( int skiplocal /* = 0 */ )
{
#ifdef SERVER_DLL
	m_pPlayer->pev->viewmodel = 0;
	m_pPlayer->pev->weaponmodel = 0;
#endif
}

void CBasePlayerItem::AttachToPlayer( CBasePlayer *pPlayer )
{
	pev->movetype = MOVETYPE_FOLLOW;
	pev->solid = SOLID_NOT;
	pev->aiment = pPlayer->edict();
	pev->effects = EF_NODRAW; // ??
	pev->modelindex = 0;// server won't send down to clients if modelindex == 0
	pev->model = iStringNull;
	pev->owner = pPlayer->edict();
	pev->nextthink = 0;// Remove think - prevents futher attempts to materialize
	SetTouch( NULL );
	SetThink( NULL );
}
