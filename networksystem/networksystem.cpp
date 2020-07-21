#include "common.h"
#include "edict.h"
#include "const.h"
#include "appframework.h"
#include "networksystem.h"
#include "netproto.h"

IEngineNetsystem* g_pNetworkSystem;

void SV_ParseNetsysMessage(edict_t* e, void* msg);
void CL_ParseNetsysMessage(void* msg);

void ConnectNetsystemLibraries()
{
	g_pNetworkSystem = static_cast<IEngineNetsystem*>(AppFramework::FindInterface(INETSYSTEM_INTERFACE));
}

void NetworksystemInit()
{
	g_pNetworkSystem->HookServerNetsystemMsg(SV_ParseNetsysMessage);
	g_pNetworkSystem->HookClientNetsystemMsg(CL_ParseNetsysMessage);
}

void SV_ParseNetsysMessage(edict_t* e, void* msg)
{

}

void CL_ParseNetsysMessage(void* msg)
{

}

CNetworkMessage::CNetworkMessage(unsigned long size)
{

}

CNetworkMessage::CNetworkMessage(const CNetworkMessage &other)
{

}

CNetworkMessage::CNetworkMessage(CNetworkMessage &&other) noexcept 
{

}

CNetworkMessage::~CNetworkMessage()
{

}

void CNetworkMessage::WriteInt64(long long int l)
{

}

void CNetworkMessage::WriteUInt64(unsigned long long int l)
{

}

void CNetworkMessage::WriteInt(int i)
{

}

void CNetworkMessage::WriteUInt(unsigned int i)
{

}

void CNetworkMessage::WriteShort(short s)
{

}

void CNetworkMessage::WriteUShort(unsigned short s)
{

}

void CNetworkMessage::WriteByte(unsigned char b)
{

}

void CNetworkMessage::WriteChar(char c)
{

}

void CNetworkMessage::WriteBytes(void *pBytes, unsigned long num)
{

}

int CNetworkMessage::ReadInt()
{
	return 0;
}

unsigned int CNetworkMessage::ReadUInt()
{
	return 0;
}

short CNetworkMessage::ReadShort()
{
	return 0;
}

unsigned short CNetworkMessage::ReadUShort()
{
	return 0;
}

unsigned char CNetworkMessage::ReadByte()
{
	return 0;
}

char CNetworkMessage::ReadChar()
{
	return 0;
}

long long CNetworkMessage::ReadInt64()
{
	return 0;
}

unsigned long long CNetworkMessage::ReadUInt64()
{
	return 0;
}

void CNetworkMessage::Clear()
{

}

void CNetworkMessage::Resize(unsigned long newsize)
{

}

void CNetworkMessage::Seek(unsigned int type, unsigned long pos)
{

}

CNetworkMessage &CNetworkMessage::operator=(const CNetworkMessage &msg)
{
	return *this;
}

CNetworkMessage &CNetworkMessage::operator=(CNetworkMessage &&msg) noexcept
{
	return *this;
}
