# class CStack

*Defined at line 284 of ./game/server/info_node.h*

========================================================= CStack - last in, first out.=========================================================



## Members

private int [100] m_stack

private int m_level



## Functions

### CStack

*public void CStack()*

*Defined at line 2168 of ./game/server/info_node.cpp*

========================================================= CStack Constructor=========================================================

### Push

*public void Push(int value)*

*Defined at line 2176 of ./game/server/info_node.cpp*

========================================================= pushes a value onto the stack=========================================================

### Pop

*public int Pop()*

*Defined at line 2190 of ./game/server/info_node.cpp*

========================================================= pops a value off of the stack=========================================================

### Top

*public int Top()*

*Defined at line 2202 of ./game/server/info_node.cpp*

========================================================= returns the value on the top of the stack=========================================================

### Empty

*public int Empty()*

*Defined at line 291 of ./game/server/info_node.h*

### Size

*public int Size()*

*Defined at line 292 of ./game/server/info_node.h*

### CopyToArray

*public void CopyToArray(int * piArray)*

*Defined at line 2210 of ./game/server/info_node.cpp*

========================================================= copies every element on the stack into an array LIFO =========================================================



