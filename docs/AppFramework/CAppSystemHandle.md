# class CAppSystemHandle

*Defined at line 148 of ./public/appframework.h*

 Utility class that maintains a handle to an arbitrary AppSystem. The handle returned from this is guaranteed to be valid, as SIGABRT will be raised if the interface is not found

 USAGE: 	CAppSystemHandle<ILoggingSystem> g_LoggingSystem(IENGINELOGGING_INTERFACE); 	g_LoggingSystem.Get().Log(....);



## Functions

### CAppSystemHandle<T>

*public void CAppSystemHandle<T>(const char * iface_name)*

### Get

*public T & Get()*

### Get

*public const T & Get()*

### Load

*public void Load()*

### IsLoaded

*public _Bool IsLoaded()*



