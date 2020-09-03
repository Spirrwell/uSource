# class CNihilanth

*Defined at line 28 of ./game/server/npc/npc_nihilanth.cpp*

Inherits from CBaseMonster



## Members

public float m_flForce

public float m_flNextPainSound

Vector m_velocity

Vector m_avelocity

Vector m_vecTarget

Vector m_posTarget

Vector m_vecDesired

Vector m_posDesired

public float m_flMinZ

public float m_flMaxZ

Vector m_vecGoal

public float m_flLastSeen

public float m_flPrevSeen

public int m_irritation

public int m_iLevel

public int m_iTeleport

EHANDLE m_hRecharger

public class EHANDLE [20] m_hSphere

public int m_iActiveSpheres

public float m_flAdj

public class CSprite * m_pBall

public char [64] m_szRechargerTarget

public char [64] m_szDrawUse

public char [64] m_szTeleportUse

public char [64] m_szTeleportTouch

public char [64] m_szDeadUse

public char [64] m_szDeadTouch

public float m_flShootEnd

public float m_flShootTime

public class EHANDLE [3] m_hFriend



## Functions

### Save

*public int Save(class CSave & save)*

*Defined at line 171 of ./game/server/npc/npc_nihilanth.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 171 of ./game/server/npc/npc_nihilanth.cpp*

### Spawn

*public void Spawn()*

*Defined at line 276 of ./game/server/npc/npc_nihilanth.cpp*

### Precache

*public void Precache()*

*Defined at line 331 of ./game/server/npc/npc_nihilanth.cpp*

### UpdateOnRemove

*public void UpdateOnRemove()*

*Defined at line 349 of ./game/server/npc/npc_nihilanth.cpp*

### Classify

*public int Classify()*

*Defined at line 38 of ./game/server/npc/npc_nihilanth.cpp*

### BloodColor

*public int BloodColor()*

*Defined at line 39 of ./game/server/npc/npc_nihilanth.cpp*

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 435 of ./game/server/npc/npc_nihilanth.cpp*

### GibMonster

*public void GibMonster()*

*Defined at line 570 of ./game/server/npc/npc_nihilanth.cpp*

### SetObjectCollisionBox

*public void SetObjectCollisionBox()*

*Defined at line 43 of ./game/server/npc/npc_nihilanth.cpp*

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 1051 of ./game/server/npc/npc_nihilanth.cpp*

### StartupThink

*public void StartupThink()*

*Defined at line 404 of ./game/server/npc/npc_nihilanth.cpp*

### HuntThink

*public void HuntThink()*

*Defined at line 849 of ./game/server/npc/npc_nihilanth.cpp*

### CrashTouch

*public void CrashTouch(class CBaseEntity * pOther)*

*Defined at line 560 of ./game/server/npc/npc_nihilanth.cpp*

### DyingThink

*public void DyingThink()*

*Defined at line 440 of ./game/server/npc/npc_nihilanth.cpp*

### StartupUse

*public void StartupUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 397 of ./game/server/npc/npc_nihilanth.cpp*

### NullThink

*public void NullThink()*

*Defined at line 391 of ./game/server/npc/npc_nihilanth.cpp*

### CommandUse

*public void CommandUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 1202 of ./game/server/npc/npc_nihilanth.cpp*

### FloatSequence

*public void FloatSequence()*

*Defined at line 575 of ./game/server/npc/npc_nihilanth.cpp*

### NextActivity

*public void NextActivity()*

*Defined at line 688 of ./game/server/npc/npc_nihilanth.cpp*

### Flight

*public void Flight()*

*Defined at line 913 of ./game/server/npc/npc_nihilanth.cpp*

### AbsorbSphere

*public BOOL AbsorbSphere()*

*Defined at line 979 of ./game/server/npc/npc_nihilanth.cpp*

### EmitSphere

*public BOOL EmitSphere()*

*Defined at line 995 of ./game/server/npc/npc_nihilanth.cpp*

### TargetSphere

*public void TargetSphere(USE_TYPE useType, float value)*

*Defined at line 1024 of ./game/server/npc/npc_nihilanth.cpp*

### RandomTargetname

*public class CBaseEntity * RandomTargetname(const char * szName)*

*Defined at line 1277 of ./game/server/npc/npc_nihilanth.cpp*

### ShootBalls

*public void ShootBalls()*

*Defined at line 603 of ./game/server/npc/npc_nihilanth.cpp*

### MakeFriend

*public void MakeFriend(Vector vecPos)*

*Defined at line 639 of ./game/server/npc/npc_nihilanth.cpp*

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 1240 of ./game/server/npc/npc_nihilanth.cpp*

### TraceAttack

*public void TraceAttack(entvars_t * pevAttacker, float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 1258 of ./game/server/npc/npc_nihilanth.cpp*

### PainSound

*public void PainSound()*

*Defined at line 369 of ./game/server/npc/npc_nihilanth.cpp*

### DeathSound

*public void DeathSound()*

*Defined at line 386 of ./game/server/npc/npc_nihilanth.cpp*



