# struct cldll_func_s

*Defined at line 27 of ./engine/cdll_exp.h*

 NOTE: ordering is important!



## Members

public int (*)(cl_enginefunc_t *, int) pfnInitialize

public void (*)(void) pfnInit

public int (*)(void) pfnVidInit

public int (*)(float, int) pfnRedraw

public int (*)(client_data_t *, float) pfnUpdateClientData

public void (*)(void) pfnReset

public void (*)(struct playermove_s *, int) pfnPlayerMove

public void (*)(struct playermove_s *) pfnPlayerMoveInit

public char (*)(char *) pfnPlayerMoveTexture

public void (*)(void) IN_ActivateMouse

public void (*)(void) IN_DeactivateMouse

public void (*)(int) IN_MouseEvent

public void (*)(void) IN_ClearStates

public void (*)(void) IN_Accumulate

public void (*)(float, struct usercmd_s *, int) CL_CreateMove

public int (*)(void) CL_IsThirdPerson

public void (*)(float *) CL_CameraOffset

public void *(*)(const char *) KB_Find

public void (*)(void) CAM_Think

public void (*)(ref_params_t *) pfnCalcRefdef

public int (*)(int, cl_entity_t *, const char *) pfnAddEntity

public void (*)(void) pfnCreateEntities

public void (*)(void) pfnDrawNormalTriangles

public void (*)(void) pfnDrawTransparentTriangles

public void (*)(const struct mstudioevent_s *, const cl_entity_t *) pfnStudioEvent

public void (*)(struct local_state_s *, struct local_state_s *, usercmd_t *, int, double, unsigned int) pfnPostRunCmd

public void (*)(void) pfnShutdown

public void (*)(entity_state_t *, const clientdata_t *) pfnTxferLocalOverrides

public void (*)(entity_state_t *, const entity_state_t *) pfnProcessPlayerState

public void (*)(entity_state_t *, const entity_state_t *, clientdata_t *, const clientdata_t *, weapon_data_t *, const weapon_data_t *) pfnTxferPredictionData

public void (*)(int, byte *) pfnDemo_ReadBuffer

public int (*)(const struct netadr_s *, const char *, char *, int *) pfnConnectionlessPacket

public int (*)(int, float *, float *) pfnGetHullBounds

public void (*)(double) pfnFrame

public int (*)(int, int, const char *) pfnKey_Event

public void (*)(double, double, double, struct tempent_s **, struct tempent_s **, int (*)(cl_entity_t *), void (*)(struct tempent_s *, float)) pfnTempEntUpdate

public cl_entity_t *(*)(int) pfnGetUserEntity

public void (*)(int, qboolean) pfnVoiceStatus

public void (*)(int, void *) pfnDirectorMessage

public int (*)(int, struct r_studio_interface_s **, struct engine_studio_api_s *) pfnGetStudioModelInterface

public void (*)(int *, int *) pfnChatInputPosition

public int (*)(int, render_api_t *, render_interface_t *) pfnGetRenderInterface

public void (*)(struct physent_s *, const vec_t *, vec_t *, vec_t *, const vec_t *, struct pmtrace_s *) pfnClipMoveToEntity

public int (*)(int, int, float, float, float, float) pfnTouchEvent

public void (*)(float, float) pfnMoveEvent

public void (*)(float, float) pfnLookEvent



