# class CWeaponBox

*Defined at line 61 of ./game/server/weapons.h*

========================================================= CWeaponBox - a single entity that can store weapons and ammo. =========================================================



Inherits from CBaseEntity



## Members

public class CBasePlayerItem *[6] m_rgpPlayerItems

public string_t [32] m_rgiszAmmo

public int [32] m_rgAmmo

public int m_cAmmoTypes



## Functions

### Precache

*private void Precache()*

*Defined at line 477 of ./game/server/weapons.cpp*

=========================================================

=========================================================

### Spawn

*private void Spawn()*

*Defined at line 502 of ./game/server/weapons.cpp*

========================================================= CWeaponBox - Spawn =========================================================

### Touch

*private void Touch(class CBaseEntity * pOther)*

*Defined at line 556 of ./game/server/weapons.cpp*

========================================================= CWeaponBox - Touch: try to add my contents to the toucher if the toucher is a player.=========================================================

### KeyValue

*private void KeyValue(KeyValueData * pkvd)*

*Defined at line 484 of ./game/server/weapons.cpp*

==================================================================================================================

### IsEmpty

*private BOOL IsEmpty()*

*Defined at line 791 of ./game/server/weapons.cpp*

========================================================= CWeaponBox::IsEmpty - is there anything in this box?=========================================================

### GiveAmmo

*private int GiveAmmo(int iCount, const char * szName, int iMax, int * pIndex)*

*Defined at line 733 of ./game/server/weapons.cpp*

========================================================= CWeaponBox - GiveAmmo=========================================================

### SetObjectCollisionBox

*private void SetObjectCollisionBox()*

*Defined at line 817 of ./game/server/weapons.cpp*

==================================================================================================================

### Kill

*public void Kill()*

*Defined at line 518 of ./game/server/weapons.cpp*

========================================================= CWeaponBox - Kill - the think function that removes the box from the world.=========================================================

### Save

*public int Save(class CSave & save)*

*Defined at line 472 of ./game/server/weapons.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 472 of ./game/server/weapons.cpp*

### HasWeapon

*public BOOL HasWeapon(class CBasePlayerItem * pCheckItem)*

*Defined at line 772 of ./game/server/weapons.cpp*

========================================================= CWeaponBox::HasWeapon - is a weapon of this type already packed in this box?=========================================================

### PackWeapon

*public BOOL PackWeapon(class CBasePlayerItem * pWeapon)*

*Defined at line 656 of ./game/server/weapons.cpp*

========================================================= CWeaponBox - PackWeapon: Add this weapon to the box=========================================================

### PackAmmo

*public BOOL PackAmmo(int iszName, int iCount)*

*Defined at line 707 of ./game/server/weapons.cpp*

========================================================= CWeaponBox - PackAmmo=========================================================



