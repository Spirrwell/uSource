# class CZombie

*Defined at line 36 of ./game/server/npc/npc_zombie.cpp*

Inherits from CBaseMonster



## Members

public float m_flNextFlinch



## Functions

### Spawn

*public void Spawn()*

*Defined at line 265 of ./game/server/npc/npc_zombie.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 287 of ./game/server/npc/npc_zombie.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 121 of ./game/server/npc/npc_zombie.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### Classify

*public int Classify()*

*Defined at line 112 of ./game/server/npc/npc_zombie.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 187 of ./game/server/npc/npc_zombie.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.=========================================================

### IgnoreConditions

*public int IgnoreConditions()*

*Defined at line 316 of ./game/server/npc/npc_zombie.cpp*

========================================================= AI Schedules Specific to this monster=========================================================

### PainSound

*public void PainSound()*

*Defined at line 152 of ./game/server/npc/npc_zombie.cpp*

### AlertSound

*public void AlertSound()*

*Defined at line 160 of ./game/server/npc/npc_zombie.cpp*

### IdleSound

*public void IdleSound()*

*Defined at line 167 of ./game/server/npc/npc_zombie.cpp*

### AttackSound

*public void AttackSound()*

*Defined at line 175 of ./game/server/npc/npc_zombie.cpp*

### CheckRangeAttack1

*public BOOL CheckRangeAttack1(float flDot, float flDist)*

*Defined at line 61 of ./game/server/npc/npc_zombie.cpp*

 No range attacks

### CheckRangeAttack2

*public BOOL CheckRangeAttack2(float flDot, float flDist)*

*Defined at line 62 of ./game/server/npc/npc_zombie.cpp*

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 134 of ./game/server/npc/npc_zombie.cpp*



