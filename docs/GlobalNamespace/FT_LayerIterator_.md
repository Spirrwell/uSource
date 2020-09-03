# struct FT_LayerIterator_

*Defined at line 4070 of /usr/include/freetype2/freetype/freetype.h*

************************************************************************



:

   FT_LayerIterator

**<not a builtin command>** :   This iterator object is needed for **<not a builtin command>** _Get_Color_Glyph_Layer.

**<not a builtin command>** :   num_layers ::     The number of glyph layers for the requested glyph index.  Will be     set by **<not a builtin command>** _Get_Color_Glyph_Layer.

   layer ::     The current layer.  Will be set by **<not a builtin command>** _Get_Color_Glyph_Layer.

   p ::     An opaque pointer into 'COLR' table data.  The caller must set this     to `NULL` before the first call of **<not a builtin command>** _Get_Color_Glyph_Layer.



## Members

public FT_UInt num_layers

public FT_UInt layer

public FT_Byte * p



