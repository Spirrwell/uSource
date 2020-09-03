# class CXProf

*Defined at line 81 of ./public/xprof.h*

## Members

List m_nodes

private std::stack<class CXProfNode *> [64] m_nodeStack

private unsigned long long [64] m_nodeStackThreads

private _Bool m_enabled

CThreadMutex m_mutex

time_t m_lastFrameTime

private unsigned int m_flags



## Functions

### CXProf

*public void CXProf()*

*Defined at line 71 of ./public/xprof.cpp*

 Constructor is NOT thread-safe, obviously! 

### ~CXProf

*public void ~CXProf()*

*Defined at line 87 of ./public/xprof.cpp*

### AddCategoryNode

*public void AddCategoryNode(const char * name, unsigned long long budget)*

*Defined at line 96 of ./public/xprof.cpp*

 Creates a new node category 

 THREAD SAFE 

### CreateNode

*public class CXProfNode * CreateNode(const char * category, const char * func, const char * file, unsigned long long budget)*

*Defined at line 178 of ./public/xprof.cpp*

### PushNode

*public void PushNode(class CXProfNode * node)*

*Defined at line 107 of ./public/xprof.cpp*

### PopNode

*public void PopNode()*

*Defined at line 164 of ./public/xprof.cpp*

### CurrentNode

*public class CXProfNode * CurrentNode()*

*Defined at line 301 of ./public/xprof.cpp*

 Returns a pointer to the current node. NOT thread-safe. Lock before calling this! 

### LastFrameTime

*public time_t LastFrameTime()*

*Defined at line 108 of ./public/xprof.h*

### ReportAlloc

*public void ReportAlloc(size_t sz)*

*Defined at line 277 of ./public/xprof.cpp*

 Use to report memory allocations/frees 

 Thread-safe without locks 

### ReportRealloc

*public void ReportRealloc(size_t oldsize, size_t newsize)*

*Defined at line 285 of ./public/xprof.cpp*

### ReportFree

*public void ReportFree()*

*Defined at line 293 of ./public/xprof.cpp*

### FindCategory

*public class CXProfNode * FindCategory(const char * name)*

*Defined at line 193 of ./public/xprof.cpp*

### SetFlag

*public void SetFlag(unsigned int flag)*

*Defined at line 118 of ./public/xprof.h*

### ClearFlag

*public void ClearFlag(unsigned int flag)*

*Defined at line 119 of ./public/xprof.h*

### Nodes

*public List Nodes()*

*Defined at line 123 of ./public/xprof.h*

 Returns a list of category nodes 

 THREAD SAFE 

### DumpAllNodes

*public void DumpAllNodes(int (*)(const char *, ...) printFn)*

*Defined at line 185 of ./public/xprof.cpp*

 Tree dump functions 

 NOT THREAD SAFE 

### DumpCategoryTree

*public void DumpCategoryTree(const char * cat, int (*)(const char *, ...) printFn)*

*Defined at line 203 of ./public/xprof.cpp*

### Frame

*public void Frame(float dt)*

*Defined at line 239 of ./public/xprof.cpp*

 A "frame". Resets all per-frame budgets 

 THREAD SAFE 

### Enabled

*public _Bool Enabled()*

*Defined at line 271 of ./public/xprof.cpp*

 Enables or disables xprof 

 THREAD SAFE 

### Enable

*public void Enable()*

*Defined at line 265 of ./public/xprof.cpp*

### Disable

*public void Disable()*

*Defined at line 259 of ./public/xprof.cpp*

### ClearNodes

*public void ClearNodes()*

*Defined at line 246 of ./public/xprof.cpp*

### DumpNodeTreeInternal

*private void DumpNodeTreeInternal(class CXProfNode * node, int indent, int (*)(const char *, ...) printFn)*

*Defined at line 217 of ./public/xprof.cpp*



