# struct FT_Raster_Params_

*Defined at line 1022 of /usr/include/freetype2/freetype/ftimage.h*

************************************************************************



:

   FT_Raster_Params

**<not a builtin command>** :   A structure to hold the parameters used by a raster's render function,   passed as an argument to **<not a builtin command>** _Outline_Render.

**<not a builtin command>** :   target ::     The target bitmap.

   source ::     A pointer to the source glyph image (e.g., an **<not a builtin command>** _Outline).

   flags ::     The rendering flags.

   gray_spans ::     The gray span drawing callback.

   black_spans ::     Unused.

   bit_test ::     Unused.

   bit_set ::     Unused.

   user ::     User-supplied data that is passed to each drawing callback.

   clip_box ::     An optional clipping box.  It is only used in direct rendering mode.     Note that coordinates here should be expressed in _integer_ pixels     (and not in 26.6 fixed-point units).



**note**:   An anti-aliased glyph bitmap is drawn if the **<not a builtin command>** _RASTER_FLAG_AA bit   flag is set in the `flags` field, otherwise a monochrome bitmap is   generated.

   If the **<not a builtin command>** _RASTER_FLAG_DIRECT bit flag is set in `flags`, the raster   will call the `gray_spans` callback to draw gray pixel spans.  This   allows direct composition over a pre-existing bitmap through   user-provided callbacks to perform the span drawing and composition.   Not supported by the monochrome rasterizer.



## Members

public const FT_Bitmap * target

public const void * source

public int flags

public FT_SpanFunc gray_spans

public FT_SpanFunc black_spans

public FT_Raster_BitTest_Func bit_test

public FT_Raster_BitSet_Func bit_set

public void * user

FT_BBox_ clip_box



