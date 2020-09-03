# class CRoach

*Defined at line 37 of ./game/server/npc/npc_roach.cpp*

========================================================= Monster's Anim Events Go Here=========================================================



Inherits from CBaseMonster



## Members

public float m_flLastLightLevel

public float m_flNextSmellTime

public BOOL m_fLightHacked

public int m_iMode



## Functions

### Spawn

*public void Spawn()*

*Defined at line 120 of ./game/server/npc/npc_roach.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 149 of ./game/server/npc/npc_roach.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 108 of ./game/server/npc/npc_roach.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### MonsterThink

*public void MonsterThink()*

*Defined at line 188 of ./game/server/npc/npc_roach.cpp*

========================================================= MonsterThink, overridden for roaches.=========================================================

### Move

*public void Move(float flInterval)*

*Defined at line 350 of ./game/server/npc/npc_roach.cpp*

========================================================= roach's move function=========================================================

### PickNewDest

*public void PickNewDest(int iCondition)*

*Defined at line 296 of ./game/server/npc/npc_roach.cpp*

========================================================= Picks a new spot for roach to run to.(=========================================================

### Touch

*public void Touch(class CBaseEntity * pOther)*

*Defined at line 85 of ./game/server/npc/npc_roach.cpp*

========================================================= Touch=========================================================

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 161 of ./game/server/npc/npc_roach.cpp*

========================================================= Killed.=========================================================

### Classify

*public int Classify()*

*Defined at line 77 of ./game/server/npc/npc_roach.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### Look

*public void Look(int iDistance)*

*Defined at line 403 of ./game/server/npc/npc_roach.cpp*

========================================================= Look - overriden for the roach, which can virtually see  360 degrees.=========================================================

### ISoundMask

*public int ISoundMask()*

*Defined at line 68 of ./game/server/npc/npc_roach.cpp*

========================================================= ISoundMask - returns a bit mask indicating which types of sounds this monster regards. In the base class implementation, monsters care about all sounds, but no scents.=========================================================



