# class CHeadCrab

*Defined at line 73 of ./game/server/npc/npc_headcrab.cpp*

Inherits from CBaseMonster



## Functions

### Spawn

*public void Spawn()*

*Defined at line 280 of ./game/server/npc/npc_headcrab.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 303 of ./game/server/npc/npc_headcrab.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### RunTask

*public void RunTask(struct Task_t * pTask)*

*Defined at line 318 of ./game/server/npc/npc_headcrab.cpp*

========================================================= RunTask =========================================================

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 379 of ./game/server/npc/npc_headcrab.cpp*

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 185 of ./game/server/npc/npc_headcrab.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### LeapTouch

*public void LeapTouch(class CBaseEntity * pOther)*

*Defined at line 344 of ./game/server/npc/npc_headcrab.cpp*

========================================================= LeapTouch - this is the headcrab's touch function when it is in the air=========================================================

### Center

*public Vector Center()*

*Defined at line 171 of ./game/server/npc/npc_headcrab.cpp*

========================================================= Center - returns the real center of the headcrab.  The  bounding box is much larger than the actual creature so  this is needed for targeting=========================================================

### BodyTarget

*public Vector BodyTarget(const class Vector & posSrc)*

*Defined at line 176 of ./game/server/npc/npc_headcrab.cpp*

### PainSound

*public void PainSound()*

*Defined at line 457 of ./game/server/npc/npc_headcrab.cpp*

========================================================= AlertSound =========================================================

### DeathSound

*public void DeathSound()*

*Defined at line 465 of ./game/server/npc/npc_headcrab.cpp*

========================================================= DeathSound =========================================================

### IdleSound

*public void IdleSound()*

*Defined at line 441 of ./game/server/npc/npc_headcrab.cpp*

========================================================= IdleSound=========================================================

### AlertSound

*public void AlertSound()*

*Defined at line 449 of ./game/server/npc/npc_headcrab.cpp*

========================================================= AlertSound =========================================================

### PrescheduleThink

*public void PrescheduleThink()*

*Defined at line 370 of ./game/server/npc/npc_headcrab.cpp*

========================================================= PrescheduleThink=========================================================

### Classify

*public int Classify()*

*Defined at line 161 of ./game/server/npc/npc_headcrab.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 217 of ./game/server/npc/npc_headcrab.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.=========================================================

### CheckRangeAttack1

*public BOOL CheckRangeAttack1(float flDot, float flDist)*

*Defined at line 402 of ./game/server/npc/npc_headcrab.cpp*

========================================================= CheckRangeAttack1=========================================================

### CheckRangeAttack2

*public BOOL CheckRangeAttack2(float flDot, float flDist)*

*Defined at line 414 of ./game/server/npc/npc_headcrab.cpp*

========================================================= CheckRangeAttack2=========================================================

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 427 of ./game/server/npc/npc_headcrab.cpp*

### GetDamageAmount

*public float GetDamageAmount()*

*Defined at line 95 of ./game/server/npc/npc_headcrab.cpp*

### GetVoicePitch

*public int GetVoicePitch()*

*Defined at line 96 of ./game/server/npc/npc_headcrab.cpp*

### GetSoundVolue

*public float GetSoundVolue()*

*Defined at line 97 of ./game/server/npc/npc_headcrab.cpp*

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int Type)*

*Defined at line 470 of ./game/server/npc/npc_headcrab.cpp*

### ScheduleFromName

*public struct Schedule_t * ScheduleFromName(const char * pName)*

*Defined at line 118 of ./game/server/npc/npc_headcrab.cpp*



