# class IServerInterface

*Defined at line 16 of ./engine/server_int.h*

Inherits from IAppInterface



## Functions

### GameInit

*public void GameInit()*

 Initialize/shutdown the game (one-time call after loading of game .dll )

### Spawn

*public int Spawn(edict_t * pent)*

### Think

*public void Think(edict_t * pent)*

### Use

*public void Use(edict_t * pentUsed, edict_t * pentOther)*

### Touch

*public void Touch(edict_t * pentTouched, edict_t * pentOther)*

### Blocked

*public void Blocked(edict_t * pentBlocked, edict_t * pentOther)*

### KeyValue

*public void KeyValue(edict_t * pentKeyvalue, KeyValueData * pkvd)*

### Save

*public void Save(edict_t * pent, SAVERESTOREDATA * pSaveData)*

### Restore

*public int Restore(edict_t * pent, SAVERESTOREDATA * pSaveData, int globalEntity)*

### SetAbsBox

*public void SetAbsBox(edict_t * pent)*

### SaveWriteFields

*public void SaveWriteFields(SAVERESTOREDATA * , const char * , void * , TYPEDESCRIPTION * , int )*

### SaveReadFields

*public void SaveReadFields(SAVERESTOREDATA * , const char * , void * , TYPEDESCRIPTION * , int )*

### SaveGlobalState

*public void SaveGlobalState(SAVERESTOREDATA * )*

### RestoreGlobalState

*public void RestoreGlobalState(SAVERESTOREDATA * )*

### ResetGlobalState

*public void ResetGlobalState()*

### ClientConnect

*public qboolean ClientConnect(edict_t * pEntity, const char * pszName, const char * pszAddress, char [128] szRejectReason)*

### ClientDisconnect

*public void ClientDisconnect(edict_t * pEntity)*

### ClientKill

*public void ClientKill(edict_t * pEntity)*

### ClientPutInServer

*public void ClientPutInServer(edict_t * pEntity)*

### ClientCommand

*public void ClientCommand(edict_t * pEntity)*

### ClientUserInfoChanged

*public void ClientUserInfoChanged(edict_t * pEntity, char * infobuffer)*

### ServerActivate

*public void ServerActivate(edict_t * pEdictList, int edictCount, int clientMax)*

### ServerDeactivate

*public void ServerDeactivate()*

### PlayerPreThink

*public void PlayerPreThink(edict_t * pEntity)*

### PlayerPostThink

*public void PlayerPostThink(edict_t * pEntity)*

### StartFrame

*public void StartFrame()*

### ParmsNewLevel

*public void ParmsNewLevel()*

### ParmsChangeLevel

*public void ParmsChangeLevel()*

### GetGameDescription

*public const char * GetGameDescription()*

 Returns string describing current .dll.  E.g., TeamFotrress 2, Half-Life

### PlayerCustomization

*public void PlayerCustomization(edict_t * pEntity, customization_t * pCustom)*

 Notify dll about a player customization.

### SpectatorConnect

*public void SpectatorConnect(edict_t * pEntity)*

 Spectator funcs

### SpectatorDisconnect

*public void SpectatorDisconnect(edict_t * pEntity)*

### SpectatorThink

*public void SpectatorThink(edict_t * pEntity)*

### Sys_Error

*public void Sys_Error(const char * error_string)*

 Notify game .dll that engine is going to shut down. Allows mod authors to set a breakpoint.

### PM_Move

*public void PM_Move(struct playermove_s * ppmove, qboolean server)*

### PM_Init

*public void PM_Init(struct playermove_s * ppmove)*

### PM_FindTextureType

*public char PM_FindTextureType(char * name)*

### SetupVisibility

*public void SetupVisibility(struct edict_s * pViewEntity, struct edict_s * pClient, unsigned char ** pvs, unsigned char ** pas)*

### UpdateClientData

*public void UpdateClientData(const struct edict_s * ent, int sendweapons, struct clientdata_s * cd)*

### AddToFullPack

*public int AddToFullPack(struct entity_state_s * state, int e, edict_t * ent, edict_t * host, int hostflags, int player, unsigned char * pSet)*

### CreateBaseline

*public void CreateBaseline(int player, int eindex, struct entity_state_s * baseline, struct edict_s * entity, int playermodelindex, float * player_mins, float * player_maxs)*

### RegisterEncoders

*public void RegisterEncoders()*

### GetWeaponData

*public int GetWeaponData(struct edict_s * player, struct weapon_data_s * info)*

### CmdStart

*public void CmdStart(const edict_t * player, const struct usercmd_s * cmd, unsigned int random_seed)*

### CmdEnd

*public void CmdEnd(const edict_t * player)*

### ConnectionlessPacket

*public int ConnectionlessPacket(const struct netadr_s * net_from, const char * args, char * response_buffer, int * response_buffer_size)*

 Return 1 if the packet is valid.  Set response_buffer_size if you want to send a response packet.  Incoming, it holds the max  size of the response_buffer, so you must zero it out if you choose not to respond.

### GetHullBounds

*public int GetHullBounds(int hullnumber, float * mins, float * maxs)*

 Enumerates player hulls.  Returns 0 if the hull number doesn't exist, 1 otherwise

### CreateInstancedBaselines

*public void CreateInstancedBaselines()*

 Create baselines for certain "unplaced" items.

### InconsistentFile

*public int InconsistentFile(const struct edict_s * player, const char * filename, char * disconnect_message)*

 One of the pfnForceUnmodified files failed the consistency check for the specified player Return 0 to allow the client to continue, 1 to force immediate disconnection ( with an optional disconnect message of up to 256 characters )

### AllowLagCompensation

*public int AllowLagCompensation()*

 The game .dll should return 1 if lag compensation should be allowed ( could also just set  the sv_unlag cvar. Most games right now should return 0, until client-side weapon prediction code is written  and tested for them.



