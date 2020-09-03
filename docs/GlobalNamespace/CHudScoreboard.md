# class CHudScoreboard

*Defined at line 226 of ./game/client/hud.h*

Inherits from CHudBase



## Members

public int m_iNumTeams

public int m_iLastKilledBy

public int m_fLastKillTime

public int m_iPlayerNum

public int m_iShowscoresHeld



## Functions

### Init

*public int Init()*

*Defined at line 49 of ./game/client/scoreboard.cpp*

#include "vgui_TeamFortressViewport.h"

### InitHUDData

*public void InitHUDData()*

*Defined at line 75 of ./game/client/scoreboard.cpp*

### VidInit

*public int VidInit()*

*Defined at line 69 of ./game/client/scoreboard.cpp*

### Draw

*public int Draw(float flTime)*

*Defined at line 115 of ./game/client/scoreboard.cpp*

### DrawPlayers

*public int DrawPlayers(int xoffset, float listslot, int nameoffset, const char * team)*

*Defined at line 340 of ./game/client/scoreboard.cpp*

 returns the ypos where it finishes drawing

### UserCmd_ShowScores

*public void UserCmd_ShowScores()*

*Defined at line 625 of ./game/client/scoreboard.cpp*

### UserCmd_HideScores

*public void UserCmd_HideScores()*

*Defined at line 630 of ./game/client/scoreboard.cpp*

### MsgFunc_ScoreInfo

*public int MsgFunc_ScoreInfo(const char * pszName, int iSize, void * pbuf)*

*Defined at line 487 of ./game/client/scoreboard.cpp*

### MsgFunc_TeamInfo

*public int MsgFunc_TeamInfo(const char * pszName, int iSize, void * pbuf)*

*Defined at line 515 of ./game/client/scoreboard.cpp*

 Message handler for TeamInfo message accepts two values:		byte: client number		string: client team name

### MsgFunc_TeamScore

*public int MsgFunc_TeamScore(const char * pszName, int iSize, void * pbuf)*

*Defined at line 589 of ./game/client/scoreboard.cpp*

 Message handler for TeamScore message accepts three values:		string: team name		short: teams kills		short: teams deaths  if this message is never received, then scores will simply be the combined totals of the players.

### MsgFunc_TeamScores

*public int MsgFunc_TeamScores(const char * pszName, int iSize, void * pbuf)*

### MsgFunc_TeamNames

*public int MsgFunc_TeamNames(const char * pszName, int iSize, void * pbuf)*

### DeathMsg

*public void DeathMsg(int killer, int victim)*

*Defined at line 612 of ./game/client/scoreboard.cpp*

### GetAllPlayersInfo

*public void GetAllPlayersInfo()*

*Defined at line 476 of ./game/client/scoreboard.cpp*



