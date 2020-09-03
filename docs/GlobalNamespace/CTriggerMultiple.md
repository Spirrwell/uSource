# class CTriggerMultiple

*Defined at line 1030 of ./game/server/triggers.cpp*

QUAKED trigger_multiple (.5 .5 .5) ? notouchVariable sized repeatable trigger.  Must be targeted at one or more entities.If "health" is set, the trigger must be killed to activate each time.If "delay" is set, the trigger waits some time after activating before firing."wait" : Seconds between triggerings. (.2 default)If notouch is set, the trigger is only fired by other entities, not by touching.NOTOUCH has been obsoleted by trigger_relay!sounds1)      secret2)      beep beep3)      large switch4)NEWif a trigger has a NETNAME, that NETNAME will become the TARGET of the triggered object.



Inherits from CBaseTrigger



## Functions

### Spawn

*public void Spawn()*

*Defined at line 1038 of ./game/server/triggers.cpp*



