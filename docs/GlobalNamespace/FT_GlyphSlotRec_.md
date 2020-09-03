# struct FT_GlyphSlotRec_

*Defined at line 1884 of /usr/include/freetype2/freetype/freetype.h*

************************************************************************



:

   FT_GlyphSlotRec

**<not a builtin command>** :   FreeType root glyph slot class structure.  A glyph slot is a container   where individual glyphs can be loaded, be they in outline or bitmap   format.

**<not a builtin command>** :   library ::     A handle to the FreeType library instance this slot belongs to.

   face ::     A handle to the parent face object.

   next ::     In some cases (like some font tools), several glyph slots per face     object can be a good thing.  As this is rare, the glyph slots are     listed through a direct, single-linked list using its `next` field.

   glyph_index ::     [Since 2.10] The glyph index passed as an argument to **<not a builtin command>** _Load_Glyph     while initializing the glyph slot.

   generic ::     A typeless pointer unused by the FreeType library or any of its     drivers.  It can be used by client applications to link their own     data to each glyph slot object.

   metrics ::     The metrics of the last loaded glyph in the slot.  The returned     values depend on the last load flags (see the **<not a builtin command>** _Load_Glyph API     function) and can be expressed either in 26.6 fractional pixels or     font units.

     Note that even when the glyph image is transformed, the metrics are     not.

   linearHoriAdvance ::     The advance width of the unhinted glyph.  Its value is expressed in     16.16 fractional pixels, unless **<not a builtin command>** _LOAD_LINEAR_DESIGN is set when     loading the glyph.  This field can be important to perform correct     WYSIWYG layout.  Only relevant for outline glyphs.

   linearVertAdvance ::     The advance height of the unhinted glyph.  Its value is expressed in     16.16 fractional pixels, unless **<not a builtin command>** _LOAD_LINEAR_DESIGN is set when     loading the glyph.  This field can be important to perform correct     WYSIWYG layout.  Only relevant for outline glyphs.

   advance ::     This shorthand is, depending on **<not a builtin command>** _LOAD_IGNORE_TRANSFORM, the     transformed (hinted) advance width for the glyph, in 26.6 fractional     pixel format.  As specified with **<not a builtin command>** _LOAD_VERTICAL_LAYOUT, it uses     either the `horiAdvance` or the `vertAdvance` value of `metrics`     field.

   format ::     This field indicates the format of the image contained in the glyph     slot.  Typically **<not a builtin command>** _GLYPH_FORMAT_BITMAP, **<not a builtin command>** _GLYPH_FORMAT_OUTLINE,     or **<not a builtin command>** _GLYPH_FORMAT_COMPOSITE, but other values are possible.

   bitmap ::     This field is used as a bitmap descriptor.  Note that the address     and content of the bitmap buffer can change between calls of**<not a builtin command>** _Load_Glyph and a few other functions.

   bitmap_left ::     The bitmap's left bearing expressed in integer pixels.

   bitmap_top ::     The bitmap's top bearing expressed in integer pixels.  This is the     distance from the baseline to the top-most glyph scanline, upwards     y~coordinates being **positive**.

   outline ::     The outline descriptor for the current glyph image if its format is**<not a builtin command>** _GLYPH_FORMAT_OUTLINE.  Once a glyph is loaded, `outline` can be     transformed, distorted, emboldened, etc.  However, it must not be     freed.

     [Since 2.10.1] If **<not a builtin command>** _LOAD_NO_SCALE is set, outline coordinates of     OpenType variation fonts for a selected instance are internally     handled as 26.6 fractional font units but returned as (rounded)     integers, as expected.  To get unrounded font units, don't use**<not a builtin command>** _LOAD_NO_SCALE but load the glyph with **<not a builtin command>** _LOAD_NO_HINTING and     scale it, using the font's `units_per_EM` value as the ppem.

   num_subglyphs ::     The number of subglyphs in a composite glyph.  This field is only     valid for the composite glyph format that should normally only be     loaded with the **<not a builtin command>** _LOAD_NO_RECURSE flag.

   subglyphs ::     An array of subglyph descriptors for composite glyphs.  There are     `num_subglyphs` elements in there.  Currently internal to FreeType.

   control_data ::     Certain font drivers can also return the control data for a given     glyph image (e.g.  TrueType bytecode, Type~1 charstrings, etc.).     This field is a pointer to such data; it is currently internal to     FreeType.

   control_len ::     This is the length in bytes of the control data.  Currently internal     to FreeType.

   other ::     Reserved.

   lsb_delta ::     The difference between hinted and unhinted left side bearing while     auto-hinting is active.  Zero otherwise.

   rsb_delta ::     The difference between hinted and unhinted right side bearing while     auto-hinting is active.  Zero otherwise.



**note**:   If **<not a builtin command>** _Load_Glyph is called with default flags (see **<not a builtin command>** _LOAD_DEFAULT)   the glyph image is loaded in the glyph slot in its native format   (e.g., an outline glyph for TrueType and Type~1 formats).  [Since 2.9]   The prospective bitmap metrics are calculated according to**<not a builtin command>** _LOAD_TARGET_XXX and other flags even for the outline glyph, even   if **<not a builtin command>** _LOAD_RENDER is not set.

   This image can later be converted into a bitmap by calling**<not a builtin command>** _Render_Glyph.  This function searches the current renderer for the   native image's format, then invokes it.

   The renderer is in charge of transforming the native image through the   slot's face transformation fields, then converting it into a bitmap   that is returned in `slot->bitmap`.

   Note that `slot->bitmap_left` and `slot->bitmap_top` are also used to   specify the position of the bitmap relative to the current pen   position (e.g., coordinates (0,0) on the baseline).  Of course,   `slot->format` is also changed to **<not a builtin command>** _GLYPH_FORMAT_BITMAP.

   Here is a small pseudo code fragment that shows how to use `lsb_delta`   and `rsb_delta` to do fractional positioning of glyphs:

   ```     FT_GlyphSlot  slot     = face->glyph;     FT_Pos        origin_x = 0;

     for all glyphs do<load glyph with `FT_Load_Glyph'>

       FT_Outline_Translate( slot->outline, origin_x & 63, 0 );

<save glyph image, or render glyph, or ...>

<compute kern between current and next glyph        and add it to `origin_x'>

       origin_x += slot->advance.x;       origin_x += slot->lsb_delta - slot->rsb_delta;     endfor   ```

   Here is another small pseudo code fragment that shows how to use   `lsb_delta` and `rsb_delta` to improve integer positioning of glyphs:

   ```     FT_GlyphSlot  slot           = face->glyph;     FT_Pos        origin_x       = 0;     FT_Pos        prev_rsb_delta = 0;

     for all glyphs do<compute kern between current and previous glyph        and add it to `origin_x'>

<load glyph with `FT_Load_Glyph'>

       if ( prev_rsb_delta - slot->lsb_delta >  32 )         origin_x -= 64;       else if ( prev_rsb_delta - slot->lsb_delta < -31 )         origin_x += 64;

       prev_rsb_delta = slot->rsb_delta;

<save glyph image, or render glyph, or ...>

       origin_x += slot->advance.x;     endfor   ```

   If you use strong auto-hinting, you **must** apply these delta values!   Otherwise you will experience far too large inter-glyph spacing at   small rendering sizes in most cases.  Note that it doesn't harm to use   the above code for other hinting modes also, since the delta values   are zero then.



## Members

public FT_Library library

public FT_Face face

public FT_GlyphSlot next

public FT_UInt glyph_index

FT_Generic_ generic

FT_Glyph_Metrics_ metrics

public FT_Fixed linearHoriAdvance

public FT_Fixed linearVertAdvance

FT_Vector_ advance

public FT_Glyph_Format format

FT_Bitmap_ bitmap

public FT_Int bitmap_left

public FT_Int bitmap_top

FT_Outline_ outline

public FT_UInt num_subglyphs

public FT_SubGlyph subglyphs

public void * control_data

public long control_len

public FT_Pos lsb_delta

public FT_Pos rsb_delta

public void * other

public FT_Slot_Internal internal



