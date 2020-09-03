# class CEngineEventAPI

*Defined at line 4094 of ./engine/client/cl_game.cpp*

Inherits from IEngineEvents



## Functions

### GetParentInterface

*public const char * GetParentInterface()*

*Defined at line 4097 of ./engine/client/cl_game.cpp*

### GetName

*public const char * GetName()*

*Defined at line 4098 of ./engine/client/cl_game.cpp*

### PreInit

*public _Bool PreInit()*

*Defined at line 4099 of ./engine/client/cl_game.cpp*

### Init

*public _Bool Init()*

*Defined at line 4100 of ./engine/client/cl_game.cpp*

### Shutdown

*public void Shutdown()*

*Defined at line 4101 of ./engine/client/cl_game.cpp*

### PlaySound

*public void PlaySound(int ent, float * origin, int channel, const char * sample, float volume, float attenuation, int fFlags, int pitch)*

*Defined at line 4103 of ./engine/client/cl_game.cpp*

### StopSound

*public void StopSound(int ent, int channel, const char * sample)*

*Defined at line 4108 of ./engine/client/cl_game.cpp*

### FindModelIndex

*public int FindModelIndex(const char * pmodel)*

*Defined at line 4113 of ./engine/client/cl_game.cpp*

### IsLocal

*public int IsLocal(int playernum)*

*Defined at line 4118 of ./engine/client/cl_game.cpp*

### LocalPlayerDucking

*public int LocalPlayerDucking()*

*Defined at line 4123 of ./engine/client/cl_game.cpp*

### LocalPlayerViewheight

*public void LocalPlayerViewheight(float * off)*

*Defined at line 4128 of ./engine/client/cl_game.cpp*

### LocalPlayerBounds

*public void LocalPlayerBounds(int hull, float * mins, float * maxs)*

*Defined at line 4133 of ./engine/client/cl_game.cpp*

### IndexFromTrace

*public int IndexFromTrace(struct pmtrace_s * pTrace)*

*Defined at line 4138 of ./engine/client/cl_game.cpp*

### GetPhysent

*public struct physent_s * GetPhysent(int idx)*

*Defined at line 4143 of ./engine/client/cl_game.cpp*

### SetUpPlayerPrediction

*public void SetUpPlayerPrediction(int dopred, int bIncludeLocalClient)*

*Defined at line 4148 of ./engine/client/cl_game.cpp*

### PushPMStates

*public void PushPMStates()*

*Defined at line 4153 of ./engine/client/cl_game.cpp*

### PopPMStates

*public void PopPMStates()*

*Defined at line 4158 of ./engine/client/cl_game.cpp*

### SetSolidPlayers

*public void SetSolidPlayers(int playernum)*

*Defined at line 4163 of ./engine/client/cl_game.cpp*

### SetTraceHull

*public void SetTraceHull(int hull)*

*Defined at line 4168 of ./engine/client/cl_game.cpp*

### PlayerTrace

*public void PlayerTrace(float * start, float * end, int traceFlags, int ignore_pe, struct pmtrace_s * tr)*

*Defined at line 4173 of ./engine/client/cl_game.cpp*

### WeaponAnimation

*public void WeaponAnimation(int sequence, int body)*

*Defined at line 4178 of ./engine/client/cl_game.cpp*

### PrecacheEvent

*public unsigned short PrecacheEvent(int type, const char * psz)*

*Defined at line 4183 of ./engine/client/cl_game.cpp*

### PlaybackEvent

*public void PlaybackEvent(int flags, const struct edict_s * pInvoker, unsigned short eventindex, float delay, float * origin, float * angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2)*

*Defined at line 4188 of ./engine/client/cl_game.cpp*

### TraceTexture

*public const char * TraceTexture(int ground, float * vstart, float * vend)*

*Defined at line 4193 of ./engine/client/cl_game.cpp*

### StopAllSounds

*public void StopAllSounds(int entnum, int entchannel)*

*Defined at line 4198 of ./engine/client/cl_game.cpp*

### KillEvents

*public void KillEvents(int entnum, const char * eventname)*

*Defined at line 4203 of ./engine/client/cl_game.cpp*

### PlayerTraceExt

*public void PlayerTraceExt(float * start, float * end, int traceFlags, int (*)(struct physent_s *) pfnIgnore, struct pmtrace_s * tr)*

*Defined at line 4209 of ./engine/client/cl_game.cpp*

### SoundForIndex

*public const char * SoundForIndex(int index)*

*Defined at line 4214 of ./engine/client/cl_game.cpp*

### TraceSurface

*public struct msurface_s * TraceSurface(int ground, float * vstart, float * vend)*

*Defined at line 4219 of ./engine/client/cl_game.cpp*

### GetMovevars

*public struct movevars_s * GetMovevars()*

*Defined at line 4224 of ./engine/client/cl_game.cpp*

### VisTraceLine

*public struct pmtrace_s * VisTraceLine(float * start, float * end, int flags)*

*Defined at line 4229 of ./engine/client/cl_game.cpp*

### GetVisent

*public struct physent_s * GetVisent(int idx)*

*Defined at line 4234 of ./engine/client/cl_game.cpp*

### TestLine

*public int TestLine(const vec3_t start, const vec3_t end, int flags)*

*Defined at line 4239 of ./engine/client/cl_game.cpp*

### PushTraceBounds

*public void PushTraceBounds(int hullnum, const float * mins, const float * maxs)*

*Defined at line 4244 of ./engine/client/cl_game.cpp*

### PopTraceBounds

*public void PopTraceBounds()*

*Defined at line 4249 of ./engine/client/cl_game.cpp*



