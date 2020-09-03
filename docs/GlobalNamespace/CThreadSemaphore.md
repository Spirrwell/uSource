# class CThreadSemaphore

*Defined at line 202 of ./public/threadtools.h*



**brief** platform agnostic Semaphore class



## Members

private sem_t * m_sem

private const char * m_name

private _Bool m_shared



## Functions

### CThreadSemaphore

*public void CThreadSemaphore(const char * name, int max, _Bool shared)*

*Defined at line 184 of ./public/threadtools.cpp*

===========================================

      CThreadSemaphore

===========================================

### ~CThreadSemaphore

*public void ~CThreadSemaphore()*

*Defined at line 195 of ./public/threadtools.cpp*

### Lock

*public void Lock()*

*Defined at line 200 of ./public/threadtools.cpp*

### Unlock

*public void Unlock()*

*Defined at line 205 of ./public/threadtools.cpp*

### TryLock

*public _Bool TryLock()*

*Defined at line 210 of ./public/threadtools.cpp*

### GetUsers

*public int GetUsers()*

*Defined at line 215 of ./public/threadtools.cpp*



