# class CISlave

*Defined at line 42 of ./game/server/islave.cpp*

Inherits from CSquadMonster



## Members

public int m_iBravery

public class CBeam *[8] m_pBeam

public int m_iBeams

public float m_flNextAttack

public int m_voicePitch

EHANDLE m_hDead



## Functions

### Spawn

*public void Spawn()*

*Defined at line 507 of ./game/server/islave.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 532 of ./game/server/islave.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### UpdateOnRemove

*public void UpdateOnRemove()*

*Defined at line 561 of ./game/server/islave.cpp*

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 272 of ./game/server/islave.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### ISoundMask

*public int ISoundMask()*

*Defined at line 254 of ./game/server/islave.cpp*

========================================================= ISoundMask - returns a bit mask indicating which types of sounds this monster regards. =========================================================

### Classify

*public int Classify()*

*Defined at line 146 of ./game/server/islave.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### IRelationship

*public int IRelationship(class CBaseEntity * pTarget)*

*Defined at line 151 of ./game/server/islave.cpp*

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 301 of ./game/server/islave.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.

 Returns number of events handled, 0 if none.=========================================================

### CheckRangeAttack1

*public BOOL CheckRangeAttack1(float flDot, float flDist)*

*Defined at line 439 of ./game/server/islave.cpp*

========================================================= CheckRangeAttack1 - normal beam attack =========================================================

### CheckRangeAttack2

*public BOOL CheckRangeAttack2(float flDot, float flDist)*

*Defined at line 452 of ./game/server/islave.cpp*

========================================================= CheckRangeAttack2 - check bravery and try to resurect dead comrades=========================================================

### CallForHelp

*public void CallForHelp(const char * szClassname, float flDist, EHANDLE hEnemy, class Vector & vecLocation)*

*Defined at line 159 of ./game/server/islave.cpp*

### TraceAttack

*public void TraceAttack(entvars_t * pevAttacker, float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 582 of ./game/server/islave.cpp*

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 572 of ./game/server/islave.cpp*

========================================================= TakeDamage - get provoked when injured=========================================================

### DeathSound

*public void DeathSound()*

*Defined at line 245 of ./game/server/islave.cpp*

========================================================= DieSound=========================================================

### PainSound

*public void PainSound()*

*Defined at line 234 of ./game/server/islave.cpp*

========================================================= PainSound=========================================================

### AlertSound

*public void AlertSound()*

*Defined at line 187 of ./game/server/islave.cpp*

========================================================= ALertSound - scream=========================================================

### IdleSound

*public void IdleSound()*

*Defined at line 200 of ./game/server/islave.cpp*

========================================================= IdleSound=========================================================

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 262 of ./game/server/islave.cpp*

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 497 of ./game/server/islave.cpp*

========================================================= StartTask=========================================================

### GetSchedule

*public struct Schedule_t * GetSchedule()*

*Defined at line 625 of ./game/server/islave.cpp*

==================================================================================================================

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int Type)*

*Defined at line 681 of ./game/server/islave.cpp*

### ScheduleFromName

*public struct Schedule_t * ScheduleFromName(const char * pName)*

*Defined at line 621 of ./game/server/islave.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 115 of ./game/server/islave.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 115 of ./game/server/islave.cpp*

### ClearBeams

*public void ClearBeams()*

*Defined at line 828 of ./game/server/islave.cpp*

========================================================= ClearBeams - remove all beams=========================================================

### ArmBeam

*public void ArmBeam(int side)*

*Defined at line 702 of ./game/server/islave.cpp*

========================================================= ArmBeam - small beam from arm to nearby geometry=========================================================

### WackBeam

*public void WackBeam(int side, class CBaseEntity * pEntity)*

*Defined at line 765 of ./game/server/islave.cpp*

========================================================= WackBeam - regenerate dead colleagues=========================================================

### ZapBeam

*public void ZapBeam(int side)*

*Defined at line 791 of ./game/server/islave.cpp*

========================================================= ZapBeam - heavy damage directly forward=========================================================

### BeamGlow

*public void BeamGlow()*

*Defined at line 747 of ./game/server/islave.cpp*

========================================================= BeamGlow - brighten all beams=========================================================



