# class IEngineNetAPI

*Defined at line 9 of ./engine/net_int.h*

Inherits from IAppInterface



## Functions

### InitNetworking

*public void InitNetworking()*

### Status

*public void Status(struct net_status_s * status)*

### SendRequest

*public void SendRequest(int context, int request, int flags, double timeout, struct netadr_s * remote_address, net_api_response_func_t response)*

### CancelRequest

*public void CancelRequest(int context)*

### CancelAllRequests

*public void CancelAllRequests()*

### AdrToString

*public char * AdrToString(struct netadr_s * a)*

### CompareAdr

*public int CompareAdr(struct netadr_s * a, struct netadr_s * b)*

### StringToAdr

*public int StringToAdr(char * s, struct netadr_s * a)*

### ValueForKey

*public const char * ValueForKey(const char * s, const char * key)*

### RemoveKey

*public void RemoveKey(char * s, const char * key)*

### SetValueForKey

*public void SetValueForKey(char * s, const char * key, const char * value, int maxsize)*



