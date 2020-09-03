# class CThreadRWMutex

*Defined at line 157 of ./public/threadtools.h*



**brief** Basic mutex class



## Members

 m_mutex

 m_attr



## Functions

### CThreadRWMutex

*public void CThreadRWMutex()*

*Defined at line 263 of ./public/threadtools.cpp*

===========================================

      CThreadRWMutex

===========================================

### ~CThreadRWMutex

*public void ~CThreadRWMutex()*

*Defined at line 273 of ./public/threadtools.cpp*

### RLock

*public void RLock()*

*Defined at line 283 of ./public/threadtools.cpp*

 Read lock 

### RTryLock

*public _Bool RTryLock()*

*Defined at line 292 of ./public/threadtools.cpp*

### RUnlock

*public void RUnlock()*

*Defined at line 301 of ./public/threadtools.cpp*

### WLock

*public void WLock()*

*Defined at line 310 of ./public/threadtools.cpp*

 Write lock 

### WTryLock

*public _Bool WTryLock()*

*Defined at line 319 of ./public/threadtools.cpp*

### WUnlock

*public void WUnlock()*

*Defined at line 328 of ./public/threadtools.cpp*



