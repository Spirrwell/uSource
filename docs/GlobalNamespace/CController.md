# class CController

*Defined at line 41 of ./game/server/ai/ai_controller.cpp*

Inherits from CSquadMonster



## Members

public float m_flNextFlinch

public float m_flShootTime

public float m_flShootEnd

public class CSprite *[2] m_pBall

public int [2] m_iBall

public float [2] m_iBallTime

public int [2] m_iBallCurrent

Vector m_vecEstVelocity

Vector m_velocity

public int m_fInCombat



## Functions

### Save

*public int Save(class CSave & save)*

*Defined at line 116 of ./game/server/ai/ai_controller.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 116 of ./game/server/ai/ai_controller.cpp*

### Spawn

*public void Spawn()*

*Defined at line 350 of ./game/server/ai/ai_controller.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 372 of ./game/server/ai/ai_controller.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### UpdateOnRemove

*public void UpdateOnRemove()*

*Defined at line 388 of ./game/server/ai/ai_controller.cpp*

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 167 of ./game/server/ai/ai_controller.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### Classify

*public int Classify()*

*Defined at line 158 of ./game/server/ai/ai_controller.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 259 of ./game/server/ai/ai_controller.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.=========================================================

### RunAI

*public void RunAI()*

*Defined at line 819 of ./game/server/ai/ai_controller.cpp*

========================================================= RunAI=========================================================

### CheckRangeAttack1

*public BOOL CheckRangeAttack1(float flDot, float flDist)*

*Defined at line 778 of ./game/server/ai/ai_controller.cpp*

========================================================= CheckRangeAttack1  - shoot a bigass energy ball out of their head

=========================================================

### CheckRangeAttack2

*public BOOL CheckRangeAttack2(float flDot, float flDist)*

*Defined at line 787 of ./game/server/ai/ai_controller.cpp*

### CheckMeleeAttack1

*public BOOL CheckMeleeAttack1(float flDot, float flDist)*

*Defined at line 796 of ./game/server/ai/ai_controller.cpp*

### GetSchedule

*public struct Schedule_t * GetSchedule()*

*Defined at line 722 of ./game/server/ai/ai_controller.cpp*

========================================================= GetSchedule - Decides which type of schedule best suits the monster's current state and conditions. Then calls monster's member function to get a pointer to a schedule of the proper type.=========================================================

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int Type)*

*Defined at line 753 of ./game/server/ai/ai_controller.cpp*

==================================================================================================================

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 498 of ./game/server/ai/ai_controller.cpp*

========================================================= StartTask=========================================================

### RunTask

*public void RunTask(struct Task_t * pTask)*

*Defined at line 622 of ./game/server/ai/ai_controller.cpp*

========================================================= RunTask =========================================================

### ScheduleFromName

*public struct Schedule_t * ScheduleFromName(const char * pName)*

*Defined at line 493 of ./game/server/ai/ai_controller.cpp*

### Stop

*public void Stop()*

*Defined at line 868 of ./game/server/ai/ai_controller.cpp*

### Move

*public void Move(float flInterval)*

*Defined at line 875 of ./game/server/ai/ai_controller.cpp*

### CheckLocalMove

*public int CheckLocalMove(const class Vector & vecStart, const class Vector & vecEnd, class CBaseEntity * pTarget, float * pflDist)*

*Defined at line 1064 of ./game/server/ai/ai_controller.cpp*

### MoveExecute

*public void MoveExecute(class CBaseEntity * pTargetEnt, const class Vector & vecDir, float flInterval)*

*Defined at line 1089 of ./game/server/ai/ai_controller.cpp*

### SetActivity

*public void SetActivity(Activity NewActivity)*

*Defined at line 801 of ./game/server/ai/ai_controller.cpp*

### ShouldAdvanceRoute

*public BOOL ShouldAdvanceRoute(float flWaypointDist)*

*Defined at line 1054 of ./game/server/ai/ai_controller.cpp*

### LookupFloat

*public int LookupFloat()*

*Defined at line 584 of ./game/server/ai/ai_controller.cpp*

### PainSound

*public void PainSound()*

*Defined at line 229 of ./game/server/ai/ai_controller.cpp*

### AlertSound

*public void AlertSound()*

*Defined at line 235 of ./game/server/ai/ai_controller.cpp*

### IdleSound

*public void IdleSound()*

*Defined at line 240 of ./game/server/ai/ai_controller.cpp*

### AttackSound

*public void AttackSound()*

*Defined at line 245 of ./game/server/ai/ai_controller.cpp*

### DeathSound

*public void DeathSound()*

*Defined at line 250 of ./game/server/ai/ai_controller.cpp*

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 180 of ./game/server/ai/ai_controller.cpp*

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 188 of ./game/server/ai/ai_controller.cpp*

### GibMonster

*public void GibMonster()*

*Defined at line 213 of ./game/server/ai/ai_controller.cpp*



