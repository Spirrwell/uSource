# class CServerInterface

*Defined at line 37 of ./game/server/cbase.cpp*

Inherits from IServerInterface



## Functions

### GetParentInterface

*public const char * GetParentInterface()*

*Defined at line 40 of ./game/server/cbase.cpp*

### GetName

*public const char * GetName()*

*Defined at line 42 of ./game/server/cbase.cpp*

### PreInit

*public _Bool PreInit()*

*Defined at line 44 of ./game/server/cbase.cpp*

### Init

*public _Bool Init()*

*Defined at line 46 of ./game/server/cbase.cpp*

### Shutdown

*public void Shutdown()*

*Defined at line 48 of ./game/server/cbase.cpp*

### GameInit

*public void GameInit()*

*Defined at line 50 of ./game/server/cbase.cpp*

### Spawn

*public int Spawn(edict_t * pent)*

*Defined at line 55 of ./game/server/cbase.cpp*

### Think

*public void Think(edict_t * pent)*

*Defined at line 60 of ./game/server/cbase.cpp*

### Use

*public void Use(edict_t * pentUsed, edict_t * pentOther)*

*Defined at line 65 of ./game/server/cbase.cpp*

### Touch

*public void Touch(edict_t * pentTouched, edict_t * pentOther)*

*Defined at line 70 of ./game/server/cbase.cpp*

### Blocked

*public void Blocked(edict_t * pentBlocked, edict_t * pentOther)*

*Defined at line 75 of ./game/server/cbase.cpp*

### KeyValue

*public void KeyValue(edict_t * pentKeyvalue, KeyValueData * pkvd)*

*Defined at line 80 of ./game/server/cbase.cpp*

### Save

*public void Save(edict_t * pent, SAVERESTOREDATA * pSaveData)*

*Defined at line 85 of ./game/server/cbase.cpp*

### Restore

*public int Restore(edict_t * pent, SAVERESTOREDATA * pSaveData, int globalEntity)*

*Defined at line 90 of ./game/server/cbase.cpp*

### SetAbsBox

*public void SetAbsBox(edict_t * pent)*

*Defined at line 95 of ./game/server/cbase.cpp*

### SaveWriteFields

*public void SaveWriteFields(SAVERESTOREDATA * pSaveData, const char * pname, void * pBaseData, TYPEDESCRIPTION * pFields, int cnt)*

*Defined at line 100 of ./game/server/cbase.cpp*

### SaveReadFields

*public void SaveReadFields(SAVERESTOREDATA * data, const char * c, void * v, TYPEDESCRIPTION * pFields, int cnt)*

*Defined at line 105 of ./game/server/cbase.cpp*

### SaveGlobalState

*public void SaveGlobalState(SAVERESTOREDATA * data)*

*Defined at line 110 of ./game/server/cbase.cpp*

### RestoreGlobalState

*public void RestoreGlobalState(SAVERESTOREDATA * data)*

*Defined at line 115 of ./game/server/cbase.cpp*

### ResetGlobalState

*public void ResetGlobalState()*

*Defined at line 120 of ./game/server/cbase.cpp*

### ClientConnect

*public qboolean ClientConnect(edict_t * pEntity, const char * pszName, const char * pszAddress, char [128] szRejectReason)*

*Defined at line 125 of ./game/server/cbase.cpp*

### ClientDisconnect

*public void ClientDisconnect(edict_t * pEntity)*

*Defined at line 130 of ./game/server/cbase.cpp*

### ClientKill

*public void ClientKill(edict_t * pEntity)*

*Defined at line 135 of ./game/server/cbase.cpp*

### ClientPutInServer

*public void ClientPutInServer(edict_t * pEntity)*

*Defined at line 140 of ./game/server/cbase.cpp*

### ClientCommand

*public void ClientCommand(edict_t * pEntity)*

*Defined at line 145 of ./game/server/cbase.cpp*

### ClientUserInfoChanged

*public void ClientUserInfoChanged(edict_t * pEntity, char * infobuffer)*

*Defined at line 150 of ./game/server/cbase.cpp*

### ServerActivate

*public void ServerActivate(edict_t * pEdictList, int edictCount, int clientMax)*

*Defined at line 155 of ./game/server/cbase.cpp*

### ServerDeactivate

*public void ServerDeactivate()*

*Defined at line 160 of ./game/server/cbase.cpp*

### PlayerPreThink

*public void PlayerPreThink(edict_t * pEntity)*

*Defined at line 165 of ./game/server/cbase.cpp*

### PlayerPostThink

*public void PlayerPostThink(edict_t * pEntity)*

*Defined at line 170 of ./game/server/cbase.cpp*

### StartFrame

*public void StartFrame()*

*Defined at line 175 of ./game/server/cbase.cpp*

### ParmsNewLevel

*public void ParmsNewLevel()*

*Defined at line 180 of ./game/server/cbase.cpp*

### ParmsChangeLevel

*public void ParmsChangeLevel()*

*Defined at line 185 of ./game/server/cbase.cpp*

### GetGameDescription

*public const char * GetGameDescription()*

*Defined at line 191 of ./game/server/cbase.cpp*

 Returns string describing current .dll.  E.g., TeamFotrress 2, Half-Life

### PlayerCustomization

*public void PlayerCustomization(edict_t * pEntity, customization_t * pCustom)*

*Defined at line 198 of ./game/server/cbase.cpp*

 Notify dll about a player customization.

### SpectatorConnect

*public void SpectatorConnect(edict_t * pEntity)*

*Defined at line 203 of ./game/server/cbase.cpp*

### SpectatorDisconnect

*public void SpectatorDisconnect(edict_t * pEntity)*

*Defined at line 208 of ./game/server/cbase.cpp*

### SpectatorThink

*public void SpectatorThink(edict_t * pEntity)*

*Defined at line 213 of ./game/server/cbase.cpp*

### Sys_Error

*public void Sys_Error(const char * error_string)*

*Defined at line 219 of ./game/server/cbase.cpp*

 Notify game .dll that engine is going to shut down. Allows mod authors to set a breakpoint.

### PM_Move

*public void PM_Move(struct playermove_s * ppmove, qboolean server)*

*Defined at line 224 of ./game/server/cbase.cpp*

### PM_Init

*public void PM_Init(struct playermove_s * ppmove)*

*Defined at line 229 of ./game/server/cbase.cpp*

### PM_FindTextureType

*public char PM_FindTextureType(char * name)*

*Defined at line 234 of ./game/server/cbase.cpp*

### SetupVisibility

*public void SetupVisibility(struct edict_s * pViewEntity, struct edict_s * pClient, unsigned char ** pvs, unsigned char ** pas)*

*Defined at line 239 of ./game/server/cbase.cpp*

### UpdateClientData

*public void UpdateClientData(const struct edict_s * ent, int sendweapons, struct clientdata_s * cd)*

*Defined at line 244 of ./game/server/cbase.cpp*

### AddToFullPack

*public int AddToFullPack(struct entity_state_s * state, int e, edict_t * ent, edict_t * host, int hostflags, int player, unsigned char * pSet)*

*Defined at line 249 of ./game/server/cbase.cpp*

### CreateBaseline

*public void CreateBaseline(int player, int eindex, struct entity_state_s * baseline, struct edict_s * entity, int playermodelindex, float * player_mins, float * player_maxs)*

*Defined at line 254 of ./game/server/cbase.cpp*

### RegisterEncoders

*public void RegisterEncoders()*

*Defined at line 259 of ./game/server/cbase.cpp*

### GetWeaponData

*public int GetWeaponData(struct edict_s * player, struct weapon_data_s * info)*

*Defined at line 264 of ./game/server/cbase.cpp*

### CmdStart

*public void CmdStart(const edict_t * player, const struct usercmd_s * cmd, unsigned int random_seed)*

*Defined at line 269 of ./game/server/cbase.cpp*

### CmdEnd

*public void CmdEnd(const edict_t * player)*

*Defined at line 274 of ./game/server/cbase.cpp*

### ConnectionlessPacket

*public int ConnectionlessPacket(const struct netadr_s * net_from, const char * args, char * response_buffer, int * response_buffer_size)*

*Defined at line 279 of ./game/server/cbase.cpp*

### GetHullBounds

*public int GetHullBounds(int hullnumber, float * mins, float * maxs)*

*Defined at line 284 of ./game/server/cbase.cpp*

### CreateInstancedBaselines

*public void CreateInstancedBaselines()*

*Defined at line 289 of ./game/server/cbase.cpp*

### InconsistentFile

*public int InconsistentFile(const struct edict_s * player, const char * filename, char * disconnect_message)*

*Defined at line 294 of ./game/server/cbase.cpp*

### AllowLagCompensation

*public int AllowLagCompensation()*

*Defined at line 299 of ./game/server/cbase.cpp*



