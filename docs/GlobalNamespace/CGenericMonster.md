# class CGenericMonster

*Defined at line 31 of ./game/server/ai/ai_genericmonster.cpp*

========================================================= Monster's Anim Events Go Here=========================================================



Inherits from CBaseMonster



## Functions

### Spawn

*public void Spawn()*

*Defined at line 97 of ./game/server/ai/ai_genericmonster.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 132 of ./game/server/ai/ai_genericmonster.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 57 of ./game/server/ai/ai_genericmonster.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### Classify

*public int Classify()*

*Defined at line 48 of ./game/server/ai/ai_genericmonster.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 75 of ./game/server/ai/ai_genericmonster.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.=========================================================

### ISoundMask

*public int ISoundMask()*

*Defined at line 89 of ./game/server/ai/ai_genericmonster.cpp*

========================================================= ISoundMask - generic monster can't hear.=========================================================



