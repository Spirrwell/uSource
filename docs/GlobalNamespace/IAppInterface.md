# class IAppInterface

*Defined at line 37 of ./public/appframework.h*

 AppFramework and how it works

 This is a system that's heavily modeled off of Source 1's AppFramework system. There are some pretty major differences, however.

 The base class IModuleInterface should be the parent of any exported interface. A module can export an infinite number of interfaces.

 Each interface has a couple of properties: 	- Version number 	- Parent interface

 The parent interface is the interface in which it implements. E.g. IFilesystem001 Version numbers are rather abstract, and they're a part of the interface parent name itself (e.g. 001 in the above example)

 Interfaces are loaded into interface "slots". Basically you have an interface implementation, such as IEngineFilesystem001, which is an implementation of IFilesystem001. So, when you load IEngineFilesystem001, it's loaded into the IFilesystem001 slot. When other modules lookup interfaces, they refer to the "slot" name, in this case IFilesystem001, and the IEngineFilesystem001 implementation is returned.

 Implementation NOTES:  - AppFramework acts as a state machine, so it should only be called from the main thread  - There are some pretty terrible hacks in here, which does make me somewhat sad 



## Functions

### GetParentInterface

*public const char * GetParentInterface()*

### GetName

*public const char * GetName()*

### PreInit

*public _Bool PreInit()*

### Init

*public _Bool Init()*

### Shutdown

*public void Shutdown()*



