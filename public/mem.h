/*
 *
 * memory.h - Global memory interface.
 *
 */

/*
 * Originally this code was located in the engine and initialized early on in Host_Main.
 * However, with the addition of tier1 to the engine, and since we've ported a bunch of stuff to C++,
 * static initialization is now a thing and it's used a LOT. Problem is, sometimes statically initialized objects
 * (such as cvars), depend on the engine's memory allocator internally, due to how the cvar system works.
 * Since the engine allocator isn't initialized like *as soon* as the program starts, we sometimes get engine crashes
 * with various tier1 utils, or other things.
 * - Jeremy L. Aug 8th, 2020
 */

#pragma once

#include <stdint.h>
#include <stddef.h>

#include "common.h"

/* Different from the other classes as we're trying to replace the engine's zone allocator */
class CZoneAllocator
{
public:
	CZoneAllocator();
	virtual void Memory_Init( void );
	virtual void *_Mem_Realloc( byte *poolptr, void *memptr, size_t size, bool clear, const char *filename, int fileline );
	virtual void *_Mem_Alloc( byte *poolptr, size_t size, bool clear, const char *filename, int fileline );
	virtual byte *_Mem_AllocPool( const char *name, const char *filename, int fileline );
	virtual void _Mem_FreePool( byte **poolptr, const char *filename, int fileline );
	virtual void _Mem_EmptyPool( byte *poolptr, const char *filename, int fileline );
	virtual void _Mem_Free( void *data, const char *filename, int fileline );
	virtual void _Mem_Check( const char *filename, int fileline );
	virtual bool Mem_IsAllocatedExt( byte *poolptr, void *data );
	virtual void Mem_PrintList( size_t minallocationsize );
	virtual void Mem_PrintStats( void );
};

extern CZoneAllocator* g_pZoneAllocator;

CZoneAllocator& GlobalAllocator();

class IBaseMemoryAllocator
{
public:
	virtual void* malloc(size_t sz) = 0;
	virtual void* calloc(size_t size_of_object, size_t num_objects) = 0;
	virtual void* realloc(void* ptr, size_t newsize) = 0;
	virtual void free(void* ptr) = 0;
};

/* TODO: Implement these new allocators */
#if 0
class CSmallBlockAllocator : public IBaseMemoryAllocator
{
public:
	void* malloc(size_t sz) override;
	void* calloc(size_t size_of_object, size_t num_objects) override;
	void* realloc(void* ptr, size_t newsize) override;
	void free(void* ptr)  override;
};

class CStringAllocator : public IBaseMemoryAllocator
{
public:
	void* malloc(size_t sz) override;
	void* calloc(size_t size_of_object, size_t num_objects) override;
	void* realloc(void* ptr, size_t newsize) override;
	void free(void* ptr)  override;
};

class CSlabAllocator : public IBaseMemoryAllocator
{
public:
	void* malloc(size_t sz) override;
	void* calloc(size_t size_of_object, size_t num_objects) override;
	void* realloc(void* ptr, size_t newsize) override;
	void free(void* ptr)  override;
};
#endif