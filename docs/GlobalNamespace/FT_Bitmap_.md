# struct FT_Bitmap_

*Defined at line 261 of /usr/include/freetype2/freetype/ftimage.h*

************************************************************************



:

   FT_Bitmap

**<not a builtin command>** :   A structure used to describe a bitmap or pixmap to the raster.  Note   that we now manage pixmaps of various depths through the `pixel_mode`   field.

**<not a builtin command>** :   rows ::     The number of bitmap rows.

   width ::     The number of pixels in bitmap row.

   pitch ::     The pitch's absolute value is the number of bytes taken by one     bitmap row, including padding.  However, the pitch is positive when     the bitmap has a 'down' flow, and negative when it has an 'up' flow.     In all cases, the pitch is an offset to add to a bitmap pointer in     order to go down one row.

     Note that 'padding' means the alignment of a bitmap to a byte     border, and FreeType functions normally align to the smallest     possible integer value.

     For the B/W rasterizer, `pitch` is always an even number.

     To change the pitch of a bitmap (say, to make it a multiple of 4),     use **<not a builtin command>** _Bitmap_Convert.  Alternatively, you might use callback     functions to directly render to the application's surface; see the     file `example2.cpp` in the tutorial for a demonstration.

   buffer ::     A typeless pointer to the bitmap buffer.  This value should be     aligned on 32-bit boundaries in most cases.

   num_grays ::     This field is only used with **<not a builtin command>** _PIXEL_MODE_GRAY; it gives the     number of gray levels used in the bitmap.

   pixel_mode ::     The pixel mode, i.e., how pixel bits are stored.  See **<not a builtin command>** _Pixel_Mode     for possible values.

   palette_mode ::     This field is intended for paletted pixel modes; it indicates how     the palette is stored.  Not used currently.

   palette ::     A typeless pointer to the bitmap palette; this field is intended for     paletted pixel modes.  Not used currently.



## Members

public unsigned int rows

public unsigned int width

public int pitch

public unsigned char * buffer

public unsigned short num_grays

public unsigned char pixel_mode

public unsigned char palette_mode

public void * palette



