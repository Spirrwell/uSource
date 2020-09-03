# class CUtlMemoryBase

*Defined at line 38 of ./mainui/miniutl/utlmemory.h*

----------------------------------------------------------------------------- The CUtlMemory class: A growable memory class which doubles in size by default.-----------------------------------------------------------------------------



## Members

protected uint32 m_unSizeOfElements

protected void * m_pMemory

protected int m_nAllocationCount

protected int m_nGrowSize



## Functions

### CUtlMemoryBase

*public void CUtlMemoryBase(int nSizeOfType, int nGrowSize, int nInitSize)*

*Defined at line 11 of ./mainui/miniutl/utlmemory.cpp*

 constructor, destructor

### CUtlMemoryBase

*public void CUtlMemoryBase(int nSizeOfType, void * pMemory, int numElements)*

*Defined at line 24 of ./mainui/miniutl/utlmemory.cpp*

### CUtlMemoryBase

*public void CUtlMemoryBase(int nSizeOfType, const void * pMemory, int numElements)*

*Defined at line 33 of ./mainui/miniutl/utlmemory.cpp*

### ~CUtlMemoryBase

*public void ~CUtlMemoryBase()*

*Defined at line 41 of ./mainui/miniutl/utlmemory.cpp*

### IsIdxValid

*public _Bool IsIdxValid(int i)*

*Defined at line 173 of ./mainui/miniutl/utlmemory.cpp*

 Can we use this index?

----------------------------------------------------------------------------- Is element index valid?-----------------------------------------------------------------------------

### SetExternalBuffer

*public void SetExternalBuffer(void * pMemory, int numElements)*

*Defined at line 103 of ./mainui/miniutl/utlmemory.cpp*

 Attaches the buffer to external memory....

----------------------------------------------------------------------------- Attaches the buffer to external memory....-----------------------------------------------------------------------------

### SetExternalBuffer

*public void SetExternalBuffer(const void * pMemory, int numElements)*

*Defined at line 116 of ./mainui/miniutl/utlmemory.cpp*

### Swap

*public void Swap(class CUtlMemoryBase & mem)*

*Defined at line 50 of ./mainui/miniutl/utlmemory.cpp*

 Fast swap

----------------------------------------------------------------------------- Fast swap-----------------------------------------------------------------------------

### Detach

*public void * Detach()*

*Defined at line 65 of ./mainui/miniutl/utlmemory.cpp*

----------------------------------------------------------------------------- Fast swap-----------------------------------------------------------------------------

### ConvertToGrowableMemory

*public void ConvertToGrowableMemory(int nGrowSize)*

*Defined at line 77 of ./mainui/miniutl/utlmemory.cpp*

 Switches the buffer from an external memory buffer to a reallocatable buffer Will copy the current contents of the external buffer to the reallocatable buffer

----------------------------------------------------------------------------- Switches the buffer from an external memory buffer to a reallocatable buffer-----------------------------------------------------------------------------

### NumAllocated

*public int NumAllocated()*

*Defined at line 158 of ./mainui/miniutl/utlmemory.cpp*

 Size

----------------------------------------------------------------------------- Size-----------------------------------------------------------------------------

### Count

*public int Count()*

*Defined at line 164 of ./mainui/miniutl/utlmemory.cpp*

### CubAllocated

*public int CubAllocated()*

*Defined at line 66 of ./mainui/miniutl/utlmemory.h*

### Grow

*public void Grow(int num)*

*Defined at line 228 of ./mainui/miniutl/utlmemory.cpp*

 Grows the memory, so that at least allocated + num elements are allocated

### EnsureCapacity

*public void EnsureCapacity(int num)*

*Defined at line 262 of ./mainui/miniutl/utlmemory.cpp*

 Makes sure we've got at least this much memory

----------------------------------------------------------------------------- Makes sure we've got at least this much memory-----------------------------------------------------------------------------

### Purge

*public void Purge()*

*Defined at line 294 of ./mainui/miniutl/utlmemory.cpp*

 Memory deallocation

----------------------------------------------------------------------------- Memory deallocation-----------------------------------------------------------------------------

### Purge

*public void Purge(int numElements, _Bool bRealloc)*

*Defined at line 309 of ./mainui/miniutl/utlmemory.cpp*

 Purge all but the given number of elements

### IsExternallyAllocated

*public _Bool IsExternallyAllocated()*

*Defined at line 132 of ./mainui/miniutl/utlmemory.cpp*

 is the memory externally allocated?

----------------------------------------------------------------------------- is the memory externally allocated?-----------------------------------------------------------------------------

### IsReadOnly

*public _Bool IsReadOnly()*

*Defined at line 141 of ./mainui/miniutl/utlmemory.cpp*

 is the memory read only?

----------------------------------------------------------------------------- is the memory read only?-----------------------------------------------------------------------------

### SetGrowSize

*public void SetGrowSize(int size)*

*Defined at line 147 of ./mainui/miniutl/utlmemory.cpp*

 Set the size by which the memory grows

### CUtlMemoryBase

*protected void CUtlMemoryBase(const class CUtlMemoryBase & rhs)*

 Copy construction and assignment are not valid

### operator=

*protected const class CUtlMemoryBase & operator=(const class CUtlMemoryBase & rhs)*



## Enums

| enum  |

--

| EXTERNAL_BUFFER_MARKER |
| EXTERNAL_CONST_BUFFER_MARKER |


*Defined at line 94 of ./mainui/miniutl/utlmemory.h*



