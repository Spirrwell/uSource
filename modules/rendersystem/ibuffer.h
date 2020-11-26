#pragma once

#include "rendersystem_common.h"

#include <stddef.h>
#include <stdint.h>
#include <initializer_list>
#include "public/containers/list.h"

BEGIN_RENDERSYSTEM_NAMESPACE

/* Defines the type of buffer */
enum class EBufferType
{
	HOST = 0, /* Host-only */
	SHARED,   /* Mapped in both host and GPU memory, changes are propagated every so-often */
	CLIENT,   /* GPU only */
};

/* Various supported types by CBufferFormat */
enum class EBufferFormatType :
	unsigned char
{
	VEC2F, // Float vectors
	VEC3F,
	VEC4F,
	VEC2D, // Double vectors
	VEC3D,
	VEC4D,
	I8,    // Signed integers
	I16,
	I32,
	I64,
	U8,    // Unsigned integers
	U16,
	U32,
	U64,
	F16,   // Floats
	F32,
	F64,
	F80,
	MAT2,  // 2x2 matricies
	MAT3,
	MAT4,
	OTHER, // If your type is not listed here, select other
};

/*

Buffer formats allow you to specify a format for an aribtrary buffer type. They can be used in conjunction with a
 buffer view in order to access the buffer in a variety of different ways

 Usage:

 CBufferFormat Format(
        CBufferFormatType(BITS(sizeof(int), "Index"),
        CBufferFormatType(BITS(sizeof(vec3_t)), "Position"),
        CBufferFormatType(BITS(sizeof(vec3_t)), "Normal"),
        CBufferFormatType(BITS(sizeof(vec3_t)), "Tangent"))


 */
class CBufferFormatType
{
private:
	int m_bits; /* Size of the type in bits */
	const char* m_name; /* Reference name of the type */

	template<class...T>
	friend class CBufferFormatT;
public:
	CBufferFormatType(int size_in_bits, const char* name) :
		m_bits(size_in_bits),
		m_name(name)
	{
	}
};

/* Pure virtual baseclass for CBufferFormat */
class IBufferFormat
{
public:
	virtual size_t StrideForType(unsigned index) const = 0;
	virtual size_t SizeOfType(unsigned index) const = 0;
	virtual unsigned int MaskOfType(unsigned index) const = 0;
};

template<class...T>
class CBufferFormat : IBufferFormat
{
private:
	CBufferFormatType m_nodes[sizeof...(T)];
	size_t m_strides[sizeof...(T)];
	size_t m_numNodes;
public:
	CBufferFormat() = delete;

	CBufferFormat(const CBufferFormat& other)
	{
		m_numNodes = other.m_numNodes;
		for(size_t i = 0; i < m_numNodes; i++)
		{
			m_nodes[i] = other.m_nodes[i];
			m_strides[i] = other.m_strides[i];
		}
	}

	CBufferFormat(T...args) :
		m_numNodes(sizeof...(T))
	{
		m_nodes = {
			args...
		};

		/* Compute total size */
		size_t totalSize = 0;
		for(int i = 0; i < m_numNodes; i++)
			totalSize += m_nodes[i].m_bits;

		/* Compute strides */
		for(size_t i = 0; i < m_numNodes; i++)
			m_strides[i] = totalSize - m_nodes[i].m_bits;
	}

	size_t StrideForType(unsigned index) const override
	{
		if(index >= m_numNodes) return 0;
		return m_strides[index];
	}

	/* Returns the size of the type in BITS */
	size_t SizeOfType(unsigned index) const override
	{
		if(index >= m_numNodes) return 0;
		return m_nodes[index].m_bits;
	}

	/* Returns the access mask of the type, if it's not aligned to a byte boundary */
	/* Basically, any types that don't have byte granularity */
	unsigned int MaskOfType(unsigned index) const override
	{
		if(index >= m_numNodes) return 0;
		return 0;
	}

	CBufferFormat& operator=(const CBufferFormat& other)
	{
		m_numNodes = other.m_numNodes;
		for(size_t i = 0; i < m_numNodes; i++)
		{
			m_nodes[i] = other.m_nodes[i];
			m_strides[i] = other.m_strides[i];
		}
	}
};

/*
 * Wrapper around an IBuffer object that allows for accessing elements in relation to a
 * buffer format
 */
class CBufferAccessor
{
private:
	class IBuffer* m_buffer;
	IBufferFormat* m_format;
public:
	CBufferAccessor() = delete;
	CBufferAccessor(class IBuffer* buffer);
	CBufferAccessor(class IBuffer& buffer);

	~CBufferAccessor();

	/**
	 * Binds a new format to this object. By default, this object will use the
	 * source buffer's format
	 * @param fmt
	 */
	void BindFormat(const IBufferFormat* fmt);

	/**
	 * Unbinds all buffer formats from this object. This will revert the buffer format to
	 * the source buffer's format
	 */
	void UnbindFormat();

	/**
	 * Accesses an element from the buffer using the currently bound buffer format.
	 * @param element_index Index of the element inside of the buffer format. E.g. 0 for the first one, 1 for second, etc.
	 * @param buffer_index Index of the element
	 * @return
	 */
	void* AccessElement(size_t element_index, size_t buffer_index);
};

class IBuffer
{
public:
	virtual ~IBuffer() = 0;

	virtual EBufferType GetType() const = 0;

	/**
	 * Returns the size of the internal data store 
	 */ 
	virtual size_t GetSize() const = 0;

	/**
	 * Returns a const ref to the buffer format description 
	 */ 
	virtual const IBufferFormat* GetBufferFormatDesc() const = 0;

	/**
	 * Returns a ptr to the internal data store
	 * @return Pointer to the internal data store
	 */ 
	virtual void* GetStorage() = 0;

	/**
	 * Performs a memory lock operation propagating changes from host memory to client memory if type == SHARED
	 */ 
	virtual void Lock() = 0;

	/**
	 * Allocates the internal storage for n elements 
	 * @param num_elements the number of elements inside of the buffer
	 */ 
	virtual void AllocateStorage(size_t num_elements) = 0;

	/**
	 * Allocates and initializes storage, assumes the target buffer is the same format as this buffer
	 * @param num_elements The number of elements in this data store
	 * @param buffer Pointer to a buffer that's the SAME SIZE as this one will be
	 */ 
	virtual void AllocateInitStorage(size_t num_elements, void* buffer) = 0;

	/**
	 * Copies data from the specified buffer into this current buffer
	 * @param buffer Pointer to the buffer
	 * @param size Size (IN NUMBER OF ELEMENTS) of the buffer
	 */ 
	virtual void CopyIntoBuffer(void* buf, size_t num_elements) = 0;
};


/*
Vertex formats are quite simple. They're intended to be tightly packed arrays of verticies for GL rendering
*/
enum class EVertexFormat
{
	INT2 = 0,    /* 2d vector that uses integers */
	FLOAT2,      /* 2d vector that uses floats for all elements */
	DOUBLE2,     /* 2d vector that uses doubles for all elements */
	INT3,        /* 3d vector of ints */
	FLOAT3,      /* 3d vector of floats */
	DOUBLE3,     /* 3d vector of doubles */
	INT4,        /* 4d vector of ints */
	FLOAT4,      /* 4d vector of floats */
	DOUBLE4,     /* 4d vector of doubles */
};

enum class EIndexFormat
{
	BYTE = 0, /* 8 bits per index, so 255 verticies max */
	SHORT,    /* 16 bits per index, so 16k verticies max */
	INT,      /* 32 bits per index, so 4 billion verticies max */
};

class IVertexBuffer
{
public:
	virtual ~IVertexBuffer() = 0;

	/**
	 * Allocates internal buffer storage for this buffer.
	 * @param num_elements number of elements we should allocate storage for
	 */ 
	virtual void AllocateStorage(size_t num_elements) = 0;

	/**
	 * Allocates and initializes storage, assumes the target buffer is the same format as this buffer
	 * @param num_elements The number of elements in this data store
	 * @param buffer Pointer to a buffer that's the SAME SIZE as this one will be
	 */ 
	virtual void AllocateInitStorage(size_t num_elements, void* buffer) = 0;

	/**
	 * Returns a pointer to the internal storage if this buffer is shared or host-only
	 */ 
	virtual void* GetStorage() const = 0;

	/**
	 * Copies the buffer into this index buffer
	 * @param buf Pointer to the buffer
	 * @param length size in ELEMENTS of the buffer
	 */ 
	virtual void CopyIntoBuffer(void* buf, size_t length) = 0;

	/**
	 * Returns the format of the buffer
	 */ 
	virtual EVertexFormat GetFormat() const = 0;

	/**
	 * Performs a memory lock operation which will propagate changes in host memory to GPU memory
	 * if the buffer type is shared
	 */ 
	virtual void Lock() = 0;

	/**
	 * Returns the type of this buffer.
	 */ 
	virtual EBufferType GetType() const = 0;

	/**
	 * Returns the size of the internal data store
	 */ 
	virtual size_t GetSize() const = 0;
};

class IIndexBuffer
{
public:
	virtual ~IIndexBuffer() = 0;

	/**
	 * Allocates internal buffer storage for this buffer.
	 * @param num_elements number of elements we should allocate storage for
	 */ 
	virtual void AllocateStorage(size_t num_elements) = 0;

	/**
	 * Returns a pointer to the internal storage if this buffer is shared or host-only
	 */ 
	virtual void* GetStorage() const = 0;

	/**
	 * Copies the buffer into this index buffer
	 * @param buf Pointer to the buffer
	 * @param length size in bytes of the buffer
	 */ 
	virtual void CopyIntoBuffer(void* buf, size_t length) = 0;

	/**
	 * Returns the format of the buffer
	 */ 
	virtual EIndexFormat GetFormat() const = 0;

	/**
	 * Performs a memory lock operation which will propagate changes in host memory to GPU memory
	 * if the buffer type is shared
	 */ 
	virtual void Lock() = 0;

	/**
	 * Returns the type of this buffer.
	 */ 
	virtual EBufferType GetType() const = 0;

	/**
	 * Returns the size of the internal data store
	 */ 
	virtual size_t GetSize() const = 0;
};

END_RENDERSYSTEM_NAMESPACE