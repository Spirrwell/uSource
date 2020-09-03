# class CHalfLifeMultiplay

*Defined at line 260 of ./game/server/gamerules.h*

========================================================= CHalfLifeMultiplay - rules for the basic half life multiplayer competition=========================================================



Inherits from CGameRules



## Members

protected float m_flIntermissionEndTime

protected BOOL m_iEndIntermissionButtonHit



## Functions

### CHalfLifeMultiplay

*public void CHalfLifeMultiplay()*

*Defined at line 74 of ./game/server/multiplay_gamerules.cpp*

********************************************************* Rules for the half-life multiplayer game.*********************************************************

### Think

*public void Think()*

*Defined at line 195 of ./game/server/multiplay_gamerules.cpp*

 GR_Think

==================================================================================================================

### RefreshSkillData

*public void RefreshSkillData()*

*Defined at line 135 of ./game/server/multiplay_gamerules.cpp*

==================================================================================================================

### IsAllowedToSpawn

*public BOOL IsAllowedToSpawn(class CBaseEntity * pEntity)*

*Defined at line 1035 of ./game/server/multiplay_gamerules.cpp*

==================================================================================================================

### FAllowFlashlight

*public BOOL FAllowFlashlight()*

*Defined at line 1125 of ./game/server/multiplay_gamerules.cpp*

### FShouldSwitchWeapon

*public BOOL FShouldSwitchWeapon(class CBasePlayer * pPlayer, class CBasePlayerItem * pWeapon)*

*Defined at line 308 of ./game/server/multiplay_gamerules.cpp*

==================================================================================================================

### GetNextBestWeapon

*public BOOL GetNextBestWeapon(class CBasePlayer * pPlayer, class CBasePlayerItem * pCurrentWeapon)*

*Defined at line 336 of ./game/server/multiplay_gamerules.cpp*

### IsMultiplayer

*public BOOL IsMultiplayer()*

*Defined at line 287 of ./game/server/multiplay_gamerules.cpp*

 Functions to verify the single/multiplayer status of a game

==================================================================================================================

### IsDeathmatch

*public BOOL IsDeathmatch()*

*Defined at line 294 of ./game/server/multiplay_gamerules.cpp*

==================================================================================================================

### IsCoOp

*public BOOL IsCoOp()*

*Defined at line 301 of ./game/server/multiplay_gamerules.cpp*

==================================================================================================================

### ClientConnected

*public BOOL ClientConnected(edict_t * pEntity, const char * pszName, const char * pszAddress, char [128] szRejectReason)*

*Defined at line 404 of ./game/server/multiplay_gamerules.cpp*

 Client connection/disconnection If ClientConnected returns FALSE, the connection is rejected and the user is provided the reason specified in  svRejectReason Only the client's name and remote address are provided to the dll for verification.

==================================================================================================================

### InitHUD

*public void InitHUD(class CBasePlayer * pl)*

*Defined at line 422 of ./game/server/multiplay_gamerules.cpp*

### ClientDisconnected

*public void ClientDisconnected(edict_t * pClient)*

*Defined at line 487 of ./game/server/multiplay_gamerules.cpp*

==================================================================================================================

### UpdateGameMode

*public void UpdateGameMode(class CBasePlayer * pPlayer)*

*Defined at line 415 of ./game/server/multiplay_gamerules.cpp*

### FlPlayerFallDamage

*public float FlPlayerFallDamage(class CBasePlayer * pPlayer)*

*Defined at line 522 of ./game/server/multiplay_gamerules.cpp*

 Client damage rules

==================================================================================================================

### FPlayerCanTakeDamage

*public BOOL FPlayerCanTakeDamage(class CBasePlayer * pPlayer, class CBaseEntity * pAttacker)*

*Defined at line 543 of ./game/server/multiplay_gamerules.cpp*

==================================================================================================================

### PlayerSpawn

*public void PlayerSpawn(class CBasePlayer * pPlayer)*

*Defined at line 567 of ./game/server/multiplay_gamerules.cpp*

 Client spawn/respawn control

==================================================================================================================

### PlayerThink

*public void PlayerThink(class CBasePlayer * pPlayer)*

*Defined at line 550 of ./game/server/multiplay_gamerules.cpp*

==================================================================================================================

### FPlayerCanRespawn

*public BOOL FPlayerCanRespawn(class CBasePlayer * pPlayer)*

*Defined at line 592 of ./game/server/multiplay_gamerules.cpp*

==================================================================================================================

### FlPlayerSpawnTime

*public float FlPlayerSpawnTime(class CBasePlayer * pPlayer)*

*Defined at line 599 of ./game/server/multiplay_gamerules.cpp*

==================================================================================================================

### GetPlayerSpawnSpot

*public edict_t * GetPlayerSpawnSpot(class CBasePlayer * pPlayer)*

*Defined at line 1095 of ./game/server/multiplay_gamerules.cpp*

### AllowAutoTargetCrosshair

*public BOOL AllowAutoTargetCrosshair()*

*Defined at line 604 of ./game/server/multiplay_gamerules.cpp*

### ClientCommand

*public BOOL ClientCommand(class CBasePlayer * pPlayer, const char * pcmd)*

*Defined at line 124 of ./game/server/multiplay_gamerules.cpp*

### IPointsForKill

*public int IPointsForKill(class CBasePlayer * pAttacker, class CBasePlayer * pKilled)*

*Defined at line 613 of ./game/server/multiplay_gamerules.cpp*

 Client kills/scoring

========================================================= IPointsForKill - how many points awarded to anyone that kills this player?=========================================================

### PlayerKilled

*public void PlayerKilled(class CBasePlayer * pVictim, entvars_t * pKiller, entvars_t * pInflictor)*

*Defined at line 621 of ./game/server/multiplay_gamerules.cpp*

========================================================= PlayerKilled - someone/something killed this player=========================================================

### DeathNotice

*public void DeathNotice(class CBasePlayer * pVictim, entvars_t * pKiller, entvars_t * pInflictor)*

*Defined at line 683 of ./game/server/multiplay_gamerules.cpp*

========================================================= Deathnotice. =========================================================

### PlayerGotWeapon

*public void PlayerGotWeapon(class CBasePlayer * pPlayer, class CBasePlayerItem * pWeapon)*

*Defined at line 886 of ./game/server/multiplay_gamerules.cpp*

 Weapon retrieval

========================================================= PlayerGotWeapon - player has grabbed a weapon that was sitting in the world=========================================================

### CanHavePlayerItem

*public BOOL CanHavePlayerItem(class CBasePlayer * pPlayer, class CBasePlayerItem * pWeapon)*

*Defined at line 958 of ./game/server/multiplay_gamerules.cpp*

========================================================= CanHaveWeapon - returns FALSE if the player is not allowed to pick up this weapon=========================================================

### WeaponShouldRespawn

*public int WeaponShouldRespawn(class CBasePlayerItem * pWeapon)*

*Defined at line 944 of ./game/server/multiplay_gamerules.cpp*

 Weapon spawn/respawn control

========================================================= WeaponShouldRespawn - any conditions inhibiting the respawning of this weapon?=========================================================

### FlWeaponRespawnTime

*public float FlWeaponRespawnTime(class CBasePlayerItem * pWeapon)*

*Defined at line 894 of ./game/server/multiplay_gamerules.cpp*

========================================================= FlWeaponRespawnTime - what is the time in the future at which this weapon may spawn?=========================================================

### FlWeaponTryRespawn

*public float FlWeaponTryRespawn(class CBasePlayerItem * pWeapon)*

*Defined at line 917 of ./game/server/multiplay_gamerules.cpp*

========================================================= FlWeaponRespawnTime - Returns 0 if the weapon can respawn  now,  otherwise it returns the time at which it can try to spawn again.=========================================================

### VecWeaponRespawnSpot

*public Vector VecWeaponRespawnSpot(class CBasePlayerItem * pWeapon)*

*Defined at line 935 of ./game/server/multiplay_gamerules.cpp*

========================================================= VecWeaponRespawnSpot - where should this weapon spawn? Some game variations may choose to randomize spawn locations=========================================================

### CanHaveItem

*public BOOL CanHaveItem(class CBasePlayer * pPlayer, class CItem * pItem)*

*Defined at line 987 of ./game/server/multiplay_gamerules.cpp*

 Item retrieval

==================================================================================================================

### PlayerGotItem

*public void PlayerGotItem(class CBasePlayer * pPlayer, class CItem * pItem)*

*Defined at line 994 of ./game/server/multiplay_gamerules.cpp*

==================================================================================================================

### ItemShouldRespawn

*public int ItemShouldRespawn(class CItem * pItem)*

*Defined at line 1000 of ./game/server/multiplay_gamerules.cpp*

 Item spawn/respawn control

==================================================================================================================

### FlItemRespawnTime

*public float FlItemRespawnTime(class CItem * pItem)*

*Defined at line 1013 of ./game/server/multiplay_gamerules.cpp*

========================================================= At what time in the future may this Item respawn?=========================================================

### VecItemRespawnSpot

*public Vector VecItemRespawnSpot(class CItem * pItem)*

*Defined at line 1022 of ./game/server/multiplay_gamerules.cpp*

========================================================= Where should this item respawn? Some game variations may choose to randomize spawn locations=========================================================

### PlayerGotAmmo

*public void PlayerGotAmmo(class CBasePlayer * pPlayer, char * szName, int iCount)*

*Defined at line 1029 of ./game/server/multiplay_gamerules.cpp*

 Ammo retrieval

==================================================================================================================

### AmmoShouldRespawn

*public int AmmoShouldRespawn(class CBasePlayerAmmo * pAmmo)*

*Defined at line 1045 of ./game/server/multiplay_gamerules.cpp*

 Ammo spawn/respawn control

==================================================================================================================

### FlAmmoRespawnTime

*public float FlAmmoRespawnTime(class CBasePlayerAmmo * pAmmo)*

*Defined at line 1057 of ./game/server/multiplay_gamerules.cpp*

==================================================================================================================

### VecAmmoRespawnSpot

*public Vector VecAmmoRespawnSpot(class CBasePlayerAmmo * pAmmo)*

*Defined at line 1064 of ./game/server/multiplay_gamerules.cpp*

==================================================================================================================

### FlHealthChargerRechargeTime

*public float FlHealthChargerRechargeTime()*

*Defined at line 1071 of ./game/server/multiplay_gamerules.cpp*

 Healthcharger respawn control

==================================================================================================================

### FlHEVChargerRechargeTime

*public float FlHEVChargerRechargeTime()*

*Defined at line 1076 of ./game/server/multiplay_gamerules.cpp*

### DeadPlayerWeapons

*public int DeadPlayerWeapons(class CBasePlayer * pPlayer)*

*Defined at line 1083 of ./game/server/multiplay_gamerules.cpp*

 What happens to a dead player's weapons

==================================================================================================================

### DeadPlayerAmmo

*public int DeadPlayerAmmo(class CBasePlayer * pPlayer)*

*Defined at line 1090 of ./game/server/multiplay_gamerules.cpp*

 What happens to a dead player's ammo	

==================================================================================================================

### GetTeamID

*public const char * GetTeamID(class CBaseEntity * pEntity)*

*Defined at line 345 of ./game/server/gamerules.h*

 Teamplay stuff	

### PlayerRelationship

*public int PlayerRelationship(class CBaseEntity * pPlayer, class CBaseEntity * pTarget)*

*Defined at line 1108 of ./game/server/multiplay_gamerules.cpp*

==================================================================================================================

### PlayTextureSounds

*public BOOL PlayTextureSounds()*

*Defined at line 348 of ./game/server/gamerules.h*

### PlayFootstepSounds

*public BOOL PlayFootstepSounds(class CBasePlayer * pl, float fvol)*

*Defined at line 1114 of ./game/server/multiplay_gamerules.cpp*

### FAllowMonsters

*public BOOL FAllowMonsters()*

*Defined at line 1132 of ./game/server/multiplay_gamerules.cpp*

 Monsters

==================================================================================================================

### EndMultiplayerGame

*public void EndMultiplayerGame()*

*Defined at line 355 of ./game/server/gamerules.h*

 Immediately end a multiplayer game

### ChangeLevel

*protected void ChangeLevel()*

*Defined at line 1519 of ./game/server/multiplay_gamerules.cpp*

==============ChangeLevel

Server is changing to a new level, check mapcycle.txt for map name and setup info==============

### GoToIntermission

*protected void GoToIntermission()*

*Defined at line 1141 of ./game/server/multiplay_gamerules.cpp*

### SendMOTDToClient

*protected void SendMOTDToClient(edict_t * client)*

*Defined at line 1649 of ./game/server/multiplay_gamerules.cpp*



