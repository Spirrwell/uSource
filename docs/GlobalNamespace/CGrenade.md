# class CGrenade

*Defined at line 6 of ./game/shared/base_grenade.h*

 Contact Grenade / Timed grenade / Satchel Charge



Inherits from CBaseMonster



## Members

public BOOL m_fRegisteredSound



## Functions

### Spawn

*public void Spawn()*

*Defined at line 81 of ./game/client/hl/hl_baseentity.cpp*

### ShootTimed

*public class CGrenade * ShootTimed(entvars_t * pevOwner, Vector vecStart, Vector vecVelocity, float time)*

*Defined at line 82 of ./game/client/hl/hl_baseentity.cpp*

### ShootContact

*public class CGrenade * ShootContact(entvars_t * pevOwner, Vector vecStart, Vector vecVelocity)*

*Defined at line 83 of ./game/client/hl/hl_baseentity.cpp*

### ShootSatchelCharge

*public class CGrenade * ShootSatchelCharge(entvars_t * pevOwner, Vector vecStart, Vector vecVelocity)*

*Defined at line 425 of ./game/server/ggrenade.cpp*

### UseSatchelCharges

*public void UseSatchelCharges(entvars_t * pevOwner, CGrenade::SATCHELCODE code)*

*Defined at line 454 of ./game/server/ggrenade.cpp*

### Explode

*public void Explode(Vector vecSrc, Vector vecAim)*

*Defined at line 78 of ./game/client/hl/hl_baseentity.cpp*

 Grenade Explode

### Explode

*public void Explode(TraceResult * pTrace, int bitsDamageType)*

*Defined at line 79 of ./game/client/hl/hl_baseentity.cpp*

 UNDONE: temporary scorching for PreAlpha - find a less sleazy permenant solution.

### Smoke

*public void Smoke()*

*Defined at line 134 of ./game/server/ggrenade.cpp*

### BounceTouch

*public void BounceTouch(class CBaseEntity * pOther)*

*Defined at line 220 of ./game/server/ggrenade.cpp*

### SlideTouch

*public void SlideTouch(class CBaseEntity * pOther)*

*Defined at line 280 of ./game/server/ggrenade.cpp*

### ExplodeTouch

*public void ExplodeTouch(class CBaseEntity * pOther)*

*Defined at line 190 of ./game/server/ggrenade.cpp*

 Contact grenade, explode when it touches something

### DangerSoundThink

*public void DangerSoundThink()*

*Defined at line 203 of ./game/server/ggrenade.cpp*

### PreDetonate

*public void PreDetonate()*

*Defined at line 167 of ./game/server/ggrenade.cpp*

### Detonate

*public void Detonate()*

*Defined at line 175 of ./game/server/ggrenade.cpp*

### DetonateUse

*public void DetonateUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 84 of ./game/client/hl/hl_baseentity.cpp*

 Timed grenade, this think is called when time runs out.

### TumbleThink

*public void TumbleThink()*

*Defined at line 319 of ./game/server/ggrenade.cpp*

### BounceSound

*public void BounceSound()*

*Defined at line 77 of ./game/client/hl/hl_baseentity.cpp*

 CGrenade Stubs

### BloodColor

*public int BloodColor()*

*Defined at line 32 of ./game/shared/base_grenade.h*

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 80 of ./game/client/hl/hl_baseentity.cpp*



## Enums

| enum  |

--

| SATCHEL_DETONATE |
| SATCHEL_RELEASE |


*Defined at line 11 of ./game/shared/base_grenade.h*



