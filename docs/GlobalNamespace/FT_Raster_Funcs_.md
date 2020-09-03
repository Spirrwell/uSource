# struct FT_Raster_Funcs_

*Defined at line 1213 of /usr/include/freetype2/freetype/ftimage.h*

************************************************************************



:

   FT_Raster_Funcs

**<not a builtin command>** :  A structure used to describe a given raster class to the library.

**<not a builtin command>** :   glyph_format ::     The supported glyph format for this raster.

   raster_new ::     The raster constructor.

   raster_reset ::     Used to reset the render pool within the raster.

   raster_render ::     A function to render a glyph into a given bitmap.

   raster_done ::     The raster destructor.



## Members

public FT_Glyph_Format glyph_format

public FT_Raster_NewFunc raster_new

public FT_Raster_ResetFunc raster_reset

public FT_Raster_SetModeFunc raster_set_mode

public FT_Raster_RenderFunc raster_render

public FT_Raster_DoneFunc raster_done



