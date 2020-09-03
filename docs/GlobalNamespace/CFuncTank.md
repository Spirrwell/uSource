# class CFuncTank

*Defined at line 46 of ./game/server/func_tank.cpp*

			Custom damage			env_laser (duration is 0.5 rate of fire)			rockets			explosion?



Inherits from CBaseEntity



## Members

protected class CBasePlayer * m_pController

protected float m_flNextAttack

Vector m_vecControllerUsePos

protected float m_yawCenter

protected float m_yawRate

protected float m_yawRange

protected float m_yawTolerance

protected float m_pitchCenter

protected float m_pitchRate

protected float m_pitchRange

protected float m_pitchTolerance

protected float m_fireLast

protected float m_fireRate

protected float m_lastSightTime

protected float m_persist

protected float m_minRange

protected float m_maxRange

Vector m_barrelPos

protected float m_spriteScale

protected string_t m_iszSpriteSmoke

protected string_t m_iszSpriteFlash

protected enum TANKBULLET m_bulletType

protected int m_iBulletDamage

Vector m_sightOrigin

protected int m_spread

protected string_t m_iszMaster



## Functions

### Spawn

*public void Spawn()*

*Defined at line 176 of ./game/server/func_tank.cpp*

### Precache

*public void Precache()*

*Defined at line 200 of ./game/server/func_tank.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 212 of ./game/server/func_tank.cpp*

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 421 of ./game/server/func_tank.cpp*

/////////// END NEW STUFF //////////////

### Think

*public void Think()*

*Defined at line 469 of ./game/server/func_tank.cpp*

### TrackTarget

*public void TrackTarget()*

*Defined at line 480 of ./game/server/func_tank.cpp*

### Fire

*public void Fire(const class Vector & barrelEnd, const class Vector & forward, entvars_t * pevAttacker)*

*Defined at line 640 of ./game/server/func_tank.cpp*

 Fire targets and spawn sprites

### UpdateTargetPosition

*public Vector UpdateTargetPosition(class CBaseEntity * pTarget)*

*Defined at line 57 of ./game/server/func_tank.cpp*

### StartRotSound

*public void StartRotSound()*

*Defined at line 686 of ./game/server/func_tank.cpp*

### StopRotSound

*public void StopRotSound()*

*Defined at line 694 of ./game/server/func_tank.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 66 of ./game/server/func_tank.cpp*

 Bmodels don't go across transitions

### IsActive

*public BOOL IsActive()*

*Defined at line 68 of ./game/server/func_tank.cpp*

### TankActivate

*public void TankActivate()*

*Defined at line 69 of ./game/server/func_tank.cpp*

### TankDeactivate

*public void TankDeactivate()*

*Defined at line 70 of ./game/server/func_tank.cpp*

### CanFire

*public BOOL CanFire()*

*Defined at line 71 of ./game/server/func_tank.cpp*

### InRange

*public BOOL InRange(float range)*

*Defined at line 459 of ./game/server/func_tank.cpp*

### FindTarget

*public edict_t * FindTarget(edict_t * pPlayer)*

*Defined at line 454 of ./game/server/func_tank.cpp*

 Acquire a target.  pPlayer is a player in the PVS

### TankTrace

*public void TankTrace(const class Vector & vecStart, const class Vector & vecForward, const class Vector & vecSpread, TraceResult & tr)*

*Defined at line 667 of ./game/server/func_tank.cpp*

### BarrelPosition

*public Vector BarrelPosition()*

*Defined at line 79 of ./game/server/func_tank.cpp*

### AdjustAnglesForBarrel

*public void AdjustAnglesForBarrel(class Vector & angles, float distance)*

*Defined at line 618 of ./game/server/func_tank.cpp*

 If barrel is offset, add in additional rotation

### Save

*public int Save(class CSave & save)*

*Defined at line 163 of ./game/server/func_tank.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 163 of ./game/server/func_tank.cpp*

### OnControls

*public _Bool OnControls(entvars_t * pevTest)*

*Defined at line 327 of ./game/server/func_tank.cpp*

================================================================================== TANK CONTROLLING

### StartControl

*public BOOL StartControl(class CBasePlayer * pController)*

*Defined at line 340 of ./game/server/func_tank.cpp*

### StopControl

*public void StopControl()*

*Defined at line 371 of ./game/server/func_tank.cpp*

### ControllerPostFrame

*public void ControllerPostFrame()*

*Defined at line 396 of ./game/server/func_tank.cpp*

 Called each frame by the player's ItemPostFrame

### StopFire

*public void StopFire()*

*Defined at line 96 of ./game/server/func_tank.cpp*



