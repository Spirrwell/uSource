# class CGLRenderBackend

*Defined at line 487 of ./rendersystem/r_context.cpp*

Inherits from IRenderBackend



## Functions

### Init

*public _Bool Init()*

*Defined at line 490 of ./rendersystem/r_context.cpp*

### PreInit

*public _Bool PreInit()*

*Defined at line 491 of ./rendersystem/r_context.cpp*

### Shutdown

*public void Shutdown()*

*Defined at line 492 of ./rendersystem/r_context.cpp*

### GetName

*public const char * GetName()*

*Defined at line 493 of ./rendersystem/r_context.cpp*

### GetParentInterface

*public const char * GetParentInterface()*

*Defined at line 494 of ./rendersystem/r_context.cpp*

### R_Init

*public qboolean R_Init()*

*Defined at line 496 of ./rendersystem/r_context.cpp*

### R_Shutdown

*public void R_Shutdown()*

*Defined at line 501 of ./rendersystem/r_context.cpp*

### R_GetConfigName

*public const char * R_GetConfigName()*

*Defined at line 506 of ./rendersystem/r_context.cpp*

### GL_SetupAttributes

*public void GL_SetupAttributes(int safegl)*

*Defined at line 511 of ./rendersystem/r_context.cpp*

### GL_InitExtensions

*public void GL_InitExtensions()*

*Defined at line 516 of ./rendersystem/r_context.cpp*

### GL_ClearExtensions

*public void GL_ClearExtensions()*

*Defined at line 521 of ./rendersystem/r_context.cpp*

### R_BeginFrame

*public void R_BeginFrame(qboolean clearScene)*

*Defined at line 526 of ./rendersystem/r_context.cpp*

### R_RenderScene

*public void R_RenderScene()*

*Defined at line 531 of ./rendersystem/r_context.cpp*

### R_EndFrame

*public void R_EndFrame()*

*Defined at line 536 of ./rendersystem/r_context.cpp*

### R_PushScene

*public void R_PushScene()*

*Defined at line 541 of ./rendersystem/r_context.cpp*

### R_PopScene

*public void R_PopScene()*

*Defined at line 546 of ./rendersystem/r_context.cpp*

### GL_BackendStartFrame

*public void GL_BackendStartFrame()*

*Defined at line 551 of ./rendersystem/r_context.cpp*

### GL_BackendEndFrame

*public void GL_BackendEndFrame()*

*Defined at line 556 of ./rendersystem/r_context.cpp*

### R_ClearScreen

*public void R_ClearScreen()*

*Defined at line 561 of ./rendersystem/r_context.cpp*

### R_AllowFog

*public void R_AllowFog(qboolean allow)*

*Defined at line 566 of ./rendersystem/r_context.cpp*

### GL_SetRenderMode

*public void GL_SetRenderMode(int renderMode)*

*Defined at line 571 of ./rendersystem/r_context.cpp*

### R_AddEntity

*public qboolean R_AddEntity(struct cl_entity_s * clent, int type)*

*Defined at line 576 of ./rendersystem/r_context.cpp*

### CL_AddCustomBeam

*public void CL_AddCustomBeam(cl_entity_t * pEnvBeam)*

*Defined at line 581 of ./rendersystem/r_context.cpp*

### R_ProcessEntData

*public void R_ProcessEntData(qboolean allocate)*

*Defined at line 586 of ./rendersystem/r_context.cpp*

### R_ShowTextures

*public void R_ShowTextures()*

*Defined at line 591 of ./rendersystem/r_context.cpp*

### R_GetTextureOriginalBuffer

*public const byte * R_GetTextureOriginalBuffer(unsigned int idx)*

*Defined at line 596 of ./rendersystem/r_context.cpp*

### GL_LoadTextureFromBuffer

*public int GL_LoadTextureFromBuffer(const char * name, rgbdata_t * pic, texFlags_t flags, qboolean update)*

*Defined at line 601 of ./rendersystem/r_context.cpp*

### GL_ProcessTexture

*public void GL_ProcessTexture(int texnum, float gamma, int topColor, int bottomColor)*

*Defined at line 606 of ./rendersystem/r_context.cpp*

### R_SetupSky

*public void R_SetupSky(const char * skyname)*

*Defined at line 611 of ./rendersystem/r_context.cpp*

### R_Set2DMode

*public void R_Set2DMode(qboolean enable)*

*Defined at line 616 of ./rendersystem/r_context.cpp*

### R_DrawStretchRaw

*public void R_DrawStretchRaw(float x, float y, float w, float h, int cols, int rows, const byte * data, qboolean dirty)*

*Defined at line 621 of ./rendersystem/r_context.cpp*

### R_DrawStretchPic

*public void R_DrawStretchPic(float x, float y, float w, float h, float s1, float t1, float s2, float t2, int texnum)*

*Defined at line 626 of ./rendersystem/r_context.cpp*

### R_DrawTileClear

*public void R_DrawTileClear(int texnum, int x, int y, int w, int h)*

*Defined at line 631 of ./rendersystem/r_context.cpp*

### FillRGBA

*public void FillRGBA(float x, float y, float w, float h, int r, int g, int b, int a)*

*Defined at line 636 of ./rendersystem/r_context.cpp*

### FillRGBABlend

*public void FillRGBABlend(float x, float y, float w, float h, int r, int g, int b, int a)*

*Defined at line 641 of ./rendersystem/r_context.cpp*

### VID_ScreenShot

*public qboolean VID_ScreenShot(const char * filename, int shot_type)*

*Defined at line 646 of ./rendersystem/r_context.cpp*

### VID_CubemapShot

*public qboolean VID_CubemapShot(const char * base, uint size, const float * vieworg, qboolean skyshot)*

*Defined at line 651 of ./rendersystem/r_context.cpp*

### R_LightPoint

*public  R_LightPoint(const float * p)*

*Defined at line 656 of ./rendersystem/r_context.cpp*

### R_DecalShoot

*public void R_DecalShoot(int textureIndex, int entityIndex, int modelIndex, vec3_t pos, int flags, float scale)*

*Defined at line 661 of ./rendersystem/r_context.cpp*

### R_DecalRemoveAll

*public void R_DecalRemoveAll(int texture)*

*Defined at line 666 of ./rendersystem/r_context.cpp*

### R_CreateDecalList

*public int R_CreateDecalList(struct decallist_s * pList)*

*Defined at line 671 of ./rendersystem/r_context.cpp*

### R_ClearAllDecals

*public void R_ClearAllDecals()*

*Defined at line 676 of ./rendersystem/r_context.cpp*

### R_StudioEstimateFrame

*public float R_StudioEstimateFrame(cl_entity_t * e, mstudioseqdesc_t * pseqdesc)*

*Defined at line 681 of ./rendersystem/r_context.cpp*

### R_StudioLerpMovement

*public void R_StudioLerpMovement(cl_entity_t * e, double time, vec3_t origin, vec3_t angles)*

*Defined at line 686 of ./rendersystem/r_context.cpp*

### CL_InitStudioAPI

*public void CL_InitStudioAPI()*

*Defined at line 691 of ./rendersystem/r_context.cpp*

### R_InitSkyClouds

*public void R_InitSkyClouds(struct mip_s * mt, struct texture_s * tx, qboolean custom_palette)*

*Defined at line 696 of ./rendersystem/r_context.cpp*

### GL_SubdivideSurface

*public void GL_SubdivideSurface(msurface_t * fa)*

*Defined at line 701 of ./rendersystem/r_context.cpp*

### CL_RunLightStyles

*public void CL_RunLightStyles()*

*Defined at line 706 of ./rendersystem/r_context.cpp*

### R_GetSpriteParms

*public void R_GetSpriteParms(int * frameWidth, int * frameHeight, int * numFrames, int currentFrame, const model_t * pSprite)*

*Defined at line 711 of ./rendersystem/r_context.cpp*

### R_GetSpriteTexture

*public int R_GetSpriteTexture(const model_t * m_pSpriteModel, int frame)*

*Defined at line 716 of ./rendersystem/r_context.cpp*

### Mod_LoadMapSprite

*public void Mod_LoadMapSprite(struct model_s * mod, const void * buffer, size_t size, qboolean * loaded)*

*Defined at line 721 of ./rendersystem/r_context.cpp*

### Mod_ProcessRenderData

*public qboolean Mod_ProcessRenderData(model_t * mod, qboolean create, const byte * buffer)*

*Defined at line 726 of ./rendersystem/r_context.cpp*

### Mod_StudioLoadTextures

*public void Mod_StudioLoadTextures(model_t * mod, void * data)*

*Defined at line 731 of ./rendersystem/r_context.cpp*

### CL_DrawParticles

*public void CL_DrawParticles(double frametime, particle_t * particles, float partsize)*

*Defined at line 736 of ./rendersystem/r_context.cpp*

### CL_DrawTracers

*public void CL_DrawTracers(double frametime, particle_t * tracers)*

*Defined at line 741 of ./rendersystem/r_context.cpp*

### CL_DrawBeams

*public void CL_DrawBeams(int fTrans, BEAM * beams)*

*Defined at line 746 of ./rendersystem/r_context.cpp*

### R_BeamCull

*public qboolean R_BeamCull(const vec3_t start, const vec3_t end, qboolean pvsOnly)*

*Defined at line 751 of ./rendersystem/r_context.cpp*

### RefGetParm

*public int RefGetParm(int parm, int arg)*

*Defined at line 756 of ./rendersystem/r_context.cpp*

### GetDetailScaleForTexture

*public void GetDetailScaleForTexture(int texture, float * xScale, float * yScale)*

*Defined at line 761 of ./rendersystem/r_context.cpp*

### GetExtraParmsForTexture

*public void GetExtraParmsForTexture(int texture, byte * red, byte * green, byte * blue, byte * alpha)*

*Defined at line 766 of ./rendersystem/r_context.cpp*

### GetFrameTime

*public float GetFrameTime()*

*Defined at line 771 of ./rendersystem/r_context.cpp*

### R_SetCurrentEntity

*public void R_SetCurrentEntity(struct cl_entity_s * ent)*

*Defined at line 776 of ./rendersystem/r_context.cpp*

### R_SetCurrentModel

*public void R_SetCurrentModel(struct model_s * mod)*

*Defined at line 781 of ./rendersystem/r_context.cpp*

### GL_FindTexture

*public int GL_FindTexture(const char * name)*

*Defined at line 786 of ./rendersystem/r_context.cpp*

### GL_TextureName

*public const char * GL_TextureName(unsigned int texnum)*

*Defined at line 791 of ./rendersystem/r_context.cpp*

### GL_TextureData

*public const byte * GL_TextureData(unsigned int texnum)*

*Defined at line 796 of ./rendersystem/r_context.cpp*

### GL_LoadTexture

*public int GL_LoadTexture(const char * name, const byte * buf, size_t size, int flags)*

*Defined at line 801 of ./rendersystem/r_context.cpp*

### GL_CreateTexture

*public int GL_CreateTexture(const char * name, int width, int height, const void * buffer, texFlags_t flags)*

*Defined at line 806 of ./rendersystem/r_context.cpp*

### GL_LoadTextureArray

*public int GL_LoadTextureArray(const char ** names, int flags)*

*Defined at line 811 of ./rendersystem/r_context.cpp*

### GL_CreateTextureArray

*public int GL_CreateTextureArray(const char * name, int width, int height, int depth, const void * buffer, texFlags_t flags)*

*Defined at line 816 of ./rendersystem/r_context.cpp*

### GL_FreeTexture

*public void GL_FreeTexture(unsigned int texnum)*

*Defined at line 821 of ./rendersystem/r_context.cpp*

### DrawSingleDecal

*public void DrawSingleDecal(struct decal_s * pDecal, struct msurface_s * fa)*

*Defined at line 826 of ./rendersystem/r_context.cpp*

### R_DecalSetupVerts

*public float * R_DecalSetupVerts(struct decal_s * pDecal, struct msurface_s * surf, int texture, int * outCount)*

*Defined at line 831 of ./rendersystem/r_context.cpp*

### R_EntityRemoveDecals

*public void R_EntityRemoveDecals(struct model_s * mod)*

*Defined at line 836 of ./rendersystem/r_context.cpp*

### AVI_UploadRawFrame

*public void AVI_UploadRawFrame(int texture, int cols, int rows, int width, int height, const byte * data)*

*Defined at line 841 of ./rendersystem/r_context.cpp*

### GL_Bind

*public void GL_Bind(int tmu, unsigned int texnum)*

*Defined at line 846 of ./rendersystem/r_context.cpp*

### GL_SelectTexture

*public void GL_SelectTexture(int tmu)*

*Defined at line 851 of ./rendersystem/r_context.cpp*

### GL_LoadTextureMatrix

*public void GL_LoadTextureMatrix(const float * glmatrix)*

*Defined at line 856 of ./rendersystem/r_context.cpp*

### GL_TexMatrixIdentity

*public void GL_TexMatrixIdentity()*

*Defined at line 861 of ./rendersystem/r_context.cpp*

### GL_CleanUpTextureUnits

*public void GL_CleanUpTextureUnits(int last)*

*Defined at line 866 of ./rendersystem/r_context.cpp*

### GL_TexGen

*public void GL_TexGen(unsigned int coord, unsigned int mode)*

*Defined at line 871 of ./rendersystem/r_context.cpp*

### GL_TextureTarget

*public void GL_TextureTarget(unsigned int target)*

*Defined at line 876 of ./rendersystem/r_context.cpp*

### GL_TexCoordArrayMode

*public void GL_TexCoordArrayMode(unsigned int texmode)*

*Defined at line 881 of ./rendersystem/r_context.cpp*

### GL_UpdateTexSize

*public void GL_UpdateTexSize(int texnum, int width, int height, int depth)*

*Defined at line 886 of ./rendersystem/r_context.cpp*

### GL_Reserved0

*public void GL_Reserved0()*

*Defined at line 891 of ./rendersystem/r_context.cpp*

### GL_Reserved1

*public void GL_Reserved1()*

*Defined at line 896 of ./rendersystem/r_context.cpp*

### GL_DrawParticles

*public void GL_DrawParticles(const struct ref_viewpass_s * rvp, qboolean trans_pass, float frametime)*

*Defined at line 901 of ./rendersystem/r_context.cpp*

### LightVec

*public  LightVec(const float * start, const float * end, float * lightspot, float * lightvec)*

*Defined at line 906 of ./rendersystem/r_context.cpp*

### StudioGetTexture

*public struct mstudiotex_s * StudioGetTexture(struct cl_entity_s * e)*

*Defined at line 911 of ./rendersystem/r_context.cpp*

### GL_RenderFrame

*public void GL_RenderFrame(const struct ref_viewpass_s * rvp)*

*Defined at line 916 of ./rendersystem/r_context.cpp*

### GL_OrthoBounds

*public void GL_OrthoBounds(const float * mins, const float * maxs)*

*Defined at line 921 of ./rendersystem/r_context.cpp*

### R_SpeedsMessage

*public qboolean R_SpeedsMessage(char * out, size_t size)*

*Defined at line 926 of ./rendersystem/r_context.cpp*

### Mod_GetCurrentVis

*public byte * Mod_GetCurrentVis()*

*Defined at line 931 of ./rendersystem/r_context.cpp*

### R_NewMap

*public void R_NewMap()*

*Defined at line 936 of ./rendersystem/r_context.cpp*

### R_ClearScene

*public void R_ClearScene()*

*Defined at line 941 of ./rendersystem/r_context.cpp*

### TriRenderMode

*public void TriRenderMode(int mode)*

*Defined at line 946 of ./rendersystem/r_context.cpp*

### Begin

*public void Begin(int primitiveCode)*

*Defined at line 951 of ./rendersystem/r_context.cpp*

### End

*public void End()*

*Defined at line 956 of ./rendersystem/r_context.cpp*

### Color4f

*public void Color4f(float r, float g, float b, float a)*

*Defined at line 961 of ./rendersystem/r_context.cpp*

### Color4ub

*public void Color4ub(unsigned char r, unsigned char g, unsigned char b, unsigned char a)*

*Defined at line 966 of ./rendersystem/r_context.cpp*

### TexCoord2f

*public void TexCoord2f(float u, float v)*

*Defined at line 971 of ./rendersystem/r_context.cpp*

### Vertex3fv

*public void Vertex3fv(const float * worldPnt)*

*Defined at line 976 of ./rendersystem/r_context.cpp*

### Vertex3f

*public void Vertex3f(float x, float y, float z)*

*Defined at line 981 of ./rendersystem/r_context.cpp*

### WorldToScreen

*public int WorldToScreen(const float * world, float * screen)*

*Defined at line 986 of ./rendersystem/r_context.cpp*

### Fog

*public void Fog(float [3] flFogColor, float flStart, float flEnd, int bOn)*

*Defined at line 991 of ./rendersystem/r_context.cpp*

### ScreenToWorld

*public void ScreenToWorld(const float * screen, float * world)*

*Defined at line 996 of ./rendersystem/r_context.cpp*

### GetMatrix

*public void GetMatrix(const int pname, float * matrix)*

*Defined at line 1001 of ./rendersystem/r_context.cpp*

### FogParams

*public void FogParams(float flDensity, int iFogSkybox)*

*Defined at line 1006 of ./rendersystem/r_context.cpp*

### CullFace

*public void CullFace(TRICULLSTYLE mode)*

*Defined at line 1011 of ./rendersystem/r_context.cpp*

### VGUI_DrawInit

*public void VGUI_DrawInit()*

*Defined at line 1016 of ./rendersystem/r_context.cpp*

### VGUI_DrawShutdown

*public void VGUI_DrawShutdown()*

*Defined at line 1021 of ./rendersystem/r_context.cpp*

### VGUI_SetupDrawingText

*public void VGUI_SetupDrawingText(int * pColor)*

*Defined at line 1026 of ./rendersystem/r_context.cpp*

### VGUI_SetupDrawingRect

*public void VGUI_SetupDrawingRect(int * pColor)*

*Defined at line 1031 of ./rendersystem/r_context.cpp*

### VGUI_SetupDrawingImage

*public void VGUI_SetupDrawingImage(int * pColor)*

*Defined at line 1036 of ./rendersystem/r_context.cpp*

### VGUI_BindTexture

*public void VGUI_BindTexture(int id)*

*Defined at line 1041 of ./rendersystem/r_context.cpp*

### VGUI_EnableTexture

*public void VGUI_EnableTexture(qboolean enable)*

*Defined at line 1046 of ./rendersystem/r_context.cpp*

### VGUI_CreateTexture

*public void VGUI_CreateTexture(int id, int width, int height)*

*Defined at line 1051 of ./rendersystem/r_context.cpp*

### VGUI_UploadTexture

*public void VGUI_UploadTexture(int id, const char * buffer, int width, int height)*

*Defined at line 1056 of ./rendersystem/r_context.cpp*

### VGUI_UploadTextureBlock

*public void VGUI_UploadTextureBlock(int id, int drawX, int drawY, const byte * rgba, int blockWidth, int blockHeight)*

*Defined at line 1061 of ./rendersystem/r_context.cpp*

### VGUI_DrawQuad

*public void VGUI_DrawQuad(const vpoint_t * ul, const vpoint_t * lr)*

*Defined at line 1066 of ./rendersystem/r_context.cpp*

### VGUI_GetTextureSizes

*public void VGUI_GetTextureSizes(int * width, int * height)*

*Defined at line 1071 of ./rendersystem/r_context.cpp*

### VGUI_GenerateTexture

*public int VGUI_GenerateTexture()*

*Defined at line 1076 of ./rendersystem/r_context.cpp*



