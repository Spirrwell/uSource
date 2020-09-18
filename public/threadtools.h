/**
 * threadtools.h
 *
 * Threading utils impl
 */
#pragma once

#ifdef _WIN32
#include "winplatform.h"
#else
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#endif

#include "common.h"

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
#       ifdef _WIN32
#               include <intrin.h>
#       else
#               include <x86intrin.h>
#       endif // _WIN32
#       include <xmmintrin.h>
#elif defined(PLATFORM_ARM) || defined(PLATFORM_ARM64)

#endif

/* Forward decls */
template<class T>
class CThreadRAIILock;

namespace threadtools
{
	/* Atomically swaps pointers, returning the old value of dst */
	inline void* AtomicSwapPtr(void** dst, void* src)
	{
#ifdef __GNUC__
		return (void*)__atomic_exchange_n(dst, src, __ATOMIC_RELAXED);
#else

#endif
	}

	/* Atomically swaps integers, returns old value of dst */
	inline int AtomicSwapInt(int* dst, int src)
	{
#ifdef __GNUC__
		return __atomic_exchange_n(dst, src, __ATOMIC_RELAXED);
#else

#endif
	}

	inline void* AtomicGetPtr(void** atomic)
	{
#ifdef __GNUC__
		return (void*)__atomic_load_n(atomic, __ATOMIC_RELAXED);
#else

#endif
	}


	inline int AtomicGetInt(int* atomic)
	{
#ifdef __GNUC__
		return __atomic_load_n(atomic, __ATOMIC_RELAXED);
#else

#endif
	}

	inline int AtomicIncInt(int* atomic)
	{
#ifdef __GNUC__
		return __atomic_add_fetch(atomic, 1, __ATOMIC_RELAXED);
#else

#endif
	}

	inline void* AtomicIncPtr(void** ptr)
	{
#ifdef __GNUC__
		return __atomic_add_fetch(ptr, 1, __ATOMIC_RELAXED);
#else

#endif
	}

	inline int AtomicDecInt(int* atomic)
	{
#ifdef __GNUC__
		return __atomic_sub_fetch(atomic, 1, __ATOMIC_RELAXED);
#else

#endif
	}

	inline void* AtomicDecPtr(void** ptr)
	{
#ifdef __GNUC__
		return __atomic_sub_fetch(ptr, 1, __ATOMIC_RELAXED);
#else

#endif
	}

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

class EXPORT CThread
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
class EXPORT CThreadRAIILock
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
class EXPORT CThreadMutex
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
class EXPORT CThreadRWMutex
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
class EXPORT CThreadSpinlock
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
class EXPORT CThreadSemaphore
{
private:
#ifdef _WIN32
	void* m_sem;
#else
	sem_t*  m_sem;
	sem_t __m_sem; // memory for the actual semaphore
#endif
	bool m_shared;
	const char* m_name;
	int m_max;
public:
	CThreadSemaphore(const char* name, int max, bool shared);
	~CThreadSemaphore();

	void Lock();
	void Unlock();
	bool TryLock();
};


/**
 * @brief A Mutex that
 */
class EXPORT CSharedMutex
{
private:
	CThreadSemaphore m_sem;
public:
	CSharedMutex(const char* name);
	~CSharedMutex();

	void Lock();
	void Unlock();
	bool TryLock();
};

/**
 * @brief Semaphore implemented using a spinlock
 */
class EXPORT CThreadSpinSemaphore
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

template<class T>
class EXPORT CInterlockedAccessor;

template<class T>
class EXPORT CInterlockedSharedPtr
{
private:
	CInterlockedAccessor<T>* m_accessor;
	const T* m_ptr;

	template<class _X>
	friend class CInterlockedAccessor;
public:
	CInterlockedSharedPtr() = delete;

	CInterlockedSharedPtr(CInterlockedAccessor<T>& accessor) :
		m_accessor(&accessor),
		m_ptr(m_accessor->m_resource)
	{
		m_accessor->m_mutex.RLock();
	}

	~CInterlockedSharedPtr()
	{
		if(!m_accessor) return;
		m_accessor->m_mutex.RUnlock();
	}

	CInterlockedSharedPtr(CInterlockedSharedPtr&& other) noexcept
	{
		this->m_accessor = other.m_accessor;
		this->m_ptr = other.m_ptr;
		other.m_accessor = nullptr;
		other.m_ptr = nullptr;
	}

	CInterlockedSharedPtr(const CInterlockedSharedPtr& other)
	{
		this->m_accessor = other.m_accessor;
		this->m_ptr = other.m_ptr;
		other.m_accessor->m_mutex.RLock();
	}

	const T& operator*() const
	{
		return *m_ptr;
	}

	const T* operator->() const
	{
		return m_ptr;
	}

	CInterlockedSharedPtr& operator=(CInterlockedSharedPtr&& other) noexcept
	{
		this->m_accessor = other.m_accessor;
		this->m_ptr = other.m_ptr;
		other.m_accessor = nullptr;
		other.m_ptr = nullptr;
		return *this;
	}

	CInterlockedSharedPtr& operator=(const CInterlockedSharedPtr& other)
	{
		this->m_accessor = other.m_accessor;
		this->m_ptr = other.m_ptr;
		other.m_accessor->m_mutex.RLock();
		return *this;
	}
};

template<class T>
class EXPORT CInterlockedSharedWritePtr
{
private:
	CInterlockedAccessor<T>* m_accessor;
	const T* m_ptr;

	template<class _X>
	friend class CInterlockedAccessor;
public:
	CInterlockedSharedWritePtr() = delete;

	CInterlockedSharedWritePtr(CInterlockedAccessor<T>& accessor) :
		m_accessor(&accessor),
		m_ptr(m_accessor->m_resource)
	{
		m_accessor->m_mutex.WLock();
	}

	~CInterlockedSharedWritePtr()
	{
		if(!m_accessor) return;
		m_accessor->m_mutex.WUnlock();
	}

	CInterlockedSharedWritePtr(CInterlockedSharedWritePtr&& other) noexcept
	{
		this->m_accessor = other.m_accessor;
		this->m_ptr = other.m_ptr;
		other.m_accessor = nullptr;
		other.m_ptr = nullptr;
	}

	CInterlockedSharedWritePtr(const CInterlockedSharedWritePtr& other)
	{
		this->m_accessor = other.m_accessor;
		this->m_ptr = other.m_ptr;
		other.m_accessor->m_mutex.WLock();
	}

	T& operator*() const
	{
		return *m_ptr;
	}

	T* operator->() const
	{
		return m_ptr;
	}

	CInterlockedSharedWritePtr& operator=(CInterlockedSharedWritePtr&& other) noexcept
	{
		this->m_accessor = other.m_accessor;
		this->m_ptr = other.m_ptr;
		other.m_accessor = nullptr;
		other.m_ptr = nullptr;
		return *this;
	}

	CInterlockedSharedWritePtr& operator=(const CInterlockedSharedWritePtr& other)
	{
		this->m_accessor = other.m_accessor;
		this->m_ptr = other.m_ptr;
		other.m_accessor->m_mutex.WLock();
		return *this;
	}
};

/**
 * Purpose:
 * 	CInterlockedAccessor is a thread-safe accessor to an arbitrary resource.
 *	The resource can have any number of readers,
 */
template<class T>
class EXPORT CInterlockedAccessor
{
private:
	CThreadRWMutex m_mutex;
	T* m_resource;


	template<class _X>
	friend class CInterlockedSharedPtr;

public:
	CInterlockedAccessor(T* ptr) :
		m_resource(ptr)
	{

	}

	CInterlockedAccessor(T& ref) :
		m_resource(&ref)
	{

	}

	CInterlockedSharedPtr<T> GetForRead()
	{
		return CInterlockedSharedPtr<T>(*this);
	}

	CInterlockedSharedWritePtr<T> GetForWrite()
	{
		return CInterlockedSharedWritePtr<T>(*this);
	}

	void ReadLock()
	{
		m_mutex.RLock();
	}

	void ReadUnlock()
	{
		m_mutex.RUnlock();
	}

	void WriteLock()
	{
		m_mutex.WLock();
	}

	void WriteUnlock()
	{
		m_mutex.WUnlock();
	}
};

static int dsdasasfasf = 0;
static CInterlockedAccessor<int> g_Poop(dsdasasfasf);
static auto ggggg = g_Poop.GetForRead();