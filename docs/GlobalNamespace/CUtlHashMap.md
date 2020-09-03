# class CUtlHashMap

*Defined at line 64 of ./mainui/miniutl/utlhashmap.h*

-----------------------------------------------------------------------------

 Purpose:	An associative container.  Similar to std::unordered_map, but without STL's rather wacky interface.  Also, each item is not a separate allocation, so insertion of items can cause existing items to move in memory.

 This differs from the one in Steam by not having any default hash or equality class.  We will use std::hash and std::equal_to insetad of our own hand-rolled versions, which I suspect do not add any value (any more at least).  Valve's CDefEquals unfortunately is not exactly the same as std::equal_to in the way it handles pointers, so let's require the few uses of hashmaps in use to be explicit in the equality operation.

-----------------------------------------------------------------------------



## Members

protected CUtlVector<struct CUtlHashMap::HashBucket_t> m_vecHashBuckets

CBitString m_bitsMigratedBuckets

protected CUtlMemory<struct CUtlHashMap::Node_t> m_memNodes

protected CUtlHashMap::IndexType_t m_iNodeFreeListHead

protected CUtlHashMap::IndexType_t m_cElements

protected CUtlHashMap::IndexType_t m_nMaxElement

protected CUtlHashMap::IndexType_t m_nMinRehashedBucket

protected CUtlHashMap::IndexType_t m_nMaxRehashedBucket

protected CUtlHashMap::EqualityFunc_t m_EqualityFunc

protected CUtlHashMap::HashFunc_t m_HashFunc



## Records

HashBucket_t

Node_t

IterateKeyElemProxyAlias



## Functions

### CUtlHashMap<K, T, L, H>

*public void CUtlHashMap<K, T, L, H>()*

*Defined at line 73 of ./mainui/miniutl/utlhashmap.h*

### CUtlHashMap<K, T, L, H>

*public void CUtlHashMap<K, T, L, H>(int cElementsExpected)*

*Defined at line 82 of ./mainui/miniutl/utlhashmap.h*

### ~CUtlHashMap<K, T, L, H>

*public void ~CUtlHashMap<K, T, L, H>()*

*Defined at line 92 of ./mainui/miniutl/utlhashmap.h*

### CopyFullHashMap

*public void CopyFullHashMap(CUtlHashMap<K, T, L, H> & target)*

*Defined at line 97 of ./mainui/miniutl/utlhashmap.h*

### Element

*public CUtlHashMap::ElemType_t & Element(CUtlHashMap::IndexType_t i)*

*Defined at line 107 of ./mainui/miniutl/utlhashmap.h*

 gets particular elements

### Element

*public const CUtlHashMap::ElemType_t & Element(CUtlHashMap::IndexType_t i)*

*Defined at line 108 of ./mainui/miniutl/utlhashmap.h*

### operator[]

*public CUtlHashMap::ElemType_t & operator[](CUtlHashMap::IndexType_t i)*

*Defined at line 109 of ./mainui/miniutl/utlhashmap.h*

### operator[]

*public const CUtlHashMap::ElemType_t & operator[](CUtlHashMap::IndexType_t i)*

*Defined at line 110 of ./mainui/miniutl/utlhashmap.h*

### Key

*public CUtlHashMap::KeyType_t & Key(CUtlHashMap::IndexType_t i)*

*Defined at line 111 of ./mainui/miniutl/utlhashmap.h*

### Key

*public const CUtlHashMap::KeyType_t & Key(CUtlHashMap::IndexType_t i)*

*Defined at line 112 of ./mainui/miniutl/utlhashmap.h*

### Count

*public CUtlHashMap::IndexType_t Count()*

*Defined at line 115 of ./mainui/miniutl/utlhashmap.h*

 Num elements

### MaxElement

*public CUtlHashMap::IndexType_t MaxElement()*

*Defined at line 118 of ./mainui/miniutl/utlhashmap.h*

 Max "size" of the vector

### IsValidIndex

*public _Bool IsValidIndex(CUtlHashMap::IndexType_t i)*

*Defined at line 121 of ./mainui/miniutl/utlhashmap.h*

 Checks if a node is valid and in the map

### InvalidIndex

*public CUtlHashMap::IndexType_t InvalidIndex()*

*Defined at line 124 of ./mainui/miniutl/utlhashmap.h*

 Invalid index

### Insert

*public CUtlHashMap::IndexType_t Insert(const CUtlHashMap::KeyType_t & key)*

*Defined at line 127 of ./mainui/miniutl/utlhashmap.h*

 Insert method

### Insert

*public CUtlHashMap::IndexType_t Insert(const CUtlHashMap::KeyType_t & key, const CUtlHashMap::ElemType_t & insert)*

*Defined at line 128 of ./mainui/miniutl/utlhashmap.h*

### InsertOrReplace

*public CUtlHashMap::IndexType_t InsertOrReplace(const CUtlHashMap::KeyType_t & key)*

*Defined at line 361 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: inserts an item into the map, replaces existing item with same key-----------------------------------------------------------------------------

### InsertOrReplace

*public CUtlHashMap::IndexType_t InsertOrReplace(const CUtlHashMap::KeyType_t & key, const CUtlHashMap::ElemType_t & insert)*

*Defined at line 378 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: inserts an item into the map, replaces existing item with same key-----------------------------------------------------------------------------

### InsertWithDupes

*public CUtlHashMap::IndexType_t InsertWithDupes(const CUtlHashMap::KeyType_t & key, const CUtlHashMap::ElemType_t & insert)*

*Defined at line 395 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: inserts element no matter what, even if key already exists-----------------------------------------------------------------------------

### FindOrInsert

*public CUtlHashMap::IndexType_t FindOrInsert(const CUtlHashMap::KeyType_t & key)*

*Defined at line 327 of ./mainui/miniutl/utlhashmap.h*

 Find-or-insert method, one-arg - can insert default-constructed element when there is no available copy constructor or assignment operator

----------------------------------------------------------------------------- Purpose: inserts a default item into the map, no change if key already exists-----------------------------------------------------------------------------

### FindOrInsert

*public CUtlHashMap::IndexType_t FindOrInsert(const CUtlHashMap::KeyType_t & key, const CUtlHashMap::ElemType_t & insert)*

*Defined at line 344 of ./mainui/miniutl/utlhashmap.h*

 Find-or-insert method, two-arg - can insert an element when there is no copy constructor for the type (but does require assignment operator)

----------------------------------------------------------------------------- Purpose: inserts an item into the map, no change if key already exists-----------------------------------------------------------------------------

### Find

*public CUtlHashMap::IndexType_t Find(const CUtlHashMap::KeyType_t & key)*

*Defined at line 511 of ./mainui/miniutl/utlhashmap.h*

 Finds an element

----------------------------------------------------------------------------- Purpose: searches for an item by key, returning the index handle-----------------------------------------------------------------------------

### FindExact

*public CUtlHashMap::IndexType_t FindExact(const CUtlHashMap::KeyType_t & key, const CUtlHashMap::ElemType_t & elem)*

*Defined at line 555 of ./mainui/miniutl/utlhashmap.h*

 Finds an exact key/value match, even with duplicate keys. Requires operator== for ElemType_t.

----------------------------------------------------------------------------- Purpose: searches for an item by key and element equality, returning the index handle-----------------------------------------------------------------------------

### NextSameKey

*public CUtlHashMap::IndexType_t NextSameKey(CUtlHashMap::IndexType_t i)*

*Defined at line 572 of ./mainui/miniutl/utlhashmap.h*

 Find next element with same key

----------------------------------------------------------------------------- Purpose: find the next element with the same key, if insertwithdupes was used-----------------------------------------------------------------------------

### HasElement

*public _Bool HasElement(const CUtlHashMap::KeyType_t & key)*

*Defined at line 151 of ./mainui/miniutl/utlhashmap.h*

 has an element

### EnsureCapacity

*public void EnsureCapacity(int num)*

*Defined at line 410 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: grows the map to fit the specified amount-----------------------------------------------------------------------------

### FindElement

*public const CUtlHashMap::ElemType_t & FindElement(const CUtlHashMap::KeyType_t & key, const CUtlHashMap::ElemType_t & defaultValue)*

*Defined at line 155 of ./mainui/miniutl/utlhashmap.h*

### RemoveAt

*public void RemoveAt(CUtlHashMap::IndexType_t i)*

*Defined at line 664 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: removes a single item from the map-----------------------------------------------------------------------------

### Remove

*public _Bool Remove(const CUtlHashMap::KeyType_t & key)*

*Defined at line 164 of ./mainui/miniutl/utlhashmap.h*

### RemoveAll

*public void RemoveAll()*

*Defined at line 737 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: removes all items from the hash map-----------------------------------------------------------------------------

### Purge

*public void Purge()*

*Defined at line 762 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: removes all items from the hash map and frees all memory-----------------------------------------------------------------------------

### PurgeAndDeleteElements

*public void PurgeAndDeleteElements()*

*Defined at line 178 of ./mainui/miniutl/utlhashmap.h*

 call delete on each element (as a pointer) and then purge

### Swap

*public void Swap(CUtlHashMap<K, T, L, H> & that)*

*Defined at line 824 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: swaps with another hash map-----------------------------------------------------------------------------

### InsertUnconstructed

*protected CUtlHashMap::IndexType_t InsertUnconstructed(const CUtlHashMap::KeyType_t & key, CUtlHashMap::IndexType_t * pExistingIndex, _Bool bAllowDupes)*

*Defined at line 258 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: inserts a key into the map with an unconstructed element member (to be copy constructed or default-constructed by a wrapper function)-----------------------------------------------------------------------------

### FreeNodeIDToIndex

*protected CUtlHashMap::IndexType_t FreeNodeIDToIndex(CUtlHashMap::IndexType_t i)*

*Defined at line 190 of ./mainui/miniutl/utlhashmap.h*

### FreeNodeIndexToID

*protected CUtlHashMap::IndexType_t FreeNodeIndexToID(CUtlHashMap::IndexType_t i)*

*Defined at line 191 of ./mainui/miniutl/utlhashmap.h*

### IsFreeNodeID

*protected _Bool IsFreeNodeID(CUtlHashMap::IndexType_t i)*

*Defined at line 192 of ./mainui/miniutl/utlhashmap.h*

### FindInBucket

*protected int FindInBucket(int iBucket, const CUtlHashMap::KeyType_t & key)*

*Defined at line 596 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: searches for an item by key, returning the index handle-----------------------------------------------------------------------------

### AllocNode

*protected int AllocNode()*

*Defined at line 452 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: gets a new node, from the free list if possible-----------------------------------------------------------------------------

### RehashNodesInBucket

*protected void RehashNodesInBucket(int iBucket)*

*Defined at line 474 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: takes a bucket of nodes and re-hashes them into a more optimal bucket-----------------------------------------------------------------------------

### LinkNodeIntoBucket

*protected void LinkNodeIntoBucket(int iBucket, int iNewNode)*

*Defined at line 620 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: links a node into a bucket-----------------------------------------------------------------------------

### UnlinkNodeFromBucket

*protected void UnlinkNodeFromBucket(int iBucket, int iNewNode)*

*Defined at line 632 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: unlinks a node from the bucket-----------------------------------------------------------------------------

### RemoveNodeFromBucket

*protected _Bool RemoveNodeFromBucket(int iBucket, int iNodeToRemove)*

*Defined at line 703 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: removes a node from the bucket, return true if it was found-----------------------------------------------------------------------------

### IncrementalRehash

*protected void IncrementalRehash()*

*Defined at line 788 of ./mainui/miniutl/utlhashmap.h*

----------------------------------------------------------------------------- Purpose: rehashes buckets-----------------------------------------------------------------------------



