# struct FT_MemoryRec_

*Defined at line 170 of /usr/include/freetype2/freetype/ftsystem.h*

************************************************************************



:

   FT_MemoryRec

**<not a builtin command>** :   A structure used to describe a given memory manager to FreeType~2.

**<not a builtin command>** :   user ::     A generic typeless pointer for user data.

   alloc ::     A pointer type to an allocation function.

   free ::     A pointer type to an memory freeing function.

   realloc ::     A pointer type to a reallocation function.





## Members

public void * user

public FT_Alloc_Func alloc

public FT_Free_Func free

public FT_Realloc_Func realloc



