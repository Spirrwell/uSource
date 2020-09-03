# class CEngineNetsystem001

*Defined at line 697 of ./engine/common/net_buffer.cpp*

 Engine netsystem implementation





Inherits from IEngineNetsystem



## Functions

### GetName

*public const char * GetName()*

*Defined at line 700 of ./engine/common/net_buffer.cpp*

### GetParentInterface

*public const char * GetParentInterface()*

*Defined at line 701 of ./engine/common/net_buffer.cpp*

### Init

*public _Bool Init()*

*Defined at line 702 of ./engine/common/net_buffer.cpp*

### PreInit

*public _Bool PreInit()*

*Defined at line 703 of ./engine/common/net_buffer.cpp*

### Shutdown

*public void Shutdown()*

*Defined at line 704 of ./engine/common/net_buffer.cpp*

### HookServerNetsystemMsg

*public void HookServerNetsystemMsg(void (*)(edict_t *, void *) pfnHook)*

*Defined at line 743 of ./engine/common/net_buffer.cpp*

### HookClientNetsystemMsg

*public void HookClientNetsystemMsg(void (*)(void *) pfnHook)*

*Defined at line 748 of ./engine/common/net_buffer.cpp*

### HookServerMsg

*public void HookServerMsg(int cmd, void (*)(edict_t *, void *) pfnHook)*

*Defined at line 753 of ./engine/common/net_buffer.cpp*

### HookClientMsg

*public void HookClientMsg(int cmd, void (*)(void *) pfnHook)*

*Defined at line 758 of ./engine/common/net_buffer.cpp*

### BeginClientNetsystemCmd

*public void BeginClientNetsystemCmd()*

*Defined at line 763 of ./engine/common/net_buffer.cpp*

### BeginServerNetsystemCmd

*public void BeginServerNetsystemCmd(edict_t * client)*

*Defined at line 769 of ./engine/common/net_buffer.cpp*

### WriteBytes

*public void WriteBytes(const void * pBuf, unsigned long long len)*

*Defined at line 775 of ./engine/common/net_buffer.cpp*

### WriteString

*public void WriteString(const char * str)*

*Defined at line 786 of ./engine/common/net_buffer.cpp*

### WriteByte

*public void WriteByte(byte _byte)*

*Defined at line 793 of ./engine/common/net_buffer.cpp*

### WriteShort

*public void WriteShort(short _short)*

*Defined at line 800 of ./engine/common/net_buffer.cpp*

### WriteInt

*public void WriteInt(int _int)*

*Defined at line 807 of ./engine/common/net_buffer.cpp*

### WriteLong

*public void WriteLong(long long _long)*

*Defined at line 814 of ./engine/common/net_buffer.cpp*

### WriteFloat

*public void WriteFloat(float _fl)*

*Defined at line 821 of ./engine/common/net_buffer.cpp*

### WriteVector

*public void WriteVector(vec3_t _vec)*

*Defined at line 828 of ./engine/common/net_buffer.cpp*

### EndMessage

*public void EndMessage()*

*Defined at line 835 of ./engine/common/net_buffer.cpp*

### ReadBytes

*public size_t ReadBytes(void * pBuffer, void * pOutbuf, unsigned long long num)*

*Defined at line 840 of ./engine/common/net_buffer.cpp*

### ReadString

*public void ReadString(void * pBuffer, char * pOutbuf, unsigned long long num)*

*Defined at line 848 of ./engine/common/net_buffer.cpp*

### ReadByte

*public byte ReadByte(void * pBuffer)*

*Defined at line 856 of ./engine/common/net_buffer.cpp*

### ReadShort

*public short ReadShort(void * pBuffer)*

*Defined at line 862 of ./engine/common/net_buffer.cpp*

### ReadInt

*public int ReadInt(void * pBuffer)*

*Defined at line 868 of ./engine/common/net_buffer.cpp*

### ReadLong

*public long long ReadLong(void * pBuffer)*

*Defined at line 874 of ./engine/common/net_buffer.cpp*

### ReadFloat

*public float ReadFloat(void * pBuffer)*

*Defined at line 880 of ./engine/common/net_buffer.cpp*

### ReadVector

*public void ReadVector(void * pBuffer, vec3_t outvec)*

*Defined at line 886 of ./engine/common/net_buffer.cpp*

### BeginServerMessage

*public void BeginServerMessage(int cmd, edict_t * client)*

*Defined at line 899 of ./engine/common/net_buffer.cpp*

### BeginClientMessage

*public void BeginClientMessage(int cmd)*

*Defined at line 892 of ./engine/common/net_buffer.cpp*



