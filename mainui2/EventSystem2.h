
#pragma once

#include "MainUI.h"

/**
 * Simple delegate class
 * @tparam R Return
 * @tparam T List of all params, or void
 */
template<class R, class ...T>
struct Delegate
{

	R(*m_ptr)(T...);

	Delegate() :
		m_ptr(nullptr)
	{
	}

	Delegate(R(*g)(T...)) :
		m_ptr(g)
	{
	}

	Delegate(const Delegate<R,T...>& other)
	{
		this->m_ptr = other.m_ptr;
	}

	Delegate(Delegate<R,T...>&& other)
	{
		this->m_ptr = other.m_ptr;
		other.m_ptr = nullptr;
	}

	bool is_bound()
	{
		return m_ptr != nullptr;
	}

	void bind(R(*g)(T...))
	{
		m_ptr = g;
	}

	Delegate<R,T...>& operator=(R(*g)(T...))
	{
		m_ptr = g;
		return *this;
	}

	R operator()(T...args)
	{
		if(m_ptr)
			return m_ptr(args...);
		return R();
	}
};

