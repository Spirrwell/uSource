# namespace NetworkSystem



## Records

usrmsg_hdr_t

varupd_hdr_t

action_hdr_t

msg_hdr_t

varupd_desc_t



## Functions

### SendToServer

*void SendToServer(unsigned int msgname, const class CNetworkMessage & msg)*

*Defined at line 107 of ./networksystem/networksystem.cpp*

 Thread-safe methods to send messages to clients and the server Internally, it puts them in a queue and will send them cl_cmdrate times per second Try not to saturate this too much!

**msgid**

**msg**

**client**

=========================================================================================================================// Send/Recv from client/server

### SendToClient

*void SendToClient(unsigned int msgname, edict_t * client, const class CNetworkMessage & msg)*

*Defined at line 117 of ./networksystem/networksystem.cpp*

### HookMsgFromServer

*void HookMsgFromServer(unsigned int msgname, NetworkSystem::pfnRecvServerMsgCallback callback)*

*Defined at line 128 of ./networksystem/networksystem.cpp*

### HookMsgFromClient

*void HookMsgFromClient(unsigned int msgname, int client, NetworkSystem::pfnRecvClientMsgCallback callback)*

*Defined at line 146 of ./networksystem/networksystem.cpp*

### HookMsgFromClients

*void HookMsgFromClients(unsigned int msgname, NetworkSystem::pfnRecvClientMsgCallback callback)*

*Defined at line 172 of ./networksystem/networksystem.cpp*

### Mem_Alloc

*void * Mem_Alloc(unsigned long long size)*

*Defined at line 91 of ./networksystem/networksystem.cpp*

### Mem_Realloc

*void * Mem_Realloc(void * ptr, unsigned long long size)*

*Defined at line 97 of ./networksystem/networksystem.cpp*

### Mem_Free

*void Mem_Free(void * ptr)*

*Defined at line 85 of ./networksystem/networksystem.cpp*

=========================================================================================================================// Memory allocation

### htons

*short htons(short in)*

*Defined at line 287 of ./networksystem/networksystem.cpp*

 Network byte-order functions 

 NOTE: These are ONLY for Networksystem!!! 

=========================================================================================================================// Network byte order functions for networksystem, byte order is little endian

### htoni

*int htoni(int in)*

*Defined at line 296 of ./networksystem/networksystem.cpp*

### htonl

*long htonl(int in)*

*Defined at line 305 of ./networksystem/networksystem.cpp*

### htonll

*long long htonll(long long in)*

*Defined at line 314 of ./networksystem/networksystem.cpp*

### ntohs

*short ntohs(short in)*

*Defined at line 324 of ./networksystem/networksystem.cpp*

### ntohi

*int ntohi(int in)*

*Defined at line 333 of ./networksystem/networksystem.cpp*

### ntohl

*long ntohl(long in)*

*Defined at line 342 of ./networksystem/networksystem.cpp*

### ntohll

*long long ntohll(long long in)*

*Defined at line 351 of ./networksystem/networksystem.cpp*



## Enums

| enum  |

--

| HDR_USRMSG |
| HDR_VARUPD |


*Defined at line 17 of ./networksystem/netproto.h*



