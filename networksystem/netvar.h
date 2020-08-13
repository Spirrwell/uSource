/*
 *
 * netvar.h - Entity subsystem
 *
 */
#pragma once

#include <stddef.h>

#include "common.h"
#include "netproto.h"
#include "reflection.h"

namespace reflection
{
template <class T> void SerializeNetworkedFields(T* _class, Buffer& buffer)
{
	unsigned long long fieldCount = 0;
	SNetworkedField_t* pFields    = _class->GetNetworkedFields(fieldCount);

	for (unsigned long long i = 0; i < fieldCount; i++)
	{
		SNetworkedField_t field = pFields[i];
		if (field.info.flags & ETypeFlags::TYPEFLAGS_NONTRIVIAL)
		{
		}
		else
		{
			/* We're only dealing with trivial types here, so theoretically the max field size should be 8 bytes */
			unsigned char buf[16];
			memcpy(buf, ((unsigned char*)_class) + field.info.offset, field.info.size);
#ifndef XASH_LITTLE_ENDIAN
			ArrayToLittleEndian<16>(buf, field.info.size); // Convert to little endian if we aren't already little endian
#endif

			/* Write out field description info */
			Serialize(field.info.offset, buffer);
			Serialize(field.info.size, buffer);
			Serialize(field.info.flags, buffer);
			buffer.puts(buf, field.info.size);
		}
	}
}

template <class T> void DeserializeNetworkedFields(T* _class, Buffer& buffer)
{
	unsigned long long fieldCount = 0;
	SNetworkedField_t* pFields    = _class->GetNetworkedFields(fieldCount);

	/* Unlike serialize, we don't actually need to write a value. Plus, we don't want to require a well-defined order for
	 * serialized network fields. */
	for (unsigned long long i = 0; i < fieldCount; i++)
	{
		auto offset = Deserialize<unsigned long long>(buffer);
		auto size   = Deserialize<unsigned long long>(buffer);
		auto flags  = Deserialize<unsigned int>(buffer);

		if (flags & ETypeFlags::TYPEFLAGS_NONTRIVIAL)
		{
		}
		else
		{
			unsigned char buf[16];
			buffer.gets((unsigned char*)buf, size);
#ifndef XASH_LITTLE_ENDIAN
			ArrayToBigEndian<16>(buf, size); // Convert to host byte order, if applicable
#endif
			/* Write out the value */
			memcpy(((unsigned char*)_class) + offset, buf, size);
		}
	}
}
} // namespace reflection