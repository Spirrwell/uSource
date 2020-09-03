# class CCopyableUtlVectorFixed

*Defined at line 202 of ./mainui/miniutl/utlvector.h*

----------------------------------------------------------------------------- The CCopyableUtlVectorFixed class: A array class that allows copy construction (so you can nest a CUtlVector inside of another one of our containers)  WARNING - this class lets you copy construct which can be an expensive operation if you don't carefully control when it happens Only use this when nesting a CUtlVector() inside of another one of our container classes (i.e a CUtlMap)-----------------------------------------------------------------------------



Inherits from CUtlVectorFixed<T, MAX_SIZE>



## Functions

### CCopyableUtlVectorFixed<T, MAX_SIZE>

*public void CCopyableUtlVectorFixed<T, MAX_SIZE>(int growSize, int initSize)*

*Defined at line 206 of ./mainui/miniutl/utlvector.h*

### CCopyableUtlVectorFixed<T, MAX_SIZE>

*public void CCopyableUtlVectorFixed<T, MAX_SIZE>(T * pMemory, int numElements)*

*Defined at line 207 of ./mainui/miniutl/utlvector.h*

### CCopyableUtlVectorFixed<T, MAX_SIZE>

*public void CCopyableUtlVectorFixed<T, MAX_SIZE>(const CCopyableUtlVectorFixed<T, MAX_SIZE> & vec)*

*Defined at line 208 of ./mainui/miniutl/utlvector.h*



