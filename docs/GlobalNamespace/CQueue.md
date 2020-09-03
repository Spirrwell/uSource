# class CQueue

*Defined at line 303 of ./game/server/info_node.h*

========================================================= CQueue - first in, first out.=========================================================



## Members

private int m_cSize

private struct tag_QUEUE_NODE [100] m_queue

private int m_head

private int m_tail



## Records

tag_QUEUE_NODE



## Functions

### CQueue

*public void CQueue()*

*Defined at line 2223 of ./game/server/info_node.cpp*

========================================================= CQueue constructor=========================================================

### Full

*public int Full()*

*Defined at line 308 of ./game/server/info_node.h*

### Empty

*public int Empty()*

*Defined at line 309 of ./game/server/info_node.h*

### Size

*public int Size()*

*Defined at line 311 of ./game/server/info_node.h*

inline int Tail ( void ) { return ( m_queue[ m_tail ] ); }

### Insert

*public void Insert(int , float )*

*Defined at line 2233 of ./game/server/info_node.cpp*

========================================================= inserts a value into the queue=========================================================

### Remove

*public int Remove(float & )*

*Defined at line 2257 of ./game/server/info_node.cpp*

========================================================= removes a value from the queue (FIFO)=========================================================



