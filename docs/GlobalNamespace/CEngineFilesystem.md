# class CEngineFilesystem

*Defined at line 3775 of ./engine/common/filesystem.cpp*

FILESYSTEM INTERFACE IMPLEMENTATION

The internal filesystem implementation here is odd to say the least. I'd like to simply return a FILE* ptr such that any file opened with the filesystem is compatible with the standard C IO functions,but there's some buffering being done in here. It's probably a good thing for performance, but for ease of useit's hardly ideal. the C stdlib should be doing buffering *anyways* so I don't think it would matter.If you're on Linux, OSX or a BSD operating system, the OS *should* be doing a bunch of caching in memory too.



Inherits from IEngineFilesystem



## Functions

### PreInit

*public _Bool PreInit()*

*Defined at line 3780 of ./engine/common/filesystem.cpp*

### Init

*public _Bool Init()*

*Defined at line 3781 of ./engine/common/filesystem.cpp*

### Shutdown

*public void Shutdown()*

*Defined at line 3782 of ./engine/common/filesystem.cpp*

### GetParentInterface

*public const char * GetParentInterface()*

*Defined at line 3783 of ./engine/common/filesystem.cpp*

### GetName

*public const char * GetName()*

*Defined at line 3784 of ./engine/common/filesystem.cpp*

### OpenFile

*public FILE * OpenFile(const char * path, const char * mode, _Bool gamedironly)*

*Defined at line 3786 of ./engine/common/filesystem.cpp*

### CloseFile

*public void CloseFile(FILE * file)*

*Defined at line 3798 of ./engine/common/filesystem.cpp*

### FileSize

*public size_t FileSize(const char * file, _Bool gamedironly)*

*Defined at line 3804 of ./engine/common/filesystem.cpp*

### FileExists

*public _Bool FileExists(const char * file, _Bool casesensitive)*

*Defined at line 3815 of ./engine/common/filesystem.cpp*

### AddSearchPath

*public void AddSearchPath(const char * dir)*

*Defined at line 3821 of ./engine/common/filesystem.cpp*

### GetFullPath

*public String GetFullPath(const char * file, _Bool gamedironly)*

*Defined at line 3826 of ./engine/common/filesystem.cpp*



