# struct FT_StreamRec_

*Defined at line 328 of /usr/include/freetype2/freetype/ftsystem.h*

************************************************************************



:

   FT_StreamRec

**<not a builtin command>** :   A structure used to describe an input stream.

**<not a builtin command>** :   base ::     For memory-based streams, this is the address of the first stream     byte in memory.  This field should always be set to `NULL` for     disk-based streams.

   size ::     The stream size in bytes.

     In case of compressed streams where the size is unknown before     actually doing the decompression, the value is set to 0x7FFFFFFF.     (Note that this size value can occur for normal streams also; it is     thus just a hint.)

   pos ::     The current position within the stream.

   descriptor ::     This field is a union that can hold an integer or a pointer.  It is     used by stream implementations to store file descriptors or `FILE*`     pointers.

   pathname ::     This field is completely ignored by FreeType.  However, it is often     useful during debugging to use it to store the stream's filename     (where available).

   read ::     The stream's input function.

   close ::     The stream's close function.

   memory ::     The memory manager to use to preload frames.  This is set internally     by FreeType and shouldn't be touched by stream implementations.

   cursor ::     This field is set and used internally by FreeType when parsing     frames.  In particular, the `FT_GET_XXX` macros use this instead of     the `pos` field.

   limit ::     This field is set and used internally by FreeType when parsing     frames.





## Members

public unsigned char * base

public unsigned long size

public unsigned long pos

FT_StreamDesc_ descriptor

FT_StreamDesc_ pathname

public FT_Stream_IoFunc read

public FT_Stream_CloseFunc close

public FT_Memory memory

public unsigned char * cursor

public unsigned char * limit



