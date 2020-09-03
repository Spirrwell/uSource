# class CPathTrack

*Defined at line 38 of ./game/server/trains.h*

#define PATH_SPARKLE_DEBUG		1	// This makes a particle effect around path_track entities for debugging



Inherits from CPointEntity



## Members

public float m_length

public string_t m_altName

public class CPathTrack * m_pnext

public class CPathTrack * m_pprevious

public class CPathTrack * m_paltpath



## Functions

### Spawn

*public void Spawn()*

*Defined at line 211 of ./game/server/pathcorner.cpp*

### Activate

*public void Activate()*

*Defined at line 225 of ./game/server/pathcorner.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 134 of ./game/server/pathcorner.cpp*

 Cache user-entity-field values until spawn is called.

### SetPrevious

*public void SetPrevious(class CPathTrack * pprevious)*

*Defined at line 268 of ./game/server/pathcorner.cpp*

### Link

*public void Link()*

*Defined at line 175 of ./game/server/pathcorner.cpp*

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 145 of ./game/server/pathcorner.cpp*

### ValidPath

*public class CPathTrack * ValidPath(class CPathTrack * ppath, int testFlag)*

*Defined at line 231 of ./game/server/pathcorner.cpp*

### Project

*public void Project(class CPathTrack * pstart, class CPathTrack * pend, class Vector * origin, float dist)*

*Defined at line 242 of ./game/server/pathcorner.cpp*

### Instance

*public class CPathTrack * Instance(edict_t * pent)*

*Defined at line 394 of ./game/server/pathcorner.cpp*

### LookAhead

*public class CPathTrack * LookAhead(class Vector * origin, float dist, int move)*

*Defined at line 276 of ./game/server/pathcorner.cpp*

 Assumes this is ALWAYS enabled

### Nearest

*public class CPathTrack * Nearest(Vector origin)*

*Defined at line 358 of ./game/server/pathcorner.cpp*

 Assumes this is ALWAYS enabled

### GetNext

*public class CPathTrack * GetNext()*

*Defined at line 252 of ./game/server/pathcorner.cpp*

### GetPrevious

*public class CPathTrack * GetPrevious()*

*Defined at line 260 of ./game/server/pathcorner.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 128 of ./game/server/pathcorner.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 128 of ./game/server/pathcorner.cpp*



