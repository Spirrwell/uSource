# struct render_interface_s

*Defined at line 247 of ./common/render_api.h*

 render callbacks



## Members

public int version

public int (*)(const struct ref_viewpass_s *) GL_RenderFrame

public void (*)(void) GL_BuildLightmaps

public void (*)(const float *, const float *) GL_OrthoBounds

public int (*)(decallist_t *, int) R_CreateStudioDecalList

public void (*)(void) R_ClearStudioDecals

public qboolean (*)(char *, size_t) R_SpeedsMessage

public void (*)(struct model_s *, qboolean, const byte *) Mod_ProcessUserData

public void (*)(qboolean) R_ProcessEntData

public byte *(*)(void) Mod_GetCurrentVis

public void (*)(void) R_NewMap

public void (*)(void) R_ClearScene

public void (*)(struct cl_entity_s *, qboolean) CL_UpdateLatchedVars



