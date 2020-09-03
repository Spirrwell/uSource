# struct physics_interface_s

*Defined at line 112 of ./engine/physint.h*

 physic callbacks



## Members

public int version

public int (*)(edict_t *, const char *) SV_CreateEntity

public int (*)(edict_t *) SV_PhysicsEntity

public int (*)(const char *, char *) SV_LoadEntities

public void (*)(edict_t *) SV_UpdatePlayerBaseVelocity

public int (*)(void) SV_AllowSaveGame

public int (*)(edict_t *, edict_t *) SV_TriggerTouch

public unsigned int (*)(void) SV_CheckFeatures

public void (*)(void) DrawDebugTriangles

public void (*)(void) DrawNormalTriangles

public void (*)(void) DrawOrthoTriangles

public void (*)(edict_t *, const float *, float *, float *, const float *, trace_t *) ClipMoveToEntity

public void (*)(struct physent_s *, const float *, float *, float *, const float *, struct pmtrace_s *) ClipPMoveToEntity

public void (*)(void) SV_EndFrame

public void (*)(void) pfnPrepWorldFrame

public void (*)(SAVERESTOREDATA *, int, qboolean) pfnCreateEntitiesInRestoreList

public string_t (*)(const char *) pfnAllocString

public string_t (*)(const char *) pfnMakeString

public const char *(*)(string_t) pfnGetString

public int (*)(struct decallist_s *, edict_t *, qboolean) pfnRestoreDecal

public void (*)(struct playermove_s *, edict_t *) PM_PlayerTouch

public void (*)(struct model_s *, qboolean, const byte *) Mod_ProcessUserData

public void *(*)(edict_t *, const float *, const float *, float *) SV_HullForBsp

public int (*)(edict_t *, float, double) SV_PlayerThink



