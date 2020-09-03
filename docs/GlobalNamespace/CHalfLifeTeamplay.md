# class CHalfLifeTeamplay

*Defined at line 27 of ./game/server/teamplay_gamerules.h*

Inherits from CHalfLifeMultiplay



## Members

private BOOL m_DisableDeathMessages

private BOOL m_DisableDeathPenalty

private BOOL m_teamLimit

private char [512] m_szTeamList



## Functions

### CHalfLifeTeamplay

*public void CHalfLifeTeamplay()*

*Defined at line 35 of ./game/server/teamplay_gamerules.cpp*

### ClientCommand

*public BOOL ClientCommand(class CBasePlayer * pPlayer, const char * pcmd)*

*Defined at line 150 of ./game/server/teamplay_gamerules.cpp*

========================================================= ClientCommand the user has typed a command which is unrecognized by everything else; this check to see if the gamerules knows anything about the command=========================================================

### ClientUserInfoChanged

*public void ClientUserInfoChanged(class CBasePlayer * pPlayer, char * infobuffer)*

*Defined at line 316 of ./game/server/teamplay_gamerules.cpp*

========================================================= ClientUserInfoChanged=========================================================

### IsTeamplay

*public BOOL IsTeamplay()*

*Defined at line 410 of ./game/server/teamplay_gamerules.cpp*

========================================================= IsTeamplay=========================================================

### FPlayerCanTakeDamage

*public BOOL FPlayerCanTakeDamage(class CBasePlayer * pPlayer, class CBaseEntity * pAttacker)*

*Defined at line 415 of ./game/server/teamplay_gamerules.cpp*

### PlayerRelationship

*public int PlayerRelationship(class CBaseEntity * pPlayer, class CBaseEntity * pTarget)*

*Defined at line 432 of ./game/server/teamplay_gamerules.cpp*

==================================================================================================================

### GetTeamID

*public const char * GetTeamID(class CBaseEntity * pEntity)*

*Defined at line 480 of ./game/server/teamplay_gamerules.cpp*

==================================================================================================================

### ShouldAutoAim

*public BOOL ShouldAutoAim(class CBasePlayer * pPlayer, edict_t * target)*

*Defined at line 449 of ./game/server/teamplay_gamerules.cpp*

==================================================================================================================

### IPointsForKill

*public int IPointsForKill(class CBasePlayer * pAttacker, class CBasePlayer * pKilled)*

*Defined at line 464 of ./game/server/teamplay_gamerules.cpp*

==================================================================================================================

### InitHUD

*public void InitHUD(class CBasePlayer * pl)*

*Defined at line 214 of ./game/server/teamplay_gamerules.cpp*

========================================================= InitHUD=========================================================

### DeathNotice

*public void DeathNotice(class CBasePlayer * pVictim, entvars_t * pKiller, entvars_t * pevInflictor)*

*Defined at line 370 of ./game/server/teamplay_gamerules.cpp*

========================================================= Deathnotice. =========================================================

### GetGameDescription

*public const char * GetGameDescription()*

*Defined at line 42 of ./game/server/teamplay_gamerules.h*

### UpdateGameMode

*public void UpdateGameMode(class CBasePlayer * pPlayer)*

*Defined at line 176 of ./game/server/teamplay_gamerules.cpp*

### PlayerKilled

*public void PlayerKilled(class CBasePlayer * pVictim, entvars_t * pKiller, entvars_t * pInflictor)*

*Defined at line 398 of ./game/server/teamplay_gamerules.cpp*

==================================================================================================================

### Think

*public void Think()*

*Defined at line 77 of ./game/server/teamplay_gamerules.cpp*

### GetTeamIndex

*public int GetTeamIndex(const char * pTeamName)*

*Defined at line 489 of ./game/server/teamplay_gamerules.cpp*

### GetIndexedTeamName

*public const char * GetIndexedTeamName(int teamIndex)*

*Defined at line 504 of ./game/server/teamplay_gamerules.cpp*

### IsValidTeam

*public BOOL IsValidTeam(const char * pTeamName)*

*Defined at line 512 of ./game/server/teamplay_gamerules.cpp*

### SetDefaultPlayerTeam

*public const char * SetDefaultPlayerTeam(class CBasePlayer * pPlayer)*

*Defined at line 183 of ./game/server/teamplay_gamerules.cpp*

### ChangePlayerTeam

*public void ChangePlayerTeam(class CBasePlayer * pPlayer, const char * pTeamName, BOOL bKill, BOOL bGib)*

*Defined at line 264 of ./game/server/teamplay_gamerules.cpp*

### RecountTeams

*private void RecountTeams(_Bool bResendInfo)*

*Defined at line 555 of ./game/server/teamplay_gamerules.cpp*

==================================================================================================================

### TeamWithFewestPlayers

*private const char * TeamWithFewestPlayers()*

*Defined at line 520 of ./game/server/teamplay_gamerules.cpp*



