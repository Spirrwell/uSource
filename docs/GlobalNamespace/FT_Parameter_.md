# struct FT_Parameter_

*Defined at line 2052 of /usr/include/freetype2/freetype/freetype.h*

************************************************************************



:

   FT_Parameter

**<not a builtin command>** :   A simple structure to pass more or less generic parameters to**<not a builtin command>** _Open_Face and **<not a builtin command>** _Face_Properties.

**<not a builtin command>** :   tag ::     A four-byte identification tag.

   data ::     A pointer to the parameter data.



**note**:   The ID and function of parameters are driver-specific.  See section**<not a builtin command>** _tags for more information.



## Members

public FT_ULong tag

public FT_Pointer data



