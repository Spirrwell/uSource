# class BufferT

*Defined at line 37 of ./public/containers/buffer.h*

## Members

private CharT * m_data

private BufferT::BufferPos m_bufPos

private BufferT::BufferPos m_size

private BufferT::BufferPos m_maxWrite

private AllocatorT m_allocator

private SizePolicyT m_sizePolicy



## Functions

### operator=

*public BufferT<CharT, AllocatorT, SizePolicyT> & operator=(const BufferT<CharT, AllocatorT, SizePolicyT> & other)*

*Defined at line 43 of ./public/containers/buffer.h*

### operator=

*public BufferT<CharT, AllocatorT, SizePolicyT> & operator=(BufferT<CharT, AllocatorT, SizePolicyT> && other)*

*Defined at line 53 of ./public/containers/buffer.h*

### operator[]

*public CharT operator[](unsigned int i)*

*Defined at line 66 of ./public/containers/buffer.h*

### compute_max_write

*private void compute_max_write()*

*Defined at line 80 of ./public/containers/buffer.h*

### BufferT<CharT, AllocatorT, SizePolicyT>

*public void BufferT<CharT, AllocatorT, SizePolicyT>(BufferT::BufferSize sz)*

*Defined at line 86 of ./public/containers/buffer.h*

### BufferT<CharT, AllocatorT, SizePolicyT>

*public void BufferT<CharT, AllocatorT, SizePolicyT>(const BufferT<CharT, AllocatorT, SizePolicyT> & other)*

*Defined at line 94 of ./public/containers/buffer.h*

### BufferT<CharT, AllocatorT, SizePolicyT>

*public void BufferT<CharT, AllocatorT, SizePolicyT>(BufferT<CharT, AllocatorT, SizePolicyT> && other)*

*Defined at line 103 of ./public/containers/buffer.h*

### ~BufferT<CharT, AllocatorT, SizePolicyT>

*public void ~BufferT<CharT, AllocatorT, SizePolicyT>()*

*Defined at line 115 of ./public/containers/buffer.h*

### resize

*public BufferT::BufferSize resize()*

*Defined at line 127 of ./public/containers/buffer.h*



**brief** Resizes the buffer based on the internal size policy

**return** New size

### resize

*public BufferT::BufferSize resize(BufferT::BufferSize newsize)*

*Defined at line 141 of ./public/containers/buffer.h*



**brief** Resizes the buffer based on an excplicit size

**newsize**

**return** New buffer size

### puts

*public BufferT::BufferSize puts(const CharT * data, BufferT::BufferSize count)*

*Defined at line 159 of ./public/containers/buffer.h*



**brief** Inserts the string into the buffer.

**data**

**count**

**return** Number of bytes written into the buffer

### putc

*public BufferT::BufferSize putc(CharT c)*

*Defined at line 174 of ./public/containers/buffer.h*



**brief** Inserts a single string into the end of the buffer

**c**

**return** 1 for OK, 0 for failure

### gets

*public BufferT::BufferSize gets(CharT * data, BufferT::BufferSize maxsize)*

*Defined at line 189 of ./public/containers/buffer.h*



**brief** Grabs some data from the buffer

**data**

**maxsize**

**return** Number of bytes written to the buffer

### peeks

*public BufferT::BufferSize peeks(CharT * data, BufferT::BufferSize sz)*

*Defined at line 205 of ./public/containers/buffer.h*



**brief** Reads a string from the buffer without changing the input ptr

**data**

**sz**

**return** Number of bytes written

### getc

*public int getc()*

*Defined at line 217 of ./public/containers/buffer.h*



**brief** Returns the next char from the buffer and increments the buffer pos

**return** next char from the buffer

### peek

*public int peek()*

*Defined at line 229 of ./public/containers/buffer.h*



**brief** Returns next char from buffer without incrementing it

**return** next char

### current_pos

*public BufferT::BufferPos current_pos()*

*Defined at line 238 of ./public/containers/buffer.h*



**brief** Get the current pos of the read/write head

**return**

### seek_start

*public BufferT::BufferPos seek_start()*

*Defined at line 247 of ./public/containers/buffer.h*



**brief** Seeks to the very start of the buffer

**return** Old buffer position

### seek_end

*public BufferT::BufferPos seek_end()*

*Defined at line 258 of ./public/containers/buffer.h*



**brief** Seeks to the very end of the buffer. Note: This seeks to the end of the allocated region

**return** Old buffer position

### seek_cur

*public BufferT::BufferPos seek_cur(int offset)*

*Defined at line 270 of ./public/containers/buffer.h*



**brief** Seeks to a relative position based on the current read/write head

**offset**

**return** New position of the buffer

### seek_absolute

*public BufferT::BufferPos seek_absolute(BufferT::BufferPos offset)*

*Defined at line 281 of ./public/containers/buffer.h*



**brief** Seeks to an absolute position in the buffer. Must be >= 0 &&< max_size

**offset**

**return** Old position in the buffer

### max_size

*public BufferT::BufferSize max_size()*

*Defined at line 292 of ./public/containers/buffer.h*



**return** Max allocated size of the buffer

### size

*public BufferT::BufferSize size()*

*Defined at line 300 of ./public/containers/buffer.h*



**return** Number of chars written to the buffer

### data

*public void * data()*

*Defined at line 308 of ./public/containers/buffer.h*



**return** Pointer to the data of the buffer

### clear

*public void clear()*

*Defined at line 316 of ./public/containers/buffer.h*



**brief** Zeroes out the internal buffer

### compact

*public void compact()*

*Defined at line 324 of ./public/containers/buffer.h*



**brief** Resizes the internal buffer so that it's  the same size as the data written to it

### empty

*public _Bool empty()*

*Defined at line 335 of ./public/containers/buffer.h*



**brief** Returns true if the buffer is empty

**return**

### will_overflow

*public _Bool will_overflow(BufferT::BufferSize num_bytes)*

*Defined at line 343 of ./public/containers/buffer.h*



**return** returns if the buffer will overflow if you write the specified number of bytes to it

### write_to_stream

*public BufferT::BufferSize write_to_stream(FILE * stream)*

*Defined at line 353 of ./public/containers/buffer.h*



**brief** Writes the current buffer to a stream

**stream**

**return**

### read_from_stream

*public BufferT::BufferSize read_from_stream(FILE * stream, BufferT::BufferSize num_bytes)*

*Defined at line 365 of ./public/containers/buffer.h*



**brief** Reads the buffer data from the stream

**stream**

**num_bytes**

**return**



