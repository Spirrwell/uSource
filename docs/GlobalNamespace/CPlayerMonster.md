# class CPlayerMonster

*Defined at line 25 of ./game/server/playermonster.cpp*

========================================================= Monster's Anim Events Go Here=========================================================



Inherits from CBaseMonster



## Functions

### Spawn

*public void Spawn()*

*Defined at line 91 of ./game/server/playermonster.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 116 of ./game/server/playermonster.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 51 of ./game/server/playermonster.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### Classify

*public int Classify()*

*Defined at line 42 of ./game/server/playermonster.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 69 of ./game/server/playermonster.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.=========================================================

### ISoundMask

*public int ISoundMask()*

*Defined at line 83 of ./game/server/playermonster.cpp*

========================================================= ISoundMask - player monster can't hear.=========================================================



