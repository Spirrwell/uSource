# class CMonsterMaker

*Defined at line 34 of ./game/server/npc/npc_monstermaker.cpp*

========================================================= MonsterMaker - this ent creates monsters during the game.=========================================================



Inherits from CBaseMonster



## Members

public string_t m_iszMonsterClassname

public int m_cNumMonsters

public int m_cLiveChildren

public int m_iMaxLiveChildren

public float m_flGround

public BOOL m_fActive

public BOOL m_fFadeChildren



## Functions

### Spawn

*public void Spawn()*

*Defined at line 100 of ./game/server/npc/npc_monstermaker.cpp*

### Precache

*public void Precache()*

*Defined at line 150 of ./game/server/npc/npc_monstermaker.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 79 of ./game/server/npc/npc_monstermaker.cpp*

### ToggleUse

*public void ToggleUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 249 of ./game/server/npc/npc_monstermaker.cpp*

========================================================= ToggleUse - activates/deactivates the monster maker=========================================================

### CyclicUse

*public void CyclicUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 241 of ./game/server/npc/npc_monstermaker.cpp*

========================================================= CyclicUse - drops one monster from the monstermaker each time we call this.=========================================================

### MakerThink

*public void MakerThink()*

*Defined at line 271 of ./game/server/npc/npc_monstermaker.cpp*

========================================================= MakerThink - creates a new monster every so often=========================================================

### DeathNotice

*public void DeathNotice(entvars_t * pevChild)*

*Defined at line 280 of ./game/server/npc/npc_monstermaker.cpp*

==================================================================================================================

### MakeMonster

*public void MakeMonster()*

*Defined at line 160 of ./game/server/npc/npc_monstermaker.cpp*

========================================================= MakeMonster-  this is the code that drops the monster=========================================================

### Save

*public int Save(class CSave & save)*

*Defined at line 77 of ./game/server/npc/npc_monstermaker.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 77 of ./game/server/npc/npc_monstermaker.cpp*



