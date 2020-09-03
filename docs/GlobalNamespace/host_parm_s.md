# struct host_parm_s

*Defined at line 387 of ./engine/common/common.h*

## Members

public HINSTANCE hInst

public HANDLE hMutex

public host_status_t status

 game

public uint type

public jmp_buf abortframe

public dword errorframe

public byte * mempool

public string finalmsg

public string downloadfile

public int downloadcount

public char [128] deferred_cmd

host_redirect_s rd

public int argc

public char ** argv

public double realtime

public double frametime

public double realframetime

public uint framecount

public char [512][64] draw_decals

public vec3_t [4] player_mins

public vec3_t [4] player_maxs

public void * hWnd

public qboolean allow_console

public qboolean allow_console_init

public qboolean key_overstrike

public qboolean stuffcmds_pending

public qboolean allow_cheats

public qboolean con_showalways

public qboolean com_handlecolon

public qboolean com_ignorebracket

public qboolean change_game

public qboolean mouse_visible

public qboolean shutdown_issued

public qboolean force_draw_version

public float force_draw_version_time

public qboolean apply_game_config

public qboolean apply_opengl_config

public qboolean config_executed

public int sv_cvars_restored

public qboolean crashed

public qboolean daemonized

public qboolean enabledll

public qboolean textmode

public qboolean userinfo_changed

public qboolean movevars_changed

public qboolean renderinfo_changed

public char [256] rootdir

public char [256] rodir

public char [64] gamefolder

public byte * imagepool

public byte * soundpool

public uint features

public int window_center_x

public int window_center_y

public struct decallist_s * decalList

public int numdecals



