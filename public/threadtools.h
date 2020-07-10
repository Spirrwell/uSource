/**
 * threadtools.h
 *
 * Threading utils impl
 */
#pragma once

class CThread
{
public:
	CThread();

	/* Calling the CThread baseclass with this parameter specified will execute the passed
	 * function instead of the potentially overridden ThreadFunction */
	CThread(void*(*threadfn)(void*));

	/* Runs the thread */
	virtual void Run() final;

	/* Sends SIGTERM to the thread */
	virtual void Terminate() final;

	/* Sends SIGKILL to the thread */
	virtual void Kill() final;

	/* Join the thread into the current one.
	 * Pauses until it exits */
	virtual void Join() final;

protected:
	/**
	 * The thread function.
	 * Override this in your child classes
	 */
	virtual void* ThreadFunction(void* param) { return nullptr; };

	virtual void OnTerminate() { };
};

class CThreadMutex
{
private:
	void* m_mutexPvt; /* NOTE: This doesn't look ideal to you, but I'm doing this to *avoid* including platform specific headers in this file! */
			  /* It would be FINE if we only supported POSIX, but windows.h is terrible and horrible and will cause many issues with it's macros if included in some areas of the engine */
public:
	CThreadMutex();
	~CThreadMutex();

	void Lock();
	bool TryLock();
	void Unlock();
};

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
};

class CThreadSemaphore
{
private:
	void* m_semPvt;
public:
	CThreadSemaphore(int max);
	~CThreadSemaphore();

	void Lock();
	void Unlock();
	bool TryLock();
	int GetUsers() const;
};

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
 * Purpose:
 * 	Interlocked, thread-safe access to a specific resource
 */ 
template<class T>
class CInterlockedAccessor
{

};