# class CUtlLinkedList

*Defined at line 41 of ./mainui/miniutl/utllinkedlist.h*

----------------------------------------------------------------------------- class CUtlLinkedList: description:		A lovely index-based linked list! T is the class type, I is the index		type, which usually should be an unsigned short or smaller.-----------------------------------------------------------------------------



## Members

protected CUtlMemory<struct CUtlLinkedList::ListElem_t> m_Memory

protected I m_Head

protected I m_Tail

protected I m_FirstFree

protected I m_ElementCount

protected I m_TotalElements

protected struct CUtlLinkedList::ListElem_t * m_pElements



## Records

ListElem_t



## Functions

### CUtlLinkedList<T, I>

*public void CUtlLinkedList<T, I>(int growSize, int initSize)*

*Defined at line 199 of ./mainui/miniutl/utllinkedlist.h*

 constructor, destructor

----------------------------------------------------------------------------- constructor, destructor-----------------------------------------------------------------------------

### CUtlLinkedList<T, I>

*public void CUtlLinkedList<T, I>(void * pMemory, int memsize)*

*Defined at line 207 of ./mainui/miniutl/utllinkedlist.h*

### ~CUtlLinkedList<T, I>

*public void ~CUtlLinkedList<T, I>()*

*Defined at line 215 of ./mainui/miniutl/utllinkedlist.h*

### Element

*public T & Element(I i)*

*Defined at line 235 of ./mainui/miniutl/utllinkedlist.h*

 gets particular elements

----------------------------------------------------------------------------- gets particular elements-----------------------------------------------------------------------------

### Element

*public const T & Element(I i)*

*Defined at line 241 of ./mainui/miniutl/utllinkedlist.h*

### operator[]

*public T & operator[](I i)*

*Defined at line 247 of ./mainui/miniutl/utllinkedlist.h*

### operator[]

*public const T & operator[](I i)*

*Defined at line 253 of ./mainui/miniutl/utllinkedlist.h*

### EnsureCapacity

*public void EnsureCapacity(int num)*

*Defined at line 334 of ./mainui/miniutl/utllinkedlist.h*

 Make sure we have a particular amount of memory

----------------------------------------------------------------------------- Makes sure we have enough memory allocated to store a requested # of elements-----------------------------------------------------------------------------

### Purge

*public void Purge()*

*Defined at line 346 of ./mainui/miniutl/utllinkedlist.h*

 Memory deallocation

----------------------------------------------------------------------------- Deallocate memory-----------------------------------------------------------------------------

### PurgeAndDeleteElements

*public void PurgeAndDeleteElements()*

*Defined at line 358 of ./mainui/miniutl/utllinkedlist.h*

 Delete all the elements then call Purge.

### NumAllocated

*public int NumAllocated()*

*Defined at line 67 of ./mainui/miniutl/utllinkedlist.h*

### InsertBefore

*public I InsertBefore(I before)*

*Defined at line 438 of ./mainui/miniutl/utllinkedlist.h*

 Insertion methods....

----------------------------------------------------------------------------- Insertion methods; allocates and links (uses default constructor)-----------------------------------------------------------------------------

### InsertAfter

*public I InsertAfter(I after)*

*Defined at line 453 of ./mainui/miniutl/utllinkedlist.h*

### AddToHead

*public I AddToHead()*

*Defined at line 468 of ./mainui/miniutl/utllinkedlist.h*

### AddToTail

*public I AddToTail()*

*Defined at line 474 of ./mainui/miniutl/utllinkedlist.h*

### InsertBefore

*public I InsertBefore(I before, const T & src)*

*Defined at line 504 of ./mainui/miniutl/utllinkedlist.h*

----------------------------------------------------------------------------- Insertion methods; allocates and links (uses copy constructor)-----------------------------------------------------------------------------

### InsertAfter

*public I InsertAfter(I after, const T & src)*

*Defined at line 519 of ./mainui/miniutl/utllinkedlist.h*

### AddToHead

*public I AddToHead(const T & src)*

*Defined at line 534 of ./mainui/miniutl/utllinkedlist.h*

### AddToTail

*public I AddToTail(const T & src)*

*Defined at line 540 of ./mainui/miniutl/utllinkedlist.h*

### Find

*public I Find(const T & src)*

*Defined at line 551 of ./mainui/miniutl/utllinkedlist.h*

 Find an element and return its index or InvalidIndex() if it couldn't be found.

----------------------------------------------------------------------------- Removal methods-----------------------------------------------------------------------------

### FindAndRemove

*public _Bool FindAndRemove(const T & src)*

*Defined at line 563 of ./mainui/miniutl/utllinkedlist.h*

 Look for the element. If it exists, remove it and return true. Otherwise, return false.

### RemoveFromHead

*public T RemoveFromHead()*

*Defined at line 578 of ./mainui/miniutl/utllinkedlist.h*

 Removal methods

### RemoveFromTail

*public T RemoveFromTail()*

*Defined at line 586 of ./mainui/miniutl/utllinkedlist.h*

### Remove

*public void Remove(I elem)*

*Defined at line 594 of ./mainui/miniutl/utllinkedlist.h*

### RemoveAll

*public void RemoveAll()*

*Defined at line 600 of ./mainui/miniutl/utllinkedlist.h*

### Swap

*public void Swap(CUtlLinkedList<T, I> & list)*

*Defined at line 485 of ./mainui/miniutl/utllinkedlist.h*

 swap one list for another

----------------------------------------------------------------------------- Swap one list for another-----------------------------------------------------------------------------

### Alloc

*public I Alloc(_Bool multilist)*

*Defined at line 413 of ./mainui/miniutl/utllinkedlist.h*

 Allocation/deallocation methods If multilist == true, then list list may contain many non-connected lists, and IsInList and Head + Tail are meaningless...

### Free

*public void Free(I elem)*

*Defined at line 422 of ./mainui/miniutl/utllinkedlist.h*

### LinkBefore

*public void LinkBefore(I before, I elem)*

*Defined at line 636 of ./mainui/miniutl/utllinkedlist.h*

 list modification

----------------------------------------------------------------------------- list modification-----------------------------------------------------------------------------

### LinkAfter

*public void LinkAfter(I after, I elem)*

*Defined at line 675 of ./mainui/miniutl/utllinkedlist.h*

### Unlink

*public void Unlink(I elem)*

*Defined at line 714 of ./mainui/miniutl/utllinkedlist.h*

### LinkToHead

*public void LinkToHead(I elem)*

*Defined at line 754 of ./mainui/miniutl/utllinkedlist.h*

### LinkToTail

*public void LinkToTail(I elem)*

*Defined at line 760 of ./mainui/miniutl/utllinkedlist.h*

### InvalidIndex

*public I InvalidIndex()*

*Defined at line 109 of ./mainui/miniutl/utllinkedlist.h*

 invalid index

### ElementSize

*public size_t ElementSize()*

*Defined at line 110 of ./mainui/miniutl/utllinkedlist.h*

### Count

*public int Count()*

*Defined at line 263 of ./mainui/miniutl/utllinkedlist.h*

 list statistics

----------------------------------------------------------------------------- list statistics-----------------------------------------------------------------------------

### IsEmpty

*public _Bool IsEmpty()*

*Defined at line 115 of ./mainui/miniutl/utllinkedlist.h*

### MaxElementIndex

*public I MaxElementIndex()*

*Defined at line 269 of ./mainui/miniutl/utllinkedlist.h*

### Head

*public I Head()*

*Defined at line 280 of ./mainui/miniutl/utllinkedlist.h*

 Traversing the list

----------------------------------------------------------------------------- Traversing the list-----------------------------------------------------------------------------

### First

*public I First()*

*Defined at line 286 of ./mainui/miniutl/utllinkedlist.h*

### Tail

*public I Tail()*

*Defined at line 292 of ./mainui/miniutl/utllinkedlist.h*

### Previous

*public I Previous(I i)*

*Defined at line 298 of ./mainui/miniutl/utllinkedlist.h*

### Next

*public I Next(I i)*

*Defined at line 305 of ./mainui/miniutl/utllinkedlist.h*

### FirstInorder

*public I FirstInorder()*

*Defined at line 130 of ./mainui/miniutl/utllinkedlist.h*

 so we can go through a FOR_EACH_MAP

### NextInorder

*public I NextInorder(I i)*

*Defined at line 131 of ./mainui/miniutl/utllinkedlist.h*

### IteratorNext

*public I IteratorNext(I i)*

*Defined at line 133 of ./mainui/miniutl/utllinkedlist.h*

### IteratorPrev

*public I IteratorPrev(I i)*

*Defined at line 134 of ./mainui/miniutl/utllinkedlist.h*

### IsValidIndex

*public _Bool IsValidIndex(I i)*

*Defined at line 317 of ./mainui/miniutl/utllinkedlist.h*

 Are nodes in the list or valid?

----------------------------------------------------------------------------- Are nodes in the list or valid?-----------------------------------------------------------------------------

### IsInList

*public _Bool IsInList(I i)*

*Defined at line 324 of ./mainui/miniutl/utllinkedlist.h*

### CUtlLinkedListHead

*public I CUtlLinkedListHead()*

*Defined at line 149 of ./mainui/miniutl/utllinkedlist.h*

 The existence of these function let us verify that this is a CUtlLinkedList rather than a CUtlFixedLinkedList, so that the iteration macros can prevent using FOR_EACH_LL on a CUtlFixedLinkedList, with the potentially too-small index var.

### CUtlLinkedListTail

*public I CUtlLinkedListTail()*

*Defined at line 150 of ./mainui/miniutl/utllinkedlist.h*

### AllocInternal

*protected I AllocInternal(_Bool multilist)*

*Defined at line 375 of ./mainui/miniutl/utllinkedlist.h*

 constructs the class

----------------------------------------------------------------------------- Node allocation/deallocation-----------------------------------------------------------------------------

### ConstructList

*protected void ConstructList()*

*Defined at line 221 of ./mainui/miniutl/utllinkedlist.h*

### InternalElement

*protected struct CUtlLinkedList::ListElem_t & InternalElement(I i)*

*Defined at line 170 of ./mainui/miniutl/utllinkedlist.h*

 Gets at the list element....

### InternalElement

*protected const struct CUtlLinkedList::ListElem_t & InternalElement(I i)*

*Defined at line 171 of ./mainui/miniutl/utllinkedlist.h*

### ResetDbgInfo

*protected void ResetDbgInfo()*

*Defined at line 173 of ./mainui/miniutl/utllinkedlist.h*

### CUtlLinkedList<T, I>

*protected void CUtlLinkedList<T, I>(const CUtlLinkedList<T, I> & list)*

 copy constructors not allowed

### operator=

*protected const CUtlLinkedList<T, I> & operator=(const CUtlLinkedList<T, I> & rhs)*



