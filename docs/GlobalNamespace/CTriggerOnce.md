# class CTriggerOnce

*Defined at line 1077 of ./game/server/triggers.cpp*

QUAKED trigger_once (.5 .5 .5) ? notouchVariable sized trigger. Triggers once, then removes itself.  You must set the key "target" to the name of another object in the level that has a matching"targetname".  If "health" is set, the trigger must be killed to activate.If notouch is set, the trigger is only fired by other entities, not by touching.if "killtarget" is set, any objects that have a matching "target" will be removed when the trigger is fired.if "angle" is set, the trigger will only fire when someone is facing the direction of the angle.  Use "360" for an angle of 0.sounds1)      secret2)      beep beep3)      large switch4)



Inherits from CTriggerMultiple



## Functions

### Spawn

*public void Spawn()*

*Defined at line 1085 of ./game/server/triggers.cpp*



