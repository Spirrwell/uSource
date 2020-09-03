# class CMultiSource

*Defined at line 21 of ./game/shared/c_point_entity.h*

Inherits from CPointEntity



## Members

public class EHANDLE [32] m_rgEntities

public int [32] m_rgTriggered

public int m_iTotal

public string_t m_globalstate



## Functions

### Spawn

*public void Spawn()*

*Defined at line 89 of ./game/shared/c_point_entity.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 71 of ./game/shared/c_point_entity.cpp*

 Cache user-entity-field values until spawn is called.

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 100 of ./game/shared/c_point_entity.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 27 of ./game/shared/c_point_entity.h*

### IsTriggered

*public _Bool IsTriggered(class CBaseEntity * pActivator)*

*Defined at line 134 of ./game/shared/c_point_entity.cpp*

### Register

*public void Register()*

*Defined at line 20 of ./game/shared/c_point_entity.cpp*

================================================================================================================================================// CMultiSource

### Save

*public int Save(class CSave & save)*

*Defined at line 64 of ./game/shared/c_point_entity.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 64 of ./game/shared/c_point_entity.cpp*



