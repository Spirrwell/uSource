# class CEngineCvar

*Defined at line 961 of ./engine/common/cvar.cpp*

============CVAR interface============



Inherits from IEngineCvar



## Functions

### PreInit

*public _Bool PreInit()*

*Defined at line 964 of ./engine/common/cvar.cpp*

### Init

*public _Bool Init()*

*Defined at line 965 of ./engine/common/cvar.cpp*

### Shutdown

*public void Shutdown()*

*Defined at line 966 of ./engine/common/cvar.cpp*

### GetParentInterface

*public const char * GetParentInterface()*

*Defined at line 967 of ./engine/common/cvar.cpp*

### GetName

*public const char * GetName()*

*Defined at line 968 of ./engine/common/cvar.cpp*

### AddCommand

*public void AddCommand(const char * cmd, void (*)(void) function, const char * desc, int flags)*

*Defined at line 980 of ./engine/common/cvar.cpp*

### RegisterCvar

*public void RegisterCvar(const char * name, const char * default_val, const char * desc, int flags, void (*)(const char *, const char *) callback)*

*Defined at line 986 of ./engine/common/cvar.cpp*

### CvarGetString

*public const char * CvarGetString(const char * name)*

*Defined at line 997 of ./engine/common/cvar.cpp*

### CvarSetString

*public void CvarSetString(const char * name, const char * string)*

*Defined at line 1004 of ./engine/common/cvar.cpp*

### CvarInit

*public void CvarInit()*

*Defined at line 1014 of ./engine/common/cvar.cpp*

### CmdInit

*public void CmdInit()*

*Defined at line 1009 of ./engine/common/cvar.cpp*

### CmdArgc

*public int CmdArgc()*

*Defined at line 1019 of ./engine/common/cvar.cpp*

### CmdArgv

*public const char ** CmdArgv()*

*Defined at line 1024 of ./engine/common/cvar.cpp*



