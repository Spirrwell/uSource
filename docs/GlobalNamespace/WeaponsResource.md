# class WeaponsResource

*Defined at line 25 of ./game/client/ammohistory.h*

## Members

private struct WEAPON [32] rgWeapons

private struct WEAPON *[6][6] rgSlots

private int [32] riAmmo

public int iOldWeaponBits



## Functions

### Init

*public void Init()*

*Defined at line 36 of ./game/client/ammohistory.h*

### Reset

*public void Reset()*

*Defined at line 42 of ./game/client/ammohistory.h*

### GetWeapon

*public struct WEAPON * GetWeapon(int iId)*

*Defined at line 52 of ./game/client/ammohistory.h*

### AddWeapon

*public void AddWeapon(struct WEAPON * wp)*

*Defined at line 53 of ./game/client/ammohistory.h*

### PickupWeapon

*public void PickupWeapon(struct WEAPON * wp)*

*Defined at line 59 of ./game/client/ammohistory.h*

### DropWeapon

*public void DropWeapon(struct WEAPON * wp)*

*Defined at line 64 of ./game/client/ammohistory.h*

### DropAllWeapons

*public void DropAllWeapons()*

*Defined at line 69 of ./game/client/ammohistory.h*

### GetWeaponSlot

*public struct WEAPON * GetWeaponSlot(int slot, int pos)*

*Defined at line 78 of ./game/client/ammohistory.h*

### LoadWeaponSprites

*public void LoadWeaponSprites(struct WEAPON * wp)*

*Defined at line 71 of ./game/client/ammo.cpp*

### LoadAllWeaponSprites

*public void LoadAllWeaponSprites()*

*Defined at line 41 of ./game/client/ammo.cpp*

### GetFirstPos

*public struct WEAPON * GetFirstPos(int iSlot)*

*Defined at line 196 of ./game/client/ammo.cpp*

 Returns the first weapon for a given slot.

### SelectSlot

*public void SelectSlot(int iSlot, int fAdvance, int iDirection)*

*Defined at line 413 of ./game/client/ammo.cpp*

 Menu Selection Code

### GetNextActivePos

*public struct WEAPON * GetNextActivePos(int iSlot, int iSlotPos)*

*Defined at line 212 of ./game/client/ammo.cpp*

### HasAmmo

*public int HasAmmo(struct WEAPON * p)*

*Defined at line 58 of ./game/client/ammo.cpp*

### GetAmmo

*public AMMO GetAmmo(int iId)*

*Defined at line 89 of ./game/client/ammohistory.h*

// AMMO /////

### SetAmmo

*public void SetAmmo(int iId, int iCount)*

*Defined at line 91 of ./game/client/ammohistory.h*

### CountAmmo

*public int CountAmmo(int iId)*

*Defined at line 50 of ./game/client/ammo.cpp*

### GetAmmoPicFromWeapon

*public HSPRITE * GetAmmoPicFromWeapon(int iAmmoId, wrect_t & rect)*

*Defined at line 393 of ./game/client/ammo.cpp*

 Helper function to return a Ammo pointer from id



