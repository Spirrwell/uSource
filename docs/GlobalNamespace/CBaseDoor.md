# class CBaseDoor

*Defined at line 34 of ./game/server/func_door.cpp*

Inherits from CBaseToggle



## Members

public BYTE m_bHealthValue

public BYTE m_bMoveSnd

public BYTE m_bStopSnd

locksounds m_ls

public BYTE m_bLockedSound

public BYTE m_bLockedSentence

public BYTE m_bUnlockedSound

public BYTE m_bUnlockedSentence

public _Bool m_bTouchEnable

public _Bool m_bDoorDown

public _Bool m_bDoorGoingDown

public _Bool m_bDoorGoingUp



## Functions

### CBaseDoor

*public void CBaseDoor()*

*Defined at line 202 of ./game/server/func_door.cpp*

### Spawn

*public void Spawn()*

*Defined at line 296 of ./game/server/func_door.cpp*

 func_water - same as a door. 

### Precache

*public void Precache()*

*Defined at line 357 of ./game/server/func_door.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 214 of ./game/server/func_door.cpp*

 Cache user-entity-field values until spawn is called.

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 579 of ./game/server/func_door.cpp*

 Used by SUB_UseTargets, when a door is the target of a button.

### Blocked

*public void Blocked(class CBaseEntity * pOther)*

*Defined at line 765 of ./game/server/func_door.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 45 of ./game/server/func_door.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 105 of ./game/server/func_door.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 105 of ./game/server/func_door.cpp*

### SetToggleState

*public void SetToggleState(int state)*

*Defined at line 349 of ./game/server/func_door.cpp*

### Touch

*public void Touch(class CBaseEntity * other)*

*Defined at line 848 of ./game/server/func_door.cpp*

 Base entity overrides 

### Think

*public void Think()*

*Defined at line 854 of ./game/server/func_door.cpp*

### DoorTouch

*public void DoorTouch(class CBaseEntity * pOther)*

*Defined at line 547 of ./game/server/func_door.cpp*

 Doors not tied to anything (e.g. button, another door) can be touched, to make them activate.

 used to selectivly override defaults

### DoorActivate

*public int DoorActivate()*

*Defined at line 590 of ./game/server/func_door.cpp*

 Causes the door to "do its thing", i.e. start moving, and cascade activation.

 local functions

### DoorGoUp

*public void DoorGoUp()*

*Defined at line 625 of ./game/server/func_door.cpp*

 Starts the door going to its "up" position (simply ToggleData->vecPosition2).

### DoorGoDown

*public void DoorGoDown()*

*Defined at line 715 of ./game/server/func_door.cpp*

 Starts the door going to its "down" position (simply ToggleData->vecPosition1).

### DoorHitTop

*public void DoorHitTop()*

*Defined at line 673 of ./game/server/func_door.cpp*

 The door has reached the "up" position.  Either go back down, or wait for another activation.

### DoorHitBottom

*public void DoorHitBottom()*

*Defined at line 736 of ./game/server/func_door.cpp*

 The door has reached the "down" position.  Back to quiescence.

### MoveDone

*public void MoveDone()*

*Defined at line 860 of ./game/server/func_door.cpp*



