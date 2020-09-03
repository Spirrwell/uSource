# struct FT_Span_

*Defined at line 851 of /usr/include/freetype2/freetype/ftimage.h*

************************************************************************



:

   FT_Span

**<not a builtin command>** :   A structure used to model a single span of gray pixels when rendering   an anti-aliased bitmap.

**<not a builtin command>** :   x ::     The span's horizontal start position.

   len ::     The span's length in pixels.

   coverage ::     The span color/coverage, ranging from 0 (background) to 255     (foreground).



**note**:   This structure is used by the span drawing callback type named**<not a builtin command>** _SpanFunc that takes the y~coordinate of the span as a parameter.

   The coverage value is always between 0 and 255.  If you want less gray   values, the callback function has to reduce them.



## Members

public short x

public unsigned short len

public unsigned char coverage



