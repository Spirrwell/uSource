# class CHornet

*Defined at line 35 of ./game/server/npc/npc_hornet.h*

========================================================= Hornet - this is the projectile that the Alien Grunt fires.=========================================================



Inherits from CBaseMonster



## Members

public float m_flStopAttack

public int m_iHornetType

public float m_flFlySpeed



## Functions

### Spawn

*public void Spawn()*

*Defined at line 59 of ./game/server/npc/npc_hornet.cpp*

==================================================================================================================

### Precache

*public void Precache()*

*Defined at line 116 of ./game/server/npc/npc_hornet.cpp*

### Classify

*public int Classify()*

*Defined at line 152 of ./game/server/npc/npc_hornet.cpp*

========================================================= ID's Hornet as their owner=========================================================

### IRelationship

*public int IRelationship(class CBaseEntity * pTarget)*

*Defined at line 139 of ./game/server/npc/npc_hornet.cpp*

========================================================= hornets will never get mad at each other, no matter who the owner is.=========================================================

### Save

*public int Save(class CSave & save)*

*Defined at line 43 of ./game/server/npc/npc_hornet.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 43 of ./game/server/npc/npc_hornet.cpp*

### IgniteTrail

*public void IgniteTrail()*

*Defined at line 188 of ./game/server/npc/npc_hornet.cpp*

### StartTrack

*public void StartTrack()*

*Defined at line 165 of ./game/server/npc/npc_hornet.cpp*

========================================================= StartTrack - starts a hornet out tracking its target=========================================================

### StartDart

*public void StartDart()*

*Defined at line 178 of ./game/server/npc/npc_hornet.cpp*

========================================================= StartDart - starts a hornet out just flying straight.=========================================================

### TrackTarget

*public void TrackTarget()*

*Defined at line 244 of ./game/server/npc/npc_hornet.cpp*

========================================================= Hornet is flying, gently tracking target=========================================================

### TrackTouch

*public void TrackTouch(class CBaseEntity * pOther)*

*Defined at line 376 of ./game/server/npc/npc_hornet.cpp*

========================================================= Tracking Hornet hit something=========================================================

### DartTouch

*public void DartTouch(class CBaseEntity * pOther)*

*Defined at line 403 of ./game/server/npc/npc_hornet.cpp*

### DieTouch

*public void DieTouch(class CBaseEntity * pOther)*

*Defined at line 408 of ./game/server/npc/npc_hornet.cpp*

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 48 of ./game/server/npc/npc_hornet.cpp*

========================================================= don't let hornets gib, ever.=========================================================



