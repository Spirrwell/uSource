# class CUtlMemoryFixed

*Defined at line 138 of ./mainui/miniutl/utlmemory.h*

----------------------------------------------------------------------------- The CUtlMemoryFixed class: A fixed memory class-----------------------------------------------------------------------------



## Members

private uint8 [SIZE * sizeof(T)] m_Memory



## Functions

### CUtlMemoryFixed<T, SIZE>

*public void CUtlMemoryFixed<T, SIZE>(int nGrowSize, int nInitSize)*

*Defined at line 142 of ./mainui/miniutl/utlmemory.h*

 constructor, destructor

### CUtlMemoryFixed<T, SIZE>

*public void CUtlMemoryFixed<T, SIZE>(T * pMemory, int numElements)*

*Defined at line 143 of ./mainui/miniutl/utlmemory.h*

### IsIdxValid

*public _Bool IsIdxValid(int i)*

*Defined at line 146 of ./mainui/miniutl/utlmemory.h*

 Can we use this index?

### Base

*public T * Base()*

*Defined at line 149 of ./mainui/miniutl/utlmemory.h*

 Gets the base address

### Base

*public const T * Base()*

*Defined at line 150 of ./mainui/miniutl/utlmemory.h*

### operator[]

*public T & operator[](int i)*

*Defined at line 153 of ./mainui/miniutl/utlmemory.h*

 element access

### operator[]

*public const T & operator[](int i)*

*Defined at line 154 of ./mainui/miniutl/utlmemory.h*

### Element

*public T & Element(int i)*

*Defined at line 155 of ./mainui/miniutl/utlmemory.h*

### Element

*public const T & Element(int i)*

*Defined at line 156 of ./mainui/miniutl/utlmemory.h*

### SetExternalBuffer

*public void SetExternalBuffer(T * pMemory, int numElements)*

*Defined at line 159 of ./mainui/miniutl/utlmemory.h*

 Attaches the buffer to external memory....

### NumAllocated

*public int NumAllocated()*

*Defined at line 162 of ./mainui/miniutl/utlmemory.h*

 Size

### Count

*public int Count()*

*Defined at line 163 of ./mainui/miniutl/utlmemory.h*

### Grow

*public void Grow(int num)*

*Defined at line 166 of ./mainui/miniutl/utlmemory.h*

 Grows the memory, so that at least allocated + num elements are allocated

### EnsureCapacity

*public void EnsureCapacity(int num)*

*Defined at line 169 of ./mainui/miniutl/utlmemory.h*

 Makes sure we've got at least this much memory

### Purge

*public void Purge()*

*Defined at line 172 of ./mainui/miniutl/utlmemory.h*

 Memory deallocation

### Purge

*public void Purge(int numElements, _Bool bRealloc)*

*Defined at line 175 of ./mainui/miniutl/utlmemory.h*

 Purge all but the given number of elements (NOT IMPLEMENTED IN CUtlMemoryFixed)

### IsExternallyAllocated

*public _Bool IsExternallyAllocated()*

*Defined at line 178 of ./mainui/miniutl/utlmemory.h*

 is the memory externally allocated?

### SetGrowSize

*public void SetGrowSize(int size)*

*Defined at line 181 of ./mainui/miniutl/utlmemory.h*

 Set the size by which the memory grows



