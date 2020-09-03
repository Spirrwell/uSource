# class CHudSpectator

*Defined at line 54 of ./game/client/hud_spectator.h*

Inherits from CHudBase



## Members

public int m_iDrawCycle

public client_textmessage_t [8] m_HUDMessages

public char [8][128] m_HUDMessageText

public int m_lastHudMessage

overviewInfo_s m_OverviewData

public overviewEntity_t [128] m_OverviewEntities

public int m_iObserverFlags

public int m_iSpectatorNumber

public float m_mapZoom

Vector m_mapOrigin

public cvar_t * m_drawnames

public cvar_t * m_drawcone

public cvar_t * m_drawstatus

public cvar_t * m_autoDirector

public cvar_t * m_pip

public qboolean m_chatEnabled

Vector m_cameraOrigin

Vector m_cameraAngles

private class Vector [64] m_vPlayerPos

private HSPRITE m_hsprPlayerBlue

private HSPRITE m_hsprPlayerRed

private HSPRITE m_hsprPlayer

private HSPRITE m_hsprCamera

private HSPRITE m_hsprPlayerDead

private HSPRITE m_hsprViewcone

private HSPRITE m_hsprUnkownMap

private HSPRITE m_hsprBeam

private HSPRITE m_hCrosshair

wrect_s m_crosshairRect

private struct model_s * m_MapSprite

private float m_flNextObserverInput

private float m_zoomDelta

private float m_moveDelta

private int m_lastPrimaryObject

private int m_lastSecondaryObject



## Functions

### Reset

*public void Reset()*

*Defined at line 1487 of ./game/client/hud_spectator.cpp*

### ToggleInset

*public int ToggleInset(_Bool allowOff)*

*Defined at line 1456 of ./game/client/hud_spectator.cpp*

### CheckSettings

*public void CheckSettings()*

*Defined at line 1394 of ./game/client/hud_spectator.cpp*

### InitHUDData

*public void InitHUDData()*

*Defined at line 1502 of ./game/client/hud_spectator.cpp*

### AddOverviewEntityToList

*public _Bool AddOverviewEntityToList(HSPRITE sprite, cl_entity_t * ent, double killTime)*

*Defined at line 1377 of ./game/client/hud_spectator.cpp*

### DeathMessage

*public void DeathMessage(int victim)*

*Defined at line 1368 of ./game/client/hud_spectator.cpp*

### AddOverviewEntity

*public _Bool AddOverviewEntity(int type, struct cl_entity_s * ent, const char * modelname)*

*Defined at line 1329 of ./game/client/hud_spectator.cpp*

### CheckOverviewEntities

*public void CheckOverviewEntities()*

*Defined at line 1314 of ./game/client/hud_spectator.cpp*

### DrawOverview

*public void DrawOverview()*

*Defined at line 1296 of ./game/client/hud_spectator.cpp*

### DrawOverviewEntities

*public void DrawOverviewEntities()*

*Defined at line 1103 of ./game/client/hud_spectator.cpp*

### GetMapPosition

*public void GetMapPosition(float * returnvec)*

### DrawOverviewLayer

*public void DrawOverviewLayer()*

*Defined at line 985 of ./game/client/hud_spectator.cpp*

### LoadMapSprites

*public void LoadMapSprites()*

*Defined at line 974 of ./game/client/hud_spectator.cpp*

### ParseOverviewFile

*public _Bool ParseOverviewFile()*

*Defined at line 821 of ./game/client/hud_spectator.cpp*

### IsActivePlayer

*public _Bool IsActivePlayer(cl_entity_t * ent)*

*Defined at line 811 of ./game/client/hud_spectator.cpp*

### SetModes

*public void SetModes(int iMainMode, int iInsetMode)*

*Defined at line 715 of ./game/client/hud_spectator.cpp*

### HandleButtonsDown

*public void HandleButtonsDown(int ButtonPressed)*

*Defined at line 616 of ./game/client/hud_spectator.cpp*

### HandleButtonsUp

*public void HandleButtonsUp(int ButtonPressed)*

*Defined at line 706 of ./game/client/hud_spectator.cpp*

### FindNextPlayer

*public void FindNextPlayer(_Bool bReverse)*

*Defined at line 546 of ./game/client/hud_spectator.cpp*

### DirectorMessage

*public void DirectorMessage(int iSize, void * pbuf)*

*Defined at line 428 of ./game/client/hud_spectator.cpp*

### SetSpectatorStartPosition

*public void SetSpectatorStartPosition()*

*Defined at line 304 of ./game/client/hud_spectator.cpp*

----------------------------------------------------------------------------- SetSpectatorStartPosition():  Get valid map position and 'beam' spectator to this position-----------------------------------------------------------------------------

### Init

*public int Init()*

*Defined at line 112 of ./game/client/hud_spectator.cpp*

----------------------------------------------------------------------------- Purpose: -----------------------------------------------------------------------------

### VidInit

*public int VidInit()*

*Defined at line 334 of ./game/client/hud_spectator.cpp*

----------------------------------------------------------------------------- Purpose: Loads new icons-----------------------------------------------------------------------------

### Draw

*public int Draw(float flTime)*

*Defined at line 353 of ./game/client/hud_spectator.cpp*

----------------------------------------------------------------------------- Purpose:  Input  : flTime - 			intermission - -----------------------------------------------------------------------------



