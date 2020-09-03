# class CThreadLockedAccessor

*Defined at line 243 of ./public/threadtools.h*

 RAII-type mutex lock around a resource



## Members

private T * m_data

private class CThreadMutex * m_mutex



## Functions

### CThreadLockedAccessor<T>

*public void CThreadLockedAccessor<T>(class CThreadMutex * mutex, T * data)*

*Defined at line 249 of ./public/threadtools.h*

### ~CThreadLockedAccessor<T>

*public void ~CThreadLockedAccessor<T>()*

*Defined at line 256 of ./public/threadtools.h*

### Get

*public T & Get()*

*Defined at line 261 of ./public/threadtools.h*

### Get

*public const T & Get()*

*Defined at line 262 of ./public/threadtools.h*

### Dispose

*public void Dispose()*

*Defined at line 265 of ./public/threadtools.h*

 Dispose of the accessor early, before we exit scope 

### operator*

*public T & operator*()*

*Defined at line 267 of ./public/threadtools.h*

### operator*

*public const T & operator*()*

*Defined at line 268 of ./public/threadtools.h*

### operator->

*public T * operator->()*

*Defined at line 269 of ./public/threadtools.h*

### operator->

*public const T * operator->()*

*Defined at line 270 of ./public/threadtools.h*



