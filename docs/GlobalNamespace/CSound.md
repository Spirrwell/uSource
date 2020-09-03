# class CSound

*Defined at line 47 of ./game/server/soundent.h*

========================================================= CSound - an instance of a sound in the world.=========================================================



## Members

Vector m_vecOrigin

public int m_iType

public int m_iVolume

public float m_flExpireTime

public int m_iNext

public int m_iNextAudible



## Functions

### Clear

*public void Clear()*

*Defined at line 29 of ./game/server/soundent.cpp*

========================================================= CSound - Clear - zeros all fields for a sound=========================================================

### Reset

*public void Reset()*

*Defined at line 43 of ./game/server/soundent.cpp*

========================================================= Reset - clears the volume, origin, and type for a sound, but doesn't expire or unlink it. =========================================================

### FIsSound

*public BOOL FIsSound()*

*Defined at line 54 of ./game/server/soundent.cpp*

========================================================= FIsSound - returns TRUE if the sound is an Audible sound=========================================================

### FIsScent

*public BOOL FIsScent()*

*Defined at line 67 of ./game/server/soundent.cpp*

========================================================= FIsScent - returns TRUE if the sound is actually a scent=========================================================



