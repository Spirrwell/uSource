# struct ui_enginefuncs_s

*Defined at line 52 of ./engine/menu_int.h*

## Members

public HIMAGE (*)(const char *, const byte *, int, int) pfnPIC_Load

public void (*)(const char *) pfnPIC_Free

public int (*)(HIMAGE) pfnPIC_Width

public int (*)(HIMAGE) pfnPIC_Height

public void (*)(HIMAGE, int, int, int, int) pfnPIC_Set

public void (*)(int, int, int, int, const wrect_t *) pfnPIC_Draw

public void (*)(int, int, int, int, const wrect_t *) pfnPIC_DrawHoles

public void (*)(int, int, int, int, const wrect_t *) pfnPIC_DrawTrans

public void (*)(int, int, int, int, const wrect_t *) pfnPIC_DrawAdditive

public void (*)(int, int, int, int) pfnPIC_EnableScissor

public void (*)(void) pfnPIC_DisableScissor

public void (*)(int, int, int, int, int, int, int, int) pfnFillRGBA

public cvar_t *(*)(const char *, const char *, int) pfnRegisterVariable

public float (*)(const char *) pfnGetCvarFloat

public const char *(*)(const char *) pfnGetCvarString

public void (*)(const char *, const char *) pfnCvarSetString

public void (*)(const char *, float) pfnCvarSetValue

public int (*)(const char *, void (*)(void)) pfnAddCommand

public void (*)(int, const char *) pfnClientCmd

public void (*)(const char *) pfnDelCommand

public int (*)(void) pfnCmdArgc

public const char *(*)(int) pfnCmdArgv

public const char *(*)(void) pfnCmd_Args

public void (*)(const char *, ...) Con_Printf

public void (*)(const char *, ...) Con_DPrintf

public void (*)(int, const char *, ...) Con_NPrintf

public void (*)(struct con_nprint_s *, const char *, ...) Con_NXPrintf

public void (*)(const char *) pfnPlayLocalSound

public void (*)(const char *, float, float, float, float) pfnDrawLogo

public int (*)(void) pfnGetLogoWidth

public int (*)(void) pfnGetLogoHeight

public float (*)(void) pfnGetLogoLength

public void (*)(int, int, int, int, int, int, HIMAGE) pfnDrawCharacter

public int (*)(int, int, const char *) pfnDrawConsoleString

public void (*)(int, int, int, int) pfnDrawSetTextColor

public void (*)(const char *, int *, int *) pfnDrawConsoleStringLen

public void (*)(int, int, int) pfnSetConsoleDefaultColor

public struct cl_entity_s *(*)(void) pfnGetPlayerModel

public void (*)(struct cl_entity_s *, const char *) pfnSetModel

public void (*)(void) pfnClearScene

public void (*)(const struct ref_viewpass_s *) pfnRenderScene

public int (*)(int, struct cl_entity_s *) CL_CreateVisibleEntity

public void (*)(const char *, ...) pfnHostError

public int (*)(const char *, int) pfnFileExists

public void (*)(char *) pfnGetGameDir

public int (*)(int) pfnCreateMapsList

public int (*)(void) pfnClientInGame

public void (*)(const struct netadr_s) pfnClientJoin

public byte *(*)(const char *, int *) COM_LoadFile

public char *(*)(char *, char *) COM_ParseFile

public void (*)(void *) COM_FreeFile

public void (*)(void) pfnKeyClearStates

public void (*)(int) pfnSetKeyDest

public const char *(*)(int) pfnKeynumToString

public const char *(*)(int) pfnKeyGetBinding

public void (*)(int, const char *) pfnKeySetBinding

public int (*)(int) pfnKeyIsDown

public int (*)(void) pfnKeyGetOverstrikeMode

public void (*)(int) pfnKeySetOverstrikeMode

public void *(*)(const char *) pfnKeyGetState

public void *(*)(size_t, const char *, const int) pfnMemAlloc

public void (*)(void *, const char *, const int) pfnMemFree

public int (*)(GAMEINFO *) pfnGetGameInfo

public GAMEINFO **(*)(int *) pfnGetGamesList

public char **(*)(const char *, int *, int) pfnGetFilesList

public int (*)(const char *, char *) pfnGetSaveComment

public int (*)(const char *, char *) pfnGetDemoComment

public int (*)(void) pfnCheckGameDll

public char *(*)(void) pfnGetClipboardData

public void (*)(const char *, const char *, int) pfnShellExecute

public void (*)(const char *) pfnWriteServerConfig

public void (*)(const char *, const char *) pfnChangeInstance

public void (*)(const char *, const char *) pfnPlayBackgroundTrack

public void (*)(const char *) pfnHostEndGame

public float (*)(float, float) pfnRandomFloat

public int (*)(int, int) pfnRandomLong

public void (*)(void *) pfnSetCursor

public int (*)(char *) pfnIsMapValid

public void (*)(int, float, int, int) pfnProcessImage

public int (*)(const char *, const char *, int *) pfnCompareFileTime

public const char *(*)(int) pfnGetModeString

public int (*)(const char *, const void *, int) COM_SaveFile

public int (*)(const char *) COM_RemoveFile



