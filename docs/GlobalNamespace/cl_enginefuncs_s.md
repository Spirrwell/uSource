# struct cl_enginefuncs_s

*Defined at line 121 of ./common/../engine/client_int.h*

## Members

public HSPRITE (*)(const char *) pfnSPR_Load

public int (*)(HSPRITE) pfnSPR_Frames

public int (*)(HSPRITE, int) pfnSPR_Height

public int (*)(HSPRITE, int) pfnSPR_Width

public void (*)(HSPRITE, int, int, int) pfnSPR_Set

public void (*)(int, int, int, const wrect_t *) pfnSPR_Draw

public void (*)(int, int, int, const wrect_t *) pfnSPR_DrawHoles

public void (*)(int, int, int, const wrect_t *) pfnSPR_DrawAdditive

public void (*)(int, int, int, int) pfnSPR_EnableScissor

public void (*)(void) pfnSPR_DisableScissor

public client_sprite_t *(*)(char *, int *) pfnSPR_GetList

public void (*)(int, int, int, int, int, int, int, int) pfnFillRGBA

public int (*)(SCREENINFO *) pfnGetScreenInfo

public void (*)(HSPRITE, wrect_t, int, int, int) pfnSetCrosshair

public struct cvar_s *(*)(const char *, const char *, int) pfnRegisterVariable

public float (*)(const char *) pfnGetCvarFloat

public const char *(*)(const char *) pfnGetCvarString

public int (*)(const char *, void (*)(void)) pfnAddCommand

public int (*)(const char *, pfnUserMsgHook) pfnHookUserMsg

public int (*)(const char *) pfnServerCmd

public int (*)(const char *) pfnClientCmd

public void (*)(int, hud_player_info_t *) pfnGetPlayerInfo

public void (*)(const char *, float) pfnPlaySoundByName

public void (*)(int, float) pfnPlaySoundByIndex

public void (*)(const float *, float *, float *, float *) pfnAngleVectors

public client_textmessage_t *(*)(const char *) pfnTextMessageGet

public int (*)(int, int, int, int, int, int) pfnDrawCharacter

public int (*)(int, int, char *) pfnDrawConsoleString

public void (*)(float, float, float) pfnDrawSetTextColor

public void (*)(const char *, int *, int *) pfnDrawConsoleStringLen

public void (*)(const char *) pfnConsolePrint

public void (*)(const char *) pfnCenterPrint

public int (*)(void) GetWindowCenterX

public int (*)(void) GetWindowCenterY

public void (*)(float *) GetViewAngles

public void (*)(float *) SetViewAngles

public int (*)(void) GetMaxClients

public void (*)(const char *, float) Cvar_SetValue

public int (*)(void) Cmd_Argc

public const char *(*)(int) Cmd_Argv

public void (*)(const char *, ...) Con_Printf

public void (*)(const char *, ...) Con_DPrintf

public void (*)(int, const char *, ...) Con_NPrintf

public void (*)(struct con_nprint_s *, const char *, ...) Con_NXPrintf

public const char *(*)(const char *) PhysInfo_ValueForKey

public const char *(*)(const char *) ServerInfo_ValueForKey

public float (*)(void) GetClientMaxspeed

public int (*)(char *, char **) CheckParm

public void (*)(int, int) Key_Event

public void (*)(int *, int *) GetMousePosition

public int (*)(void) IsNoClipping

public struct cl_entity_s *(*)(void) GetLocalPlayer

public struct cl_entity_s *(*)(void) GetViewModel

public struct cl_entity_s *(*)(int) GetEntityByIndex

public float (*)(void) GetClientTime

public void (*)(void) V_CalcShake

public void (*)(float *, float *, float) V_ApplyShake

public int (*)(const float *, int *) PM_PointContents

public int (*)(const float *) PM_WaterEntity

public struct pmtrace_s *(*)(float *, float *, int, int, int) PM_TraceLine

public struct model_s *(*)(const char *, int *) CL_LoadModel

public int (*)(int, struct cl_entity_s *) CL_CreateVisibleEntity

public const struct model_s *(*)(HSPRITE) GetSpritePointer

public void (*)(char *, float, float *) pfnPlaySoundByNameAtLocation

public unsigned short (*)(int, const char *) pfnPrecacheEvent

public void (*)(int, const struct edict_s *, unsigned short, float, float *, float *, float, float, int, int, int, int) pfnPlaybackEvent

public void (*)(int, int) pfnWeaponAnim

public float (*)(float, float) pfnRandomFloat

public int (*)(int, int) pfnRandomLong

public void (*)(const char *, void (*)(struct event_args_s *)) pfnHookEvent

public int (*)(void) Con_IsVisible

public const char *(*)(void) pfnGetGameDirectory

public struct cvar_s *(*)(const char *) pfnGetCvarPointer

public const char *(*)(const char *) Key_LookupBinding

public const char *(*)(void) pfnGetLevelName

public void (*)(struct screenfade_s *) pfnGetScreenFade

public void (*)(struct screenfade_s *) pfnSetScreenFade

public void *(*)(void) VGui_GetPanel

public void (*)(int *) VGui_ViewportPaintBackground

public byte *(*)(const char *, int, int *) COM_LoadFile

public char *(*)(char *, char *) COM_ParseFile

public void (*)(void *) COM_FreeFile

public struct triangleapi_s * pTriAPI

public struct efx_api_s * pEfxAPI

public struct event_api_s * pEventAPI

public struct demo_api_s * pDemoAPI

public struct net_api_s * pNetAPI

public struct IVoiceTweak_s * pVoiceTweak

public int (*)(void) IsSpectateOnly

public struct model_s *(*)(const char *) LoadMapSprite

public void (*)(const char *, const char *) COM_AddAppDirectoryToSearchPath

public int (*)(const char *, char *, int) COM_ExpandFilename

public const char *(*)(int, const char *) PlayerInfo_ValueForKey

public void (*)(const char *, const char *) PlayerInfo_SetValueForKey

public qboolean (*)(int, char *) GetPlayerUniqueID

public int (*)(int) GetTrackerIDForPlayer

public int (*)(int) GetPlayerForTrackerID

public int (*)(char *) pfnServerCmdUnreliable

public void (*)(struct tagPOINT *) pfnGetMousePos

public void (*)(int, int) pfnSetMousePos

public void (*)(qboolean) pfnSetMouseEnable

public struct cvar_s *(*)(void) pfnGetFirstCvarPtr

public void *(*)(void) pfnGetFirstCmdFunctionHandle

public void *(*)(void *) pfnGetNextCmdFunctionHandle

public const char *(*)(void *) pfnGetCmdFunctionName

public float (*)(void) pfnGetClientOldTime

public float (*)(void) pfnGetGravity

public struct model_s *(*)(int) pfnGetModelByIndex

public void (*)(int) pfnSetFilterMode

public void (*)(float, float, float) pfnSetFilterColor

public void (*)(float) pfnSetFilterBrightness

public void *(*)(const char *, const char *) pfnSequenceGet

public void (*)(int, int, int, const wrect_t *, int, int, int, int) pfnSPR_DrawGeneric

public void *(*)(const char *, int, int *) pfnSequencePickSentence

public int (*)(int, int, const char *, int, int, int) pfnDrawString

public int (*)(int, int, const char *, int, int, int) pfnDrawStringReverse

public const char *(*)(const char *) LocalPlayerInfo_ValueForKey

public int (*)(int, int, int, unsigned int) pfnVGUI2DrawCharacter

public int (*)(int, int, int, int, int, int, unsigned int) pfnVGUI2DrawCharacterAdditive

public unsigned int (*)(char *) pfnGetApproxWavePlayLen

public void *(*)(void) GetCareerGameUI

public void (*)(char *, char *) Cvar_Set

public int (*)(void) pfnIsPlayingCareerMatch

public void (*)(char *, float, int) pfnPlaySoundVoiceByName

public void (*)(char *, int) pfnPrimeMusicStream

public double (*)(void) pfnSys_FloatTime

public void (*)(int *, int) pfnProcessTutorMessageDecayBuffer

public void (*)(int *, int) pfnConstructTutorMessageDecayBuffer

public void (*)(void) pfnResetTutorMessageDecayData

public void (*)(char *, float, int) pfnPlaySoundByNameAtPitch

public void (*)(int, int, int, int, int, int, int, int) pfnFillRGBABlend

public int (*)(void) pfnGetAppID

public cmdalias_t *(*)(void) pfnGetAliases

public void (*)(int *, int *) pfnVguiWrap2_GetMouseDelta

public int (*)(const char *) pfnFilteredClientCmd



