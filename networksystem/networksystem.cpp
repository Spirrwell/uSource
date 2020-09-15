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

#include "containers/list.h"
#include "containers/hashmap.h"

Convar net_debug_messages("net_debug_messages", "0", FCVAR_CHEAT | FCVAR_ARCHIVE);

IEngineNetsystem* g_pNetworkSystem = NULL;
byte* NetworkSystem::g_pNetworkPool;

/* Callbacks registered BY the client FOR messages sent BY the server */
struct cl_usermsg_callback
{
	unsigned int msgid;
	List<NetworkSystem::pfnRecvServerMsgCallback> callbacks;
};
Array<cl_usermsg_callback> g_client_msg_callbacks;

/* Callbacks registered BY the server FOR message sent BY a client */
struct sv_usermsg_callback_t
{
	unsigned int msgid;
	struct internal_callback
	{
		bool any;
		int client_id;
		NetworkSystem::pfnRecvClientMsgCallback callback;
	};
	List<internal_callback> callbacks;
};
Array<sv_usermsg_callback_t> g_server_msg_callbacks;

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
}

void NetworksystemShutdown()
{
	AssertMsg(bNetsysInitialized, "NetworkSystem has not been initialized yet!");
	g_pZoneAllocator->_Mem_FreePool(&g_pNetworkPool, __FILE__, __LINE__);
}


void NetworksystemInit_Client()
{
	g_pNetworkSystem->HookClientNetsystemMsg(CL_ParseNetsysMessage);
	CClientUserMessageHook::Init();
}

void NetworksystemInit_Server()
{
	g_pNetworkSystem->HookServerNetsystemMsg(SV_ParseNetsysMessage);
	CServerUserMessageHook::Init();
}

IEngineNetsystem* GlobalNetworkSystem()
{
	return g_pNetworkSystem;
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
//=========================================================================================================================//

//=========================================================================================================================//
// Send/Recv from client/server
void NetworkSystem::SendToServer(unsigned int msgname, const CNetworkMessage &msg)
{
	g_pNetworkSystem->BeginClientNetsystemCmd();
		g_pNetworkSystem->WriteShort(HDR_USRMSG); // Write out the message type
		g_pNetworkSystem->WriteInt(msgname); // Write out the message id
		g_pNetworkSystem->WriteInt(msg.Size()); // Write out the message length
		g_pNetworkSystem->WriteBytes(msg.Data(), msg.Size()); // Write out the message data
	g_pNetworkSystem->EndMessage();
}

void NetworkSystem::SendToClient(unsigned int msgname, edict_t *client, const CNetworkMessage &msg)
{
	g_pNetworkSystem->BeginServerNetsystemCmd(client);
		g_pNetworkSystem->WriteShort(HDR_USRMSG); // Write out the message type
		g_pNetworkSystem->WriteInt(msgname); // Write out the message id
		g_pNetworkSystem->WriteInt(msg.Size()); // Write out the message length
		g_pNetworkSystem->WriteBytes(msg.Data(), msg.Size()); // Write out the message data
	g_pNetworkSystem->EndMessage();
}


void NetworkSystem::HookMsgFromServer(unsigned int msgname, pfnRecvServerMsgCallback callback)
{
	for(auto& x : g_client_msg_callbacks)
	{
		if(x.msgid == msgname)
		{
			x.callbacks.push_back(callback);
			return;
		}
	}

	/* Not found. add new callback entry */
	cl_usermsg_callback _callback;
	_callback.msgid = msgname;
	_callback.callbacks.push_back(callback);
	g_client_msg_callbacks.push_back(_callback);
}

void NetworkSystem::HookMsgFromClient(unsigned int msgname, int client, pfnRecvClientMsgCallback callback)
{
	for(auto& x : g_server_msg_callbacks)
	{
		if(x.msgid == msgname)
		{
			x.callbacks.push_back({
				false,          /* Ignore client id? */
				client,         /* Client ID */
				callback,               /* Callback */
			});
			return;
		}
	}

	/* Not found. Add new entry */
	sv_usermsg_callback_t _callback_table;
	_callback_table.msgid = msgname;
	_callback_table.callbacks.push_back({
		false,          /* Ignore client id? */
		client,   /* Client ID */
		callback,               /* Callback */
	});
	g_server_msg_callbacks.push_back(_callback_table);
}

void NetworkSystem::HookMsgFromClients(unsigned int msgname, pfnRecvClientMsgCallback callback)
{
	for(auto& x : g_server_msg_callbacks)
	{
		if(x.msgid == msgname)
		{
			x.callbacks.push_back({
				true,
				0,
				callback,
			});
			return;
		}
	}

	/* Not found. Add new entry */
	sv_usermsg_callback_t _callback_table;
	_callback_table.msgid = msgname;
	_callback_table.callbacks.push_back({
		true,
		0,
		callback,
	});
	g_server_msg_callbacks.push_back(_callback_table);
}


/**
 * Parse a netsys message received from the server
 */
void CL_ParseNetsysMessage(void* msg)
{
	msg_hdr_t hdr;
	hdr.type = g_pNetworkSystem->ReadInt(msg);

	CNetworkMessage msgbuf;
	switch(hdr.type)
	{
		case HDR_USRMSG:
		{
			usrmsg_hdr_t usermsghdr;
			usermsghdr.id = g_pNetworkSystem->ReadInt(msg);
			usermsghdr.length = g_pNetworkSystem->ReadInt(msg);
			/* Initialize a new message buffer */
			msgbuf = CNetworkMessage(usermsghdr.length);
			msgbuf.InitStorage();
			g_pNetworkSystem->ReadBytes(msg, msgbuf.Data(), usermsghdr.length);
			/* Search for a usermessage entry and execute it */
			for (const auto &callback : g_client_msg_callbacks)
			{
				if (callback.msgid != usermsghdr.id) continue;
				for (const auto &entry : callback.callbacks)
				{
					entry(msgbuf);
				}
			}
			break;
		}
		case HDR_VARUPD:
			Error("Varupdate message type is not implemented yet.\n");
		default:
			Error("Unknown message type %u received from server\n", hdr.type);
			break;
	}

	if(net_debug_messages.GetBool())
		Msg("CLIENT: Received message: type=%u\n", (unsigned)hdr.type);

}

/* Parse a netsys message received from a client connected to the server */
void SV_ParseNetsysMessage(edict_t* e, void* msg)
{
	msg_hdr_t hdr;
	hdr.type = g_pNetworkSystem->ReadInt(msg);

	CNetworkMessage msgbuf;
	switch(hdr.type)
	{
	case HDR_USRMSG:
	{
		usrmsg_hdr_t usermsghdr;
		usermsghdr.id = g_pNetworkSystem->ReadInt(msg);
		usermsghdr.length = g_pNetworkSystem->ReadInt(msg);
		/* Initialize a new message buffer */
		msgbuf = CNetworkMessage(usermsghdr.length);
		msgbuf.InitStorage();
		g_pNetworkSystem->ReadBytes(msg, msgbuf.Data(), usermsghdr.length);
		/* Search for a usermessage entry and execute it */
		for (const auto &callback : g_server_msg_callbacks)
		{
			if (callback.msgid != usermsghdr.id) continue;
			for (const auto &entry : callback.callbacks)
			{
				if (entry.any || (entry.client_id == e->serialnumber))
					entry.callback(e, msgbuf);
			}
		}
		break;
	}
	case HDR_VARUPD:
		Error("Varupdate message type is not implemented yet.\n");
	default:
		Error("Unknown message type %u received from client %u\n", hdr.type, e->serialnumber);
		break;
	}

	if(net_debug_messages.GetBool())
		Msg("SERVER: Received message: type=%u client=%u\n", (unsigned)hdr.type, e->serialnumber);
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
	m_data = Mem_Alloc(size);
}

CNetworkMessage::CNetworkMessage(void *data, size_t size) :
	m_init(true),
	m_data(nullptr),
	m_size(size),
	m_bufpos(0),
	m_overflowed(false)
{
	Assert(size > 0);
	m_data = Mem_Alloc(size);
	memcpy(m_data, data, size);
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

void CNetworkMessage::Reset() const
{
	m_bufpos = 0;
	m_overflowed = false;
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

int CNetworkMessage::ReadInt() const
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

unsigned int CNetworkMessage::ReadUInt() const
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

short CNetworkMessage::ReadShort() const
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

unsigned short CNetworkMessage::ReadUShort() const
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

unsigned char CNetworkMessage::ReadByte() const
{
	if(m_bufpos + 4 >= m_size)
	{
		m_overflowed = true;
		return 0;
	}
	m_bufpos++;
	return ((char*)m_data)[m_bufpos-1];
}

char CNetworkMessage::ReadChar() const
{
	if(m_bufpos + 4 >= m_size)
	{
		m_overflowed = true;
		return 0;
	}
	m_bufpos++;
	return ((char*)m_data)[m_bufpos-1];
}

long long CNetworkMessage::ReadInt64() const
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

unsigned long long CNetworkMessage::ReadUInt64() const
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

void CNetworkMessage::ReadBytes(void *outbuf, unsigned long num) const
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
List<CServerUserMessageHook::desc_t>* g_server_message_hooks_registry = nullptr;
bool CServerUserMessageHook::init = false;
CServerUserMessageHook::CServerUserMessageHook(unsigned int _m, int client_index, void (*callback)(edict_t *, const CNetworkMessage &))
{
	if(!g_server_message_hooks_registry)
		g_server_message_hooks_registry = new List<CServerUserMessageHook::desc_t>();
	g_server_message_hooks_registry->push_back({_m, client_index, callback});
}

CServerUserMessageHook::~CServerUserMessageHook()
{

}

void CServerUserMessageHook::Init()
{
	Assert(!CServerUserMessageHook::init);
	init = true;
	if(!g_server_message_hooks_registry) return;
	for(auto c : *g_server_message_hooks_registry)
	{
		if(c.clid == -1)
			NetworkSystem::HookMsgFromClients(c.msgid, c.callback);
		else
			NetworkSystem::HookMsgFromClient(c.msgid, c.clid, c.callback);
	}
}
//=========================================================================================================================//

//=========================================================================================================================//
List<CClientUserMessageHook::desc_t>* g_client_message_hooks_registry = nullptr;
bool CClientUserMessageHook::init = false;
CClientUserMessageHook::CClientUserMessageHook(unsigned int _m, void (*callback)(const CNetworkMessage &))
{
	if(!g_client_message_hooks_registry)
		g_client_message_hooks_registry = new List<CClientUserMessageHook::desc_t>();
	g_client_message_hooks_registry->push_back({_m, callback});
}

CClientUserMessageHook::~CClientUserMessageHook()
{

}

void CClientUserMessageHook::Init()
{
	Assert(!CClientUserMessageHook::init);
	init = true;
	if(!g_client_message_hooks_registry) return;
	for(auto c : *g_client_message_hooks_registry)
	{
		NetworkSystem::HookMsgFromServer(c.msgid, c.callback);
	}
}
//=========================================================================================================================//
