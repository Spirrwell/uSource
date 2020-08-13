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
#ifndef WEAPONS_H
#define WEAPONS_H

#include "c_base_weapon.h"
#include "effects.h"
#include "weapon_shared.h"

class CBasePlayer;
extern int gmsgWeapPickup;

void DeactivateSatchels(CBasePlayer* pOwner);

extern DLL_GLOBAL short	      g_sModelIndexLaser; // holds the index for the laser beam
extern DLL_GLOBAL const char* g_pModelNameLaser;

extern DLL_GLOBAL short g_sModelIndexLaserDot;	 // holds the index for the laser beam dot
extern DLL_GLOBAL short g_sModelIndexFireball;	 // holds the index for the fireball
extern DLL_GLOBAL short g_sModelIndexSmoke;	 // holds the index for the smoke cloud
extern DLL_GLOBAL short g_sModelIndexWExplosion; // holds the index for the underwater explosion
extern DLL_GLOBAL short g_sModelIndexBubbles;	 // holds the index for the bubbles model
extern DLL_GLOBAL short g_sModelIndexBloodDrop;	 // holds the sprite index for blood drops
extern DLL_GLOBAL short g_sModelIndexBloodSpray; // holds the sprite index for blood spray (bigger)

extern void ClearMultiDamage(void);
extern void ApplyMultiDamage(entvars_t* pevInflictor, entvars_t* pevAttacker);
extern void AddMultiDamage(entvars_t* pevInflictor, CBaseEntity* pEntity, float flDamage, int bitsDamageType);

extern void DecalGunshot(TraceResult* pTrace, int iBulletType);
extern void SpawnBlood(Vector vecSpot, int bloodColor, float flDamage);
extern int  DamageDecal(CBaseEntity* pEntity, int bitsDamageType);
extern void RadiusDamage(Vector vecSrc, entvars_t* pevInflictor, entvars_t* pevAttacker, float flDamage, float flRadius, int iClassIgnore,
			 int bitsDamageType);

typedef struct
{
	CBaseEntity* pEntity;
	float	     amount;
	int	     type;
} MULTIDAMAGE;

extern MULTIDAMAGE gMultiDamage;

//=========================================================
// CWeaponBox - a single entity that can store weapons
// and ammo.
//=========================================================
class CWeaponBox : public CBaseEntity
{
	void Precache(void);
	void Spawn(void);
	void Touch(CBaseEntity* pOther);
	void KeyValue(KeyValueData* pkvd);
	BOOL IsEmpty(void);
	int  GiveAmmo(int iCount, const char* szName, int iMax, int* pIndex = NULL);
	void SetObjectCollisionBox(void);

public:
	void EXPORT	       Kill(void);
	int		       Save(CSave& save);
	int		       Restore(CRestore& restore);
	static TYPEDESCRIPTION m_SaveData[];

	BOOL HasWeapon(CBasePlayerItem* pCheckItem);
	BOOL PackWeapon(CBasePlayerItem* pWeapon);
	BOOL PackAmmo(int iszName, int iCount);

	CBasePlayerItem* m_rgpPlayerItems[MAX_ITEM_TYPES]; // one slot for each

	string_t m_rgiszAmmo[MAX_AMMO_SLOTS]; // ammo names
	int	 m_rgAmmo[MAX_AMMO_SLOTS];    // ammo quantities

	int m_cAmmoTypes; // how many ammo types packed into this box (if packed by a level designer)
};

#ifdef CLIENT_DLL
bool bIsMultiplayer(void);
void LoadVModel(const char* szViewModel, CBasePlayer* m_pPlayer);
#endif

class CLaserSpot : public CBaseEntity
{
	void Spawn(void);
	void Precache(void);

	int ObjectCaps(void) { return FCAP_DONT_SAVE; }

public:
	void	    Suspend(float flSuspendTime);
	void EXPORT Revive(void);

	static CLaserSpot* CreateSpot(void);
};

#endif // WEAPONS_H
