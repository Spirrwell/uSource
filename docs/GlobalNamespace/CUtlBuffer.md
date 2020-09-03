# class CUtlBuffer

*Defined at line 102 of ./mainui/miniutl/utlbuffer.h*

----------------------------------------------------------------------------- Command parsing..-----------------------------------------------------------------------------



## Members

CUtlMemory m_Memory

protected int m_Get

protected int m_Put

protected int m_nMaxPut

protected uint16 m_nTab

protected uint8 m_Error

protected uint8 m_Flags

protected CUtlBuffer::UtlBufferOverflowFunc_t m_GetOverflowFunc

protected CUtlBuffer::UtlBufferOverflowFunc_t m_PutOverflowFunc



## Functions

### CUtlBuffer

*public void CUtlBuffer(int growSize, int initSize, int nFlags)*

*Defined at line 195 of ./mainui/miniutl/utlbuffer.cpp*

 Constructors for growable + external buffers for serialization/unserialization

----------------------------------------------------------------------------- constructors-----------------------------------------------------------------------------

### CUtlBuffer

*public void CUtlBuffer(const void * pBuffer, int size, int nFlags)*

*Defined at line 214 of ./mainui/miniutl/utlbuffer.cpp*

### GetFlags

*public unsigned char GetFlags()*

*Defined at line 518 of ./mainui/miniutl/utlbuffer.h*

----------------------------------------------------------------------------- Where am I writing?-----------------------------------------------------------------------------

### SetBufferType

*public void SetBufferType(_Bool bIsText, _Bool bContainsCRLF)*

*Defined at line 240 of ./mainui/miniutl/utlbuffer.cpp*

 NOTE: This will assert if you attempt to recast it in a way that is not compatible. The only valid conversion is binary-> text w/CRLF

----------------------------------------------------------------------------- Modifies the buffer to be binary or text; Blows away the buffer and the CONTAINS_CRLF value. -----------------------------------------------------------------------------

### EnsureCapacity

*public void EnsureCapacity(int num)*

*Defined at line 319 of ./mainui/miniutl/utlbuffer.cpp*

 Makes sure we've got at least this much memory

----------------------------------------------------------------------------- Makes sure we've got at least this much memory-----------------------------------------------------------------------------

### SetExternalBuffer

*public void SetExternalBuffer(void * pMemory, int nSize, int nInitialPut, int nFlags)*

*Defined at line 285 of ./mainui/miniutl/utlbuffer.cpp*

 Attaches the buffer to external memory....

----------------------------------------------------------------------------- Attaches the buffer to external memory....-----------------------------------------------------------------------------

### SetReadOnlyBuffer

*public void SetReadOnlyBuffer(void * pMemory, int nSize)*

*Defined at line 303 of ./mainui/miniutl/utlbuffer.cpp*

 Attaches to an external buffer as read only. Will purge any existing buffer data

----------------------------------------------------------------------------- Purpose: Attaches to an external buffer as read only. Will purge any existing buffer data-----------------------------------------------------------------------------

### Clear

*public void Clear()*

*Defined at line 765 of ./mainui/miniutl/utlbuffer.h*

 Controls endian-ness of binary utlbufs Resets the buffer; but doesn't free memory

----------------------------------------------------------------------------- Clears out the buffer; does not free memory-----------------------------------------------------------------------------

### Purge

*public void Purge()*

*Defined at line 777 of ./mainui/miniutl/utlbuffer.h*

 Clears out the buffer; frees memory

----------------------------------------------------------------------------- Clears out the buffer; frees memory-----------------------------------------------------------------------------

### Swap

*public void Swap(class CUtlBuffer & buf)*

*Defined at line 1610 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Fast swap-----------------------------------------------------------------------------

### TakeOwnershipOfMemory

*public void TakeOwnershipOfMemory(CUtlMemory<uint8> & mem)*

*Defined at line 1623 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Take ownership of mem from a CUtlMemory-----------------------------------------------------------------------------

### ReleaseToMemory

*public void ReleaseToMemory(CUtlMemory<uint8> & mem, int * punCurrentPut)*

*Defined at line 1639 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Release our memory to a CUtlMemory The punCurrentPut parameter is because that information (how much of the memory allocated has been written to) is lost when transferring into a CUtlMemory-----------------------------------------------------------------------------

### DetachAndClear

*public void * DetachAndClear()*

*Defined at line 1651 of ./mainui/miniutl/utlbuffer.cpp*

 detaches the memory, returns it, and clears the members (but detached memory is preserved)

----------------------------------------------------------------------------- memory access-----------------------------------------------------------------------------

### CopyBuffer

*public void CopyBuffer(const class CUtlBuffer & buffer)*

*Defined at line 786 of ./mainui/miniutl/utlbuffer.h*

 copies data from another buffer

### CopyBuffer

*public void CopyBuffer(const void * pubData, int cubData)*

*Defined at line 791 of ./mainui/miniutl/utlbuffer.h*

### GetChar

*public char GetChar()*

*Defined at line 1749 of ./mainui/miniutl/utlbuffer.cpp*

 Read stuff out. Binary mode: it'll just read the bits directly in, and characters will be		read for strings until a null character is reached. Text mode: it'll parse the file, turning text #s into real numbers.		GetString will read a string until a space is reached

### GetUint8

*public uint8 GetUint8()*

*Defined at line 1760 of ./mainui/miniutl/utlbuffer.cpp*

### GetShort

*public short GetShort()*

*Defined at line 1790 of ./mainui/miniutl/utlbuffer.cpp*

### GetUnsignedShort

*public unsigned short GetUnsignedShort()*

*Defined at line 1798 of ./mainui/miniutl/utlbuffer.cpp*

### GetInt

*public int GetInt()*

*Defined at line 1805 of ./mainui/miniutl/utlbuffer.cpp*

### GetIntHex

*public int GetIntHex()*

*Defined at line 1812 of ./mainui/miniutl/utlbuffer.cpp*

### GetUnsignedInt

*public unsigned int GetUnsignedInt()*

*Defined at line 1819 of ./mainui/miniutl/utlbuffer.cpp*

### GetInt16

*public int16 GetInt16()*

*Defined at line 1782 of ./mainui/miniutl/utlbuffer.cpp*

### GetUnsignedInt64

*public uint64 GetUnsignedInt64()*

*Defined at line 1768 of ./mainui/miniutl/utlbuffer.cpp*

### GetInt64

*public int64 GetInt64()*

*Defined at line 1775 of ./mainui/miniutl/utlbuffer.cpp*

### GetFloat

*public float GetFloat()*

*Defined at line 1826 of ./mainui/miniutl/utlbuffer.cpp*

### GetDouble

*public double GetDouble()*

*Defined at line 1864 of ./mainui/miniutl/utlbuffer.cpp*

### GetString

*public _Bool GetString(char * pString, int nMaxLen)*

*Defined at line 611 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Reads a null-terminated string-----------------------------------------------------------------------------

### GetLine

*public _Bool GetLine(char * pString, int nMaxLen)*

*Defined at line 666 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Reads a CRLF/LF terminated string line -----------------------------------------------------------------------------

### GetStringFast

*public const char * GetStringFast()*

*Defined at line 572 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- returns a pointer to the next string. works for binary buffers only-----------------------------------------------------------------------------

### Get

*public _Bool Get(void * pMem, int size)*

*Defined at line 344 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Base get method from which all others derive-----------------------------------------------------------------------------

### GetUpTo

*public int GetUpTo(void * pMem, int nSize)*

*Defined at line 363 of ./mainui/miniutl/utlbuffer.cpp*

 This will get at least 1 byte and up to nSize bytes.  It will return the number of bytes actually read.

----------------------------------------------------------------------------- This will get at least 1 byte and up to nSize bytes.  It will return the number of bytes actually read.-----------------------------------------------------------------------------

### GetDelimitedString

*public void GetDelimitedString(class CUtlCharConversion * pConv, char * pString, int nMaxChars)*

*Defined at line 741 of ./mainui/miniutl/utlbuffer.cpp*

 This version of GetString converts " to \ and " to \, etc. It also reads a " at the beginning and end of the string

### GetDelimitedChar

*public char GetDelimitedChar(class CUtlCharConversion * pConv)*

*Defined at line 734 of ./mainui/miniutl/utlbuffer.cpp*

### PeekStringLength

*public int PeekStringLength()*

*Defined at line 458 of ./mainui/miniutl/utlbuffer.cpp*

 This will return the # of characters of the string about to be read out NOTE: The count will *include* the terminating 0!! In binary mode, it's the number of characters until the next 0 In text mode, it's the number of characters until the next space.

----------------------------------------------------------------------------- Peek size of sting to come, check memory bound-----------------------------------------------------------------------------

### PeekDelimitedStringLength

*public int PeekDelimitedStringLength(class CUtlCharConversion * pConv, _Bool bActualSize)*

*Defined at line 523 of ./mainui/miniutl/utlbuffer.cpp*

 This version of PeekStringLength converts " to \ and " to \, etc. It also reads a " at the beginning and end of the string NOTE: The count will *include* the terminating 0!! In binary mode, it's the number of characters until the next 0 In text mode, it's the number of characters between "s (checking for ") Specifying false for bActualSize will return the pre-translated number of characters including the delimiters and the escape characters. So, **<not a builtin command>**  counts as 2 characters when bActualSize == false and only 1 character when bActualSize == true

----------------------------------------------------------------------------- This version of PeekStringLength converts " to \ and " to \, etc. It also reads a " at the beginning and end of the string-----------------------------------------------------------------------------

### Scanf

*public int Scanf(const char * pFmt)*

*Defined at line 1092 of ./mainui/miniutl/utlbuffer.cpp*

 Just like scanf, but doesn't work in binary mode

### VaScanf

*public int VaScanf(const char * pFmt, va_list list)*

*Defined at line 922 of ./mainui/miniutl/utlbuffer.cpp*

### EatWhiteSpace

*public void EatWhiteSpace()*

*Defined at line 378 of ./mainui/miniutl/utlbuffer.cpp*

 Eats white space, advances Get index

----------------------------------------------------------------------------- Eats whitespace-----------------------------------------------------------------------------

### EatWhiteSpaceNoOverflow

*public void EatWhiteSpaceNoOverflow()*

*Defined at line 395 of ./mainui/miniutl/utlbuffer.cpp*

 Eats white space, advances Get index - won't overflow if file ends with whitespace.

----------------------------------------------------------------------------- Eats whitespace without causing overflows-----------------------------------------------------------------------------

### EatCPPComment

*public _Bool EatCPPComment()*

*Defined at line 412 of ./mainui/miniutl/utlbuffer.cpp*

 Eats C++ style comments

----------------------------------------------------------------------------- Eats C++ style comments-----------------------------------------------------------------------------

### ParseToken

*public _Bool ParseToken(const char * pStartingDelim, const char * pEndingDelim, char * pString, int nMaxLen)*

*Defined at line 1159 of ./mainui/miniutl/utlbuffer.cpp*

 (For text buffers only) Parse a token from the buffer: Grab all text that lies between a starting delimiter + ending delimiter (skipping whitespace that leads + trails both delimiters). If successful, the get index is advanced and the function returns true, otherwise the index is not advanced and the function returns false.

----------------------------------------------------------------------------- (For text buffers only) Parse a token from the buffer: Grab all text that lies between a starting delimiter + ending delimiter (skipping whitespace that leads + trails both delimiters). Note the delimiter checks are case-insensitive. If successful, the get index is advanced and the function returns true, otherwise the index is not advanced and the function returns false.-----------------------------------------------------------------------------

### GetToken

*public _Bool GetToken(const char * pToken)*

*Defined at line 1108 of ./mainui/miniutl/utlbuffer.cpp*

 Advance the get index until after the particular string is found Do not eat whitespace before starting. Return false if it failed String test is case-insensitive.

----------------------------------------------------------------------------- Advance the get index until after the particular string is found Do not eat whitespace before starting. Return false if it failed-----------------------------------------------------------------------------

### PutChar

*public void PutChar(char c)*

*Defined at line 1665 of ./mainui/miniutl/utlbuffer.cpp*

 Write stuff in Binary mode: it'll just write the bits directly in, and strings will be		written with a null terminating character Text mode: it'll convert the numbers to text versions		PutString will not write a terminating character

### PutUint8

*public void PutUint8(uint8 ub)*

*Defined at line 1675 of ./mainui/miniutl/utlbuffer.cpp*

### PutShort

*public void PutShort(short s)*

*Defined at line 1695 of ./mainui/miniutl/utlbuffer.cpp*

### PutUnsignedShort

*public void PutUnsignedShort(unsigned short us)*

*Defined at line 1700 of ./mainui/miniutl/utlbuffer.cpp*

### PutInt

*public void PutInt(int i)*

*Defined at line 1705 of ./mainui/miniutl/utlbuffer.cpp*

### PutUnsignedInt

*public void PutUnsignedInt(unsigned int u)*

*Defined at line 1710 of ./mainui/miniutl/utlbuffer.cpp*

### PutInt16

*public void PutInt16(int16 s16)*

*Defined at line 1690 of ./mainui/miniutl/utlbuffer.cpp*

### PutUnsignedInt64

*public void PutUnsignedInt64(uint64 u64)*

*Defined at line 1680 of ./mainui/miniutl/utlbuffer.cpp*

### PutInt64

*public void PutInt64(int64 u64)*

*Defined at line 1685 of ./mainui/miniutl/utlbuffer.cpp*

### PutFloat

*public void PutFloat(float f)*

*Defined at line 1715 of ./mainui/miniutl/utlbuffer.cpp*

### PutDouble

*public void PutDouble(double d)*

*Defined at line 1732 of ./mainui/miniutl/utlbuffer.cpp*

### PutString

*public void PutString(const char * pString)*

*Defined at line 1255 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Writes a null-terminated string-----------------------------------------------------------------------------

### PutStringWithoutNull

*public void PutStringWithoutNull(const char * pString)*

*Defined at line 1310 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- This version of PutString never appends a null, normal PutString does in binary buffers-----------------------------------------------------------------------------

### Put

*public void Put(const void * pMem, int size)*

*Defined at line 1239 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Serialization-----------------------------------------------------------------------------

### PutDelimitedString

*public void PutDelimitedString(class CUtlCharConversion * pConv, const char * pString)*

*Defined at line 1346 of ./mainui/miniutl/utlbuffer.cpp*

 This version of PutString converts \ to \ and " to ", etc. It also places " at the beginning and end of the string

### PutDelimitedChar

*public void PutDelimitedChar(class CUtlCharConversion * pConv, char c)*

*Defined at line 1335 of ./mainui/miniutl/utlbuffer.cpp*

### Printf

*public void Printf(const char * pFmt)*

*Defined at line 1387 of ./mainui/miniutl/utlbuffer.cpp*

 Just like printf, writes a terminating zero in binary mode

### VaPrintf

*public void VaPrintf(const char * pFmt, va_list list)*

*Defined at line 1374 of ./mainui/miniutl/utlbuffer.cpp*

### PeekPut

*public void * PeekPut(int offset)*

*Defined at line 545 of ./mainui/miniutl/utlbuffer.h*

 What am I writing (put)/reading (get)?

----------------------------------------------------------------------------- What am I reading?-----------------------------------------------------------------------------

### PeekGet

*public const void * PeekGet()*

*Defined at line 433 of ./mainui/miniutl/utlbuffer.h*

----------------------------------------------------------------------------- no offset so optimizer can resolve the function-----------------------------------------------------------------------------

### PeekGet

*public const void * PeekGet(int offset)*

*Defined at line 425 of ./mainui/miniutl/utlbuffer.h*

----------------------------------------------------------------------------- What am I reading?-----------------------------------------------------------------------------

### PeekGet

*public const void * PeekGet(int nMaxSize, int nOffset)*

*Defined at line 875 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Peek part of the butt-----------------------------------------------------------------------------

### ReservePut

*public void * ReservePut(int nBytes)*

*Defined at line 441 of ./mainui/miniutl/utlbuffer.h*

 Reserve at least nBytes and return the pointer to the start of the reserved area. Like EnsureCapacity(TellPut()+nBytes) but non-exact; preserves geometric growth.

----------------------------------------------------------------------------- Reserve nBytes at the put location and return pointer; follow with SeekPut-----------------------------------------------------------------------------

### GetBytesRemaining

*public int GetBytesRemaining()*

*Defined at line 416 of ./mainui/miniutl/utlbuffer.h*

 How many bytes remain to be read? NOTE: This is not accurate for streaming text files; it overshoots

----------------------------------------------------------------------------- How many bytes remain to be read?-----------------------------------------------------------------------------

### TellPut

*public int TellPut()*

*Defined at line 527 of ./mainui/miniutl/utlbuffer.h*

 Where am I writing (put)/reading (get)?	

----------------------------------------------------------------------------- Where am I writing?-----------------------------------------------------------------------------

### TellGet

*public int TellGet()*

*Defined at line 407 of ./mainui/miniutl/utlbuffer.h*

----------------------------------------------------------------------------- Where am I reading?-----------------------------------------------------------------------------

### SeekPut

*public void SeekPut(enum CUtlBuffer::SeekType_t type, int offset)*

*Defined at line 1470 of ./mainui/miniutl/utlbuffer.cpp*

 Change where I'm writing (put)/reading (get)

### SeekGet

*public _Bool SeekGet(enum CUtlBuffer::SeekType_t type, int offset)*

*Defined at line 886 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Change where I'm reading-----------------------------------------------------------------------------

### Base

*public const void * Base()*

*Defined at line 724 of ./mainui/miniutl/utlbuffer.h*

 Buffer base

----------------------------------------------------------------------------- Buffer base and size-----------------------------------------------------------------------------

### Base

*public void * Base()*

*Defined at line 729 of ./mainui/miniutl/utlbuffer.h*

### String

*public const char * String()*

*Defined at line 735 of ./mainui/miniutl/utlbuffer.h*

 Returns the base as a const char*, only valid in text mode.

### CopyToString

*public void CopyToString(class CUtlString & strText)*

*Defined at line 746 of ./mainui/miniutl/utlbuffer.h*

 Copies the content of the buffer into a string (valid for binary and text mode).

### Size

*public int Size()*

*Defined at line 752 of ./mainui/miniutl/utlbuffer.h*

 memory allocation size, does *not* reflect size written or read,	use TellPut or TellGet for that

### SizeAllocated

*public int SizeAllocated()*

*Defined at line 756 of ./mainui/miniutl/utlbuffer.h*

### IsText

*public _Bool IsText()*

*Defined at line 672 of ./mainui/miniutl/utlbuffer.h*

 Am I a text buffer?

----------------------------------------------------------------------------- Am I a text buffer?-----------------------------------------------------------------------------

### IsExternallyAllocated

*public _Bool IsExternallyAllocated()*

*Defined at line 689 of ./mainui/miniutl/utlbuffer.h*

 Am I externally allocated (may not be growable, check below)

----------------------------------------------------------------------------- Am I externally allocated (may need to check IsGrowable or can't grow buffer)-----------------------------------------------------------------------------

### IsGrowable

*public _Bool IsGrowable()*

*Defined at line 681 of ./mainui/miniutl/utlbuffer.h*

 Can I grow if I'm externally allocated?

----------------------------------------------------------------------------- Can I grow if I'm externally allocated?-----------------------------------------------------------------------------

### IsValid

*public _Bool IsValid()*

*Defined at line 697 of ./mainui/miniutl/utlbuffer.h*

 Am I valid? (overflow or underflow error), Once invalid it stays invalid

----------------------------------------------------------------------------- Am I valid? (overflow or underflow error), Once invalid it stays invalid-----------------------------------------------------------------------------

### ContainsCRLF

*public _Bool ContainsCRLF()*

*Defined at line 706 of ./mainui/miniutl/utlbuffer.h*

 Do I contain carriage return/linefeeds? 

----------------------------------------------------------------------------- Do I contain carriage return/linefeeds? -----------------------------------------------------------------------------

### IsReadOnly

*public _Bool IsReadOnly()*

*Defined at line 715 of ./mainui/miniutl/utlbuffer.h*

 Am I read-only

----------------------------------------------------------------------------- Am I read-only-----------------------------------------------------------------------------

### ConvertCRLF

*public _Bool ConvertCRLF(class CUtlBuffer & outBuf)*

*Defined at line 1525 of ./mainui/miniutl/utlbuffer.cpp*

 Converts a buffer from a CRLF buffer to a CR buffer (and back) Returns false if no conversion was necessary (and outBuf is left untouched) If the conversion occurs, outBuf will be cleared.

----------------------------------------------------------------------------- Converts a buffer from a CRLF buffer to a CR buffer (and back) Returns false if no conversion was necessary (and outBuf is left untouched) If the conversion occurs, outBuf will be cleared.-----------------------------------------------------------------------------

### PushTab

*public void PushTab()*

*Defined at line 639 of ./mainui/miniutl/utlbuffer.h*

 Push/pop pretty-printing tabs

----------------------------------------------------------------------------- Push/pop pretty-printing tabs-----------------------------------------------------------------------------

### PopTab

*public void PopTab()*

*Defined at line 644 of ./mainui/miniutl/utlbuffer.h*

### EnableTabs

*public void EnableTabs(_Bool bEnable)*

*Defined at line 656 of ./mainui/miniutl/utlbuffer.h*

 Temporarily disables pretty print

----------------------------------------------------------------------------- Temporarily disables pretty print-----------------------------------------------------------------------------

### SecureZero

*public void SecureZero()*

*Defined at line 333 of ./mainui/miniutl/utlbuffer.h*

 Securely erases buffer

### SetOverflowFuncs

*protected void SetOverflowFuncs(CUtlBuffer::UtlBufferOverflowFunc_t getFunc, CUtlBuffer::UtlBufferOverflowFunc_t putFunc)*

*Defined at line 1400 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Calls the overflow functions-----------------------------------------------------------------------------

### OnPutOverflow

*protected _Bool OnPutOverflow(int nSize)*

*Defined at line 1410 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Calls the overflow functions-----------------------------------------------------------------------------

### OnGetOverflow

*protected _Bool OnGetOverflow(int nSize)*

*Defined at line 1415 of ./mainui/miniutl/utlbuffer.cpp*

### CheckPut

*protected _Bool CheckPut(int size)*

*Defined at line 1453 of ./mainui/miniutl/utlbuffer.cpp*

 Checks if a get/put is ok

----------------------------------------------------------------------------- Checks if a put is ok-----------------------------------------------------------------------------

### CheckGet

*protected _Bool CheckGet(int size)*

*Defined at line 801 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- Checks if a get is ok-----------------------------------------------------------------------------

### AddNullTermination

*protected void AddNullTermination()*

*Defined at line 1497 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- null terminate the buffer-----------------------------------------------------------------------------

### WasLastCharacterCR

*protected _Bool WasLastCharacterCR()*

*Defined at line 619 of ./mainui/miniutl/utlbuffer.h*

 Methods to help with pretty-printing

----------------------------------------------------------------------------- Methods to help with pretty-printing-----------------------------------------------------------------------------

### PutTabs

*protected void PutTabs()*

*Defined at line 626 of ./mainui/miniutl/utlbuffer.h*

### GetDelimitedCharInternal

*protected char GetDelimitedCharInternal(class CUtlCharConversion * pConv)*

*Defined at line 718 of ./mainui/miniutl/utlbuffer.cpp*

 Help with delimited stuff

----------------------------------------------------------------------------- This version of GetString converts \ to \ and " to ", etc. It also places " at the beginning and end of the string-----------------------------------------------------------------------------

### PutDelimitedCharInternal

*protected void PutDelimitedCharInternal(class CUtlCharConversion * pConv, char c)*

*Defined at line 1321 of ./mainui/miniutl/utlbuffer.cpp*

----------------------------------------------------------------------------- This version of PutString converts \ to \ and " to ", etc. It also places " at the beginning and end of the string-----------------------------------------------------------------------------

### PutOverflow

*protected _Bool PutOverflow(int nSize)*

*Defined at line 1424 of ./mainui/miniutl/utlbuffer.cpp*

 Default overflow funcs

----------------------------------------------------------------------------- Checks if a put is ok-----------------------------------------------------------------------------

### GetOverflow

*protected _Bool GetOverflow(int nSize)*

*Defined at line 1444 of ./mainui/miniutl/utlbuffer.cpp*

### PeekStringMatch

*protected _Bool PeekStringMatch(int nOffset, const char * pString, int nLen)*

*Defined at line 511 of ./mainui/miniutl/utlbuffer.cpp*

 Does the next bytes of the buffer match a pattern?

----------------------------------------------------------------------------- Does the next bytes of the buffer match a pattern?-----------------------------------------------------------------------------

### PeekWhiteSpace

*protected int PeekWhiteSpace(int nOffset)*

*Defined at line 439 of ./mainui/miniutl/utlbuffer.cpp*

 How much whitespace should I skip?

----------------------------------------------------------------------------- Peeks how much whitespace to eat-----------------------------------------------------------------------------

### CheckPeekGet

*protected _Bool CheckPeekGet(int nOffset, int nSize)*

*Defined at line 831 of ./mainui/miniutl/utlbuffer.cpp*

 Checks if a peek get is ok

----------------------------------------------------------------------------- Checks if a peek get is ok-----------------------------------------------------------------------------

### CheckArbitraryPeekGet

*protected _Bool CheckArbitraryPeekGet(int nOffset, int & nIncrement)*

*Defined at line 847 of ./mainui/miniutl/utlbuffer.cpp*

 Call this to peek arbitrarily long into memory. It doesn't fail unless it can't read *anything* new

----------------------------------------------------------------------------- Call this to peek arbitrarily long into memory. It doesn't fail unless it can't read *anything* new-----------------------------------------------------------------------------

### TellMaxPut

*private int TellMaxPut()*

*Defined at line 536 of ./mainui/miniutl/utlbuffer.h*

 Returns max amount of data written. Used internally but externally you should use put / seek

----------------------------------------------------------------------------- What's the most I've ever written?-----------------------------------------------------------------------------

### CUtlBuffer

*private void CUtlBuffer(const class CUtlBuffer & rhs)*

 Copy construction and assignment are not valid

### operator=

*private const class CUtlBuffer & operator=(const class CUtlBuffer & rhs)*



## Enums

| enum SeekType_t |

--

| SEEK_HEAD |
| SEEK_CURRENT |
| SEEK_TAIL |


*Defined at line 105 of ./mainui/miniutl/utlbuffer.h*

| enum BufferFlags_t |

--

| TEXT_BUFFER |
| EXTERNAL_GROWABLE |
| CONTAINS_CRLF |
| READ_ONLY |
| AUTO_TABS_DISABLED |
| LITTLE_ENDIAN_BUFFER |
| BIG_ENDIAN_BUFFER |


*Defined at line 113 of ./mainui/miniutl/utlbuffer.h*

 flags

| enum  |

--

| PUT_OVERFLOW |
| GET_OVERFLOW |
| MAX_ERROR_FLAG |


*Defined at line 337 of ./mainui/miniutl/utlbuffer.h*

 error flags



