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

#include <atomic>

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
	/* Just wanted an explicit thing so we don't end up with someone using long as an atomic flag or something like that */
	typedef uint32_t AtomicUInt;
	typedef int32_t AtomicInt;
	typedef uint32_t AtomicFlag;

	/* Atomically swaps pointers, returning the old value of dst */
	static inline void* AtomicSwapPtr(void** dst, void* src)
	{
#if defined(__GNUC__) || defined(__clang__)
		return (void*)__atomic_exchange_n(dst, src, __ATOMIC_RELAXED);
#else
		return (void*)InterlockedExchangePointer(dst, src);
#endif
	}

	/* Atomically swaps integers, returns old value of dst */
	static inline int AtomicSwapInt(int* dst, int src)
	{
#if defined(__GNUC__) || defined(__clang__)
		return __atomic_exchange_n(dst, src, __ATOMIC_RELAXED);
#else
		return (int)InterlockedExchange(dst, src);
#endif
	}

	static inline void* AtomicGetPtr(void** atomic)
	{
#if defined(__GNUC__) || defined(__clang__)
		return (void*)__atomic_load_n(atomic, __ATOMIC_RELAXED);
#else
	#ifdef XASH_64BIT
		return (void*)InterlockedOr64(atomic, 0);
	#else
		return (void*)InterlockedOr(atomic, 0);
	#endif
#endif
	}


	static inline int AtomicGetInt(int* atomic)
	{
#if defined(__GNUC__) || defined(__clang__)
		return __atomic_load_n(atomic, __ATOMIC_RELAXED);
#else
		/* Note: we're using interlocked Or here because Windows doesn't provide a raw interlocked get function */
		return (int)InterlockedOr(atomic, 0);
#endif
	}

	static inline int AtomicIncInt(int* atomic)
	{
#if defined(__GNUC__) || defined(__clang__)
		return __atomic_add_fetch(atomic, 1, __ATOMIC_RELAXED);
#else
		return (int)InterlockedIncrement(atomic);
#endif
	}

	static inline void* AtomicIncPtr(void** ptr)
	{
#if defined(__GNUC__) || defined(__clang__)
		return __atomic_add_fetch(ptr, 1, __ATOMIC_RELAXED);
#else
	#ifdef XASH_64BIT
		return (void*)InterlockedIncrement64(atomic);
	#else
		return (void*)InterlockedIncrement(atomic);
	#endif
#endif
	}

	static inline int AtomicDecInt(int* atomic)
	{
#if defined(__GNUC__) || defined(__clang__)
		return __atomic_sub_fetch(atomic, 1, __ATOMIC_RELAXED);
#else
		return (int)InterlockedDecrement(atomic);
#endif
	}

	static inline void* AtomicDecPtr(void** ptr)
	{
#if defined(__GNUC__) || defined(__clang__)
		return __atomic_sub_fetch(ptr, 1, __ATOMIC_RELAXED);
#else
	#ifdef XASH_64BIT
		return (void*)InterlockedDecrement64(atomic);
	#else
		return (void*)InterlockedDecrement(atomic);
	#endif
#endif
	}

	/* Adds num to the atomic and returns the result of the operation */
	static inline int AtomicAddInt(int* atomic, int num)
	{
#if defined(__GNUC__) || defined(__clang__)
		return __atomic_add_fetch(atomic, num, __ATOMIC_RELAXED);
#else
		return (int)InterlockedAdd(atomic, num);
#endif
	}

	static inline void* AtomicAddPtr(void** atomic, uintptr_t num)
	{
#if defined(__GNUC__) || defined(__clang__)
		return __atomic_add_fetch(atomic, num, __ATOMIC_RELAXED);
#else
	#ifdef XASH_64BIT
		return (void*)InterlockedAdd64(atomic, num);
	#else
		return (void*)InterlockedAdd(atomic, num);
	#endif
#endif
	}

	/* Subtract a number from the atomic and return the new value */
	static inline int AtomicSubInt(int* atomic, int num)
	{
#if defined(__GNUC__) || defined(__clang__)
		return __atomic_sub_fetch(atomic, num, __ATOMIC_RELAXED);
#else
		return (int)InterlockedAdd(atomic, -num);
#endif
	}

	static inline void* AtomicSubPtr(void** atomic, uintptr_t num)
	{
#if defined(__GNUC__) || defined(__clang__)
		return __atomic_add_fetch(atomic, num, __ATOMIC_RELAXED);
#else
	#ifdef XASH_64BIT
		return (void*)InterlockedAdd64(atomic, -num);
	#else
		return (void*)InterlockedAdd(atomic, -num);
	#endif
#endif
	}



	static inline void mfence()
	{
#if defined(PLATFORM_X64) || defined(PLATFORM_X86)
		_mm_mfence();
#else

#endif
	}

	static inline void lfence()
	{
#if defined(PLATFORM_X64) || defined(PLATFORM_X86)
		_mm_lfence();
#else

#endif
	}

	static inline void sfence()
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
