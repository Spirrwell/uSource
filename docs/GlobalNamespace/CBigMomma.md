# class CBigMomma

*Defined at line 170 of ./game/server/npc/npc_bigmomma.cpp*

Inherits from CBaseMonster



## Members

private float m_nodeTime

private float m_crabTime

private float m_mortarTime

private float m_painSoundTime

private int m_crabCount



## Functions

### Spawn

*public void Spawn()*

*Defined at line 631 of ./game/server/npc/npc_bigmomma.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 652 of ./game/server/npc/npc_bigmomma.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 384 of ./game/server/npc/npc_bigmomma.cpp*

### Activate

*public void Activate()*

*Defined at line 678 of ./game/server/npc/npc_bigmomma.cpp*

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 559 of ./game/server/npc/npc_bigmomma.cpp*

### RunTask

*public void RunTask(struct Task_t * pTask)*

*Defined at line 980 of ./game/server/npc/npc_bigmomma.cpp*

========================================================= RunTask=========================================================

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 876 of ./game/server/npc/npc_bigmomma.cpp*

### GetSchedule

*public struct Schedule_t * GetSchedule()*

*Defined at line 866 of ./game/server/npc/npc_bigmomma.cpp*

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int Type)*

*Defined at line 841 of ./game/server/npc/npc_bigmomma.cpp*

### TraceAttack

*public void TraceAttack(entvars_t * pevAttacker, float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 537 of ./game/server/npc/npc_bigmomma.cpp*

### NodeStart

*public void NodeStart(int iszNextNode)*

*Defined at line 684 of ./game/server/npc/npc_bigmomma.cpp*

### NodeReach

*public void NodeReach()*

*Defined at line 708 of ./game/server/npc/npc_bigmomma.cpp*

### ShouldGoToNode

*public BOOL ShouldGoToNode()*

*Defined at line 856 of ./game/server/npc/npc_bigmomma.cpp*

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 410 of ./game/server/npc/npc_bigmomma.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### Classify

*public int Classify()*

*Defined at line 401 of ./game/server/npc/npc_bigmomma.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 431 of ./game/server/npc/npc_bigmomma.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.

 Returns number of events handled, 0 if none.=========================================================

### LayHeadcrab

*public void LayHeadcrab()*

*Defined at line 578 of ./game/server/npc/npc_bigmomma.cpp*

### GetNodeSequence

*public int GetNodeSequence()*

*Defined at line 194 of ./game/server/npc/npc_bigmomma.cpp*

### GetNodePresequence

*public int GetNodePresequence()*

*Defined at line 204 of ./game/server/npc/npc_bigmomma.cpp*

### GetNodeDelay

*public float GetNodeDelay()*

*Defined at line 214 of ./game/server/npc/npc_bigmomma.cpp*

### GetNodeRange

*public float GetNodeRange()*

*Defined at line 224 of ./game/server/npc/npc_bigmomma.cpp*

### GetNodeYaw

*public float GetNodeYaw()*

*Defined at line 234 of ./game/server/npc/npc_bigmomma.cpp*

### OverrideReset

*public void OverrideReset()*

*Defined at line 246 of ./game/server/npc/npc_bigmomma.cpp*

 Restart the crab count on each new level

### DeathNotice

*public void DeathNotice(entvars_t * pevChild)*

*Defined at line 604 of ./game/server/npc/npc_bigmomma.cpp*

### CanLayCrab

*public BOOL CanLayCrab()*

*Defined at line 253 of ./game/server/npc/npc_bigmomma.cpp*

### LaunchMortar

*public void LaunchMortar()*

*Defined at line 615 of ./game/server/npc/npc_bigmomma.cpp*

### SetObjectCollisionBox

*public void SetObjectCollisionBox()*

*Defined at line 276 of ./game/server/npc/npc_bigmomma.cpp*

### CheckMeleeAttack1

*public BOOL CheckMeleeAttack1(float flDot, float flDist)*

*Defined at line 733 of ./game/server/npc/npc_bigmomma.cpp*

 Slash

### CheckMeleeAttack2

*public BOOL CheckMeleeAttack2(float flDot, float flDist)*

*Defined at line 744 of ./game/server/npc/npc_bigmomma.cpp*

 Lay a crab

### CheckRangeAttack1

*public BOOL CheckRangeAttack1(float flDot, float flDist)*

*Defined at line 750 of ./game/server/npc/npc_bigmomma.cpp*

 Mortar launch

### Save

*public int Save(class CSave & save)*

*Defined at line 321 of ./game/server/npc/npc_bigmomma.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 321 of ./game/server/npc/npc_bigmomma.cpp*

### ScheduleFromName

*public struct Schedule_t * ScheduleFromName(const char * pName)*

*Defined at line 839 of ./game/server/npc/npc_bigmomma.cpp*



