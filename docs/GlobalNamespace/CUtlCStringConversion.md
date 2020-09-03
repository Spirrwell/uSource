# class CUtlCStringConversion

*Defined at line 25 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Character conversions for C strings-----------------------------------------------------------------------------



Inherits from CUtlCharConversion



## Members

private char [256] m_pConversion



## Functions

### CUtlCStringConversion

*public void CUtlCStringConversion(const char nEscapeChar, const char * pDelimiter, int nCount, struct CUtlCharConversion::ConversionArray_t * pArray)*

*Defined at line 87 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Constructor-----------------------------------------------------------------------------

### FindConversion

*public char FindConversion(const char * pString, int * pLength)*

*Defined at line 98 of ./mainui/miniutl/utlbuffer.cpp*

 Finds a conversion for the passed-in string, returns length



