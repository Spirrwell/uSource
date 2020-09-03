# struct FT_Outline_

*Defined at line 337 of /usr/include/freetype2/freetype/ftimage.h*

************************************************************************



:

   FT_Outline

**<not a builtin command>** :   This structure is used to describe an outline to the scan-line   converter.

**<not a builtin command>** :   n_contours ::     The number of contours in the outline.

   n_points ::     The number of points in the outline.

   points ::     A pointer to an array of `n_points` **<not a builtin command>** _Vector elements, giving the     outline's point coordinates.

   tags ::     A pointer to an array of `n_points` chars, giving each outline     point's type.

     If bit~0 is unset, the point is 'off' the curve, i.e., a Bezier     control point, while it is 'on' if set.

     Bit~1 is meaningful for 'off' points only.  If set, it indicates a     third-order Bezier arc control point; and a second-order control     point if unset.

     If bit~2 is set, bits 5-7 contain the drop-out mode (as defined in     the OpenType specification; the value is the same as the argument to     the 'SCANMODE' instruction).

     Bits 3 and~4 are reserved for internal purposes.

   contours ::     An array of `n_contours` shorts, giving the end point of each     contour within the outline.  For example, the first contour is     defined by the points '0' to `contours[0]`, the second one is     defined by the points `contours[0]+1` to `contours[1]`, etc.

   flags ::     A set of bit flags used to characterize the outline and give hints     to the scan-converter and hinter on how to convert/grid-fit it.  See**<not a builtin command>** _OUTLINE_XXX.



**note**:   The B/W rasterizer only checks bit~2 in the `tags` array for the first   point of each contour.  The drop-out mode as given with**<not a builtin command>** _OUTLINE_IGNORE_DROPOUTS, **<not a builtin command>** _OUTLINE_SMART_DROPOUTS, and**<not a builtin command>** _OUTLINE_INCLUDE_STUBS in `flags` is then overridden.



## Members

public short n_contours

public short n_points

public FT_Vector * points

public char * tags

public short * contours

public int flags



