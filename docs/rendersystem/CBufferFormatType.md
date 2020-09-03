# class CBufferFormatType

*Defined at line 63 of ./rendersystem/ibuffer.h*

Buffer formats allow you to specify a format for an aribtrary buffer type. They can be used in conjunction with a buffer view in order to access the buffer in a variety of different ways

 Usage:

 CBufferFormat Format(        CBufferFormatType(BITS(sizeof(int), "Index"),        CBufferFormatType(BITS(sizeof(vec3_t)), "Position"),        CBufferFormatType(BITS(sizeof(vec3_t)), "Normal"),        CBufferFormatType(BITS(sizeof(vec3_t)), "Tangent"))





## Members

private int m_bits

private const char * m_name



## Functions

### CBufferFormatType

*public void CBufferFormatType(int size_in_bits, const char * name)*

*Defined at line 72 of ./rendersystem/ibuffer.h*



