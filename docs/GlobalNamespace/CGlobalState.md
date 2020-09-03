# class CGlobalState

*Defined at line 144 of ./game/server/saverestore.h*

## Members

private globalentity_t * m_pList

private int m_listCount



## Functions

### CGlobalState

*public void CGlobalState()*

*Defined at line 260 of ./game/server/world.cpp*

### Reset

*public void Reset()*

*Defined at line 265 of ./game/server/world.cpp*

### ClearStates

*public void ClearStates()*

*Defined at line 409 of ./game/server/world.cpp*

### EntityAdd

*public void EntityAdd(string_t globalname, string_t mapName, GLOBALESTATE state)*

*Defined at line 308 of ./game/server/world.cpp*

#endif

### EntitySetState

*public void EntitySetState(string_t globalname, GLOBALESTATE state)*

*Defined at line 322 of ./game/server/world.cpp*

### EntityUpdate

*public void EntityUpdate(string_t globalname, string_t mapname)*

*Defined at line 401 of ./game/server/world.cpp*

### EntityFromTable

*public const globalentity_t * EntityFromTable(string_t globalname)*

*Defined at line 330 of ./game/server/world.cpp*

### EntityGetState

*public GLOBALESTATE EntityGetState(string_t globalname)*

*Defined at line 337 of ./game/server/world.cpp*

### EntityInTable

*public int EntityInTable(string_t globalname)*

*Defined at line 155 of ./game/server/saverestore.h*

### Save

*public int Save(class CSave & save)*

*Defined at line 360 of ./game/server/world.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 380 of ./game/server/world.cpp*

### DumpGlobals

*public void DumpGlobals()*

*Defined at line 293 of ./game/server/world.cpp*

 This is available all the time now on impulse 104, remove later#ifdef _DEBUG

#ifdef _DEBUG

### Find

*private globalentity_t * Find(string_t globalname)*

*Defined at line 271 of ./game/server/world.cpp*

#endif

### operator=

*private void operator=(class CGlobalState & )*

 effc++ rule 11

### CGlobalState

*private void CGlobalState(const class CGlobalState & )*



