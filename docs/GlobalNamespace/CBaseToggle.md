# class CBaseToggle

*Defined at line 62 of ./game/shared/c_base_animating.h*

Inherits from CBaseAnimating



## Members

public TOGGLE_STATE m_toggle_state

public float m_flActivateFinished

public float m_flMoveDistance

public float m_flWait

public float m_flLip

public float m_flTWidth

public float m_flTLength

Vector m_vecPosition1

Vector m_vecPosition2

Vector m_vecAngle1

Vector m_vecAngle2

public int m_cTriggersLeft

public float m_flHeight

EHANDLE m_hActivator

public void (class CBaseToggle::*)(void) m_pfnCallWhenMoveDone

Vector m_vecFinalDest

Vector m_vecFinalAngle

public int m_bitsDamageInflict

public string_t m_sMaster

public _Bool m_bAngMoveDone

public _Bool m_bLinearMoveDone



## Functions

### CBaseToggle

*public void CBaseToggle()*

*Defined at line 65 of ./game/shared/c_base_animating.h*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 74 of ./game/client/hl/hl_baseentity.cpp*

### Think

*public void Think()*

*Defined at line 75 of ./game/shared/c_base_animating.h*

### Save

*public int Save(class CSave & save)*

*Defined at line 73 of ./game/client/hl/hl_baseentity.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 72 of ./game/client/hl/hl_baseentity.cpp*

 CBaseToggle Stubs

### GetToggleState

*public int GetToggleState()*

*Defined at line 111 of ./game/shared/c_base_animating.h*

### GetDelay

*public float GetDelay()*

*Defined at line 112 of ./game/shared/c_base_animating.h*

### LinearMove

*public void LinearMove(Vector vecDest, float flSpeed)*

*Defined at line 308 of ./game/server/subs.cpp*

 common member functions

=============LinearMove

calculate pev->velocity and pev->nextthink to reach vecDest frompev->origin traveling at flSpeed===============

### LinearMoveDone

*public void LinearMoveDone()*

*Defined at line 349 of ./game/server/subs.cpp*

============After moving, set origin to exact final destination, call "move done" function============

### AngularMove

*public void AngularMove(Vector vecDestAngle, float flSpeed)*

*Defined at line 383 of ./game/server/subs.cpp*

=============AngularMove

calculate pev->velocity and pev->nextthink to reach vecDest frompev->origin traveling at flSpeedJust like LinearMove, but rotational.===============

### AngularMoveDone

*public void AngularMoveDone()*

*Defined at line 417 of ./game/server/subs.cpp*

============After rotating, set angle to exact final angle, call "move done" function============

### IsLockedByMaster

*public _Bool IsLockedByMaster()*

*Defined at line 366 of ./game/server/subs.cpp*

### MoveDone

*public void MoveDone()*

*Defined at line 122 of ./game/shared/c_base_animating.h*

 Override this in place of SetMoveDone 

### AxisValue

*public float AxisValue(int flags, const class Vector & angles)*

*Defined at line 429 of ./game/server/subs.cpp*

### AxisDir

*public void AxisDir(entvars_t * pev)*

*Defined at line 439 of ./game/server/subs.cpp*

### AxisDelta

*public float AxisDelta(int flags, const class Vector & angle1, const class Vector & angle2)*

*Defined at line 449 of ./game/server/subs.cpp*



