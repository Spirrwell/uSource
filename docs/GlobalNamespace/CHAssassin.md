# class CHAssassin

*Defined at line 63 of ./game/server/npc/npc_hassassin.cpp*

Inherits from CBaseMonster



## Members

public float m_flLastShot

public float m_flDiviation

public float m_flNextJump

Vector m_vecJumpVelocity

public float m_flNextGrenadeCheck

Vector m_vecTossVelocity

public BOOL m_fThrowGrenade

public int m_iTargetRanderamt

public int m_iFrustration

public int m_iShell



## Functions

### Spawn

*public void Spawn()*

*Defined at line 275 of ./game/server/npc/npc_hassassin.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 304 of ./game/server/npc/npc_hassassin.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 166 of ./game/server/npc/npc_hassassin.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### Classify

*public int Classify()*

*Defined at line 157 of ./game/server/npc/npc_hassassin.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### ISoundMask

*public int ISoundMask()*

*Defined at line 145 of ./game/server/npc/npc_hassassin.cpp*

========================================================= ISoundMask - returns a bit mask indicating which types of sounds this monster regards. =========================================================

### Shoot

*public void Shoot()*

*Defined at line 187 of ./game/server/npc/npc_hassassin.cpp*

========================================================= Shoot=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 239 of ./game/server/npc/npc_hassassin.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.

 Returns number of events handled, 0 if none.=========================================================

### GetSchedule

*public struct Schedule_t * GetSchedule()*

*Defined at line 812 of ./game/server/npc/npc_hassassin.cpp*

========================================================= GetSchedule - Decides which type of schedule best suits the monster's current state and conditions. Then calls monster's member function to get a pointer to a schedule of the proper type.=========================================================

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int Type)*

*Defined at line 943 of ./game/server/npc/npc_hassassin.cpp*

==================================================================================================================

### CheckMeleeAttack1

*public BOOL CheckMeleeAttack1(float flDot, float flDist)*

*Defined at line 599 of ./game/server/npc/npc_hassassin.cpp*

========================================================= CheckMeleeAttack1 - jump like crazy if the enemy gets too close. =========================================================

### CheckRangeAttack1

*public BOOL CheckRangeAttack1(float flDot, float flDist)*

*Defined at line 629 of ./game/server/npc/npc_hassassin.cpp*

 BOOL CheckMeleeAttack2( float flDot, float flDist );

========================================================= CheckRangeAttack1  - drop a cap in their ass

=========================================================

### CheckRangeAttack2

*public BOOL CheckRangeAttack2(float flDot, float flDist)*

*Defined at line 651 of ./game/server/npc/npc_hassassin.cpp*

========================================================= CheckRangeAttack2 - toss grenade is enemy gets in the way and is too close. =========================================================

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 741 of ./game/server/npc/npc_hassassin.cpp*

========================================================= StartTask=========================================================

### RunAI

*public void RunAI()*

*Defined at line 685 of ./game/server/npc/npc_hassassin.cpp*

========================================================= RunAI=========================================================

### RunTask

*public void RunTask(struct Task_t * pTask)*

*Defined at line 766 of ./game/server/npc/npc_hassassin.cpp*

========================================================= RunTask =========================================================

### DeathSound

*public void DeathSound()*

*Defined at line 130 of ./game/server/npc/npc_hassassin.cpp*

========================================================= DieSound=========================================================

### IdleSound

*public void IdleSound()*

*Defined at line 137 of ./game/server/npc/npc_hassassin.cpp*

========================================================= IdleSound=========================================================

### ScheduleFromName

*public struct Schedule_t * ScheduleFromName(const char * pName)*

*Defined at line 594 of ./game/server/npc/npc_hassassin.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 125 of ./game/server/npc/npc_hassassin.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 125 of ./game/server/npc/npc_hassassin.cpp*



