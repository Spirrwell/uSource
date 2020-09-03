# class CBaseTrigger

*Defined at line 498 of ./game/server/triggers.cpp*

Inherits from CBaseToggle



## Functions

### TeleportTouch

*public void TeleportTouch(class CBaseEntity * pOther)*

*Defined at line 1835 of ./game/server/triggers.cpp*

====================================== teleport trigger

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 538 of ./game/server/triggers.cpp*

 Cache user-entity-field values until spawn is called.

### MultiTouch

*public void MultiTouch(class CBaseEntity * pOther)*

*Defined at line 1092 of ./game/server/triggers.cpp*

### HurtTouch

*public void HurtTouch(class CBaseEntity * pOther)*

*Defined at line 883 of ./game/server/triggers.cpp*

 When touched, a hurt trigger does DMG points of damage each half-second

### CDAudioTouch

*public void CDAudioTouch(class CBaseEntity * pOther)*

### ActivateMultiTrigger

*public void ActivateMultiTrigger(class CBaseEntity * pActivator)*

*Defined at line 1122 of ./game/server/triggers.cpp*

 the trigger was just touched/killed/used self.enemy should be set to the activator so it can be held through a delay so wait for the delay time before firing

### MultiWaitOver

*public void MultiWaitOver()*

*Defined at line 1168 of ./game/server/triggers.cpp*

 the wait time has passed, so set back up for another activation

### CounterUse

*public void CounterUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 1184 of ./game/server/triggers.cpp*

 GLOBALS ASSUMED SET:  g_eoActivator

### ToggleUse

*public void ToggleUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 864 of ./game/server/triggers.cpp*

 ToggleUse - If this is the USE function for a trigger, its state will toggle every time it's fired

### InitTrigger

*public void InitTrigger()*

*Defined at line 522 of ./game/server/triggers.cpp*

================InitTrigger================

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 512 of ./game/server/triggers.cpp*



