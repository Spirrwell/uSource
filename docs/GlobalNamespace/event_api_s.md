# struct event_api_s

*Defined at line 21 of ./common/event_api.h*

## Members

public int version

public void (*)(int, float *, int, const char *, float, float, int, int) EV_PlaySound

public void (*)(int, int, const char *) EV_StopSound

public int (*)(const char *) EV_FindModelIndex

public int (*)(int) EV_IsLocal

public int (*)(void) EV_LocalPlayerDucking

public void (*)(float *) EV_LocalPlayerViewheight

public void (*)(int, float *, float *) EV_LocalPlayerBounds

public int (*)(struct pmtrace_s *) EV_IndexFromTrace

public struct physent_s *(*)(int) EV_GetPhysent

public void (*)(int, int) EV_SetUpPlayerPrediction

public void (*)(void) EV_PushPMStates

public void (*)(void) EV_PopPMStates

public void (*)(int) EV_SetSolidPlayers

public void (*)(int) EV_SetTraceHull

public void (*)(float *, float *, int, int, struct pmtrace_s *) EV_PlayerTrace

public void (*)(int, int) EV_WeaponAnimation

public unsigned short (*)(int, const char *) EV_PrecacheEvent

public void (*)(int, const struct edict_s *, unsigned short, float, float *, float *, float, float, int, int, int, int) EV_PlaybackEvent

public const char *(*)(int, float *, float *) EV_TraceTexture

public void (*)(int, int) EV_StopAllSounds

public void (*)(int, const char *) EV_KillEvents

public void (*)(float *, float *, int, int (*)(struct physent_s *), struct pmtrace_s *) EV_PlayerTraceExt

public const char *(*)(int) EV_SoundForIndex

public struct msurface_s *(*)(int, float *, float *) EV_TraceSurface

public struct movevars_s *(*)(void) EV_GetMovevars

public struct pmtrace_s *(*)(float *, float *, int) EV_VisTraceLine

public struct physent_s *(*)(int) EV_GetVisent

public int (*)(const class Vector, const class Vector, int) EV_TestLine

public void (*)(int, const float *, const float *) EV_PushTraceBounds

public void (*)(void) EV_PopTraceBounds



