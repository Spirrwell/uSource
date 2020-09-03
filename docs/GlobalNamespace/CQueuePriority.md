# class CQueuePriority

*Defined at line 330 of ./game/server/info_node.h*

========================================================= CQueuePriority - Priority queue (smallest item out first).

=========================================================



## Members

private int m_cSize

private struct tag_HEAP_NODE [100] m_heap



## Records

tag_HEAP_NODE



## Functions

### CQueuePriority

*public void CQueuePriority()*

*Defined at line 2273 of ./game/server/info_node.cpp*

========================================================= CQueue constructor=========================================================

### Full

*public int Full()*

*Defined at line 335 of ./game/server/info_node.h*

### Empty

*public int Empty()*

*Defined at line 336 of ./game/server/info_node.h*

### Size

*public int Size()*

*Defined at line 338 of ./game/server/info_node.h*

inline int Tail ( float & ) { return ( m_queue[ m_tail ].Id ); }

### Insert

*public void Insert(int , float )*

*Defined at line 2281 of ./game/server/info_node.cpp*

========================================================= inserts a value into the priority queue=========================================================

### Remove

*public int Remove(float & )*

*Defined at line 2299 of ./game/server/info_node.cpp*

========================================================= removes the smallest item from the priority queue

=========================================================

### Heap_SiftDown

*private void Heap_SiftDown(int )*

*Defined at line 2316 of ./game/server/info_node.cpp*

### Heap_SiftUp

*private void Heap_SiftUp()*

*Defined at line 2343 of ./game/server/info_node.cpp*



