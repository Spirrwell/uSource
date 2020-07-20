/*
 *
 * entity_system.h - Entity subsystem
 *
 */
#pragma once

#include <stddef.h>

enum class ECoherenceType
{
	SERVER, /* Server -> Client */
	CLIENT, /* Client -> Server */
};

#define NET_MAX_FIELDS 65536
#define NET_MAX_FIELD_SIZE 65535

/**
 * Max number of exported fields in a class: 65536
 * Max size of an exported field: 65535
 * Max offset of a field in a class: ~4 billion
 */
#pragma pack(1)
struct ClassFieldDescription_t
{
	unsigned short m_id;      /* ID used to identify this field */
	unsigned int m_offset;    /* Offset of the field in the class or struct */
	unsigned short m_size;    /* Size of the field in bytes */
	unsigned char m_type;     /* Coherence model for this type */
};

struct ClassNetvarMessageHeader_t
{
	unsigned long long m_classid; /* Unique ID of the class. One per TYPE */
	unsigned long long m_objectid; /* Unique ID of the object itself. This is PER OBJECT. */
	unsigned short m_numFields; /* Number of fields being sent over in the message */
};
#pragma pack()

/**
 * All classes that want to use the netvar system should derive from this class.
 */
class INetworkedClass
{
public:
	virtual ClassFieldDescription_t* GetNetvarTable(int& __num_vars) { return nullptr; }
};

/**
Usage:
 BEGIN_NETVAR_DECL
 	DECLARE_NETVAR(0, m_iMyInteger, ECoherenceType::SERVER),
 	DECLARE_NETVAR(1, m_fMyFloat, ECoherenceType::SERVER),
 	DECLARE_NETVAR(2, m_vMyVector, ECoherenceType::SERVER),
 END_NETVAR_DECL

 The _i parameter corresponds to a netvar ID that corresponds to a parameter. This allows you to mix up the order of the netvars, but you must remember
 the netvar ID. It's explicit so that you don't end up with fucked up bugs on the client or server because you accidentally swapped a pair of params in the list

 */
#define DECLARE_NETVAR(_i, _x, _c) {(_i), ((unsigned int)offsetof(_CNetworkedBaseClass, _x)), sizeof(_x), (_c)}

#define BEGIN_NETVAR_LIST(_class) ClassFieldDescription_t* _class::GetNetvarTable(int& __num_vars) {\
static ClassFieldDescription_t __descs[] = {\

#define END_NETVAR_LIST };\
__num_vars = (sizeof(__descs) / sizeof(ClassFieldDescription_t));\
return __descs;}

#define DECLARE_NETWORKED_CLASS(_x) private:\
typedef _x _CNetworkedBaseClass;\
public:\
virtual ClassFieldDescription_t* GetNetvarTable(int& __num_vars) override

/*
EXAMPLE OF HOW TO USE NETWORKED VARS:

class CNetworkedClass : INetworkedClass
{
public:
	int m_nVar;
	float m_fVar;
	bool m_bVar;

	DECLARE_NETWORKED_CLASS(CNetworkedClass);


};

// In CPP file or something
BEGIN_NETVAR_LIST(CNetworkedClass)
	DECLARE_NETVAR(0, m_nVar, ECoherenceType::SERVER),
	DECLARE_NETVAR(1, m_fVar, ECoherenceType::SERVER),
	DECLARE_NETVAR(2, m_bVar, ECoherenceType::SERVER),
END_NETVAR_LIST

*/

namespace NetvarSystem
{
	/**
	 * Call once from your game code to initialize the netvar system. Note: This doesn't need to be called prior to adding types
	 */
	void InitNetvarSystem();

	/**
	 * Registers a networked type with the system. Should ONLY be called during static initialization. Strongly ordered by means of internal trickery
	 * @tparam T
	 * @return typeid of the networked type
	 */
	template<class T>
	unsigned long long RegisterNetworkedType();

	/**
	 * For a newly created networked class, create the component on the client
	 * @param pNetworkable
	 * @return Unique ID of the object
	 */
	unsigned long long CreateClientClassComponent(INetworkedClass* pNetworkable);

	/**
	 * Returns the unique object ID of the specified class on the client
	 * @param pNetworkable
	 * @return
	 */
	unsigned long long GetClientClassComponent(INetworkedClass* pNetworkable);
	unsigned long long GetNetworkObjectId(INetworkedClass* pNetworkable);

	/**
	 * Destroy the client component of the specified networked class. Either a pointer or objectid can be used
	 * @param pNetworkable
	 */
	void DestroyClientClassComponent(INetworkedClass* pNetworkable);
	void DestroyClientClassComponent(unsigned long long objid);

	/**
	 * Returns the networked type id of the specified networkable class
	 * @param pNetworkable
	 * @return typeid
	 */
	unsigned long long GetNetworkTypeId(INetworkedClass* pNetworkable);

}