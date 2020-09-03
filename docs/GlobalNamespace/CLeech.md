# class CLeech

*Defined at line 64 of ./game/server/npc/npc_leech.cpp*

Inherits from CBaseMonster



## Members

private float m_flTurning

private BOOL m_fPathBlocked

private float m_flAccelerate

private float m_obstacle

private float m_top

private float m_bottom

private float m_height

private float m_waterTime

private float m_sideTime

private float m_zTime

private float m_stateTime

private float m_attackSoundTime



## Functions

### Spawn

*public void Spawn()*

*Defined at line 169 of ./game/server/npc/npc_leech.cpp*

### Precache

*public void Precache()*

*Defined at line 272 of ./game/server/npc/npc_leech.cpp*

### SwimThink

*public void SwimThink()*

*Defined at line 524 of ./game/server/npc/npc_leech.cpp*

### DeadThink

*public void DeadThink()*

*Defined at line 394 of ./game/server/npc/npc_leech.cpp*

### Touch

*public void Touch(class CBaseEntity * pOther)*

*Defined at line 72 of ./game/server/npc/npc_leech.cpp*

### SetObjectCollisionBox

*public void SetObjectCollisionBox()*

*Defined at line 85 of ./game/server/npc/npc_leech.cpp*

### AttackSound

*public void AttackSound()*

*Defined at line 258 of ./game/server/npc/npc_leech.cpp*

### AlertSound

*public void AlertSound()*

*Defined at line 267 of ./game/server/npc/npc_leech.cpp*

### UpdateMotion

*public void UpdateMotion()*

*Defined at line 428 of ./game/server/npc/npc_leech.cpp*

### ObstacleDistance

*public float ObstacleDistance(class CBaseEntity * pTarget)*

*Defined at line 342 of ./game/server/npc/npc_leech.cpp*

 ObstacleDistance - returns normalized distance to obstacle

### MakeVectors

*public void MakeVectors()*

*Defined at line 332 of ./game/server/npc/npc_leech.cpp*

### RecalculateWaterlevel

*public void RecalculateWaterlevel()*

*Defined at line 204 of ./game/server/npc/npc_leech.cpp*

### SwitchLeechState

*public void SwitchLeechState()*

*Defined at line 227 of ./game/server/npc/npc_leech.cpp*

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 298 of ./game/server/npc/npc_leech.cpp*

 Base entity functions

### BloodColor

*public int BloodColor()*

*Defined at line 101 of ./game/server/npc/npc_leech.cpp*

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 654 of ./game/server/npc/npc_leech.cpp*

### Activate

*public void Activate()*

*Defined at line 199 of ./game/server/npc/npc_leech.cpp*

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 285 of ./game/server/npc/npc_leech.cpp*

### Classify

*public int Classify()*

*Defined at line 105 of ./game/server/npc/npc_leech.cpp*

### IRelationship

*public int IRelationship(class CBaseEntity * pTarget)*

*Defined at line 251 of ./game/server/npc/npc_leech.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 154 of ./game/server/npc/npc_leech.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 154 of ./game/server/npc/npc_leech.cpp*



