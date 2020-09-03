# struct sv_client_s

*Defined at line 201 of ./engine/server/server.h*

## Members

public cl_state_t state

public cl_upload_t upstate

public char [32] name

public int flags

public CRC32_t crcValue

public char [256] userinfo

public char [256] physinfo

netchan_s netchan

public int chokecount

public int delta_sequence

public double next_messagetime

public double next_checkpingtime

public double next_sendinfotime

public double cl_updaterate

public double timebase

public double connection_started

public char [34] hashedcdkey

customization_s customdata

resource_s resourcesonhand

resource_s resourcesneeded

usercmd_s lastcmd

public double connecttime

public double cmdtime

public double ignorecmdtime

public int packet_loss

public float latency

public int ignored_ents

public edict_t * edict

public edict_t * pViewEntity

public edict_t *[128] viewentity

public int num_viewents

public qboolean m_bLoopback

public uint listeners

sizebuf_s datagram

public byte [16384] datagram_buf

public client_frame_t * frames

event_state_s events

public int challenge

public int userid

public int extensions

public char [256] useragent



