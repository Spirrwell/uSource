# class CFlockingFlyer

*Defined at line 63 of ./game/server/npc/npc_aflock.cpp*

==================================================================================================================



Inherits from CBaseMonster



## Members

public class CFlockingFlyer * m_pSquadLeader

public class CFlockingFlyer * m_pSquadNext

public BOOL m_fTurning

public BOOL m_fCourseAdjust

public BOOL m_fPathBlocked

Vector m_vecReferencePoint

Vector m_vecAdjustedVelocity

public float m_flGoalSpeed

public float m_flLastBlockedTime

public float m_flFakeBlockedTime

public float m_flAlertTime

public float m_flFlockNextSoundTime



## Functions

### Spawn

*public void Spawn()*

*Defined at line 226 of ./game/server/npc/npc_aflock.cpp*

==================================================================================================================

### Precache

*public void Precache()*

*Defined at line 238 of ./game/server/npc/npc_aflock.cpp*

==================================================================================================================

### SpawnCommonCode

*public void SpawnCommonCode()*

*Defined at line 327 of ./game/server/npc/npc_aflock.cpp*

==================================================================================================================

### IdleThink

*public void IdleThink()*

*Defined at line 374 of ./game/server/npc/npc_aflock.cpp*

==================================================================================================================

### BoidAdvanceFrame

*public void BoidAdvanceFrame()*

*Defined at line 348 of ./game/server/npc/npc_aflock.cpp*

==================================================================================================================

### FormFlock

*public void FormFlock()*

*Defined at line 424 of ./game/server/npc/npc_aflock.cpp*

========================================================= Leader boid calls this to form a flock from surrounding boids=========================================================

### Start

*public void Start()*

*Defined at line 389 of ./game/server/npc/npc_aflock.cpp*

========================================================= Start - player enters the pvs, so get things going.=========================================================

### FlockLeaderThink

*public void FlockLeaderThink()*

*Defined at line 565 of ./game/server/npc/npc_aflock.cpp*

========================================================= Leader boids use this think every tenth=========================================================

### FlockFollowerThink

*public void FlockFollowerThink()*

*Defined at line 670 of ./game/server/npc/npc_aflock.cpp*

========================================================= follower boids execute this code when flocking=========================================================

### FallHack

*public void FallHack()*

*Defined at line 308 of ./game/server/npc/npc_aflock.cpp*

### MakeSound

*public void MakeSound()*

*Defined at line 247 of ./game/server/npc/npc_aflock.cpp*

==================================================================================================================

### AlertFlock

*public void AlertFlock()*

### SpreadFlock

*public void SpreadFlock()*

*Defined at line 458 of ./game/server/npc/npc_aflock.cpp*

========================================================= Searches for boids that are too close and pushes them away=========================================================

### SpreadFlock2

*public void SpreadFlock2()*

*Defined at line 489 of ./game/server/npc/npc_aflock.cpp*

========================================================= Alters the caller's course if he's too close to others 

 This function should **ONLY** be called when Caller's velocity is normalized!!=========================================================

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 279 of ./game/server/npc/npc_aflock.cpp*

==================================================================================================================

### Poop

*public void Poop()*

### FPathBlocked

*public BOOL FPathBlocked()*

*Defined at line 511 of ./game/server/npc/npc_aflock.cpp*

========================================================= FBoidPathBlocked - returns TRUE if there is an obstacle ahead=========================================================

### Save

*public int Save(class CSave & save)*

*Defined at line 130 of ./game/server/npc/npc_aflock.cpp*

void KeyValue( KeyValueData *pkvd );

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 130 of ./game/server/npc/npc_aflock.cpp*

### IsLeader

*public int IsLeader()*

*Defined at line 89 of ./game/server/npc/npc_aflock.cpp*

### InSquad

*public int InSquad()*

*Defined at line 90 of ./game/server/npc/npc_aflock.cpp*

### SquadCount

*public int SquadCount()*

*Defined at line 889 of ./game/server/npc/npc_aflock.cpp*

=========================================================

 SquadCount(), return the number of members of this squad callable from leaders & followers

=========================================================

### SquadRemove

*public void SquadRemove(class CFlockingFlyer * pRemove)*

*Defined at line 829 of ./game/server/npc/npc_aflock.cpp*

=========================================================

 SquadRemove(), remove pRemove from my squad. If I am pRemove, promote m_pSquadNext to leader

=========================================================

### SquadUnlink

*public void SquadUnlink()*

*Defined at line 801 of ./game/server/npc/npc_aflock.cpp*

=========================================================

 SquadUnlink(), Unlink the squad pointers.

=========================================================

### SquadAdd

*public void SquadAdd(class CFlockingFlyer * pAdd)*

*Defined at line 812 of ./game/server/npc/npc_aflock.cpp*

=========================================================

 SquadAdd(), add pAdd to my squad

=========================================================

### SquadDisband

*public void SquadDisband()*

*Defined at line 907 of ./game/server/npc/npc_aflock.cpp*

=========================================================

 SquadDisband(), Unlink all squad members

=========================================================



