# struct gameinfo_s

*Defined at line 205 of ./engine/common/common.h*

==============================================================

HOST INTERFACE

==============================================================

========================================================================

GAMEINFO stuff

internal shared gameinfo structure (readonly for engine parts)========================================================================



## Members

public char [64] gamefolder

public char [64] basedir

public char [64] falldir

public char [64] startmap

public char [64] trainmap

public char [64] title

public float version

public char [64] dll_path

public char [64] game_dll

public char [64] iconpath

public string game_url

public string update_url

public char [64] type

public char [64] date

public size_t size

public int gamemode

public qboolean secure

public qboolean nomodels

public qboolean noskills

public char [32] sp_entity

public char [32] mp_entity

public char [32] mp_filter

public char [4][64] ambientsound

public int max_edicts

public int max_tents

public int max_beams

public int max_particles

public char [64] game_dll_linux

public char [64] game_dll_osx

public qboolean added

public class KeyValues * keyvalues



