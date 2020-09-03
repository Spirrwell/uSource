# class CBreakable

*Defined at line 41 of ./game/server/func_break.h*

Inherits from CBaseDelay



## Members

public Materials m_Material

public Explosions m_Explosion

public int m_idShard

public float m_angle

public string_t m_iszGibModel

public string_t m_iszSpawnObject



## Functions

### Spawn

*public void Spawn()*

*Defined at line 145 of ./game/server/func_break.cpp*

 basic functions

### Precache

*public void Precache()*

*Defined at line 278 of ./game/server/func_break.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 64 of ./game/server/func_break.cpp*

### BreakTouch

*public void BreakTouch(class CBaseEntity * pOther)*

*Defined at line 422 of ./game/server/func_break.cpp*

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 472 of ./game/server/func_break.cpp*

 Break when triggered

### DamageSound

*public void DamageSound()*

*Defined at line 353 of ./game/server/func_break.cpp*

 play shard sound when func_breakable takes damage. the more damage, the louder the shard sound.

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 523 of ./game/server/func_break.cpp*

 breakables use an overridden takedamage

========================================================= Special takedamage for func_breakable. Allows us to make exceptions that are breakable-specific bitsDamageType indicates the type of damage sustained ie: DMG_CRUSH=========================================================

### TraceAttack

*public void TraceAttack(entvars_t * pevAttacker, float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 484 of ./game/server/func_break.cpp*

 To spark when hit

### IsBreakable

*public BOOL IsBreakable()*

*Defined at line 758 of ./game/server/func_break.cpp*

### SparkWhenHit

*public BOOL SparkWhenHit()*

### DamageDecal

*public int DamageDecal(int bitsDamageType)*

*Defined at line 763 of ./game/server/func_break.cpp*

### Die

*public void Die()*

*Defined at line 574 of ./game/server/func_break.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 63 of ./game/server/func_break.h*

### Save

*public int Save(class CSave & save)*

*Defined at line 143 of ./game/server/func_break.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 143 of ./game/server/func_break.cpp*

### Explodable

*public BOOL Explodable()*

*Defined at line 67 of ./game/server/func_break.h*

### ExplosionMagnitude

*public int ExplosionMagnitude()*

*Defined at line 68 of ./game/server/func_break.h*

### ExplosionSetMagnitude

*public void ExplosionSetMagnitude(int magnitude)*

*Defined at line 69 of ./game/server/func_break.h*

### MaterialSoundPrecache

*public void MaterialSoundPrecache(Materials precacheMaterial)*

*Defined at line 254 of ./game/server/func_break.cpp*

### MaterialSoundRandom

*public void MaterialSoundRandom(edict_t * pEdict, Materials soundMaterial, float volume)*

*Defined at line 267 of ./game/server/func_break.cpp*

### MaterialSoundList

*public const char ** MaterialSoundList(Materials precacheMaterial, int & soundCount)*

*Defined at line 215 of ./game/server/func_break.cpp*



