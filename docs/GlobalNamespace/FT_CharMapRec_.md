# struct FT_CharMapRec_

*Defined at line 833 of /usr/include/freetype2/freetype/freetype.h*

************************************************************************



:

   FT_CharMapRec

**<not a builtin command>** :   The base charmap structure.

**<not a builtin command>** :   face ::     A handle to the parent face object.

   encoding ::     An **<not a builtin command>** _Encoding tag identifying the charmap.  Use this with**<not a builtin command>** _Select_Charmap.

   platform_id ::     An ID number describing the platform for the following encoding ID.     This comes directly from the TrueType specification and gets     emulated for other formats.

   encoding_id ::     A platform-specific encoding number.  This also comes from the     TrueType specification and gets emulated similarly.



## Members

public FT_Face face

public FT_Encoding encoding

public FT_UShort platform_id

public FT_UShort encoding_id



