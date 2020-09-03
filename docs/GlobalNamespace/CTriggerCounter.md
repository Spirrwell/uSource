# class CTriggerCounter

*Defined at line 1233 of ./game/server/triggers.cpp*

QUAKED trigger_counter (.5 .5 .5) ? nomessageActs as an intermediary for an action that takes multiple inputs.If nomessage is not set, it will print "1 more.. " etc when triggered and"sequence complete" when finished.  After the counter has been triggered "cTriggersLeft"times (default 2), it will fire all of it's targets and remove itself.



Inherits from CBaseTrigger



## Functions

### Spawn

*public void Spawn()*

*Defined at line 1241 of ./game/server/triggers.cpp*



