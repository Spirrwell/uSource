#pragma once

#undef min
#undef max
#include "net_int.h"
#include "engine_int.h"
#include "const.h"
#include "reflection.h"

extern IEngineNetsystem* g_pNetworkSystem;

void ConnectNetsystemLibraries();
void NetworksystemInit();
void NetworksystemShutdown();

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
	 */
	typedef void(*pfnRecvServerMsgCallback)(CNetworkMessage&);
	typedef void(*pfnRecvClientMsgCallback)(edict_t*,CNetworkMessage&);
	void RecvFromServer(unsigned int msgname, pfnRecvServerMsgCallback callback);
	void RecvFromClient(unsigned int msgname, edict_t* client, pfnRecvClientMsgCallback callback);
	void RecvFromClients(unsigned int msgname, pfnRecvClientMsgCallback callback);

	extern byte* g_pNetworkPool;

	void* Mem_Alloc(unsigned long long size);
	void* Mem_Realloc(void* ptr, unsigned long long size);
	void Mem_Free(void* ptr);

	/* Network byte-order functions */
	/* NOTE: These are ONLY for Networksystem!!! */
	short htons(short in);
	int htoni(int in);
	long htonl(int in);
	long long htonll(long long in);

	short ntohs(short in);
	int ntohi(int in);
	long ntohl(long in);
	long long ntohll(long long in);
}

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
	void* m_data;
	unsigned long m_size;
	unsigned long m_bufpos;
	bool m_overflowed : 1;
	bool m_init : 1;

public:
	enum {
		ABSOLUTE,
		RELATIVE
	};
	CNetworkMessage(unsigned long size = 2048);
	CNetworkMessage(const CNetworkMessage& other);
	CNetworkMessage(CNetworkMessage&& other) noexcept;
	~CNetworkMessage();

	void InitStorage();
	bool WasInit() const { return m_init; }

	void WriteInt64(long long l);
	void WriteUInt64(unsigned long long l);
	void WriteInt(int i);
	void WriteUInt(unsigned int i);
	void WriteShort(short s);
	void WriteUShort(unsigned short s);
	void WriteByte(unsigned char b);
	void WriteChar(char c);
	void WriteBytes(void* pBytes, unsigned long num);

	int ReadInt();
	unsigned int ReadUInt();
	short ReadShort();
	unsigned short ReadUShort();
	unsigned char ReadByte();
	char ReadChar();
	long long ReadInt64();
	unsigned long long ReadUInt64();
	void ReadBytes(void* outbuf, unsigned long num);

	const void* Data() const { return m_data; }

	unsigned long Size() const { return m_size; };
	unsigned long BufferPos() const { return m_bufpos; }
	bool HasOverflowed() const { return m_overflowed; };
	bool IsEmpty() const { return m_bufpos == 0; };
	bool Good() const { return !m_overflowed; };

	void Clear();
	void Resize(unsigned long newsize);
	void Seek(unsigned type, unsigned long pos);

	CNetworkMessage& operator=(const CNetworkMessage& msg);
	CNetworkMessage& operator=(CNetworkMessage&& msg) noexcept;
};