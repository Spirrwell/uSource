# namespace AppFramework



 API usage:

 AppFramework_AddInterface("engine.so", "IFilesystem001"); AppFramework_AddInterface("engine.so", "IEngineTrace001");

 AppFramework_LoadInterfaces();

 void* ptr = AppFramework_FindInterface("IEngineTrace001");

 ...





## Records

interface_t

CAppSystemHandle



## Functions

### AddInterface

*_Bool AddInterface(const char * module, const char * iface)*

*Defined at line 98 of ./public/appframework.cpp*



**brief** Adds an interface to the load list

**module**

**iface**

**return** True if added, false otherwise

### AddInterfaces

*_Bool AddInterfaces(std::initializer_list<interface_t> interfaces)*

*Defined at line 174 of ./public/appframework.cpp*

### AddInterfaces

*_Bool AddInterfaces(struct AppFramework::interface_t * interfaces)*

*Defined at line 183 of ./public/appframework.cpp*

### GetLastError

*const char * GetLastError()*

*Defined at line 60 of ./public/appframework.cpp*



**brief** Gets the last error that happened or empty string

**return** last error

### LoadInterfaces

*_Bool LoadInterfaces()*

*Defined at line 192 of ./public/appframework.cpp*



**brief** Called to load all interfaces queued for load

**return** True if OK, false if something failed

### FindInterface

*void * FindInterface(const char * iface)*

*Defined at line 242 of ./public/appframework.cpp*



**brief** Finds a pointer to a loaded interface

**iface**

**return** Pointer to the iface or NULL if not found

### UnloadInterfaces

*void UnloadInterfaces()*

*Defined at line 254 of ./public/appframework.cpp*



**brief** Unloads all added interfaces

### SetLoadLibrary

*void SetLoadLibrary(std::function<void *(const char *)> fn)*

*Defined at line 65 of ./public/appframework.cpp*

 Set a custom LoadLibrary/FreeLibrary function

### SetFreeLibrary

*void SetFreeLibrary(std::function<void (void *)> fn)*

*Defined at line 70 of ./public/appframework.cpp*

### ClearCustomFunctions

*void ClearCustomFunctions()*

*Defined at line 75 of ./public/appframework.cpp*



