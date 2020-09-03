# class IRenderBackend

*Defined at line 622 of ./engine/ref_int.h*

Inherits from IAppInterface



## Functions

### R_Init

*public qboolean R_Init()*

### R_Shutdown

*public void R_Shutdown()*

### R_GetConfigName

*public const char * R_GetConfigName()*

### GL_SetupAttributes

*public void GL_SetupAttributes(int safegl)*

### GL_InitExtensions

*public void GL_InitExtensions()*

### GL_ClearExtensions

*public void GL_ClearExtensions()*

### R_BeginFrame

*public void R_BeginFrame(qboolean clearScene)*

### R_RenderScene

*public void R_RenderScene()*

### R_EndFrame

*public void R_EndFrame()*

### R_PushScene

*public void R_PushScene()*

### R_PopScene

*public void R_PopScene()*

### GL_BackendStartFrame

*public void GL_BackendStartFrame()*

### GL_BackendEndFrame

*public void GL_BackendEndFrame()*

### R_ClearScreen

*public void R_ClearScreen()*

### R_AllowFog

*public void R_AllowFog(qboolean allow)*

### GL_SetRenderMode

*public void GL_SetRenderMode(int renderMode)*

### R_AddEntity

*public qboolean R_AddEntity(struct cl_entity_s * clent, int type)*

### CL_AddCustomBeam

*public void CL_AddCustomBeam(cl_entity_t * pEnvBeam)*

### R_ProcessEntData

*public void R_ProcessEntData(qboolean allocate)*

### R_ShowTextures

*public void R_ShowTextures()*

### R_GetTextureOriginalBuffer

*public const byte * R_GetTextureOriginalBuffer(unsigned int idx)*

### GL_LoadTextureFromBuffer

*public int GL_LoadTextureFromBuffer(const char * name, rgbdata_t * pic, texFlags_t flags, qboolean update)*

### GL_ProcessTexture

*public void GL_ProcessTexture(int texnum, float gamma, int topColor, int bottomColor)*

### R_SetupSky

*public void R_SetupSky(const char * skyname)*

### R_Set2DMode

*public void R_Set2DMode(qboolean enable)*

### R_DrawStretchRaw

*public void R_DrawStretchRaw(float x, float y, float w, float h, int cols, int rows, const byte * data, qboolean dirty)*

### R_DrawStretchPic

*public void R_DrawStretchPic(float x, float y, float w, float h, float s1, float t1, float s2, float t2, int texnum)*

### R_DrawTileClear

*public void R_DrawTileClear(int texnum, int x, int y, int w, int h)*

### FillRGBA

*public void FillRGBA(float x, float y, float w, float h, int r, int g, int b, int a)*

### FillRGBABlend

*public void FillRGBABlend(float x, float y, float w, float h, int r, int g, int b, int a)*

### VID_ScreenShot

*public qboolean VID_ScreenShot(const char * filename, int shot_type)*

### VID_CubemapShot

*public qboolean VID_CubemapShot(const char * base, uint size, const float * vieworg, qboolean skyshot)*

### R_LightPoint

*public  R_LightPoint(const float * p)*

### R_DecalShoot

*public void R_DecalShoot(int textureIndex, int entityIndex, int modelIndex, vec3_t pos, int flags, float scale)*

### R_DecalRemoveAll

*public void R_DecalRemoveAll(int texture)*

### R_CreateDecalList

*public int R_CreateDecalList(struct decallist_s * pList)*

### R_ClearAllDecals

*public void R_ClearAllDecals()*

### R_StudioEstimateFrame

*public float R_StudioEstimateFrame(cl_entity_t * e, mstudioseqdesc_t * pseqdesc)*

### R_StudioLerpMovement

*public void R_StudioLerpMovement(cl_entity_t * e, double time, vec3_t origin, vec3_t angles)*

### CL_InitStudioAPI

*public void CL_InitStudioAPI()*

### R_InitSkyClouds

*public void R_InitSkyClouds(struct mip_s * mt, struct texture_s * tx, qboolean custom_palette)*

### GL_SubdivideSurface

*public void GL_SubdivideSurface(msurface_t * fa)*

### CL_RunLightStyles

*public void CL_RunLightStyles()*

### R_GetSpriteParms

*public void R_GetSpriteParms(int * frameWidth, int * frameHeight, int * numFrames, int currentFrame, const model_t * pSprite)*

### R_GetSpriteTexture

*public int R_GetSpriteTexture(const model_t * m_pSpriteModel, int frame)*

### Mod_LoadMapSprite

*public void Mod_LoadMapSprite(struct model_s * mod, const void * buffer, size_t size, qboolean * loaded)*

### Mod_ProcessRenderData

*public qboolean Mod_ProcessRenderData(model_t * mod, qboolean create, const byte * buffer)*

### Mod_StudioLoadTextures

*public void Mod_StudioLoadTextures(model_t * mod, void * data)*

### CL_DrawParticles

*public void CL_DrawParticles(double frametime, particle_t * particles, float partsize)*

### CL_DrawTracers

*public void CL_DrawTracers(double frametime, particle_t * tracers)*

### CL_DrawBeams

*public void CL_DrawBeams(int fTrans, BEAM * beams)*

### R_BeamCull

*public qboolean R_BeamCull(const vec3_t start, const vec3_t end, qboolean pvsOnly)*

### RefGetParm

*public int RefGetParm(int parm, int arg)*

### GetDetailScaleForTexture

*public void GetDetailScaleForTexture(int texture, float * xScale, float * yScale)*

### GetExtraParmsForTexture

*public void GetExtraParmsForTexture(int texture, byte * red, byte * green, byte * blue, byte * alpha)*

### GetFrameTime

*public float GetFrameTime()*

### R_SetCurrentEntity

*public void R_SetCurrentEntity(struct cl_entity_s * ent)*

### R_SetCurrentModel

*public void R_SetCurrentModel(struct model_s * mod)*

### GL_FindTexture

*public int GL_FindTexture(const char * name)*

### GL_TextureName

*public const char * GL_TextureName(unsigned int texnum)*

### GL_TextureData

*public const byte * GL_TextureData(unsigned int texnum)*

### GL_LoadTexture

*public int GL_LoadTexture(const char * name, const byte * buf, size_t size, int flags)*

### GL_CreateTexture

*public int GL_CreateTexture(const char * name, int width, int height, const void * buffer, texFlags_t flags)*

### GL_LoadTextureArray

*public int GL_LoadTextureArray(const char ** names, int flags)*

### GL_CreateTextureArray

*public int GL_CreateTextureArray(const char * name, int width, int height, int depth, const void * buffer, texFlags_t flags)*

### GL_FreeTexture

*public void GL_FreeTexture(unsigned int texnum)*

### DrawSingleDecal

*public void DrawSingleDecal(struct decal_s * pDecal, struct msurface_s * fa)*

### R_DecalSetupVerts

*public float * R_DecalSetupVerts(struct decal_s * pDecal, struct msurface_s * surf, int texture, int * outCount)*

### R_EntityRemoveDecals

*public void R_EntityRemoveDecals(struct model_s * mod)*

### AVI_UploadRawFrame

*public void AVI_UploadRawFrame(int texture, int cols, int rows, int width, int height, const byte * data)*

### GL_Bind

*public void GL_Bind(int tmu, unsigned int texnum)*

### GL_SelectTexture

*public void GL_SelectTexture(int tmu)*

### GL_LoadTextureMatrix

*public void GL_LoadTextureMatrix(const float * glmatrix)*

### GL_TexMatrixIdentity

*public void GL_TexMatrixIdentity()*

### GL_CleanUpTextureUnits

*public void GL_CleanUpTextureUnits(int last)*

### GL_TexGen

*public void GL_TexGen(unsigned int coord, unsigned int mode)*

### GL_TextureTarget

*public void GL_TextureTarget(unsigned int target)*

### GL_TexCoordArrayMode

*public void GL_TexCoordArrayMode(unsigned int texmode)*

### GL_UpdateTexSize

*public void GL_UpdateTexSize(int texnum, int width, int height, int depth)*

### GL_Reserved0

*public void GL_Reserved0()*

### GL_Reserved1

*public void GL_Reserved1()*

### GL_DrawParticles

*public void GL_DrawParticles(const struct ref_viewpass_s * rvp, qboolean trans_pass, float frametime)*

### LightVec

*public  LightVec(const float * start, const float * end, float * lightspot, float * lightvec)*

### StudioGetTexture

*public struct mstudiotex_s * StudioGetTexture(struct cl_entity_s * e)*

### GL_RenderFrame

*public void GL_RenderFrame(const struct ref_viewpass_s * rvp)*

### GL_OrthoBounds

*public void GL_OrthoBounds(const float * mins, const float * maxs)*

### R_SpeedsMessage

*public qboolean R_SpeedsMessage(char * out, size_t size)*

### Mod_GetCurrentVis

*public byte * Mod_GetCurrentVis()*

### R_NewMap

*public void R_NewMap()*

### R_ClearScene

*public void R_ClearScene()*

### TriRenderMode

*public void TriRenderMode(int mode)*

### Begin

*public void Begin(int primitiveCode)*

### End

*public void End()*

### Color4f

*public void Color4f(float r, float g, float b, float a)*

### Color4ub

*public void Color4ub(unsigned char r, unsigned char g, unsigned char b, unsigned char a)*

### TexCoord2f

*public void TexCoord2f(float u, float v)*

### Vertex3fv

*public void Vertex3fv(const float * worldPnt)*

### Vertex3f

*public void Vertex3f(float x, float y, float z)*

### WorldToScreen

*public int WorldToScreen(const float * world, float * screen)*

### Fog

*public void Fog(float [3] flFogColor, float flStart, float flEnd, int bOn)*

### ScreenToWorld

*public void ScreenToWorld(const float * screen, float * world)*

### GetMatrix

*public void GetMatrix(const int pname, float * matrix)*

### FogParams

*public void FogParams(float flDensity, int iFogSkybox)*

### CullFace

*public void CullFace(TRICULLSTYLE mode)*

### VGUI_DrawInit

*public void VGUI_DrawInit()*

### VGUI_DrawShutdown

*public void VGUI_DrawShutdown()*

### VGUI_SetupDrawingText

*public void VGUI_SetupDrawingText(int * pColor)*

### VGUI_SetupDrawingRect

*public void VGUI_SetupDrawingRect(int * pColor)*

### VGUI_SetupDrawingImage

*public void VGUI_SetupDrawingImage(int * pColor)*

### VGUI_BindTexture

*public void VGUI_BindTexture(int id)*

### VGUI_EnableTexture

*public void VGUI_EnableTexture(qboolean enable)*

### VGUI_CreateTexture

*public void VGUI_CreateTexture(int id, int width, int height)*

### VGUI_UploadTexture

*public void VGUI_UploadTexture(int id, const char * buffer, int width, int height)*

### VGUI_UploadTextureBlock

*public void VGUI_UploadTextureBlock(int id, int drawX, int drawY, const byte * rgba, int blockWidth, int blockHeight)*

### VGUI_DrawQuad

*public void VGUI_DrawQuad(const vpoint_t * ul, const vpoint_t * lr)*

### VGUI_GetTextureSizes

*public void VGUI_GetTextureSizes(int * width, int * height)*

### VGUI_GenerateTexture

*public int VGUI_GenerateTexture()*



