# struct server_s

*Defined at line 117 of ./engine/server/server.h*

## Members

public sv_state_t state

public qboolean background

public qboolean loadgame

public double time

public double time_residual

public float frametime

public int framecount

public struct sv_client_s * current_client

public int hostflags

public CRC32_t worldmapCRC

public int progsCRC

public char [64] name

public char [64] startspot

public double lastchecktime

public int lastcheck

public char [1024][64] model_precache

public char [2048][64] sound_precache

public char [1024][64] files_precache

public char [1024][64] event_precache

public byte [1024] model_precache_flags

public model_t *[1024] models

public int num_static_entities

public lightstyle_t [64] lightstyles

public consistency_t [1024] consistency_list

public resource_t [5120] resources

public int num_consistency

public int num_resources

public sv_baseline_t [64] instanced

public int last_valid_baseline

public int num_instanced

sizebuf_s datagram

public byte [16384] datagram_buf

sizebuf_s reliable_datagram

public byte [16384] reliable_datagram_buf

sizebuf_s multicast

public byte [8192] multicast_buf

sizebuf_s signon

public byte [131072] signon_buf

sizebuf_s spec_datagram

public byte [8192] spectator_buf

public model_t * worldmodel

public qboolean playersonly

public qboolean simulating

public qboolean paused

public int ignored_static_ents

public int ignored_world_decals

public int static_ents_overflow



