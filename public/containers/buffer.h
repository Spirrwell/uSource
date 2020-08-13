/*
 *
 * buffer.h - Simple buffer class
 *
 */
#pragma once

#include "allocator.h"
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <ios>
#include <memory.h>
#include <memory>
#include <sstream>

class BufferSizePolicyLinear
{
public:
	unsigned long long GetNewSize(unsigned long long old) { return old * 2; }
};

class BufferSizePolicyFixed
{
public:
	unsigned long long GetNewSize(unsigned long long old) { return old; }
};

template <class CharT = char, class AllocatorT = DefaultAllocator<CharT>, class SizePolicyT = BufferSizePolicyLinear> class BufferT
{
public:
	typedef long long BufferPos;
	typedef long long BufferSize;

	BufferT& operator=(const BufferT& other)
	{
		this->m_data = m_allocator.allocate(m_size * sizeof(CharT));
		memcpy(this->m_data, other.m_data, sizeof(CharT) * m_size);
		this->m_bufPos	 = other.m_bufPos;
		this->m_size	 = other.m_size;
		this->m_maxWrite = other.m_maxWrite;
		return *this;
	}

	BufferT& operator=(BufferT&& other) noexcept
	{
		this->m_data	 = other.m_data;
		this->m_bufPos	 = other.m_bufPos;
		this->m_size	 = other.m_size;
		this->m_maxWrite = other.m_maxWrite;
		other.m_data	 = nullptr;
		other.m_maxWrite = 0;
		other.m_size	 = 0;
		other.m_bufPos	 = 0;
		return *this;
	}

	CharT operator[](unsigned int i)
	{
		if (i >= m_size)
			return CharT();
		return m_data[i];
	}

private:
	CharT*	    m_data;
	BufferPos   m_bufPos;
	BufferPos   m_size;
	BufferPos   m_maxWrite;
	AllocatorT  m_allocator;
	SizePolicyT m_sizePolicy;

	inline void compute_max_write() { m_maxWrite = m_bufPos > m_maxWrite ? m_bufPos : m_maxWrite; }

public:
	BufferT(BufferSize sz) : m_size(sz), m_bufPos(0), m_maxWrite(-1) { m_data = m_allocator.allocate(sizeof(CharT) * m_size); }

	BufferT(const BufferT& other)
	{
		this->m_data = m_allocator.allocate(m_size * sizeof(CharT));
		memcpy(this->m_data, other.m_data, sizeof(CharT) * m_size);
		this->m_bufPos	 = other.m_bufPos;
		this->m_size	 = other.m_size;
		this->m_maxWrite = other.m_maxWrite;
	}

	BufferT(BufferT&& other) noexcept
	{
		this->m_data	 = other.m_data;
		this->m_bufPos	 = other.m_bufPos;
		this->m_size	 = other.m_size;
		this->m_maxWrite = other.m_maxWrite;
		other.m_data	 = nullptr;
		other.m_maxWrite = 0;
		other.m_size	 = 0;
		other.m_bufPos	 = 0;
	}

	virtual ~BufferT()
	{
		if (m_data)
			m_allocator.deallocate(m_data);
		m_size	 = 0;
		m_bufPos = 0;
	}

	/**
	 * @brief Resizes the buffer based on the internal size policy
	 * @return New size
	 */
	inline BufferSize resize()
	{
		BufferSize newsize = m_sizePolicy.GetNewSize(m_size);
		if (newsize == m_size)
			return m_size;
		m_data = m_allocator.reallocate(m_data, newsize);
		m_size = newsize;
		return m_size;
	}

	/**
	 * @brief Resizes the buffer based on an excplicit size
	 * @param newsize New size
	 * @return New buffer size
	 */
	inline BufferSize resize(BufferSize newsize)
	{
		if (newsize == m_size)
			return m_size;
		m_data = m_allocator.reallocate(m_data, newsize);
		m_size = newsize;
		/* Fix up the buffer pointers */
		m_maxWrite >= m_size ? 0 : m_maxWrite;
		m_bufPos >= m_size ? 0 : m_bufPos;

		return m_size;
	}

	/**
	 * @brief Inserts the string into the buffer.
	 * @param data Pointer to the data buffer
	 * @param count Number of bytes in string
	 * @return Number of bytes written into the buffer
	 */
	inline BufferSize puts(const CharT* data, BufferSize count)
	{
		BufferSize i;
		for (i = 0; i < count && (i + m_bufPos) < m_size; i++)
			m_data[m_bufPos + i] = data[i];
		m_bufPos += i;
		compute_max_write();
		return i;
	}

	/**
	 * @brief Inserts a single string into the end of the buffer
	 * @param c
	 * @return 1 for OK, 0 for failure
	 */
	inline BufferSize putc(CharT c)
	{
		if (m_bufPos + 1 >= m_size)
			return 0;
		m_data[m_bufPos] = c;
		m_bufPos++;
		compute_max_write();
		return 1;
	}

	/**
	 * @brief Grabs some data from the buffer
	 * @param data Pointer to the output buffer
	 * @param maxsize Max size of the output buffer
	 * @return Number of bytes written to the buffer
	 */
	inline BufferSize gets(CharT* data, BufferSize maxsize)
	{
		BufferSize i;
		for (i = 0; i < maxsize && (m_bufPos + i) < m_size; i++)
			data[i] = m_data[i + m_bufPos];
		m_bufPos += i;
		compute_max_write();
		return i;
	}

	/**
	 * @brief Reads a string from the buffer without changing the input ptr
	 * @param data Pointer to output buffer
	 * @param sz Size of the output buffer
	 * @return Number of bytes written
	 */
	inline BufferSize peeks(CharT* data, BufferSize sz)
	{
		BufferSize i;
		for (i = 0; i < sz && (i + m_bufPos) < m_size; i++)
			data[i] = m_data[i + m_bufPos];
		return i;
	}

	/**
	 * @brief Returns the next char from the buffer and increments the buffer pos
	 * @return next char from the buffer
	 */
	inline int getc()
	{
		int dat = m_data[m_bufPos];
		m_bufPos++;
		compute_max_write();
		return dat;
	}

	/**
	 * @brief Returns next char from buffer without incrementing it
	 * @return next char
	 */
	inline int peek() const { return m_data[m_bufPos]; }

	/**
	 * @brief Get the current pos of the read/write head
	 * @return
	 */
	inline BufferPos current_pos() const { return m_bufPos; }

	/**
	 * @brief Seeks to the very start of the buffer
	 * @return Old buffer position
	 */
	inline BufferPos seek_start()
	{
		BufferPos old = m_bufPos;
		m_bufPos      = 0;
		return old;
	}

	/**
	 * @brief Seeks to the very end of the buffer. Note: This seeks to the end of the allocated region
	 * @return Old buffer position
	 */
	inline BufferPos seek_end()
	{
		BufferPos old = m_bufPos;
		m_bufPos      = m_size - 1;
		return old;
	}

	/**
	 * @brief Seeks to a relative position based on the current read/write head
	 * @param offset
	 * @return New position of the buffer
	 */
	inline BufferPos seek_cur(int offset)
	{
		if (offset + m_bufPos >= m_size)
			return m_bufPos;
		m_bufPos += offset;
	}

	/**
	 * @brief Seeks to an absolute position in the buffer. Must be >= 0 && < max_size
	 * @param offset Absolute offset in the buffer
	 * @return Old position in the buffer
	 */
	inline BufferPos seek_absolute(BufferPos offset)
	{
		if (offset > m_size)
			return m_bufPos;
		BufferPos old = m_bufPos;
		m_bufPos      = offset;
		return m_bufPos;
	}

	/**
	 * @return Max allocated size of the buffer
	 */
	inline BufferSize max_size() const { return m_size; }

	/**
	 * @return Number of chars written to the buffer
	 */
	inline BufferSize size() const { return m_maxWrite; }

	/**
	 * @return Pointer to the data of the buffer
	 */
	inline void* data() const { return m_data; }

	/**
	 * @brief Zeroes out the internal buffer
	 */
	inline void clear() { memset(m_data, 0, sizeof(CharT) * m_size); }

	/**
	 * @brief Resizes the internal buffer so that it's  the same size as the data written to it
	 */
	inline void compact()
	{
		/* Cannot compact if we're already at max compaction */
		if (m_maxWrite == m_size - 1)
			return;
		this->resize(m_maxWrite);
	}

	/**
	 * @brief Returns true if the buffer is empty
	 * @return
	 */
	inline bool empty() const { return (m_maxWrite == -1 || m_size == 0); }

	/**
	 * @return returns if the buffer will overflow if you write the specified number of bytes to it
	 */
	inline bool will_overflow(BufferSize num_bytes) const { return (m_bufPos + num_bytes >= m_size); }

	/**
	 * @brief Writes the current buffer to a stream
	 * @param stream
	 * @return
	 */
	inline BufferSize write_to_stream(FILE* stream) const
	{
		if (m_maxWrite == m_bufPos)
			return 0;
		return (BufferSize)std::fwrite(&m_data[m_bufPos], sizeof(CharT), m_maxWrite - m_bufPos, stream);
	}

	/**
	 * @brief Reads the buffer data from the stream
	 * @param stream Stream to read from
	 * @param num_bytes number of bytes to read
	 * @return
	 */
	inline BufferSize read_from_stream(FILE* stream, BufferSize num_bytes)
	{
		if ((num_bytes / sizeof(CharT)) > m_size)
			resize(num_bytes / sizeof(CharT));
		std::size_t num_read = fread(&m_data[m_bufPos], 1, num_bytes, stream);
		m_bufPos += (num_read / sizeof(CharT));
		compute_max_write();
		return (BufferSize)num_read;
	}
};

template <unsigned long long N, class CharT = unsigned char>
class FixedBufferT : public BufferT<CharT, StaticAllocator<CharT, N>, BufferSizePolicyFixed>
{
public:
	typedef BufferT<CharT, StaticAllocator<CharT, N>, BufferSizePolicyFixed> BaseClass;

	FixedBufferT() : BaseClass(N) {}

	virtual ~FixedBufferT() {}
};

typedef BufferT<unsigned char> Buffer;
