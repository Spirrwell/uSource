# class CBaseButton

*Defined at line 122 of ./game/server/cbase.h*

 Generic Button



Inherits from CBaseToggle



## Members

public BOOL m_fStayPushed

public BOOL m_fRotating

public string_t m_strChangeTarget

locksounds m_ls

public BYTE m_bLockedSound

public BYTE m_bLockedSentence

public BYTE m_bUnlockedSound

public BYTE m_bUnlockedSentence

public int m_sounds



## Functions

### Spawn

*public void Spawn()*

*Defined at line 319 of ./game/server/func_button.cpp*

QUAKED func_button (0 .5 .8) ?When a button is touched, it moves some distance in the direction of it's angle,triggers all of it's targets, waits some time, then returns to it's original positionwhere it can be triggered again.

"angle"		determines the opening direction"target"	all entities with a matching targetname will be used"speed"		override the default 40 speed"wait"		override the default 1 second wait (-1 = never return)"lip"		override the default 4 pixel lip remaining at end of move"health"	if set, the button must be killed instead of touched"sounds"0) steam metal1) wooden clunk2) metallic click3) in-out

### Precache

*public void Precache()*

*Defined at line 133 of ./game/server/func_button.cpp*

### RotSpawn

*public void RotSpawn()*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 232 of ./game/server/func_button.cpp*

 Cache user-entity-field values until spawn is called.

### ButtonActivate

*public void ButtonActivate()*

*Defined at line 587 of ./game/server/func_button.cpp*

 Starts the button moving "in/up".

### SparkSoundCache

*public void SparkSoundCache()*

### ButtonShot

*public void ButtonShot()*

### ButtonTouch

*public void ButtonTouch(class CBaseEntity * pOther)*

*Defined at line 551 of ./game/server/func_button.cpp*

 Touching a button simply "activates" it.

### ButtonSpark

*public void ButtonSpark()*

*Defined at line 494 of ./game/server/func_button.cpp*

### TriggerAndWait

*public void TriggerAndWait()*

*Defined at line 616 of ./game/server/func_button.cpp*

 Button has reached the "in/up" position.  Activate its "targets", and pause before "popping out".

### ButtonReturn

*public void ButtonReturn()*

*Defined at line 651 of ./game/server/func_button.cpp*

 Starts the button moving "out/down".

### ButtonBackHome

*public void ButtonBackHome()*

*Defined at line 668 of ./game/server/func_button.cpp*

 Button has returned to start state.  Quiesce it.

### ButtonUse

*public void ButtonUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 505 of ./game/server/func_button.cpp*

 Button's Use function

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 271 of ./game/server/func_button.cpp*

 ButtonShot

### Save

*public int Save(class CSave & save)*

*Defined at line 131 of ./game/server/func_button.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 131 of ./game/server/func_button.cpp*

### ButtonResponseToTouch

*public enum CBaseButton::BUTTON_CODE ButtonResponseToTouch()*

*Defined at line 527 of ./game/server/func_button.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 149 of ./game/server/cbase.h*

 Buttons that don't take damage can be IMPULSE used



## Enums

| enum BUTTON_CODE |

--

| BUTTON_NOTHING |
| BUTTON_ACTIVATE |
| BUTTON_RETURN |


*Defined at line 144 of ./game/server/cbase.h*



