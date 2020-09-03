# struct FT_SizeRec_

*Defined at line 1645 of /usr/include/freetype2/freetype/freetype.h*

************************************************************************



:

   FT_SizeRec

**<not a builtin command>** :   FreeType root size class structure.  A size object models a face   object at a given size.

**<not a builtin command>** :   face ::     Handle to the parent face object.

   generic ::     A typeless pointer, unused by the FreeType library or any of its     drivers.  It can be used by client applications to link their own     data to each size object.

   metrics ::     Metrics for this size object.  This field is read-only.



## Members

public FT_Face face

FT_Generic_ generic

FT_Size_Metrics_ metrics

public FT_Size_Internal internal



