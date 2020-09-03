# class CBullsquid

*Defined at line 187 of ./game/server/npc/npc_bullsquid.cpp*

Inherits from CBaseMonster



## Members

public BOOL m_fCanThreatDisplay

public float m_flLastHurtTime

public float m_flNextSpitTime



## Functions

### Spawn

*public void Spawn()*

*Defined at line 667 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 691 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 501 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### ISoundMask

*public int ISoundMask()*

*Defined at line 410 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= ISoundMask - returns a bit mask indicating which types of sounds this monster regards. In the base class implementation, monsters care about all sounds, but no scents.=========================================================

### Classify

*public int Classify()*

*Defined at line 424 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 533 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.=========================================================

### IdleSound

*public void IdleSound()*

*Defined at line 433 of ./game/server/npc/npc_bullsquid.cpp*

### PainSound

*public void PainSound()*

*Defined at line 458 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= PainSound =========================================================

### DeathSound

*public void DeathSound()*

*Defined at line 735 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= DeathSound=========================================================

### AlertSound

*public void AlertSound()*

*Defined at line 482 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= AlertSound=========================================================

### AttackSound

*public void AttackSound()*

*Defined at line 754 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= AttackSound=========================================================

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 1154 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= Start task - selects the correct activity and performs any necessary calculations to start the next task on the schedule.  OVERRIDDEN for bullsquid because it needs to know explicitly when the last attempt to chase the enemy failed, since that impacts its attack choices.=========================================================

### RunTask

*public void RunTask(struct Task_t * pTask)*

*Defined at line 1208 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= RunTask=========================================================

### CheckMeleeAttack1

*public BOOL CheckMeleeAttack1(float flDot, float flDist)*

*Defined at line 357 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= CheckMeleeAttack1 - bullsquid is a big guy, so has a longer melee range than most monsters. This is the tailwhip attack=========================================================

### CheckMeleeAttack2

*public BOOL CheckMeleeAttack2(float flDot, float flDist)*

*Defined at line 372 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= CheckMeleeAttack2 - bullsquid is a big guy, so has a longer melee range than most monsters. This is the bite attack. this attack will not be performed if the tailwhip attack is valid.=========================================================

### CheckRangeAttack1

*public BOOL CheckRangeAttack1(float flDot, float flDist)*

*Defined at line 317 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= CheckRangeAttack1=========================================================

### RunAI

*public void RunAI()*

*Defined at line 771 of ./game/server/npc/npc_bullsquid.cpp*

======================================================== RunAI - overridden for bullsquid because there are things that need to be checked every think.========================================================

### FValidateHintType

*public BOOL FValidateHintType(short sHint)*

*Defined at line 384 of ./game/server/npc/npc_bullsquid.cpp*

=========================================================  FValidateHintType =========================================================

### GetSchedule

*public struct Schedule_t * GetSchedule()*

*Defined at line 1012 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= GetSchedule =========================================================

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int Type)*

*Defined at line 1117 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= GetScheduleOfType=========================================================

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 283 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= TakeDamage - overridden for bullsquid so we can keep track of how much time has passed since it was last injured=========================================================

### IRelationship

*public int IRelationship(class CBaseEntity * pTarget)*

*Defined at line 267 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= IRelationship - overridden for bullsquid so that it can be made to ignore its love of headcrabs for a while.=========================================================

### IgnoreConditions

*public int IgnoreConditions()*

*Defined at line 241 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= IgnoreConditions =========================================================

### GetIdealState

*public MONSTERSTATE GetIdealState()*

*Defined at line 1236 of ./game/server/npc/npc_bullsquid.cpp*

========================================================= GetIdealState - Overridden for Bullsquid to deal with the feature that makes it lose interest in headcrabs for  a while if something injures it. =========================================================

### Save

*public int Save(class CSave & save)*

*Defined at line 236 of ./game/server/npc/npc_bullsquid.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 236 of ./game/server/npc/npc_bullsquid.cpp*

### ScheduleFromName

*public struct Schedule_t * ScheduleFromName(const char * pName)*

*Defined at line 1007 of ./game/server/npc/npc_bullsquid.cpp*



