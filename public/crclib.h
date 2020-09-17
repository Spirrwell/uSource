/*
crclib.c - generate crc stuff
Copyright (C) 2007 Uncle Mike
Copyright (C) 2019 a1batross

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/
#pragma once
#ifndef CRCLIB_H
#define CRCLIB_H

#include "xash3d_types.h"

typedef struct
{
	uint	buf[4];
	uint	bits[2];
	byte	in[64];
} MD5Context_t;


EXPORT void CRC32_Init(dword* pulCRC);
EXPORT byte CRC32_BlockSequence(byte* base, int length, int sequence);
EXPORT void CRC32_ProcessBuffer(dword* pulCRC, const void* pBuffer, int nBuffer);
EXPORT void CRC32_ProcessByte(dword* pulCRC, byte ch);
EXPORT dword CRC32_Final(dword pulCRC);
EXPORT void  MD5Init(MD5Context_t* ctx);
EXPORT void  MD5Update(MD5Context_t* ctx, const byte* buf, uint len);
EXPORT void  MD5Final(byte digest[16], MD5Context_t* ctx);
EXPORT uint COM_HashKey(const char* string, uint hashSize);
EXPORT char* MD5_Print(byte hash[16]);

#endif // CRCLIB_H
