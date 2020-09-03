# class CChangeLevel

*Defined at line 1303 of ./game/server/triggers.cpp*

Inherits from CBaseTrigger



## Members

public char [32] m_szMapName

public char [32] m_szLandmarkName

public string_t m_changeTarget

public float m_changeTargetDelay



## Functions

### Spawn

*public void Spawn()*

*Defined at line 1379 of ./game/server/triggers.cpp*

QUAKED trigger_changelevel (0.5 0.5 0.5) ? NO_INTERMISSIONWhen the player touches this, he gets sent to the map listed in the "map" variable.  Unless the NO_INTERMISSION flag is set, the view will go to the info_intermission spot and display stats.

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 1346 of ./game/server/triggers.cpp*

 Cache user-entity-field values until spawn is called.

### UseChangeLevel

*public void UseChangeLevel(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 1433 of ./game/server/triggers.cpp*

========================================================= CChangeLevel :: Use - allows level transitions to be  triggered by buttons, etc.

=========================================================

### TriggerChangeLevel

*public void TriggerChangeLevel()*

### ExecuteChangeLevel

*public void ExecuteChangeLevel()*

*Defined at line 1397 of ./game/server/triggers.cpp*

### TouchChangeLevel

*public void TouchChangeLevel(class CBaseEntity * pOther)*

*Defined at line 1500 of ./game/server/triggers.cpp*

 GLOBALS ASSUMED SET:  st_szNextMap

### ChangeLevelNow

*public void ChangeLevelNow(class CBaseEntity * pActivator)*

*Defined at line 1438 of ./game/server/triggers.cpp*

### FindLandmark

*public edict_t * FindLandmark(const char * pLandmarkName)*

*Defined at line 1411 of ./game/server/triggers.cpp*

### ChangeList

*public int ChangeList(LEVELLIST * pLevelList, int maxList)*

*Defined at line 1576 of ./game/server/triggers.cpp*

 This has grown into a complicated beast Can we make this more elegant? This builds the list of all transitions on this level and which entities are in their PVS's and can / should be moved across.

### AddTransitionToList

*public int AddTransitionToList(LEVELLIST * pLevelList, int listCount, const char * pMapName, const char * pLandmarkName, edict_t * pentLandmark)*

*Defined at line 1510 of ./game/server/triggers.cpp*

 Add a transition to the list, but ignore duplicates  (a designer may have placed multiple trigger_changelevels with the same landmark)

### InTransitionVolume

*public int InTransitionVolume(class CBaseEntity * pEntity, char * pVolumeName)*

*Defined at line 1535 of ./game/server/triggers.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 1341 of ./game/server/triggers.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 1341 of ./game/server/triggers.cpp*



