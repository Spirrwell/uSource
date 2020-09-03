# class IEngineInterface

*Defined at line 116 of ./engine/engine_int.h*

Inherits from IAppInterface



## Functions

### PrecacheModel

*public int PrecacheModel(const char * s)*

### PrecacheSound

*public int PrecacheSound(const char * s)*

### SetModel

*public void SetModel(edict_t * e, const char * m)*

### ModelIndex

*public int ModelIndex(const char * m)*

### ModelFrames

*public int ModelFrames(int modelIndex)*

### SetSize

*public void SetSize(edict_t * e, const float * rgflMin, const float * rgflMax)*

### ChangeLevel

*public void ChangeLevel(const char * s1, const char * s2)*

### GetSpawnParms

*public void GetSpawnParms(edict_t * ent)*

### SaveSpawnParms

*public void SaveSpawnParms(edict_t * ent)*

### VecToYaw

*public float VecToYaw(const float * rgflVector)*

### VecToAngles

*public void VecToAngles(const float * rgflVectorIn, float * rgflVectorOut)*

### MoveToOrigin

*public void MoveToOrigin(edict_t * ent, const float * pflGoal, float dist, int iMoveType)*

### ChangeYaw

*public void ChangeYaw(edict_t * ent)*

### ChangePitch

*public void ChangePitch(edict_t * ent)*

### FindEntityByString

*public edict_t * FindEntityByString(edict_t * pEdictStartSearchAfter, const char * pszField, const char * pszValue)*

### GetEntityIllum

*public int GetEntityIllum(edict_t * pEnt)*

### FindEntityInSphere

*public edict_t * FindEntityInSphere(edict_t * pEdictStartSearchAfter, const float * org, float rad)*

### FindClientInPVS

*public edict_t * FindClientInPVS(edict_t * pEdict)*

### EntitiesInPVS

*public edict_t * EntitiesInPVS(edict_t * pplayer)*

### MakeVectors

*public void MakeVectors(const float * rgflVector)*

### AngleVectors

*public void AngleVectors(const float * rgflVector, float * forward, float * right, float * up)*

### CreateEntity

*public edict_t * CreateEntity()*

### RemoveEntity

*public void RemoveEntity(edict_t * e)*

### CreateNamedEntity

*public edict_t * CreateNamedEntity(int className)*

### MakeStatic

*public void MakeStatic(edict_t * ent)*

### EntIsOnFloor

*public int EntIsOnFloor(edict_t * e)*

### DropToFloor

*public int DropToFloor(edict_t * e)*

### WalkMove

*public int WalkMove(edict_t * ent, float yaw, float dist, int iMode)*

### SetOrigin

*public void SetOrigin(edict_t * e, const float * rgflOrigin)*

### EmitSound

*public void EmitSound(edict_t * entity, int channel, const char * sample, float volume, float attenuation, int fFlags, int pitch)*

### EmitAmbientSound

*public void EmitAmbientSound(edict_t * entity, float * pos, const char * samp, float vol, float attenuation, int fFlags, int pitch)*

### GetAimVector

*public void GetAimVector(edict_t * ent, float speed, float * rgflReturn)*

### ServerCommand

*public void ServerCommand(const char * str)*

### ServerExecute

*public void ServerExecute()*

### ClientCommand

*public void ClientCommand(edict_t * pEdict, char * szFmt)*

### ParticleEffect

*public void ParticleEffect(const float * org, const float * dir, float color, float count)*

### LightStyle

*public void LightStyle(int style, const char * val)*

### DecalIndex

*public int DecalIndex(const char * name)*

### PointContents

*public int PointContents(const float * rgflVector)*

### MessageBegin

*public void MessageBegin(int msg_dest, int msg_type, const float * pOrigin, edict_t * ed)*

### MessageEnd

*public void MessageEnd()*

### WriteByte

*public void WriteByte(int iValue)*

### WriteChar

*public void WriteChar(int iValue)*

### WriteShort

*public void WriteShort(int iValue)*

### WriteLong

*public void WriteLong(int iValue)*

### WriteAngle

*public void WriteAngle(float flValue)*

### WriteCoord

*public void WriteCoord(float flValue)*

### WriteString

*public void WriteString(const char * sz)*

### WriteEntity

*public void WriteEntity(int iValue)*

### AlertMessage

*public void AlertMessage(ALERT_TYPE atype, char * szFmt)*

### EngineFprintf

*public void EngineFprintf(FILE * pfile, char * szFmt)*

### PvAllocEntPrivateData

*public void * PvAllocEntPrivateData(edict_t * pEdict, long cb)*

### PvEntPrivateData

*public void * PvEntPrivateData(edict_t * pEdict)*

### FreeEntPrivateData

*public void FreeEntPrivateData(edict_t * pEdict)*

### SzFromIndex

*public const char * SzFromIndex(int iString)*

### AllocString

*public int AllocString(const char * szValue)*

### GetVarsOfEnt

*public struct entvars_s * GetVarsOfEnt(edict_t * pEdict)*

### PEntityOfEntOffset

*public edict_t * PEntityOfEntOffset(int iEntOffset)*

### EntOffsetOfPEntity

*public int EntOffsetOfPEntity(const edict_t * pEdict)*

### IndexOfEdict

*public int IndexOfEdict(const edict_t * pEdict)*

### EntityOfEntIndex

*public edict_t * EntityOfEntIndex(int iEntIndex)*

### FindEntityByVars

*public edict_t * FindEntityByVars(struct entvars_s * pvars)*

### GetModelPtr

*public void * GetModelPtr(edict_t * pEdict)*

### RegUserMsg

*public int RegUserMsg(const char * pszName, int iSize)*

### AnimationAutomove

*public void AnimationAutomove(const edict_t * pEdict, float flTime)*

### GetBonePosition

*public void GetBonePosition(const edict_t * pEdict, int iBone, float * rgflOrigin, float * rgflAngles)*

### FunctionFromName

*public unsigned long FunctionFromName(const char * pName)*

### NameForFunction

*public const char * NameForFunction(unsigned long function)*

### ClientPrintf

*public void ClientPrintf(edict_t * pEdict, PRINT_TYPE ptype, const char * szMsg)*

### ServerPrint

*public void ServerPrint(const char * szMsg)*

### Cmd_Args

*public const char * Cmd_Args()*

### Cmd_Argv

*public const char * Cmd_Argv(int argc)*

### Cmd_Argc

*public int Cmd_Argc()*

### GetAttachment

*public void GetAttachment(const edict_t * pEdict, int iAttachment, float * rgflOrigin, float * rgflAngles)*

### CRC32_Init

*public void CRC32_Init(CRC32_t * pulCRC)*

### CRC32_ProcessBuffer

*public void CRC32_ProcessBuffer(CRC32_t * pulCRC, const void * p, int len)*

### CRC32_ProcessByte

*public void CRC32_ProcessByte(CRC32_t * pulCRC, unsigned char ch)*

### CRC32_Final

*public CRC32_t CRC32_Final(CRC32_t pulCRC)*

### RandomLong

*public int RandomLong(int lLow, int lHigh)*

### RandomFloat

*public float RandomFloat(float flLow, float flHigh)*

### SetView

*public void SetView(const edict_t * pClient, const edict_t * pViewent)*

### Time

*public float Time()*

### CrosshairAngle

*public void CrosshairAngle(const edict_t * pClient, float pitch, float yaw)*

### LoadFileForMe

*public byte * LoadFileForMe(const char * filename, int * pLength)*

### FreeFile

*public void FreeFile(void * buffer)*

### EndSection

*public void EndSection(const char * pszSectionName)*

### CompareFileTime

*public int CompareFileTime(const char * filename1, const char * filename2, int * iCompare)*

### GetGameDir

*public void GetGameDir(char * szGetGameDir)*

### FadeClientVolume

*public void FadeClientVolume(const edict_t * pEdict, int fadePercent, int fadeOutSeconds, int holdTime, int fadeInSeconds)*

### SetClientMaxspeed

*public void SetClientMaxspeed(const edict_t * pEdict, float fNewMaxspeed)*

### CreateFakeClient

*public edict_t * CreateFakeClient(const char * netname)*

### RunPlayerMove

*public void RunPlayerMove(edict_t * fakeclient, const float * viewangles, float forwardmove, float sidemove, float upmove, unsigned short buttons, byte impulse, byte msec)*

### NumberOfEntities

*public int NumberOfEntities()*

### GetInfoKeyBuffer

*public char * GetInfoKeyBuffer(edict_t * e)*

### InfoKeyValue

*public const char * InfoKeyValue(const char * infobuffer, const char * key)*

### SetKeyValue

*public void SetKeyValue(char * infobuffer, char * key, char * value)*

### SetClientKeyValue

*public void SetClientKeyValue(int clientIndex, char * infobuffer, char * key, char * value)*

### IsMapValid

*public int IsMapValid(char * filename)*

### StaticDecal

*public void StaticDecal(const float * origin, int decalIndex, int entityIndex, int modelIndex)*

### PrecacheGeneric

*public int PrecacheGeneric(const char * s)*

### GetPlayerUserId

*public int GetPlayerUserId(edict_t * e)*

### BuildSoundMsg

*public void BuildSoundMsg(edict_t * entity, int channel, const char * sample, float volume, float attenuation, int fFlags, int pitch, int msg_dest, int msg_type, const float * pOrigin, edict_t * ed)*

### IsDedicatedServer

*public int IsDedicatedServer()*

### GetPlayerWONId

*public unsigned int GetPlayerWONId(edict_t * e)*

### Info_RemoveKey

*public void Info_RemoveKey(char * s, const char * key)*

### GetPhysicsKeyValue

*public const char * GetPhysicsKeyValue(const edict_t * pClient, const char * key)*

### SetPhysicsKeyValue

*public void SetPhysicsKeyValue(const edict_t * pClient, const char * key, const char * value)*

### GetPhysicsInfoString

*public const char * GetPhysicsInfoString(const edict_t * pClient)*

### PrecacheEvent

*public unsigned short PrecacheEvent(int type, const char * psz)*

### PlaybackEvent

*public void PlaybackEvent(int flags, const edict_t * pInvoker, unsigned short eventindex, float delay, float * origin, float * angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2)*

### SetFatPVS

*public unsigned char * SetFatPVS(const float * org)*

### SetFatPAS

*public unsigned char * SetFatPAS(const float * org)*

### CheckVisibility

*public int CheckVisibility(const edict_t * entity, unsigned char * pset)*

### DeltaSetField

*public void DeltaSetField(struct delta_s * pFields, const char * fieldname)*

### DeltaUnsetField

*public void DeltaUnsetField(struct delta_s * pFields, const char * fieldname)*

### DeltaAddEncoder

*public void DeltaAddEncoder(char * name, void (*)(struct delta_s *, const unsigned char *, const unsigned char *) conditionalencode)*

### GetCurrentPlayer

*public int GetCurrentPlayer()*

### CanSkipPlayer

*public int CanSkipPlayer(const edict_t * player)*

### DeltaFindField

*public int DeltaFindField(struct delta_s * pFields, const char * fieldname)*

### DeltaSetFieldByIndex

*public void DeltaSetFieldByIndex(struct delta_s * pFields, int fieldNumber)*

### DeltaUnsetFieldByIndex

*public void DeltaUnsetFieldByIndex(struct delta_s * pFields, int fieldNumber)*

### SetGroupMask

*public void SetGroupMask(int mask, int op)*

### CreateInstancedBaseline

*public int CreateInstancedBaseline(int classname, struct entity_state_s * baseline)*

### ForceUnmodified

*public void ForceUnmodified(FORCE_TYPE type, float * mins, float * maxs, const char * filename)*

### GetPlayerStats

*public void GetPlayerStats(const edict_t * pClient, int * ping, int * packet_loss)*

### Voice_GetClientListening

*public qboolean Voice_GetClientListening(int iReceiver, int iSender)*

### Voice_SetClientListening

*public qboolean Voice_SetClientListening(int iReceiver, int iSender, qboolean bListen)*

### GetPlayerAuthId

*public const char * GetPlayerAuthId(edict_t * e)*

### CheckParm

*public int CheckParm(char * parm, char ** ppnext)*



