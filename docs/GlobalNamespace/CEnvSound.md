# class CEnvSound

*Defined at line 805 of ./game/server/sound.cpp*

 =================== ROOM SOUND FX ==========================================



Inherits from CPointEntity



## Members

public float m_flRadius

public float m_flRoomtype



## Functions

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 831 of ./game/server/sound.cpp*

### Spawn

*public void Spawn()*

*Defined at line 978 of ./game/server/sound.cpp*

 env_sound - spawn a sound entity that will set player roomtype when player moves in range and sight.

### Think

*public void Think()*

*Defined at line 887 of ./game/server/sound.cpp*

 CONSIDER: if player in water state, autoset roomtype to 14,15 or 16. 

### Save

*public int Save(class CSave & save)*

*Defined at line 829 of ./game/server/sound.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 829 of ./game/server/sound.cpp*



