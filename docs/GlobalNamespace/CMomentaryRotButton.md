# class CMomentaryRotButton

*Defined at line 791 of ./game/server/func_button.cpp*

Inherits from CBaseToggle



## Members

public int m_lastUsed

public int m_direction

public float m_returnSpeed

Vector m_start

Vector m_end

public int m_sounds



## Functions

### Spawn

*public void Spawn()*

*Defined at line 840 of ./game/server/func_button.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 876 of ./game/server/func_button.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 796 of ./game/server/func_button.cpp*

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 900 of ./game/server/func_button.cpp*

 BUGBUG: This design causes a latentcy.  When the button is retriggered, the first impulse will send the target in the wrong direction because the parameter is calculated based on the current, not future position.

### Off

*public void Off()*

*Defined at line 993 of ./game/server/func_button.cpp*

### Return

*public void Return()*

*Defined at line 1007 of ./game/server/func_button.cpp*

### UpdateSelf

*public void UpdateSelf(float value)*

*Defined at line 936 of ./game/server/func_button.cpp*

### UpdateSelfReturn

*public void UpdateSelfReturn(float value)*

*Defined at line 1016 of ./game/server/func_button.cpp*

### UpdateAllButtons

*public void UpdateAllButtons(float value, int start)*

*Defined at line 912 of ./game/server/func_button.cpp*

### PlaySound

*public void PlaySound()*

*Defined at line 892 of ./game/server/func_button.cpp*

### UpdateTarget

*public void UpdateTarget(float value)*

*Defined at line 974 of ./game/server/func_button.cpp*

### Instance

*public class CMomentaryRotButton * Instance(edict_t * pent)*

*Defined at line 813 of ./game/server/func_button.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 836 of ./game/server/func_button.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 836 of ./game/server/func_button.cpp*



