# class CThread

*Defined at line 83 of ./public/threadtools.h*

## Members

private pthread_t m_thread

pthread_attr_t m_attr

private void * m_ret

private void *(*)(void *) m_threadfn

private _Bool m_run



## Functions

### CThread

*public void CThread(void *(*)(void *) threadfn)*

*Defined at line 24 of ./public/threadtools.cpp*

 Calling the CThread baseclass with this parameter specified will execute the passed function instead of the potentially overridden ThreadFunction 

===========================================

      CThread

===========================================

### Run

*public void Run(void * pvt)*

*Defined at line 35 of ./public/threadtools.cpp*

 Runs the thread with the specified val 

### Terminate

*public void Terminate()*

*Defined at line 49 of ./public/threadtools.cpp*

 Sends SIGTERM to the thread 

### Kill

*public void Kill()*

*Defined at line 58 of ./public/threadtools.cpp*

 Sends SIGKILL to the thread 

### Join

*public void Join()*

*Defined at line 67 of ./public/threadtools.cpp*

 Join the thread into the current one. Pauses until it exits 

### GetReturn

*public void * GetReturn()*

*Defined at line 113 of ./public/threadtools.h*



