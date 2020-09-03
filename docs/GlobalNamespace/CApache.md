# class CApache

*Defined at line 31 of ./game/server/npc/npc_apache.cpp*

Inherits from CBaseMonster



## Members

private int m_iRockets

private float m_flForce

private float m_flNextRocket

Vector m_vecTarget

Vector m_posTarget

Vector m_vecDesired

Vector m_posDesired

Vector m_vecGoal

Vector m_angGun

private float m_flLastSeen

private float m_flPrevSeen

private int m_iSoundState

private int m_iSpriteTexture

private int m_iExplode

private int m_iBodyGibs

private float m_flGoalSpeed

private int m_iDoSmokePuff

private class CBeam * m_pBeam



## Functions

### Save

*private int Save(class CSave & save)*

*Defined at line 117 of ./game/server/npc/npc_apache.cpp*

### Restore

*private int Restore(class CRestore & restore)*

*Defined at line 117 of ./game/server/npc/npc_apache.cpp*

### Spawn

*private void Spawn()*

*Defined at line 119 of ./game/server/npc/npc_apache.cpp*

### Precache

*private void Precache()*

*Defined at line 156 of ./game/server/npc/npc_apache.cpp*

### Classify

*private int Classify()*

*Defined at line 39 of ./game/server/npc/npc_apache.cpp*

### BloodColor

*private int BloodColor()*

*Defined at line 40 of ./game/server/npc/npc_apache.cpp*

### Killed

*private void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 193 of ./game/server/npc/npc_apache.cpp*

### GibMonster

*private void GibMonster()*

*Defined at line 429 of ./game/server/npc/npc_apache.cpp*

### SetObjectCollisionBox

*private void SetObjectCollisionBox()*

*Defined at line 44 of ./game/server/npc/npc_apache.cpp*

### HuntThink

*private void HuntThink()*

*Defined at line 434 of ./game/server/npc/npc_apache.cpp*

### FlyTouch

*private void FlyTouch(class CBaseEntity * pOther)*

*Defined at line 406 of ./game/server/npc/npc_apache.cpp*

### CrashTouch

*private void CrashTouch(class CBaseEntity * pOther)*

*Defined at line 418 of ./game/server/npc/npc_apache.cpp*

### DyingThink

*private void DyingThink()*

*Defined at line 217 of ./game/server/npc/npc_apache.cpp*

### StartupUse

*private void StartupUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 185 of ./game/server/npc/npc_apache.cpp*

### NullThink

*private void NullThink()*

*Defined at line 179 of ./game/server/npc/npc_apache.cpp*

### ShowDamage

*private void ShowDamage()*

*Defined at line 861 of ./game/server/npc/npc_apache.cpp*

### Flight

*private void Flight()*

*Defined at line 581 of ./game/server/npc/npc_apache.cpp*

### FireRocket

*private void FireRocket()*

*Defined at line 733 of ./game/server/npc/npc_apache.cpp*

### FireGun

*private BOOL FireGun()*

*Defined at line 780 of ./game/server/npc/npc_apache.cpp*

### TakeDamage

*private int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 879 of ./game/server/npc/npc_apache.cpp*

### TraceAttack

*private void TraceAttack(entvars_t * pevAttacker, float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 901 of ./game/server/npc/npc_apache.cpp*



