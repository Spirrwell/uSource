# class CFuncPlat

*Defined at line 210 of ./game/server/plats.cpp*

Inherits from CBasePlatTrain



## Functions

### Spawn

*public void Spawn()*

*Defined at line 301 of ./game/server/plats.cpp*

### Precache

*public void Precache()*

*Defined at line 292 of ./game/server/plats.cpp*

### Setup

*public void Setup()*

*Defined at line 259 of ./game/server/plats.cpp*

QUAKED func_plat (0 .5 .8) ? PLAT_LOW_TRIGGERspeed	default 150

Plats are always drawn in the extended position, so they will light correctly.

If the plat is the target of another trigger or button, it will start out disabled inthe extended position until it is trigger, when it will lower and become a normal plat.

If the "height" key is set, that will determine the amount the plat moves, instead ofbeing implicitly determined by the model's height.

Set "sounds" to one of the following:1) base fast2) chain slow

### Blocked

*public void Blocked(class CBaseEntity * pOther)*

*Defined at line 478 of ./game/server/plats.cpp*

### PlatUse

*public void PlatUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 389 of ./game/server/plats.cpp*

 Used by SUB_UseTargets, when a platform is the target of a button. Start bringing platform down.

### CallGoDown

*public void CallGoDown()*

*Defined at line 221 of ./game/server/plats.cpp*

### CallHitTop

*public void CallHitTop()*

*Defined at line 222 of ./game/server/plats.cpp*

### CallHitBottom

*public void CallHitBottom()*

*Defined at line 223 of ./game/server/plats.cpp*

### GoUp

*public void GoUp()*

*Defined at line 445 of ./game/server/plats.cpp*

 Platform is at bottom, now starts moving up

### GoDown

*public void GoDown()*

*Defined at line 416 of ./game/server/plats.cpp*

 Platform is at top, now starts moving down.

### HitTop

*public void HitTop()*

*Defined at line 459 of ./game/server/plats.cpp*

 Platform has hit top. Pauses, then starts back down again.

### HitBottom

*public void HitBottom()*

*Defined at line 430 of ./game/server/plats.cpp*

 Platform has hit bottom. Stops and waits forever.



