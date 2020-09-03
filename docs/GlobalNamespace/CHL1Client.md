# class CHL1Client

*Defined at line 103 of ./game/client/client_int.cpp*

Inherits from IClientInterface



## Functions

### GetParentInterface

*public const char * GetParentInterface()*

*Defined at line 106 of ./game/client/client_int.cpp*

### GetName

*public const char * GetName()*

*Defined at line 107 of ./game/client/client_int.cpp*

### PreInit

*public _Bool PreInit()*

*Defined at line 108 of ./game/client/client_int.cpp*

### Init

*public _Bool Init()*

*Defined at line 110 of ./game/client/client_int.cpp*

### InitHud

*public void InitHud()*

*Defined at line 119 of ./game/client/client_int.cpp*

### Shutdown

*public void Shutdown()*

*Defined at line 124 of ./game/client/client_int.cpp*

### Initialize

*public int Initialize(cl_enginefunc_t * pEnginefuncs, int iVersion)*

*Defined at line 126 of ./game/client/client_int.cpp*

### VidInit

*public int VidInit()*

*Defined at line 131 of ./game/client/client_int.cpp*

### Redraw

*public int Redraw(float flTime, int intermission)*

*Defined at line 136 of ./game/client/client_int.cpp*

### UpdateClientData

*public int UpdateClientData(client_data_t * cdata, float flTime)*

*Defined at line 141 of ./game/client/client_int.cpp*

### Reset

*public void Reset()*

*Defined at line 146 of ./game/client/client_int.cpp*

### PlayerMove

*public void PlayerMove(struct playermove_s * ppmove, int server)*

*Defined at line 151 of ./game/client/client_int.cpp*

### PlayerMoveInit

*public void PlayerMoveInit(struct playermove_s * ppmove)*

*Defined at line 156 of ./game/client/client_int.cpp*

### PlayerMoveTexture

*public char PlayerMoveTexture(char * name)*

*Defined at line 161 of ./game/client/client_int.cpp*

### CL_CreateMove

*public void CL_CreateMove(float frametime, struct usercmd_s * cmd, int active)*

*Defined at line 166 of ./game/client/client_int.cpp*

### CL_IsThirdPerson

*public int CL_IsThirdPerson()*

*Defined at line 171 of ./game/client/client_int.cpp*

### CL_CameraOffset

*public void CL_CameraOffset(float * ofs)*

*Defined at line 176 of ./game/client/client_int.cpp*

### CAM_Think

*public void CAM_Think()*

*Defined at line 181 of ./game/client/client_int.cpp*

### CalcRefdef

*public void CalcRefdef(ref_params_t * pparams)*

*Defined at line 186 of ./game/client/client_int.cpp*

### AddEntity

*public int AddEntity(int type, cl_entity_t * ent, const char * modelname)*

*Defined at line 191 of ./game/client/client_int.cpp*

### CreateEntities

*public void CreateEntities()*

*Defined at line 196 of ./game/client/client_int.cpp*

### DrawNormalTriangles

*public void DrawNormalTriangles()*

*Defined at line 201 of ./game/client/client_int.cpp*

### DrawTransparentTriangles

*public void DrawTransparentTriangles()*

*Defined at line 206 of ./game/client/client_int.cpp*

### StudioEvent

*public void StudioEvent(const struct mstudioevent_s * event, const cl_entity_t * entity)*

*Defined at line 211 of ./game/client/client_int.cpp*

### PostRunCmd

*public void PostRunCmd(struct local_state_s * from, struct local_state_s * to, usercmd_t * cmd, int runfuncs, double time, unsigned int random_seed)*

*Defined at line 216 of ./game/client/client_int.cpp*

### GameShutdown

*public void GameShutdown()*

*Defined at line 221 of ./game/client/client_int.cpp*

### TxferLocalOverrides

*public void TxferLocalOverrides(entity_state_t * state, const clientdata_t * client)*

*Defined at line 226 of ./game/client/client_int.cpp*

### ProcessPlayerState

*public void ProcessPlayerState(entity_state_t * dst, const entity_state_t * src)*

*Defined at line 231 of ./game/client/client_int.cpp*

### TxferPredictionData

*public void TxferPredictionData(entity_state_t * ps, const entity_state_t * pps, clientdata_t * pcd, const clientdata_t * ppcd, weapon_data_t * wd, const weapon_data_t * pwd)*

*Defined at line 236 of ./game/client/client_int.cpp*

### Demo_ReadBuffer

*public void Demo_ReadBuffer(int size, byte * buffer)*

*Defined at line 241 of ./game/client/client_int.cpp*

### ConnectionlessPacket

*public int ConnectionlessPacket(const struct netadr_s * net_from, const char * args, char * buffer, int * size)*

*Defined at line 246 of ./game/client/client_int.cpp*

### GetHullBounds

*public int GetHullBounds(int hullnumber, float * mins, float * maxs)*

*Defined at line 251 of ./game/client/client_int.cpp*

### Frame

*public void Frame(double time)*

*Defined at line 256 of ./game/client/client_int.cpp*

### TempEntUpdate

*public void TempEntUpdate(double frametime, double client_time, double cl_gravity, struct tempent_s ** ppTempEntFree, struct tempent_s ** ppTempEntActive, int (*)(cl_entity_t *) Callback_AddVisibleEntity, void (*)(struct tempent_s *, float) Callback_TempEntPlaySound)*

*Defined at line 261 of ./game/client/client_int.cpp*

### GetUserEntity

*public cl_entity_t * GetUserEntity(int index)*

*Defined at line 266 of ./game/client/client_int.cpp*

### VoiceStatus

*public void VoiceStatus(int entindex, qboolean bTalking)*

*Defined at line 271 of ./game/client/client_int.cpp*

### DirectorMessage

*public void DirectorMessage(int iSize, void * pbuf)*

*Defined at line 276 of ./game/client/client_int.cpp*

### ChatInputPosition

*public void ChatInputPosition(int * x, int * y)*

*Defined at line 281 of ./game/client/client_int.cpp*

### ClipMoveToEntity

*public void ClipMoveToEntity(struct physent_s * pe, Vector start, Vector mins, Vector maxs, Vector end, struct pmtrace_s * tr)*

*Defined at line 286 of ./game/client/client_int.cpp*



