# class CUtlRBTreeBase

*Defined at line 225 of ./mainui/miniutl/utlrbtree.h*

## Members

protected CUtlRBTreeInternal::Links_t<I> m_Sentinel

protected EmptyBaseOpt_t m_data

protected I m_Root

protected I m_NumElements

protected I m_FirstFree

protected I m_TotalElements



## Records

EmptyBaseOpt_t



## Functions

### CUtlRBTreeBase<I, E>

*public void CUtlRBTreeBase<I, E>()*

*Defined at line 548 of ./mainui/miniutl/utlrbtree.h*

----------------------------------------------------------------------------- constructor, destructor-----------------------------------------------------------------------------

### Count

*public unsigned int Count()*

*Defined at line 700 of ./mainui/miniutl/utlrbtree.h*

 Num elements

----------------------------------------------------------------------------- Num elements-----------------------------------------------------------------------------

### MaxElement

*public I MaxElement()*

*Defined at line 720 of ./mainui/miniutl/utlrbtree.h*

 Max "size" of the vector

----------------------------------------------------------------------------- Max "size" of the vector-----------------------------------------------------------------------------

### Root

*public I Root()*

*Defined at line 690 of ./mainui/miniutl/utlrbtree.h*

 Gets the root

----------------------------------------------------------------------------- Gets the root-----------------------------------------------------------------------------

### IsRoot

*public _Bool IsRoot(I i)*

*Defined at line 804 of ./mainui/miniutl/utlrbtree.h*

 Tests if root or leaf

----------------------------------------------------------------------------- Tests if root or leaf-----------------------------------------------------------------------------

### InvalidIndex

*public I InvalidIndex()*

*Defined at line 244 of ./mainui/miniutl/utlrbtree.h*

 Invalid index

### FirstPreorder

*public I FirstPreorder()*

*Defined at line 1514 of ./mainui/miniutl/utlrbtree.h*

 First pre-order

### PrevPreorder

*public I PrevPreorder(I i)*

*Defined at line 1546 of ./mainui/miniutl/utlrbtree.h*

### _IsValidIndex

*protected _Bool _IsValidIndex(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 830 of ./mainui/miniutl/utlrbtree.h*

 Checks if a node is valid and in the tree

### _Links

*protected const CUtlRBTreeInternal::Links_t<I> & _Links(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 884 of ./mainui/miniutl/utlrbtree.h*

 Gets at the links

----------------------------------------------------------------------------- Gets at the links-----------------------------------------------------------------------------

### _Links

*protected CUtlRBTreeInternal::Links_t<I> & _Links(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 890 of ./mainui/miniutl/utlrbtree.h*

### _Parent

*protected I _Parent(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 737 of ./mainui/miniutl/utlrbtree.h*

 Gets the children                               

### _LeftChild

*protected I _LeftChild(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 750 of ./mainui/miniutl/utlrbtree.h*

### _RightChild

*protected I _RightChild(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 763 of ./mainui/miniutl/utlrbtree.h*

### _SetParent

*protected void _SetParent(I i, I parent, size_t unNodeSize, void * pMemBase)*

*Defined at line 861 of ./mainui/miniutl/utlrbtree.h*

 Sets the children

----------------------------------------------------------------------------- Sets the children-----------------------------------------------------------------------------

### _SetLeftChild

*protected void _SetLeftChild(I i, I child, size_t unNodeSize, void * pMemBase)*

*Defined at line 868 of ./mainui/miniutl/utlrbtree.h*

### _SetRightChild

*protected void _SetRightChild(I i, I child, size_t unNodeSize, void * pMemBase)*

*Defined at line 874 of ./mainui/miniutl/utlrbtree.h*

### _IsRed

*protected _Bool _IsRed(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 901 of ./mainui/miniutl/utlrbtree.h*

----------------------------------------------------------------------------- Checks if a link is red or black-----------------------------------------------------------------------------

### _IsBlack

*protected _Bool _IsBlack(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 907 of ./mainui/miniutl/utlrbtree.h*

### _IsLeftChild

*protected _Bool _IsLeftChild(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 779 of ./mainui/miniutl/utlrbtree.h*

 Tests if a node is a left or right child

### _IsRightChild

*protected _Bool _IsRightChild(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 793 of ./mainui/miniutl/utlrbtree.h*

### _Color

*protected CUtlRBTreeInternal::NodeColor_t _Color(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 918 of ./mainui/miniutl/utlrbtree.h*

 Sets/gets node color

----------------------------------------------------------------------------- Sets/gets node color-----------------------------------------------------------------------------

### _SetColor

*protected void _SetColor(I i, CUtlRBTreeInternal::NodeColor_t c, size_t unNodeSize, void * pMemBase)*

*Defined at line 924 of ./mainui/miniutl/utlrbtree.h*

### _RotateLeft

*protected void _RotateLeft(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 980 of ./mainui/miniutl/utlrbtree.h*

----------------------------------------------------------------------------- Rotates node i to the left-----------------------------------------------------------------------------

### _RotateRight

*protected void _RotateRight(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 1012 of ./mainui/miniutl/utlrbtree.h*

----------------------------------------------------------------------------- Rotates node i to the right-----------------------------------------------------------------------------

### _InsertRebalance

*protected void _InsertRebalance(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 1044 of ./mainui/miniutl/utlrbtree.h*

----------------------------------------------------------------------------- Rebalances the tree after an insertion-----------------------------------------------------------------------------

### _RemoveRebalance

*protected void _RemoveRebalance(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 1159 of ./mainui/miniutl/utlrbtree.h*

----------------------------------------------------------------------------- Rebalance the tree after a deletion-----------------------------------------------------------------------------

### _Unlink

*protected void _Unlink(I elem, size_t unNodeSize, void * pMemBase)*

*Defined at line 1249 of ./mainui/miniutl/utlrbtree.h*

### _LinkToParent

*protected void _LinkToParent(I i, I parent, _Bool isLeft, size_t unNodeSize, void * pMemBase)*

*Defined at line 1128 of ./mainui/miniutl/utlrbtree.h*

 Sets the children

### _IsValid

*protected _Bool _IsValid(size_t unNodeSize, void * pMemBase)*

*Defined at line 1668 of ./mainui/miniutl/utlrbtree.h*

 Checks if the tree as a whole is valid

### _FirstInorder

*protected I _FirstInorder(size_t unNodeSize, void * pMemBase)*

*Defined at line 1430 of ./mainui/miniutl/utlrbtree.h*

### _NextInorder

*protected I _NextInorder(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 1446 of ./mainui/miniutl/utlrbtree.h*

### _PrevInorder

*protected I _PrevInorder(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 1476 of ./mainui/miniutl/utlrbtree.h*

### _LastInorder

*protected I _LastInorder(size_t unNodeSize, void * pMemBase)*

*Defined at line 1505 of ./mainui/miniutl/utlrbtree.h*

### _NextPreorder

*protected I _NextPreorder(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 1526 of ./mainui/miniutl/utlrbtree.h*

### _LastPreorder

*protected I _LastPreorder(size_t unNodeSize, void * pMemBase)*

*Defined at line 1559 of ./mainui/miniutl/utlrbtree.h*

### _FirstPostorder

*protected I _FirstPostorder(size_t unNodeSize, void * pMemBase)*

*Defined at line 1582 of ./mainui/miniutl/utlrbtree.h*

### _NextPostorder

*protected I _NextPostorder(I i, size_t unNodeSize, void * pMemBase)*

*Defined at line 1602 of ./mainui/miniutl/utlrbtree.h*

### _Depth

*protected int _Depth(I node, size_t unNodeSize, void * pMemBase)*

*Defined at line 1646 of ./mainui/miniutl/utlrbtree.h*

### ResetDbgInfo

*protected void ResetDbgInfo(void * pMemBase)*

*Defined at line 318 of ./mainui/miniutl/utlrbtree.h*



