# struct client_t

*Defined at line 173 of ./engine/client/client.h*

 the client_t structure is wiped completely at every server map change



## Members

public int servercount

public int validsequence

public int parsecount

public int parsecountmod

public qboolean video_prepped

public qboolean audio_prepped

public qboolean paused

public int delta_sequence

public double [2] mtime

public float lerpFrac

public int last_command_ack

public int last_incoming_sequence

public qboolean send_reply

public qboolean background

public qboolean first_frame

public qboolean proxy_redirect

public qboolean skip_interp

public uint checksum

public frame_t [64] frames

public runcmd_t [64] commands

public local_state_t [64] predicted_frames

public double time

public double oldtime

public float timedelta

public char [512] serverinfo

public player_info_t [32] players

public double lastresourcecheck

public string downloadUrl

event_state_s events

 local

public usercmd_t * cmd

public int viewentity

public vec3_t viewangles

public vec3_t viewheight

public vec3_t punchangle

public int intermission

public vec3_t crosshairangle

public pred_viewangle_t [16] predicted_angle

public int angle_position

public float addangletotal

public float prevaddangletotal

public vec3_t simorg

public vec3_t simvel

public int playernum

public int maxclients

public entity_state_t [64] instanced_baseline

public int instanced_baseline_count

public char [2048][64] sound_precache

public char [1024][64] event_precache

public char [1024][64] files_precache

public lightstyle_t [64] lightstyles

public model_t *[1025] models

public int nummodels

public int numfiles

public consistency_t [1024] consistency_list

public int num_consistency

public qboolean need_force_consistency_response

resource_s resourcesonhand

resource_s resourcesneeded

public resource_t [5120] resourcelist

public int num_resources

public short [2048] sound_index

public short [512] decal_index

public model_t * worldmodel

public int lostpackets



