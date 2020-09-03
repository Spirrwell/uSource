# class CTriggerHurt

*Defined at line 559 of ./game/server/triggers.cpp*

Inherits from CBaseTrigger



## Functions

### Spawn

*public void Spawn()*

*Defined at line 780 of ./game/server/triggers.cpp*

=====================================

 trigger_hurt - hurts anything that touches it. if the trigger has a targetname, firing it will toggle state

int gfToggleState = 0; // used to determine when all radiation trigger hurts have called 'RadiationThink'

### RadiationThink

*public void RadiationThink()*

*Defined at line 809 of ./game/server/triggers.cpp*

 trigger hurt that causes radiation will do a radius check and set the player's geiger counter level according to distance from center of trigger



