# class CLight

*Defined at line 27 of ./game/server/lights.cpp*

Inherits from CPointEntity



## Members

private int m_iStyle

private string_t m_iszPattern



## Functions

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 57 of ./game/server/lights.cpp*

 Cache user-entity-field values until spawn is called.

### Spawn

*public void Spawn()*

*Defined at line 87 of ./game/server/lights.cpp*

QUAKED light (0 1 0) (-8 -8 -8) (8 8 8) LIGHT_START_OFFNon-displayed light.Default light value is 300Default style is 0If targeted, it will toggle between on or off.

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 108 of ./game/server/lights.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 52 of ./game/server/lights.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 52 of ./game/server/lights.cpp*



