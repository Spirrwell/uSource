# struct ref_interface_s

*Defined at line 432 of ./engine/ref_int.h*

 render callbacks



## Members

public qboolean (*)(void) R_Init

public void (*)(void) R_Shutdown

public const char *(*)(void) R_GetConfigName

public void (*)(int) GL_SetupAttributes

public void (*)(void) GL_InitExtensions

public void (*)(void) GL_ClearExtensions

public void (*)(qboolean) R_BeginFrame

public void (*)(void) R_RenderScene

public void (*)(void) R_EndFrame

public void (*)(void) R_PushScene

public void (*)(void) R_PopScene

public void (*)(void) GL_BackendStartFrame

public void (*)(void) GL_BackendEndFrame

public void (*)(void) R_ClearScreen

public void (*)(qboolean) R_AllowFog

public void (*)(int) GL_SetRenderMode

public qboolean (*)(struct cl_entity_s *, int) R_AddEntity

public void (*)(cl_entity_t *) CL_AddCustomBeam

public void (*)(qboolean) R_ProcessEntData

public void (*)(void) R_ShowTextures

public const byte *(*)(unsigned int) R_GetTextureOriginalBuffer

public int (*)(const char *, rgbdata_t *, texFlags_t, qboolean) GL_LoadTextureFromBuffer

public void (*)(int, float, int, int) GL_ProcessTexture

public void (*)(const char *) R_SetupSky

public void (*)(qboolean) R_Set2DMode

public void (*)(float, float, float, float, int, int, const byte *, qboolean) R_DrawStretchRaw

public void (*)(float, float, float, float, float, float, float, float, int) R_DrawStretchPic

public void (*)(int, int, int, int, int) R_DrawTileClear

public void (*)(float, float, float, float, int, int, int, int) FillRGBA

public void (*)(float, float, float, float, int, int, int, int) FillRGBABlend

public qboolean (*)(const char *, int) VID_ScreenShot

public qboolean (*)(const char *, uint, const float *, qboolean) VID_CubemapShot

public colorVec (*)(const float *) R_LightPoint

public void (*)(int, int, int, vec_t *, int, float) R_DecalShoot

public void (*)(int) R_DecalRemoveAll

public int (*)(struct decallist_s *) R_CreateDecalList

public void (*)(void) R_ClearAllDecals

public float (*)(cl_entity_t *, mstudioseqdesc_t *) R_StudioEstimateFrame

public void (*)(cl_entity_t *, double, vec_t *, vec_t *) R_StudioLerpMovement

public void (*)(void) CL_InitStudioAPI

public void (*)(struct mip_s *, struct texture_s *, qboolean) R_InitSkyClouds

public void (*)(msurface_t *) GL_SubdivideSurface

public void (*)(void) CL_RunLightStyles

public void (*)(int *, int *, int *, int, const model_t *) R_GetSpriteParms

public int (*)(const model_t *, int) R_GetSpriteTexture

public void (*)(struct model_s *, const void *, size_t, qboolean *) Mod_LoadMapSprite

public qboolean (*)(model_t *, qboolean, const byte *) Mod_ProcessRenderData

public void (*)(model_t *, void *) Mod_StudioLoadTextures

public void (*)(double, particle_t *, float) CL_DrawParticles

public void (*)(double, particle_t *) CL_DrawTracers

public void (*)(int, BEAM *) CL_DrawBeams

public qboolean (*)(const vec_t *, const vec_t *, qboolean) R_BeamCull

public int (*)(int, int) RefGetParm

public void (*)(int, float *, float *) GetDetailScaleForTexture

public void (*)(int, byte *, byte *, byte *, byte *) GetExtraParmsForTexture

public float (*)(void) GetFrameTime

public void (*)(struct cl_entity_s *) R_SetCurrentEntity

public void (*)(struct model_s *) R_SetCurrentModel

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

public void (*)(int, int, int, int, int, const byte *) AVI_UploadRawFrame

public void (*)(int, unsigned int) GL_Bind

public void (*)(int) GL_SelectTexture

public void (*)(const float *) GL_LoadTextureMatrix

public void (*)(void) GL_TexMatrixIdentity

public void (*)(int) GL_CleanUpTextureUnits

public void (*)(unsigned int, unsigned int) GL_TexGen

public void (*)(unsigned int) GL_TextureTarget

public void (*)(unsigned int) GL_TexCoordArrayMode

public void (*)(int, int, int, int) GL_UpdateTexSize

public void (*)(void) GL_Reserved0

public void (*)(void) GL_Reserved1

public void (*)(const struct ref_viewpass_s *, qboolean, float) GL_DrawParticles

public colorVec (*)(const float *, const float *, float *, float *) LightVec

public struct mstudiotex_s *(*)(struct cl_entity_s *) StudioGetTexture

public void (*)(const struct ref_viewpass_s *) GL_RenderFrame

public void (*)(const float *, const float *) GL_OrthoBounds

public qboolean (*)(char *, size_t) R_SpeedsMessage

public byte *(*)(void) Mod_GetCurrentVis

public void (*)(void) R_NewMap

public void (*)(void) R_ClearScene

public void (*)(int) TriRenderMode

public void (*)(int) Begin

public void (*)(void) End

public void (*)(float, float, float, float) Color4f

public void (*)(unsigned char, unsigned char, unsigned char, unsigned char) Color4ub

public void (*)(float, float) TexCoord2f

public void (*)(const float *) Vertex3fv

public void (*)(float, float, float) Vertex3f

public int (*)(const float *, float *) WorldToScreen

public void (*)(float *, float, float, int) Fog

public void (*)(const float *, float *) ScreenToWorld

public void (*)(const int, float *) GetMatrix

public void (*)(float, int) FogParams

public void (*)(TRICULLSTYLE) CullFace

public void (*)(void) VGUI_DrawInit

public void (*)(void) VGUI_DrawShutdown

public void (*)(int *) VGUI_SetupDrawingText

public void (*)(int *) VGUI_SetupDrawingRect

public void (*)(int *) VGUI_SetupDrawingImage

public void (*)(int) VGUI_BindTexture

public void (*)(qboolean) VGUI_EnableTexture

public void (*)(int, int, int) VGUI_CreateTexture

public void (*)(int, const char *, int, int) VGUI_UploadTexture

public void (*)(int, int, int, const byte *, int, int) VGUI_UploadTextureBlock

public void (*)(const vpoint_t *, const vpoint_t *) VGUI_DrawQuad

public void (*)(int *, int *) VGUI_GetTextureSizes

public int (*)(void) VGUI_GenerateTexture



