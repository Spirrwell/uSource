#pragma once

#include "appframework.h"
#include "net_api.h"

#define INETAPI_001 "IEngineNetwork001"
#define INETAPI_INTERFACE INETAPI_001

class IEngineNetAPI : public IAppInterface
{
public:
	virtual void		InitNetworking( void ) = 0;
	virtual void		Status ( struct net_status_s *status ) = 0;
	virtual void		SendRequest( int context, int request, int flags, double timeout, struct netadr_s *remote_address, net_api_response_func_t response ) = 0;
	virtual void		CancelRequest( int context ) = 0;
	virtual void		CancelAllRequests( void ) = 0;
	virtual char		*AdrToString( struct netadr_s *a ) = 0;
	virtual int		CompareAdr( struct netadr_s *a, struct netadr_s *b ) = 0;
	virtual int		StringToAdr( char *s, struct netadr_s *a ) = 0;
	virtual const char	*ValueForKey( const char *s, const char *key ) = 0;
	virtual void		RemoveKey( char *s, const char *key ) = 0;
	virtual void		SetValueForKey( char *s, const char *key, const char *value, int maxsize ) = 0;
};

/**
 * IEngineNetsystem is a higher-level interface to the server networking system
 */

#define INETSYSTEM_001 "IEngineNetsystem001"
#define INETSYSTEM_INTERFACE INETSYSTEM_001

enum class ENetSourceType {
	NETSRC_CLIENT = 0,
	NETSRC_SERVER
};

class IEngineNetsystem : public IAppInterface
{
public:
	virtual void HookServerNetsystemMsg(void(*pfnHook)(edict_t*, void*)) = 0;
	virtual void HookClientNetsystemMsg(void(*pfnHook)(void*)) = 0;

	/* Hooks any client or server message */
	virtual void HookServerMsg(int cmd, void(*pfnHook)(edict_t*, void*)) = 0;
	virtual void HookClientMsg(int cmd, void(*pfnHook)(void*)) = 0;

	/* Basic message sending api for the client and server */
	/* This API is not threadsafe, so be careful! */
	virtual void BeginClientNetsystemCmd() = 0;
	virtual void BeginServerNetsystemCmd(edict_t* client) = 0;

	/* Alternatively, you can use this to begin a custom message */
	virtual void BeginServerMessage(int cmd, edict_t* client) = 0;
	virtual void BeginClientMessage(int cmd) = 0;
	virtual void EndMessage() = 0;

	virtual void WriteBytes(void* pBuf, unsigned long long len) = 0;
	virtual void WriteString(const char* str) = 0;
	virtual void WriteByte(byte _byte) = 0;
	virtual void WriteShort(short _short) = 0;
	virtual void WriteInt(int _int) = 0;
	virtual void WriteLong(long long _long) = 0;
	virtual void WriteFloat(float _fl) = 0;
	virtual void WriteVector(vec3_t _vec) = 0;

	/* Used to decode a message. No state is held here */
	virtual void ReadBytes(void* pBuffer, void* pOutbuf, unsigned long long num) = 0;
	virtual void ReadString(void* pBuffer, char* pOutbuf, unsigned long long num) = 0;
	virtual byte ReadByte(void* pBuffer) = 0;
	virtual short ReadShort(void* pBuffer) = 0;
	virtual int ReadInt(void* pBuffer) = 0;
	virtual long long ReadLong(void* pBuffer) = 0;
	virtual float ReadFloat(void* pBuffer) = 0;
	virtual void ReadVector(void* pBuffer, vec3_t outvec) = 0;
};