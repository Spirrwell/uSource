#include "common.h"
#include "const.h"
#include "edict.h"
#include "appframework.h"
#include "networksystem.h"
#include "netproto.h"
#include <memory.h>

#include "public/mem.h"
#include "tier1/convar.h"
#include "tier1/dbg.h"

Convar net_debug_messages("net_debug_messages", "0", FCVAR_CHEAT | FCVAR_ARCHIVE);

IEngineNetsystem* g_pNetworkSystem;
byte* NetworkSystem::g_pNetworkPool;

void SV_ParseNetsysMessage(edict_t* e, void* msg);
void CL_ParseNetsysMessage(void* msg);

bool bNetsysInitialized = false;

using namespace NetworkSystem;

void ConnectNetsystemLibraries()
{
	g_pNetworkSystem = static_cast<IEngineNetsystem*>(AppFramework::FindInterface(INETSYSTEM_INTERFACE));
	AssertFMsg(g_pNetworkSystem, "Unable to find the networksystem interface!!");
}

void NetworksystemInit()
{
	AssertMsg(!bNetsysInitialized, "NetworkSystem has already been initialized!");
	bNetsysInitialized = true;
	g_pNetworkPool = g_pZoneAllocator->_Mem_AllocPool("NetworksystemPool", __FILE__, __LINE__);
	g_pNetworkSystem->HookServerNetsystemMsg(SV_ParseNetsysMessage);
	g_pNetworkSystem->HookClientNetsystemMsg(CL_ParseNetsysMessage);
}

void NetworksystemShutdown()
{
	AssertMsg(bNetsysInitialized, "NetworkSystem has not been initialized yet!");
	g_pZoneAllocator->_Mem_FreePool(&g_pNetworkPool, __FILE__, __LINE__);
}

//=========================================================================================================================//
// Memory allocation
void NetworkSystem::Mem_Free(void* ptr)
{
	Assert(ptr);
	g_pZoneAllocator->_Mem_Free(ptr, "", 0);
}

void* NetworkSystem::Mem_Alloc(unsigned long long size)
{
	Assert(size > 0);
	return g_pZoneAllocator->_Mem_Alloc(g_pNetworkPool, size, false, "", 0);
}

void* NetworkSystem::Mem_Realloc(void *ptr, unsigned long long size)
{
	Assert(size > 0);
	Assert(ptr);
	return g_pZoneAllocator->_Mem_Realloc(g_pNetworkPool, ptr, size, false, "", 0);
}

void NetworkSystem::SendToServer(unsigned int msgname, const CNetworkMessage &msg)
{

}

void NetworkSystem::SendToClient(unsigned int msgname, edict_t *client, const CNetworkMessage &msg)
{

}

void NetworkSystem::RecvFromServer(unsigned int msgname, pfnRecvServerMsgCallback callback)
{

}

void NetworkSystem::RecvFromClient(unsigned int msgname, edict_t *client, pfnRecvClientMsgCallback callback)
{

}

void NetworkSystem::RecvFromClients(unsigned int msgname, pfnRecvClientMsgCallback callback)
{

}

/**
 * Parse a netsys message received from the server
 */
void CL_ParseNetsysMessage(void* msg)
{
	msg_hdr_t hdr;
	hdr.type = g_pNetworkSystem->ReadShort(msg);

	if(net_debug_messages.GetBool())
		Msg("Received message: type=%u\n", (unsigned)hdr.type);

}

/* Parse a netsys message received from a client connected to the server */
void SV_ParseNetsysMessage(edict_t* e, void* msg)
{

}

//=========================================================================================================================//

//=========================================================================================================================//
// Network byte order functions
// for networksystem, byte order is little endian
short NetworkSystem::htons(short in)
{
#ifdef XASH_BIG_ENDIAN
	return ToLittleEndian(in);
#else
	return in;
#endif
}

int NetworkSystem::htoni(int in)
{
#ifdef XASH_BIG_ENDIAN
	return ToLittleEndian(in);
#else
	return in;
#endif
}

long NetworkSystem::htonl(int in)
{
#ifdef XASH_BIG_ENDIAN
	return ToLittleEndian(in);
#else
	return in;
#endif
}

long long NetworkSystem::htonll(long long in)
{
#ifdef XASH_BIG_ENDIAN
	return ToLittleEndian(in);
#else
	return in;
#endif
}


short NetworkSystem::ntohs(short in)
{
#ifdef XASH_BIG_ENDIAN
	return ToBigEndian(in);
#else
	return in;
#endif
}

int NetworkSystem::ntohi(int in)
{
#ifdef XASH_BIG_ENDIAN
	return ToBigEndian(in);
#else
	return in;
#endif
}

long NetworkSystem::ntohl(long in)
{
#ifdef XASH_BIG_ENDIAN
	return ToBigEndian(in);
#else
	return in;
#endif
}

long long NetworkSystem::ntohll(long long in)
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
