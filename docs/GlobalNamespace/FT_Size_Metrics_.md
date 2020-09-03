# struct FT_Size_Metrics_

*Defined at line 1608 of /usr/include/freetype2/freetype/freetype.h*

************************************************************************



:

   FT_Size_Metrics

**<not a builtin command>** :   The size metrics structure gives the metrics of a size object.

**<not a builtin command>** :   x_ppem ::     The width of the scaled EM square in pixels, hence the term 'ppem'     (pixels per EM).  It is also referred to as 'nominal width'.

   y_ppem ::     The height of the scaled EM square in pixels, hence the term 'ppem'     (pixels per EM).  It is also referred to as 'nominal height'.

   x_scale ::     A 16.16 fractional scaling value to convert horizontal metrics from     font units to 26.6 fractional pixels.  Only relevant for scalable     font formats.

   y_scale ::     A 16.16 fractional scaling value to convert vertical metrics from     font units to 26.6 fractional pixels.  Only relevant for scalable     font formats.

   ascender ::     The ascender in 26.6 fractional pixels, rounded up to an integer     value.  See **<not a builtin command>** _FaceRec for the details.

   descender ::     The descender in 26.6 fractional pixels, rounded down to an integer     value.  See **<not a builtin command>** _FaceRec for the details.

   height ::     The height in 26.6 fractional pixels, rounded to an integer value.     See **<not a builtin command>** _FaceRec for the details.

   max_advance ::     The maximum advance width in 26.6 fractional pixels, rounded to an     integer value.  See **<not a builtin command>** _FaceRec for the details.



**note**:   The scaling values, if relevant, are determined first during a size   changing operation.  The remaining fields are then set by the driver.   For scalable formats, they are usually set to scaled values of the   corresponding fields in **<not a builtin command>** _FaceRec.  Some values like ascender or   descender are rounded for historical reasons; more precise values (for   outline fonts) can be derived by scaling the corresponding **<not a builtin command>** _FaceRec   values manually, with code similar to the following.

   ```     scaled_ascender = FT_MulFix( face->ascender,                                  size_metrics->y_scale );   ```

   Note that due to glyph hinting and the selected rendering mode these   values are usually not exact; consequently, they must be treated as   unreliable with an error margin of at least one pixel!

   Indeed, the only way to get the exact metrics is to render _all_   glyphs.  As this would be a definite performance hit, it is up to   client applications to perform such computations.

   The `FT_Size_Metrics` structure is valid for bitmap fonts also.

   **TrueType fonts with native bytecode hinting**

   All applications that handle TrueType fonts with native hinting must   be aware that TTFs expect different rounding of vertical font   dimensions.  The application has to cater for this, especially if it   wants to rely on a TTF's vertical data (for example, to properly align   box characters vertically).

   Only the application knows _in advance_ that it is going to use native   hinting for TTFs!  FreeType, on the other hand, selects the hinting   mode not at the time of creating an **<not a builtin command>** _Size object but much later,   namely while calling **<not a builtin command>** _Load_Glyph.

   Here is some pseudo code that illustrates a possible solution.

   ```     font_format = FT_Get_Font_Format( face );

     if ( !strcmp( font_format, "TrueType" ) &&          do_native_bytecode_hinting         )     {       ascender  = ROUND( FT_MulFix( face->ascender,                                     size_metrics->y_scale ) );       descender = ROUND( FT_MulFix( face->descender,                                     size_metrics->y_scale ) );     }     else     {       ascender  = size_metrics->ascender;       descender = size_metrics->descender;     }

     height      = size_metrics->height;     max_advance = size_metrics->max_advance;   ```



## Members

public FT_UShort x_ppem

public FT_UShort y_ppem

public FT_Fixed x_scale

public FT_Fixed y_scale

public FT_Pos ascender

public FT_Pos descender

public FT_Pos height

public FT_Pos max_advance



