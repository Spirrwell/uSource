# class CCopyableUtlVector

*Defined at line 219 of ./mainui/miniutl/utlvector.h*

----------------------------------------------------------------------------- The CCopyableUtlVector class: A array class that allows copy construction (so you can nest a CUtlVector inside of another one of our containers)  WARNING - this class lets you copy construct which can be an expensive operation if you don't carefully control when it happens Only use this when nesting a CUtlVector() inside of another one of our container classes (i.e a CUtlMap)-----------------------------------------------------------------------------



Inherits from CUtlVector<T, A>



## Functions

### CCopyableUtlVector<T, A>

*public void CCopyableUtlVector<T, A>(int growSize, int initSize)*

*Defined at line 223 of ./mainui/miniutl/utlvector.h*

### CCopyableUtlVector<T, A>

*public void CCopyableUtlVector<T, A>(T * pMemory, int numElements)*

*Defined at line 224 of ./mainui/miniutl/utlvector.h*

### CCopyableUtlVector<T, A>

*public void CCopyableUtlVector<T, A>(const CCopyableUtlVector<T, A> & vec)*

*Defined at line 225 of ./mainui/miniutl/utlvector.h*

### CCopyableUtlVector<T, A>

*public void CCopyableUtlVector<T, A>(const CUtlVector<T, A> & vec)*

*Defined at line 226 of ./mainui/miniutl/utlvector.h*



