# struct FT_Size_RequestRec_

*Defined at line 2615 of /usr/include/freetype2/freetype/freetype.h*

************************************************************************



:

   FT_Size_RequestRec

**<not a builtin command>** :   A structure to model a size request.

**<not a builtin command>** :   type ::     See **<not a builtin command>** _Size_Request_Type.

   width ::     The desired width, given as a 26.6 fractional point value (with 72pt     = 1in).

   height ::     The desired height, given as a 26.6 fractional point value (with     72pt = 1in).

   horiResolution ::     The horizontal resolution (dpi, i.e., pixels per inch).  If set to     zero, `width` is treated as a 26.6 fractional **pixel** value, which     gets internally rounded to an integer.

   vertResolution ::     The vertical resolution (dpi, i.e., pixels per inch).  If set to     zero, `height` is treated as a 26.6 fractional **pixel** value,     which gets internally rounded to an integer.



**note**:   If `width` is zero, the horizontal scaling value is set equal to the   vertical scaling value, and vice versa.

   If `type` is `FT_SIZE_REQUEST_TYPE_SCALES`, `width` and `height` are   interpreted directly as 16.16 fractional scaling values, without any   further modification, and both `horiResolution` and `vertResolution`   are ignored.



## Members

public FT_Size_Request_Type type

public FT_Long width

public FT_Long height

public FT_UInt horiResolution

public FT_UInt vertResolution



