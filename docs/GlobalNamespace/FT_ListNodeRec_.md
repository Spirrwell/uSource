# struct FT_ListNodeRec_

*Defined at line 555 of /usr/include/freetype2/freetype/fttypes.h*

************************************************************************



:

   FT_ListNodeRec

**<not a builtin command>** :   A structure used to hold a single list element.

**<not a builtin command>** :   prev ::     The previous element in the list.  `NULL` if first.

   next ::     The next element in the list.  `NULL` if last.

   data ::     A typeless pointer to the listed object.



## Members

public FT_ListNode prev

public FT_ListNode next

public void * data



