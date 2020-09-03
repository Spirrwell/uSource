# struct FT_Open_Args_

*Defined at line 2124 of /usr/include/freetype2/freetype/freetype.h*

************************************************************************



:

   FT_Open_Args

**<not a builtin command>** :   A structure to indicate how to open a new font file or stream.  A   pointer to such a structure can be used as a parameter for the   functions **<not a builtin command>** _Open_Face and **<not a builtin command>** _Attach_Stream.

**<not a builtin command>** :   flags ::     A set of bit flags indicating how to use the structure.

   memory_base ::     The first byte of the file in memory.

   memory_size ::     The size in bytes of the file in memory.

   pathname ::     A pointer to an 8-bit file pathname.  The pointer is not owned by     FreeType.

   stream ::     A handle to a source stream object.

   driver ::     This field is exclusively used by **<not a builtin command>** _Open_Face; it simply specifies     the font driver to use for opening the face.  If set to `NULL`,     FreeType tries to load the face with each one of the drivers in its     list.

   num_params ::     The number of extra parameters.

   params ::     Extra parameters passed to the font driver when opening a new face.



**note**:   The stream type is determined by the contents of `flags` that are   tested in the following order by **<not a builtin command>** _Open_Face:

   If the **<not a builtin command>** _OPEN_MEMORY bit is set, assume that this is a memory file   of `memory_size` bytes, located at `memory_address`.  The data are not   copied, and the client is responsible for releasing and destroying   them _after_ the corresponding call to **<not a builtin command>** _Done_Face.

   Otherwise, if the **<not a builtin command>** _OPEN_STREAM bit is set, assume that a custom   input stream `stream` is used.

   Otherwise, if the **<not a builtin command>** _OPEN_PATHNAME bit is set, assume that this is a   normal file and use `pathname` to open it.

   If the **<not a builtin command>** _OPEN_DRIVER bit is set, **<not a builtin command>** _Open_Face only tries to open   the file with the driver whose handler is in `driver`.

   If the **<not a builtin command>** _OPEN_PARAMS bit is set, the parameters given by   `num_params` and `params` is used.  They are ignored otherwise.

   Ideally, both the `pathname` and `params` fields should be tagged as   'const'; this is missing for API backward compatibility.  In other   words, applications should treat them as read-only.



## Members

public FT_UInt flags

public const FT_Byte * memory_base

public FT_Long memory_size

public FT_String * pathname

public FT_Stream stream

public FT_Module driver

public FT_Int num_params

public FT_Parameter * params



