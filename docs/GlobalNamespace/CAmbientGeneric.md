# class CAmbientGeneric

*Defined at line 112 of ./game/server/sound.cpp*

Inherits from CBaseEntity



## Members

public float m_flAttenuation

dynpitchvol m_dpv

public BOOL m_fActive

public BOOL m_fLooping



## Functions

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 637 of ./game/server/sound.cpp*

 KeyValue - load keyvalue pairs into member data of the ambient generic. NOTE: called BEFORE spawn!

### Spawn

*public void Spawn()*

*Defined at line 155 of ./game/server/sound.cpp*

 ambient_generic - general-purpose user-defined static sound

### Precache

*public void Precache()*

*Defined at line 218 of ./game/server/sound.cpp*

### ToggleUse

*public void ToggleUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 535 of ./game/server/sound.cpp*

 ToggleUse - turns an ambient sound on or off.  If the  ambient is a looping sound, mark sound as active (m_fActive) if it's playing, innactive if not.  If the sound is not a looping sound, never mark it as active.

### RampThink

*public void RampThink()*

*Defined at line 250 of ./game/server/sound.cpp*

 RampThink - Think at 5hz if we are dynamically modifying  pitch or volume of the playing sound.  This function will ramp pitch and/or volume up or down, modify pitch/volume with lfo if active.

### InitModulationParms

*public void InitModulationParms()*

*Defined at line 448 of ./game/server/sound.cpp*

 Init all ramp params in preparation to  play a new sound

### Save

*public int Save(class CSave & save)*

*Defined at line 150 of ./game/server/sound.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 150 of ./game/server/sound.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 125 of ./game/server/sound.cpp*



