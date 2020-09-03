# struct engine_studio_api_s

*Defined at line 22 of ./common/r_studioint.h*

## Members

public void *(*)(int, size_t) Mem_Calloc

public void *(*)(struct cache_user_s *) Cache_Check

public void (*)(const char *, struct cache_user_s *) LoadCacheFile

public struct model_s *(*)(const char *, int) Mod_ForName

public void *(*)(struct model_s *) Mod_Extradata

public struct model_s *(*)(int) GetModelByIndex

public struct cl_entity_s *(*)(void) GetCurrentEntity

public struct player_info_s *(*)(int) PlayerInfo

public struct entity_state_s *(*)(int) GetPlayerState

public struct cl_entity_s *(*)(void) GetViewEntity

public void (*)(int *, double *, double *) GetTimes

public struct cvar_s *(*)(const char *) GetCvar

public void (*)(float *, float *, float *, float *) GetViewInfo

public struct model_s *(*)(void) GetChromeSprite

public void (*)(int **, int **) GetModelCounters

public void (*)(float *, float *) GetAliasScale

public float ****(*)(void) StudioGetBoneTransform

public float ****(*)(void) StudioGetLightTransform

public float ***(*)(void) StudioGetAliasTransform

public float ***(*)(void) StudioGetRotationMatrix

public void (*)(int, void **, void **) StudioSetupModel

public int (*)(void) StudioCheckBBox

public void (*)(struct cl_entity_s *, struct alight_s *) StudioDynamicLight

public void (*)(struct alight_s *) StudioEntityLight

public void (*)(struct alight_s *) StudioSetupLighting

public void (*)(void) StudioDrawPoints

public void (*)(void) StudioDrawHulls

public void (*)(void) StudioDrawAbsBBox

public void (*)(void) StudioDrawBones

public void (*)(void *, int) StudioSetupSkin

public void (*)(int, int) StudioSetRemapColors

public struct model_s *(*)(int) SetupPlayerModel

public void (*)(void) StudioClientEvents

public int (*)(void) GetForceFaceFlags

public void (*)(int) SetForceFaceFlags

public void (*)(void *) StudioSetHeader

public void (*)(struct model_s *) SetRenderModel

public void (*)(int) SetupRenderer

public void (*)(void) RestoreRenderer

public void (*)(void) SetChromeOrigin

public int (*)(void) IsHardware

public void (*)(void) GL_StudioDrawShadow

public void (*)(int) GL_SetRenderMode

public void (*)(int) StudioSetRenderamt

public void (*)(int) StudioSetCullState

public void (*)(int, float *, float *, float *, float *) StudioRenderShadow



