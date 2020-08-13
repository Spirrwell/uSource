#pragma once

#include "public/containers/allocator.h"

/* Standard includes */
#undef min
#undef max
#include <unordered_map>
#include <map>

template<class KeyT, class ValT>
class Map : public std::map<KeyT, ValT>
{
public:
	void add(const KeyT& k, const ValT& v)
	{
		this->insert(std::pair<KeyT,ValT>(k,v));
	}
};

template<class KeyT, class ValT>
class MultiMap : public std::multimap<KeyT, ValT>
{
public:
	void add(const KeyT& k, const ValT& v)
	{
		this->insert(std::pair<KeyT,ValT>(k,v));
	}
};

template<class KeyT, class ValT, class Hash = std::hash<KeyT>>
class HashMap : public std::unordered_map<KeyT, ValT>
{
public:
	void add(const KeyT& k, const ValT& v)
	{
		this->insert(std::pair<KeyT,ValT>(k,v));
	}
};

template<class KeyT, class ValT, class Hash = std::hash<KeyT>>
class HasMultiMap
{
public:
	void add(const KeyT& k, const ValT& v)
	{
		this->insert(std::pair<KeyT,ValT>(k,v));
	}
};