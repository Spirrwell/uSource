#pragma once

#undef min
#undef max
#include "const.h"
#include "engine_int.h"
#include "net_int.h"
#include "reflection.h"

extern IEngineNetsystem* g_pNetworkSystem;

void ConnectNetsystemLibraries();
void NetworksystemInit();
void NetworksystemInit_Client();
void NetworksystemInit_Server();
void NetworksystemShutdown();

#define USR_MSG_RESERVED_MAX 512
#define USR_MSG_RESERVED_MIN 0

class CNetworkMessage;

namespace NetworkSystem
{
/**
 * Thread-safe methods to send messages to clients and the server
 * Internally, it puts them in a queue and will send them cl_cmdrate times per second
 * Try not to saturate this too much!
 * @param msgid Unique id of this message. Used in the recv functions
 * @param msg the message itself
 * @param client The client to send the message to
 */
void SendToServer(unsigned int msgname, const CNetworkMessage& msg);
void SendToClient(unsigned int msgname, edict_t* client, const CNetworkMessage& msg);

/**
 * Listens for the message on the client or server and calls the specified callback when the message
 * is received. You'll need to make a local copy of the message in order to use it
 * Replaces the usermessage system
 */
typedef void (*pfnRecvServerMsgCallback)(const CNetworkMessage&);
typedef void (*pfnRecvClientMsgCallback)(edict_t*, const CNetworkMessage&);
void HookMsgFromServer(unsigned int msgname, pfnRecvServerMsgCallback callback);
void HookMsgFromClient(unsigned int msgname, int client, pfnRecvClientMsgCallback callback);
void HookMsgFromClients(unsigned int msgname, pfnRecvClientMsgCallback callback);

extern byte* g_pNetworkPool;

void* Mem_Alloc(unsigned long long size);
void* Mem_Realloc(void* ptr, unsigned long long size);
void  Mem_Free(void* ptr);

/* Network byte-order functions */
/* NOTE: These are ONLY for Networksystem!!! */
short	  htons(short in);
int	  htoni(int in);
long	  htonl(int in);
long long htonll(long long in);

short	  ntohs(short in);
int	  ntohi(int in);
long	  ntohl(long in);
long long ntohll(long long in);
} // namespace NetworkSystem

enum class ENetworkType
{
	BYTE,
	SHORT,
	INT,
	LONG, /* Note: always 64bit long */
	FLOAT,
	DOUBLE,
	STRING
};

/**
 * Network message class. Internally converted to a sizebuf structure
 */
class CNetworkMessage
{
private:
	void*		      m_data;
	unsigned long	      m_size;
	mutable unsigned long m_bufpos;
	mutable bool	      m_overflowed : 1;
	bool		      m_init : 1;

public:
	enum
	{
		ABSOLUTE,
		RELATIVE
	};
	CNetworkMessage(unsigned long size = 2048);
	CNetworkMessage(void* data, size_t size);
	CNetworkMessage(const CNetworkMessage& other);
	CNetworkMessage(CNetworkMessage&& other) noexcept;
	~CNetworkMessage();

	void InitStorage();
	bool WasInit() const { return m_init; }

	/* Resets the buffer position and other flags to allow for re-reading */
	void Reset() const;

	void WriteInt64(long long l);
	void WriteUInt64(unsigned long long l);
	void WriteInt(int i);
	void WriteUInt(unsigned int i);
	void WriteShort(short s);
	void WriteUShort(unsigned short s);
	void WriteByte(unsigned char b);
	void WriteChar(char c);
	void WriteBytes(void* pBytes, unsigned long num);

	int		   ReadInt() const;
	unsigned int	   ReadUInt() const;
	short		   ReadShort() const;
	unsigned short	   ReadUShort() const;
	unsigned char	   ReadByte() const;
	char		   ReadChar() const;
	long long	   ReadInt64() const;
	unsigned long long ReadUInt64() const;
	void		   ReadBytes(void* outbuf, unsigned long num) const;

	const void* Data() const { return m_data; }
	void*	    Data() { return m_data; };

	unsigned long Size() const { return m_size; };
	unsigned long BufferPos() const { return m_bufpos; }
	bool	      HasOverflowed() const { return m_overflowed; };
	bool	      IsEmpty() const { return m_bufpos == 0; };
	bool	      Good() const { return !m_overflowed; };

	void Clear();
	void Resize(unsigned long newsize);
	void Seek(unsigned type, unsigned long pos);

	CNetworkMessage& operator=(const CNetworkMessage& msg);
	CNetworkMessage& operator=(CNetworkMessage&& msg) noexcept;
};

/**
 * Class used to hook a usermessage coming from a client
 * Does some static magic!
 */
class CServerUserMessageHook
{
public:
	struct desc_t
	{
		unsigned int msgid;
		int	     clid;
		void (*callback)(edict_t*, const CNetworkMessage&);
	};

	static bool  init;
	unsigned int msg;

	CServerUserMessageHook(unsigned int msg, int client_id, void (*callback)(edict_t*, const CNetworkMessage&));

	~CServerUserMessageHook();

	static void Init();
};

/**
 * Hooks a usermessage coming from the server
 */
class CClientUserMessageHook
{
public:
	static bool init;
	struct desc_t
	{
		unsigned int msgid;
		void (*callback)(const CNetworkMessage&);
	};

	CClientUserMessageHook(unsigned int msg, void (*callback)(const CNetworkMessage&));

	~CClientUserMessageHook();

	static void Init();
};