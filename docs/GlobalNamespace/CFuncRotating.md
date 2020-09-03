# class CFuncRotating

*Defined at line 262 of ./game/server/bmodels.cpp*

 =================== FUNC_ROTATING ==============================================



Inherits from CBaseEntity



## Members

public float m_flFanFriction

public float m_flAttenuation

public float m_flVolume

public float m_pitch

public int m_sounds

public _Bool m_bSpinDown

public _Bool m_bSpinUp

public _Bool m_bEnableHurt

public _Bool m_bRotate

public _Bool m_bDelayUse



## Functions

### CFuncRotating

*public void CFuncRotating()*

*Defined at line 313 of ./game/server/bmodels.cpp*

### Spawn

*public void Spawn()*

*Defined at line 369 of ./game/server/bmodels.cpp*

 basic functions

QUAKED func_rotating (0 .5 .8) ? START_ON REVERSE X_AXIS Y_AXISYou need to have an origin brush as part of this entity.  The  center of that brush will bethe point around which it is rotated. It will rotate around the Z  axis by default.  You cancheck either the X_AXIS or Y_AXIS box to change that.

"speed" determines how fast it moves; default value is 100."dmg"	damage to inflict when blocked (2 default)

REVERSE will cause the it to rotate in the opposite direction.

### Precache

*public void Precache()*

*Defined at line 454 of ./game/server/bmodels.cpp*

### SpinUp

*public void SpinUp()*

*Defined at line 572 of ./game/server/bmodels.cpp*

 SpinUp - accelerates a non-moving func_rotating up to it's speed

### SpinDown

*public void SpinDown()*

*Defined at line 603 of ./game/server/bmodels.cpp*

 SpinDown - decelerates a moving func_rotating to a standstill.

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 323 of ./game/server/bmodels.cpp*

### HurtTouch

*public void HurtTouch(class CBaseEntity * pOther)*

*Defined at line 510 of ./game/server/bmodels.cpp*

 Touch - will hurt others based on how fast the brush is spinning

### Rotate

*public void Rotate()*

*Defined at line 642 of ./game/server/bmodels.cpp*

### RampPitchVol

*public void RampPitchVol(int fUp)*

*Defined at line 533 of ./game/server/bmodels.cpp*

### Blocked

*public void Blocked(class CBaseEntity * pOther)*

*Defined at line 707 of ./game/server/bmodels.cpp*

 RotatingBlocked - An entity has blocked the brush

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 277 of ./game/server/bmodels.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 309 of ./game/server/bmodels.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 309 of ./game/server/bmodels.cpp*

### Think

*public void Think()*

*Defined at line 719 of ./game/server/bmodels.cpp*

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 650 of ./game/server/bmodels.cpp*

========================================================= Rotating Use - when a rotating brush is triggered=========================================================

### Touch

*public void Touch(class CBaseEntity * toucher)*

*Defined at line 712 of ./game/server/bmodels.cpp*



