#pragma once

#include "net_int.h"
#include "const.h"

extern IEngineNetsystem* g_pNetworkSystem;

void ConnectNetsystemLibraries();
void NetworksystemInit();

class CNetworkMessage;

namespace NetSystem
{
	/**
	 * Thread-safe methods to send messages to clients and the server
	 * Internally, it puts them in a queue and will send them cl_cmdrate times per second
	 * Try not to saturate this too much!
	 * @param msgid Unique id of this message. Used in the recv functions
	 * @param msg the message itself
	 * @param client The client to send the message to
	 */
	void SendToServer(int msgid, const CNetworkMessage& msg);
	void SendToClient(int msgid, edict_t* client, const CNetworkMessage& msg);

	/**
	 * Listens for the message on the client or server and calls the specified callback when the message
	 * is received. You'll need to make a local copy of the message in order to use it
	 */
	typedef void(*pfnRecvServerMsgCallback)(CNetworkMessage&);
	typedef void(*pfnRecvClientMsgCallback)(edict_t*,CNetworkMessage&);
	void RecvFromServer(int msgid, pfnRecvServerMsgCallback callback);
	void RecvFromClient(int msgid, edict_t* client, pfnRecvClientMsgCallback callback);
	void RecvFromClients(int msgid, pfnRecvClientMsgCallback callback);
}

/**
 * Network message class. Internally converted to a sizebuf structure
 */
class CNetworkMessage
{
private:
	void* m_data;
	unsigned long m_size;
	unsigned long m_bufpos;
	bool m_overflowed;
public:
	enum {
		ABSOLUTE,
		RELATIVE
	};
	CNetworkMessage(unsigned long size = 2048);
	CNetworkMessage(const CNetworkMessage& other);
	CNetworkMessage(CNetworkMessage&& other) noexcept;
	~CNetworkMessage();

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