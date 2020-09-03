# class CIchthyosaur

*Defined at line 50 of ./game/server/npc/npc_ichthyosaur.cpp*

 UNDONE: Save/restore here



Inherits from CFlyingMonster



## Members

Vector m_SaveVelocity

public float m_idealDist

public float m_flBlink

public float m_flEnemyTouched

public BOOL m_bOnAttack

public float m_flMaxSpeed

public float m_flMinSpeed

public float m_flMaxDist

public class CBeam * m_pBeam

public float m_flNextAlert



## Functions

### Spawn

*public void Spawn()*

*Defined at line 465 of ./game/server/npc/npc_ichthyosaur.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 504 of ./game/server/npc/npc_ichthyosaur.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 381 of ./game/server/npc/npc_ichthyosaur.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### Classify

*public int Classify()*

*Defined at line 321 of ./game/server/npc/npc_ichthyosaur.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 411 of ./game/server/npc/npc_ichthyosaur.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.=========================================================

### ScheduleFromName

*public struct Schedule_t * ScheduleFromName(const char * pName)*

*Defined at line 315 of ./game/server/npc/npc_ichthyosaur.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 139 of ./game/server/npc/npc_ichthyosaur.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 139 of ./game/server/npc/npc_ichthyosaur.cpp*

### GetSchedule

*public struct Schedule_t * GetSchedule()*

*Defined at line 519 of ./game/server/npc/npc_ichthyosaur.cpp*

========================================================= GetSchedule=========================================================

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int Type)*

*Defined at line 565 of ./game/server/npc/npc_ichthyosaur.cpp*

==================================================================================================================

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 389 of ./game/server/npc/npc_ichthyosaur.cpp*

========================================================= Killed - overrides CFlyingMonster.

### BecomeDead

*public void BecomeDead()*

*Defined at line 395 of ./game/server/npc/npc_ichthyosaur.cpp*

### CombatUse

*public void CombatUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 348 of ./game/server/npc/npc_ichthyosaur.cpp*

### BiteTouch

*public void BiteTouch(class CBaseEntity * pOther)*

*Defined at line 338 of ./game/server/npc/npc_ichthyosaur.cpp*

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 590 of ./game/server/npc/npc_ichthyosaur.cpp*

========================================================= Start task - selects the correct activity and performs any necessary calculations to start the next task on the schedule.=========================================================

### RunTask

*public void RunTask(struct Task_t * pTask)*

*Defined at line 620 of ./game/server/npc/npc_ichthyosaur.cpp*

### CheckMeleeAttack1

*public BOOL CheckMeleeAttack1(float flDot, float flDist)*

*Defined at line 329 of ./game/server/npc/npc_ichthyosaur.cpp*

========================================================= CheckMeleeAttack1=========================================================

### CheckRangeAttack1

*public BOOL CheckRangeAttack1(float flDot, float flDist)*

*Defined at line 367 of ./game/server/npc/npc_ichthyosaur.cpp*

========================================================= CheckRangeAttack1  - swim in for a chomp

=========================================================

### ChangeYaw

*public float ChangeYaw(int speed)*

*Defined at line 801 of ./game/server/npc/npc_ichthyosaur.cpp*

### GetStoppedActivity

*public Activity GetStoppedActivity()*

*Defined at line 820 of ./game/server/npc/npc_ichthyosaur.cpp*

### Move

*public void Move(float flInterval)*

*Defined at line 751 of ./game/server/npc/npc_ichthyosaur.cpp*

=========================================================

### MoveExecute

*public void MoveExecute(class CBaseEntity * pTargetEnt, const class Vector & vecDir, float flInterval)*

*Defined at line 827 of ./game/server/npc/npc_ichthyosaur.cpp*

### MonsterThink

*public void MonsterThink()*

*Defined at line 832 of ./game/server/npc/npc_ichthyosaur.cpp*

### Stop

*public void Stop()*

*Defined at line 859 of ./game/server/npc/npc_ichthyosaur.cpp*

### Swim

*public void Swim()*

*Defined at line 865 of ./game/server/npc/npc_ichthyosaur.cpp*

### DoProbe

*public Vector DoProbe(const class Vector & Probe)*

*Defined at line 1053 of ./game/server/npc/npc_ichthyosaur.cpp*

### VectorToPitch

*public float VectorToPitch(const class Vector & vec)*

*Defined at line 736 of ./game/server/npc/npc_ichthyosaur.cpp*

### FlPitchDiff

*public float FlPitchDiff()*

*Defined at line 756 of ./game/server/npc/npc_ichthyosaur.cpp*

### ChangePitch

*public float ChangePitch(int speed)*

*Defined at line 783 of ./game/server/npc/npc_ichthyosaur.cpp*

### IdleSound

*public void IdleSound()*

*Defined at line 183 of ./game/server/npc/npc_ichthyosaur.cpp*

### AlertSound

*public void AlertSound()*

*Defined at line 188 of ./game/server/npc/npc_ichthyosaur.cpp*

### AttackSound

*public void AttackSound()*

*Defined at line 193 of ./game/server/npc/npc_ichthyosaur.cpp*

### BiteSound

*public void BiteSound()*

*Defined at line 198 of ./game/server/npc/npc_ichthyosaur.cpp*

### DeathSound

*public void DeathSound()*

*Defined at line 203 of ./game/server/npc/npc_ichthyosaur.cpp*

### PainSound

*public void PainSound()*

*Defined at line 208 of ./game/server/npc/npc_ichthyosaur.cpp*



