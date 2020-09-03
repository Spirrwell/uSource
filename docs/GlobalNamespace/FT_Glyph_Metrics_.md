# struct FT_Glyph_Metrics_

*Defined at line 316 of /usr/include/freetype2/freetype/freetype.h*

************************************************************************



:

   FT_Glyph_Metrics

**<not a builtin command>** :   A structure to model the metrics of a single glyph.  The values are   expressed in 26.6 fractional pixel format; if the flag**<not a builtin command>** _LOAD_NO_SCALE has been used while loading the glyph, values are   expressed in font units instead.

**<not a builtin command>** :   width ::     The glyph's width.

   height ::     The glyph's height.

   horiBearingX ::     Left side bearing for horizontal layout.

   horiBearingY ::     Top side bearing for horizontal layout.

   horiAdvance ::     Advance width for horizontal layout.

   vertBearingX ::     Left side bearing for vertical layout.

   vertBearingY ::     Top side bearing for vertical layout.  Larger positive values mean     further below the vertical glyph origin.

   vertAdvance ::     Advance height for vertical layout.  Positive values mean the glyph     has a positive advance downward.



**note**:   If not disabled with **<not a builtin command>** _LOAD_NO_HINTING, the values represent   dimensions of the hinted glyph (in case hinting is applicable).

   Stroking a glyph with an outside border does not increase   `horiAdvance` or `vertAdvance`; you have to manually adjust these   values to account for the added width and height.

   FreeType doesn't use the 'VORG' table data for CFF fonts because it   doesn't have an interface to quickly retrieve the glyph height.  The   y~coordinate of the vertical origin can be simply computed as   `vertBearingY + height` after loading a glyph.



## Members

public FT_Pos width

public FT_Pos height

public FT_Pos horiBearingX

public FT_Pos horiBearingY

public FT_Pos horiAdvance

public FT_Pos vertBearingX

public FT_Pos vertBearingY

public FT_Pos vertAdvance



