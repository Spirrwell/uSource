# class CBufferFormat

*Defined at line 89 of ./rendersystem/ibuffer.h*

Inherits from IBufferFormat



## Members

private class rendersystem::CBufferFormatType [sizeof...(T)] m_nodes

private size_t [sizeof...(T)] m_strides

private size_t m_numNodes



## Functions

### CBufferFormat<T...>

*public void CBufferFormat<T...>()*

*Defined at line 96 of ./rendersystem/ibuffer.h*

### CBufferFormat<T...>

*public void CBufferFormat<T...>(const CBufferFormat<T...> & other)*

*Defined at line 98 of ./rendersystem/ibuffer.h*

### CBufferFormat<T...>

*public void CBufferFormat<T...>(T... args)*

*Defined at line 108 of ./rendersystem/ibuffer.h*

### StrideForType

*public size_t StrideForType(unsigned int index)*

*Defined at line 125 of ./rendersystem/ibuffer.h*

### SizeOfType

*public size_t SizeOfType(unsigned int index)*

*Defined at line 132 of ./rendersystem/ibuffer.h*

 Returns the size of the type in BITS 

### MaskOfType

*public unsigned int MaskOfType(unsigned int index)*

*Defined at line 140 of ./rendersystem/ibuffer.h*

 Returns the access mask of the type, if it's not aligned to a byte boundary 

 Basically, any types that don't have byte granularity 

### operator=

*public CBufferFormat<T...> & operator=(const CBufferFormat<T...> & other)*

*Defined at line 146 of ./rendersystem/ibuffer.h*



