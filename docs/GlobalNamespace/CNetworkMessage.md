# class CNetworkMessage

*Defined at line 80 of ./networksystem/networksystem.h*

 Network message class. Internally converted to a sizebuf structure



## Members

private void * m_data

private unsigned long m_size

private unsigned long m_bufpos

private _Bool m_overflowed

private _Bool m_init



## Functions

### CNetworkMessage

*public void CNetworkMessage(unsigned long size)*

*Defined at line 365 of ./networksystem/networksystem.cpp*

=========================================================================================================================// CNetworkMessage

### CNetworkMessage

*public void CNetworkMessage(void * data, size_t size)*

*Defined at line 374 of ./networksystem/networksystem.cpp*

### CNetworkMessage

*public void CNetworkMessage(const class CNetworkMessage & other)*

*Defined at line 386 of ./networksystem/networksystem.cpp*

### CNetworkMessage

*public void CNetworkMessage(class CNetworkMessage && other)*

*Defined at line 401 of ./networksystem/networksystem.cpp*

### ~CNetworkMessage

*public void ~CNetworkMessage()*

*Defined at line 415 of ./networksystem/networksystem.cpp*

### InitStorage

*public void InitStorage()*

*Defined at line 420 of ./networksystem/networksystem.cpp*

### WasInit

*public _Bool WasInit()*

*Defined at line 101 of ./networksystem/networksystem.h*

### Reset

*public void Reset()*

*Defined at line 427 of ./networksystem/networksystem.cpp*

 Resets the buffer position and other flags to allow for re-reading 

### WriteInt64

*public void WriteInt64(long long l)*

*Defined at line 436 of ./networksystem/networksystem.cpp*

### WriteUInt64

*public void WriteUInt64(unsigned long long l)*

*Defined at line 441 of ./networksystem/networksystem.cpp*

### WriteInt

*public void WriteInt(int i)*

*Defined at line 446 of ./networksystem/networksystem.cpp*

### WriteUInt

*public void WriteUInt(unsigned int i)*

*Defined at line 451 of ./networksystem/networksystem.cpp*

### WriteShort

*public void WriteShort(short s)*

*Defined at line 456 of ./networksystem/networksystem.cpp*

### WriteUShort

*public void WriteUShort(unsigned short s)*

*Defined at line 461 of ./networksystem/networksystem.cpp*

### WriteByte

*public void WriteByte(unsigned char b)*

*Defined at line 466 of ./networksystem/networksystem.cpp*

### WriteChar

*public void WriteChar(char c)*

*Defined at line 471 of ./networksystem/networksystem.cpp*

### WriteBytes

*public void WriteBytes(void * pBytes, unsigned long num)*

*Defined at line 476 of ./networksystem/networksystem.cpp*

### ReadInt

*public int ReadInt()*

*Defined at line 487 of ./networksystem/networksystem.cpp*

### ReadUInt

*public unsigned int ReadUInt()*

*Defined at line 500 of ./networksystem/networksystem.cpp*

### ReadShort

*public short ReadShort()*

*Defined at line 513 of ./networksystem/networksystem.cpp*

### ReadUShort

*public unsigned short ReadUShort()*

*Defined at line 526 of ./networksystem/networksystem.cpp*

### ReadByte

*public unsigned char ReadByte()*

*Defined at line 539 of ./networksystem/networksystem.cpp*

### ReadChar

*public char ReadChar()*

*Defined at line 550 of ./networksystem/networksystem.cpp*

### ReadInt64

*public long long ReadInt64()*

*Defined at line 561 of ./networksystem/networksystem.cpp*

### ReadUInt64

*public unsigned long long ReadUInt64()*

*Defined at line 574 of ./networksystem/networksystem.cpp*

### ReadBytes

*public void ReadBytes(void * outbuf, unsigned long num)*

*Defined at line 587 of ./networksystem/networksystem.cpp*

### Data

*public const void * Data()*

*Defined at line 126 of ./networksystem/networksystem.h*

### Data

*public void * Data()*

*Defined at line 127 of ./networksystem/networksystem.h*

### Size

*public unsigned long Size()*

*Defined at line 129 of ./networksystem/networksystem.h*

### BufferPos

*public unsigned long BufferPos()*

*Defined at line 130 of ./networksystem/networksystem.h*

### HasOverflowed

*public _Bool HasOverflowed()*

*Defined at line 131 of ./networksystem/networksystem.h*

### IsEmpty

*public _Bool IsEmpty()*

*Defined at line 132 of ./networksystem/networksystem.h*

### Good

*public _Bool Good()*

*Defined at line 133 of ./networksystem/networksystem.h*

### Clear

*public void Clear()*

*Defined at line 598 of ./networksystem/networksystem.cpp*

### Resize

*public void Resize(unsigned long newsize)*

*Defined at line 604 of ./networksystem/networksystem.cpp*

### Seek

*public void Seek(unsigned int type, unsigned long pos)*

*Defined at line 609 of ./networksystem/networksystem.cpp*

### operator=

*public class CNetworkMessage & operator=(const class CNetworkMessage & msg)*

*Defined at line 615 of ./networksystem/networksystem.cpp*

### operator=

*public class CNetworkMessage & operator=(class CNetworkMessage && msg)*

*Defined at line 631 of ./networksystem/networksystem.cpp*



## Enums

| enum  |

--

| ABSOLUTE |
| RELATIVE |


*Defined at line 90 of ./networksystem/networksystem.h*



