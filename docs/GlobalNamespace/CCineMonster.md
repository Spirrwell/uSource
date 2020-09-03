# class CCineMonster

*Defined at line 324 of ./game/shared/c_base_monster.h*

Inherits from CBaseMonster



## Members

public string_t m_iszIdle

public string_t m_iszPlay

public string_t m_iszEntity

public int m_fMoveTo

public int m_iFinishSchedule

public float m_flRadius

public float m_flRepeat

public int m_iDelay

public float m_startTime

public int m_saved_movetype

public int m_saved_solid

public int m_saved_effects

public BOOL m_interruptable



## Functions

### Spawn

*public void Spawn()*

*Defined at line 124 of ./game/server/ai/ai_scripted.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 54 of ./game/server/ai/ai_scripted.cpp*

 Cache user-entity-field values until spawn is called.

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 173 of ./game/server/ai/ai_scripted.cpp*

 CineStart

### Blocked

*public void Blocked(class CBaseEntity * pOther)*

*Defined at line 199 of ./game/server/ai/ai_scripted.cpp*

 This doesn't really make sense since only MOVETYPE_PUSH get 'Blocked' events

### Touch

*public void Touch(class CBaseEntity * pOther)*

*Defined at line 204 of ./game/server/ai/ai_scripted.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 332 of ./game/shared/c_base_monster.h*

### Activate

*public void Activate()*

*Defined at line 724 of ./game/server/ai/ai_scripted.cpp*

 Find an entity that I'm interested in and precache the sounds he'll need in the sequence.

### Save

*public int Save(class CSave & save)*

*Defined at line 116 of ./game/server/ai/ai_scripted.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 116 of ./game/server/ai/ai_scripted.cpp*

### CineThink

*public void CineThink()*

*Defined at line 458 of ./game/server/ai/ai_scripted.cpp*

 void EXPORT CineSpawnThink( void );

### Pain

*public void Pain()*

*Defined at line 253 of ./game/server/ai/ai_scripted.cpp*

 ********** Cinematic PAIN **********

### Die

*public void Die()*

*Defined at line 245 of ./game/server/ai/ai_scripted.cpp*

 ********** Cinematic DIE **********

### DelayStart

*public void DelayStart(int state)*

*Defined at line 699 of ./game/server/ai/ai_scripted.cpp*

 find all the cinematic entities with my targetname and tell them to wait before starting

### FindEntity

*public BOOL FindEntity()*

*Defined at line 263 of ./game/server/ai/ai_scripted.cpp*

 find a viable entity

### PossessEntity

*public void PossessEntity()*

*Defined at line 312 of ./game/server/ai/ai_scripted.cpp*

 make the entity enter a scripted sequence

### ReleaseEntity

*public void ReleaseEntity(class CBaseMonster * pEntity)*

### CancelScript

*public void CancelScript()*

*Defined at line 679 of ./game/server/ai/ai_scripted.cpp*

 find all the cinematic entities with my targetname and stop them from playing

### StartSequence

*public BOOL StartSequence(class CBaseMonster * pTarget, int iszSeq, BOOL completeOnEmpty)*

*Defined at line 474 of ./game/server/ai/ai_scripted.cpp*

 lookup a sequence name and setup the target monster to play it

### FCanOverrideState

*public BOOL FCanOverrideState()*

*Defined at line 154 of ./game/server/ai/ai_scripted.cpp*

========================================================= FCanOverrideState - returns FALSE, scripted sequences  cannot possess entities regardless of state.=========================================================

### SequenceDone

*public void SequenceDone(class CBaseMonster * pMonster)*

*Defined at line 540 of ./game/server/ai/ai_scripted.cpp*

========================================================= SequenceDone - called when a scripted sequence animation sequence is done playing ( or when an AI Scripted Sequence doesn't supply an animation sequence to play ). Expects the CBaseMonster pointer to the monster that the sequence possesses. =========================================================

### FixScriptMonsterSchedule

*public void FixScriptMonsterSchedule(class CBaseMonster * pMonster)*

*Defined at line 569 of ./game/server/ai/ai_scripted.cpp*

========================================================= When a monster finishes a scripted sequence, we have to  fix up its state and schedule for it to return to a  normal AI monster. 

 Scripted sequences just dirty the Schedule and drop the monster in Idle State.=========================================================

### CanInterrupt

*public BOOL CanInterrupt()*

*Defined at line 631 of ./game/server/ai/ai_scripted.cpp*

### AllowInterrupt

*public void AllowInterrupt(BOOL fAllow)*

*Defined at line 624 of ./game/server/ai/ai_scripted.cpp*

### IgnoreConditions

*public int IgnoreConditions()*

*Defined at line 644 of ./game/server/ai/ai_scripted.cpp*



