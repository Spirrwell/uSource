# class CFuncTrain

*Defined at line 601 of ./game/server/plats.cpp*

====================== TRAIN code ==================================================



Inherits from CBasePlatTrain



## Members

public entvars_t * m_pevCurrentTarget

public int m_sounds

public BOOL m_activated



## Functions

### Spawn

*public void Spawn()*

*Defined at line 813 of ./game/server/plats.cpp*

QUAKED func_train (0 .5 .8) ?Trains are moving platforms that players can ride.The targets origin specifies the min point of the train at each corner.The train spawns at the first target it is pointing at.If the train is the target of a button or trigger, it will not begin moving until activated.speed	default 100dmg		default	2sounds1) ratchet metal

### Precache

*public void Precache()*

*Defined at line 842 of ./game/server/plats.cpp*

### Activate

*public void Activate()*

*Defined at line 780 of ./game/server/plats.cpp*

### OverrideReset

*public void OverrideReset()*

*Defined at line 869 of ./game/server/plats.cpp*

### Blocked

*public void Blocked(class CBaseEntity * pOther)*

*Defined at line 646 of ./game/server/plats.cpp*

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 656 of ./game/server/plats.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 635 of ./game/server/plats.cpp*

### Wait

*public void Wait()*

*Defined at line 677 of ./game/server/plats.cpp*

### Next

*public void Next()*

*Defined at line 721 of ./game/server/plats.cpp*

 Train next - path corner needs to change to next target 

### Save

*public int Save(class CSave & save)*

*Defined at line 633 of ./game/server/plats.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 633 of ./game/server/plats.cpp*



