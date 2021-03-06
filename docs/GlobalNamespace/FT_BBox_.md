# struct FT_BBox_

*Defined at line 119 of /usr/include/freetype2/freetype/ftimage.h*

************************************************************************



:

   FT_BBox

**<not a builtin command>** :   A structure used to hold an outline's bounding box, i.e., the   coordinates of its extrema in the horizontal and vertical directions.

**<not a builtin command>** :   xMin ::     The horizontal minimum (left-most).

   yMin ::     The vertical minimum (bottom-most).

   xMax ::     The horizontal maximum (right-most).

   yMax ::     The vertical maximum (top-most).



**note**:   The bounding box is specified with the coordinates of the lower left   and the upper right corner.  In PostScript, those values are often   called (llx,lly) and (urx,ury), respectively.

   If `yMin` is negative, this value gives the glyph's descender.   Otherwise, the glyph doesn't descend below the baseline.  Similarly,   if `ymax` is positive, this value gives the glyph's ascender.

   `xMin` gives the horizontal distance from the glyph's origin to the   left edge of the glyph's bounding box.  If `xMin` is negative, the   glyph extends to the left of the origin.



## Members

public FT_Pos xMin

public FT_Pos yMin

public FT_Pos xMax

public FT_Pos yMax



