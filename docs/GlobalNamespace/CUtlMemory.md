# class CUtlMemory

*Defined at line 107 of ./mainui/miniutl/utlmemory.h*

Inherits from CUtlMemoryBase



## Functions

### CUtlMemory<T>

*public void CUtlMemory<T>(int nGrowSize, int nInitSize)*

*Defined at line 191 of ./mainui/miniutl/utlmemory.h*

 constructor, destructor

----------------------------------------------------------------------------- constructor, destructor-----------------------------------------------------------------------------

### CUtlMemory<T>

*public void CUtlMemory<T>(T * pMemory, int numElements)*

*Defined at line 198 of ./mainui/miniutl/utlmemory.h*

### CUtlMemory<T>

*public void CUtlMemory<T>(const T * pMemory, int numElements)*

*Defined at line 204 of ./mainui/miniutl/utlmemory.h*

### operator[]

*public T & operator[](int i)*

*Defined at line 222 of ./mainui/miniutl/utlmemory.h*

 element access

----------------------------------------------------------------------------- element access-----------------------------------------------------------------------------

### operator[]

*public const T & operator[](int i)*

*Defined at line 230 of ./mainui/miniutl/utlmemory.h*

### Element

*public T & Element(int i)*

*Defined at line 237 of ./mainui/miniutl/utlmemory.h*

### Element

*public const T & Element(int i)*

*Defined at line 245 of ./mainui/miniutl/utlmemory.h*

### Base

*public T * Base()*

*Defined at line 256 of ./mainui/miniutl/utlmemory.h*

 Gets the base address (can change when adding elements!)

----------------------------------------------------------------------------- Gets the base address (can change when adding elements!)-----------------------------------------------------------------------------

### Base

*public const T * Base()*

*Defined at line 262 of ./mainui/miniutl/utlmemory.h*

### CUtlMemory<T>

*private void CUtlMemory<T>(const CUtlMemory<T> & rhs)*

 Copy construction and assignment are not valid

### operator=

*private const CUtlMemory<T> & operator=(const CUtlMemory<T> & rhs)*



