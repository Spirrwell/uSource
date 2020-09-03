# class IEngineStudio

*Defined at line 19 of ./engine/studio_int.h*

Inherits from IAppInterface



## Functions

### Mem_Calloc

*public void * Mem_Calloc(int number, size_t size)*

### Cache_Check

*public void * Cache_Check(struct cache_user_s * c)*

### LoadCacheFile

*public void LoadCacheFile(const char * path, struct cache_user_s * cu)*

### Mod_ForName

*public struct model_s * Mod_ForName(const char * name, int crash_if_missing)*

### Mod_Extradata

*public void * Mod_Extradata(struct model_s * mod)*

### GetModelByIndex

*public struct model_s * GetModelByIndex(int index)*

### GetCurrentEntity

*public struct cl_entity_s * GetCurrentEntity()*

### PlayerInfo

*public struct player_info_s * PlayerInfo(int index)*

### GetPlayerState

*public struct entity_state_s * GetPlayerState(int index)*

### GetViewEntity

*public struct cl_entity_s * GetViewEntity()*

### GetTimes

*public void GetTimes(int * framecount, double * current, double * old)*

### GetCvar

*public struct cvar_s * GetCvar(const char * name)*

### GetViewInfo

*public void GetViewInfo(float * origin, float * upv, float * rightv, float * vpnv)*

### GetChromeSprite

*public struct model_s * GetChromeSprite()*

### GetModelCounters

*public void GetModelCounters(int ** s, int ** a)*

### GetAliasScale

*public void GetAliasScale(float * x, float * y)*

### StudioGetBoneTransform

*public float **** StudioGetBoneTransform()*

### StudioGetLightTransform

*public float **** StudioGetLightTransform()*

### StudioGetAliasTransform

*public float *** StudioGetAliasTransform()*

### StudioGetRotationMatrix

*public float *** StudioGetRotationMatrix()*

### StudioSetupModel

*public void StudioSetupModel(int bodypart, void ** ppbodypart, void ** ppsubmodel)*

### StudioCheckBBox

*public int StudioCheckBBox()*

### StudioDynamicLight

*public void StudioDynamicLight(struct cl_entity_s * ent, struct alight_s * plight)*

### StudioEntityLight

*public void StudioEntityLight(struct alight_s * plight)*

### StudioSetupLighting

*public void StudioSetupLighting(struct alight_s * plighting)*

### StudioDrawPoints

*public void StudioDrawPoints()*

### StudioDrawHulls

*public void StudioDrawHulls()*

### StudioDrawAbsBBox

*public void StudioDrawAbsBBox()*

### StudioDrawBones

*public void StudioDrawBones()*

### StudioSetupSkin

*public void StudioSetupSkin(void * ptexturehdr, int index)*

### StudioSetRemapColors

*public void StudioSetRemapColors(int top, int bottom)*

### SetupPlayerModel

*public struct model_s * SetupPlayerModel(int index)*

### StudioClientEvents

*public void StudioClientEvents()*

### GetForceFaceFlags

*public int GetForceFaceFlags()*

### SetForceFaceFlags

*public void SetForceFaceFlags(int flags)*

### StudioSetHeader

*public void StudioSetHeader(void * header)*

### SetRenderModel

*public void SetRenderModel(struct model_s * model)*

### SetupRenderer

*public void SetupRenderer(int rendermode)*

### RestoreRenderer

*public void RestoreRenderer()*

### SetChromeOrigin

*public void SetChromeOrigin()*

### IsHardware

*public int IsHardware()*

### GL_StudioDrawShadow

*public void GL_StudioDrawShadow()*

### GL_SetRenderMode

*public void GL_SetRenderMode(int mode)*

### StudioSetRenderamt

*public void StudioSetRenderamt(int iRenderamt)*

### StudioSetCullState

*public void StudioSetCullState(int iCull)*

### StudioRenderShadow

*public void StudioRenderShadow(int iSprite, float * p1, float * p2, float * p3, float * p4)*



