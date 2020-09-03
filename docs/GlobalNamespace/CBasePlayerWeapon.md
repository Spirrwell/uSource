# class CBasePlayerWeapon

*Defined at line 8 of ./game/shared/c_base_weapon.h*

 inventory items that



Inherits from CBasePlayerItem



## Members

public int m_iPlayEmptySound

public int m_fFireOnEmpty

public float m_flPumpTime

public int m_fInSpecialReload

public float m_flNextPrimaryAttack

public float m_flNextSecondaryAttack

public float m_flTimeWeaponIdle

public int m_iPrimaryAmmoType

public int m_iSecondaryAmmoType

public int m_iClip

public int m_iClientClip

public int m_iClientWeaponState

public int m_fInReload

public int m_iDefaultAmmo

public float m_flPrevPrimaryAttack

public float m_flLastFireTime

public float m_flStartThrow

public float m_flReleaseThrow

public int m_chargeReady

public int m_fInAttack

public int m_fireState



## Functions

### Save

*public int Save(class CSave & save)*

*Defined at line 43 of ./game/shared/c_base_weapon.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 43 of ./game/shared/c_base_weapon.cpp*

### AddToPlayer

*public int AddToPlayer(class CBasePlayer * pPlayer)*

*Defined at line 223 of ./game/shared/c_base_weapon.cpp*

 generic weapon versions of CBasePlayerItem calls

### AddDuplicate

*public int AddDuplicate(class CBasePlayerItem * pItem)*

*Defined at line 210 of ./game/shared/c_base_weapon.cpp*

 CALLED THROUGH the newly-touched weapon's instance. The existing player weapon is pOriginal

### ExtractAmmo

*public int ExtractAmmo(class CBasePlayerWeapon * pWeapon)*

*Defined at line 538 of ./game/shared/c_base_weapon.cpp*

========================================================= called by the new item with the existing item as parameter

 if we call ExtractAmmo(), it's because the player is picking up this type of weapon for the first time. If it is spawned by the world, m_iDefaultAmmo will have a default ammo amount in it. if  this is a weapon dropped by a dying player, has 0 m_iDefaultAmmo, which means only the ammo in the weapon clip comes along.=========================================================

### ExtractClipAmmo

*public int ExtractClipAmmo(class CBasePlayerWeapon * pWeapon)*

*Defined at line 565 of ./game/shared/c_base_weapon.cpp*

========================================================= called by the new item's class with the existing item as parameter=========================================================

### AddWeapon

*public int AddWeapon()*

*Defined at line 23 of ./game/shared/c_base_weapon.h*

### AddPrimaryAmmo

*public BOOL AddPrimaryAmmo(int iCount, char * szName, int iMaxClip, int iMaxCarry)*

*Defined at line 325 of ./game/shared/c_base_weapon.cpp*

 generic "shared" ammo handlers

### AddSecondaryAmmo

*public BOOL AddSecondaryAmmo(int iCount, char * szName, int iMaxCarry)*

*Defined at line 366 of ./game/shared/c_base_weapon.cpp*

### UpdateItemInfo

*public void UpdateItemInfo()*

*Defined at line 29 of ./game/shared/c_base_weapon.h*

### PlayEmptySound

*public BOOL PlayEmptySound()*

*Defined at line 489 of ./game/shared/c_base_weapon.cpp*

 attack key(s)

### ResetEmptySound

*public void ResetEmptySound()*

*Defined at line 500 of ./game/shared/c_base_weapon.cpp*

### SendWeaponAnim

*public void SendWeaponAnim(int iAnim, int skiplocal, int body)*

*Defined at line 300 of ./game/shared/c_base_weapon.cpp*

### CanDeploy

*public BOOL CanDeploy()*

*Defined at line 406 of ./game/shared/c_base_weapon.cpp*

### IsUseable

*public BOOL IsUseable()*

*Defined at line 388 of ./game/shared/c_base_weapon.cpp*

========================================================= IsUseable - this function determines whether or not a weapon is useable by the player in its current state. (does it have ammo loaded? do I have any ammo for the weapon?, etc)=========================================================

### DefaultDeploy

*public BOOL DefaultDeploy(const char * szViewModel, const char * szWeaponModel, int iAnim, const char * szAnimExt, int skiplocal, int body)*

*Defined at line 436 of ./game/shared/c_base_weapon.cpp*

### DefaultReload

*public int DefaultReload(int iClipSize, int iAnim, float fDelay, int body)*

*Defined at line 468 of ./game/shared/c_base_weapon.cpp*

### ItemPostFrame

*public void ItemPostFrame()*

*Defined at line 61 of ./game/shared/c_base_weapon.cpp*

### PrimaryAttack

*public void PrimaryAttack()*

*Defined at line 46 of ./game/shared/c_base_weapon.h*

 called by CBasePlayerWeapons ItemPostFrame()

### SecondaryAttack

*public void SecondaryAttack()*

*Defined at line 47 of ./game/shared/c_base_weapon.h*

### Reload

*public void Reload()*

*Defined at line 48 of ./game/shared/c_base_weapon.h*

### WeaponTick

*public void WeaponTick()*

*Defined at line 49 of ./game/shared/c_base_weapon.h*

### WeaponIdle

*public void WeaponIdle()*

*Defined at line 50 of ./game/shared/c_base_weapon.h*

### UpdateClientData

*public int UpdateClientData(class CBasePlayer * pPlayer)*

*Defined at line 244 of ./game/shared/c_base_weapon.cpp*

### RetireWeapon

*public void RetireWeapon()*

*Defined at line 588 of ./game/shared/c_base_weapon.cpp*

========================================================= RetireWeapon - no more ammo for this gun, put it away.=========================================================

### ShouldWeaponIdle

*public BOOL ShouldWeaponIdle()*

*Defined at line 53 of ./game/shared/c_base_weapon.h*

### Holster

*public void Holster(int skiplocal)*

*Defined at line 519 of ./game/shared/c_base_weapon.cpp*

### UseDecrement

*public BOOL UseDecrement()*

*Defined at line 55 of ./game/shared/c_base_weapon.h*

### PrimaryAmmoIndex

*public int PrimaryAmmoIndex()*

*Defined at line 507 of ./game/shared/c_base_weapon.cpp*

==================================================================================================================

### SecondaryAmmoIndex

*public int SecondaryAmmoIndex()*

*Defined at line 514 of ./game/shared/c_base_weapon.cpp*

==================================================================================================================

### PrintState

*public void PrintState()*

*Defined at line 823 of ./game/server/weapons.cpp*

### GetWeaponPtr

*public class CBasePlayerItem * GetWeaponPtr()*

*Defined at line 62 of ./game/shared/c_base_weapon.h*

### GetNextAttackDelay

*public float GetNextAttackDelay(float delay)*

*Defined at line 613 of ./game/shared/c_base_weapon.cpp*

========================================================================= GetNextAttackDelay - An accurate way of calcualting the next attack time.=========================================================================



## Enums

| enum EGON_FIRESTATE |

--

| FIRE_OFF |
| FIRE_CHARGE |


*Defined at line 89 of ./game/shared/c_base_weapon.h*



