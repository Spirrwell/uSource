# struct enginefuncs_s

*Defined at line 103 of ./engine/eiface.h*

 Engine hands this to DLLs for functionality callbacks



## Members

public int (*)(const char *) pfnPrecacheModel

public int (*)(const char *) pfnPrecacheSound

public void (*)(edict_t *, const char *) pfnSetModel

public int (*)(const char *) pfnModelIndex

public int (*)(int) pfnModelFrames

public void (*)(edict_t *, const float *, const float *) pfnSetSize

public void (*)(const char *, const char *) pfnChangeLevel

public void (*)(edict_t *) pfnGetSpawnParms

public void (*)(edict_t *) pfnSaveSpawnParms

public float (*)(const float *) pfnVecToYaw

public void (*)(const float *, float *) pfnVecToAngles

public void (*)(edict_t *, const float *, float, int) pfnMoveToOrigin

public void (*)(edict_t *) pfnChangeYaw

public void (*)(edict_t *) pfnChangePitch

public edict_t *(*)(edict_t *, const char *, const char *) pfnFindEntityByString

public int (*)(edict_t *) pfnGetEntityIllum

public edict_t *(*)(edict_t *, const float *, float) pfnFindEntityInSphere

public edict_t *(*)(edict_t *) pfnFindClientInPVS

public edict_t *(*)(edict_t *) pfnEntitiesInPVS

public void (*)(const float *) pfnMakeVectors

public void (*)(const float *, float *, float *, float *) pfnAngleVectors

public edict_t *(*)(void) pfnCreateEntity

public void (*)(edict_t *) pfnRemoveEntity

public edict_t *(*)(int) pfnCreateNamedEntity

public void (*)(edict_t *) pfnMakeStatic

public int (*)(edict_t *) pfnEntIsOnFloor

public int (*)(edict_t *) pfnDropToFloor

public int (*)(edict_t *, float, float, int) pfnWalkMove

public void (*)(edict_t *, const float *) pfnSetOrigin

public void (*)(edict_t *, int, const char *, float, float, int, int) pfnEmitSound

public void (*)(edict_t *, float *, const char *, float, float, int, int) pfnEmitAmbientSound

public void (*)(const float *, const float *, int, edict_t *, TraceResult *) pfnTraceLine

public void (*)(edict_t *, edict_t *, TraceResult *) pfnTraceToss

public int (*)(edict_t *, const float *, const float *, int, edict_t *, TraceResult *) pfnTraceMonsterHull

public void (*)(const float *, const float *, int, int, edict_t *, TraceResult *) pfnTraceHull

public void (*)(const float *, const float *, int, edict_t *, TraceResult *) pfnTraceModel

public const char *(*)(edict_t *, const float *, const float *) pfnTraceTexture

public void (*)(const float *, const float *, int, float, edict_t *, TraceResult *) pfnTraceSphere

public void (*)(edict_t *, float, float *) pfnGetAimVector

public void (*)(const char *) pfnServerCommand

public void (*)(void) pfnServerExecute

public void (*)(edict_t *, char *, ...) pfnClientCommand

public void (*)(const float *, const float *, float, float) pfnParticleEffect

public void (*)(int, const char *) pfnLightStyle

public int (*)(const char *) pfnDecalIndex

public int (*)(const float *) pfnPointContents

public void (*)(int, int, const float *, edict_t *) pfnMessageBegin

public void (*)(void) pfnMessageEnd

public void (*)(int) pfnWriteByte

public void (*)(int) pfnWriteChar

public void (*)(int) pfnWriteShort

public void (*)(int) pfnWriteLong

public void (*)(float) pfnWriteAngle

public void (*)(float) pfnWriteCoord

public void (*)(const char *) pfnWriteString

public void (*)(int) pfnWriteEntity

public void (*)(cvar_t *) pfnCVarRegister

public float (*)(const char *) pfnCVarGetFloat

public const char *(*)(const char *) pfnCVarGetString

public void (*)(const char *, float) pfnCVarSetFloat

public void (*)(const char *, const char *) pfnCVarSetString

public void (*)(ALERT_TYPE, char *, ...) pfnAlertMessage

public void (*)(FILE *, char *, ...) pfnEngineFprintf

public void *(*)(edict_t *, long) pfnPvAllocEntPrivateData

public void *(*)(edict_t *) pfnPvEntPrivateData

public void (*)(edict_t *) pfnFreeEntPrivateData

public const char *(*)(int) pfnSzFromIndex

public int (*)(const char *) pfnAllocString

public struct entvars_s *(*)(edict_t *) pfnGetVarsOfEnt

public edict_t *(*)(int) pfnPEntityOfEntOffset

public int (*)(const edict_t *) pfnEntOffsetOfPEntity

public int (*)(const edict_t *) pfnIndexOfEdict

public edict_t *(*)(int) pfnPEntityOfEntIndex

public edict_t *(*)(struct entvars_s *) pfnFindEntityByVars

public void *(*)(edict_t *) pfnGetModelPtr

public int (*)(const char *, int) pfnRegUserMsg

public void (*)(const edict_t *, float) pfnAnimationAutomove

public void (*)(const edict_t *, int, float *, float *) pfnGetBonePosition

public unsigned long (*)(const char *) pfnFunctionFromName

public const char *(*)(unsigned long) pfnNameForFunction

public void (*)(edict_t *, PRINT_TYPE, const char *) pfnClientPrintf

public void (*)(const char *) pfnServerPrint

public const char *(*)(void) pfnCmd_Args

public const char *(*)(int) pfnCmd_Argv

public int (*)(void) pfnCmd_Argc

public void (*)(const edict_t *, int, float *, float *) pfnGetAttachment

public void (*)(CRC32_t *) pfnCRC32_Init

public void (*)(CRC32_t *, const void *, int) pfnCRC32_ProcessBuffer

public void (*)(CRC32_t *, unsigned char) pfnCRC32_ProcessByte

public CRC32_t (*)(CRC32_t) pfnCRC32_Final

public int (*)(int, int) pfnRandomLong

public float (*)(float, float) pfnRandomFloat

public void (*)(const edict_t *, const edict_t *) pfnSetView

public float (*)(void) pfnTime

public void (*)(const edict_t *, float, float) pfnCrosshairAngle

public byte *(*)(const char *, int *) pfnLoadFileForMe

public void (*)(void *) pfnFreeFile

public void (*)(const char *) pfnEndSection

public int (*)(const char *, const char *, int *) pfnCompareFileTime

public void (*)(char *) pfnGetGameDir

public void (*)(cvar_t *) pfnCvar_RegisterVariable

public void (*)(const edict_t *, int, int, int, int) pfnFadeClientVolume

public void (*)(const edict_t *, float) pfnSetClientMaxspeed

public edict_t *(*)(const char *) pfnCreateFakeClient

public void (*)(edict_t *, const float *, float, float, float, unsigned short, byte, byte) pfnRunPlayerMove

public int (*)(void) pfnNumberOfEntities

public char *(*)(edict_t *) pfnGetInfoKeyBuffer

public const char *(*)(const char *, const char *) pfnInfoKeyValue

public void (*)(char *, char *, char *) pfnSetKeyValue

public void (*)(int, char *, char *, char *) pfnSetClientKeyValue

public int (*)(char *) pfnIsMapValid

public void (*)(const float *, int, int, int) pfnStaticDecal

public int (*)(const char *) pfnPrecacheGeneric

public int (*)(edict_t *) pfnGetPlayerUserId

public void (*)(edict_t *, int, const char *, float, float, int, int, int, int, const float *, edict_t *) pfnBuildSoundMsg

public int (*)(void) pfnIsDedicatedServer

public cvar_t *(*)(const char *) pfnCVarGetPointer

public unsigned int (*)(edict_t *) pfnGetPlayerWONId

public void (*)(char *, const char *) pfnInfo_RemoveKey

public const char *(*)(const edict_t *, const char *) pfnGetPhysicsKeyValue

public void (*)(const edict_t *, const char *, const char *) pfnSetPhysicsKeyValue

public const char *(*)(const edict_t *) pfnGetPhysicsInfoString

public unsigned short (*)(int, const char *) pfnPrecacheEvent

public void (*)(int, const edict_t *, unsigned short, float, float *, float *, float, float, int, int, int, int) pfnPlaybackEvent

public unsigned char *(*)(const float *) pfnSetFatPVS

public unsigned char *(*)(const float *) pfnSetFatPAS

public int (*)(const edict_t *, unsigned char *) pfnCheckVisibility

public void (*)(struct delta_s *, const char *) pfnDeltaSetField

public void (*)(struct delta_s *, const char *) pfnDeltaUnsetField

public void (*)(char *, void (*)(struct delta_s *, const unsigned char *, const unsigned char *)) pfnDeltaAddEncoder

public int (*)(void) pfnGetCurrentPlayer

public int (*)(const edict_t *) pfnCanSkipPlayer

public int (*)(struct delta_s *, const char *) pfnDeltaFindField

public void (*)(struct delta_s *, int) pfnDeltaSetFieldByIndex

public void (*)(struct delta_s *, int) pfnDeltaUnsetFieldByIndex

public void (*)(int, int) pfnSetGroupMask

public int (*)(int, struct entity_state_s *) pfnCreateInstancedBaseline

public void (*)(struct cvar_s *, const char *) pfnCvar_DirectSet

public void (*)(FORCE_TYPE, float *, float *, const char *) pfnForceUnmodified

public void (*)(const edict_t *, int *, int *) pfnGetPlayerStats

public void (*)(const char *, void (*)(void)) pfnAddServerCommand

public qboolean (*)(int, int) pfnVoice_GetClientListening

public qboolean (*)(int, int, qboolean) pfnVoice_SetClientListening

public const char *(*)(edict_t *) pfnGetPlayerAuthId

public void (*)(void) pfnUnused1

public void (*)(void) pfnUnused2

public void (*)(void) pfnUnused3

public void (*)(void) pfnUnused4

public void (*)(void) pfnUnused5

public void (*)(void) pfnUnused6

public void (*)(void) pfnUnused7

public void (*)(void) pfnUnused8

public void (*)(void) pfnUnused9

public void (*)(void) pfnUnused10

public void (*)(void) pfnUnused11

public void (*)(const edict_t *, const char *) pfnQueryClientCvarValue

public void (*)(const edict_t *, const char *, int) pfnQueryClientCvarValue2

public int (*)(char *, char **) pfnCheckParm



