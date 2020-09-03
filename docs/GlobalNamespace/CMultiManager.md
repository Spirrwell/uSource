# class CMultiManager

*Defined at line 250 of ./game/server/triggers.cpp*

Inherits from CBaseToggle



## Members

public int m_cTargets

public int m_index

public float m_startTime

public string_t [16] m_iTargetName

public float [16] m_flTargetDelay



## Functions

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 302 of ./game/server/triggers.cpp*

### Spawn

*public void Spawn()*

*Defined at line 330 of ./game/server/triggers.cpp*

### ManagerThink

*public void ManagerThink()*

*Defined at line 371 of ./game/server/triggers.cpp*

 Designers were using this to fire targets that may or may not exist --  so I changed it to use the standard target fire code, made it a little simpler.

### ManagerUse

*public void ManagerUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 413 of ./game/server/triggers.cpp*

 The USE function builds the time table and starts the entity thinking.

### ManagerReport

*public void ManagerReport()*

*Defined at line 435 of ./game/server/triggers.cpp*

### HasTarget

*public _Bool HasTarget(string_t targetname)*

*Defined at line 360 of ./game/server/triggers.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 263 of ./game/server/triggers.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 300 of ./game/server/triggers.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 300 of ./game/server/triggers.cpp*

### IsClone

*private BOOL IsClone()*

*Defined at line 276 of ./game/server/triggers.cpp*

### ShouldClone

*private BOOL ShouldClone()*

*Defined at line 277 of ./game/server/triggers.cpp*

### Clone

*private class CMultiManager * Clone()*

*Defined at line 396 of ./game/server/triggers.cpp*



