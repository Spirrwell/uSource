# class CBarney

*Defined at line 43 of ./game/server/npc/npc_barney.cpp*

Inherits from CTalkMonster



## Members

public BOOL m_fGunDrawn

public float m_painTime

public float m_checkAttackTime

public BOOL m_lastAttackCheck

public float m_flPlayerDamage



## Functions

### Spawn

*public void Spawn()*

*Defined at line 394 of ./game/server/npc/npc_barney.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 421 of ./game/server/npc/npc_barney.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 278 of ./game/server/npc/npc_barney.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### ISoundMask

*public int ISoundMask()*

*Defined at line 240 of ./game/server/npc/npc_barney.cpp*

========================================================= ISoundMask - returns a bit mask indicating which types of sounds this monster regards. =========================================================

### BarneyFirePistol

*public void BarneyFirePistol()*

*Defined at line 334 of ./game/server/npc/npc_barney.cpp*

========================================================= BarneyFirePistol - shoots one round from the pistol at the enemy barney is facing.=========================================================

### AlertSound

*public void AlertSound()*

*Defined at line 263 of ./game/server/npc/npc_barney.cpp*

========================================================= ALertSound - barney says "Freeze!"=========================================================

### Classify

*public int Classify()*

*Defined at line 255 of ./game/server/npc/npc_barney.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 369 of ./game/server/npc/npc_barney.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.

 Returns number of events handled, 0 if none.=========================================================

### RunTask

*public void RunTask(struct Task_t * pTask)*

*Defined at line 219 of ./game/server/npc/npc_barney.cpp*

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 214 of ./game/server/npc/npc_barney.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 57 of ./game/server/npc/npc_barney.cpp*

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 494 of ./game/server/npc/npc_barney.cpp*

### CheckRangeAttack1

*public BOOL CheckRangeAttack1(float flDot, float flDist)*

*Defined at line 306 of ./game/server/npc/npc_barney.cpp*

========================================================= CheckRangeAttack1=========================================================

### DeclineFollowing

*public void DeclineFollowing()*

*Defined at line 762 of ./game/server/npc/npc_barney.cpp*

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int Type)*

*Defined at line 629 of ./game/server/npc/npc_barney.cpp*

 Override these to set behavior

========================================================= AI Schedules Specific to this monster=========================================================

### GetSchedule

*public struct Schedule_t * GetSchedule()*

*Defined at line 677 of ./game/server/npc/npc_barney.cpp*

========================================================= GetSchedule - Decides which type of schedule best suits the monster's current state and conditions. Then calls monster's member function to get a pointer to a schedule of the proper type.=========================================================

### GetIdealState

*public MONSTERSTATE GetIdealState()*

*Defined at line 757 of ./game/server/npc/npc_barney.cpp*

### DeathSound

*public void DeathSound()*

*Defined at line 561 of ./game/server/npc/npc_barney.cpp*

========================================================= DeathSound =========================================================

### PainSound

*public void PainSound()*

*Defined at line 537 of ./game/server/npc/npc_barney.cpp*

========================================================= PainSound=========================================================

### TalkInit

*public void TalkInit()*

*Defined at line 443 of ./game/server/npc/npc_barney.cpp*

 Init talk data

### TraceAttack

*public void TraceAttack(entvars_t * pevAttacker, float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 577 of ./game/server/npc/npc_barney.cpp*

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 607 of ./game/server/npc/npc_barney.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 102 of ./game/server/npc/npc_barney.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 102 of ./game/server/npc/npc_barney.cpp*

### ScheduleFromName

*public struct Schedule_t * ScheduleFromName(const char * pName)*

*Defined at line 212 of ./game/server/npc/npc_barney.cpp*



