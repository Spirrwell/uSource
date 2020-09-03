# class IEngineTrace

*Defined at line 87 of ./engine/engine_int.h*

Inherits from IAppInterface



## Functions

### TraceLine

*public void TraceLine(const float * v1, const float * v2, int fNoMonsters, edict_t * pentToSkip, TraceResult * ptr)*

### TraceToss

*public void TraceToss(edict_t * pent, edict_t * pentToIgnore, TraceResult * ptr)*

### TraceMonsterHull

*public int TraceMonsterHull(edict_t * pEdict, const float * v1, const float * v2, int fNoMonsters, edict_t * pentToSkip, TraceResult * ptr)*

### TraceHull

*public void TraceHull(const float * v1, const float * v2, int fNoMonsters, int hullNumber, edict_t * pentToSkip, TraceResult * ptr)*

### TraceModel

*public void TraceModel(const float * v1, const float * v2, int hullNumber, edict_t * pent, TraceResult * ptr)*

### TraceTexture

*public const char * TraceTexture(edict_t * pTextureEntity, const float * v1, const float * v2)*

### TraceSphere

*public void TraceSphere(const float * v1, const float * v2, int fNoMonsters, float radius, edict_t * pentToSkip, TraceResult * ptr)*



