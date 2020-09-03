# class CHudAmmo

*Defined at line 97 of ./game/client/hud.h*

-----------------------------------------------------



Inherits from CHudBase



## Members

private float m_fFade

 m_rgba

private struct WEAPON * m_pWeapon

private int m_HUD_bucket0

private int m_HUD_selection



## Functions

### Init

*public int Init()*

*Defined at line 257 of ./game/client/ammo.cpp*

### VidInit

*public int VidInit()*

*Defined at line 313 of ./game/client/ammo.cpp*

### Draw

*public int Draw(float flTime)*

*Defined at line 831 of ./game/client/ammo.cpp*

------------------------------------------------------------------------- Drawing code-------------------------------------------------------------------------

### Think

*public void Think()*

*Defined at line 346 of ./game/client/ammo.cpp*

 Think:  Used for selection of weapon menu item.

### Reset

*public void Reset()*

*Defined at line 296 of ./game/client/ammo.cpp*

### DrawWList

*public int DrawWList(float flTime)*

*Defined at line 1003 of ./game/client/ammo.cpp*

 Draw Weapon Menu

### MsgFunc_CurWeapon

*public int MsgFunc_CurWeapon(const char * pszName, int iSize, void * pbuf)*

*Defined at line 560 of ./game/client/ammo.cpp*

  CurWeapon: Update hud state with the current weapon and clip count. Ammo  counts are updated with AmmoX. Server assures that the Weapon ammo type   numbers match a real ammo type.

### MsgFunc_WeaponList

*public int MsgFunc_WeaponList(const char * pszName, int iSize, void * pbuf)*

*Defined at line 641 of ./game/client/ammo.cpp*

 WeaponList -- Tells the hud about a new weapon type.

### MsgFunc_AmmoX

*public int MsgFunc_AmmoX(const char * pszName, int iSize, void * pbuf)*

*Defined at line 485 of ./game/client/ammo.cpp*

 AmmoX  -- Update the count of a known type of ammo

### MsgFunc_AmmoPickup

*public int MsgFunc_AmmoPickup(const char * pszName, int iSize, void * pbuf)*

*Defined at line 497 of ./game/client/ammo.cpp*

### MsgFunc_WeapPickup

*public int MsgFunc_WeapPickup(const char * pszName, int iSize, void * pbuf)*

*Defined at line 509 of ./game/client/ammo.cpp*

### MsgFunc_ItemPickup

*public int MsgFunc_ItemPickup(const char * pszName, int iSize, void * pbuf)*

*Defined at line 520 of ./game/client/ammo.cpp*

### MsgFunc_HideWeapon

*public int MsgFunc_HideWeapon(const char * pszName, int iSize, void * pbuf)*

*Defined at line 531 of ./game/client/ammo.cpp*

### SlotInput

*public void SlotInput(int iSlot)*

*Defined at line 674 of ./game/client/ammo.cpp*

------------------------------------------------------------------------ Command Handlers------------------------------------------------------------------------ Slot button pressed

### UserCmd_Slot1

*public void UserCmd_Slot1()*

*Defined at line 683 of ./game/client/ammo.cpp*

### UserCmd_Slot2

*public void UserCmd_Slot2()*

*Defined at line 688 of ./game/client/ammo.cpp*

### UserCmd_Slot3

*public void UserCmd_Slot3()*

*Defined at line 693 of ./game/client/ammo.cpp*

### UserCmd_Slot4

*public void UserCmd_Slot4()*

*Defined at line 698 of ./game/client/ammo.cpp*

### UserCmd_Slot5

*public void UserCmd_Slot5()*

*Defined at line 703 of ./game/client/ammo.cpp*

### UserCmd_Slot6

*public void UserCmd_Slot6()*

*Defined at line 708 of ./game/client/ammo.cpp*

### UserCmd_Slot7

*public void UserCmd_Slot7()*

*Defined at line 713 of ./game/client/ammo.cpp*

### UserCmd_Slot8

*public void UserCmd_Slot8()*

*Defined at line 718 of ./game/client/ammo.cpp*

### UserCmd_Slot9

*public void UserCmd_Slot9()*

*Defined at line 723 of ./game/client/ammo.cpp*

### UserCmd_Slot10

*public void UserCmd_Slot10()*

*Defined at line 728 of ./game/client/ammo.cpp*

### UserCmd_Close

*public void UserCmd_Close()*

*Defined at line 733 of ./game/client/ammo.cpp*

### UserCmd_NextWeapon

*public void UserCmd_NextWeapon()*

*Defined at line 747 of ./game/client/ammo.cpp*

 Selects the next item in the weapon menu

### UserCmd_PrevWeapon

*public void UserCmd_PrevWeapon()*

*Defined at line 788 of ./game/client/ammo.cpp*

 Selects the previous item in the menu



