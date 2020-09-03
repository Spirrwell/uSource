# class CBaseEntity

*Defined at line 32 of ./game/shared/c_base_entity.h*

 Base Entity.  All entity types derive from this



## Members

private _Bool m_bShouldRemove

public entvars_t * pev

public class CBaseEntity * m_pGoalEnt

public class CBaseEntity * m_pLink

public void (class CBaseEntity::*)(void) m_pfnThink

public void (class CBaseEntity::*)(class CBaseEntity *) m_pfnTouch

public void (class CBaseEntity::*)(class CBaseEntity *, class CBaseEntity *, USE_TYPE, float) m_pfnUse

public void (class CBaseEntity::*)(class CBaseEntity *) m_pfnBlocked



## Functions

### Activate

*public void Activate()*

*Defined at line 47 of ./game/shared/c_base_entity.h*

 Event functions 

### Spawn

*public void Spawn()*

*Defined at line 48 of ./game/shared/c_base_entity.h*

### Precache

*public void Precache()*

*Defined at line 49 of ./game/shared/c_base_entity.h*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 50 of ./game/shared/c_base_entity.h*

### Save

*public int Save(class CSave & save)*

*Defined at line 134 of ./game/shared/c_base_entity.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 145 of ./game/shared/c_base_entity.cpp*

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 99 of ./game/shared/c_base_entity.cpp*

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 46 of ./game/shared/c_base_entity.cpp*

 inflict damage on this entity.  bitsDamageType indicates type of damage inflicted, ie: DMG_CRUSH

### TakeHealth

*public int TakeHealth(float flHealth, int bitsDamageType)*

*Defined at line 23 of ./game/shared/c_base_entity.cpp*

 give health

### SetToggleState

*public void SetToggleState(int state)*

*Defined at line 56 of ./game/shared/c_base_entity.h*

### StartSneaking

*public void StartSneaking()*

*Defined at line 57 of ./game/shared/c_base_entity.h*

### StopSneaking

*public void StopSneaking()*

*Defined at line 58 of ./game/shared/c_base_entity.h*

### OnControls

*public _Bool OnControls(entvars_t * pev)*

*Defined at line 59 of ./game/shared/c_base_entity.h*

### Touch

*public void Touch(class CBaseEntity * pOther)*

*Defined at line 60 of ./game/shared/c_base_entity.h*

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 411 of ./game/shared/c_base_entity.cpp*

### Blocked

*public void Blocked(class CBaseEntity * pOther)*

*Defined at line 62 of ./game/shared/c_base_entity.h*

### DeathNotice

*public void DeathNotice(entvars_t * pevChild)*

*Defined at line 63 of ./game/shared/c_base_entity.h*

### IsBSPModel

*public _Bool IsBSPModel()*

*Defined at line 66 of ./game/shared/c_base_entity.h*

 Entity type checking 

### IsPlayer

*public _Bool IsPlayer()*

*Defined at line 67 of ./game/shared/c_base_entity.h*

### IsNetClient

*public _Bool IsNetClient()*

*Defined at line 68 of ./game/shared/c_base_entity.h*

### IsNPC

*public _Bool IsNPC()*

*Defined at line 69 of ./game/shared/c_base_entity.h*

### IsItem

*public _Bool IsItem()*

*Defined at line 70 of ./game/shared/c_base_entity.h*

### IsWeapon

*public _Bool IsWeapon()*

*Defined at line 71 of ./game/shared/c_base_entity.h*

### IsTriggered

*public _Bool IsTriggered(class CBaseEntity * pActivator)*

*Defined at line 74 of ./game/shared/c_base_entity.h*

 State checks 

### IsSneaking

*public _Bool IsSneaking()*

*Defined at line 75 of ./game/shared/c_base_entity.h*

### IsAlive

*public _Bool IsAlive()*

*Defined at line 76 of ./game/shared/c_base_entity.h*

### IsMoving

*public int IsMoving()*

*Defined at line 77 of ./game/shared/c_base_entity.h*

### IsInWorld

*public _Bool IsInWorld()*

*Defined at line 250 of ./game/shared/c_base_entity.cpp*

### IsDormant

*public int IsDormant()*

*Defined at line 245 of ./game/shared/c_base_entity.cpp*

### IsLockedByMaster

*public _Bool IsLockedByMaster()*

*Defined at line 80 of ./game/shared/c_base_entity.h*

### HasTarget

*public _Bool HasTarget(string_t targetname)*

*Defined at line 81 of ./game/shared/c_base_entity.h*

### MyMonsterPointer

*public class CBaseMonster * MyMonsterPointer()*

*Defined at line 84 of ./game/shared/c_base_entity.h*

 Internal Utils 

### MySquadMonsterPointer

*public class CSquadMonster * MySquadMonsterPointer()*

*Defined at line 85 of ./game/shared/c_base_entity.h*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 88 of ./game/shared/c_base_entity.h*

### SetObjectCollisionBox

*public void SetObjectCollisionBox()*

*Defined at line 210 of ./game/shared/c_base_entity.cpp*

 Setup the object->object collision box (pev->mins / pev->maxs is the object->world collision box)

### Classify

*public int Classify()*

*Defined at line 93 of ./game/shared/c_base_entity.h*

### TraceAttack

*public void TraceAttack(entvars_t * pevAttacker, float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 457 of ./game/shared/c_base_entity.cpp*

================TraceAttack================

### BloodColor

*public int BloodColor()*

*Defined at line 100 of ./game/shared/c_base_entity.h*

### TraceBleed

*public void TraceBleed(float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 479 of ./game/shared/c_base_entity.cpp*

### GetToggleState

*public int GetToggleState()*

*Defined at line 104 of ./game/shared/c_base_entity.h*

### AddPoints

*public void AddPoints(int score, _Bool bAllowNegativeScore)*

*Defined at line 105 of ./game/shared/c_base_entity.h*

### AddPointsToTeam

*public void AddPointsToTeam(int score, _Bool bAllowNegativeScore)*

*Defined at line 106 of ./game/shared/c_base_entity.h*

### AddPlayerItem

*public _Bool AddPlayerItem(class CBasePlayerItem * pItem)*

*Defined at line 107 of ./game/shared/c_base_entity.h*

### RemovePlayerItem

*public _Bool RemovePlayerItem(class CBasePlayerItem * pItem)*

*Defined at line 108 of ./game/shared/c_base_entity.h*

### GiveAmmo

*public int GiveAmmo(int iAmount, const char * szName, int iMax)*

*Defined at line 109 of ./game/shared/c_base_entity.h*

### GetDelay

*public float GetDelay()*

*Defined at line 110 of ./game/shared/c_base_entity.h*

### OverrideReset

*public void OverrideReset()*

*Defined at line 111 of ./game/shared/c_base_entity.h*

### DamageDecal

*public int DamageDecal(int bitsDamageType)*

*Defined at line 300 of ./game/shared/c_base_entity.cpp*

### ReflectGauss

*public _Bool ReflectGauss()*

*Defined at line 115 of ./game/shared/c_base_entity.h*

### TeamID

*public const char * TeamID()*

*Defined at line 117 of ./game/shared/c_base_entity.h*

### RemoveThis

*public void RemoveThis(float time)*

*Defined at line 340 of ./game/shared/c_base_entity.cpp*

 Utility functions 

### GetNextTarget

*public class CBaseEntity * GetNextTarget()*

*Defined at line 110 of ./game/shared/c_base_entity.cpp*

virtual void SetActivator( CBaseEntity *pActivator ) {}

### Think

*public void Think()*

*Defined at line 131 of ./game/shared/c_base_entity.h*

### operator new

*public void * operator new(size_t stAllocateBlock, entvars_t * pev)*

*Defined at line 142 of ./game/shared/c_base_entity.h*

 allow engine to allocate instance data

### UpdateOnRemove

*public void UpdateOnRemove()*

*Defined at line 419 of ./game/shared/c_base_entity.cpp*

 This updates global tables that need to know about entities being removed

### SUB_Remove

*public void SUB_Remove()*

*Defined at line 551 of ./game/shared/c_base_entity.cpp*

 Convenient way to delay removing oneself

 common member functions

### SUB_DoNothing

*public void SUB_DoNothing()*

*Defined at line 601 of ./game/shared/c_base_entity.cpp*

 Convenient way to explicitly do nothing (passed to functions that require a method)

### SUB_StartFadeOut

*public void SUB_StartFadeOut()*

*Defined at line 631 of ./game/server/combat.cpp*

 fade out - slowly fades a entity out, then removes it.

 DON'T USE ME FOR GIBS AND STUFF IN MULTIPLAYER!  SET A FUTURE THINK AND A RENDERMODE!!

### SUB_FadeOut

*public void SUB_FadeOut()*

*Defined at line 646 of ./game/server/combat.cpp*

### SUB_CallUseToggle

*public void SUB_CallUseToggle()*

*Defined at line 162 of ./game/shared/c_base_entity.h*

### ShouldToggle

*public int ShouldToggle(USE_TYPE useType, _Bool currentState)*

*Defined at line 286 of ./game/shared/c_base_entity.cpp*

### FireBullets

*public void FireBullets(ULONG cShots, Vector vecSrc, Vector vecDirShooting, Vector vecSpread, float flDistance, int iBulletType, int iTracerFreq, int iDamage, entvars_t * pevAttacker)*

*Defined at line 615 of ./game/shared/c_base_entity.cpp*

================FireBullets

Go to the trouble of combining multiple pellets into a single damage call.

This version is used by Monsters.================

### FireBulletsPlayer

*public Vector FireBulletsPlayer(ULONG cShots, Vector vecSrc, Vector vecDirShooting, Vector vecSpread, float flDistance, int iBulletType, int iTracerFreq, int iDamage, entvars_t * pevAttacker, int shared_rand)*

*Defined at line 746 of ./game/shared/c_base_entity.cpp*

================FireBullets

Go to the trouble of combining multiple pellets into a single damage call.

This version is used by Players, uses the random seed generator to sync client and server side shots.================

### Respawn

*public class CBaseEntity * Respawn()*

*Defined at line 167 of ./game/shared/c_base_entity.h*

### SUB_UseTargets

*public void SUB_UseTargets(class CBaseEntity * pActivator, USE_TYPE useType, float value)*

*Defined at line 585 of ./game/shared/c_base_entity.cpp*

==============================SUB_UseTargets

If self.delay is set, a DelayedUse entity will be created that will actuallydo the SUB_UseTargets after that many seconds have passed.

Removes all entities with a targetname that match self.killtarget,and removes them, so some events can remove other triggers.

Search for (string)targetname in all entities thatmatch (string)self.target and call their .use function (if they have one)

==============================

### Intersects

*public int Intersects(class CBaseEntity * pOther)*

*Defined at line 217 of ./game/shared/c_base_entity.cpp*

 Do the bounding boxes of these two intersect?

### MakeDormant

*public void MakeDormant()*

*Defined at line 229 of ./game/shared/c_base_entity.cpp*

### Instance

*public class CBaseEntity * Instance(edict_t * pent)*

*Defined at line 174 of ./game/shared/c_base_entity.h*

### Instance

*public class CBaseEntity * Instance(entvars_t * pev)*

*Defined at line 183 of ./game/shared/c_base_entity.h*

 Returns the instance of this class 

### Instance

*public class CBaseEntity * Instance(int eoffset)*

*Defined at line 184 of ./game/shared/c_base_entity.h*

### GetMonsterPointer

*public class CBaseMonster * GetMonsterPointer(entvars_t * pevMonster)*

*Defined at line 186 of ./game/shared/c_base_entity.h*

### GetMonsterPointer

*public class CBaseMonster * GetMonsterPointer(edict_t * pentMonster)*

*Defined at line 193 of ./game/shared/c_base_entity.h*

### UpdateOwner

*public void UpdateOwner()*

*Defined at line 201 of ./game/shared/c_base_entity.h*

### Create

*public class CBaseEntity * Create(const char * szName, const class Vector & vecOrigin, const class Vector & vecAngles, edict_t * pentOwner)*

*Defined at line 317 of ./game/shared/c_base_entity.cpp*

 NOTE: szName must be a pointer to constant memory, e.g. "monster_class" because the entity will keep a pointer to it after this call.

### FBecomeProne

*public _Bool FBecomeProne()*

*Defined at line 205 of ./game/shared/c_base_entity.h*

### edict

*public edict_t * edict()*

*Defined at line 206 of ./game/shared/c_base_entity.h*

### eoffset

*public EOFFSET eoffset()*

*Defined at line 207 of ./game/shared/c_base_entity.h*

### entindex

*public int entindex()*

*Defined at line 208 of ./game/shared/c_base_entity.h*

### Center

*public Vector Center()*

*Defined at line 211 of ./game/shared/c_base_entity.h*

 Camera and Ear Positioning 

### EyePosition

*public Vector EyePosition()*

*Defined at line 212 of ./game/shared/c_base_entity.h*

### EarPosition

*public Vector EarPosition()*

*Defined at line 213 of ./game/shared/c_base_entity.h*

### BodyTarget

*public Vector BodyTarget(const class Vector & posSrc)*

*Defined at line 214 of ./game/shared/c_base_entity.h*

### Illumination

*public int Illumination()*

*Defined at line 216 of ./game/shared/c_base_entity.h*

### FVisible

*public _Bool FVisible(class CBaseEntity * pEntity)*

*Defined at line 350 of ./game/shared/c_base_entity.cpp*

### FVisible

*public _Bool FVisible(const class Vector & vecOrigin)*

*Defined at line 388 of ./game/shared/c_base_entity.cpp*



