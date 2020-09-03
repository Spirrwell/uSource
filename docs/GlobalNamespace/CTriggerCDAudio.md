# class CTriggerCDAudio

*Defined at line 635 of ./game/server/triggers.cpp*

=====================================

 trigger_cdaudio - starts/stops cd audio tracks



Inherits from CBaseTrigger



## Functions

### Spawn

*public void Spawn()*

*Defined at line 662 of ./game/server/triggers.cpp*

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 667 of ./game/server/triggers.cpp*

### PlayTrack

*public void PlayTrack()*

*Defined at line 703 of ./game/server/triggers.cpp*

 only plays for ONE client, so only use in single play!

### Touch

*public void Touch(class CBaseEntity * pOther)*

*Defined at line 651 of ./game/server/triggers.cpp*

 Changes tracks or stops CD when player touches

 !!!HACK - overloaded HEALTH to avoid adding new field



