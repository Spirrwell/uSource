# class CCycler

*Defined at line 34 of ./game/server/npc/npc_h_cycler.cpp*

Inherits from CBaseMonster



## Members

public int m_animate



## Functions

### GenericCyclerSpawn

*public void GenericCyclerSpawn(const char * szModel, Vector vecMin, Vector vecMax)*

*Defined at line 95 of ./game/server/npc/npc_h_cycler.cpp*

 Cycler member functions

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 38 of ./game/server/npc/npc_h_cycler.cpp*

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 184 of ./game/server/npc/npc_h_cycler.cpp*

 CyclerPain , changes sequences when shot

void CCycler::Pain( float flDamage )

### Spawn

*public void Spawn()*

*Defined at line 113 of ./game/server/npc/npc_h_cycler.cpp*

### Think

*public void Think()*

*Defined at line 146 of ./game/server/npc/npc_h_cycler.cpp*

 cycler think

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 171 of ./game/server/npc/npc_h_cycler.cpp*

 CyclerUse - starts a rotation trend

void Pain( float flDamage );

### IsAlive

*public _Bool IsAlive()*

*Defined at line 46 of ./game/server/npc/npc_h_cycler.cpp*

 Don't treat as a live target

### Save

*public int Save(class CSave & save)*

*Defined at line 60 of ./game/server/npc/npc_h_cycler.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 60 of ./game/server/npc/npc_h_cycler.cpp*



