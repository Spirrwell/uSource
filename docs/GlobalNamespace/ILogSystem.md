# class ILogSystem

*Defined at line 14 of ./engine/log_int.h*

Inherits from IAppInterface



## Functions

### SupportsRemoteLogging

*public _Bool SupportsRemoteLogging()*

 Return true to support remote logging features 

### ConnectPort

*public void ConnectPort(int port)*

 If this supports remote logging, connect stdout/stdin with the port 

### DisconnectPort

*public void DisconnectPort(int port)*

 Disconnect remote logging from the specified port 

### CreateLoggingChannel

*public LoggingChannel_t CreateLoggingChannel(const char * name, int verbosity, char [3] color)*

 verbosity is the minimum verbosity a message must have in order to be shown 

### CreateLoggingChannel

*public LoggingChannel_t CreateLoggingChannel(LoggingChannel_t id, const char * name, int verbo, char [3] color)*

### GetLoggingChannelForName

*public LoggingChannel_t GetLoggingChannelForName(const char * name)*

### SetColor

*public void SetColor(const char [3] colo)*

### ClearColor

*public void ClearColor()*

### Log

*public void Log(LoggingChannel_t channel, int verbosity, const char * fmt)*

### SetStdin

*public void SetStdin(FILE * stream)*

 Sets the standard file streams 

### SetStdout

*public void SetStdout(FILE * stream)*

### AddStdin

*public void AddStdin(FILE * stream)*

 Adds or removes streams 

### AddStdout

*public void AddStdout(FILE * stream)*

### RemoveStdin

*public void RemoveStdin(FILE * stream)*

### RemoveStdout

*public void RemoveStdout(FILE * steam)*



