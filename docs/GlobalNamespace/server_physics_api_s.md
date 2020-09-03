# struct server_physics_api_s

*Defined at line 61 of ./engine/physint.h*

## Members

public void (*)(edict_t *, qboolean) pfnLinkEdict

public double (*)(void) pfnGetServerTime

public double (*)(void) pfnGetFrameTime

public void *(*)(int) pfnGetModel

public areanode_t *(*)(void) pfnGetHeadnode

public int (*)(void) pfnServerState

public void (*)(const char *, ...) pfnHost_Error

public struct triangleapi_s * pTriAPI

public int (*)(int, int, char *) pfnDrawConsoleString

public void (*)(float, float, float) pfnDrawSetTextColor

public void (*)(const char *, int *, int *) pfnDrawConsoleStringLen

public void (*)(int, const char *, ...) Con_NPrintf

public void (*)(struct con_nprint_s *, const char *, ...) Con_NXPrintf

public const char *(*)(int) pfnGetLightStyle

public void (*)(unsigned int) pfnUpdateFogSettings

public char **(*)(const char *, int *, int) pfnGetFilesList

public struct msurface_s *(*)(edict_t *, const float *, const float *) pfnTraceSurface

public const byte *(*)(unsigned int) pfnGetTextureData

public void *(*)(size_t, const char *, const int) pfnMemAlloc

public void (*)(void *, const char *, const int) pfnMemFree

public int (*)(const float *, int) pfnMaskPointContents

public trace_t (*)(const float *, float *, float *, const float *, int, edict_t *) pfnTrace

public trace_t (*)(const float *, float *, float *, const float *, int, edict_t *) pfnTraceNoEnts

public int (*)(const float *, const float *, const float *) pfnBoxInPVS

public void (*)(const byte *, int) pfnWriteBytes

public int (*)(const char *, const int, int *) pfnCheckLump

public int (*)(const char *, const int, void **, int *) pfnReadLump

public int (*)(const char *, const int, void *, int) pfnSaveLump

public int (*)(const char *, const void *, int) pfnSaveFile

public const byte *(*)(const char *, int *, int *) pfnLoadImagePixels

public const char *(*)(int) pfnGetModelName



