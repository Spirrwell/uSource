# class CBarnacle

*Defined at line 34 of ./game/server/npc/npc_barnacle.cpp*

Inherits from CBaseMonster



## Members

public float m_flAltitude

public float m_flCachedLength

public float m_flKillVictimTime

public int m_cGibs

public BOOL m_fTongueExtended

public BOOL m_fLiftingPrey

public float m_flTongueAdj



## Functions

### Spawn

*public void Spawn()*

*Defined at line 115 of ./game/server/npc/npc_barnacle.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 406 of ./game/server/npc/npc_barnacle.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### TongueTouchEnt

*public class CBaseEntity * TongueTouchEnt(float * pflLength)*

*Defined at line 425 of ./game/server/npc/npc_barnacle.cpp*

### Classify

*public int Classify()*

*Defined at line 88 of ./game/server/npc/npc_barnacle.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 99 of ./game/server/npc/npc_barnacle.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.

 Returns number of events handled, 0 if none.=========================================================

### BarnacleThink

*public void BarnacleThink()*

*Defined at line 158 of ./game/server/npc/npc_barnacle.cpp*

==================================================================================================================

### WaitTillDead

*public void WaitTillDead()*

*Defined at line 388 of ./game/server/npc/npc_barnacle.cpp*

==================================================================================================================

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 348 of ./game/server/npc/npc_barnacle.cpp*

========================================================= Killed.=========================================================

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 146 of ./game/server/npc/npc_barnacle.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 82 of ./game/server/npc/npc_barnacle.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 82 of ./game/server/npc/npc_barnacle.cpp*



