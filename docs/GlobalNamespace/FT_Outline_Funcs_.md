# struct FT_Outline_Funcs_

*Defined at line 651 of /usr/include/freetype2/freetype/ftimage.h*

************************************************************************



:

   FT_Outline_Funcs

**<not a builtin command>** :   A structure to hold various function pointers used during outline   decomposition in order to emit segments, conic, and cubic Beziers.

**<not a builtin command>** :   move_to ::     The 'move to' emitter.

   line_to ::     The segment emitter.

   conic_to ::     The second-order Bezier arc emitter.

   cubic_to ::     The third-order Bezier arc emitter.

   shift ::     The shift that is applied to coordinates before they are sent to the     emitter.

   delta ::     The delta that is applied to coordinates before they are sent to the     emitter, but after the shift.



**note**:   The point coordinates sent to the emitters are the transformed version   of the original coordinates (this is important for high accuracy   during scan-conversion).  The transformation is simple:

   ```     x' = (x << shift) - delta     y' = (y << shift) - delta   ```

   Set the values of `shift` and `delta` to~0 to get the original point   coordinates.



## Members

public FT_Outline_MoveToFunc move_to

public FT_Outline_LineToFunc line_to

public FT_Outline_ConicToFunc conic_to

public FT_Outline_CubicToFunc cubic_to

public int shift

public FT_Pos delta



