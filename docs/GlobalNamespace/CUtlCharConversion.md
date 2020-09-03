# class CUtlCharConversion

*Defined at line 30 of ./mainui/miniutl/utlbuffer.h*

----------------------------------------------------------------------------- Description of character conversions for string output Here's an example of how to use the macros to define a character conversion BEGIN_CHAR_CONVERSION( CStringConversion, '\' )	{ '**<not a builtin command>** ', "n" },	{ '**<not a builtin command>** ', "t" } END_CHAR_CONVERSION( CStringConversion, '\' )-----------------------------------------------------------------------------



## Members

protected char m_nEscapeChar

protected const char * m_pDelimiter

protected int m_nDelimiterLength

protected int m_nCount

protected int m_nMaxConversionLength

protected char [255] m_pList

protected struct CUtlCharConversion::ConversionInfo_t [255] m_pReplacements



## Records

ConversionArray_t

ConversionInfo_t



## Functions

### CUtlCharConversion

*public void CUtlCharConversion(const char nEscapeChar, const char * pDelimiter, int nCount, struct CUtlCharConversion::ConversionArray_t * pArray)*

### GetEscapeChar

*public char GetEscapeChar()*

*Defined at line 138 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Escape character + delimiter-----------------------------------------------------------------------------

### GetDelimiter

*public const char * GetDelimiter()*

*Defined at line 143 of ./mainui/miniutl/utlbuffer.cpp*

### GetDelimiterLength

*public int GetDelimiterLength()*

*Defined at line 148 of ./mainui/miniutl/utlbuffer.cpp*

### GetConversionString

*public const char * GetConversionString(char c)*

*Defined at line 157 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Constructor-----------------------------------------------------------------------------

### GetConversionLength

*public int GetConversionLength(char c)*

*Defined at line 162 of ./mainui/miniutl/utlbuffer.cpp*

### MaxConversionLength

*public int MaxConversionLength()*

*Defined at line 167 of ./mainui/miniutl/utlbuffer.cpp*

### FindConversion

*public char FindConversion(const char * pString, int * pLength)*

*Defined at line 176 of ./mainui/miniutl/utlbuffer.cpp*

 Finds a conversion for the passed-in string, returns length

----------------------------------------------------------------------------- Finds a conversion for the passed-in string, returns length-----------------------------------------------------------------------------

### CUtlCharConversion

*public void CUtlCharConversion(char nEscapeChar, const char * pDelimiter, int nCount, struct CUtlCharConversion::ConversionArray_t * pArray)*

*Defined at line 110 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Constructor-----------------------------------------------------------------------------



