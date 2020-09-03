# struct client_static_t

*Defined at line 516 of ./engine/client/client.h*

## Members

public connstate_t state

public qboolean initialized

public qboolean changelevel

public qboolean changedemo

public double timestart

public float disable_screen

public int disable_servercount

public qboolean draw_changelevel

public keydest_t key_dest

public byte * mempool

netadr_s hltv_listen_address

public int signon

public int quakePort

public char [64] servername

public double connect_time

public int max_fragment_size

public int connect_retry

public qboolean spectator

local_state_s spectator_state

public char [256] userinfo

public char [256] physinfo

sizebuf_s datagram

public byte [16384] datagram_buf

netchan_s netchan

public int challenge

public float packet_loss

public double packet_loss_recalc_time

public int starting_count

public float nextcmdtime

public int lastoutgoingcommand

public int lastupdate_sequence

public int td_lastframe

public int td_startframe

public double td_starttime

public int forcetrack

public int pauseIcon

public int tileImage

public int loadingBar

 creditsFont

public float latency

public int num_client_entities

public int next_client_entities

public entity_state_t * packet_entities

public predicted_player_t [32] predicted_players

public double correction_time

public scrshot_t scrshot_request

public scrshot_t scrshot_action

public const float * envshot_vieworg

public int envshot_viewsize

public qboolean envshot_disable_vis

public string shotname

 dl

public int demonum

public int olddemonum

public char [32][64] demos

public qboolean demos_pending

public int movienum

public string [8] movies

public qboolean demorecording

public qboolean demoplayback

public qboolean demowaiting

public qboolean timedemo

public string demoname

public double demotime

public qboolean set_lastdemo

public file_t * demofile

public file_t * demoheader

public qboolean internetservers_wait

public qboolean internetservers_pending

public qboolean legacymode

netadr_s legacyserver

public netadr_t [32] legacyservers

public int legacyservercount

public int extensions

netadr_s serveradr



