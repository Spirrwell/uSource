# class CScientist

*Defined at line 71 of ./game/server/npc/npc_scientist.cpp*

======================================================= Scientist=======================================================



Inherits from CTalkMonster



## Members

private float m_painTime

private float m_healTime

private float m_fearTime



## Functions

### Spawn

*public void Spawn()*

*Defined at line 638 of ./game/server/npc/npc_scientist.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 677 of ./game/server/npc/npc_scientist.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 579 of ./game/server/npc/npc_scientist.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### Classify

*public int Classify()*

*Defined at line 570 of ./game/server/npc/npc_scientist.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 611 of ./game/server/npc/npc_scientist.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.=========================================================

### RunTask

*public void RunTask(struct Task_t * pTask)*

*Defined at line 501 of ./game/server/npc/npc_scientist.cpp*

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 442 of ./game/server/npc/npc_scientist.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 82 of ./game/server/npc/npc_scientist.cpp*

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 741 of ./game/server/npc/npc_scientist.cpp*

### FriendNumber

*public int FriendNumber(int arrayNumber)*

*Defined at line 1070 of ./game/server/npc/npc_scientist.cpp*

### SetActivity

*public void SetActivity(Activity newActivity)*

*Defined at line 810 of ./game/server/npc/npc_scientist.cpp*

### GetStoppedActivity

*public Activity GetStoppedActivity()*

*Defined at line 435 of ./game/server/npc/npc_scientist.cpp*

### ISoundMask

*public int ISoundMask()*

*Defined at line 758 of ./game/server/npc/npc_scientist.cpp*

========================================================= ISoundMask - returns a bit mask indicating which types of sounds this monster regards. In the base class implementation, monsters care about all sounds, but no scents.=========================================================

### DeclineFollowing

*public void DeclineFollowing()*

*Defined at line 418 of ./game/server/npc/npc_scientist.cpp*

### CoverRadius

*public float CoverRadius()*

*Defined at line 90 of ./game/server/npc/npc_scientist.cpp*

### DisregardEnemy

*public BOOL DisregardEnemy(class CBaseEntity * pEnemy)*

*Defined at line 91 of ./game/server/npc/npc_scientist.cpp*

### CanHeal

*public BOOL CanHeal()*

*Defined at line 1048 of ./game/server/npc/npc_scientist.cpp*

### Heal

*public void Heal()*

*Defined at line 1056 of ./game/server/npc/npc_scientist.cpp*

### Scream

*public void Scream()*

*Defined at line 425 of ./game/server/npc/npc_scientist.cpp*

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int Type)*

*Defined at line 822 of ./game/server/npc/npc_scientist.cpp*

 Override these to set behavior

### GetSchedule

*public struct Schedule_t * GetSchedule()*

*Defined at line 868 of ./game/server/npc/npc_scientist.cpp*

### GetIdealState

*public MONSTERSTATE GetIdealState()*

*Defined at line 985 of ./game/server/npc/npc_scientist.cpp*

### DeathSound

*public void DeathSound()*

*Defined at line 799 of ./game/server/npc/npc_scientist.cpp*

========================================================= DeathSound =========================================================

### PainSound

*public void PainSound()*

*Defined at line 769 of ./game/server/npc/npc_scientist.cpp*

========================================================= PainSound=========================================================

### TalkInit

*public void TalkInit()*

*Defined at line 694 of ./game/server/npc/npc_scientist.cpp*

 Init talk data

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 804 of ./game/server/npc/npc_scientist.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 130 of ./game/server/npc/npc_scientist.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 130 of ./game/server/npc/npc_scientist.cpp*

### ScheduleFromName

*public struct Schedule_t * ScheduleFromName(const char * pName)*

*Defined at line 416 of ./game/server/npc/npc_scientist.cpp*



