# class CLoggingSystem

*Defined at line 36 of ./engine/common/logsystem/logsystem.cpp*

Inherits from ILogSystem



## Members

private FILE * _stdin

private FILE * _stdout

List m_stdout

List m_stdin

public char [3] default_color



## Functions

### GetParentInterface

*public const char * GetParentInterface()*

*Defined at line 213 of ./engine/common/logsystem/logsystem.cpp*

### GetName

*public const char * GetName()*

*Defined at line 218 of ./engine/common/logsystem/logsystem.cpp*

### PreInit

*public _Bool PreInit()*

*Defined at line 223 of ./engine/common/logsystem/logsystem.cpp*

### Init

*public _Bool Init()*

*Defined at line 230 of ./engine/common/logsystem/logsystem.cpp*

### Shutdown

*public void Shutdown()*

*Defined at line 240 of ./engine/common/logsystem/logsystem.cpp*

### CLoggingSystem

*public void CLoggingSystem()*

*Defined at line 82 of ./engine/common/logsystem/logsystem.cpp*

### SupportsRemoteLogging

*public _Bool SupportsRemoteLogging()*

*Defined at line 92 of ./engine/common/logsystem/logsystem.cpp*

 For Now we aren't supporting remote logging. This is a simple baseline logger

 Return true to support remote logging features 

### ConnectPort

*public void ConnectPort(int port)*

*Defined at line 97 of ./engine/common/logsystem/logsystem.cpp*

 If this supports remote logging, connect stdout/stdin with the port 

### DisconnectPort

*public void DisconnectPort(int port)*

*Defined at line 102 of ./engine/common/logsystem/logsystem.cpp*

 Disconnect remote logging from the specified port 

### CreateLoggingChannel

*public LoggingChannel_t CreateLoggingChannel(const char * name, int verbosity, char [3] color)*

*Defined at line 107 of ./engine/common/logsystem/logsystem.cpp*

### CreateLoggingChannel

*public LoggingChannel_t CreateLoggingChannel(LoggingChannel_t id, const char * name, int verbosity, char [3] color)*

*Defined at line 201 of ./engine/common/logsystem/logsystem.cpp*

### GetLoggingChannelForName

*public LoggingChannel_t GetLoggingChannelForName(const char * name)*

*Defined at line 130 of ./engine/common/logsystem/logsystem.cpp*

### SetColor

*public void SetColor(const char [3] color)*

*Defined at line 183 of ./engine/common/logsystem/logsystem.cpp*

### ClearColor

*public void ClearColor()*

*Defined at line 189 of ./engine/common/logsystem/logsystem.cpp*

### Log

*public void Log(LoggingChannel_t channel, int v, const char * fmt)*

*Defined at line 158 of ./engine/common/logsystem/logsystem.cpp*

 Actual log function 

### SetStdin

*public void SetStdin(FILE * stream)*

*Defined at line 245 of ./engine/common/logsystem/logsystem.cpp*

 Sets the standard file streams 

### SetStdout

*public void SetStdout(FILE * stream)*

*Defined at line 250 of ./engine/common/logsystem/logsystem.cpp*

### AddStdin

*public void AddStdin(FILE * stream)*

*Defined at line 255 of ./engine/common/logsystem/logsystem.cpp*

### AddStdout

*public void AddStdout(FILE * stream)*

*Defined at line 260 of ./engine/common/logsystem/logsystem.cpp*

### RemoveStdin

*public void RemoveStdin(FILE * stream)*

*Defined at line 265 of ./engine/common/logsystem/logsystem.cpp*

### RemoveStdout

*public void RemoveStdout(FILE * steam)*

*Defined at line 270 of ./engine/common/logsystem/logsystem.cpp*



