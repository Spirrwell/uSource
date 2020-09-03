# class CEngineNetAPI

*Defined at line 4331 of ./engine/client/cl_game.cpp*

Inherits from IEngineNetAPI



## Functions

### GetParentInterface

*public const char * GetParentInterface()*

*Defined at line 4334 of ./engine/client/cl_game.cpp*

### GetName

*public const char * GetName()*

*Defined at line 4335 of ./engine/client/cl_game.cpp*

### PreInit

*public _Bool PreInit()*

*Defined at line 4336 of ./engine/client/cl_game.cpp*

### Init

*public _Bool Init()*

*Defined at line 4337 of ./engine/client/cl_game.cpp*

### Shutdown

*public void Shutdown()*

*Defined at line 4338 of ./engine/client/cl_game.cpp*

### InitNetworking

*public void InitNetworking()*

*Defined at line 4340 of ./engine/client/cl_game.cpp*

### Status

*public void Status(struct net_status_s * status)*

*Defined at line 4344 of ./engine/client/cl_game.cpp*

### SendRequest

*public void SendRequest(int context, int request, int flags, double timeout, struct netadr_s * remote_address, net_api_response_func_t response)*

*Defined at line 4348 of ./engine/client/cl_game.cpp*

### CancelRequest

*public void CancelRequest(int context)*

*Defined at line 4352 of ./engine/client/cl_game.cpp*

### CancelAllRequests

*public void CancelAllRequests()*

*Defined at line 4356 of ./engine/client/cl_game.cpp*

### AdrToString

*public char * AdrToString(struct netadr_s * a)*

*Defined at line 4360 of ./engine/client/cl_game.cpp*

### CompareAdr

*public int CompareAdr(struct netadr_s * a, struct netadr_s * b)*

*Defined at line 4364 of ./engine/client/cl_game.cpp*

### StringToAdr

*public int StringToAdr(char * s, struct netadr_s * a)*

*Defined at line 4368 of ./engine/client/cl_game.cpp*

### ValueForKey

*public const char * ValueForKey(const char * s, const char * key)*

*Defined at line 4372 of ./engine/client/cl_game.cpp*

### RemoveKey

*public void RemoveKey(char * s, const char * key)*

*Defined at line 4376 of ./engine/client/cl_game.cpp*

### SetValueForKey

*public void SetValueForKey(char * s, const char * key, const char * value, int maxsize)*

*Defined at line 4380 of ./engine/client/cl_game.cpp*



