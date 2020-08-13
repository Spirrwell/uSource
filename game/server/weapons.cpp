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
/*

===== weapons.cpp ========================================================

  functions governing the selection/use of weapons for players

*/

#include "weapons.h"
#include "c_base_item.h"
#include "cbase.h"
#include "crtlib.h"
#include "decals.h"
#include "extdll.h"
#include "game/server/ai/ai_monsters.h"
#include "gamerules.h"
#include "info_node.h"
#include "player.h"
#include "soundent.h"
#include "util.h"

#include "hl1/weapon_crossbow.h"
#include "hl1/weapon_crowbar.h"
#include "hl1/weapon_egon.h"
#include "hl1/weapon_frag.h"
#include "hl1/weapon_gauss.h"
#include "hl1/weapon_glock.h"
#include "hl1/weapon_hornetgun.h"
#include "hl1/weapon_mp5.h"
#include "hl1/weapon_python.h"
#include "hl1/weapon_rpg.h"
#include "hl1/weapon_satchel.h"
#include "hl1/weapon_shotgun.h"
#include "hl1/weapon_squeakgrenade.h"
#include "hl1/weapon_tripmine.h"

extern CGraph WorldGraph;
extern int    gEvilImpulse101;

#define NOT_USED 255

DLL_GLOBAL short       g_sModelIndexLaser; // holds the index for the laser beam
DLL_GLOBAL const char* g_pModelNameLaser = "sprites/laserbeam.spr";
DLL_GLOBAL short       g_sModelIndexLaserDot;	// holds the index for the laser beam dot
DLL_GLOBAL short       g_sModelIndexFireball;	// holds the index for the fireball
DLL_GLOBAL short       g_sModelIndexSmoke;	// holds the index for the smoke cloud
DLL_GLOBAL short       g_sModelIndexWExplosion; // holds the index for the underwater explosion
DLL_GLOBAL short       g_sModelIndexBubbles;	// holds the index for the bubbles model
DLL_GLOBAL short       g_sModelIndexBloodDrop;	// holds the sprite index for the initial blood
DLL_GLOBAL short       g_sModelIndexBloodSpray; // holds the sprite index for splattered blood

ItemInfo CBasePlayerItem::ItemInfoArray[MAX_WEAPONS];
AmmoInfo CBasePlayerItem::AmmoInfoArray[MAX_AMMO_SLOTS];

extern int gmsgCurWeapon;

MULTIDAMAGE gMultiDamage;

#define TRACER_FREQ 4 // Tracers fire every fourth bullet

//=========================================================
// MaxAmmoCarry - pass in a name and this function will tell
// you the maximum amount of that type of ammunition that a
// player can carry.
//=========================================================
int MaxAmmoCarry(int iszName)
{
	for (int i = 0; i < MAX_WEAPONS; i++)
	{
		if (CBasePlayerItem::ItemInfoArray[i].pszAmmo1 && !strcmp(STRING(iszName), CBasePlayerItem::ItemInfoArray[i].pszAmmo1))
			return CBasePlayerItem::ItemInfoArray[i].iMaxAmmo1;
		if (CBasePlayerItem::ItemInfoArray[i].pszAmmo2 && !strcmp(STRING(iszName), CBasePlayerItem::ItemInfoArray[i].pszAmmo2))
			return CBasePlayerItem::ItemInfoArray[i].iMaxAmmo2;
	}

	ALERT(at_console, "MaxAmmoCarry() doesn't recognize '%s'!\n", STRING(iszName));
	return -1;
}

/*
==============================================================================

MULTI-DAMAGE

Collects multiple small damages into a single damage

==============================================================================
*/

//
// ClearMultiDamage - resets the global multi damage accumulator
//
void ClearMultiDamage(void)
{
	gMultiDamage.pEntity = NULL;
	gMultiDamage.amount  = 0;
	gMultiDamage.type    = 0;
}

//
// ApplyMultiDamage - inflicts contents of global multi damage register on gMultiDamage.pEntity
//
// GLOBALS USED:
//		gMultiDamage
void ApplyMultiDamage(entvars_t* pevInflictor, entvars_t* pevAttacker)
{
	Vector	    vecSpot1; // where blood comes from
	Vector	    vecDir;   // direction blood should go
	TraceResult tr;

	if (!gMultiDamage.pEntity)
		return;

	gMultiDamage.pEntity->TakeDamage(pevInflictor, pevAttacker, gMultiDamage.amount, gMultiDamage.type);
}

// GLOBALS USED:
//		gMultiDamage
void AddMultiDamage(entvars_t* pevInflictor, CBaseEntity* pEntity, float flDamage, int bitsDamageType)
{
	if (!pEntity)
		return;

	gMultiDamage.type |= bitsDamageType;

	if (pEntity != gMultiDamage.pEntity)
	{
		ApplyMultiDamage(pevInflictor, pevInflictor); // UNDONE: wrong attacker!
		gMultiDamage.pEntity = pEntity;
		gMultiDamage.amount  = 0;
	}

	gMultiDamage.amount += flDamage;
}

/*
================
SpawnBlood
================
*/
void SpawnBlood(Vector vecSpot, int bloodColor, float flDamage) { UTIL_BloodDrips(vecSpot, g_vecAttackDir, bloodColor, (int)flDamage); }

int DamageDecal(CBaseEntity* pEntity, int bitsDamageType)
{
	if (!pEntity)
		return (DECAL_GUNSHOT1 + RANDOM_LONG(0, 4));

	return pEntity->DamageDecal(bitsDamageType);
}

void DecalGunshot(TraceResult* pTrace, int iBulletType)
{
	// Is the entity valid
	if (!UTIL_IsValidEntity(pTrace->pHit))
		return;

	if (VARS(pTrace->pHit)->solid == SOLID_BSP || VARS(pTrace->pHit)->movetype == MOVETYPE_PUSHSTEP)
	{
		CBaseEntity* pEntity = NULL;
		// Decal the wall with a gunshot
		if (!FNullEnt(pTrace->pHit))
			pEntity = CBaseEntity::Instance(pTrace->pHit);

		switch (iBulletType)
		{
		case BULLET_PLAYER_9MM:
		case BULLET_MONSTER_9MM:
		case BULLET_PLAYER_MP5:
		case BULLET_MONSTER_MP5:
		case BULLET_PLAYER_BUCKSHOT:
		case BULLET_PLAYER_357:
		default:
			// smoke and decal
			UTIL_GunshotDecalTrace(pTrace, DamageDecal(pEntity, DMG_BULLET));
			break;
		case BULLET_MONSTER_12MM:
			// smoke and decal
			UTIL_GunshotDecalTrace(pTrace, DamageDecal(pEntity, DMG_BULLET));
			break;
		case BULLET_PLAYER_CROWBAR:
			// wall decal
			UTIL_DecalTrace(pTrace, DamageDecal(pEntity, DMG_CLUB));
			break;
		}
	}
}

//
// EjectBrass - tosses a brass shell from passed origin at passed velocity
//
void EjectBrass(const Vector& vecOrigin, const Vector& vecVelocity, float rotation, int model, int soundtype)
{
	// FIX: when the player shoots, their gun isn't in the same position as it is on the model other players see.
	MESSAGE_BEGIN(MSG_PVS, SVC_TEMPENTITY, vecOrigin);
	WRITE_BYTE(TE_MODEL);
	WRITE_COORD(vecOrigin.x);
	WRITE_COORD(vecOrigin.y);
	WRITE_COORD(vecOrigin.z);
	WRITE_COORD(vecVelocity.x);
	WRITE_COORD(vecVelocity.y);
	WRITE_COORD(vecVelocity.z);
	WRITE_ANGLE(rotation);
	WRITE_SHORT(model);
	WRITE_BYTE(soundtype);
	WRITE_BYTE(25); // 2.5 seconds
	MESSAGE_END();
}

int giAmmoIndex = 0;

// Precaches the ammo and queues the ammo info for sending to clients
void AddAmmoNameToAmmoRegistry(const char* szAmmoname)
{
	// make sure it's not already in the registry
	for (int i = 0; i < MAX_AMMO_SLOTS; i++)
	{
		if (!CBasePlayerItem::AmmoInfoArray[i].pszName)
			continue;

		if (Q_stricmp(CBasePlayerItem::AmmoInfoArray[i].pszName, szAmmoname) == 0)
			return; // ammo already in registry, just quite
	}

	giAmmoIndex++;
	ASSERT(giAmmoIndex < MAX_AMMO_SLOTS);
	if (giAmmoIndex >= MAX_AMMO_SLOTS)
		giAmmoIndex = 0;

	CBasePlayerItem::AmmoInfoArray[giAmmoIndex].pszName = szAmmoname;
	CBasePlayerItem::AmmoInfoArray[giAmmoIndex].iId	    = giAmmoIndex; // yes, this info is redundant
}

// Precaches the weapon and queues the weapon info for sending to clients
void UTIL_PrecacheOtherWeapon(const char* szClassname)
{
	edict_t* pent;

	pent = CREATE_NAMED_ENTITY(MAKE_STRING(szClassname));
	if (FNullEnt(pent))
	{
		ALERT(at_console, "NULL Ent in UTIL_PrecacheOtherWeapon\n");
		return;
	}

	CBaseEntity* pEntity = CBaseEntity::Instance(VARS(pent));

	if (pEntity)
	{
		ItemInfo II = {0};
		pEntity->Precache();
		if (((CBasePlayerItem*)pEntity)->GetItemInfo(&II))
		{
			CBasePlayerItem::ItemInfoArray[II.iId] = II;

			if (II.pszAmmo1 && *II.pszAmmo1)
			{
				AddAmmoNameToAmmoRegistry(II.pszAmmo1);
			}

			if (II.pszAmmo2 && *II.pszAmmo2)
			{
				AddAmmoNameToAmmoRegistry(II.pszAmmo2);
			}
		}
	}

	REMOVE_ENTITY(pent);
}

// called by worldspawn
void W_Precache(void)
{
	memset(CBasePlayerItem::ItemInfoArray, 0, sizeof(CBasePlayerItem::ItemInfoArray));
	memset(CBasePlayerItem::AmmoInfoArray, 0, sizeof(CBasePlayerItem::AmmoInfoArray));
	giAmmoIndex = 0;

	// custom items...

	// common world objects
	UTIL_PrecacheOther("item_suit");
	UTIL_PrecacheOther("item_healthkit");
	UTIL_PrecacheOther("item_battery");
	UTIL_PrecacheOther("item_antidote");
	UTIL_PrecacheOther("item_security");
	UTIL_PrecacheOther("item_longjump");

	// shotgun
	UTIL_PrecacheOtherWeapon("weapon_shotgun");
	UTIL_PrecacheOther("ammo_buckshot");

	// crowbar
	UTIL_PrecacheOtherWeapon("weapon_crowbar");

	// glock
	UTIL_PrecacheOtherWeapon("weapon_9mmhandgun");
	UTIL_PrecacheOther("ammo_9mmclip");

	// mp5
	UTIL_PrecacheOtherWeapon("weapon_9mmAR");
	UTIL_PrecacheOther("ammo_9mmAR");
	UTIL_PrecacheOther("ammo_ARgrenades");

	// 9mm ammo box
	UTIL_PrecacheOther("ammo_9mmbox");

#if !defined(OEM_BUILD) && !defined(HLDEMO_BUILD)
	// python
	UTIL_PrecacheOtherWeapon("weapon_357");
	UTIL_PrecacheOther("ammo_357");

	// gauss
	UTIL_PrecacheOtherWeapon("weapon_gauss");
	UTIL_PrecacheOther("ammo_gaussclip");

	// rpg
	UTIL_PrecacheOtherWeapon("weapon_rpg");
	UTIL_PrecacheOther("ammo_rpgclip");

	// crossbow
	UTIL_PrecacheOtherWeapon("weapon_crossbow");
	UTIL_PrecacheOther("ammo_crossbow");

	// egon
	UTIL_PrecacheOtherWeapon("weapon_egon");
#endif
	// tripmine
	UTIL_PrecacheOtherWeapon("weapon_tripmine");
#if !defined(OEM_BUILD) && !defined(HLDEMO_BUILD)
	// satchel charge
	UTIL_PrecacheOtherWeapon("weapon_satchel");
#endif
	// hand grenade
	UTIL_PrecacheOtherWeapon("weapon_handgrenade");
#if !defined(OEM_BUILD) && !defined(HLDEMO_BUILD)
	// squeak grenade
	UTIL_PrecacheOtherWeapon("weapon_snark");

	// hornetgun
	UTIL_PrecacheOtherWeapon("weapon_hornetgun");

	if (g_pGameRules->IsDeathmatch())
	{
		UTIL_PrecacheOther("weaponbox"); // container for dropped deathmatch weapons
	}
#endif
	g_sModelIndexFireball	= PRECACHE_MODEL("sprites/zerogxplode.spr"); // fireball
	g_sModelIndexWExplosion = PRECACHE_MODEL("sprites/WXplo1.spr");	     // underwater fireball
	g_sModelIndexSmoke	= PRECACHE_MODEL("sprites/steam1.spr");	     // smoke
	g_sModelIndexBubbles	= PRECACHE_MODEL("sprites/bubble.spr");	     // bubbles
	g_sModelIndexBloodSpray = PRECACHE_MODEL("sprites/bloodspray.spr");  // initial blood
	g_sModelIndexBloodDrop	= PRECACHE_MODEL("sprites/blood.spr");	     // splattered blood

	g_sModelIndexLaser    = PRECACHE_MODEL(g_pModelNameLaser);
	g_sModelIndexLaserDot = PRECACHE_MODEL("sprites/laserdot.spr");

	// used by explosions
	PRECACHE_MODEL("models/grenade.mdl");
	PRECACHE_MODEL("sprites/explode1.spr");

	PRECACHE_SOUND("weapons/debris1.wav"); // explosion aftermaths
	PRECACHE_SOUND("weapons/debris2.wav"); // explosion aftermaths
	PRECACHE_SOUND("weapons/debris3.wav"); // explosion aftermaths

	PRECACHE_SOUND("weapons/grenade_hit1.wav"); // grenade
	PRECACHE_SOUND("weapons/grenade_hit2.wav"); // grenade
	PRECACHE_SOUND("weapons/grenade_hit3.wav"); // grenade

	PRECACHE_SOUND("weapons/bullet_hit1.wav"); // hit by bullet
	PRECACHE_SOUND("weapons/bullet_hit2.wav"); // hit by bullet

	PRECACHE_SOUND("items/weapondrop1.wav"); // weapon falls to the ground
}

void CBasePlayerAmmo::Spawn(void)
{
	pev->movetype = MOVETYPE_TOSS;
	pev->solid    = SOLID_TRIGGER;
	UTIL_SetSize(pev, Vector(-16, -16, 0), Vector(16, 16, 16));
	UTIL_SetOrigin(pev, pev->origin);

	SetTouch(&CBasePlayerAmmo::DefaultTouch);
}

CBaseEntity* CBasePlayerAmmo::Respawn(void)
{
	pev->effects |= EF_NODRAW;
	SetTouch(NULL);

	UTIL_SetOrigin(pev, g_pGameRules->VecAmmoRespawnSpot(this)); // move to wherever I'm supposed to repawn.

	SetThink(&CBasePlayerAmmo::Materialize);
	pev->nextthink = g_pGameRules->FlAmmoRespawnTime(this);

	return this;
}

void CBasePlayerAmmo::Materialize(void)
{
	if (pev->effects & EF_NODRAW)
	{
		// changing from invisible state to visible.
		EMIT_SOUND_DYN(ENT(pev), CHAN_WEAPON, "items/suitchargeok1.wav", 1, ATTN_NORM, 0, 150);
		pev->effects &= ~EF_NODRAW;
		pev->effects |= EF_MUZZLEFLASH;
	}

	SetTouch(&CBasePlayerAmmo::DefaultTouch);
	SetThink(NULL);
}

void CBasePlayerAmmo::DefaultTouch(CBaseEntity* pOther)
{
	if (!pOther->IsPlayer())
	{
		return;
	}

	if (AddAmmo(pOther))
	{
		if (g_pGameRules->AmmoShouldRespawn(this) == GR_AMMO_RESPAWN_YES)
		{
			Respawn();
		}
		else
		{
			SetTouch(NULL);
			SetThink(&CBaseEntity::SUB_Remove);
			pev->nextthink = gpGlobals->time + .1;
		}
	}
	else if (gEvilImpulse101)
	{
		// evil impulse 101 hack, kill always
		SetTouch(NULL);
		SetThink(&CBaseEntity::SUB_Remove);
		pev->nextthink = gpGlobals->time + .1;
	}
}

//*********************************************************
// weaponbox code:
//*********************************************************

LINK_ENTITY_TO_CLASS(weaponbox, CWeaponBox)

TYPEDESCRIPTION CWeaponBox::m_SaveData[] = {
	DEFINE_ARRAY(CWeaponBox, m_rgAmmo, FIELD_INTEGER, MAX_AMMO_SLOTS),
	DEFINE_ARRAY(CWeaponBox, m_rgiszAmmo, FIELD_STRING, MAX_AMMO_SLOTS),
	DEFINE_ARRAY(CWeaponBox, m_rgpPlayerItems, FIELD_CLASSPTR, MAX_ITEM_TYPES),
	DEFINE_FIELD(CWeaponBox, m_cAmmoTypes, FIELD_INTEGER),
};

IMPLEMENT_SAVERESTORE(CWeaponBox, CBaseEntity)

//=========================================================
//
//=========================================================
void CWeaponBox::Precache(void) { PRECACHE_MODEL("models/w_weaponbox.mdl"); }

//=========================================================
//=========================================================
void CWeaponBox::KeyValue(KeyValueData* pkvd)
{
	if (m_cAmmoTypes < MAX_AMMO_SLOTS)
	{
		PackAmmo(ALLOC_STRING(pkvd->szKeyName), atoi(pkvd->szValue));
		m_cAmmoTypes++; // count this new ammo type.

		pkvd->fHandled = TRUE;
	}
	else
	{
		ALERT(at_console, "WeaponBox too full! only %d ammotypes allowed\n", MAX_AMMO_SLOTS);
	}
}

//=========================================================
// CWeaponBox - Spawn
//=========================================================
void CWeaponBox::Spawn(void)
{
	Precache();

	pev->movetype = MOVETYPE_TOSS;
	pev->solid    = SOLID_TRIGGER;

	UTIL_SetSize(pev, g_vecZero, g_vecZero);

	SET_MODEL(ENT(pev), "models/w_weaponbox.mdl");
}

//=========================================================
// CWeaponBox - Kill - the think function that removes the
// box from the world.
//=========================================================
void CWeaponBox::Kill(void)
{
	CBasePlayerItem* pWeapon;
	int		 i;

	// destroy the weapons
	for (i = 0; i < MAX_ITEM_TYPES; i++)
	{
		pWeapon = m_rgpPlayerItems[i];

		while (pWeapon)
		{
			pWeapon->SetThink(&CBaseEntity::SUB_Remove);
			pWeapon->pev->nextthink = gpGlobals->time + 0.1;
			pWeapon			= pWeapon->m_pNext;
		}
	}

	// remove the box
	UTIL_Remove(this);
}

static const char* IsAmmoForExhaustibleWeapon(const char* ammoName, int& weaponId)
{
	for (int i = 0; i < MAX_WEAPONS; ++i)
	{
		ItemInfo& II = CBasePlayerItem::ItemInfoArray[i];
		if ((II.iFlags & ITEM_FLAG_EXHAUSTIBLE) && II.pszAmmo1 && FStrEq(ammoName, II.pszAmmo1))
		{
			weaponId = II.iId;
			return II.pszName;
		}
	}
	return 0;
}

//=========================================================
// CWeaponBox - Touch: try to add my contents to the toucher
// if the toucher is a player.
//=========================================================
void CWeaponBox::Touch(CBaseEntity* pOther)
{
	if (!(pev->flags & FL_ONGROUND))
	{
		return;
	}

	if (!pOther->IsPlayer())
	{
		// only players may touch a weaponbox.
		return;
	}

	if (!pOther->IsAlive())
	{
		// no dead guys.
		return;
	}

	CBasePlayer* pPlayer = (CBasePlayer*)pOther;
	int	     i;

	// dole out ammo
	for (i = 0; i < MAX_AMMO_SLOTS; i++)
	{
		if (!FStringNull(m_rgiszAmmo[i]))
		{
			// horrific HACK to give player an exhaustible weapon as a real weapon, not just ammo
			int	    exhaustibleWeaponId;
			const char* weaponName = IsAmmoForExhaustibleWeapon(STRING(m_rgiszAmmo[i]), exhaustibleWeaponId);
			if (weaponName)
			{
				bool foundWeapon = false;
				for (int j = 0; j < MAX_ITEM_TYPES && !foundWeapon; j++)
				{
					CBasePlayerItem* pPlayerItem = pPlayer->m_rgpPlayerItems[j];
					while (pPlayerItem)
					{
						if (pPlayerItem->m_iId == exhaustibleWeaponId)
						{
							foundWeapon = true;
							break;
						}
						pPlayerItem = pPlayerItem->m_pNext;
					}
				}
				if (!foundWeapon)
				{
					CBasePlayerWeapon* weapon = (CBasePlayerWeapon*)Create(weaponName, pev->origin, pev->angles);
					if (weapon)
					{
						weapon->pev->spawnflags |= SF_NORESPAWN;
						weapon->m_iDefaultAmmo = 0;
						if (pPlayer->AddPlayerItem(weapon))
						{
							weapon->AttachToPlayer(pPlayer);
						}
					}
				}
			}

			// there's some ammo of this type.
			pPlayer->GiveAmmo(m_rgAmmo[i], STRING(m_rgiszAmmo[i]), MaxAmmoCarry(m_rgiszAmmo[i]));

			// ALERT( at_console, "Gave %d rounds of %s\n", m_rgAmmo[i], STRING( m_rgiszAmmo[i] ) );

			// now empty the ammo from the weaponbox since we just gave it to the player
			m_rgiszAmmo[i] = iStringNull;
			m_rgAmmo[i]    = 0;
		}
	}

	// go through my weapons and try to give the usable ones to the player.
	// it's important the the player be given ammo first, so the weapons code doesn't refuse
	// to deploy a better weapon that the player may pick up because he has no ammo for it.
	for (i = 0; i < MAX_ITEM_TYPES; i++)
	{
		if (m_rgpPlayerItems[i])
		{
			CBasePlayerItem* pItem;

			// have at least one weapon in this slot
			while (m_rgpPlayerItems[i])
			{
				// ALERT( at_console, "trying to give %s\n", STRING( m_rgpPlayerItems[i]->pev->classname ) );

				pItem		    = m_rgpPlayerItems[i];
				m_rgpPlayerItems[i] = m_rgpPlayerItems[i]->m_pNext; // unlink this weapon from the box

				if (pPlayer->AddPlayerItem(pItem))
				{
					pItem->AttachToPlayer(pPlayer);
				}
			}
		}
	}

	EMIT_SOUND(pOther->edict(), CHAN_ITEM, "items/gunpickup2.wav", 1, ATTN_NORM);
	SetTouch(NULL);
	UTIL_Remove(this);
}

//=========================================================
// CWeaponBox - PackWeapon: Add this weapon to the box
//=========================================================
BOOL CWeaponBox::PackWeapon(CBasePlayerItem* pWeapon)
{
	// is one of these weapons already packed in this box?
	if (HasWeapon(pWeapon))
	{
		return FALSE; // box can only hold one of each weapon type
	}

	if (pWeapon->m_pPlayer)
	{
		if (!pWeapon->m_pPlayer->RemovePlayerItem(pWeapon, true))
		{
			// failed to unhook the weapon from the player!
			return FALSE;
		}
	}

	int iWeaponSlot = pWeapon->iItemSlot();

	if (m_rgpPlayerItems[iWeaponSlot])
	{
		// there's already one weapon in this slot, so link this into the slot's column
		pWeapon->m_pNext	      = m_rgpPlayerItems[iWeaponSlot];
		m_rgpPlayerItems[iWeaponSlot] = pWeapon;
	}
	else
	{
		// first weapon we have for this slot
		m_rgpPlayerItems[iWeaponSlot] = pWeapon;
		pWeapon->m_pNext	      = NULL;
	}

	pWeapon->pev->spawnflags |= SF_NORESPAWN; // never respawn
	pWeapon->pev->movetype	 = MOVETYPE_NONE;
	pWeapon->pev->solid	 = SOLID_NOT;
	pWeapon->pev->effects	 = EF_NODRAW;
	pWeapon->pev->modelindex = 0;
	pWeapon->pev->model	 = iStringNull;
	pWeapon->pev->owner	 = edict();
	pWeapon->SetThink(NULL); // crowbar may be trying to swing again, etc.
	pWeapon->SetTouch(NULL);
	pWeapon->m_pPlayer = NULL;

	// ALERT( at_console, "packed %s\n", STRING( pWeapon->pev->classname ) );

	return TRUE;
}

//=========================================================
// CWeaponBox - PackAmmo
//=========================================================
BOOL CWeaponBox::PackAmmo(int iszName, int iCount)
{
	int iMaxCarry;

	if (FStringNull(iszName))
	{
		// error here
		ALERT(at_console, "NULL String in PackAmmo!\n");
		return FALSE;
	}

	iMaxCarry = MaxAmmoCarry(iszName);

	if (iMaxCarry != -1 && iCount > 0)
	{
		// ALERT( at_console, "Packed %d rounds of %s\n", iCount, STRING( iszName ) );
		GiveAmmo(iCount, STRING(iszName), iMaxCarry);
		return TRUE;
	}

	return FALSE;
}

//=========================================================
// CWeaponBox - GiveAmmo
//=========================================================
int CWeaponBox::GiveAmmo(int iCount, const char* szName, int iMax, int* pIndex /* = NULL*/)
{
	int i;

	for (i = 1; i < MAX_AMMO_SLOTS && !FStringNull(m_rgiszAmmo[i]); i++)
	{
		if (Q_stricmp(szName, STRING(m_rgiszAmmo[i])) == 0)
		{
			if (pIndex)
				*pIndex = i;

			int iAdd = Q_min(iCount, iMax - m_rgAmmo[i]);
			if (iCount == 0 || iAdd > 0)
			{
				m_rgAmmo[i] += iAdd;

				return i;
			}
			return -1;
		}
	}
	if (i < MAX_AMMO_SLOTS)
	{
		if (pIndex)
			*pIndex = i;

		m_rgiszAmmo[i] = MAKE_STRING(szName);
		m_rgAmmo[i]    = iCount;

		return i;
	}
	ALERT(at_console, "out of named ammo slots\n");
	return i;
}

//=========================================================
// CWeaponBox::HasWeapon - is a weapon of this type already
// packed in this box?
//=========================================================
BOOL CWeaponBox::HasWeapon(CBasePlayerItem* pCheckItem)
{
	CBasePlayerItem* pItem = m_rgpPlayerItems[pCheckItem->iItemSlot()];

	while (pItem)
	{
		if (FClassnameIs(pItem->pev, STRING(pCheckItem->pev->classname)))
		{
			return TRUE;
		}
		pItem = pItem->m_pNext;
	}

	return FALSE;
}

//=========================================================
// CWeaponBox::IsEmpty - is there anything in this box?
//=========================================================
BOOL CWeaponBox::IsEmpty(void)
{
	int i;

	for (i = 0; i < MAX_ITEM_TYPES; i++)
	{
		if (m_rgpPlayerItems[i])
		{
			return FALSE;
		}
	}

	for (i = 0; i < MAX_AMMO_SLOTS; i++)
	{
		if (!FStringNull(m_rgiszAmmo[i]))
		{
			// still have a bit of this type of ammo
			return FALSE;
		}
	}

	return TRUE;
}

//=========================================================
//=========================================================
void CWeaponBox::SetObjectCollisionBox(void)
{
	pev->absmin = pev->origin + Vector(-16, -16, 0);
	pev->absmax = pev->origin + Vector(16, 16, 16);
}

void CBasePlayerWeapon::PrintState(void)
{
	ALERT(at_console, "primary:  %f\n", m_flNextPrimaryAttack);
	ALERT(at_console, "idle   :  %f\n", m_flTimeWeaponIdle);

	// ALERT( at_console, "nextrl :  %f\n", m_flNextReload );
	// ALERT( at_console, "nextpum:  %f\n", m_flPumpTime );

	// ALERT( at_console, "m_frt  :  %f\n", m_fReloadTime );
	ALERT(at_console, "m_finre:  %i\n", m_fInReload);
	// ALERT( at_console, "m_finsr:  %i\n", m_fInSpecialReload );

	ALERT(at_console, "m_iclip:  %i\n", m_iClip);
}

TYPEDESCRIPTION CRpg::m_SaveData[] = {
	DEFINE_FIELD(CRpg, m_fSpotActive, FIELD_INTEGER),
	DEFINE_FIELD(CRpg, m_cActiveRockets, FIELD_INTEGER),
};

IMPLEMENT_SAVERESTORE(CRpg, CBasePlayerWeapon)

TYPEDESCRIPTION CRpgRocket::m_SaveData[] = {
	DEFINE_FIELD(CRpgRocket, m_flIgniteTime, FIELD_TIME),
	DEFINE_FIELD(CRpgRocket, m_hLauncher, FIELD_EHANDLE),
};

IMPLEMENT_SAVERESTORE(CRpgRocket, CGrenade)

TYPEDESCRIPTION CShotgun::m_SaveData[] = {
	DEFINE_FIELD(CShotgun, m_flNextReload, FIELD_TIME),
	DEFINE_FIELD(CShotgun, m_fInSpecialReload, FIELD_INTEGER),
	DEFINE_FIELD(CShotgun, m_flNextReload, FIELD_TIME),
	// DEFINE_FIELD( CShotgun, m_iShell, FIELD_INTEGER ),
	DEFINE_FIELD(CShotgun, m_flPumpTime, FIELD_TIME),
};

IMPLEMENT_SAVERESTORE(CShotgun, CBasePlayerWeapon)

TYPEDESCRIPTION CGauss::m_SaveData[] = {
	DEFINE_FIELD(CGauss, m_fInAttack, FIELD_INTEGER),
	// DEFINE_FIELD( CGauss, m_flStartCharge, FIELD_TIME ),
	// DEFINE_FIELD( CGauss, m_flPlayAftershock, FIELD_TIME ),
	// DEFINE_FIELD( CGauss, m_flNextAmmoBurn, FIELD_TIME ),
	DEFINE_FIELD(CGauss, m_fPrimaryFire, FIELD_BOOLEAN),
};

IMPLEMENT_SAVERESTORE(CGauss, CBasePlayerWeapon)

TYPEDESCRIPTION CEgon::m_SaveData[] = {
	// DEFINE_FIELD( CEgon, m_pBeam, FIELD_CLASSPTR ),
	// DEFINE_FIELD( CEgon, m_pNoise, FIELD_CLASSPTR ),
	// DEFINE_FIELD( CEgon, m_pSprite, FIELD_CLASSPTR ),
	DEFINE_FIELD(CEgon, m_shootTime, FIELD_TIME),	  DEFINE_FIELD(CEgon, m_fireState, FIELD_INTEGER),
	DEFINE_FIELD(CEgon, m_fireMode, FIELD_INTEGER),	  DEFINE_FIELD(CEgon, m_shakeTime, FIELD_TIME),
	DEFINE_FIELD(CEgon, m_flAmmoUseTime, FIELD_TIME),
};

IMPLEMENT_SAVERESTORE(CEgon, CBasePlayerWeapon)

TYPEDESCRIPTION CHgun::m_SaveData[] = {
	DEFINE_FIELD(CHgun, m_flRechargeTime, FIELD_TIME),
};

IMPLEMENT_SAVERESTORE(CHgun, CBasePlayerWeapon)

TYPEDESCRIPTION CSatchel::m_SaveData[] = {
	DEFINE_FIELD(CSatchel, m_chargeReady, FIELD_INTEGER),
};

IMPLEMENT_SAVERESTORE(CSatchel, CBasePlayerWeapon)
