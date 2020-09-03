# class CBasePlayer

*Defined at line 75 of ./game/shared/c_base_player.h*

Inherits from CBaseMonster



## Members

EHANDLE m_hObserverTarget

public float m_flNextObserverInput

public int m_iObserverWeapon

public int m_iObserverLastMode

public int random_seed

public int m_iPlayerSound

public int m_iTargetVolume

public int m_iWeaponVolume

public int m_iExtraSoundTypes

public int m_iWeaponFlash

public float m_flStopExtraSoundTime

public float m_flFlashLightTime

public int m_iFlashBattery

public int m_afButtonLast

public int m_afButtonPressed

public int m_afButtonReleased

public edict_t * m_pentSndLast

public float m_flSndRoomtype

public float m_flSndRange

public float m_flFallVelocity

public int [5] m_rgItems

public int m_fKnownItem

public int m_fNewAmmo

public unsigned int m_afPhysicsFlags

public float m_fNextSuicideTime

public float m_flTimeStepSound

public float m_flTimeWeaponIdle

public float m_flSwimTime

public float m_flDuckTime

public float m_flWallJumpTime

public float m_flSuitUpdate

public int [4] m_rgSuitPlayList

public int m_iSuitPlayNext

public int [32] m_rgiSuitNoRepeat

public float [32] m_rgflSuitNoRepeatTime

public int m_lastDamageAmount

public float m_tbdPrev

public float m_flgeigerRange

public float m_flgeigerDelay

public int m_igeigerRangePrev

public int m_iStepLeft

public char [13] m_szTextureName

public char m_chTextureType

public int m_idrowndmg

public int m_idrownrestored

public int m_bitsHUDDamage

public BOOL m_fInitHUD

public BOOL m_fGameHUDInitialized

public int m_iTrain

public BOOL m_fWeapon

EHANDLE m_pTank

public float m_fDeadTime

public BOOL m_fNoPlayerSound

public BOOL m_fLongJump

public float m_tSneaking

public int m_iUpdateTime

public int m_iClientHealth

public int m_iClientBattery

public int m_iHideHUD

public int m_iClientHideHUD

public int m_iFOV

public int m_iClientFOV

public class CBasePlayerItem *[6] m_rgpPlayerItems

public class CBasePlayerItem * m_pActiveItem

public class CBasePlayerItem * m_pClientActiveItem

public class CBasePlayerItem * m_pLastItem

public int [32] m_rgAmmo

public int [32] m_rgAmmoLast

Vector m_vecAutoAim

public BOOL m_fOnTarget

public int m_iDeaths

public float m_iRespawnFrames

public int m_lastx

public int m_lasty

public int m_nCustomSprayFrames

public float m_flNextDecalTime

public char [16] m_szTeamName

public char [32] m_szAnimExtention

Vector m_vecLastViewAngles

public float m_flStartCharge

public float m_flAmmoStartCharge

public float m_flPlayAftershock

public float m_flNextAmmoBurn

public int [4] m_izSBarState

public float m_flNextSBarUpdateTime

public float m_flStatusBarDisappearDelay

public char [128] m_SbarString0

public char [128] m_SbarString1

public float m_flNextChatTime

public _Bool m_bSentBhopcap

public int ammo_9mm

public int ammo_357

public int ammo_bolts

public int ammo_buckshot

public int ammo_rockets

public int ammo_uranium

public int ammo_hornets

public int ammo_argrens



## Functions

### Observer_FindNextPlayer

*public void Observer_FindNextPlayer(_Bool bReverse)*

*Defined at line 32 of ./game/server/observer.cpp*

 Find the next client in the game for this player to spectate

 Spectator camera

### Observer_HandleButtons

*public void Observer_HandleButtons()*

*Defined at line 84 of ./game/server/observer.cpp*

 Handle buttons in observer mode

### Observer_SetMode

*public void Observer_SetMode(int iMode)*

*Defined at line 218 of ./game/server/observer.cpp*

 Attempt to change the observer mode

### Observer_CheckTarget

*public void Observer_CheckTarget()*

*Defined at line 126 of ./game/server/observer.cpp*

### Observer_CheckProperties

*public void Observer_CheckProperties()*

*Defined at line 170 of ./game/server/observer.cpp*

### IsObserver

*public int IsObserver()*

*Defined at line 88 of ./game/shared/c_base_player.h*

### Spawn

*public void Spawn()*

*Defined at line 227 of ./game/client/hl/hl_weapons.cpp*

=====================CBasePlayer::Spawn

=====================

### Pain

*public void Pain()*

*Defined at line 242 of ./game/server/player.cpp*

### Jump

*public void Jump()*

*Defined at line 234 of ./game/client/hl/hl_baseentity.cpp*

virtual void Think( void );

### Duck

*public void Duck()*

*Defined at line 235 of ./game/client/hl/hl_baseentity.cpp*

### PreThink

*public void PreThink()*

*Defined at line 237 of ./game/client/hl/hl_baseentity.cpp*

### PostThink

*public void PostThink()*

*Defined at line 243 of ./game/client/hl/hl_baseentity.cpp*

### GetGunPosition

*public Vector GetGunPosition()*

*Defined at line 279 of ./game/client/hl/hl_baseentity.cpp*

### TakeHealth

*public int TakeHealth(float flHealth, int bitsDamageType)*

*Defined at line 222 of ./game/client/hl/hl_baseentity.cpp*

 override takehealth bitsDamageType indicates type of damage healed. 

### TraceAttack

*public void TraceAttack(entvars_t * pevAttacker, float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 223 of ./game/client/hl/hl_baseentity.cpp*

========================================================= TraceAttack=========================================================

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 224 of ./game/client/hl/hl_baseentity.cpp*

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 212 of ./game/client/hl/hl_weapons.cpp*

 Better solution:  Add as parameter to all Killed() functions.

=====================CBasePlayer::Killed

=====================

### BodyTarget

*public Vector BodyTarget(const class Vector & posSrc)*

*Defined at line 201 of ./game/shared/c_base_player.h*

### StartSneaking

*public void StartSneaking()*

*Defined at line 202 of ./game/shared/c_base_player.h*

### StopSneaking

*public void StopSneaking()*

*Defined at line 203 of ./game/shared/c_base_player.h*

### IsSneaking

*public _Bool IsSneaking()*

*Defined at line 204 of ./game/shared/c_base_player.h*

### IsAlive

*public _Bool IsAlive()*

*Defined at line 205 of ./game/shared/c_base_player.h*

### ShouldFadeOnDeath

*public BOOL ShouldFadeOnDeath()*

*Defined at line 206 of ./game/shared/c_base_player.h*

### IsPlayer

*public _Bool IsPlayer()*

*Defined at line 207 of ./game/shared/c_base_player.h*

### IsNetClient

*public _Bool IsNetClient()*

*Defined at line 209 of ./game/shared/c_base_player.h*

### TeamID

*public const char * TeamID()*

*Defined at line 280 of ./game/client/hl/hl_baseentity.cpp*

 Spectators should return TRUE for this

### Save

*public int Save(class CSave & save)*

*Defined at line 245 of ./game/client/hl/hl_baseentity.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 247 of ./game/client/hl/hl_baseentity.cpp*

### RenewItems

*public void RenewItems()*

*Defined at line 246 of ./game/client/hl/hl_baseentity.cpp*

 Marks everything as new so the player will resend this to the hud.

### PackDeadPlayerItems

*public void PackDeadPlayerItems()*

*Defined at line 225 of ./game/client/hl/hl_baseentity.cpp*

========================================================= PackDeadPlayerItems - call this when a player dies to pack up the appropriate weapons and ammo items, and to destroy anything that shouldn't be packed.

 This is pretty brute force :(=========================================================

### RemoveAllItems

*public void RemoveAllItems(BOOL removeSuit)*

*Defined at line 226 of ./game/client/hl/hl_baseentity.cpp*

### SwitchWeapon

*public BOOL SwitchWeapon(class CBasePlayerItem * pWeapon)*

*Defined at line 278 of ./game/client/hl/hl_baseentity.cpp*

=========================================================

=========================================================

### UpdateClientData

*public void UpdateClientData()*

*Defined at line 265 of ./game/client/hl/hl_baseentity.cpp*

 JOHN:  sends custom messages if player HUD data has changed  (eg health, ammo)

=========================================================	UpdateClientData

resends any changed player HUD info to the client.Called every frame by PlayerPreThinkAlso called at start of demo recording and playback byForceClientDllUpdate to ensure the demo gets messagesreflecting all of the HUD state info.=========================================================

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 226 of ./game/shared/c_base_player.h*

 Player is moved across the transition by other means

### Precache

*public void Precache()*

*Defined at line 244 of ./game/client/hl/hl_baseentity.cpp*

### IsOnLadder

*public BOOL IsOnLadder()*

*Defined at line 229 of ./game/client/hl/hl_baseentity.cpp*

 TRUE if the player is attached to a ladder

### FlashlightIsOn

*public BOOL FlashlightIsOn()*

*Defined at line 252 of ./game/client/hl/hl_baseentity.cpp*

### FlashlightTurnOn

*public void FlashlightTurnOn()*

*Defined at line 253 of ./game/client/hl/hl_baseentity.cpp*

### FlashlightTurnOff

*public void FlashlightTurnOff()*

*Defined at line 254 of ./game/client/hl/hl_baseentity.cpp*

### UpdatePlayerSound

*public void UpdatePlayerSound()*

*Defined at line 242 of ./game/client/hl/hl_baseentity.cpp*

========================================================= UpdatePlayerSound - updates the position of the player's reserved sound slot in the sound list.=========================================================

### DeathSound

*public void DeathSound()*

*Defined at line 221 of ./game/client/hl/hl_baseentity.cpp*

### Classify

*public int Classify()*

*Defined at line 236 of ./game/client/hl/hl_baseentity.cpp*

 ID's player as such.

### SetAnimation

*public void SetAnimation(PLAYER_ANIM playerAnim)*

*Defined at line 227 of ./game/client/hl/hl_baseentity.cpp*

 Set the activity based on an event or current state

### SetWeaponAnimType

*public void SetWeaponAnimType(const char * szExtention)*

### ImpulseCommands

*public void ImpulseCommands()*

*Defined at line 256 of ./game/client/hl/hl_baseentity.cpp*

 custom player functions

### CheatImpulseCommands

*public void CheatImpulseCommands(int iImpulse)*

*Defined at line 257 of ./game/client/hl/hl_baseentity.cpp*

==================================================================================================================

### StartDeathCam

*public void StartDeathCam()*

*Defined at line 231 of ./game/client/hl/hl_baseentity.cpp*

========================================================= StartDeathCam - find an intermission spot and send the player off into observer mode=========================================================

### StartObserver

*public void StartObserver(Vector vecPosition, Vector vecViewAngle)*

*Defined at line 232 of ./game/client/hl/hl_baseentity.cpp*

### StopObserver

*public void StopObserver()*

*Defined at line 274 of ./game/server/observer.cpp*

### AddPoints

*public void AddPoints(int score, _Bool bAllowNegativeScore)*

*Defined at line 282 of ./game/client/hl/hl_baseentity.cpp*

### AddPointsToTeam

*public void AddPointsToTeam(int score, _Bool bAllowNegativeScore)*

*Defined at line 283 of ./game/client/hl/hl_baseentity.cpp*

### AddPlayerItem

*public _Bool AddPlayerItem(class CBasePlayerItem * pItem)*

*Defined at line 258 of ./game/client/hl/hl_baseentity.cpp*

 Add a weapon to the player (Item == Weapon == Selectable Object)

### RemovePlayerItem

*public BOOL RemovePlayerItem(class CBasePlayerItem * pItem, _Bool bCallHoster)*

*Defined at line 259 of ./game/client/hl/hl_baseentity.cpp*

### DropPlayerItem

*public void DropPlayerItem(char * pszItemName)*

*Defined at line 276 of ./game/client/hl/hl_baseentity.cpp*

========================================================= DropPlayerItem - drop the named item, or if no name, the active item. =========================================================

### HasPlayerItem

*public BOOL HasPlayerItem(class CBasePlayerItem * pCheckItem)*

*Defined at line 277 of ./game/client/hl/hl_baseentity.cpp*

========================================================= HasPlayerItem Does the player already have this item?=========================================================

### HasNamedPlayerItem

*public BOOL HasNamedPlayerItem(const char * pszItemName)*

*Defined at line 4501 of ./game/server/player.cpp*

========================================================= HasNamedPlayerItem Does the player already have this item?=========================================================

### HasWeapons

*public BOOL HasWeapons()*

*Defined at line 249 of ./game/client/hl/hl_baseentity.cpp*

============================================== HasWeapons - do I have any weapons at all?==============================================

### SelectPrevItem

*public void SelectPrevItem(int iItem)*

*Defined at line 250 of ./game/client/hl/hl_baseentity.cpp*

### SelectNextItem

*public void SelectNextItem(int iItem)*

*Defined at line 248 of ./game/client/hl/hl_baseentity.cpp*

### SelectLastItem

*public void SelectLastItem()*

*Defined at line 185 of ./game/client/hl/hl_weapons.cpp*

=====================CBasePlayer::SelectLastItem

=====================

### SelectItem

*public void SelectItem(const char * pstr)*

*Defined at line 154 of ./game/client/hl/hl_weapons.cpp*

=====================CBasePlayer::SelectItem

  Switch weapons=====================

### ItemPreFrame

*public void ItemPreFrame()*

*Defined at line 260 of ./game/client/hl/hl_baseentity.cpp*

============ItemPreFrame

Called every frame by the player PreThink============

### ItemPostFrame

*public void ItemPostFrame()*

*Defined at line 261 of ./game/client/hl/hl_baseentity.cpp*

============ItemPostFrame

Called every frame by the player PostThink============

### GiveNamedItem

*public void GiveNamedItem(const char * szName)*

*Defined at line 3212 of ./game/server/player.cpp*

==============================================

### EnableControl

*public void EnableControl(BOOL fControl)*

*Defined at line 270 of ./game/client/hl/hl_baseentity.cpp*

### GiveAmmo

*public int GiveAmmo(int iAmount, const char * szName, int iMax)*

*Defined at line 281 of ./game/client/hl/hl_baseentity.cpp*

 Returns the unique ID for the ammo, or -1 if error

### SendAmmoUpdate

*public void SendAmmoUpdate()*

*Defined at line 264 of ./game/client/hl/hl_baseentity.cpp*

 Called from UpdateClientData makes sure the client has all the necessary ammo info,  if values have changed

### WaterMove

*public void WaterMove()*

*Defined at line 228 of ./game/client/hl/hl_baseentity.cpp*

### PlayerDeathThink

*public void PlayerDeathThink()*

*Defined at line 230 of ./game/client/hl/hl_baseentity.cpp*

### PlayerUse

*public void PlayerUse()*

*Defined at line 233 of ./game/client/hl/hl_baseentity.cpp*

### CheckSuitUpdate

*public void CheckSuitUpdate()*

*Defined at line 240 of ./game/client/hl/hl_baseentity.cpp*

### SetSuitUpdate

*public void SetSuitUpdate(const char * name, int fgroup, int iNoRepeat)*

*Defined at line 241 of ./game/client/hl/hl_baseentity.cpp*

 add sentence to suit playlist queue. if fgroup is true, then name is a sentence group (HEV_AA), otherwise name is a specific sentence name ie: !HEV_AA0.  If iNoRepeat is specified in seconds, then we won't repeat playback of this word or sentence for at least that number of seconds.

### UpdateGeigerCounter

*public void UpdateGeigerCounter()*

*Defined at line 239 of ./game/client/hl/hl_baseentity.cpp*

### CheckTimeBasedDamage

*public void CheckTimeBasedDamage()*

*Defined at line 238 of ./game/client/hl/hl_baseentity.cpp*

#define SLOWFREEZE_DURATION		1.0#define SLOWFREEZE_DAMAGE		3.0

### FBecomeProne

*public _Bool FBecomeProne()*

*Defined at line 266 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FBecomeProne - Overridden for the player to set the proper physics flags when a barnacle grabs player.=========================================================

### BarnacleVictimBitten

*public void BarnacleVictimBitten(entvars_t * pevBarnacle)*

*Defined at line 267 of ./game/client/hl/hl_baseentity.cpp*

========================================================= BarnacleVictimBitten - bad name for a function that is called by Barnacle victims when the barnacle pulls their head into its mouth. For the player, just die.=========================================================

### BarnacleVictimReleased

*public void BarnacleVictimReleased()*

*Defined at line 268 of ./game/client/hl/hl_baseentity.cpp*

========================================================= BarnacleVictimReleased - overridden for player who has physics flags concerns. =========================================================

### GetAmmoIndex

*public int GetAmmoIndex(const char * psz)*

*Defined at line 263 of ./game/client/hl/hl_baseentity.cpp*

### AmmoInventory

*public int AmmoInventory(int iAmmoIndex)*

*Defined at line 262 of ./game/client/hl/hl_baseentity.cpp*

### Illumination

*public int Illumination()*

*Defined at line 269 of ./game/client/hl/hl_baseentity.cpp*

========================================================= Illumination  return player light level plus virtual muzzle flash=========================================================

### ResetAutoaim

*public void ResetAutoaim()*

*Defined at line 273 of ./game/client/hl/hl_baseentity.cpp*

### GetAutoaimVector

*public Vector GetAutoaimVector(float flDelta)*

*Defined at line 271 of ./game/client/hl/hl_baseentity.cpp*

========================================================= Autoaim set crosshair position to point to enemey=========================================================

### AutoaimDeflection

*public Vector AutoaimDeflection(class Vector & vecSrc, float flDist, float flDelta)*

*Defined at line 272 of ./game/client/hl/hl_baseentity.cpp*

### ForceClientDllUpdate

*public void ForceClientDllUpdate()*

*Defined at line 255 of ./game/client/hl/hl_baseentity.cpp*

===============ForceClientDllUpdate

When recording a demo, we need to have the server tell us the entire client stateso that the client side .dll can behave correctly.Reset stuff so that the state is transmitted.===============

### DeathMessage

*public void DeathMessage(entvars_t * pevKiller)*

### SetCustomDecalFrames

*public void SetCustomDecalFrames(int nFrames)*

*Defined at line 274 of ./game/client/hl/hl_baseentity.cpp*

=============SetCustomDecalFrames

  UNDONE:  Determine real frame limit, 8 is a placeholder.  Note:  -1 means no custom frames present.=============

### GetCustomDecalFrames

*public int GetCustomDecalFrames()*

*Defined at line 275 of ./game/client/hl/hl_baseentity.cpp*

=============GetCustomDecalFrames

  Returns the # of custom frames this player's custom clan logo contains.=============

### TabulateAmmo

*public void TabulateAmmo()*

*Defined at line 1061 of ./game/server/player.cpp*

===========TabulateAmmoThis function is used to find and store all the ammo we have into the ammo vars.============

### InitStatusBar

*public void InitStatusBar()*

*Defined at line 1664 of ./game/server/player.cpp*

Player ID

### UpdateStatusBar

*public void UpdateStatusBar()*

*Defined at line 1670 of ./game/server/player.cpp*



