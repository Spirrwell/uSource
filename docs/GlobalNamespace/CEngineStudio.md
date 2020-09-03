# class CEngineStudio

*Defined at line 4005 of ./rendersystem/r_studio.cpp*

Inherits from IEngineStudio



## Functions

### Init

*public _Bool Init()*

*Defined at line 4009 of ./rendersystem/r_studio.cpp*

### PreInit

*public _Bool PreInit()*

*Defined at line 4010 of ./rendersystem/r_studio.cpp*

### Shutdown

*public void Shutdown()*

*Defined at line 4011 of ./rendersystem/r_studio.cpp*

### GetName

*public const char * GetName()*

*Defined at line 4012 of ./rendersystem/r_studio.cpp*

### GetParentInterface

*public const char * GetParentInterface()*

*Defined at line 4013 of ./rendersystem/r_studio.cpp*

### Mem_Calloc

*public void * Mem_Calloc(int number, size_t size)*

*Defined at line 4015 of ./rendersystem/r_studio.cpp*

### Cache_Check

*public void * Cache_Check(struct cache_user_s * c)*

*Defined at line 4020 of ./rendersystem/r_studio.cpp*

### LoadCacheFile

*public void LoadCacheFile(const char * path, struct cache_user_s * cu)*

*Defined at line 4025 of ./rendersystem/r_studio.cpp*

### Mod_ForName

*public struct model_s * Mod_ForName(const char * name, int crash_if_missing)*

*Defined at line 4030 of ./rendersystem/r_studio.cpp*

### Mod_Extradata

*public void * Mod_Extradata(struct model_s * mod)*

*Defined at line 4035 of ./rendersystem/r_studio.cpp*

### GetModelByIndex

*public struct model_s * GetModelByIndex(int index)*

*Defined at line 4040 of ./rendersystem/r_studio.cpp*

### GetCurrentEntity

*public struct cl_entity_s * GetCurrentEntity()*

*Defined at line 4045 of ./rendersystem/r_studio.cpp*

### PlayerInfo

*public struct player_info_s * PlayerInfo(int index)*

*Defined at line 4050 of ./rendersystem/r_studio.cpp*

### GetPlayerState

*public struct entity_state_s * GetPlayerState(int index)*

*Defined at line 4055 of ./rendersystem/r_studio.cpp*

### GetViewEntity

*public struct cl_entity_s * GetViewEntity()*

*Defined at line 4060 of ./rendersystem/r_studio.cpp*

### GetTimes

*public void GetTimes(int * framecount, double * current, double * old)*

*Defined at line 4065 of ./rendersystem/r_studio.cpp*

### GetCvar

*public struct cvar_s * GetCvar(const char * name)*

*Defined at line 4070 of ./rendersystem/r_studio.cpp*

### GetViewInfo

*public void GetViewInfo(float * origin, float * upv, float * rightv, float * vpnv)*

*Defined at line 4075 of ./rendersystem/r_studio.cpp*

### GetChromeSprite

*public struct model_s * GetChromeSprite()*

*Defined at line 4080 of ./rendersystem/r_studio.cpp*

### GetModelCounters

*public void GetModelCounters(int ** s, int ** a)*

*Defined at line 4085 of ./rendersystem/r_studio.cpp*

### GetAliasScale

*public void GetAliasScale(float * x, float * y)*

*Defined at line 4090 of ./rendersystem/r_studio.cpp*

### StudioGetBoneTransform

*public float **** StudioGetBoneTransform()*

*Defined at line 4095 of ./rendersystem/r_studio.cpp*

### StudioGetLightTransform

*public float **** StudioGetLightTransform()*

*Defined at line 4100 of ./rendersystem/r_studio.cpp*

### StudioGetAliasTransform

*public float *** StudioGetAliasTransform()*

*Defined at line 4105 of ./rendersystem/r_studio.cpp*

### StudioGetRotationMatrix

*public float *** StudioGetRotationMatrix()*

*Defined at line 4110 of ./rendersystem/r_studio.cpp*

### StudioSetupModel

*public void StudioSetupModel(int bodypart, void ** ppbodypart, void ** ppsubmodel)*

*Defined at line 4115 of ./rendersystem/r_studio.cpp*

### StudioCheckBBox

*public int StudioCheckBBox()*

*Defined at line 4120 of ./rendersystem/r_studio.cpp*

### StudioDynamicLight

*public void StudioDynamicLight(struct cl_entity_s * ent, struct alight_s * plight)*

*Defined at line 4125 of ./rendersystem/r_studio.cpp*

### StudioEntityLight

*public void StudioEntityLight(struct alight_s * plight)*

*Defined at line 4130 of ./rendersystem/r_studio.cpp*

### StudioSetupLighting

*public void StudioSetupLighting(struct alight_s * plighting)*

*Defined at line 4135 of ./rendersystem/r_studio.cpp*

### StudioDrawPoints

*public void StudioDrawPoints()*

*Defined at line 4140 of ./rendersystem/r_studio.cpp*

### StudioDrawHulls

*public void StudioDrawHulls()*

*Defined at line 4145 of ./rendersystem/r_studio.cpp*

### StudioDrawAbsBBox

*public void StudioDrawAbsBBox()*

*Defined at line 4150 of ./rendersystem/r_studio.cpp*

### StudioDrawBones

*public void StudioDrawBones()*

*Defined at line 4155 of ./rendersystem/r_studio.cpp*

### StudioSetupSkin

*public void StudioSetupSkin(void * ptexturehdr, int index)*

*Defined at line 4160 of ./rendersystem/r_studio.cpp*

### StudioSetRemapColors

*public void StudioSetRemapColors(int top, int bottom)*

*Defined at line 4165 of ./rendersystem/r_studio.cpp*

### SetupPlayerModel

*public struct model_s * SetupPlayerModel(int index)*

*Defined at line 4170 of ./rendersystem/r_studio.cpp*

### StudioClientEvents

*public void StudioClientEvents()*

*Defined at line 4175 of ./rendersystem/r_studio.cpp*

### GetForceFaceFlags

*public int GetForceFaceFlags()*

*Defined at line 4180 of ./rendersystem/r_studio.cpp*

### SetForceFaceFlags

*public void SetForceFaceFlags(int flags)*

*Defined at line 4185 of ./rendersystem/r_studio.cpp*

### StudioSetHeader

*public void StudioSetHeader(void * header)*

*Defined at line 4190 of ./rendersystem/r_studio.cpp*

### SetRenderModel

*public void SetRenderModel(struct model_s * model)*

*Defined at line 4195 of ./rendersystem/r_studio.cpp*

### SetupRenderer

*public void SetupRenderer(int rendermode)*

*Defined at line 4200 of ./rendersystem/r_studio.cpp*

### RestoreRenderer

*public void RestoreRenderer()*

*Defined at line 4205 of ./rendersystem/r_studio.cpp*

### SetChromeOrigin

*public void SetChromeOrigin()*

*Defined at line 4210 of ./rendersystem/r_studio.cpp*

### IsHardware

*public int IsHardware()*

*Defined at line 4215 of ./rendersystem/r_studio.cpp*

### GL_StudioDrawShadow

*public void GL_StudioDrawShadow()*

*Defined at line 4220 of ./rendersystem/r_studio.cpp*

### GL_SetRenderMode

*public void GL_SetRenderMode(int mode)*

*Defined at line 4225 of ./rendersystem/r_studio.cpp*

### StudioSetRenderamt

*public void StudioSetRenderamt(int iRenderamt)*

*Defined at line 4230 of ./rendersystem/r_studio.cpp*

### StudioSetCullState

*public void StudioSetCullState(int iCull)*

*Defined at line 4235 of ./rendersystem/r_studio.cpp*

### StudioRenderShadow

*public void StudioRenderShadow(int iSprite, float * p1, float * p2, float * p3, float * p4)*

*Defined at line 4240 of ./rendersystem/r_studio.cpp*



