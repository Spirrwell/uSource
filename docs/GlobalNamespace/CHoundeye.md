# class CHoundeye

*Defined at line 76 of ./game/server/npc/npc_houndeye.cpp*

Inherits from CSquadMonster



## Members

public int m_iSpriteTexture

public BOOL m_fAsleep

public BOOL m_fDontBlink

Vector m_vecPackCenter



## Functions

### Spawn

*public void Spawn()*

*Defined at line 317 of ./game/server/npc/npc_houndeye.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 342 of ./game/server/npc/npc_houndeye.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### Classify

*public int Classify()*

*Defined at line 130 of ./game/server/npc/npc_houndeye.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 271 of ./game/server/npc/npc_houndeye.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.=========================================================

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 206 of ./game/server/npc/npc_houndeye.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### WarmUpSound

*public void WarmUpSound()*

*Defined at line 399 of ./game/server/npc/npc_houndeye.cpp*

========================================================= IdleSound=========================================================

### AlertSound

*public void AlertSound()*

*Defined at line 434 of ./game/server/npc/npc_houndeye.cpp*

========================================================= AlertSound =========================================================

### DeathSound

*public void DeathSound()*

*Defined at line 458 of ./game/server/npc/npc_houndeye.cpp*

========================================================= DeathSound =========================================================

### WarnSound

*public void WarnSound()*

*Defined at line 415 of ./game/server/npc/npc_houndeye.cpp*

========================================================= WarnSound =========================================================

### PainSound

*public void PainSound()*

*Defined at line 477 of ./game/server/npc/npc_houndeye.cpp*

========================================================= PainSound =========================================================

### IdleSound

*public void IdleSound()*

*Defined at line 380 of ./game/server/npc/npc_houndeye.cpp*

========================================================= IdleSound=========================================================

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 664 of ./game/server/npc/npc_houndeye.cpp*

========================================================= start task=========================================================

### RunTask

*public void RunTask(struct Task_t * pTask)*

*Defined at line 765 of ./game/server/npc/npc_houndeye.cpp*

========================================================= RunTask =========================================================

### SonicAttack

*public void SonicAttack()*

*Defined at line 545 of ./game/server/npc/npc_houndeye.cpp*

========================================================= SonicAttack=========================================================

### PrescheduleThink

*public void PrescheduleThink()*

*Defined at line 836 of ./game/server/npc/npc_houndeye.cpp*

========================================================= PrescheduleThink=========================================================

### SetActivity

*public void SetActivity(Activity NewActivity)*

*Defined at line 235 of ./game/server/npc/npc_houndeye.cpp*

========================================================= SetActivity =========================================================

### WriteBeamColor

*public void WriteBeamColor()*

*Defined at line 497 of ./game/server/npc/npc_houndeye.cpp*

========================================================= WriteBeamColor - writes a color vector to the network  based on the size of the group. =========================================================

### CheckRangeAttack1

*public BOOL CheckRangeAttack1(float flDot, float flDist)*

*Defined at line 193 of ./game/server/npc/npc_houndeye.cpp*

========================================================= CheckRangeAttack1 - overridden for houndeyes so that they try to get within half of their max attack radius before attacking, so as to increase their chances of doing damage.=========================================================

### FValidateHintType

*public BOOL FValidateHintType(short sHint)*

*Defined at line 138 of ./game/server/npc/npc_houndeye.cpp*

=========================================================  FValidateHintType =========================================================

### FCanActiveIdle

*public BOOL FCanActiveIdle()*

*Defined at line 165 of ./game/server/npc/npc_houndeye.cpp*

========================================================= FCanActiveIdle=========================================================

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int Type)*

*Defined at line 1141 of ./game/server/npc/npc_houndeye.cpp*

========================================================= GetScheduleOfType =========================================================

### GetSchedule

*public struct Schedule_t * GetSchedule()*

*Defined at line 1248 of ./game/server/npc/npc_houndeye.cpp*

========================================================= GetSchedule =========================================================

### Save

*public int Save(class CSave & save)*

*Defined at line 124 of ./game/server/npc/npc_houndeye.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 124 of ./game/server/npc/npc_houndeye.cpp*

### ScheduleFromName

*public struct Schedule_t * ScheduleFromName(const char * pName)*

*Defined at line 1136 of ./game/server/npc/npc_houndeye.cpp*



