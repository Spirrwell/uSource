# class CNodeViewer

*Defined at line 3566 of ./game/server/info_node.cpp*

========================================================= CNodeViewer - Draws a graph of the shorted path from all nodes to current location (typically the player).  It then draws as many connects as it can per frame, trying not to overflow the buffer=========================================================



Inherits from CBaseEntity



## Members

public int m_iBaseNode

public int m_iDraw

public int m_nVisited

public int [128] m_aFrom

public int [128] m_aTo

public int m_iHull

public int m_afNodeType

Vector m_vecColor



## Functions

### Spawn

*public void Spawn()*

*Defined at line 3590 of ./game/server/info_node.cpp*

### FindNodeConnections

*public void FindNodeConnections(int iNode)*

*Defined at line 3663 of ./game/server/info_node.cpp*

### AddNode

*public void AddNode(int iFrom, int iTo)*

*Defined at line 3673 of ./game/server/info_node.cpp*

### DrawThink

*public void DrawThink()*

*Defined at line 3697 of ./game/server/info_node.cpp*



