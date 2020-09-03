# class IEngineEvents

*Defined at line 9 of ./engine/event_int.h*

Inherits from IAppInterface



## Functions

### PlaySound

*public void PlaySound(int ent, float * origin, int channel, const char * sample, float volume, float attenuation, int fFlags, int pitch)*

### StopSound

*public void StopSound(int ent, int channel, const char * sample)*

### FindModelIndex

*public int FindModelIndex(const char * pmodel)*

### IsLocal

*public int IsLocal(int playernum)*

### LocalPlayerDucking

*public int LocalPlayerDucking()*

### LocalPlayerViewheight

*public void LocalPlayerViewheight(float * )*

### LocalPlayerBounds

*public void LocalPlayerBounds(int hull, float * mins, float * maxs)*

### IndexFromTrace

*public int IndexFromTrace(struct pmtrace_s * pTrace)*

### GetPhysent

*public struct physent_s * GetPhysent(int idx)*

### SetUpPlayerPrediction

*public void SetUpPlayerPrediction(int dopred, int bIncludeLocalClient)*

### PushPMStates

*public void PushPMStates()*

### PopPMStates

*public void PopPMStates()*

### SetSolidPlayers

*public void SetSolidPlayers(int playernum)*

### SetTraceHull

*public void SetTraceHull(int hull)*

### PlayerTrace

*public void PlayerTrace(float * start, float * end, int traceFlags, int ignore_pe, struct pmtrace_s * tr)*

### WeaponAnimation

*public void WeaponAnimation(int sequence, int body)*

### PrecacheEvent

*public unsigned short PrecacheEvent(int type, const char * psz)*

### PlaybackEvent

*public void PlaybackEvent(int flags, const struct edict_s * pInvoker, unsigned short eventindex, float delay, float * origin, float * angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2)*

### TraceTexture

*public const char * TraceTexture(int ground, float * vstart, float * vend)*

### StopAllSounds

*public void StopAllSounds(int entnum, int entchannel)*

### KillEvents

*public void KillEvents(int entnum, const char * eventname)*

### PlayerTraceExt

*public void PlayerTraceExt(float * start, float * end, int traceFlags, int (*)(struct physent_s *) pfnIgnore, struct pmtrace_s * tr)*

 Xash3D extension

### SoundForIndex

*public const char * SoundForIndex(int index)*

### TraceSurface

*public struct msurface_s * TraceSurface(int ground, float * vstart, float * vend)*

### GetMovevars

*public struct movevars_s * GetMovevars()*

### VisTraceLine

*public struct pmtrace_s * VisTraceLine(float * start, float * end, int flags)*

### GetVisent

*public struct physent_s * GetVisent(int idx)*

### TestLine

*public int TestLine(Vector start, Vector end, int flags)*

### PushTraceBounds

*public void PushTraceBounds(int hullnum, const float * mins, const float * maxs)*

### PopTraceBounds

*public void PopTraceBounds()*

### TestLine

*public int TestLine(const vec3_t start, const vec3_t end, int flags)*



