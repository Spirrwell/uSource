#include "threadtools.h"

#ifdef _POSIX
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#else
#include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>


//===========================================
//
//      CThread
//
//===========================================

CThread::CThread(void *(*threadfn)(void *)) :
	m_threadfn(threadfn),
	m_run(false)
{
#ifdef _WIN32
	hThread = nullptr;
#else
	pthread_attr_init(&m_attr);
#endif
}

void CThread::Run(void* pvt)
{
#ifdef _WIN32
	if(m_run && hThread)
		TerminateThread(hThread, 1);
	DWORD dwThreadId;
	hThread = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(m_threadfn), pvt, 0, &dwThreadId);
	m_run = true;
#else
	if(m_run)
	{
		pthread_cancel(m_thread);
	}
	m_run = true;
	pthread_create(&m_thread, &m_attr, m_threadfn, pvt);
#endif
}

void CThread::Terminate()
{
#ifdef _WIN32
	if(hThread)
		TerminateThread(hThread, 0);
#else
	pthread_kill(m_thread, SIGTERM);
#endif
}

void CThread::Kill()
{
#ifdef _WIN32
	if(hThread)
		TerminateThread(hThread, 0);
#else
	pthread_kill(m_thread, SIGKILL);
#endif
}

void CThread::Join()
{
#ifdef _WIN32
	if(hThread)
		WaitForSingleObject(hThread, INFINITE);
#else
	pthread_join(m_thread, &m_ret);
#endif
}

//===========================================
//
//      CThreadMutex
//
//===========================================

CThreadMutex::CThreadMutex()
{
#ifdef _WIN32
	m_mutex = CreateMutexA(NULL, TRUE, NULL);
#else
	pthread_mutexattr_init(&m_attr);
	pthread_mutex_init(&m_mutex, &m_attr);
#endif
}

CThreadMutex::~CThreadMutex()
{
#ifdef _WIN32
	CloseHandle(m_mutex);
#else
	pthread_mutex_destroy(&m_mutex);
	pthread_mutexattr_destroy(&m_attr);
#endif
}

void CThreadMutex::Lock()
{
#ifdef _WIN32
	WaitForSingleObject(m_mutex, INFINITE);
#else
	pthread_mutex_lock(&m_mutex);
#endif
}

bool CThreadMutex::TryLock()
{
#ifdef _WIN32
	DWORD dwRes = WaitForSingleObject(m_mutex, 0);
	return dwRes == WAIT_OBJECT_0;
#else
	return pthread_mutex_trylock(&m_mutex) == 0;
#endif
}

void CThreadMutex::Unlock()
{
#ifdef _WIN32
	ReleaseMutex(m_mutex);
#else
	pthread_mutex_unlock(&m_mutex);
#endif
}


//===========================================
//
//      CThreadSpinlock
//
//===========================================

CThreadSpinlock::CThreadSpinlock()
{
#ifdef __GNUC__
	unsigned int f = 0;
	__atomic_store(&m_atomicFlag, &f, __ATOMIC_RELAXED);
#else

#endif
}

CThreadSpinlock::~CThreadSpinlock()
{
}

void CThreadSpinlock::Lock()
{
#ifdef __GNUC__
	while(__sync_bool_compare_and_swap(&m_atomicFlag, 0, 1)) {};
#else

#endif
}

bool CThreadSpinlock::TryLock()
{
#ifdef __GNUC__
	return __sync_bool_compare_and_swap(&m_atomicFlag, 0, 1);
#else

#endif
}

void CThreadSpinlock::Unlock()
{
#ifdef __GNUC__
	__sync_bool_compare_and_swap(&m_atomicFlag, 1, 0);
#else

#endif
}


//===========================================
//
//      CThreadSemaphore
//
//===========================================

CThreadSemaphore::CThreadSemaphore(const char* name, int max, bool shared) :
	m_name(name),
	m_shared(shared)
{
#ifdef _WIN32

#else

#endif
}

CThreadSemaphore::~CThreadSemaphore()
{

}

void CThreadSemaphore::Lock()
{

}

void CThreadSemaphore::Unlock()
{

}

bool CThreadSemaphore::TryLock()
{
	return false;
}

int CThreadSemaphore::GetUsers() const
{
	return 0;
}


//===========================================
//
//      CThreadSpinSemaphore
//
//===========================================

CThreadSpinSemaphore::CThreadSpinSemaphore(int max)
{

}

CThreadSpinSemaphore::~CThreadSpinSemaphore()
{

}

void CThreadSpinSemaphore::Lock()
{

}

void CThreadSpinSemaphore::Unlock()
{

}

bool CThreadSpinSemaphore::TryLock()
{
	return false;
}

int CThreadSpinSemaphore::GetUsers() const
{
	return 0;
}

//===========================================
//
//      CThreadRWMutex
//
//===========================================

CThreadRWMutex::CThreadRWMutex()
{
#ifdef _WIN32

#else
	pthread_rwlockattr_init(&m_attr);
	pthread_rwlock_init(&m_mutex, &m_attr);
#endif
}

CThreadRWMutex::~CThreadRWMutex()
{
#ifdef _WIN32

#else
	pthread_rwlockattr_destroy(&m_attr);
	pthread_rwlock_destroy(&m_mutex);
#endif
}

void CThreadRWMutex::RLock()
{
#ifdef _WIN32
	m_r_mutex.Lock();
#else
	pthread_rwlock_rdlock(&m_mutex);
#endif
}

bool CThreadRWMutex::RTryLock()
{
#ifdef _WIN32
	return m_r_mutex.TryLock();
#else
	return pthread_rwlock_tryrdlock(&m_mutex) == 0;
#endif
}

void CThreadRWMutex::RUnlock()
{
#ifdef _WIN32
	m_r_mutex.Unlock();
#else
	pthread_rwlock_unlock(&m_mutex);
#endif
}

void CThreadRWMutex::WLock()
{
#ifdef _WIN32
	m_w_mutex.Lock();
#else
	pthread_rwlock_wrlock(&m_mutex);
#endif
}

bool CThreadRWMutex::WTryLock()
{
#ifdef _WIN32
	return m_w_mutex.TryLock();
#else
	return pthread_rwlock_trywrlock(&m_mutex) == 0;
#endif
}

void CThreadRWMutex::WUnlock()
{
#ifdef _WIN32
	m_w_mutex.Unlock();
#else
	pthread_rwlock_unlock(&m_mutex);
#endif
}
