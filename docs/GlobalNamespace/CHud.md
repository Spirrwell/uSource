# class CHud

*Defined at line 564 of ./game/client/hud.h*

-----------------------------------------------------



## Members

private struct HUDLIST * m_pHudList

private HSPRITE m_hsprLogo

private int m_iLogo

private client_sprite_t * m_pSpriteList

private int m_iSpriteCount

private int m_iSpriteCountAllRes

private float m_flMouseSensitivity

private int m_iConcussionEffect

public HSPRITE m_hsprCursor

public float m_flTime

public float m_fOldTime

public double m_flTimeDelta

Vector m_vecOrigin

Vector m_vecAngles

public int m_iKeyBits

public int m_iHideHUDDisplay

public int m_iFOV

public int m_Teamplay

public int m_iRes

public cvar_t * m_pCvarStealMouse

public cvar_t * m_pCvarDraw

public int m_iFontHeight

private HSPRITE * m_rghSprites

private wrect_t * m_rgrcRects

private char * m_rgszSpriteNames

private struct cvar_s * default_fov

CHudAmmo m_Ammo

CHudHealth m_Health

CHudSpectator m_Spectator

CHudGeiger m_Geiger

CHudBattery m_Battery

CHudTrain m_Train

CHudFlashlight m_Flash

CHudMessage m_Message

CHudStatusBar m_StatusBar

CHudDeathNotice m_DeathNotice

CHudSayText m_SayText

CHudMenu m_Menu

CHudAmmoSecondary m_AmmoSecondary

CHudTextMessage m_TextMessage

CHudStatusIcons m_StatusIcons

CHudScoreboard m_Scoreboard

CHudMOTD m_MOTD

SCREENINFO_s m_scrinfo

public int m_iWeaponBits

public int m_fPlayerDead

public int m_iIntermission

public int m_HUD_number_0

public int m_iNoConsolePrint



## Functions

### DrawHudNumber

*public int DrawHudNumber(int x, int y, int iFlags, int iNumber, int r, int g, int b)*

*Defined at line 298 of ./game/client/hud_redraw.cpp*

### DrawHudString

*public int DrawHudString(int x, int y, int iMaxX, const char * szString, int r, int g, int b)*

*Defined at line 202 of ./game/client/hud_redraw.cpp*

### DrawHudStringReverse

*public int DrawHudStringReverse(int xpos, int ypos, int iMinX, const char * szString, int r, int g, int b)*

*Defined at line 287 of ./game/client/hud_redraw.cpp*

 draws a string from right to left (right-aligned)

### DrawHudNumberString

*public int DrawHudNumberString(int xpos, int ypos, int iMinX, int iNumber, int r, int g, int b)*

*Defined at line 279 of ./game/client/hud_redraw.cpp*

### GetNumWidth

*public int GetNumWidth(int iNumber, int iFlags)*

*Defined at line 364 of ./game/client/hud_redraw.cpp*

### DrawHudStringLen

*public int DrawHudStringLen(const char * szIt)*

*Defined at line 269 of ./game/client/hud_redraw.cpp*

### DrawDarkRectangle

*public void DrawDarkRectangle(int x, int y, int wide, int tall)*

*Defined at line 389 of ./game/client/hud_redraw.cpp*

### GetSprite

*public HSPRITE GetSprite(int index)*

*Defined at line 609 of ./game/client/hud.h*

### GetSpriteRect

*public wrect_t & GetSpriteRect(int index)*

*Defined at line 614 of ./game/client/hud.h*

### GetSpriteIndex

*public int GetSpriteIndex(const char * SpriteName)*

*Defined at line 267 of ./game/client/hud.cpp*

 GetSpriteIndex() searches through the sprite list loaded from hud.txt for a name matching SpriteName returns an index into the gHUD.m_rghSprites[] array returns 0 if sprite not found

### Init

*public void Init()*

*Defined at line 156 of ./game/client/hud.cpp*

 This is called every time the DLL is loaded

### VidInit

*public void VidInit()*

*Defined at line 279 of ./game/client/hud.cpp*

### Think

*public void Think()*

*Defined at line 39 of ./game/client/hud_redraw.cpp*

 Think

### Redraw

*public int Redraw(float flTime, int intermission)*

*Defined at line 85 of ./game/client/hud_redraw.cpp*

 Redraw step through the local data,  placing the appropriate graphics & text as appropriate returns 1 if they've changed, 0 otherwise

### UpdateClientData

*public int UpdateClientData(client_data_t * cdata, float time)*

*Defined at line 32 of ./game/client/hud_update.cpp*

### CHud

*public void CHud()*

*Defined at line 645 of ./game/client/hud.h*

### ~CHud

*public void ~CHud()*

*Defined at line 244 of ./game/client/hud.cpp*

 CHud destructor cleans up memory allocated for m_rg* arrays

### MsgFunc_Damage

*public int MsgFunc_Damage(const char * pszName, int iSize, void * pbuf)*

*Defined at line 93 of ./game/client/hud_msg.cpp*

 user messages

### MsgFunc_GameMode

*public int MsgFunc_GameMode(const char * pszName, int iSize, void * pbuf)*

*Defined at line 85 of ./game/client/hud_msg.cpp*

### MsgFunc_Logo

*public int MsgFunc_Logo(const char * pszName, int iSize, void * pbuf)*

*Defined at line 419 of ./game/client/hud.cpp*

### MsgFunc_ResetHUD

*public int MsgFunc_ResetHUD(const char * pszName, int iSize, void * pbuf)*

*Defined at line 34 of ./game/client/hud_msg.cpp*

 USER-DEFINED SERVER MESSAGE HANDLERS

### MsgFunc_InitHUD

*public void MsgFunc_InitHUD(const char * pszName, int iSize, void * pbuf)*

*Defined at line 68 of ./game/client/hud_msg.cpp*

### MsgFunc_ViewMode

*public void MsgFunc_ViewMode(const char * pszName, int iSize, void * pbuf)*

*Defined at line 63 of ./game/client/hud_msg.cpp*

### MsgFunc_SetFOV

*public int MsgFunc_SetFOV(const char * pszName, int iSize, void * pbuf)*

*Defined at line 523 of ./game/client/hud.cpp*

### MsgFunc_Concuss

*public int MsgFunc_Concuss(const char * pszName, int iSize, void * pbuf)*

*Defined at line 116 of ./game/client/hud_msg.cpp*

### AddHudElem

*public void AddHudElem(class CHudBase * p)*

*Defined at line 558 of ./game/client/hud.cpp*

### GetSensitivity

*public float GetSensitivity()*

*Defined at line 588 of ./game/client/hud.cpp*



