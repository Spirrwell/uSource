/*
 *
 * netvar.h - Entity subsystem
 *
 */
#pragma once

#include <stddef.h>

#include "netproto.h"

struct SNetworkedField_t
{
	unsigned long long id;
	const char* name;
	unsigned long long offset;
};

class INetworkedClass
{
public:
	virtual SNetworkedField_t* GetNetworkedFields(unsigned long long& num) = 0;
};