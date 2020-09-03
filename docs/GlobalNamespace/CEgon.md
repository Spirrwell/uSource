# class CEgon

*Defined at line 5 of ./game/shared/hl1/weapon_egon.h*

Inherits from CBasePlayerWeapon



## Members

public float m_flAmmoUseTime

public class CBeam * m_pBeam

public class CBeam * m_pNoise

public class CSprite * m_pSprite

public unsigned short m_usEgonStop

private enum CEgon::EGON_FIREMODE m_fireMode

private float m_shakeTime

private BOOL m_deployed

private unsigned short m_usEgonFire



## Functions

### Spawn

*public void Spawn()*

*Defined at line 54 of ./game/shared/hl1/weapon_egon.cpp*

### Precache

*public void Precache()*

*Defined at line 65 of ./game/shared/hl1/weapon_egon.cpp*

### iItemSlot

*public int iItemSlot()*

*Defined at line 15 of ./game/shared/hl1/weapon_egon.h*

### GetItemInfo

*public int GetItemInfo(ItemInfo * p)*

*Defined at line 114 of ./game/shared/hl1/weapon_egon.cpp*

### AddToPlayer

*public int AddToPlayer(class CBasePlayer * pPlayer)*

*Defined at line 94 of ./game/shared/hl1/weapon_egon.cpp*

### Deploy

*public BOOL Deploy()*

*Defined at line 87 of ./game/shared/hl1/weapon_egon.cpp*

### Holster

*public void Holster(int skiplocal)*

*Defined at line 106 of ./game/shared/hl1/weapon_egon.cpp*

### UpdateEffect

*public void UpdateEffect(const class Vector & startPoint, const class Vector & endPoint, float timeBlend)*

*Defined at line 374 of ./game/shared/hl1/weapon_egon.cpp*

### CreateEffect

*public void CreateEffect()*

*Defined at line 400 of ./game/shared/hl1/weapon_egon.cpp*

### DestroyEffect

*public void DestroyEffect()*

*Defined at line 446 of ./game/shared/hl1/weapon_egon.cpp*

### EndAttack

*public void EndAttack()*

*Defined at line 500 of ./game/shared/hl1/weapon_egon.cpp*

### Attack

*public void Attack()*

*Defined at line 160 of ./game/shared/hl1/weapon_egon.cpp*

### PrimaryAttack

*public void PrimaryAttack()*

*Defined at line 233 of ./game/shared/hl1/weapon_egon.cpp*

### WeaponIdle

*public void WeaponIdle()*

*Defined at line 471 of ./game/shared/hl1/weapon_egon.cpp*

### GetPulseInterval

*public float GetPulseInterval()*

*Defined at line 134 of ./game/shared/hl1/weapon_egon.cpp*

### GetDischargeInterval

*public float GetDischargeInterval()*

*Defined at line 139 of ./game/shared/hl1/weapon_egon.cpp*

### Fire

*public void Fire(const class Vector & vecOrigSrc, const class Vector & vecDir)*

*Defined at line 239 of ./game/shared/hl1/weapon_egon.cpp*

### HasAmmo

*public BOOL HasAmmo()*

*Defined at line 144 of ./game/shared/hl1/weapon_egon.cpp*

### UseAmmo

*public void UseAmmo(int count)*

*Defined at line 152 of ./game/shared/hl1/weapon_egon.cpp*

### UseDecrement

*public BOOL UseDecrement()*

*Defined at line 49 of ./game/shared/hl1/weapon_egon.h*

### Save

*public int Save(class CSave & save)*

*Defined at line 888 of ./game/server/weapons.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 888 of ./game/server/weapons.cpp*



## Enums

| enum EGON_FIREMODE |

--

| FIRE_NARROW |
| FIRE_WIDE |


*Defined at line 43 of ./game/shared/hl1/weapon_egon.h*



