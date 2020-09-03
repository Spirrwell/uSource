# class CFixedBitStringBase

*Defined at line 175 of ./mainui/miniutl/bitstring.h*

-------------------------------------



## Members

private int [(NUM_BITS + (32 - 1)) / 32] m_Ints



## Functions

### IsFixedSize

*public _Bool IsFixedSize()*

*Defined at line 178 of ./mainui/miniutl/bitstring.h*

### Size

*public int Size()*

*Defined at line 179 of ./mainui/miniutl/bitstring.h*

### Resize

*public void Resize(int numBits)*

*Defined at line 180 of ./mainui/miniutl/bitstring.h*

### GetNumInts

*public int GetNumInts()*

*Defined at line 182 of ./mainui/miniutl/bitstring.h*

### GetInts

*public int * GetInts()*

*Defined at line 183 of ./mainui/miniutl/bitstring.h*

### GetInts

*public const int * GetInts()*

*Defined at line 184 of ./mainui/miniutl/bitstring.h*

### CFixedBitStringBase<NUM_BITS>

*protected void CFixedBitStringBase<NUM_BITS>()*

*Defined at line 187 of ./mainui/miniutl/bitstring.h*

### CFixedBitStringBase<NUM_BITS>

*protected void CFixedBitStringBase<NUM_BITS>(int numBits)*

*Defined at line 188 of ./mainui/miniutl/bitstring.h*

### ValidateOperand

*protected void ValidateOperand(const CFixedBitStringBase<NUM_BITS> & operand)*

*Defined at line 190 of ./mainui/miniutl/bitstring.h*

### GetEndMask

*public unsigned int GetEndMask()*

*Defined at line 193 of ./mainui/miniutl/bitstring.h*



## Enums

| enum  |

--

| NUM_INTS |


*Defined at line 196 of ./mainui/miniutl/bitstring.h*



