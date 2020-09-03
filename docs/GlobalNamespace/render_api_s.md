# struct render_api_s

*Defined at line 158 of ./common/render_api.h*

## Members

public int (*)(int, int) RenderGetParm

public void (*)(int, float *, float *) GetDetailScaleForTexture

public void (*)(int, byte *, byte *, byte *, byte *) GetExtraParmsForTexture

public lightstyle_t *(*)(int) GetLightStyle

public dlight_t *(*)(int) GetDynamicLight

public dlight_t *(*)(int) GetEntityLight

public byte (*)(byte) LightToTexGamma

public float (*)(void) GetFrameTime

public void (*)(struct cl_entity_s *) R_SetCurrentEntity

public void (*)(struct model_s *) R_SetCurrentModel

public int (*)(const float *, float, byte *, qboolean, qboolean) R_FatPVS

public void (*)(struct efrag_s **, int) R_StoreEfrags

public int (*)(const char *) GL_FindTexture

public const char *(*)(unsigned int) GL_TextureName

public const byte *(*)(unsigned int) GL_TextureData

public int (*)(const char *, const byte *, size_t, int) GL_LoadTexture

public int (*)(const char *, int, int, const void *, texFlags_t) GL_CreateTexture

public int (*)(const char **, int) GL_LoadTextureArray

public int (*)(const char *, int, int, int, const void *, texFlags_t) GL_CreateTextureArray

public void (*)(unsigned int) GL_FreeTexture

public void (*)(struct decal_s *, struct msurface_s *) DrawSingleDecal

public float *(*)(struct decal_s *, struct msurface_s *, int, int *) R_DecalSetupVerts

public void (*)(struct model_s *) R_EntityRemoveDecals

public void *(*)(const char *, qboolean) AVI_LoadVideo

public int (*)(void *, long *, long *, float *) AVI_GetVideoInfo

public long (*)(void *, float) AVI_GetVideoFrameNumber

public byte *(*)(void *, long) AVI_GetVideoFrame

public void (*)(int, int, int, int, int, const byte *) AVI_UploadRawFrame

public void (*)(void *) AVI_FreeVideo

public int (*)(void *) AVI_IsActive

public void (*)(void *, int, float, float, float) AVI_StreamSound

public void (*)(void) AVI_Reserved0

public void (*)(void) AVI_Reserved1

public void (*)(int, unsigned int) GL_Bind

public void (*)(int) GL_SelectTexture

public void (*)(const float *) GL_LoadTextureMatrix

public void (*)(void) GL_TexMatrixIdentity

public void (*)(int) GL_CleanUpTextureUnits

public void (*)(unsigned int, unsigned int) GL_TexGen

public void (*)(unsigned int) GL_TextureTarget

public void (*)(unsigned int) GL_TexCoordArrayMode

public void *(*)(const char *) GL_GetProcAddress

public void (*)(int, int, int, int) GL_UpdateTexSize

public void (*)(void) GL_Reserved0

public void (*)(void) GL_Reserved1

public void (*)(const struct ref_viewpass_s *, qboolean, float) GL_DrawParticles

public void (*)(const float *, const char *, qboolean, int) EnvShot

public int (*)(const char *, unsigned int) SPR_LoadExt

public colorVec (*)(const float *, const float *, float *, float *) LightVec

public struct mstudiotex_s *(*)(struct cl_entity_s *) StudioGetTexture

public const struct ref_overview_s *(*)(void) GetOverviewParms

public const char *(*)(int) GetFileByIndex

public int (*)(const char *, const void *, int) pfnSaveFile

public void (*)(void) R_Reserved0

public void *(*)(size_t, const char *, const int) pfnMemAlloc

public void (*)(void *, const char *, const int) pfnMemFree

public char **(*)(const char *, int *, int) pfnGetFilesList

public unsigned int (*)(const void *, const int) pfnFileBufferCRC32

public int (*)(const char *, const char *, int *) COM_CompareFileTime

public void (*)(const char *, ...) Host_Error

public void *(*)(int) pfnGetModel

public float (*)(void) pfnTime

public void (*)(const char *, const char *) Cvar_Set

public void (*)(float) S_FadeMusicVolume

public void (*)(int) SetRandomSeed



