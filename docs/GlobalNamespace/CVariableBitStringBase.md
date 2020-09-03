# class CVariableBitStringBase

*Defined at line 96 of ./mainui/miniutl/bitstring.h*

----------------------------------------------------------------------------- class CVariableBitStringBase

 Defines the operations necessary for a variable sized bit array



## Members

private int m_numBits

private int m_numInts

private int m_iBitStringStorage

private int * m_pInt



## Functions

### IsFixedSize

*public _Bool IsFixedSize()*

*Defined at line 99 of ./mainui/miniutl/bitstring.h*

### Size

*public int Size()*

*Defined at line 100 of ./mainui/miniutl/bitstring.h*

### Resize

*public void Resize(int numBits)*

*Defined at line 126 of ./mainui/miniutl/bitstring.cpp*

----------------------------------------------------------------------------- Purpose: Resizes the bit string to a new number of bits Input  : resizeNumBits - -----------------------------------------------------------------------------

### GetNumInts

*public int GetNumInts()*

*Defined at line 103 of ./mainui/miniutl/bitstring.h*

### GetInts

*public int * GetInts()*

*Defined at line 104 of ./mainui/miniutl/bitstring.h*

### GetInts

*public const int * GetInts()*

*Defined at line 105 of ./mainui/miniutl/bitstring.h*

### Validate

*public void Validate(class CValidator & validator, const char * pchName)*

### CVariableBitStringBase

*protected void CVariableBitStringBase()*

*Defined at line 241 of ./mainui/miniutl/bitstring.h*

-----------------------------------------------------------------------------

### CVariableBitStringBase

*protected void CVariableBitStringBase(int numBits)*

*Defined at line 248 of ./mainui/miniutl/bitstring.h*

-----------------------------------------------------------------------------

### CVariableBitStringBase

*protected void CVariableBitStringBase(const class CVariableBitStringBase & from)*

*Defined at line 261 of ./mainui/miniutl/bitstring.h*

-----------------------------------------------------------------------------

### operator=

*protected class CVariableBitStringBase & operator=(const class CVariableBitStringBase & from)*

*Defined at line 277 of ./mainui/miniutl/bitstring.h*

-----------------------------------------------------------------------------

### ~CVariableBitStringBase

*protected void ~CVariableBitStringBase()*

*Defined at line 292 of ./mainui/miniutl/bitstring.h*

----------------------------------------------------------------------------- Purpose: Destructor Input  : Output :-----------------------------------------------------------------------------

### ValidateOperand

*protected void ValidateOperand(const class CVariableBitStringBase & operand)*

*Defined at line 117 of ./mainui/miniutl/bitstring.cpp*

-----------------------------------------------------------------------------

### GetEndMask

*protected unsigned int GetEndMask()*

*Defined at line 118 of ./mainui/miniutl/bitstring.h*

### AllocInts

*private void AllocInts(int numInts)*

*Defined at line 166 of ./mainui/miniutl/bitstring.cpp*

----------------------------------------------------------------------------- Purpose: Allocate the storage for the ints Input  : numInts - -----------------------------------------------------------------------------

### ReallocInts

*private void ReallocInts(int numInts)*

*Defined at line 187 of ./mainui/miniutl/bitstring.cpp*

----------------------------------------------------------------------------- Purpose: Reallocate the storage for the ints Input  : numInts - -----------------------------------------------------------------------------

### FreeInts

*private void FreeInts()*

*Defined at line 222 of ./mainui/miniutl/bitstring.cpp*

----------------------------------------------------------------------------- Purpose: Free storage allocated with AllocInts-----------------------------------------------------------------------------



