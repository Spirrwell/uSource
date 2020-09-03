# class IEngineNetsystem

*Defined at line 37 of ./engine/net_int.h*

Inherits from IAppInterface



## Functions

### HookServerNetsystemMsg

*public void HookServerNetsystemMsg(void (*)(edict_t *, void *) pfnHook)*

 Hooks the network message with the svc_netsystem index. 

### HookClientNetsystemMsg

*public void HookClientNetsystemMsg(void (*)(void *) pfnHook)*

### HookServerMsg

*public void HookServerMsg(int cmd, void (*)(edict_t *, void *) pfnHook)*

 Hooks any client or server message 

### HookClientMsg

*public void HookClientMsg(int cmd, void (*)(void *) pfnHook)*

### BeginClientNetsystemCmd

*public void BeginClientNetsystemCmd()*

 Basic message sending api for the client and server 

 This API is not threadsafe, so be careful! 

### BeginServerNetsystemCmd

*public void BeginServerNetsystemCmd(edict_t * client)*

### BeginServerMessage

*public void BeginServerMessage(int cmd, edict_t * client)*

 Alternatively, you can use this to begin a custom message 

### BeginClientMessage

*public void BeginClientMessage(int cmd)*

### EndMessage

*public void EndMessage()*

### WriteBytes

*public void WriteBytes(const void * pBuf, unsigned long long len)*

### WriteString

*public void WriteString(const char * str)*

### WriteByte

*public void WriteByte(byte _byte)*

### WriteShort

*public void WriteShort(short _short)*

### WriteInt

*public void WriteInt(int _int)*

### WriteLong

*public void WriteLong(long long _long)*

### WriteFloat

*public void WriteFloat(float _fl)*

### WriteVector

*public void WriteVector(Vector _vec)*

### ReadBytes

*public size_t ReadBytes(void * pBuffer, void * pOutbuf, unsigned long long num)*

 Used to decode a message. No state is held here 

### ReadString

*public void ReadString(void * pBuffer, char * pOutbuf, unsigned long long num)*

### ReadByte

*public byte ReadByte(void * pBuffer)*

### ReadShort

*public short ReadShort(void * pBuffer)*

### ReadInt

*public int ReadInt(void * pBuffer)*

### ReadLong

*public long long ReadLong(void * pBuffer)*

### ReadFloat

*public float ReadFloat(void * pBuffer)*

### ReadVector

*public void ReadVector(void * pBuffer, float [3] outvec)*

### WriteVector

*public void WriteVector(vec3_t _vec)*



