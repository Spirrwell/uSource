# class CTentacle

*Defined at line 35 of ./game/server/npc/npc_tentacle.cpp*

Inherits from CBaseMonster



## Members

public float m_flInitialYaw

public int m_iGoalAnim

public int m_iLevel

public int m_iDir

public float m_flFramerateAdj

public float m_flSoundYaw

public int m_iSoundLevel

public float m_flSoundTime

public float m_flSoundRadius

public int m_iHitDmg

public float m_flHitTime

public float m_flTapRadius

public float m_flNextSong

public float m_flMaxYaw

public int m_iTapSound

Vector m_vecPrevSound

public float m_flPrevSoundTime



## Functions

### CTentacle

*public void CTentacle()*

*Defined at line 316 of ./game/server/npc/npc_tentacle.cpp*

### Spawn

*public void Spawn()*

*Defined at line 242 of ./game/server/npc/npc_tentacle.cpp*

 Tentacle Spawn

### Precache

*public void Precache()*

*Defined at line 287 of ./game/server/npc/npc_tentacle.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 322 of ./game/server/npc/npc_tentacle.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 164 of ./game/server/npc/npc_tentacle.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 164 of ./game/server/npc/npc_tentacle.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 49 of ./game/server/npc/npc_tentacle.cpp*

 Don't allow the tentacle to go across transitions!!!

### SetObjectCollisionBox

*public void SetObjectCollisionBox()*

*Defined at line 51 of ./game/server/npc/npc_tentacle.cpp*

### Cycle

*public void Cycle()*

*Defined at line 435 of ./game/server/npc/npc_tentacle.cpp*

 TentacleThink

### CommandUse

*public void CommandUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 693 of ./game/server/npc/npc_tentacle.cpp*

### Start

*public void Start()*

*Defined at line 916 of ./game/server/npc/npc_tentacle.cpp*

 TentacleStart

 void CTentacle::Start( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value )

### DieThink

*public void DieThink()*

*Defined at line 720 of ./game/server/npc/npc_tentacle.cpp*

### Test

*public void Test()*

*Defined at line 424 of ./game/server/npc/npc_tentacle.cpp*

### HitTouch

*public void HitTouch(class CBaseEntity * pOther)*

*Defined at line 935 of ./game/server/npc/npc_tentacle.cpp*

### HearingSensitivity

*public float HearingSensitivity()*

*Defined at line 66 of ./game/server/npc/npc_tentacle.cpp*

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 971 of ./game/server/npc/npc_tentacle.cpp*

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 793 of ./game/server/npc/npc_tentacle.cpp*

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 984 of ./game/server/npc/npc_tentacle.cpp*

### GetIdealState

*public MONSTERSTATE GetIdealState()*

*Defined at line 72 of ./game/server/npc/npc_tentacle.cpp*

### CanPlaySequence

*public int CanPlaySequence(BOOL fDisregardState)*

*Defined at line 73 of ./game/server/npc/npc_tentacle.cpp*

### Classify

*public int Classify()*

*Defined at line 234 of ./game/server/npc/npc_tentacle.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### Level

*public int Level(float dz)*

*Defined at line 338 of ./game/server/npc/npc_tentacle.cpp*

### MyLevel

*public int MyLevel()*

*Defined at line 363 of ./game/server/npc/npc_tentacle.cpp*

### MyHeight

*public float MyHeight()*

*Defined at line 349 of ./game/server/npc/npc_tentacle.cpp*



