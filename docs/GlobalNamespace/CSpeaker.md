# class CSpeaker

*Defined at line 1716 of ./game/server/sound.cpp*

 ===================================================================================

 Speaker class. Used for announcements per level, for door lock/unlock spoken voice. 



Inherits from CBaseEntity



## Members

public int m_preset



## Functions

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 1910 of ./game/server/sound.cpp*

 KeyValue - load keyvalue pairs into member data NOTE: called BEFORE spawn!

### Spawn

*public void Spawn()*

*Defined at line 1746 of ./game/server/sound.cpp*

 ambient_generic - general-purpose user-defined static sound

### Precache

*public void Precache()*

*Defined at line 1772 of ./game/server/sound.cpp*

### ToggleUse

*public void ToggleUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 1866 of ./game/server/sound.cpp*

 ToggleUse - if an announcement is pending, cancel it.  If no announcement is pending, start one.

### SpeakerThink

*public void SpeakerThink()*

*Defined at line 1778 of ./game/server/sound.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 1741 of ./game/server/sound.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 1741 of ./game/server/sound.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 1729 of ./game/server/sound.cpp*



