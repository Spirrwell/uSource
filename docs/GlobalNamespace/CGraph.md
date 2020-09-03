# class CGraph

*Defined at line 117 of ./game/server/info_node.h*

## Members

public BOOL m_fGraphPresent

public BOOL m_fGraphPointersSet

public BOOL m_fRoutingComplete

public class CNode * m_pNodes

public class CLink * m_pLinkPool

public signed char * m_pRouteInfo

public int m_cNodes

public int m_cLinks

public int m_nRouteInfo

public DIST_INFO * m_di

public int [3][256] m_RangeStart

public int [3][256] m_RangeEnd

public float m_flShortest

public int m_iNearest

public int m_minX

public int m_minY

public int m_minZ

public int m_maxX

public int m_maxY

public int m_maxZ

public int m_minBoxX

public int m_minBoxY

public int m_minBoxZ

public int m_maxBoxX

public int m_maxBoxY

public int m_maxBoxZ

public int m_CheckedCounter

public float [3] m_RegionMin

public float [3] m_RegionMax

public CACHE_ENTRY [128] m_Cache

public int [16] m_HashPrimes

public short * m_pHashLinks

public int m_nHashLinks

public int m_iLastActiveIdleSearch

public int m_iLastCoverSearch



## Functions

### LinkVisibleNodes

*public int LinkVisibleNodes(class CLink * pLinkPool, FILE * file, int * piBadNode)*

*Defined at line 1190 of ./game/server/info_node.cpp*

 functions to create the graph

========================================================= CGraph - LinkVisibleNodes - the first, most basic function of node graph creation, this connects every node to every other node that it can see. Expects a  pointer to an empty connection pool and a file pointer  to write progress to. Returns the total number of initial links.

 If there's a problem with this process, the index of the offending node will be written to piBadNode=========================================================

### RejectInlineLinks

*public int RejectInlineLinks(class CLink * pLinkPool, FILE * file)*

*Defined at line 1388 of ./game/server/info_node.cpp*

========================================================= CGraph - RejectInlineLinks - expects a pointer to a link pool, and a pointer to and already-open file ( if you want status reports written to disk ). RETURNS the number of connections that were rejected=========================================================

### FindShortestPath

*public int FindShortestPath(int * piPath, int iStart, int iDest, int iHull, int afCapMask)*

*Defined at line 585 of ./game/server/info_node.cpp*

========================================================= CGraph - FindShortestPath 

 accepts a capability mask (afCapMask), and will only  find a path usable by a monster with those capabilities returns the number of nodes copied into supplied array=========================================================

### FindNearestNode

*public int FindNearestNode(const class Vector & vecOrigin, class CBaseEntity * pEntity)*

*Defined at line 869 of ./game/server/info_node.cpp*

========================================================= CGraph - FindNearestNode - returns the index of the node nearest the given vector -1 is failure (couldn't find a valid near node )=========================================================

### FindNearestNode

*public int FindNearestNode(const class Vector & vecOrigin, int afNodeTypes)*

*Defined at line 874 of ./game/server/info_node.cpp*

### PathLength

*public float PathLength(int iStart, int iDest, int iHull, int afCapMask)*

*Defined at line 479 of ./game/server/info_node.cpp*

 Sum up graph weights on the path from iStart to iDest to determine path length

int		FindNearestLink ( const Vector &vecTestPoint, int *piNearestLink, BOOL *pfAlongLine );

### NextNodeInRoute

*public int NextNodeInRoute(int iCurrentNode, int iDest, int iHull, int iCap)*

*Defined at line 521 of ./game/server/info_node.cpp*

 Parse the routing table at iCurrentNode for the next node on the shortest path to iDest

### HandleLinkEnt

*public int HandleLinkEnt(int iNode, entvars_t * pevLinkEnt, int afCapMask, enum CGraph::NODEQUERY queryType)*

*Defined at line 216 of ./game/server/info_node.cpp*

 A static query means we're asking about the possiblity of handling this entity at ANY time A dynamic query means we're asking about it RIGHT NOW.  So we should query the current state

========================================================= CGraph - HandleLinkEnt - a brush ent is between two nodes that would otherwise be able to see each other.  Given the monster's capability, determine whether or not the monster can go this way. =========================================================

### LinkEntForLink

*public entvars_t * LinkEntForLink(class CLink * pLink, class CNode * pNode)*

*Defined at line 145 of ./game/server/info_node.cpp*

========================================================= CGraph - LinkEntForLink - sometimes the ent that blocks a path is a usable door, in which case the monster just needs to face the door and fire it. In other cases, the monster needs to operate a button or lever to get the  door to open. This function will return a pointer to the button if the monster needs to hit a button to open the  door, or returns a pointer to the door if the monster  need only use the door.

 pNode is the node the monster will be standing on when it will need to stop and trigger the ent.=========================================================

### ShowNodeConnections

*public void ShowNodeConnections(int iNode)*

*Defined at line 1129 of ./game/server/info_node.cpp*

========================================================= CGraph - ShowNodeConnections - draws a line from the given node to all connected nodes=========================================================

### InitGraph

*public void InitGraph()*

*Defined at line 58 of ./game/server/info_node.cpp*

========================================================= CGraph - InitGraph - prepares the graph for use. Frees any memory currently in use by the world graph, NULLs  all pointers, and zeros the node count.=========================================================

### AllocNodes

*public int AllocNodes()*

*Defined at line 117 of ./game/server/info_node.cpp*

========================================================= CGraph - AllocNodes - temporary function that mallocs a reasonable number of nodes so we can build the path which will be saved to disk.=========================================================

### CheckNODFile

*public int CheckNODFile(const char * szMapName)*

*Defined at line 2704 of ./game/server/info_node.cpp*

========================================================= CGraph - CheckNODFile - this function checks the date of  the BSP file that was just loaded and the date of the a ssociated .NOD file. If the NOD file is not present, or  is older than the BSP file, we rebuild it.

 returns FALSE if the .NOD file doesn't qualify and needs to be rebuilt.

 !!!BUGBUG - the file times we get back are 20 hours ahead! since this happens consistantly, we can still correctly  determine which of the 2 files is newer. This needs fixed, though. ( I now suspect that we are getting GMT back from these functions and must compensate for local time ) (sjb)=========================================================

### FLoadGraph

*public int FLoadGraph(const char * szMapName)*

*Defined at line 2367 of ./game/server/info_node.cpp*

========================================================= CGraph - FLoadGraph - attempts to load a node graph from disk. if the current level is maps/snar.bsp, maps/graphs/snar.nod will be loaded. If file cannot be loaded, the node tree will be created and saved to disk.=========================================================

### FSaveGraph

*public int FSaveGraph(const char * szMapName)*

*Defined at line 2572 of ./game/server/info_node.cpp*

========================================================= CGraph - FSaveGraph - It's not rocket science. this WILL overwrite existing files.=========================================================

### FSetGraphPointers

*public int FSetGraphPointers()*

*Defined at line 2645 of ./game/server/info_node.cpp*

========================================================= CGraph - FSetGraphPointers - Takes the modelnames of  all of the brush ents that block connections in the node graph and resolves them into pointers to those entities. this is done after loading the graph from disk, whereupon the pointers are not valid.=========================================================

### CheckNode

*public void CheckNode(Vector vecOrigin, int iNode)*

*Defined at line 824 of ./game/server/info_node.cpp*

### BuildRegionTables

*public void BuildRegionTables()*

*Defined at line 2978 of ./game/server/info_node.cpp*

### ComputeStaticRoutingTables

*public void ComputeStaticRoutingTables()*

*Defined at line 3127 of ./game/server/info_node.cpp*

### TestRoutingTables

*public void TestRoutingTables()*

*Defined at line 3434 of ./game/server/info_node.cpp*

 Test those routing tables. Doesn't really work, yet.

### HashInsert

*public void HashInsert(int iSrcNode, int iDestNode, int iKey)*

*Defined at line 2747 of ./game/server/info_node.cpp*

### HashSearch

*public void HashSearch(int iSrcNode, int iDestNode, int & iKey)*

*Defined at line 2769 of ./game/server/info_node.cpp*

### HashChoosePrimes

*public void HashChoosePrimes(int TableSize)*

*Defined at line 2814 of ./game/server/info_node.cpp*

### BuildLinkLookups

*public void BuildLinkLookups()*

*Defined at line 2942 of ./game/server/info_node.cpp*

### SortNodes

*public void SortNodes()*

*Defined at line 2880 of ./game/server/info_node.cpp*

### HullIndex

*public int HullIndex(const class CBaseEntity * pEntity)*

*Defined at line 446 of ./game/server/info_node.cpp*

### NodeType

*public int NodeType(const class CBaseEntity * pEntity)*

*Defined at line 462 of ./game/server/info_node.cpp*

### CapIndex

*public int CapIndex(int afCapMask)*

*Defined at line 208 of ./game/server/info_node.h*

### Node

*public class CNode & Node(int i)*

*Defined at line 216 of ./game/server/info_node.h*

### Link

*public class CLink & Link(int i)*

*Defined at line 225 of ./game/server/info_node.h*

### NodeLink

*public class CLink & NodeLink(int iNode, int iLink)*

*Defined at line 234 of ./game/server/info_node.h*

### NodeLink

*public class CLink & NodeLink(const class CNode & node, int iLink)*

*Defined at line 239 of ./game/server/info_node.h*

### INodeLink

*public int INodeLink(int iNode, int iLink)*

*Defined at line 244 of ./game/server/info_node.h*



## Enums

| enum NODEQUERY |

--

| NODEGRAPH_DYNAMIC |
| NODEGRAPH_STATIC |


*Defined at line 180 of ./game/server/info_node.h*



