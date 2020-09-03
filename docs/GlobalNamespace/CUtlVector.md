# class CUtlVector

*Defined at line 37 of ./mainui/miniutl/utlvector.h*

----------------------------------------------------------------------------- The CUtlVector class: A growable array class which doubles in size by default. It will always keep all elements consecutive in memory, and may move the elements around in memory (via a PvRealloc) when elements are inserted or removed. Clients should therefore refer to the elements of the vector by index (they should *never* maintain pointers to elements in the vector).-----------------------------------------------------------------------------



## Members

protected CUtlVector::CAllocator m_Memory

protected int m_Size



## Functions

### CUtlVector<T, A>

*public void CUtlVector<T, A>(int growSize, int initSize)*

*Defined at line 232 of ./mainui/miniutl/utlvector.h*

 constructor, destructor

----------------------------------------------------------------------------- constructor, destructor-----------------------------------------------------------------------------

### CUtlVector<T, A>

*public void CUtlVector<T, A>(T * pMemory, int allocationCount, int numElements)*

*Defined at line 238 of ./mainui/miniutl/utlvector.h*

### ~CUtlVector<T, A>

*public void ~CUtlVector<T, A>()*

*Defined at line 244 of ./mainui/miniutl/utlvector.h*

### operator=

*public CUtlVector<T, A> & operator=(const CUtlVector<T, A> & other)*

*Defined at line 250 of ./mainui/miniutl/utlvector.h*

 Copy the array.

### operator[]

*public T & operator[](int i)*

*Defined at line 261 of ./mainui/miniutl/utlvector.h*

 element access

----------------------------------------------------------------------------- element access-----------------------------------------------------------------------------

### operator[]

*public const T & operator[](int i)*

*Defined at line 268 of ./mainui/miniutl/utlvector.h*

### Element

*public T & Element(int i)*

*Defined at line 275 of ./mainui/miniutl/utlvector.h*

### Element

*public const T & Element(int i)*

*Defined at line 282 of ./mainui/miniutl/utlvector.h*

### Head

*public T & Head()*

*Defined at line 289 of ./mainui/miniutl/utlvector.h*

### Head

*public const T & Head()*

*Defined at line 296 of ./mainui/miniutl/utlvector.h*

### Tail

*public T & Tail()*

*Defined at line 303 of ./mainui/miniutl/utlvector.h*

### Tail

*public const T & Tail()*

*Defined at line 310 of ./mainui/miniutl/utlvector.h*

### Base

*public T * Base()*

*Defined at line 64 of ./mainui/miniutl/utlvector.h*

 Gets the base address (can change when adding elements!)

### Base

*public const T * Base()*

*Defined at line 65 of ./mainui/miniutl/utlvector.h*

### Count

*public int Count()*

*Defined at line 320 of ./mainui/miniutl/utlvector.h*

 Returns the number of elements in the vector

----------------------------------------------------------------------------- Count-----------------------------------------------------------------------------

### IsEmpty

*public _Bool IsEmpty()*

*Defined at line 69 of ./mainui/miniutl/utlvector.h*

### IsValidIndex

*public _Bool IsValidIndex(int i)*

*Defined at line 330 of ./mainui/miniutl/utlvector.h*

 Is element index valid?

----------------------------------------------------------------------------- Is element index valid?-----------------------------------------------------------------------------

### InvalidIndex

*public int InvalidIndex()*

*Defined at line 340 of ./mainui/miniutl/utlvector.h*

----------------------------------------------------------------------------- Returns in invalid index-----------------------------------------------------------------------------

### AddToHead

*public int AddToHead()*

*Defined at line 653 of ./mainui/miniutl/utlvector.h*

 Adds an element, uses default constructor

----------------------------------------------------------------------------- Adds an element, uses default constructor-----------------------------------------------------------------------------

### AddToTail

*public int AddToTail()*

*Defined at line 659 of ./mainui/miniutl/utlvector.h*

### AddToTailGetPtr

*public T * AddToTailGetPtr()*

*Defined at line 665 of ./mainui/miniutl/utlvector.h*

### InsertBefore

*public int InsertBefore(int elem)*

*Defined at line 677 of ./mainui/miniutl/utlvector.h*

### InsertAfter

*public int InsertAfter(int elem)*

*Defined at line 671 of ./mainui/miniutl/utlvector.h*

### AddToHead

*public int AddToHead(const T & src)*

*Defined at line 693 of ./mainui/miniutl/utlvector.h*

 Adds an element, uses copy constructor

----------------------------------------------------------------------------- Adds an element, uses copy constructor-----------------------------------------------------------------------------

### AddToTail

*public int AddToTail(const T & src)*

*Defined at line 699 of ./mainui/miniutl/utlvector.h*

### InsertBefore

*public int InsertBefore(int elem, const T & src)*

*Defined at line 711 of ./mainui/miniutl/utlvector.h*

### InsertAfter

*public int InsertAfter(int elem, const T & src)*

*Defined at line 705 of ./mainui/miniutl/utlvector.h*

### AddMultipleToHead

*public int AddMultipleToHead(int num)*

*Defined at line 729 of ./mainui/miniutl/utlvector.h*

 Adds multiple elements, uses default constructor

----------------------------------------------------------------------------- Adds multiple elements, uses default constructor-----------------------------------------------------------------------------

### AddMultipleToTail

*public int AddMultipleToTail(int num, const T * pToCopy)*

*Defined at line 735 of ./mainui/miniutl/utlvector.h*

### InsertMultipleBefore

*public int InsertMultipleBefore(int elem, int num, const T * pToCopy)*

*Defined at line 803 of ./mainui/miniutl/utlvector.h*

### InsertMultipleAfter

*public int InsertMultipleAfter(int elem, int num, const T * pToCopy)*

*Defined at line 744 of ./mainui/miniutl/utlvector.h*

### SetCount

*public void SetCount(int count)*

*Defined at line 750 of ./mainui/miniutl/utlvector.h*

 Matches desired element count by removing or adding at tail

### CopyArray

*public void CopyArray(const T * pArray, int size)*

*Defined at line 777 of ./mainui/miniutl/utlvector.h*

 Calls SetSize and copies each element.

### Swap

*public void Swap(CUtlVector<T, A> & vec)*

*Defined at line 790 of ./mainui/miniutl/utlvector.h*

 Fast swap

### AddVectorToTail

*public int AddVectorToTail(const CUtlVector<T, A> & src)*

*Defined at line 797 of ./mainui/miniutl/utlvector.h*

 Add the specified array to the tail.

### Find

*public int Find(const T & src)*

*Defined at line 835 of ./mainui/miniutl/utlvector.h*

 Finds an element (element needs operator== defined)

----------------------------------------------------------------------------- Finds an element (element needs operator== defined)-----------------------------------------------------------------------------

### HasElement

*public _Bool HasElement(const T & src)*

*Defined at line 846 of ./mainui/miniutl/utlvector.h*

### EnsureCapacity

*public void EnsureCapacity(int num)*

*Defined at line 604 of ./mainui/miniutl/utlvector.h*

 Makes sure we have enough memory allocated to store a requested # of elements

----------------------------------------------------------------------------- Makes sure we have enough memory allocated to store a requested # of elements-----------------------------------------------------------------------------

### EnsureCount

*public void EnsureCount(int num)*

*Defined at line 614 of ./mainui/miniutl/utlvector.h*

 Makes sure we have at least this many elements

----------------------------------------------------------------------------- Makes sure we have at least this many elements-----------------------------------------------------------------------------

### FastRemove

*public void FastRemove(int elem)*

*Defined at line 856 of ./mainui/miniutl/utlvector.h*

 Element removal

----------------------------------------------------------------------------- Element removal-----------------------------------------------------------------------------

### Remove

*public void Remove(int elem)*

*Defined at line 874 of ./mainui/miniutl/utlvector.h*

### FindAndRemove

*public _Bool FindAndRemove(const T & src)*

*Defined at line 882 of ./mainui/miniutl/utlvector.h*

### FindAndFastRemove

*public _Bool FindAndFastRemove(const T & src)*

*Defined at line 894 of ./mainui/miniutl/utlvector.h*

### RemoveMultiple

*public void RemoveMultiple(int elem, int num)*

*Defined at line 906 of ./mainui/miniutl/utlvector.h*

### RemoveMultipleFromTail

*public void RemoveMultipleFromTail(int num)*

*Defined at line 929 of ./mainui/miniutl/utlvector.h*

### RemoveAll

*public void RemoveAll()*

*Defined at line 947 of ./mainui/miniutl/utlvector.h*

### Purge

*public void Purge()*

*Defined at line 964 of ./mainui/miniutl/utlvector.h*

 Memory deallocation

----------------------------------------------------------------------------- Memory deallocation-----------------------------------------------------------------------------

### PurgeAndDeleteElements

*public void PurgeAndDeleteElements()*

*Defined at line 972 of ./mainui/miniutl/utlvector.h*

 Purges the list and calls delete on each element in it.

### Compact

*public void Compact()*

*Defined at line 982 of ./mainui/miniutl/utlvector.h*

 Compacts the vector to the number of elements actually in use

### SetGrowSize

*public void SetGrowSize(int size)*

*Defined at line 136 of ./mainui/miniutl/utlvector.h*

 Set the size by which it grows when it needs to allocate more memory.

### NumAllocated

*public int NumAllocated()*

*Defined at line 138 of ./mainui/miniutl/utlvector.h*

### Reverse

*public void Reverse()*

*Defined at line 365 of ./mainui/miniutl/utlvector.h*

 Reverses the order of elements via swaps

----------------------------------------------------------------------------- Reverses the order of elements-----------------------------------------------------------------------------

### SortedFind

*public int SortedFind(const T & search, _Bool (*)(const T &, const T &, void *) pfnLessFunc, void * pLessContext)*

*Defined at line 382 of ./mainui/miniutl/utlvector.h*

 Finds an element within the list using a binary search You must sort the list before using these or your results will be wrong

----------------------------------------------------------------------------- finds a particular element You must sort the list before using or your results will be wrong-----------------------------------------------------------------------------

### SortedFind

*public int SortedFind(const T & search, _Bool (*)(const T &, const T &) pfnLessFunc)*

*Defined at line 410 of ./mainui/miniutl/utlvector.h*

----------------------------------------------------------------------------- finds a particular element You must sort the list before using or your results will be wrong-----------------------------------------------------------------------------

### SortedFindFirst

*public int SortedFindFirst(const T & search, _Bool (*)(const T &, const T &, void *) pfnLessFunc, void * pLessContext)*

*Defined at line 439 of ./mainui/miniutl/utlvector.h*

----------------------------------------------------------------------------- finds the FIRST matching element ( assumes dupes ) You must sort the list before using or your results will be wrong-----------------------------------------------------------------------------

### SortedFindLessOrEqual

*public int SortedFindLessOrEqual(const T & search, _Bool (*)(const T &, const T &, void *) pfnLessFunc, void * pLessContext, int start, int end)*

*Defined at line 472 of ./mainui/miniutl/utlvector.h*

----------------------------------------------------------------------------- Implementation of upper_bound(). Finds the element with the highest index that is less than or equal to what you're looking for. You must sort the list before using or your results will be wrong This takes a range in the vector to search, end is inclusive (Count() - 1)-----------------------------------------------------------------------------

### SortedFindLessOrEqual

*public int SortedFindLessOrEqual(const T & search, _Bool (*)(const T &, const T &, void *) pfnLessFunc, void * pLessContext)*

*Defined at line 515 of ./mainui/miniutl/utlvector.h*

----------------------------------------------------------------------------- Implementation of upper_bound(). Finds the element with the highest index that is less than or equal to what you're looking for. You must sort the list before using or your results will be wrong Searches the entire vector-----------------------------------------------------------------------------

### SortedFindLessOrEqual

*public int SortedFindLessOrEqual(const T & search, _Bool (*)(const T &, const T &) pfnLessFunc, int start, int end)*

*Defined at line 534 of ./mainui/miniutl/utlvector.h*

----------------------------------------------------------------------------- sorted find, with no context pointer-----------------------------------------------------------------------------

### SortedFindLessOrEqual

*public int SortedFindLessOrEqual(const T & search, _Bool (*)(const T &, const T &) pfnLessFunc)*

*Defined at line 574 of ./mainui/miniutl/utlvector.h*

----------------------------------------------------------------------------- sorted find, with no context pointer-----------------------------------------------------------------------------

### SortedInsert

*public int SortedInsert(const T & src, _Bool (*)(const T &, const T &, void *) pfnLessFunc, void * pLessContext)*

*Defined at line 521 of ./mainui/miniutl/utlvector.h*

### SortedInsert

*public int SortedInsert(const T & src, _Bool (*)(const T &, const T &) pfnLessFunc)*

*Defined at line 581 of ./mainui/miniutl/utlvector.h*

### Sort

*public void Sort(int (*)(const T *, const T *) pfnCompare)*

*Defined at line 595 of ./mainui/miniutl/utlvector.h*

 WARNING: The less func for these Sort functions expects -1, 0 for equal, or 1. If you pass only true/false back, you won't get correct sorting.

----------------------------------------------------------------------------- Sorts the vector-----------------------------------------------------------------------------

### CUtlVector<T, A>

*protected void CUtlVector<T, A>(const CUtlVector<T, A> & )*

 Can't copy this unless we explicitly do it!

### GrowVector

*protected void GrowVector(int num)*

*Defined at line 350 of ./mainui/miniutl/utlvector.h*

 Grows the vector

----------------------------------------------------------------------------- Grows the vector-----------------------------------------------------------------------------

### ShiftElementsRight

*protected void ShiftElementsRight(int elem, int num)*

*Defined at line 625 of ./mainui/miniutl/utlvector.h*

 Shifts elements....

----------------------------------------------------------------------------- Shifts elements-----------------------------------------------------------------------------

### ShiftElementsLeft

*protected void ShiftElementsLeft(int elem, int num)*

*Defined at line 634 of ./mainui/miniutl/utlvector.h*



