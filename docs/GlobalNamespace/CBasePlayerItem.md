# class CBasePlayerItem

*Defined at line 9 of ./game/shared/c_base_item.h*

 Items that the player has in their inventory that they can use

#include "weapons.h"#include "items.h"



Inherits from CBaseAnimating



## Members

public class CBasePlayer * m_pPlayer

public class CBasePlayerItem * m_pNext

public int m_iId



## Functions

### SetObjectCollisionBox

*public void SetObjectCollisionBox()*

*Defined at line 9 of ./game/shared/c_base_item.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 22 of ./game/shared/c_base_weapon.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 22 of ./game/shared/c_base_weapon.cpp*

### AddToPlayer

*public int AddToPlayer(class CBasePlayer * pPlayer)*

*Defined at line 196 of ./game/shared/c_base_item.cpp*

### AddDuplicate

*public int AddDuplicate(class CBasePlayerItem * pItem)*

*Defined at line 20 of ./game/shared/c_base_item.h*

### DestroyItem

*public void DestroyItem()*

*Defined at line 185 of ./game/shared/c_base_item.cpp*

### DefaultTouch

*public void DefaultTouch(class CBaseEntity * pOther)*

*Defined at line 155 of ./game/shared/c_base_item.cpp*

### FallThink

*public void FallThink()*

*Defined at line 39 of ./game/shared/c_base_item.cpp*

========================================================= FallThink - Items that have just spawned run this think to catch them when they hit the ground. Once we're sure that the object is grounded, we change its solid type to trigger and set it in a large box that helps the player get it.=========================================================

### Materialize

*public void Materialize()*

*Defined at line 66 of ./game/shared/c_base_item.cpp*

========================================================= Materialize - make a CBasePlayerItem visible and tangible=========================================================

### AttemptToMaterialize

*public void AttemptToMaterialize()*

*Defined at line 87 of ./game/shared/c_base_item.cpp*

========================================================= AttemptToMaterialize - the item is trying to rematerialize, should it do so now or wait longer?=========================================================

### Respawn

*public class CBaseEntity * Respawn()*

*Defined at line 125 of ./game/shared/c_base_item.cpp*

========================================================= Respawn- this item is already in the world, but it is invisible and intangible. Make it visible and tangible.=========================================================

### FallInit

*public void FallInit()*

*Defined at line 18 of ./game/shared/c_base_item.cpp*

========================================================= Sets up movetype, size, solidtype for a new weapon.=========================================================

### CheckRespawn

*public void CheckRespawn()*

*Defined at line 106 of ./game/shared/c_base_item.cpp*

========================================================= CheckRespawn - a player is taking this weapon, should it respawn?=========================================================

### GetItemInfo

*public int GetItemInfo(ItemInfo * p)*

*Defined at line 29 of ./game/shared/c_base_item.h*

### CanDeploy

*public BOOL CanDeploy()*

*Defined at line 30 of ./game/shared/c_base_item.h*

### Deploy

*public BOOL Deploy()*

*Defined at line 31 of ./game/shared/c_base_item.h*

### CanHolster

*public BOOL CanHolster()*

*Defined at line 34 of ./game/shared/c_base_item.h*

### Holster

*public void Holster(int skiplocal)*

*Defined at line 217 of ./game/shared/c_base_item.cpp*

### UpdateItemInfo

*public void UpdateItemInfo()*

*Defined at line 36 of ./game/shared/c_base_item.h*

### ItemPreFrame

*public void ItemPreFrame()*

*Defined at line 38 of ./game/shared/c_base_item.h*

### ItemPostFrame

*public void ItemPostFrame()*

*Defined at line 39 of ./game/shared/c_base_item.h*

### Drop

*public void Drop()*

*Defined at line 203 of ./game/shared/c_base_item.cpp*

### Kill

*public void Kill()*

*Defined at line 210 of ./game/shared/c_base_item.cpp*

### AttachToPlayer

*public void AttachToPlayer(class CBasePlayer * pPlayer)*

*Defined at line 225 of ./game/shared/c_base_item.cpp*

### PrimaryAmmoIndex

*public int PrimaryAmmoIndex()*

*Defined at line 45 of ./game/shared/c_base_item.h*

### SecondaryAmmoIndex

*public int SecondaryAmmoIndex()*

*Defined at line 46 of ./game/shared/c_base_item.h*

### UpdateClientData

*public int UpdateClientData(class CBasePlayer * pPlayer)*

*Defined at line 48 of ./game/shared/c_base_item.h*

### GetWeaponPtr

*public class CBasePlayerItem * GetWeaponPtr()*

*Defined at line 50 of ./game/shared/c_base_item.h*

### iItemSlot

*public int iItemSlot()*

*Defined at line 59 of ./game/shared/c_base_item.h*

### iItemPosition

*public int iItemPosition()*

*Defined at line 61 of ./game/shared/c_base_item.h*

### pszAmmo1

*public const char * pszAmmo1()*

*Defined at line 62 of ./game/shared/c_base_item.h*

### iMaxAmmo1

*public int iMaxAmmo1()*

*Defined at line 63 of ./game/shared/c_base_item.h*

### pszAmmo2

*public const char * pszAmmo2()*

*Defined at line 64 of ./game/shared/c_base_item.h*

### iMaxAmmo2

*public int iMaxAmmo2()*

*Defined at line 65 of ./game/shared/c_base_item.h*

### pszName

*public const char * pszName()*

*Defined at line 66 of ./game/shared/c_base_item.h*

### iMaxClip

*public int iMaxClip()*

*Defined at line 67 of ./game/shared/c_base_item.h*

### iWeight

*public int iWeight()*

*Defined at line 68 of ./game/shared/c_base_item.h*

### iFlags

*public int iFlags()*

*Defined at line 69 of ./game/shared/c_base_item.h*



