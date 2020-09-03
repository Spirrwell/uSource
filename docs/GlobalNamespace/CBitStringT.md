# class CBitStringT

*Defined at line 59 of ./mainui/miniutl/bitstring.h*

----------------------------------------------------------------------------- template CBitStringT

 Defines the operations relevant to any bit array. Simply requires a base class that implements Size(), GetInts(), GetNumInts() & ValidateOperand()

 CBitString and CFixedBitString<int> are the actual classes generally used by clients



Inherits from BASE_OPS



## Functions

### CBitStringT<BASE_OPS>

*public void CBitStringT<BASE_OPS>()*

*Defined at line 299 of ./mainui/miniutl/bitstring.h*

-----------------------------------------------------------------------------

### CBitStringT<BASE_OPS>

*public void CBitStringT<BASE_OPS>(int numBits)*

*Defined at line 312 of ./mainui/miniutl/bitstring.h*

-----------------------------------------------------------------------------

### And

*public void And(const CBitStringT<BASE_OPS> & andStr, CBitStringT<BASE_OPS> * out)*

*Defined at line 360 of ./mainui/miniutl/bitstring.h*

 Do NOT override bitwise operators (see note in header)

----------------------------------------------------------------------------- Purpose: Input  : Output :-----------------------------------------------------------------------------

### Or

*public void Or(const CBitStringT<BASE_OPS> & orStr, CBitStringT<BASE_OPS> * out)*

*Defined at line 381 of ./mainui/miniutl/bitstring.h*

----------------------------------------------------------------------------- Purpose: Input  : Output :-----------------------------------------------------------------------------

### Xor

*public void Xor(const CBitStringT<BASE_OPS> & orStr, CBitStringT<BASE_OPS> * out)*

*Defined at line 402 of ./mainui/miniutl/bitstring.h*

----------------------------------------------------------------------------- Purpose: Input  : Output :-----------------------------------------------------------------------------

### Not

*public void Not(CBitStringT<BASE_OPS> * out)*

*Defined at line 420 of ./mainui/miniutl/bitstring.h*

----------------------------------------------------------------------------- Purpose: Input  : Output :-----------------------------------------------------------------------------

### Copy

*public void Copy(CBitStringT<BASE_OPS> * out)*

*Defined at line 439 of ./mainui/miniutl/bitstring.h*

----------------------------------------------------------------------------- Purpose: Copy a bit string Input  : Output :-----------------------------------------------------------------------------

### IsAllClear

*public _Bool IsAllClear()*

*Defined at line 453 of ./mainui/miniutl/bitstring.h*

----------------------------------------------------------------------------- Purpose: Are all bits zero? Input  : Output :-----------------------------------------------------------------------------

### IsAllSet

*public _Bool IsAllSet()*

*Defined at line 476 of ./mainui/miniutl/bitstring.h*

----------------------------------------------------------------------------- Purpose: Are all bits set? Input  : Output :-----------------------------------------------------------------------------

### GetBit

*public _Bool GetBit(int bitNum)*

*Defined at line 327 of ./mainui/miniutl/bitstring.h*

-----------------------------------------------------------------------------

### SetBit

*public void SetBit(int bitNum)*

*Defined at line 337 of ./mainui/miniutl/bitstring.h*

-----------------------------------------------------------------------------

### ClearBit

*public void ClearBit(int bitNum)*

*Defined at line 347 of ./mainui/miniutl/bitstring.h*

-----------------------------------------------------------------------------

### SetAllBits

*public void SetAllBits()*

*Defined at line 499 of ./mainui/miniutl/bitstring.h*

----------------------------------------------------------------------------- Purpose: Sets all bits Input  : Output :-----------------------------------------------------------------------------

### ClearAllBits

*public void ClearAllBits()*

*Defined at line 511 of ./mainui/miniutl/bitstring.h*

----------------------------------------------------------------------------- Purpose: Clears all bits Input  : Output :-----------------------------------------------------------------------------

### DebugPrintBits

*public void DebugPrintBits()*

*Defined at line 520 of ./mainui/miniutl/bitstring.h*

-----------------------------------------------------------------------------

### SaveBitString

*public void SaveBitString(class CUtlBuffer & buf)*

*Defined at line 529 of ./mainui/miniutl/bitstring.h*

-----------------------------------------------------------------------------

### LoadBitString

*public void LoadBitString(class CUtlBuffer & buf)*

*Defined at line 538 of ./mainui/miniutl/bitstring.h*

-----------------------------------------------------------------------------

### And

*public void And(const class CBitStringT<class CFixedBitStringBase<128> > & addStr, class CBitStringT<class CFixedBitStringBase<128> > * out)*

*Defined at line 549 of ./mainui/miniutl/bitstring.h*

-----------------------------------------------------------------------------

**note** (toml 11-09-02): these methods are a nod to a heavy user of the bit string, AI conditions. This assumes MAX_CONDITIONS == 128

### IsAllClear

*public _Bool IsAllClear()*

*Defined at line 562 of ./mainui/miniutl/bitstring.h*

### Copy

*public void Copy(class CBitStringT<class CFixedBitStringBase<128> > * out)*

*Defined at line 570 of ./mainui/miniutl/bitstring.h*



