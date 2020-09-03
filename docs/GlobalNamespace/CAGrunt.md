# class CAGrunt

*Defined at line 69 of ./game/server/npc/npc_agrunt.cpp*

Inherits from CSquadMonster



## Members

public BOOL m_fCanHornetAttack

public float m_flNextHornetAttackCheck

public float m_flNextPainTime

public float m_flNextSpeakTime

public float m_flNextWordTime

public int m_iLastWord



## Functions

### Spawn

*public void Spawn()*

*Defined at line 582 of ./game/server/npc/npc_agrunt.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 609 of ./game/server/npc/npc_agrunt.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 391 of ./game/server/npc/npc_agrunt.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### Classify

*public int Classify()*

*Defined at line 382 of ./game/server/npc/npc_agrunt.cpp*

========================================================= Classify - indicates this monster's place in the relationship table.=========================================================

### ISoundMask

*public int ISoundMask()*

*Defined at line 207 of ./game/server/npc/npc_agrunt.cpp*

========================================================= ISoundMask =========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 415 of ./game/server/npc/npc_agrunt.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.

 Returns number of events handled, 0 if none.=========================================================

### SetObjectCollisionBox

*public void SetObjectCollisionBox()*

*Defined at line 78 of ./game/server/npc/npc_agrunt.cpp*

### GetSchedule

*public struct Schedule_t * GetSchedule()*

*Defined at line 1062 of ./game/server/npc/npc_agrunt.cpp*

========================================================= GetSchedule - Decides which type of schedule best suits the monster's current state and conditions. Then calls monster's member function to get a pointer to a schedule of the proper type.=========================================================

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int Type)*

*Defined at line 1128 of ./game/server/npc/npc_agrunt.cpp*

==================================================================================================================

### FCanCheckAttacks

*public BOOL FCanCheckAttacks()*

*Defined at line 894 of ./game/server/npc/npc_agrunt.cpp*

========================================================= FCanCheckAttacks - this is overridden for alien grunts because they can use their smart weapons against unseen enemies. Base class doesn't attack anyone it can't see.=========================================================

### CheckMeleeAttack1

*public BOOL CheckMeleeAttack1(float flDot, float flDist)*

*Defined at line 910 of ./game/server/npc/npc_agrunt.cpp*

========================================================= CheckMeleeAttack1 - alien grunts zap the crap out of  any enemy that gets too close. =========================================================

### CheckRangeAttack1

*public BOOL CheckRangeAttack1(float flDot, float flDist)*

*Defined at line 926 of ./game/server/npc/npc_agrunt.cpp*

========================================================= CheckRangeAttack1 

 !!!LATER - we may want to load balance this. Several tracelines are done, so we may not want to do this every server frame. Definitely not while firing. =========================================================

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 961 of ./game/server/npc/npc_agrunt.cpp*

========================================================= StartTask=========================================================

### AlertSound

*public void AlertSound()*

*Defined at line 344 of ./game/server/npc/npc_agrunt.cpp*

========================================================= AlertSound=========================================================

### DeathSound

*public void DeathSound()*

*Defined at line 334 of ./game/server/npc/npc_agrunt.cpp*

========================================================= DieSound=========================================================

### PainSound

*public void PainSound()*

*Defined at line 364 of ./game/server/npc/npc_agrunt.cpp*

========================================================= PainSound=========================================================

### AttackSound

*public void AttackSound()*

*Defined at line 354 of ./game/server/npc/npc_agrunt.cpp*

========================================================= AttackSound=========================================================

### PrescheduleThink

*public void PrescheduleThink()*

*Defined at line 299 of ./game/server/npc/npc_agrunt.cpp*

========================================================= PrescheduleThink =========================================================

### TraceAttack

*public void TraceAttack(entvars_t * pevAttacker, float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 215 of ./game/server/npc/npc_agrunt.cpp*

========================================================= TraceAttack=========================================================

### IRelationship

*public int IRelationship(class CBaseEntity * pTarget)*

*Defined at line 194 of ./game/server/npc/npc_agrunt.cpp*

========================================================= IRelationship - overridden because Human Grunts are  Alien Grunt's nemesis.=========================================================

### StopTalking

*public void StopTalking()*

*Defined at line 264 of ./game/server/npc/npc_agrunt.cpp*

========================================================= StopTalking - won't speak again for 10-20 seconds.=========================================================

### ShouldSpeak

*public BOOL ShouldSpeak()*

*Defined at line 272 of ./game/server/npc/npc_agrunt.cpp*

========================================================= ShouldSpeak - Should this agrunt be talking?=========================================================

### ScheduleFromName

*public struct Schedule_t * ScheduleFromName(const char * pName)*

*Defined at line 887 of ./game/server/npc/npc_agrunt.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 136 of ./game/server/npc/npc_agrunt.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 136 of ./game/server/npc/npc_agrunt.cpp*



