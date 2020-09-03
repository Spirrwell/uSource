# struct convar_s

*Defined at line 25 of ./engine/common/cvar.h*

 NOTE: if this is changed, it must be changed in cvardef.h too



## Members

public char * name

public char * string

public int flags

public float value

public struct convar_s * next

public void (*)(const char *, const char *) callback

public char * desc

public char * def_string



