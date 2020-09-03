# class CZoneAllocator

*Defined at line 25 of ./public/mem.h*

 Different from the other classes as we're trying to replace the engine's zone allocator 



## Functions

### CZoneAllocator

*public void CZoneAllocator()*

*Defined at line 385 of ./public/mem.cpp*

### Memory_Init

*public void Memory_Init()*

*Defined at line 377 of ./public/mem.cpp*

### _Mem_Realloc

*public void * _Mem_Realloc(byte * poolptr, void * memptr, size_t size, _Bool clear, const char * filename, int fileline)*

*Defined at line 168 of ./public/mem.cpp*

### _Mem_Alloc

*public void * _Mem_Alloc(byte * poolptr, size_t size, _Bool clear, const char * filename, int fileline)*

*Defined at line 75 of ./public/mem.cpp*

### _Mem_AllocPool

*public byte * _Mem_AllocPool(const char * name, const char * filename, int fileline)*

*Defined at line 196 of ./public/mem.cpp*

### _Mem_FreePool

*public void _Mem_FreePool(byte ** poolptr, const char * filename, int fileline)*

*Defined at line 219 of ./public/mem.cpp*

### _Mem_EmptyPool

*public void _Mem_EmptyPool(byte * poolptr, const char * filename, int fileline)*

*Defined at line 242 of ./public/mem.cpp*

### _Mem_Free

*public void _Mem_Free(void * data, const char * filename, int fileline)*

*Defined at line 161 of ./public/mem.cpp*

### _Mem_Check

*public void _Mem_Check(const char * filename, int fileline)*

*Defined at line 310 of ./public/mem.cpp*

### Mem_IsAllocatedExt

*public _Bool Mem_IsAllocatedExt(byte * poolptr, void * data)*

*Defined at line 280 of ./public/mem.cpp*

========================Check pointer for memory========================

### Mem_PrintList

*public void Mem_PrintList(size_t minallocationsize)*

*Defined at line 345 of ./public/mem.cpp*

### Mem_PrintStats

*public void Mem_PrintStats()*

*Defined at line 328 of ./public/mem.cpp*



