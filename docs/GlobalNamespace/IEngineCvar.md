# class IEngineCvar

*Defined at line 103 of ./engine/engine_int.h*

 IEngineCvar 	Provides console variable and command managment. This interface can be use either standalone, or with some type of adapter. 



Inherits from IAppInterface



## Functions

### AddCommand

*public void AddCommand(const char * cmd, void (*)(void) function, const char * desc, int flags)*

### RegisterCvar

*public void RegisterCvar(const char * name, const char * default_val, const char * desc, int flags, void (*)(const char *, const char *) callback)*

### CvarGetString

*public const char * CvarGetString(const char * name)*

### CvarSetString

*public void CvarSetString(const char * name, const char * string)*

### CvarInit

*public void CvarInit()*

### CmdInit

*public void CmdInit()*

### CmdArgc

*public int CmdArgc()*

### CmdArgv

*public const char ** CmdArgv()*



