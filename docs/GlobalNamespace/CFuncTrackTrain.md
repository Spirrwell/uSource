# class CFuncTrackTrain

*Defined at line 74 of ./game/server/trains.h*

Inherits from CBaseEntity



## Members

public class CPathTrack * m_ppath

public float m_length

public float m_height

public float m_speed

public float m_dir

public float m_startSpeed

Vector m_controlMins

Vector m_controlMaxs

public int m_soundPlaying

public int m_sounds

public float m_flVolume

public float m_flBank

public float m_oldSpeed

private unsigned short m_usAdjustPitch



## Functions

### Spawn

*public void Spawn()*

*Defined at line 1430 of ./game/server/plats.cpp*

QUAKED func_train (0 .5 .8) ?Trains are moving platforms that players can ride.The targets origin specifies the min point of the train at each corner.The train spawns at the first target it is pointing at.If the train is the target of a button or trigger, it will not begin moving until activated.speed	default 100dmg		default	2sounds1) ratchet metal

### Precache

*public void Precache()*

*Defined at line 1472 of ./game/server/plats.cpp*

### Blocked

*public void Blocked(class CBaseEntity * pOther)*

*Defined at line 964 of ./game/server/plats.cpp*

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 988 of ./game/server/plats.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 917 of ./game/server/plats.cpp*

### Next

*public void Next()*

*Defined at line 1114 of ./game/server/plats.cpp*

### Find

*public void Find()*

*Defined at line 1323 of ./game/server/plats.cpp*

### NearestPath

*public void NearestPath()*

*Defined at line 1359 of ./game/server/plats.cpp*

### DeadEnd

*public void DeadEnd()*

*Defined at line 1249 of ./game/server/plats.cpp*

### NextThink

*public void NextThink(float thinkTime, BOOL alwaysThink)*

*Defined at line 954 of ./game/server/plats.cpp*

### SetTrack

*public void SetTrack(class CPathTrack * track)*

*Defined at line 91 of ./game/server/trains.h*

### SetControls

*public void SetControls(entvars_t * pevControls)*

*Defined at line 1294 of ./game/server/plats.cpp*

### OnControls

*public _Bool OnControls(entvars_t * pev)*

*Defined at line 1302 of ./game/server/plats.cpp*

### StopSound

*public void StopSound()*

*Defined at line 1051 of ./game/server/plats.cpp*

### UpdateSound

*public void UpdateSound()*

*Defined at line 1075 of ./game/server/plats.cpp*

 update pitch based on speed, start sound if not playing NOTE: when train goes through transition, m_soundPlaying should go to 0,  which will cause the looped sound to restart.

### Instance

*public class CFuncTrackTrain * Instance(edict_t * pent)*

*Defined at line 1412 of ./game/server/plats.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 914 of ./game/server/plats.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 914 of ./game/server/plats.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 104 of ./game/server/trains.h*

### OverrideReset

*public void OverrideReset()*

*Defined at line 1406 of ./game/server/plats.cpp*



