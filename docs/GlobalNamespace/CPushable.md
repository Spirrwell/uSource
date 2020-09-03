# class CPushable

*Defined at line 774 of ./game/server/func_break.cpp*

Inherits from CBreakable



## Members

public int m_lastSound

public float m_maxSpeed

public float m_soundTime



## Functions

### Spawn

*public void Spawn()*

*Defined at line 820 of ./game/server/func_break.cpp*

### Precache

*public void Precache()*

*Defined at line 846 of ./game/server/func_break.cpp*

### Touch

*public void Touch(class CBaseEntity * pOther)*

*Defined at line 906 of ./game/server/func_break.cpp*

### Move

*public void Move(class CBaseEntity * pMover, int push)*

*Defined at line 914 of ./game/server/func_break.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 855 of ./game/server/func_break.cpp*

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 893 of ./game/server/func_break.cpp*

 Pull the func_pushable

### StopSound

*public void StopSound()*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 786 of ./game/server/func_break.cpp*

virtual void	SetActivator( CBaseEntity *pActivator ) { m_pPusher = pActivator; }

### Save

*public int Save(class CSave & save)*

*Defined at line 809 of ./game/server/func_break.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 809 of ./game/server/func_break.cpp*

### MaxSpeed

*public float MaxSpeed()*

*Defined at line 790 of ./game/server/func_break.cpp*

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 993 of ./game/server/func_break.cpp*

 breakables use an overridden takedamage



