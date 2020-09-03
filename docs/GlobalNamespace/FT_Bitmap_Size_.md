# struct FT_Bitmap_Size_

*Defined at line 371 of /usr/include/freetype2/freetype/freetype.h*

************************************************************************



:

   FT_Bitmap_Size

**<not a builtin command>** :   This structure models the metrics of a bitmap strike (i.e., a set of   glyphs for a given point size and resolution) in a bitmap font.  It is   used for the `available_sizes` field of **<not a builtin command>** _Face.

**<not a builtin command>** :   height ::     The vertical distance, in pixels, between two consecutive baselines.     It is always positive.

   width ::     The average width, in pixels, of all glyphs in the strike.

   size ::     The nominal size of the strike in 26.6 fractional points.  This     field is not very useful.

   x_ppem ::     The horizontal ppem (nominal width) in 26.6 fractional pixels.

   y_ppem ::     The vertical ppem (nominal height) in 26.6 fractional pixels.



**note**:   Windows FNT:     The nominal size given in a FNT font is not reliable.  If the driver     finds it incorrect, it sets `size` to some calculated values, and     `x_ppem` and `y_ppem` to the pixel width and height given in the     font, respectively.

   TrueType embedded bitmaps:     `size`, `width`, and `height` values are not contained in the bitmap     strike itself.  They are computed from the global font parameters.



## Members

public FT_Short height

public FT_Short width

public FT_Pos size

public FT_Pos x_ppem

public FT_Pos y_ppem



