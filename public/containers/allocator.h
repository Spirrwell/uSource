#pragma once

#undef max
#undef min 

#include <memory>
#include <cstdlib>
#include <exception>

template<class T>
class AllocatorBase
{
public:
	virtual T* allocate(std::size_t sz) { return nullptr; };
	virtual T* reallocate(T* ptr, std::size_t sz) { return nullptr; };
	virtual void deallocate(T* ptr) {};
};

template<class T>
class DefaultAllocator : public AllocatorBase<T>
{
public:
	T* allocate(std::size_t sz) override final
	{
		return (T*)std::malloc(sz);
	}

	T* reallocate(T* ptr, std::size_t sz) override final
	{
		return (T*)std::realloc(ptr, sz);
	}

	void deallocate(T* ptr) override final
	{
		std::free(ptr);
	}
};

template<class T, unsigned long long num>
class StaticAllocator : public AllocatorBase<T>
{
	T m_internalStore[num];
public:
	T* allocate(std::size_t sz) override final
	{
		return (T*)m_internalStore;
	}

	T* reallocate(T* ptr, std::size_t sz) override final
	{
		throw std::exception();
		return nullptr;
	}

	void deallocate(T* ptr) override final
	{
	}
};