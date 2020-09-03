# class CGib

*Defined at line 140 of ./game/server/ai/ai_monsters.h*

 A gib is a chunk of a body, or a piece of wood/metal/rocks/etc.



Inherits from CBaseEntity



## Members

public int m_bloodColor

public int m_cBloodDecals

public int m_material

public float m_lifeTime



## Functions

### Spawn

*public void Spawn(const char * szGibModel)*

*Defined at line 768 of ./game/server/combat.cpp*

 Throw a chunk

### BounceGibTouch

*public void BounceGibTouch(class CBaseEntity * pOther)*

*Defined at line 697 of ./game/server/combat.cpp*

 Gib bounces on the ground or wall, sponges some blood down, too!

### StickyGibTouch

*public void StickyGibTouch(class CBaseEntity * pOther)*

*Defined at line 740 of ./game/server/combat.cpp*

 Sticky gib puts blood on the wall and stays put. 

### WaitTillLand

*public void WaitTillLand()*

*Defined at line 667 of ./game/server/combat.cpp*

========================================================= WaitTillLand - in order to emit their meaty scent from the proper location, gibs should wait until they stop  bouncing to emit their scent. That's what this function does.=========================================================

### LimitVelocity

*public void LimitVelocity()*

*Defined at line 45 of ./game/server/combat.cpp*

 HACKHACK -- The gib velocity equations don't work

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 149 of ./game/server/ai/ai_monsters.h*

### SpawnHeadGib

*public void SpawnHeadGib(entvars_t * pevVictim)*

*Defined at line 124 of ./game/server/combat.cpp*

### SpawnRandomGibs

*public void SpawnRandomGibs(entvars_t * pevVictim, int cGibs, int human)*

*Defined at line 181 of ./game/server/combat.cpp*

### SpawnStickyGibs

*public void SpawnStickyGibs(entvars_t * pevVictim, Vector vecOrigin, int cGibs)*

*Defined at line 56 of ./game/server/combat.cpp*



