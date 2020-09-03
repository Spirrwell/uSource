# class IClientInterface

*Defined at line 320 of ./common/../engine/client_int.h*

Inherits from IAppInterface



## Functions

### Initialize

*public int Initialize(cl_enginefunc_t * pEnginefuncs, int iVersion)*

### InitHud

*public void InitHud()*

### VidInit

*public int VidInit()*

### Redraw

*public int Redraw(float flTime, int intermission)*

### UpdateClientData

*public int UpdateClientData(client_data_t * cdata, float flTime)*

### Reset

*public void Reset()*

### PlayerMove

*public void PlayerMove(struct playermove_s * ppmove, int server)*

### PlayerMoveInit

*public void PlayerMoveInit(struct playermove_s * ppmove)*

### PlayerMoveTexture

*public char PlayerMoveTexture(char * name)*

### CL_CreateMove

*public void CL_CreateMove(float frametime, struct usercmd_s * cmd, int active)*

### CL_IsThirdPerson

*public int CL_IsThirdPerson()*

### CL_CameraOffset

*public void CL_CameraOffset(float * ofs)*

### CAM_Think

*public void CAM_Think()*

### CalcRefdef

*public void CalcRefdef(struct ref_params_s * pparams)*

### AddEntity

*public int AddEntity(int type, cl_entity_t * ent, const char * modelname)*

### CreateEntities

*public void CreateEntities()*

### DrawNormalTriangles

*public void DrawNormalTriangles()*

### DrawTransparentTriangles

*public void DrawTransparentTriangles()*

### StudioEvent

*public void StudioEvent(const struct mstudioevent_s * event, const cl_entity_t * entity)*

### PostRunCmd

*public void PostRunCmd(struct local_state_s * from, struct local_state_s * to, usercmd_t * cmd, int runfuncs, double time, unsigned int random_seed)*

### GameShutdown

*public void GameShutdown()*

### TxferLocalOverrides

*public void TxferLocalOverrides(entity_state_t * state, const clientdata_t * client)*

### ProcessPlayerState

*public void ProcessPlayerState(entity_state_t * dst, const entity_state_t * src)*

### TxferPredictionData

*public void TxferPredictionData(entity_state_t * ps, const entity_state_t * pps, clientdata_t * pcd, const clientdata_t * ppcd, weapon_data_t * wd, const weapon_data_t * pwd)*

### Demo_ReadBuffer

*public void Demo_ReadBuffer(int size, byte * buffer)*

### ConnectionlessPacket

*public int ConnectionlessPacket(const struct netadr_s * net_from, const char * args, char * buffer, int * size)*

### GetHullBounds

*public int GetHullBounds(int hullnumber, float * mins, float * maxs)*

### Frame

*public void Frame(double time)*

### TempEntUpdate

*public void TempEntUpdate(double frametime, double client_time, double cl_gravity, struct tempent_s ** ppTempEntFree, struct tempent_s ** ppTempEntActive, int (*)(cl_entity_t *) Callback_AddVisibleEntity, void (*)(struct tempent_s *, float) Callback_TempEntPlaySound)*

### GetUserEntity

*public cl_entity_t * GetUserEntity(int index)*

### VoiceStatus

*public void VoiceStatus(int entindex, qboolean bTalking)*

### DirectorMessage

*public void DirectorMessage(int iSize, void * pbuf)*

### ChatInputPosition

*public void ChatInputPosition(int * x, int * y)*

### ClipMoveToEntity

*public void ClipMoveToEntity(struct physent_s * pe, Vector start, Vector mins, Vector maxs, Vector end, struct pmtrace_s * tr)*

### ClipMoveToEntity

*public void ClipMoveToEntity(struct physent_s * pe, const vec3_t start, vec3_t mins, vec3_t maxs, const vec3_t end, struct pmtrace_s * tr)*



