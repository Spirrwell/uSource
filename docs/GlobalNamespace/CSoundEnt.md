# class CSoundEnt

*Defined at line 69 of ./game/server/soundent.h*

========================================================= CSoundEnt - a single instance of this entity spawns when the world spawns. The SoundEnt's job is to update the  world's Free and Active sound lists.=========================================================



Inherits from CBaseEntity



## Members

public int m_iFreeSound

public int m_iActiveSound

public int m_cLastActiveSounds

public BOOL m_fShowReport

private class CSound [64] m_SoundPool



## Functions

### Precache

*public void Precache()*

*Defined at line 131 of ./game/server/soundent.cpp*

========================================================= Precache - dummy function=========================================================

### Spawn

*public void Spawn()*

*Defined at line 80 of ./game/server/soundent.cpp*

========================================================= Spawn =========================================================

### Think

*public void Think()*

*Defined at line 93 of ./game/server/soundent.cpp*

========================================================= Think - at interval, the entire active sound list is checked for sounds that have ExpireTimes less than or equal to the current world time, and these sounds are deallocated.=========================================================

### Initialize

*public void Initialize()*

*Defined at line 227 of ./game/server/soundent.cpp*

========================================================= Initialize - clears all sounds and moves them into the  free sound list.=========================================================

### InsertSound

*public void InsertSound(int iType, const class Vector & vecOrigin, int iVolume, float flDuration)*

*Defined at line 297 of ./game/client/hl/hl_baseentity.cpp*

========================================================= InsertSound - Allocates a free sound and fills it with  sound info.=========================================================

### FreeSound

*public void FreeSound(int iSound, int iPrevious)*

*Defined at line 140 of ./game/server/soundent.cpp*

========================================================= FreeSound - clears the passed active sound and moves it  to the top of the free list. TAKE CARE to only call this function for sounds in the Active list!!=========================================================

### ActiveList

*public int ActiveList()*

*Defined at line 311 of ./game/server/soundent.cpp*

========================================================= ActiveList - returns the head of the active sound list=========================================================

### FreeList

*public int FreeList()*

*Defined at line 324 of ./game/server/soundent.cpp*

========================================================= FreeList - returns the head of the free sound list=========================================================

### SoundPointerForIndex

*public class CSound * SoundPointerForIndex(int iIndex)*

*Defined at line 338 of ./game/server/soundent.cpp*

========================================================= SoundPointerForIndex - returns a pointer to the instance of CSound at index's position in the sound pool.=========================================================

### ClientSoundIndex

*public int ClientSoundIndex(edict_t * pClient)*

*Defined at line 366 of ./game/server/soundent.cpp*

========================================================= Clients are numbered from 1 to MAXCLIENTS, but the client reserved sounds in the soundlist are from 0 to MAXCLIENTS - 1, so this function ensures that a client gets the proper index to his reserved sound in the soundlist.=========================================================

### IsEmpty

*public BOOL IsEmpty()*

*Defined at line 84 of ./game/server/soundent.h*

### ISoundsInList

*public int ISoundsInList(int iListType)*

*Defined at line 273 of ./game/server/soundent.cpp*

========================================================= ISoundsInList - returns the number of sounds in the desired sound list.=========================================================

### IAllocSound

*public int IAllocSound()*

*Defined at line 170 of ./game/server/soundent.cpp*

========================================================= IAllocSound - moves a sound from the Free list to the  Active list returns the index of the alloc'd sound=========================================================

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 87 of ./game/server/soundent.h*



