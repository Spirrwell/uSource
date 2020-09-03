# struct FT_Generic_

*Defined at line 467 of /usr/include/freetype2/freetype/fttypes.h*

************************************************************************



:

   FT_Generic

**<not a builtin command>** :   Client applications often need to associate their own data to a   variety of FreeType core objects.  For example, a text layout API   might want to associate a glyph cache to a given size object.

   Some FreeType object contains a `generic` field, of type `FT_Generic`,   which usage is left to client applications and font servers.

   It can be used to store a pointer to client-specific data, as well as   the address of a 'finalizer' function, which will be called by   FreeType when the object is destroyed (for example, the previous   client example would put the address of the glyph cache destructor in   the `finalizer` field).

**<not a builtin command>** :   data ::     A typeless pointer to any client-specified data. This field is     completely ignored by the FreeType library.

   finalizer ::     A pointer to a 'generic finalizer' function, which will be called     when the object is destroyed.  If this field is set to `NULL`, no     code will be called.



## Members

public void * data

public FT_Generic_Finalizer finalizer



