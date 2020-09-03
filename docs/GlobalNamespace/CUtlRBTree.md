# class CUtlRBTree

*Defined at line 334 of ./mainui/miniutl/utlrbtree.h*

----------------------------------------------------------------------------- A red-black binary search tree-----------------------------------------------------------------------------



Inherits from CUtlRBTreeBase<I, E>



## Members

protected CUtlRBTree::LessFunc_t m_LessFunc

protected CUtlMemory<struct CUtlRBTree::Node_t> m_Elements



## Records

ProxyTypeIterateUnordered

Node_t



## Functions

### CUtlRBTree<T, I, L, E>

*public void CUtlRBTree<T, I, L, E>(int growSize, int initSize, const CUtlRBTree::LessFunc_t & lessfunc)*

*Defined at line 560 of ./mainui/miniutl/utlrbtree.h*

 constructor, destructor Left at growSize = 0, the memory will first allocate 1 element and double in size at each increment. LessFunc_t is required, but may be set after the constructor using SetLessFunc() below

### CUtlRBTree<T, I, L, E>

*public void CUtlRBTree<T, I, L, E>(const CUtlRBTree::LessFunc_t & lessfunc)*

*Defined at line 569 of ./mainui/miniutl/utlrbtree.h*

### CUtlRBTree<T, I, L, E>

*public void CUtlRBTree<T, I, L, E>(const CUtlRBTree::BalanceListener_t & eventListener)*

*Defined at line 578 of ./mainui/miniutl/utlrbtree.h*

### ~CUtlRBTree<T, I, L, E>

*public void ~CUtlRBTree<T, I, L, E>()*

*Defined at line 588 of ./mainui/miniutl/utlrbtree.h*

### NumAllocated

*public unsigned int NumAllocated()*

*Defined at line 710 of ./mainui/miniutl/utlrbtree.h*

----------------------------------------------------------------------------- Num elements allocated-----------------------------------------------------------------------------

### Element

*public T & Element(I i)*

*Defined at line 598 of ./mainui/miniutl/utlrbtree.h*

 gets particular elements

----------------------------------------------------------------------------- gets particular elements-----------------------------------------------------------------------------

### Element

*public const T & Element(I i)*

*Defined at line 604 of ./mainui/miniutl/utlrbtree.h*

### operator[]

*public T & operator[](I i)*

*Defined at line 610 of ./mainui/miniutl/utlrbtree.h*

### operator[]

*public const T & operator[](I i)*

*Defined at line 616 of ./mainui/miniutl/utlrbtree.h*

### ElementByLinearIndex

*public T & ElementByLinearIndex(CUtlRBTree::IndexType_t i)*

*Defined at line 622 of ./mainui/miniutl/utlrbtree.h*

### ElementByLinearIndex

*public const T & ElementByLinearIndex(CUtlRBTree::IndexType_t i)*

*Defined at line 638 of ./mainui/miniutl/utlrbtree.h*

### operator=

*public CUtlRBTree<T, I, L, E> & operator=(const CUtlRBTree<T, I, L, E> & other)*

*Defined at line 663 of ./mainui/miniutl/utlrbtree.h*

### Parent

*public I Parent(I i)*

*Defined at line 731 of ./mainui/miniutl/utlrbtree.h*

 Gets the children                               

----------------------------------------------------------------------------- Gets the children                               -----------------------------------------------------------------------------

### LeftChild

*public I LeftChild(I i)*

*Defined at line 744 of ./mainui/miniutl/utlrbtree.h*

### RightChild

*public I RightChild(I i)*

*Defined at line 757 of ./mainui/miniutl/utlrbtree.h*

### IsLeftChild

*public _Bool IsLeftChild(I i)*

*Defined at line 773 of ./mainui/miniutl/utlrbtree.h*

 Tests if a node is a left or right child

----------------------------------------------------------------------------- Tests if a node is a left or right child-----------------------------------------------------------------------------

### IsRightChild

*public _Bool IsRightChild(I i)*

*Defined at line 787 of ./mainui/miniutl/utlrbtree.h*

### IsLeaf

*public _Bool IsLeaf(I i)*

*Defined at line 810 of ./mainui/miniutl/utlrbtree.h*

 Tests if root or leaf

### IsValidIndex

*public _Bool IsValidIndex(I i)*

*Defined at line 824 of ./mainui/miniutl/utlrbtree.h*

 Checks if a node is valid and in the tree

----------------------------------------------------------------------------- Checks if a node is valid and in the tree the sign-comparison supression is due to comparing index val < 0, which is never true for unsigned types, but specializing the template seems like overkill-----------------------------------------------------------------------------

### IsValidLinearIndex

*public _Bool IsValidLinearIndex(I i)*

*Defined at line 656 of ./mainui/miniutl/utlrbtree.h*

 Checks if a index is of range 0 to Count()-1

### IsValid

*public _Bool IsValid()*

*Defined at line 1662 of ./mainui/miniutl/utlrbtree.h*

 Checks if the tree as a whole is valid

----------------------------------------------------------------------------- Makes sure the tree is valid after every operation-----------------------------------------------------------------------------

### Depth

*public int Depth(I node)*

*Defined at line 1640 of ./mainui/miniutl/utlrbtree.h*

 returns the tree depth (not a very fast operation)

----------------------------------------------------------------------------- returns the tree depth (not a very fast operation)-----------------------------------------------------------------------------

### Depth

*public int Depth()*

*Defined at line 851 of ./mainui/miniutl/utlrbtree.h*

----------------------------------------------------------------------------- returns the tree depth (not a very fast operation)-----------------------------------------------------------------------------

### SetLessFunc

*public void SetLessFunc(const CUtlRBTree::LessFunc_t & func)*

*Defined at line 1744 of ./mainui/miniutl/utlrbtree.h*

 Sets the less func

----------------------------------------------------------------------------- Sets the less func-----------------------------------------------------------------------------

### NewNode

*public I NewNode(_Bool bConstructElement)*

*Defined at line 934 of ./mainui/miniutl/utlrbtree.h*

 Allocation method

----------------------------------------------------------------------------- Allocates/ deallocates nodes-----------------------------------------------------------------------------

### Insert

*public I Insert(const T & insert, _Bool bInsertDuplicates)*

*Defined at line 1792 of ./mainui/miniutl/utlrbtree.h*

 Insert method (inserts in order)

### Insert

*public void Insert(const T * pArray, int nItems, _Bool bInsertDuplicates)*

*Defined at line 1838 of ./mainui/miniutl/utlrbtree.h*

### InsertIfNotFound

*public I InsertIfNotFound(const T & insert)*

*Defined at line 1816 of ./mainui/miniutl/utlrbtree.h*

 Insert with not found interface to match source engine branches

### FindOrInsert

*public I FindOrInsert(const T & insert)*

*Defined at line 1848 of ./mainui/miniutl/utlrbtree.h*

 FindOrInsert method (returns existing index, or inserts if not found)

### Find

*public I Find(const T & search)*

*Defined at line 1884 of ./mainui/miniutl/utlrbtree.h*

 Find method

----------------------------------------------------------------------------- finds a node in the tree-----------------------------------------------------------------------------

### FindFirst

*public I FindFirst(const T & search)*

*Defined at line 1907 of ./mainui/miniutl/utlrbtree.h*

 FindFirst method ( finds first inorder if there are duplicates )

----------------------------------------------------------------------------- finds a the first node (inorder) with this key in the tree-----------------------------------------------------------------------------

### FindClosest

*public I FindClosest(const T & search, enum CompareOperands_t eFindCriteria)*

*Defined at line 1949 of ./mainui/miniutl/utlrbtree.h*

 First element >= key

----------------------------------------------------------------------------- finds the closest node to the key supplied-----------------------------------------------------------------------------

### RemoveAt

*public void RemoveAt(I i)*

*Defined at line 1351 of ./mainui/miniutl/utlrbtree.h*

 Remove methods

----------------------------------------------------------------------------- Delete a node from the tree-----------------------------------------------------------------------------

### Remove

*public _Bool Remove(const T & remove)*

*Defined at line 1369 of ./mainui/miniutl/utlrbtree.h*

----------------------------------------------------------------------------- remove a node in the tree-----------------------------------------------------------------------------

### RemoveAll

*public void RemoveAll()*

*Defined at line 1385 of ./mainui/miniutl/utlrbtree.h*

----------------------------------------------------------------------------- Removes all nodes from the tree-----------------------------------------------------------------------------

### Purge

*public void Purge()*

*Defined at line 1411 of ./mainui/miniutl/utlrbtree.h*

----------------------------------------------------------------------------- purge-----------------------------------------------------------------------------

### HasElement

*public _Bool HasElement(const T & search)*

*Defined at line 1873 of ./mainui/miniutl/utlrbtree.h*

----------------------------------------------------------------------------- returns true if the node exists in the tree-----------------------------------------------------------------------------

### FreeNode

*public void FreeNode(I i)*

*Defined at line 965 of ./mainui/miniutl/utlrbtree.h*

 Allocation, deletion

### FirstInorder

*public I FirstInorder()*

*Defined at line 1424 of ./mainui/miniutl/utlrbtree.h*

 Iteration

----------------------------------------------------------------------------- iteration-----------------------------------------------------------------------------

### NextInorder

*public I NextInorder(I i)*

*Defined at line 1440 of ./mainui/miniutl/utlrbtree.h*

### PrevInorder

*public I PrevInorder(I i)*

*Defined at line 1469 of ./mainui/miniutl/utlrbtree.h*

### LastInorder

*public I LastInorder()*

*Defined at line 1499 of ./mainui/miniutl/utlrbtree.h*

### NextPreorder

*public I NextPreorder(I i)*

*Defined at line 1520 of ./mainui/miniutl/utlrbtree.h*

### LastPreorder

*public I LastPreorder()*

*Defined at line 1553 of ./mainui/miniutl/utlrbtree.h*

### FirstPostorder

*public I FirstPostorder()*

*Defined at line 1576 of ./mainui/miniutl/utlrbtree.h*

### NextPostorder

*public I NextPostorder(I i)*

*Defined at line 1596 of ./mainui/miniutl/utlrbtree.h*

### Reinsert

*public void Reinsert(I elem)*

*Defined at line 1628 of ./mainui/miniutl/utlrbtree.h*

 If you change the search key, this can be used to reinsert the  element into the tree.

### Swap

*public void Swap(CUtlRBTree<T, I, L, E> & that)*

*Defined at line 1933 of ./mainui/miniutl/utlrbtree.h*

 swap in place

----------------------------------------------------------------------------- swap in place-----------------------------------------------------------------------------

### InsertAt

*public I InsertAt(I parent, _Bool leftchild, _Bool bConstructElement)*

*Defined at line 1119 of ./mainui/miniutl/utlrbtree.h*

 If you build a container on top of RBTree you need this - otherwise you shouldnt use Insertion, removal

----------------------------------------------------------------------------- Insert a node into the tree-----------------------------------------------------------------------------

### FindInsertionPosition

*public void FindInsertionPosition(const T & insert, _Bool bCheckForDuplicates, I & parent, _Bool & leftchild, _Bool & isDuplicate)*

*Defined at line 1762 of ./mainui/miniutl/utlrbtree.h*

 If you build a container on top of RBTree you need this - otherwise you shouldnt use Inserts a node into the tree, doesn't copy the data in.

 Inserts a node into the tree, doesn't copy the data in.

### EnsureCapacity

*public void EnsureCapacity(int num)*

*Defined at line 1998 of ./mainui/miniutl/utlrbtree.h*

 Makes sure we have enough memory allocated to store a requested # of elements

----------------------------------------------------------------------------- Makes sure we have enough memory allocated to store a requested # of elements-----------------------------------------------------------------------------

### CubAllocated

*public int CubAllocated()*

*Defined at line 459 of ./mainui/miniutl/utlrbtree.h*

### IteratorNext

*public I IteratorNext(I i)*

*Defined at line 461 of ./mainui/miniutl/utlrbtree.h*

### IteratorPrev

*public I IteratorPrev(I i)*

*Defined at line 462 of ./mainui/miniutl/utlrbtree.h*

### IterateUnordered

*public struct CUtlRBTree::ProxyTypeIterateUnordered & IterateUnordered()*

*Defined at line 481 of ./mainui/miniutl/utlrbtree.h*

### IterateUnordered

*public const struct CUtlRBTree::ProxyTypeIterateUnordered & IterateUnordered()*

*Defined at line 482 of ./mainui/miniutl/utlrbtree.h*

### BDiffRBTrees

*public _Bool BDiffRBTrees(const CUtlRBTree<T, I, L, E> & rbTreeBase, const CUtlRBTree<T, I, L, E> & rbTreeCompare, CUtlRBTree<T, I, L, E> * prbTreeAdditions, CUtlRBTree<T, I, L, E> * prbTreeDeletions)*

*Defined at line 2010 of ./mainui/miniutl/utlrbtree.h*

----------------------------------------------------------------------------- Purpose: Utility function for diffing RBTrees-----------------------------------------------------------------------------

### Links

*protected const CUtlRBTreeInternal::Links_t<I> & Links(I i)*

*Defined at line 504 of ./mainui/miniutl/utlrbtree.h*

 Inline functions that just pass straight into base, but with extra params.  

 This is done so the bulk of the code can be in the base class, but interfaces to  these within child class code can be sane.

### Links

*protected CUtlRBTreeInternal::Links_t<I> & Links(I i)*

*Defined at line 505 of ./mainui/miniutl/utlrbtree.h*

### SetParent

*protected void SetParent(I i, I parent)*

*Defined at line 507 of ./mainui/miniutl/utlrbtree.h*

### SetLeftChild

*protected void SetLeftChild(I i, I child)*

*Defined at line 508 of ./mainui/miniutl/utlrbtree.h*

### SetRightChild

*protected void SetRightChild(I i, I child)*

*Defined at line 509 of ./mainui/miniutl/utlrbtree.h*

### IsRed

*protected _Bool IsRed(I i)*

*Defined at line 512 of ./mainui/miniutl/utlrbtree.h*

 Checks if a link is red or black

### IsBlack

*protected _Bool IsBlack(I i)*

*Defined at line 513 of ./mainui/miniutl/utlrbtree.h*

### Color

*protected CUtlRBTreeInternal::NodeColor_t Color(I i)*

*Defined at line 516 of ./mainui/miniutl/utlrbtree.h*

 Sets/gets node color

### SetColor

*protected void SetColor(I i, CUtlRBTreeInternal::NodeColor_t c)*

*Defined at line 517 of ./mainui/miniutl/utlrbtree.h*

### RotateLeft

*protected void RotateLeft(I i)*

*Defined at line 520 of ./mainui/miniutl/utlrbtree.h*

 operations required to preserve tree balance

### RotateRight

*protected void RotateRight(I i)*

*Defined at line 521 of ./mainui/miniutl/utlrbtree.h*

### InsertRebalance

*protected void InsertRebalance(I i)*

*Defined at line 522 of ./mainui/miniutl/utlrbtree.h*

### RemoveRebalance

*protected void RemoveRebalance(I i)*

*Defined at line 523 of ./mainui/miniutl/utlrbtree.h*

### Unlink

*protected void Unlink(I elem)*

*Defined at line 525 of ./mainui/miniutl/utlrbtree.h*

### LinkToParent

*protected void LinkToParent(I i, I parent, _Bool isLeft)*

*Defined at line 528 of ./mainui/miniutl/utlrbtree.h*

 Sets the children

### CUtlRBTree<T, I, L, E>

*protected void CUtlRBTree<T, I, L, E>(const CUtlRBTree<T, I, L, E> & tree)*

 copy constructors not allowed

### Link

*protected void Link(I elem)*

*Defined at line 1332 of ./mainui/miniutl/utlrbtree.h*

 Remove and add back an element in the tree.



