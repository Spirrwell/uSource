# class CHudHealth

*Defined at line 101 of ./game/client/health.h*

-----------------------------------------------------



Inherits from CHudBase



## Members

public int m_iHealth

public int m_HUD_dmg_bio

public int m_HUD_cross

public float m_fAttackFront

public float m_fAttackRear

public float m_fAttackLeft

public float m_fAttackRight

public float m_fFade

private HSPRITE m_hSprite

private HSPRITE m_hDamage

private DAMAGE_IMAGE [12] m_dmg

private int m_bitsDamage



## Functions

### Init

*public int Init()*

*Defined at line 56 of ./game/client/health.cpp*

### VidInit

*public int VidInit()*

*Defined at line 87 of ./game/client/health.cpp*

### Draw

*public int Draw(float fTime)*

*Defined at line 179 of ./game/client/health.cpp*

### Reset

*public void Reset()*

*Defined at line 74 of ./game/client/health.cpp*

### MsgFunc_Health

*public int MsgFunc_Health(const char * pszName, int iSize, void * pbuf)*

*Defined at line 100 of ./game/client/health.cpp*

### MsgFunc_Damage

*public int MsgFunc_Damage(const char * pszName, int iSize, void * pbuf)*

*Defined at line 118 of ./game/client/health.cpp*

### GetPainColor

*public void GetPainColor(int & r, int & g, int & b)*

*Defined at line 153 of ./game/client/health.cpp*

 Returns back a color from the Green <-> Yellow <-> Red ramp

### DrawPain

*private int DrawPain(float fTime)*

*Defined at line 299 of ./game/client/health.cpp*

### DrawDamage

*private int DrawDamage(float fTime)*

*Defined at line 375 of ./game/client/health.cpp*

### CalcDamageDirection

*private void CalcDamageDirection(Vector vecFrom)*

*Defined at line 242 of ./game/client/health.cpp*

### UpdateTiles

*private void UpdateTiles(float fTime, long bits)*

*Defined at line 427 of ./game/client/health.cpp*



