# struct FT_Matrix_

*Defined at line 390 of /usr/include/freetype2/freetype/fttypes.h*

************************************************************************



:

   FT_Matrix

**<not a builtin command>** :   A simple structure used to store a 2x2 matrix.  Coefficients are in   16.16 fixed-point format.  The computation performed is:

   ```     x' = x*xx + y*xy     y' = x*yx + y*yy   ```

**<not a builtin command>** :   xx ::     Matrix coefficient.

   xy ::     Matrix coefficient.

   yx ::     Matrix coefficient.

   yy ::     Matrix coefficient.



## Members

public FT_Fixed xx

public FT_Fixed xy

public FT_Fixed yx

public FT_Fixed yy



