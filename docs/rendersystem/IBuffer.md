# class IBuffer

*Defined at line 195 of ./rendersystem/ibuffer.h*

## Functions

### ~IBuffer

*public void ~IBuffer()*

### GetType

*public enum rendersystem::EBufferType GetType()*

### GetSize

*public size_t GetSize()*

 Returns the size of the internal data store 

### GetBufferFormatDesc

*public const class rendersystem::IBufferFormat * GetBufferFormatDesc()*

 Returns a const ref to the buffer format description 

### GetStorage

*public void * GetStorage()*

 Returns a ptr to the internal data store

**return** Pointer to the internal data store

### Lock

*public void Lock()*

 Performs a memory lock operation propagating changes from host memory to client memory if type == SHARED

### AllocateStorage

*public void AllocateStorage(size_t num_elements)*

 Allocates the internal storage for n elements 

**num_elements**

### AllocateInitStorage

*public void AllocateInitStorage(size_t num_elements, void * buffer)*

 Allocates and initializes storage, assumes the target buffer is the same format as this buffer

**num_elements**

**buffer**

### CopyIntoBuffer

*public void CopyIntoBuffer(void * buf, size_t num_elements)*

 Copies data from the specified buffer into this current buffer

**buffer**

**size**



