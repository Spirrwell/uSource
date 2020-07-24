#include "common.h"
#include "const.h"
#include "edict.h"
#include "appframework.h"
#include "networksystem.h"
#include "netproto.h"
#include <memory.h>

IEngineNetsystem* g_pNetworkSystem;
IEngineMalloc* NetworkSystem::g_pMalloc;
byte* NetworkSystem::g_pNetworkPool;

void SV_ParseNetsysMessage(edict_t* e, void* msg);
void CL_ParseNetsysMessage(void* msg);

using namespace NetworkSystem;

void ConnectNetsystemLibraries()
{
	g_pNetworkSystem = static_cast<IEngineNetsystem*>(AppFramework::FindInterface(INETSYSTEM_INTERFACE));
	NetworkSystem::g_pMalloc = static_cast<IEngineMalloc*>(AppFramework::FindInterface(IENGINEMALLOC_INTERFACE));
}

void NetworksystemInit()
{
	g_pNetworkPool = g_pMalloc->Mem_AllocPool("NetworksystemPool", __FILE__, __LINE__);
	g_pNetworkSystem->HookServerNetsystemMsg(SV_ParseNetsysMessage);
	g_pNetworkSystem->HookClientNetsystemMsg(CL_ParseNetsysMessage);
}

void NetworksystemShutdown()
{
	g_pMalloc->Mem_FreePool(&g_pNetworkPool, __FILE__, __LINE__);
}

void SV_ParseNetsysMessage(edict_t* e, void* msg)
{

}


//=========================================================================================================================//
// Memory allocation
void NetworkSystem::Mem_Free(void* ptr)
{
	g_pMalloc->Mem_Free(ptr, "", 0);
}

void* NetworkSystem::Mem_Alloc(unsigned long long size)
{
	return g_pMalloc->Mem_Alloc(g_pNetworkPool, size, false, "", 0);
}

void* NetworkSystem::Mem_Realloc(void *ptr, unsigned long long size)
{
	return g_pMalloc->Mem_Realloc(g_pNetworkPool, ptr, size, false, "", 0);
}

void CL_ParseNetsysMessage(void* msg)
{

}
//=========================================================================================================================//

//=========================================================================================================================//
// Network byte order functions
// for networksystem, byte order is little endian
short htons(short in)
{
#ifdef XASH_BIG_ENDIAN
	return ToLittleEndian(in);
#else
	return in;
#endif
}

int htoni(int in)
{
#ifdef XASH_BIG_ENDIAN
	return ToLittleEndian(in);
#else
	return in;
#endif
}

long htonl(int in)
{
#ifdef XASH_BIG_ENDIAN
	return ToLittleEndian(in);
#else
	return in;
#endif
}

long long htonll(long long in)
{
#ifdef XASH_BIG_ENDIAN
	return ToLittleEndian(in);
#else
	return in;
#endif
}


short ntohs(short in)
{
#ifdef XASH_BIG_ENDIAN
	return ToBigEndian(in);
#else
	return in;
#endif
}

int ntohi(int in)
{
#ifdef XASH_BIG_ENDIAN
	return ToBigEndian(in);
#else
	return in;
#endif
}

long ntohl(long in)
{
#ifdef XASH_BIG_ENDIAN
	return ToBigEndian(in);
#else
	return in;
#endif
}

long long ntohll(long long in)
{
#ifdef XASH_BIG_ENDIAN
	return ToBigEndian(in);
#else
	return in;
#endif
}
//=========================================================================================================================//


//=========================================================================================================================//
// CNetworkMessage
CNetworkMessage::CNetworkMessage(unsigned long size) :
	m_size(size),
	m_init(false),
	m_data(nullptr),
	m_bufpos(0),
	m_overflowed(false)
{
}

CNetworkMessage::CNetworkMessage(const CNetworkMessage &msg)
{
	this->m_bufpos = msg.m_bufpos;
	this->m_overflowed = msg.m_overflowed;
	this->m_init = msg.m_init;
	this->m_size = msg.m_size;
	if(msg.m_data)
	{
		this->m_data = Mem_Alloc(m_size);
		memcpy(m_data, msg.m_data, m_size);
	}
	else
		m_data = nullptr;
}

CNetworkMessage::CNetworkMessage(CNetworkMessage &&other) noexcept 
{
	this->m_size = other.m_size;
	this->m_data = other.m_data;
	this->m_init = other.m_init;
	this->m_overflowed = other.m_overflowed;
	this->m_bufpos = other.m_bufpos;
	other.m_bufpos = 0;
	other.m_overflowed = false;
	other.m_init = false;
	other.m_data = nullptr;
	other.m_size = 0;
}

CNetworkMessage::~CNetworkMessage()
{
	if(m_data) Mem_Free(m_data);
}

void CNetworkMessage::InitStorage()
{
	if(m_init) return;
	m_init = true;
	m_data = Mem_Alloc(m_size);
}

#define WRITE_TO_BUFFER(x) if(m_bufpos + sizeof(x) >= m_size) { m_overflowed = true; return; }; auto y = ToLittleEndian(x); memcpy((void*)((uintptr_t)m_data + m_bufpos), &y, sizeof(y));\
m_bufpos += sizeof(y);

void CNetworkMessage::WriteInt64(long long int l)
{
	WRITE_TO_BUFFER(l);
}

void CNetworkMessage::WriteUInt64(unsigned long long int l)
{
	WRITE_TO_BUFFER(l);
}

void CNetworkMessage::WriteInt(int i)
{
	WRITE_TO_BUFFER(i);
}

void CNetworkMessage::WriteUInt(unsigned int i)
{
	WRITE_TO_BUFFER(i);
}

void CNetworkMessage::WriteShort(short s)
{
	WRITE_TO_BUFFER(s);
}

void CNetworkMessage::WriteUShort(unsigned short s)
{
	WRITE_TO_BUFFER(s);
}

void CNetworkMessage::WriteByte(unsigned char b)
{
	WRITE_TO_BUFFER(b);
}

void CNetworkMessage::WriteChar(char c)
{
	WRITE_TO_BUFFER(c);
}

void CNetworkMessage::WriteBytes(void *pBytes, unsigned long num)
{
	if(num + m_bufpos >= m_size)
	{
		m_overflowed = true;
		return;
	}
	memcpy((void*)((uintptr_t)m_data + m_bufpos), pBytes, num);
	m_bufpos += num;
}

int CNetworkMessage::ReadInt()
{
	if(m_bufpos + 4 >= m_size)
	{
		m_overflowed = true;
		return 0;
	}
	int l;
	memcpy(&l, (void*)((uintptr_t)m_data + m_bufpos), sizeof(l));
	m_bufpos += sizeof(l);
	return NetworkSystem::htoni(l);
}

unsigned int CNetworkMessage::ReadUInt()
{
	if(m_bufpos + 4 >= m_size)
	{
		m_overflowed = true;
		return 0;
	}
	unsigned int l;
	memcpy(&l, (void*)((uintptr_t)m_data + m_bufpos), sizeof(l));
	m_bufpos += sizeof(l);
	return NetworkSystem::htoni(l);
}

short CNetworkMessage::ReadShort()
{
	if(m_bufpos + 4 >= m_size)
	{
		m_overflowed = true;
		return 0;
	}
	short l;
	memcpy(&l, (void*)((uintptr_t)m_data + m_bufpos), sizeof(l));
	m_bufpos += sizeof(l);
	return NetworkSystem::htons(l);
}

unsigned short CNetworkMessage::ReadUShort()
{
	if(m_bufpos + 4 >= m_size)
	{
		m_overflowed = true;
		return 0;
	}
	unsigned short l;
	memcpy(&l, (void*)((uintptr_t)m_data + m_bufpos), sizeof(l));
	m_bufpos += sizeof(l);
	return NetworkSystem::htons(l);
}

unsigned char CNetworkMessage::ReadByte()
{
	if(m_bufpos + 4 >= m_size)
	{
		m_overflowed = true;
		return 0;
	}
	m_bufpos++;
	return ((char*)m_data)[m_bufpos-1];
}

char CNetworkMessage::ReadChar()
{
	if(m_bufpos + 4 >= m_size)
	{
		m_overflowed = true;
		return 0;
	}
	m_bufpos++;
	return ((char*)m_data)[m_bufpos-1];
}

long long CNetworkMessage::ReadInt64()
{
	if(m_bufpos + 4 >= m_size)
	{
		m_overflowed = true;
		return 0;
	}
	unsigned long long l;
	memcpy(&l, (void*)((uintptr_t)m_data + m_bufpos), sizeof(l));
	m_bufpos += sizeof(l);
	return NetworkSystem::htonll(l);
}

unsigned long long CNetworkMessage::ReadUInt64()
{
	if(m_bufpos + 4 >= m_size)
	{
		m_overflowed = true;
		return 0;
	}
	unsigned long long l;
	memcpy(&l, (void*)((uintptr_t)m_data + m_bufpos), sizeof(l));
	m_bufpos += sizeof(l);
	return NetworkSystem::htonll(l);
}

void CNetworkMessage::ReadBytes(void *outbuf, unsigned long num)
{
	if(m_bufpos + num >= m_size)
	{
		m_overflowed = true;
		return;
	}
	memcpy(outbuf, (void*)((uintptr_t)m_data + m_bufpos), num);
	m_bufpos += num;
}

void CNetworkMessage::Clear()
{
	memset(m_data, 0, m_size);
	m_bufpos = 0;
}

void CNetworkMessage::Resize(unsigned long newsize)
{
	m_data = Mem_Realloc(m_data, newsize);
}

void CNetworkMessage::Seek(unsigned int type, unsigned long pos)
{
	if(type == CNetworkMessage::ABSOLUTE) m_bufpos = pos;
	else if(type == CNetworkMessage::RELATIVE) m_bufpos += pos;
}

CNetworkMessage &CNetworkMessage::operator=(const CNetworkMessage &msg)
{
	this->m_bufpos = msg.m_bufpos;
	this->m_overflowed = msg.m_overflowed;
	this->m_init = msg.m_init;
	this->m_size = msg.m_size;
	if(msg.m_data)
	{
		this->m_data = Mem_Alloc(m_size);
		memcpy(m_data, msg.m_data, m_size);
	}
	else
		m_data = nullptr;
	return *this;
}

CNetworkMessage &CNetworkMessage::operator=(CNetworkMessage &&other) noexcept
{

	this->m_size = other.m_size;
	this->m_data = other.m_data;
	this->m_init = other.m_init;
	this->m_overflowed = other.m_overflowed;
	this->m_bufpos = other.m_bufpos;
	other.m_bufpos = 0;
	other.m_overflowed = false;
	other.m_init = false;
	other.m_data = nullptr;
	other.m_size = 0;
	return *this;
}
//=========================================================================================================================//
