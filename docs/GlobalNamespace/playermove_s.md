# struct playermove_s

*Defined at line 85 of ./pm_shared/pm_defs.h*

## Members

public int player_index

public qboolean server

public qboolean multiplayer

public float time

public float frametime

public vec3_t forward

public vec3_t right

public vec3_t up

public vec3_t origin

public vec3_t angles

public vec3_t oldangles

public vec3_t velocity

public vec3_t movedir

public vec3_t basevelocity

public vec3_t view_ofs

public float flDuckTime

public qboolean bInDuck

public int flTimeStepSound

public int iStepLeft

public float flFallVelocity

public vec3_t punchangle

public float flSwimTime

public float flNextPrimaryAttack

public int effects

public int flags

public int usehull

public float gravity

public float friction

public int oldbuttons

public float waterjumptime

public qboolean dead

public int deadflag

public int spectator

public int movetype

public int onground

public int waterlevel

public int watertype

public int oldwaterlevel

public char [256] sztexturename

public char chtexturetype

public float maxspeed

public float clientmaxspeed

public int iuser1

public int iuser2

public int iuser3

public int iuser4

public float fuser1

public float fuser2

public float fuser3

public float fuser4

public vec3_t vuser1

public vec3_t vuser2

public vec3_t vuser3

public vec3_t vuser4

public int numphysent

public physent_t [600] physents

public int nummoveent

public physent_t [64] moveents

public int numvisent

public physent_t [600] visents

usercmd_s cmd

public int numtouch

public pmtrace_t [600] touchindex

public char [256] physinfo

public struct movevars_s * movevars

public vec3_t [4] player_mins

public vec3_t [4] player_maxs

public const char *(*)(const char *, const char *) PM_Info_ValueForKey

public void (*)(const float *, int, float, int, int) PM_Particle

public int (*)(float *, pmtrace_t *) PM_TestPlayerPosition

public void (*)(int, const char *, ...) Con_NPrintf

public void (*)(const char *, ...) Con_DPrintf

public void (*)(const char *, ...) Con_Printf

public double (*)(void) Sys_FloatTime

public void (*)(int, pmtrace_t *) PM_StuckTouch

public int (*)(float *, int *) PM_PointContents

public int (*)(float *) PM_TruePointContents

public int (*)(struct hull_s *, int, float *) PM_HullPointContents

public pmtrace_t (*)(float *, float *, int, int) PM_PlayerTrace

public struct pmtrace_s *(*)(float *, float *, int, int, int) PM_TraceLine

public int (*)(int, int) RandomLong

public float (*)(float, float) RandomFloat

public int (*)(struct model_s *) PM_GetModelType

public void (*)(struct model_s *, float *, float *) PM_GetModelBounds

public void *(*)(physent_t *, float *) PM_HullForBsp

public float (*)(physent_t *, float *, float *, trace_t *) PM_TraceModel

public int (*)(const char *) COM_FileSize

public byte *(*)(const char *, int, int *) COM_LoadFile

public void (*)(void *) COM_FreeFile

public char *(*)(byte *, int, int *, char *, int) memfgets

public qboolean runfuncs

public void (*)(int, const char *, float, float, int, int) PM_PlaySound

public const char *(*)(int, float *, float *) PM_TraceTexture

public void (*)(int, int, unsigned short, float, float *, float *, float, float, int, int, int, int) PM_PlaybackEventFull

public pmtrace_t (*)(float *, float *, int, int (*)(physent_t *)) PM_PlayerTraceEx

public int (*)(float *, pmtrace_t *, int (*)(physent_t *)) PM_TestPlayerPositionEx

public struct pmtrace_s *(*)(float *, float *, int, int, int (*)(physent_t *)) PM_TraceLineEx

public struct msurface_s *(*)(int, float *, float *) PM_TraceSurface



