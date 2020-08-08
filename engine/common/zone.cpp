/*
zone.c - zone memory allocation from DarkPlaces
Copyright (C) 2007 Uncle Mike

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

#include "common.h"
#include "engine_int.h"
#include "public/mem.h"

#define MEMHEADER_SENTINEL1	0xDEADF00D
#define MEMHEADER_SENTINEL2	0xDF

typedef struct memheader_s
{
	struct memheader_s	*next;		// next and previous memheaders in chain belonging to pool
	struct memheader_s	*prev;
	struct mempool_s	*pool;		// pool this memheader belongs to
	size_t		size;		// size of the memory after the header (excluding header and sentinel2)
	const char	*filename;	// file name and line where Mem_Alloc was called
	uint		fileline;
	uint		sentinel1;	// should always be MEMHEADER_SENTINEL1

	// immediately followed by data, which is followed by a MEMHEADER_SENTINEL2 byte
} memheader_t;

typedef struct mempool_s
{
	uint		sentinel1;	// should always be MEMHEADER_SENTINEL1
	struct memheader_s	*chain;		// chain of individual memory allocations
	size_t		totalsize;	// total memory allocated in this pool (inside memheaders)
	size_t		realsize;		// total memory allocated in this pool (actual malloc total)
	size_t		lastchecksize;	// updated each time the pool is displayed by memlist
	struct mempool_s	*next;		// linked into global mempool list
	const char	*filename;	// file name and line where Mem_AllocPool was called
	int		fileline;
	char		name[64];		// name of the pool
	uint		sentinel2;	// should always be MEMHEADER_SENTINEL1
} mempool_t;

// mempool_t *poolchain = NULL; // critical stuff

void *_Mem_Alloc( byte *poolptr, size_t size, qboolean clear, const char *filename, int fileline )
{
	return g_pZoneAllocator->_Mem_Alloc(poolptr, size, clear, filename, fileline);
}

void _Mem_Free( void *data, const char *filename, int fileline )
{
	g_pZoneAllocator->_Mem_Free(data, filename, fileline);
}

void *_Mem_Realloc( byte *poolptr, void *memptr, size_t size, qboolean clear, const char *filename, int fileline )
{
	return g_pZoneAllocator->_Mem_Realloc(poolptr, memptr, size, clear, filename, fileline);
}

byte *_Mem_AllocPool( const char *name, const char *filename, int fileline )
{
	return g_pZoneAllocator->_Mem_AllocPool(name, filename, fileline);
}

void _Mem_FreePool( byte **poolptr, const char *filename, int fileline )
{
	g_pZoneAllocator->_Mem_FreePool(poolptr, filename, fileline);
}

void _Mem_EmptyPool( byte *poolptr, const char *filename, int fileline )
{
	g_pZoneAllocator->_Mem_EmptyPool(poolptr, filename, fileline);
}

/*
========================
Check pointer for memory
========================
*/
qboolean Mem_IsAllocatedExt( byte *poolptr, void *data )
{
	return g_pZoneAllocator->Mem_IsAllocatedExt(poolptr, data);
}

void _Mem_Check( const char *filename, int fileline )
{
	return g_pZoneAllocator->_Mem_Check(filename, fileline);
}

void Mem_PrintStats( void )
{
	return g_pZoneAllocator->Mem_PrintStats();
}

void Mem_PrintList( size_t minallocationsize )
{
	return g_pZoneAllocator->Mem_PrintList(minallocationsize);
}

/*
========================
Memory_Init
========================
*/
void Memory_Init( void )
{
	g_pZoneAllocator->Memory_Init();
}
