# class CBaseTurret

*Defined at line 54 of ./game/server/npc/npc_turret.cpp*

Inherits from CBaseMonster



## Members

public float m_flMaxSpin

public int m_iSpin

public class CSprite * m_pEyeGlow

public int m_eyeBrightness

public int m_iDeployHeight

public int m_iRetractHeight

public int m_iMinPitch

public int m_iBaseTurnRate

public float m_fTurnRate

public int m_iOrientation

public int m_iOn

public int m_fBeserk

public int m_iAutoStart

Vector m_vecLastSight

public float m_flLastSight

public float m_flMaxWait

public int m_iSearchSpeed

public float m_flStartYaw

Vector m_vecCurAngles

Vector m_vecGoalAngles

public float m_flPingTime

public float m_flSpinUpTime



## Functions

### Spawn

*public void Spawn()*

*Defined at line 241 of ./game/server/npc/npc_turret.cpp*

### Precache

*public void Precache()*

*Defined at line 267 of ./game/server/npc/npc_turret.cpp*

### UpdateOnRemove

*public void UpdateOnRemove()*

*Defined at line 283 of ./game/server/npc/npc_turret.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 209 of ./game/server/npc/npc_turret.cpp*

### TurretUse

*public void TurretUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 394 of ./game/server/npc/npc_turret.cpp*

### TraceAttack

*public void TraceAttack(entvars_t * pevAttacker, float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 982 of ./game/server/npc/npc_turret.cpp*

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 1003 of ./game/server/npc/npc_turret.cpp*

 take damage. bitsDamageType indicates type of damage sustained, ie: DMG_BULLET

### Classify

*public int Classify()*

*Defined at line 1125 of ./game/server/npc/npc_turret.cpp*

 ID as a machine

### BloodColor

*public int BloodColor()*

*Defined at line 67 of ./game/server/npc/npc_turret.cpp*

### GibMonster

*public void GibMonster()*

*Defined at line 68 of ./game/server/npc/npc_turret.cpp*

### ActiveThink

*public void ActiveThink()*

*Defined at line 463 of ./game/server/npc/npc_turret.cpp*

 Think functions

### SearchThink

*public void SearchThink()*

*Defined at line 828 of ./game/server/npc/npc_turret.cpp*

 This search function will sit with the turret deployed and look for a new target.  After a set amount of time, the barrel will spin down. After m_flMaxWait, the turret will retact.

### AutoSearchThink

*public void AutoSearchThink()*

*Defined at line 889 of ./game/server/npc/npc_turret.cpp*

 This think function will deploy the turret when something comes into range. This is for automatically activated turrets.

### TurretDeath

*public void TurretDeath()*

*Defined at line 916 of ./game/server/npc/npc_turret.cpp*

### SpinDownCall

*public void SpinDownCall()*

*Defined at line 76 of ./game/server/npc/npc_turret.cpp*

### SpinUpCall

*public void SpinUpCall()*

*Defined at line 77 of ./game/server/npc/npc_turret.cpp*

### Deploy

*public void Deploy()*

*Defined at line 643 of ./game/server/npc/npc_turret.cpp*

 virtual float SpinDown( void ) { return 0;} virtual float Retire( void ) { return 0;}

### Retire

*public void Retire()*

*Defined at line 681 of ./game/server/npc/npc_turret.cpp*

### Initialize

*public void Initialize()*

*Defined at line 357 of ./game/server/npc/npc_turret.cpp*

### Ping

*public void Ping()*

*Defined at line 422 of ./game/server/npc/npc_turret.cpp*

### EyeOn

*public void EyeOn()*

*Defined at line 439 of ./game/server/npc/npc_turret.cpp*

### EyeOff

*public void EyeOff()*

*Defined at line 451 of ./game/server/npc/npc_turret.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 167 of ./game/server/npc/npc_turret.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 167 of ./game/server/npc/npc_turret.cpp*

### SetTurretAnim

*public void SetTurretAnim(TURRET_ANIM anim)*

*Defined at line 786 of ./game/server/npc/npc_turret.cpp*

 other functions

### MoveTurret

*public int MoveTurret()*

*Defined at line 1040 of ./game/server/npc/npc_turret.cpp*

### Shoot

*public void Shoot(class Vector & vecSrc, class Vector & vecDirToEnemy)*

*Defined at line 102 of ./game/server/npc/npc_turret.cpp*



