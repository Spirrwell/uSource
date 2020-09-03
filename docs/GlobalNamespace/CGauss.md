# class CGauss

*Defined at line 5 of ./game/shared/hl1/weapon_gauss.h*

Inherits from CBasePlayerWeapon



## Members

public int m_iBalls

public int m_iGlow

public int m_iBeam

public int m_iSoundState

public BOOL m_fPrimaryFire

private unsigned short m_usGaussFire

private unsigned short m_usGaussSpin



## Functions

### Spawn

*public void Spawn()*

*Defined at line 65 of ./game/shared/hl1/weapon_gauss.cpp*

### Precache

*public void Precache()*

*Defined at line 76 of ./game/shared/hl1/weapon_gauss.cpp*

### iItemSlot

*public int iItemSlot()*

*Defined at line 15 of ./game/shared/hl1/weapon_gauss.h*

### GetItemInfo

*public int GetItemInfo(ItemInfo * p)*

*Defined at line 110 of ./game/shared/hl1/weapon_gauss.cpp*

### AddToPlayer

*public int AddToPlayer(class CBasePlayer * pPlayer)*

*Defined at line 98 of ./game/shared/hl1/weapon_gauss.cpp*

### IsUseable

*public BOOL IsUseable()*

*Defined at line 127 of ./game/shared/hl1/weapon_gauss.cpp*

### Deploy

*public BOOL Deploy()*

*Defined at line 133 of ./game/shared/hl1/weapon_gauss.cpp*

### Holster

*public void Holster(int skiplocal)*

*Defined at line 139 of ./game/shared/hl1/weapon_gauss.cpp*

### PrimaryAttack

*public void PrimaryAttack()*

*Defined at line 149 of ./game/shared/hl1/weapon_gauss.cpp*

### SecondaryAttack

*public void SecondaryAttack()*

*Defined at line 177 of ./game/shared/hl1/weapon_gauss.cpp*

### WeaponIdle

*public void WeaponIdle()*

*Defined at line 546 of ./game/shared/hl1/weapon_gauss.cpp*

### StartFire

*public void StartFire()*

*Defined at line 318 of ./game/shared/hl1/weapon_gauss.cpp*

========================================================= StartFire- since all of this code has to run and then  call Fire(), it was easier at this point to rip it out  of weaponidle() and make its own function then to try to merge this into Fire(), which has some identical variable names =========================================================

### Fire

*public void Fire(Vector vecOrigSrc, Vector vecDirShooting, float flDamage)*

*Defined at line 372 of ./game/shared/hl1/weapon_gauss.cpp*

### GetFullChargeTime

*public float GetFullChargeTime()*

*Defined at line 47 of ./game/shared/hl1/weapon_gauss.cpp*

### UseDecrement

*public BOOL UseDecrement()*

*Defined at line 38 of ./game/shared/hl1/weapon_gauss.h*

### Save

*public int Save(class CSave & save)*

*Defined at line 874 of ./game/server/weapons.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 874 of ./game/server/weapons.cpp*



