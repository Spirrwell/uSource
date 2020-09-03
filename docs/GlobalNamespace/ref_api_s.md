# struct ref_api_s

*Defined at line 246 of ./engine/ref_int.h*

## Members

public int (*)(int, int) EngineGetParm

public cvar_t *(*)(const char *, const char *, int, const char *) Cvar_Get

public cvar_t *(*)(const char *, int) pfnGetCvarPointer

public float (*)(const char *) pfnGetCvarFloat

public const char *(*)(const char *) pfnGetCvarString

public void (*)(const char *, float) Cvar_SetValue

public void (*)(const char *, const char *) Cvar_Set

public void (*)(cvar_t *) Cvar_RegisterVariable

public void (*)(const char *, const char *, int) Cvar_FullSet

public int (*)(const char *, void (*)(void), const char *) Cmd_AddCommand

public void (*)(const char *) Cmd_RemoveCommand

public int (*)(void) Cmd_Argc

public const char *(*)(int) Cmd_Argv

public const char *(*)(void) Cmd_Args

public void (*)(const char *) Cbuf_AddText

public void (*)(const char *) Cbuf_InsertText

public void (*)(void) Cbuf_Execute

public void (*)(const char *, ...) Con_Printf

public void (*)(const char *, ...) Con_DPrintf

public void (*)(const char *, ...) Con_Reportf

public void (*)(int, const char *, ...) Con_NPrintf

public void (*)(struct con_nprint_s *, const char *, ...) Con_NXPrintf

public void (*)(const char *, float) CL_CenterPrint

public void (*)(const char *, int *, int *) Con_DrawStringLen

public int (*)(int, int, const char *, byte *) Con_DrawString

public void (*)(void) CL_DrawCenterPrint

public struct cl_entity_s *(*)(void) GetLocalPlayer

public struct cl_entity_s *(*)(void) GetViewModel

public struct cl_entity_s *(*)(int) GetEntityByIndex

public struct cl_entity_s *(*)(int) R_BeamGetEntity

public struct cl_entity_s *(*)(const vec_t *) CL_GetWaterEntity

public qboolean (*)(cl_entity_t *, int) CL_AddVisibleEntity

public int (*)(struct msurface_s *) Mod_SampleSizeForFace

public qboolean (*)(const vec_t *, const vec_t *, const byte *) Mod_BoxVisible

public struct world_static_s *(*)(void) GetWorld

public mleaf_t *(*)(const vec_t *, mnode_t *) Mod_PointInLeaf

public void (*)(int) Mod_CreatePolygonsForHull

public void (*)(int, vec4_t *, float (*)[3], vec4_t *, float (*)[3], float) R_StudioSlerpBones

public void (*)(int, float, mstudiobone_t *, mstudioanim_t *, float *, vec_t *) R_StudioCalcBoneQuaternion

public void (*)(int, float, mstudiobone_t *, mstudioanim_t *, vec_t *, vec_t *) R_StudioCalcBonePosition

public void *(*)(studiohdr_t *, model_t *, mstudioseqdesc_t *) R_StudioGetAnim

public void (*)(const struct mstudioevent_s *, const cl_entity_t *) pfnStudioEvent

public void (*)(float, qboolean) CL_DrawEFX

public void (*)(double, particle_t *) CL_ThinkParticle

public void (*)(particle_t **) R_FreeDeadParticles

public particle_t *(*)(void) CL_AllocParticleFast

public struct dlight_s *(*)(int) CL_AllocElight

public struct model_s *(*)(enum ref_defaultsprite_e) GetDefaultSprite

public void (*)(struct efrag_s **, int) R_StoreEfrags

public model_t *(*)(const char *, qboolean, qboolean) Mod_ForName

public void *(*)(int, model_t *) Mod_Extradata

public struct model_s *(*)(int) pfnGetModelByIndex

public struct model_s *(*)(void) Mod_GetCurrentLoadingModel

public void (*)(struct model_s *) Mod_SetCurrentLoadingModel

public struct remap_info_s *(*)(cl_entity_t *) CL_GetRemapInfoForEntity

public void (*)(int, int) CL_AllocRemapInfo

public void (*)(struct remap_info_s *) CL_FreeRemapInfo

public void (*)(int, int) CL_UpdateRemapInfo

public void (*)(void) CL_ExtraUpdate

public void (*)(const char *, ...) Host_Error

public void (*)(int) COM_SetRandomSeed

public float (*)(float, float) COM_RandomFloat

public int (*)(int, int) COM_RandomLong

public struct screenfade_s *(*)(void) GetScreenFade

public struct client_textmessage_s *(*)(const char *) pfnTextMessageGet

public void (*)(vec_t *) GetPredictedOrigin

public color24 *(*)(int) CL_GetPaletteColor

public void (*)(int *, int *) CL_GetScreenInfo

public void (*)(int) SetLocalLightLevel

public int (*)(const char *) Sys_CheckParm

public player_info_t *(*)(int) pfnPlayerInfo

public entity_state_t *(*)(int) pfnGetPlayerState

public void *(*)(struct cache_user_s *) Mod_CacheCheck

public void (*)(const char *, struct cache_user_s *) Mod_LoadCacheFile

public void *(*)(int, size_t) Mod_Calloc

public int (*)(int, struct r_studio_interface_s **, struct engine_studio_api_s *) pfnGetStudioModelInterface

public byte *(*)(const char *, const char *, int) _Mem_AllocPool

public void (*)(byte **, const char *, int) _Mem_FreePool

public void *(*)(byte *, size_t, qboolean, const char *, int) _Mem_Alloc

public void *(*)(byte *, void *, size_t, qboolean, const char *, int) _Mem_Realloc

public void (*)(void *, const char *, int) _Mem_Free

public void *(*)(const char *, int, qboolean) COM_LoadLibrary

public void (*)(void *) COM_FreeLibrary

public void *(*)(void *, const char *) COM_GetProcAddress

public byte *(*)(const char *, fs_offset_t *, qboolean) COM_LoadFile

public char *(*)(char *, char *) COM_ParseFile

public int (*)(const char *, int) FS_FileExists

public void (*)(qboolean) FS_AllowDirectPaths

public qboolean (*)(int) R_Init_Video

public void (*)(void) R_Free_Video

public int (*)(int, int) GL_SetAttribute

public int (*)(int, int *) GL_GetAttribute

public void *(*)(const char *) GL_GetProcAddress

public void (*)(void) GL_SwapBuffers

public qboolean (*)(int, int, uint *, uint *, uint *, uint *, uint *) SW_CreateBuffer

public void *(*)(void) SW_LockBuffer

public void (*)(void) SW_UnlockBuffer

public void (*)(float, float) BuildGammaTable

public byte (*)(byte) LightToTexGamma

public qboolean (*)(void) R_DoResetGamma

public lightstyle_t *(*)(int) GetLightStyle

public dlight_t *(*)(int) GetDynamicLight

public dlight_t *(*)(int) GetEntityLight

public int (*)(const float *, float, byte *, qboolean, qboolean) R_FatPVS

public const struct ref_overview_s *(*)(void) GetOverviewParms

public double (*)(void) pfnTime

public struct physent_s *(*)(int) EV_GetPhysent

public struct msurface_s *(*)(int, float *, float *) EV_TraceSurface

public struct pmtrace_s *(*)(float *, float *, int, int, int) PM_TraceLine

public struct pmtrace_s *(*)(float *, float *, int) EV_VisTraceLine

public struct pmtrace_s (*)(vec_t *, vec_t *, int) CL_TraceLine

public struct movevars_s *(*)(void) pfnGetMoveVars

public void (*)(uint) Image_AddCmdFlags

public void (*)(uint) Image_SetForceFlags

public void (*)(void) Image_ClearForceFlags

public qboolean (*)(void) Image_CustomPalette

public qboolean (*)(rgbdata_t **, int, int, uint, float) Image_Process

public rgbdata_t *(*)(const char *, const byte *, size_t) FS_LoadImage

public qboolean (*)(const char *, rgbdata_t *) FS_SaveImage

public rgbdata_t *(*)(rgbdata_t *) FS_CopyImage

public void (*)(rgbdata_t *) FS_FreeImage

public void (*)(byte *) Image_SetMDLPointer

public byte *(*)(void) Image_GetPool

public const struct bpc_desc_s *(*)(int) Image_GetPFDesc

public void (*)(void) pfnDrawNormalTriangles

public void (*)(void) pfnDrawTransparentTriangles

public render_interface_t * drawFuncs



