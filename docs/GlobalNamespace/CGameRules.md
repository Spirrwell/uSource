# class CGameRules

*Defined at line 61 of ./game/server/gamerules.h*

## Functions

### ~CGameRules

*public void ~CGameRules()*

*Defined at line 64 of ./game/server/gamerules.h*

### RefreshSkillData

*public void RefreshSkillData()*

*Defined at line 113 of ./game/server/gamerules.cpp*

========================================================= load the SkillData struct with the proper values based on the skill level.=========================================================

### Think

*public void Think()*

### IsAllowedToSpawn

*public BOOL IsAllowedToSpawn(class CBaseEntity * pEntity)*

### FAllowFlashlight

*public BOOL FAllowFlashlight()*

### FShouldSwitchWeapon

*public BOOL FShouldSwitchWeapon(class CBasePlayer * pPlayer, class CBasePlayerItem * pWeapon)*

### GetNextBestWeapon

*public BOOL GetNextBestWeapon(class CBasePlayer * pPlayer, class CBasePlayerItem * pCurrentWeapon)*

### IsMultiplayer

*public BOOL IsMultiplayer()*

 Functions to verify the single/multiplayer status of a game

### IsDeathmatch

*public BOOL IsDeathmatch()*

### IsTeamplay

*public BOOL IsTeamplay()*

*Defined at line 77 of ./game/server/gamerules.h*

### IsCoOp

*public BOOL IsCoOp()*

### GetGameDescription

*public const char * GetGameDescription()*

*Defined at line 79 of ./game/server/gamerules.h*

### ClientConnected

*public BOOL ClientConnected(edict_t * pEntity, const char * pszName, const char * pszAddress, char [128] szRejectReason)*

 Client connection/disconnection

### InitHUD

*public void InitHUD(class CBasePlayer * pl)*

### ClientDisconnected

*public void ClientDisconnected(edict_t * pClient)*

### UpdateGameMode

*public void UpdateGameMode(class CBasePlayer * pPlayer)*

*Defined at line 85 of ./game/server/gamerules.h*

### FlPlayerFallDamage

*public float FlPlayerFallDamage(class CBasePlayer * pPlayer)*

 Client damage rules

### FPlayerCanTakeDamage

*public BOOL FPlayerCanTakeDamage(class CBasePlayer * pPlayer, class CBaseEntity * pAttacker)*

*Defined at line 89 of ./game/server/gamerules.h*

### ShouldAutoAim

*public BOOL ShouldAutoAim(class CBasePlayer * pPlayer, edict_t * target)*

*Defined at line 90 of ./game/server/gamerules.h*

### PlayerSpawn

*public void PlayerSpawn(class CBasePlayer * pPlayer)*

 Client spawn/respawn control

### PlayerThink

*public void PlayerThink(class CBasePlayer * pPlayer)*

### FPlayerCanRespawn

*public BOOL FPlayerCanRespawn(class CBasePlayer * pPlayer)*

### FlPlayerSpawnTime

*public float FlPlayerSpawnTime(class CBasePlayer * pPlayer)*

### GetPlayerSpawnSpot

*public edict_t * GetPlayerSpawnSpot(class CBasePlayer * pPlayer)*

*Defined at line 63 of ./game/server/gamerules.cpp*

==================================================================================================================

### AllowAutoTargetCrosshair

*public BOOL AllowAutoTargetCrosshair()*

*Defined at line 99 of ./game/server/gamerules.h*

### ClientCommand

*public BOOL ClientCommand(class CBasePlayer * pPlayer, const char * pcmd)*

*Defined at line 100 of ./game/server/gamerules.h*

### ClientUserInfoChanged

*public void ClientUserInfoChanged(class CBasePlayer * pPlayer, char * infobuffer)*

*Defined at line 101 of ./game/server/gamerules.h*

### IPointsForKill

*public int IPointsForKill(class CBasePlayer * pAttacker, class CBasePlayer * pKilled)*

 Client kills/scoring

### PlayerKilled

*public void PlayerKilled(class CBasePlayer * pVictim, entvars_t * pKiller, entvars_t * pInflictor)*

### DeathNotice

*public void DeathNotice(class CBasePlayer * pVictim, entvars_t * pKiller, entvars_t * pInflictor)*

### CanHavePlayerItem

*public BOOL CanHavePlayerItem(class CBasePlayer * pPlayer, class CBasePlayerItem * pWeapon)*

*Defined at line 79 of ./game/server/gamerules.cpp*

 Weapon retrieval

==================================================================================================================

### PlayerGotWeapon

*public void PlayerGotWeapon(class CBasePlayer * pPlayer, class CBasePlayerItem * pWeapon)*

### WeaponShouldRespawn

*public int WeaponShouldRespawn(class CBasePlayerItem * pWeapon)*

 Weapon spawn/respawn control

### FlWeaponRespawnTime

*public float FlWeaponRespawnTime(class CBasePlayerItem * pWeapon)*

### FlWeaponTryRespawn

*public float FlWeaponTryRespawn(class CBasePlayerItem * pWeapon)*

### VecWeaponRespawnSpot

*public Vector VecWeaponRespawnSpot(class CBasePlayerItem * pWeapon)*

### CanHaveItem

*public BOOL CanHaveItem(class CBasePlayer * pPlayer, class CItem * pItem)*

 Item retrieval

### PlayerGotItem

*public void PlayerGotItem(class CBasePlayer * pPlayer, class CItem * pItem)*

### ItemShouldRespawn

*public int ItemShouldRespawn(class CItem * pItem)*

 Item spawn/respawn control

### FlItemRespawnTime

*public float FlItemRespawnTime(class CItem * pItem)*

### VecItemRespawnSpot

*public Vector VecItemRespawnSpot(class CItem * pItem)*

### CanHaveAmmo

*public BOOL CanHaveAmmo(class CBasePlayer * pPlayer, const char * pszAmmoName, int iMaxCarry)*

*Defined at line 40 of ./game/server/gamerules.cpp*

 Ammo retrieval

==================================================================================================================

### PlayerGotAmmo

*public void PlayerGotAmmo(class CBasePlayer * pPlayer, char * szName, int iCount)*

### AmmoShouldRespawn

*public int AmmoShouldRespawn(class CBasePlayerAmmo * pAmmo)*

 Ammo spawn/respawn control

### FlAmmoRespawnTime

*public float FlAmmoRespawnTime(class CBasePlayerAmmo * pAmmo)*

### VecAmmoRespawnSpot

*public Vector VecAmmoRespawnSpot(class CBasePlayerAmmo * pAmmo)*

### FlHealthChargerRechargeTime

*public float FlHealthChargerRechargeTime()*

 Healthcharger respawn control

### FlHEVChargerRechargeTime

*public float FlHEVChargerRechargeTime()*

*Defined at line 139 of ./game/server/gamerules.h*

### DeadPlayerWeapons

*public int DeadPlayerWeapons(class CBasePlayer * pPlayer)*

 What happens to a dead player's weapons

### DeadPlayerAmmo

*public int DeadPlayerAmmo(class CBasePlayer * pPlayer)*

 What happens to a dead player's ammo	

### GetTeamID

*public const char * GetTeamID(class CBaseEntity * pEntity)*

 Teamplay stuff

### PlayerRelationship

*public int PlayerRelationship(class CBaseEntity * pPlayer, class CBaseEntity * pTarget)*

### GetTeamIndex

*public int GetTeamIndex(const char * pTeamName)*

*Defined at line 150 of ./game/server/gamerules.h*

### GetIndexedTeamName

*public const char * GetIndexedTeamName(int teamIndex)*

*Defined at line 151 of ./game/server/gamerules.h*

### IsValidTeam

*public BOOL IsValidTeam(const char * pTeamName)*

*Defined at line 152 of ./game/server/gamerules.h*

### ChangePlayerTeam

*public void ChangePlayerTeam(class CBasePlayer * pPlayer, const char * pTeamName, BOOL bKill, BOOL bGib)*

*Defined at line 153 of ./game/server/gamerules.h*

### SetDefaultPlayerTeam

*public const char * SetDefaultPlayerTeam(class CBasePlayer * pPlayer)*

*Defined at line 154 of ./game/server/gamerules.h*

### PlayTextureSounds

*public BOOL PlayTextureSounds()*

*Defined at line 157 of ./game/server/gamerules.h*

 Sounds

### PlayFootstepSounds

*public BOOL PlayFootstepSounds(class CBasePlayer * pl, float fvol)*

*Defined at line 158 of ./game/server/gamerules.h*

### FAllowMonsters

*public BOOL FAllowMonsters()*

 Monsters

### EndMultiplayerGame

*public void EndMultiplayerGame()*

*Defined at line 164 of ./game/server/gamerules.h*

 Immediately end a multiplayer game



