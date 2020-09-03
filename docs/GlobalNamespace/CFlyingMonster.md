# class CFlyingMonster

*Defined at line 20 of ./game/server/ai/ai_flyingmonster.h*

Inherits from CBaseMonster



## Members

Vector m_vecTravel

protected float m_flightSpeed

protected float m_stopTime

protected float m_momentum

protected const char * m_pFlapSound



## Functions

### CheckLocalMove

*public int CheckLocalMove(const class Vector & vecStart, const class Vector & vecEnd, class CBaseEntity * pTarget, float * pflDist)*

*Defined at line 28 of ./game/server/ai/ai_flyingmonster.cpp*

### FTriangulate

*public BOOL FTriangulate(const class Vector & vecStart, const class Vector & vecEnd, float flDist, class CBaseEntity * pTargetEnt, class Vector * pApex)*

*Defined at line 60 of ./game/server/ai/ai_flyingmonster.cpp*

### GetStoppedActivity

*public Activity GetStoppedActivity()*

*Defined at line 65 of ./game/server/ai/ai_flyingmonster.cpp*

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 105 of ./game/server/ai/ai_flyingmonster.cpp*

### Stop

*public void Stop()*

*Defined at line 73 of ./game/server/ai/ai_flyingmonster.cpp*

### ChangeYaw

*public float ChangeYaw(int speed)*

*Defined at line 86 of ./game/server/ai/ai_flyingmonster.cpp*

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 114 of ./game/server/ai/ai_flyingmonster.cpp*

### MoveExecute

*public void MoveExecute(class CBaseEntity * pTargetEnt, const class Vector & vecDir, float flInterval)*

*Defined at line 150 of ./game/server/ai/ai_flyingmonster.cpp*

### Move

*public void Move(float flInterval)*

*Defined at line 131 of ./game/server/ai/ai_flyingmonster.cpp*

### ShouldAdvanceRoute

*public BOOL ShouldAdvanceRoute(float flWaypointDist)*

*Defined at line 138 of ./game/server/ai/ai_flyingmonster.cpp*

### SetFlyingMomentum

*public void SetFlyingMomentum(float momentum)*

*Defined at line 34 of ./game/server/ai/ai_flyingmonster.h*

### SetFlyingFlapSound

*public void SetFlyingFlapSound(const char * pFlapSound)*

*Defined at line 35 of ./game/server/ai/ai_flyingmonster.h*

### SetFlyingSpeed

*public void SetFlyingSpeed(float speed)*

*Defined at line 36 of ./game/server/ai/ai_flyingmonster.h*

### CeilingZ

*public float CeilingZ(const class Vector & position)*

*Defined at line 190 of ./game/server/ai/ai_flyingmonster.cpp*

### FloorZ

*public float FloorZ(const class Vector & position)*

*Defined at line 255 of ./game/server/ai/ai_flyingmonster.cpp*

### ProbeZ

*public BOOL ProbeZ(const class Vector & position, const class Vector & probe, float * pFraction)*

*Defined at line 209 of ./game/server/ai/ai_flyingmonster.cpp*



