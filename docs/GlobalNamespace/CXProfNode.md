# class CXProfNode

*Defined at line 149 of ./public/xprof.h*

## Members

private class CXProfNode * m_parent

private class CXProfNode * m_root

List m_children

private const char * m_function

private _Bool m_added

private unsigned long long m_timeBudget

private unsigned long long m_totalTime

private unsigned long long m_absTotal

private unsigned long long m_avgTime

private _Bool m_logTests

private unsigned int m_testQueueSize

Array m_testQueue

private const char * m_file

private const char * m_category

CThreadSpinlock m_mutex

time_t m_lastSampleTime

private unsigned long long m_numFrames

private unsigned long long m_allocBudget

private unsigned long long m_freeBudget

private unsigned long long m_frameAllocs

private unsigned long long m_frameAllocBytes

private unsigned long long m_frameFrees

private unsigned long long m_totalAllocs

private unsigned long long m_totalAllocBytes

private unsigned long long m_totalFrees

private unsigned int m_avgAllocs

private unsigned int m_avgAllocBytes

private unsigned int m_avgFrees



## Functions

### ReportAlloc

*private void ReportAlloc(size_t size)*

*Defined at line 443 of ./public/xprof.cpp*

 Counter reports for the memory allocators and such These will be called by CXProf

### ReportFree

*private void ReportFree()*

*Defined at line 453 of ./public/xprof.cpp*

### ReportRealloc

*private void ReportRealloc(size_t old, size_t newsize)*

*Defined at line 461 of ./public/xprof.cpp*

### CXProfNode

*public void CXProfNode(const char * category, const char * function, const char * file, unsigned long long budget)*

*Defined at line 326 of ./public/xprof.cpp*

=======================================================

      CXProfNode

======================================================= 

### ~CXProfNode

*public void ~CXProfNode()*

*Defined at line 356 of ./public/xprof.cpp*

### LockRead

*public CXProfNode LockRead()*

*Defined at line 204 of ./public/xprof.h*

 Returns a copy of this node for reading 

 THREAD SAFE 

### SubmitTest

*public void SubmitTest(class CXProfTest * test)*

*Defined at line 380 of ./public/xprof.cpp*



**brief** Submit a new XProf time test to the node

### SetBudget

*public void SetBudget(unsigned long long time)*

*Defined at line 391 of ./public/xprof.cpp*

### GetBudget

*public unsigned long long GetBudget()*

*Defined at line 397 of ./public/xprof.cpp*

### GetRemainingBudget

*public unsigned long long GetRemainingBudget()*

*Defined at line 361 of ./public/xprof.cpp*



**brief** Get or reset the remaining budget constraints

### ResetBudget

*public void ResetBudget()*

*Defined at line 370 of ./public/xprof.cpp*

### DoFrame

*public void DoFrame()*

*Defined at line 421 of ./public/xprof.cpp*



**brief** Resets anything that might need to be reset

### Name

*public const char * Name()*

*Defined at line 231 of ./public/xprof.h*

 Accessors 

 THREAD SAFE 

### File

*public const char * File()*

*Defined at line 232 of ./public/xprof.h*

### Category

*public const char * Category()*

*Defined at line 233 of ./public/xprof.h*

### Parent

*public class CXProfNode * Parent()*

*Defined at line 234 of ./public/xprof.h*

### Children

*public List Children()*

*Defined at line 403 of ./public/xprof.cpp*

### AddChild

*public void AddChild(class CXProfNode * node)*

*Defined at line 409 of ./public/xprof.cpp*

### TestQueue

*public Array TestQueue()*

*Defined at line 415 of ./public/xprof.cpp*



