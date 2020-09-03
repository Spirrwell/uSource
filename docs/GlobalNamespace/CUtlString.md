# class CUtlString

*Defined at line 33 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: simple wrapper class around a char *			relies on the small-block heap existing for efficient memory allocation			as compact as possible, no virtuals or extraneous data			to be used primarily to replace of char array buffers			tries to match CUtlSymbol interface wherever possible-----------------------------------------------------------------------------



## Members

private char * m_pchString



## Functions

### CUtlString

*public void CUtlString()*

*Defined at line 166 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: constructor-----------------------------------------------------------------------------

### CUtlString

*public void CUtlString(const char * pchString)*

*Defined at line 193 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: constructor-----------------------------------------------------------------------------

### CUtlString

*public void CUtlString(const class CUtlString & string)*

*Defined at line 202 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: constructor-----------------------------------------------------------------------------

### CUtlString

*public void CUtlString(size_t nPreallocateBytes)*

*Defined at line 174 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: constructor-----------------------------------------------------------------------------

### ~CUtlString

*public void ~CUtlString()*

*Defined at line 211 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: destructor-----------------------------------------------------------------------------

### operator=

*public class CUtlString & operator=(const class CUtlString & src)*

*Defined at line 242 of ./mainui/miniutl/utlstring.h*

 operator=

----------------------------------------------------------------------------- Purpose: assignment-----------------------------------------------------------------------------

### operator=

*public class CUtlString & operator=(const char * pchString)*

*Defined at line 232 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: assignment-----------------------------------------------------------------------------

### operator==

*public _Bool operator==(const class CUtlString & src)*

*Defined at line 252 of ./mainui/miniutl/utlstring.h*

 operator==

----------------------------------------------------------------------------- Purpose: comparison-----------------------------------------------------------------------------

### operator==

*public _Bool operator==(const char * pchString)*

*Defined at line 261 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: comparison-----------------------------------------------------------------------------

### operator!=

*public _Bool operator!=(const class CUtlString & src)*

*Defined at line 269 of ./mainui/miniutl/utlstring.h*

 operator!=

----------------------------------------------------------------------------- Purpose: comparison-----------------------------------------------------------------------------

### operator!=

*public _Bool operator!=(const char * pchString)*

*Defined at line 278 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: comparison-----------------------------------------------------------------------------

### operator<

*public _Bool operator<(const class CUtlString & val)*

*Defined at line 287 of ./mainui/miniutl/utlstring.h*

 operator </>, performs case sensitive comparison

----------------------------------------------------------------------------- Purpose: comparison-----------------------------------------------------------------------------

### operator<

*public _Bool operator<(const char * pchString)*

*Defined at line 296 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: comparison-----------------------------------------------------------------------------

### operator>

*public _Bool operator>(const class CUtlString & val)*

*Defined at line 304 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: comparison-----------------------------------------------------------------------------

### operator>

*public _Bool operator>(const char * pchString)*

*Defined at line 313 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: comparison-----------------------------------------------------------------------------

### operator+=

*public class CUtlString & operator+=(const char * rhs)*

*Defined at line 321 of ./mainui/miniutl/utlstring.h*

 operator+=

----------------------------------------------------------------------------- Return a string with this string and rhs joined together.

### IsValid

*public _Bool IsValid()*

*Defined at line 331 of ./mainui/miniutl/utlstring.h*

 is valid?

----------------------------------------------------------------------------- Purpose: returns true if the string is not null-----------------------------------------------------------------------------

### String

*public const char * String()*

*Defined at line 340 of ./mainui/miniutl/utlstring.h*

 gets the string never returns NULL, use IsValid() to see if it's never been set

----------------------------------------------------------------------------- Purpose: data accessor-----------------------------------------------------------------------------

### Get

*public const char * Get()*

*Defined at line 69 of ./mainui/miniutl/utlstring.h*

### operator const char *

*public const char * operator const char *()*

*Defined at line 70 of ./mainui/miniutl/utlstring.h*

### Access

*public char * Access()*

*Defined at line 74 of ./mainui/miniutl/utlstring.h*

 returns the string directly (could be NULL) useful for doing inline operations on the string

### DetachRawPtr

*public char * DetachRawPtr()*

*Defined at line 77 of ./mainui/miniutl/utlstring.h*

 If you want to take ownership of the ptr, you can use this.

### Append

*public void Append(const char * pchAddition)*

*Defined at line 492 of ./mainui/miniutl/utlstring.h*

 append in-place, causing a re-allocation

----------------------------------------------------------------------------- Purpose: concatenate the provided string to our current content-----------------------------------------------------------------------------

### Append

*public void Append(const char * pchAddition, size_t cbLen)*

*Defined at line 506 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: concatenate the provided string to our current content			when the additional string length is known-----------------------------------------------------------------------------

### AppendChar

*public void AppendChar(char ch)*

*Defined at line 84 of ./mainui/miniutl/utlstring.h*

 append in-place for a single or repeated run of characters

### AppendRepeat

*public void AppendRepeat(char ch, int cCount)*

*Defined at line 533 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: repeat the passed character a specified number of times and			concatenate those characters to our existing content-----------------------------------------------------------------------------

### SetValue

*public void SetValue(const char * pchString)*

*Defined at line 349 of ./mainui/miniutl/utlstring.h*

 sets the string

----------------------------------------------------------------------------- Purpose: Sets the string to be the new value, taking a copy of it-----------------------------------------------------------------------------

### Set

*public void Set(const char * pchString)*

*Defined at line 440 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: Sets the string to be the new value, taking a copy of it-----------------------------------------------------------------------------

### Clear

*public void Clear()*

*Defined at line 90 of ./mainui/miniutl/utlstring.h*

### SetPtr

*public void SetPtr(char * pchString)*

*Defined at line 449 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: Sets the string to be the new value, taking ownership of the pointer-----------------------------------------------------------------------------

### Swap

*public void Swap(class CUtlString & src)*

*Defined at line 566 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: Swaps string contents-----------------------------------------------------------------------------

### ToLower

*public void ToLower()*

*Defined at line 374 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: Converts the string to lower case in-place. Not necessarily clean          about all possibly localization issues.-----------------------------------------------------------------------------

### ToUpper

*public void ToUpper()*

*Defined at line 390 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: Converts the string to upper case in-place. Not necessarily clean          about all possibly localization issues.-----------------------------------------------------------------------------

### Wipe

*public void Wipe()*

*Defined at line 405 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: Clear the string from memory, then free it.-----------------------------------------------------------------------------

### SetDirect

*public void SetDirect(const char * pValue, size_t nChars)*

*Defined at line 421 of ./mainui/miniutl/utlstring.h*

 Set directly and don't look for a null terminator in pValue.

----------------------------------------------------------------------------- Purpose: Set directly and don't look for a null terminator in pValue.-----------------------------------------------------------------------------

### Length

*public uint32 Length()*

*Defined at line 456 of ./mainui/miniutl/utlstring.h*

 Get the length of the string in characters.

### IsEmpty

*public _Bool IsEmpty()*

*Defined at line 220 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: ask if the string has anything in it-----------------------------------------------------------------------------

### Format

*public size_t Format(const char * pFormat)*

*Defined at line 468 of ./mainui/miniutl/utlstring.h*

 Format like sprintf.

----------------------------------------------------------------------------- Purpose: format something sprintf() style, and take it as the new value of this CUtlString-----------------------------------------------------------------------------

### AppendFormat

*public size_t AppendFormat(const char * pFormat)*

*Defined at line 480 of ./mainui/miniutl/utlstring.h*

 format, then append what we crated in the format

----------------------------------------------------------------------------- format a string and append the result to the string we hold-----------------------------------------------------------------------------

### AppendHex

*public void AppendHex(const uint8 * pbInput, size_t cubInput, _Bool bLowercase)*

*Defined at line 420 of ./mainui/miniutl/utlstring.cpp*

 convert bytes to hex string and append

----------------------------------------------------------------------------- Purpose: format binary data as hex characters, appending to existing data-----------------------------------------------------------------------------

### Replace

*public size_t Replace(char chTarget, char chReplacement)*

*Defined at line 577 of ./mainui/miniutl/utlstring.h*

 replace a single character with another, returns hit count

----------------------------------------------------------------------------- Purpose: replace all occurrences of one character with another-----------------------------------------------------------------------------

### Replace

*public size_t Replace(const char * pstrTarget, const char * pstrReplacement)*

*Defined at line 216 of ./mainui/miniutl/utlstring.cpp*

 replace a string with another string, returns hit count replacement string might be NULL or "" to remove target substring

----------------------------------------------------------------------------- Purpose: replace all occurrences of one string with another			replacement string may be NULL or "" to remove target string-----------------------------------------------------------------------------

### ReplaceCaseless

*public size_t ReplaceCaseless(const char * pstrTarget, const char * pstrReplacement)*

*Defined at line 227 of ./mainui/miniutl/utlstring.cpp*

----------------------------------------------------------------------------- Purpose: replace all occurrences of one string with another			replacement string may be NULL or "" to remove target string-----------------------------------------------------------------------------

### IndexOf

*public ptrdiff_t IndexOf(const char * pstrTarget)*

*Defined at line 318 of ./mainui/miniutl/utlstring.cpp*

----------------------------------------------------------------------------- Purpose: Indicates if the target string exists in this instance.			The index is negative if the target string is not found, otherwise it is the index in the string.-----------------------------------------------------------------------------

### BEndsWith

*public _Bool BEndsWith(const char * pchString)*

*Defined at line 327 of ./mainui/miniutl/utlstring.cpp*

----------------------------------------------------------------------------- Purpose: returns true if the string ends with the string passed in-----------------------------------------------------------------------------

### BEndsWithCaseless

*public _Bool BEndsWithCaseless(const char * pchString)*

*Defined at line 336 of ./mainui/miniutl/utlstring.cpp*

----------------------------------------------------------------------------- Purpose: returns true if the string ends with the string passed in (caseless)-----------------------------------------------------------------------------

### BStartsWith

*public _Bool BStartsWith(const char * pchString)*

*Defined at line 345 of ./mainui/miniutl/utlstring.cpp*

----------------------------------------------------------------------------- Purpose: returns true if the string starts with the string passed in-----------------------------------------------------------------------------

### BStartsWithCaseless

*public _Bool BStartsWithCaseless(const char * pchString)*

*Defined at line 354 of ./mainui/miniutl/utlstring.cpp*

----------------------------------------------------------------------------- Purpose: returns true if the string ends with the string passed in (caseless)-----------------------------------------------------------------------------

### RemoveWhitespace

*public size_t RemoveWhitespace()*

*Defined at line 364 of ./mainui/miniutl/utlstring.cpp*

 remove whitespace from the string; anything that is isspace()

----------------------------------------------------------------------------- Purpose: 			remove whitespace -- anything that is isspace() -- from the string-----------------------------------------------------------------------------

### TrimWhitespace

*public size_t TrimWhitespace()*

*Defined at line 374 of ./mainui/miniutl/utlstring.cpp*

 trim whitespace from the beginning and end of the string

----------------------------------------------------------------------------- Purpose: 			trim whitespace from front and back of string-----------------------------------------------------------------------------

### TrimTrailingWhitespace

*public size_t TrimTrailingWhitespace()*

*Defined at line 388 of ./mainui/miniutl/utlstring.cpp*

 trim whitespace from the end of the string

----------------------------------------------------------------------------- Purpose: 			trim whitespace from back of string-----------------------------------------------------------------------------

### SecureZero

*public void SecureZero()*

*Defined at line 138 of ./mainui/miniutl/utlstring.h*

### FormatV

*public size_t FormatV(const char * pFormat, va_list args)*

*Defined at line 112 of ./mainui/miniutl/utlstring.cpp*

----------------------------------------------------------------------------- Purpose: Helper for Format() method-----------------------------------------------------------------------------

### VAppendFormat

*public size_t VAppendFormat(const char * pFormat, va_list args)*

*Defined at line 165 of ./mainui/miniutl/utlstring.cpp*

----------------------------------------------------------------------------- Purpose: implementation helper for AppendFormat()-----------------------------------------------------------------------------

### Truncate

*public void Truncate(size_t nChars)*

*Defined at line 600 of ./mainui/miniutl/utlstring.h*

----------------------------------------------------------------------------- Purpose: Truncates the string to the specified number of characters-----------------------------------------------------------------------------

### TruncateUTF8Bytes

*public _Bool TruncateUTF8Bytes(size_t unMaxBytes)*

*Defined at line 152 of ./mainui/miniutl/utlstring.h*

 Both TruncateUTF8 methods guarantee truncation of the string to a length less-than-or-equal-to the  specified number of bytes or characters.  Both return false and truncate early if invalid UTF8 sequences  are encountered before the cap is reached. As a result, the string is guaranteed to be valid UTF-8 upon completion of the operation.

### TruncateUTF8Chars

*public _Bool TruncateUTF8Chars(size_t unMaxChars)*

*Defined at line 153 of ./mainui/miniutl/utlstring.h*

### TruncateUTF8Internal

*private _Bool TruncateUTF8Internal(size_t unMaxChars, size_t unMaxBytes)*

*Defined at line 465 of ./mainui/miniutl/utlstring.cpp*

----------------------------------------------------------------------------- Purpose: Caps the string to the specified number of bytes/chars, while respecting UTF-8 character blocks. Resulting string will be strictly less than unMaxChars and unMaxBytes.-----------------------------------------------------------------------------

### ReplaceInternal

*private size_t ReplaceInternal(const char * pstrTarget, const char * pstrReplacement, const char *(const char *, const char *) pfnCompare)*

*Defined at line 236 of ./mainui/miniutl/utlstring.cpp*

----------------------------------------------------------------------------- Purpose: replace all occurrences of one string with another			replacement string may be NULL or "" to remove target string-----------------------------------------------------------------------------

### AssertStringTooLong

*private void AssertStringTooLong()*

*Defined at line 411 of ./mainui/miniutl/utlstring.cpp*

----------------------------------------------------------------------------- Purpose: out-of-line assertion to keep code generation size down-----------------------------------------------------------------------------



