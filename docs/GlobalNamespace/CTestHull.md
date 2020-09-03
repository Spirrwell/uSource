# class CTestHull

*Defined at line 1482 of ./game/server/info_node.cpp*

========================================================= TestHull is a modelless clip hull that verifies reachable nodes by walking from every node to each of it's connections=========================================================



Inherits from CBaseMonster



## Members

Vector vecBadNodeOrigin



## Functions

### Spawn

*public void Spawn(entvars_t * pevMasterNode)*

*Defined at line 1501 of ./game/server/info_node.cpp*

========================================================= CTestHull::Spawn=========================================================

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 1486 of ./game/server/info_node.cpp*

### CallBuildNodeGraph

*public void CallBuildNodeGraph()*

*Defined at line 1633 of ./game/server/info_node.cpp*

### BuildNodeGraph

*public void BuildNodeGraph()*

*Defined at line 1650 of ./game/server/info_node.cpp*

========================================================= BuildNodeGraph - think function called by the empty walk hull that is spawned by the first node to spawn. This function links all nodes that can see each other, then eliminates all inline links, then uses a monster-sized  hull that walks between each node and each of its links to ensure that a monster can actually fit through the space=========================================================

### ShowBadNode

*public void ShowBadNode()*

*Defined at line 1615 of ./game/server/info_node.cpp*

========================================================= CTestHull - ShowBadNode - makes a bad node fizzle. When there's a problem with node graph generation, the test  hull will be placed up the bad node's location and will generate particles=========================================================

### DropDelay

*public void DropDelay()*

*Defined at line 1534 of ./game/server/info_node.cpp*

========================================================= TestHull::DropDelay - spawns TestHull on top of  the 0th node and drops it to the ground.=========================================================

### PathFind

*public void PathFind()*

*Defined at line 2119 of ./game/server/info_node.cpp*

========================================================= returns a hardcoded path.=========================================================



