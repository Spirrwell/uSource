# class CHudAmmoSecondary

*Defined at line 140 of ./game/client/hud.h*

-----------------------------------------------------



Inherits from CHudBase



## Members

private int m_HUD_ammoicon

private int [4] m_iAmmoAmounts

private float m_fFade



## Functions

### Init

*public int Init()*

*Defined at line 30 of ./game/client/ammo_secondary.cpp*

### VidInit

*public int VidInit()*

*Defined at line 51 of ./game/client/ammo_secondary.cpp*

### Reset

*public void Reset()*

*Defined at line 46 of ./game/client/ammo_secondary.cpp*

### Draw

*public int Draw(float flTime)*

*Defined at line 56 of ./game/client/ammo_secondary.cpp*

### MsgFunc_SecAmmoVal

*public int MsgFunc_SecAmmoVal(const char * pszName, int iSize, void * pbuf)*

*Defined at line 130 of ./game/client/ammo_secondary.cpp*

 Message handler for Secondary Ammo Icon Sets an ammo value takes two values:		byte:  ammo index		byte:  ammo value

### MsgFunc_SecAmmoIcon

*public int MsgFunc_SecAmmoIcon(const char * pszName, int iSize, void * pbuf)*

*Defined at line 117 of ./game/client/ammo_secondary.cpp*

 Message handler for Secondary Ammo Value accepts one value:		string:  sprite name



## Enums

| enum  |

--

| MAX_SEC_AMMO_VALUES |


*Defined at line 152 of ./game/client/hud.h*



