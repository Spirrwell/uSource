# class CHudFlashlight

*Defined at line 430 of ./game/client/hud.h*

-----------------------------------------------------



Inherits from CHudBase



## Members

private HSPRITE m_hSprite1

private HSPRITE m_hSprite2

private HSPRITE m_hBeam

private wrect_t * m_prc1

private wrect_t * m_prc2

private wrect_t * m_prcBeam

private float m_flBat

private int m_iBat

private int m_fOn

private float m_fFade

private int m_iWidth



## Functions

### Init

*public int Init()*

*Defined at line 33 of ./game/client/flashlight.cpp*

### VidInit

*public int VidInit()*

*Defined at line 56 of ./game/client/flashlight.cpp*

### Draw

*public int Draw(float flTime)*

*Defined at line 94 of ./game/client/flashlight.cpp*

### Reset

*public void Reset()*

*Defined at line 48 of ./game/client/flashlight.cpp*

### MsgFunc_Flashlight

*public int MsgFunc_Flashlight(const char * pszName, int iSize, void * pbuf)*

*Defined at line 83 of ./game/client/flashlight.cpp*

### MsgFunc_FlashBat

*public int MsgFunc_FlashBat(const char * pszName, int iSize, void * pbuf)*

*Defined at line 73 of ./game/client/flashlight.cpp*



