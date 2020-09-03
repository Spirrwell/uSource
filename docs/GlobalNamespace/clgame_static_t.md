# struct clgame_static_t

*Defined at line 433 of ./engine/client/client.h*

## Members

public void * hInstance

cldll_func_s dllFuncs

render_interface_s drawFuncs

public byte * mempool

public string mapname

public string maptitle

public string itemspath

public cl_entity_t * entities

public cl_entity_t * static_entities

public remap_info_t ** remap_info

public int maxEntities

public int maxRemapInfos

public int numStatics

public int maxModels

movevars_s movevars

movevars_s oldmovevars

public playermove_t * pmove

public qboolean pushed

public int oldviscount

public int oldphyscount

public cl_user_message_t [197] msg

public cl_user_event_t *[1024] events

public string [32] cdtracks

public model_t [256] sprites

public int [4] viewport

 ds

screenfade_s fade

 shake

 centerPrint

SCREENINFO_s scrInfo

ref_overview_s overView

public color24 [256] palette

public cached_spritelist_t [256] sprlist

public client_textmessage_t * titles

public int numTitles

public net_request_type_t request_type

public net_request_t [64] net_requests

public net_request_t * master_request

public efrag_t * free_efrags

cl_entity_s viewent

public qboolean client_dll_uses_sdl



