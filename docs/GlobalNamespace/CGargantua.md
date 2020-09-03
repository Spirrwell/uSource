# class CGargantua

*Defined at line 198 of ./game/server/npc/npc_gargantua.cpp*

Inherits from CBaseMonster



## Members

private class CSprite * m_pEyeGlow

private class CBeam *[4] m_pFlame

private int m_eyeBrightness

private float m_seeTime

private float m_flameTime

private float m_painSoundTime

private float m_streakTime

private float m_flameX

private float m_flameY



## Functions

### Spawn

*public void Spawn()*

*Defined at line 732 of ./game/server/npc/npc_gargantua.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 760 of ./game/server/npc/npc_gargantua.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### UpdateOnRemove

*public void UpdateOnRemove()*

*Defined at line 806 of ./game/server/npc/npc_gargantua.cpp*

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 704 of ./game/server/npc/npc_gargantua.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### Classify

*public int Classify()*

*Defined at line 695 of ./game/server/npc/npc_gargantua.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 856 of ./game/server/npc/npc_gargantua.cpp*

### TraceAttack

*public void TraceAttack(entvars_t * pevAttacker, float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 819 of ./game/server/npc/npc_gargantua.cpp*

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 961 of ./game/server/npc/npc_gargantua.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.=========================================================

### CheckMeleeAttack1

*public BOOL CheckMeleeAttack1(float flDot, float flDist)*

*Defined at line 908 of ./game/server/npc/npc_gargantua.cpp*

========================================================= CheckMeleeAttack1 Garg swipe attack

=========================================================

### CheckMeleeAttack2

*public BOOL CheckMeleeAttack2(float flDot, float flDist)*

*Defined at line 921 of ./game/server/npc/npc_gargantua.cpp*

 Flame thrower madness!

### CheckRangeAttack1

*public BOOL CheckRangeAttack1(float flDot, float flDist)*

*Defined at line 945 of ./game/server/npc/npc_gargantua.cpp*

========================================================= CheckRangeAttack1 flDot is the cos of the angle of the cone within which the attack can occur.=========================================================

 Stomp attack

=========================================================

### SetObjectCollisionBox

*public void SetObjectCollisionBox()*

*Defined at line 213 of ./game/server/npc/npc_gargantua.cpp*

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int Type)*

*Defined at line 1043 of ./game/server/npc/npc_gargantua.cpp*

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 1061 of ./game/server/npc/npc_gargantua.cpp*

### RunTask

*public void RunTask(struct Task_t * pTask)*

*Defined at line 1090 of ./game/server/npc/npc_gargantua.cpp*

========================================================= RunTask=========================================================

### PrescheduleThink

*public void PrescheduleThink()*

*Defined at line 678 of ./game/server/npc/npc_gargantua.cpp*

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 895 of ./game/server/npc/npc_gargantua.cpp*

### DeathEffect

*public void DeathEffect()*

*Defined at line 871 of ./game/server/npc/npc_gargantua.cpp*

### EyeOff

*public void EyeOff()*

*Defined at line 444 of ./game/server/npc/npc_gargantua.cpp*

### EyeOn

*public void EyeOn(int level)*

*Defined at line 439 of ./game/server/npc/npc_gargantua.cpp*

### EyeUpdate

*public void EyeUpdate()*

*Defined at line 449 of ./game/server/npc/npc_gargantua.cpp*

### Leap

*public void Leap()*

### StompAttack

*public void StompAttack()*

*Defined at line 462 of ./game/server/npc/npc_gargantua.cpp*

### FlameCreate

*public void FlameCreate()*

*Defined at line 481 of ./game/server/npc/npc_gargantua.cpp*

### FlameUpdate

*public void FlameUpdate()*

*Defined at line 539 of ./game/server/npc/npc_gargantua.cpp*

### FlameControls

*public void FlameControls(float angleX, float angleY)*

*Defined at line 521 of ./game/server/npc/npc_gargantua.cpp*

### FlameDestroy

*public void FlameDestroy()*

*Defined at line 663 of ./game/server/npc/npc_gargantua.cpp*

### FlameIsOn

*public BOOL FlameIsOn()*

*Defined at line 237 of ./game/server/npc/npc_gargantua.cpp*

### FlameDamage

*public void FlameDamage(Vector vecStart, Vector vecEnd, entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType)*

*Defined at line 593 of ./game/server/npc/npc_gargantua.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 289 of ./game/server/npc/npc_gargantua.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 289 of ./game/server/npc/npc_gargantua.cpp*

### ScheduleFromName

*public struct Schedule_t * ScheduleFromName(const char * pName)*

*Defined at line 437 of ./game/server/npc/npc_gargantua.cpp*

### GargantuaCheckTraceHullAttack

*private class CBaseEntity * GargantuaCheckTraceHullAttack(float flDist, int iDamage, int iDmgType)*

*Defined at line 1017 of ./game/server/npc/npc_gargantua.cpp*

 Overridden for Gargantua because his swing starts lower as a percentage of his height (otherwise he swings over the players head)=========================================================



