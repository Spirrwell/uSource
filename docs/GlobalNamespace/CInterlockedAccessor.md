# class CInterlockedAccessor

*Defined at line 280 of ./public/threadtools.h*

 Purpose: 	Interlocked, thread-safe access to a specific resource 	Users of this class can either lock the resource for unrestricted use of the actual data, 	or they can opt to copy the data into another container in the calling scope



## Members

private T * m_data

CThreadMutex m_mutex



## Functions

### CInterlockedAccessor<T>

*public void CInterlockedAccessor<T>(Params... args)*

*Defined at line 287 of ./public/threadtools.h*

### ~CInterlockedAccessor<T>

*public void ~CInterlockedAccessor<T>()*

*Defined at line 293 of ./public/threadtools.h*

### Get

*public CThreadLockedAccessor<T> Get()*

*Defined at line 298 of ./public/threadtools.h*

### Get

*public const CThreadLockedAccessor<T> Get()*

*Defined at line 303 of ./public/threadtools.h*

### Set

*public void Set(T * element)*

*Defined at line 308 of ./public/threadtools.h*

### Retrieve

*public T Retrieve()*

*Defined at line 316 of ./public/threadtools.h*



