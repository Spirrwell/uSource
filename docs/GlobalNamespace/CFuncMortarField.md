# class CFuncMortarField

*Defined at line 32 of ./game/server/func_mortar.cpp*

Inherits from CBaseToggle



## Members

public string_t m_iszXController

public string_t m_iszYController

public float m_flSpread

public float m_flDelay

public int m_iCount

public int m_fControl



## Functions

### Spawn

*public void Spawn()*

*Defined at line 101 of ./game/server/func_mortar.cpp*

 Drop bombs from above

### Precache

*public void Precache()*

*Defined at line 111 of ./game/server/func_mortar.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 71 of ./game/server/func_mortar.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 40 of ./game/server/func_mortar.cpp*

 Bmodels don't go across transitions

### Save

*public int Save(class CSave & save)*

*Defined at line 69 of ./game/server/func_mortar.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 69 of ./game/server/func_mortar.cpp*

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 119 of ./game/server/func_mortar.cpp*

 If connected to a table, then use the table controllers, else hit where the trigger is.



