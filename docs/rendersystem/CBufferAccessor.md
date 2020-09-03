# class CBufferAccessor

*Defined at line 161 of ./rendersystem/ibuffer.h*

 Wrapper around an IBuffer object that allows for accessing elements in relation to a buffer format



## Members

private class IBuffer * m_buffer

private class rendersystem::IBufferFormat * m_format



## Functions

### CBufferAccessor

*public void CBufferAccessor()*

*Defined at line 167 of ./rendersystem/ibuffer.h*

### CBufferAccessor

*public void CBufferAccessor(class IBuffer * buffer)*

### CBufferAccessor

*public void CBufferAccessor(class IBuffer & buffer)*

### ~CBufferAccessor

*public void ~CBufferAccessor()*

### BindFormat

*public void BindFormat(const class rendersystem::IBufferFormat * fmt)*

 Binds a new format to this object. By default, this object will use the source buffer's format

**fmt**

### UnbindFormat

*public void UnbindFormat()*

 Unbinds all buffer formats from this object. This will revert the buffer format to the source buffer's format

### AccessElement

*public void * AccessElement(size_t element_index, size_t buffer_index)*

 Accesses an element from the buffer using the currently bound buffer format.

**element_index**

**buffer_index**

**return**



