# class CHalfLifeRules

*Defined at line 174 of ./game/server/gamerules.h*

========================================================= CHalfLifeRules - rules for the single player Half-Life  game.=========================================================



Inherits from CGameRules



## Functions

### CHalfLifeRules

*public void CHalfLifeRules()*

*Defined at line 36 of ./game/server/singleplay_gamerules.cpp*

==================================================================================================================

### Think

*public void Think()*

*Defined at line 43 of ./game/server/singleplay_gamerules.cpp*

 GR_Think

==================================================================================================================

### IsAllowedToSpawn

*public BOOL IsAllowedToSpawn(class CBaseEntity * pEntity)*

*Defined at line 260 of ./game/server/singleplay_gamerules.cpp*

==================================================================================================================

### FAllowFlashlight

*public BOOL FAllowFlashlight()*

*Defined at line 182 of ./game/server/gamerules.h*

### FShouldSwitchWeapon

*public BOOL FShouldSwitchWeapon(class CBasePlayer * pPlayer, class CBasePlayerItem * pWeapon)*

*Defined at line 70 of ./game/server/singleplay_gamerules.cpp*

==================================================================================================================

### GetNextBestWeapon

*public BOOL GetNextBestWeapon(class CBasePlayer * pPlayer, class CBasePlayerItem * pCurrentWeapon)*

*Defined at line 88 of ./game/server/singleplay_gamerules.cpp*

==================================================================================================================

### IsMultiplayer

*public BOOL IsMultiplayer()*

*Defined at line 49 of ./game/server/singleplay_gamerules.cpp*

 Functions to verify the single/multiplayer status of a game

==================================================================================================================

### IsDeathmatch

*public BOOL IsDeathmatch()*

*Defined at line 56 of ./game/server/singleplay_gamerules.cpp*

==================================================================================================================

### IsCoOp

*public BOOL IsCoOp()*

*Defined at line 63 of ./game/server/singleplay_gamerules.cpp*

==================================================================================================================

### ClientConnected

*public BOOL ClientConnected(edict_t * pEntity, const char * pszName, const char * pszAddress, char [128] szRejectReason)*

*Defined at line 95 of ./game/server/singleplay_gamerules.cpp*

 Client connection/disconnection

==================================================================================================================

### InitHUD

*public void InitHUD(class CBasePlayer * pl)*

*Defined at line 100 of ./game/server/singleplay_gamerules.cpp*

### ClientDisconnected

*public void ClientDisconnected(edict_t * pClient)*

*Defined at line 106 of ./game/server/singleplay_gamerules.cpp*

==================================================================================================================

### FlPlayerFallDamage

*public float FlPlayerFallDamage(class CBasePlayer * pPlayer)*

*Defined at line 112 of ./game/server/singleplay_gamerules.cpp*

 Client damage rules

==================================================================================================================

### PlayerSpawn

*public void PlayerSpawn(class CBasePlayer * pPlayer)*

*Defined at line 122 of ./game/server/singleplay_gamerules.cpp*

 Client spawn/respawn control

==================================================================================================================

### PlayerThink

*public void PlayerThink(class CBasePlayer * pPlayer)*

*Defined at line 135 of ./game/server/singleplay_gamerules.cpp*

==================================================================================================================

### FPlayerCanRespawn

*public BOOL FPlayerCanRespawn(class CBasePlayer * pPlayer)*

*Defined at line 141 of ./game/server/singleplay_gamerules.cpp*

==================================================================================================================

### FlPlayerSpawnTime

*public float FlPlayerSpawnTime(class CBasePlayer * pPlayer)*

*Defined at line 148 of ./game/server/singleplay_gamerules.cpp*

==================================================================================================================

### AllowAutoTargetCrosshair

*public BOOL AllowAutoTargetCrosshair()*

*Defined at line 128 of ./game/server/singleplay_gamerules.cpp*

==================================================================================================================

### IPointsForKill

*public int IPointsForKill(class CBasePlayer * pAttacker, class CBasePlayer * pKilled)*

*Defined at line 157 of ./game/server/singleplay_gamerules.cpp*

 Client kills/scoring

========================================================= IPointsForKill - how many points awarded to anyone that kills this player?=========================================================

### PlayerKilled

*public void PlayerKilled(class CBasePlayer * pVictim, entvars_t * pKiller, entvars_t * pInflictor)*

*Defined at line 165 of ./game/server/singleplay_gamerules.cpp*

========================================================= PlayerKilled - someone/something killed this player=========================================================

### DeathNotice

*public void DeathNotice(class CBasePlayer * pVictim, entvars_t * pKiller, entvars_t * pInflictor)*

*Defined at line 172 of ./game/server/singleplay_gamerules.cpp*

========================================================= Deathnotice=========================================================

### PlayerGotWeapon

*public void PlayerGotWeapon(class CBasePlayer * pPlayer, class CBasePlayerItem * pWeapon)*

*Defined at line 180 of ./game/server/singleplay_gamerules.cpp*

 Weapon retrieval

========================================================= PlayerGotWeapon - player has grabbed a weapon that was sitting in the world=========================================================

### WeaponShouldRespawn

*public int WeaponShouldRespawn(class CBasePlayerItem * pWeapon)*

*Defined at line 216 of ./game/server/singleplay_gamerules.cpp*

 Weapon spawn/respawn control

========================================================= WeaponShouldRespawn - any conditions inhibiting the respawning of this weapon?=========================================================

### FlWeaponRespawnTime

*public float FlWeaponRespawnTime(class CBasePlayerItem * pWeapon)*

*Defined at line 188 of ./game/server/singleplay_gamerules.cpp*

========================================================= FlWeaponRespawnTime - what is the time in the future at which this weapon may spawn?=========================================================

### FlWeaponTryRespawn

*public float FlWeaponTryRespawn(class CBasePlayerItem * pWeapon)*

*Defined at line 198 of ./game/server/singleplay_gamerules.cpp*

========================================================= FlWeaponRespawnTime - Returns 0 if the weapon can respawn  now,  otherwise it returns the time at which it can try to spawn again.=========================================================

### VecWeaponRespawnSpot

*public Vector VecWeaponRespawnSpot(class CBasePlayerItem * pWeapon)*

*Defined at line 207 of ./game/server/singleplay_gamerules.cpp*

========================================================= VecWeaponRespawnSpot - where should this weapon spawn? Some game variations may choose to randomize spawn locations=========================================================

### CanHaveItem

*public BOOL CanHaveItem(class CBasePlayer * pPlayer, class CItem * pItem)*

*Defined at line 223 of ./game/server/singleplay_gamerules.cpp*

 Item retrieval

==================================================================================================================

### PlayerGotItem

*public void PlayerGotItem(class CBasePlayer * pPlayer, class CItem * pItem)*

*Defined at line 230 of ./game/server/singleplay_gamerules.cpp*

==================================================================================================================

### ItemShouldRespawn

*public int ItemShouldRespawn(class CItem * pItem)*

*Defined at line 236 of ./game/server/singleplay_gamerules.cpp*

 Item spawn/respawn control

==================================================================================================================

### FlItemRespawnTime

*public float FlItemRespawnTime(class CItem * pItem)*

*Defined at line 244 of ./game/server/singleplay_gamerules.cpp*

========================================================= At what time in the future may this Item respawn?=========================================================

### VecItemRespawnSpot

*public Vector VecItemRespawnSpot(class CItem * pItem)*

*Defined at line 253 of ./game/server/singleplay_gamerules.cpp*

========================================================= Where should this item respawn? Some game variations may choose to randomize spawn locations=========================================================

### PlayerGotAmmo

*public void PlayerGotAmmo(class CBasePlayer * pPlayer, char * szName, int iCount)*

*Defined at line 267 of ./game/server/singleplay_gamerules.cpp*

 Ammo retrieval

==================================================================================================================

### AmmoShouldRespawn

*public int AmmoShouldRespawn(class CBasePlayerAmmo * pAmmo)*

*Defined at line 273 of ./game/server/singleplay_gamerules.cpp*

 Ammo spawn/respawn control

==================================================================================================================

### FlAmmoRespawnTime

*public float FlAmmoRespawnTime(class CBasePlayerAmmo * pAmmo)*

*Defined at line 280 of ./game/server/singleplay_gamerules.cpp*

==================================================================================================================

### VecAmmoRespawnSpot

*public Vector VecAmmoRespawnSpot(class CBasePlayerAmmo * pAmmo)*

*Defined at line 287 of ./game/server/singleplay_gamerules.cpp*

==================================================================================================================

### FlHealthChargerRechargeTime

*public float FlHealthChargerRechargeTime()*

*Defined at line 294 of ./game/server/singleplay_gamerules.cpp*

 Healthcharger respawn control

==================================================================================================================

### DeadPlayerWeapons

*public int DeadPlayerWeapons(class CBasePlayer * pPlayer)*

*Defined at line 301 of ./game/server/singleplay_gamerules.cpp*

 What happens to a dead player's weapons

==================================================================================================================

### DeadPlayerAmmo

*public int DeadPlayerAmmo(class CBasePlayer * pPlayer)*

*Defined at line 308 of ./game/server/singleplay_gamerules.cpp*

 What happens to a dead player's ammo	

==================================================================================================================

### FAllowMonsters

*public BOOL FAllowMonsters()*

*Defined at line 323 of ./game/server/singleplay_gamerules.cpp*

 Monsters

==================================================================================================================

### GetTeamID

*public const char * GetTeamID(class CBaseEntity * pEntity)*

*Defined at line 252 of ./game/server/gamerules.h*

 Teamplay stuff	

### PlayerRelationship

*public int PlayerRelationship(class CBaseEntity * pPlayer, class CBaseEntity * pTarget)*

*Defined at line 315 of ./game/server/singleplay_gamerules.cpp*

==================================================================================================================



