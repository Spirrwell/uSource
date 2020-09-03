# struct net_api_s

*Defined at line 82 of ./common/net_api.h*

## Members

public void (*)(void) InitNetworking

public void (*)(struct net_status_s *) Status

public void (*)(int, int, int, double, struct netadr_s *, net_api_response_func_t) SendRequest

public void (*)(int) CancelRequest

public void (*)(void) CancelAllRequests

public char *(*)(struct netadr_s *) AdrToString

public int (*)(struct netadr_s *, struct netadr_s *) CompareAdr

public int (*)(char *, struct netadr_s *) StringToAdr

public const char *(*)(const char *, const char *) ValueForKey

public void (*)(char *, const char *) RemoveKey

public void (*)(char *, const char *, const char *, int) SetValueForKey



