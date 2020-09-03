# class CThreadSpinlock

*Defined at line 184 of ./public/threadtools.h*



**brief** Spinlock class



## Members

private unsigned int m_atomicFlag



## Functions

### CThreadSpinlock

*public void CThreadSpinlock()*

*Defined at line 136 of ./public/threadtools.cpp*

===========================================

      CThreadSpinlock

===========================================

### ~CThreadSpinlock

*public void ~CThreadSpinlock()*

*Defined at line 146 of ./public/threadtools.cpp*

### Lock

*public void Lock()*

*Defined at line 150 of ./public/threadtools.cpp*

### TryLock

*public _Bool TryLock()*

*Defined at line 159 of ./public/threadtools.cpp*

### Unlock

*public void Unlock()*

*Defined at line 168 of ./public/threadtools.cpp*

### RAIILock

*public CThreadRAIILock RAIILock()*

*Defined at line 196 of ./public/threadtools.h*



