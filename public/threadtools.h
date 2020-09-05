/**
 * threadtools.h
 *
 * Threading utils impl
 */
#pragma once

#ifdef _WIN32
#include <synchapi.h>
#else
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#endif

#if defined(_M_X86) || defined(__i386__)
#       define PLATFORM_X86
#endif

#if defined(__x86_64__) || defined(_M_X64)
#       define PLATFORM_X64
#endif

#if defined(__arm__) || defined(_M_ARM)
#       define PLATFORM_ARM
#endif

#if defined(__aarch64__)
#       define PLATFORM_ARM64
#endif

/* Platform specific includes */
#if defined(PLATFORM_X64) || defined(PLATFORM_X86)
#       include <x86intrin.h>
#       include <xmmintrin.h>
#elif defined(PLATFORM_ARM) || defined(PLATFORM_ARM64)

#endif

/* Forward decls */
template<class T>
class CThreadRAIILock;

namespace threadtools
{
	/* Atomically swaps pointers, returning the old value of dst */
	void* AtomicSwapPtr(void** dst, void* src);

	/* Atomically swaps integers, returns old value of dst */
	int AtomicSwapInt(int* dst, int src);

	void* AtomicGetPtr(void** atomic);
	int AtomicGetInt(int* atomic);

	inline void mfence()
	{
#if defined(PLATFORM_X64) || defined(PLATFORM_X86)
		_mm_mfence();
#else

#endif
	}

	inline void lfence()
	{
#if defined(PLATFORM_X64) || defined(PLATFORM_X86)
		_mm_lfence();
#else

#endif
	}

	inline void sfence()
	{
#if defined(PLATFORM_X64) || defined(PLATFORM_X86)
		_mm_sfence();
#else

#endif
	}
}

class CThread
{
private:
#ifdef _WIN32
	HANDLE hThread;
#else
	pthread_t m_thread;
	pthread_attr_t m_attr;
#endif
	void* m_ret;
	void*(*m_threadfn)(void*);
	bool m_run;
public:
	/* Calling the CThread baseclass with this parameter specified will execute the passed
	 * function instead of the potentially overridden ThreadFunction */
	CThread(void*(*threadfn)(void*));

	/* Runs the thread with the specified val */
	void Run(void* pvt = nullptr);

	/* Sends SIGTERM to the thread */
	void Terminate();

	/* Sends SIGKILL to the thread */
	void Kill();

	/* Join the thread into the current one.
	 * Pauses until it exits */
	void Join();

	void* GetReturn() { return m_ret; };
};

/**
 * Simple RAII lock that wraps around a mutex, semaphore, etc.
 * @tparam T lock class to use
 */
template<class T>
class CThreadRAIILock
{
private:
	T* m_mutex;
public:
	CThreadRAIILock(T* mut) { m_mutex = mut; m_mutex->Lock(); };
	~CThreadRAIILock() { m_mutex->Unlock(); };
};


/**
 * @brief Basic mutex class
 */
class CThreadMutex
{
private:
#ifdef _WIN32
	void* m_mutex;
#else
	pthread_mutex_t m_mutex;
	pthread_mutexattr_t m_attr;
#endif
public:
	CThreadMutex();
	~CThreadMutex();

	void Lock();
	bool TryLock();
	void Unlock();

	CThreadRAIILock<CThreadMutex> RAIILock() { return CThreadRAIILock<CThreadMutex>(this); };
};

/**
 * @brief Basic mutex class
 */
class CThreadRWMutex
{
private:
#ifdef _WIN32
	CThreadMutex m_r_mutex;
	CThreadMutex m_w_mutex;
#else
	pthread_rwlock_t m_mutex;
	pthread_rwlockattr_t m_attr;
#endif
public:
	CThreadRWMutex();
	~CThreadRWMutex();

	/* Read lock */
	void RLock();
	bool RTryLock();
	void RUnlock();

	/* Write lock */
	void WLock();
	bool WTryLock();
	void WUnlock();
};

/**
 * @brief Spinlock class
 */
class CThreadSpinlock
{
private:
	unsigned int m_atomicFlag;
public:
	CThreadSpinlock();
	~CThreadSpinlock();

	void Lock();
	bool TryLock();
	void Unlock();

	CThreadRAIILock<CThreadSpinlock> RAIILock() { return CThreadRAIILock<CThreadSpinlock>(this); };
};

/**
 * @brief platform agnostic Semaphore class
 */
class CThreadSemaphore
{
private:
#ifdef _WIN32
	void* m_sem;
#else
	sem_t*  m_sem;
#endif
	const char* m_name;
	bool m_shared;
public:
	CThreadSemaphore(const char* name, int max, bool shared);
	~CThreadSemaphore();

	void Lock();
	void Unlock();
	bool TryLock();
	int GetUsers() const;
};

/**
 * @brief Semaphore implemented using a spinlock
 */
class CThreadSpinSemaphore
{
private:

public:
	CThreadSpinSemaphore(int max);
	~CThreadSpinSemaphore();

	void Lock();
	void Unlock();
	bool TryLock();
	int GetUsers() const;
};

/**
 * RAII-type mutex lock around a resource
 */
template<class T>
class CThreadLockedAccessor
{
private:
	T* m_data;
	CThreadMutex* m_mutex;
public:
	CThreadLockedAccessor(CThreadMutex* mutex, T* data)
	{
		this->m_data = data;
		this->m_mutex = mutex;
		mutex->Lock();
	}

	~CThreadLockedAccessor()
	{
		m_mutex->Unlock();
	}

	T& Get() { return *m_data; };
	const T& Get() const { return *m_data; };

	/* Dispose of the accessor early, before we exit scope */
	void Dispose() { m_data = nullptr; m_mutex->Unlock(); }

	T& operator*() { return *m_data; };
	const T& operator*() const { return *m_data; };
	T* operator->() { return m_data; };
	const T* operator->() const { return m_data; };
};

/**
 * Purpose:
 * 	Interlocked, thread-safe access to a specific resource
 * 	Users of this class can either lock the resource for unrestricted use of the actual data,
 * 	or they can opt to copy the data into another container in the calling scope
 */ 
template<class T>
class CInterlockedAccessor
{
private:
	T* m_data;
	CThreadMutex m_mutex;
public:
	template<class ... Params>
	CInterlockedAccessor(Params...args) :
		m_mutex(CThreadMutex())
	{
		m_data = new T(args...);
	}

	~CInterlockedAccessor()
	{
		delete m_data;
	}

	CThreadLockedAccessor<T> Get()
	{
		return CThreadLockedAccessor<T>(&m_mutex, m_data);
	}

	const CThreadLockedAccessor<T> Get() const
	{
		return CThreadLockedAccessor<T>(&m_mutex, m_data);
	}

	void Set(T* element)
	{
		m_mutex.Lock();
		m_data = element;
		threadtools::sfence();
		m_mutex.Unlock();
	}

	T Retrieve()
	{
		CThreadRAIILock<CThreadMutex> lock(&m_mutex);
		return *m_data;
	}
};