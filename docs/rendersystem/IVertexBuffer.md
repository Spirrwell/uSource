# class IVertexBuffer

*Defined at line 268 of ./rendersystem/ibuffer.h*

## Functions

### ~IVertexBuffer

*public void ~IVertexBuffer()*

### AllocateStorage

*public void AllocateStorage(size_t num_elements)*

 Allocates internal buffer storage for this buffer.

**num_elements**

### AllocateInitStorage

*public void AllocateInitStorage(size_t num_elements, void * buffer)*

 Allocates and initializes storage, assumes the target buffer is the same format as this buffer

**num_elements**

**buffer**

### GetStorage

*public void * GetStorage()*

 Returns a pointer to the internal storage if this buffer is shared or host-only

### CopyIntoBuffer

*public void CopyIntoBuffer(void * buf, size_t length)*

 Copies the buffer into this index buffer

**buf**

**length**

### GetFormat

*public enum rendersystem::EVertexFormat GetFormat()*

 Returns the format of the buffer

### Lock

*public void Lock()*

 Performs a memory lock operation which will propagate changes in host memory to GPU memory if the buffer type is shared

### GetType

*public enum rendersystem::EBufferType GetType()*

 Returns the type of this buffer.

### GetSize

*public size_t GetSize()*

 Returns the size of the internal data store



