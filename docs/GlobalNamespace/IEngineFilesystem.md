# class IEngineFilesystem

*Defined at line 76 of ./engine/engine_int.h*

Inherits from IAppInterface



## Functions

### OpenFile

*public FILE * OpenFile(const char * path, const char * mode, _Bool gamedironly)*

### CloseFile

*public void CloseFile(FILE * file)*

### FileSize

*public size_t FileSize(const char * file, _Bool gamedironly)*

### FileExists

*public _Bool FileExists(const char * file, _Bool gamedironly)*

### AddSearchPath

*public void AddSearchPath(const char * dir)*

### GetFullPath

*public String GetFullPath(const char * file, _Bool gamedironly)*



