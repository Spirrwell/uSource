/*
 *
 * reflection.h - Reflection for C++!! Primarily designed for serialization of objects
 *
 */
#pragma once

#include <typeinfo>
#include <type_traits>
#include <cstddef>

template <typename T1, typename T2>
inline size_t constexpr offset_of(T1 T2::*member) {
	constexpr T2 object {};
	return size_t(&(object.*member)) - size_t(&object);
}

struct SFieldInfo_t
{
	const char* classname;
	const char* name;
	unsigned long long offset;
	unsigned long long size;
	const std::type_info& info;
	unsigned int flags;
};

struct SMethodInfo_t
{
	const char* name;
	const char* classname;
	void* ptr;
};

class IObject
{
public:
	virtual SFieldInfo_t* GetFieldInfo() = 0;
};

enum ETypeFlags {
	TYPEFLAGS_CONST                 = 0b0000000000000001,
	TYPEFLAGS_NONTRIVIAL            = 0b0000000000000010,
	TYPEFLAGS_CLASS                 = 0b0000000000000110,
	TYPEFLAGS_UNION                 = 0b0000000000001010,
};

template<class T>
constexpr unsigned int ComputeTypeFlags()
{
	unsigned int fl = 0;
	if(std::is_const<T>::value) fl |= TYPEFLAGS_CONST;
	if(std::is_class<T>::value) fl |= TYPEFLAGS_CLASS;
	if(std::is_union<T>::value) fl |= TYPEFLAGS_UNION;
	return fl;
}

#define DECLARE_CLASS() static SFieldInfo_t* g_fieldInfo; \
static SMethodInfo_t* g_methodInfo;\
SFieldInfo_t* GetFieldInfo() override { return g_fieldInfo; }

#define BEGIN_REFLECTION_INFO(_class) namespace C__## _class ## __wrapper {\
typedef _class BaseClass; \
constexpr char* BaseClassString = #_class;\
static constexpr SFieldInfo_t __g__ ## _class ## _field_info[] = {

#define FIELD(_type, _x) { BaseClassString, #_x, offsetof(BaseClass, _x), sizeof(BaseClass::_x), typeid(_type), ComputeTypeFlags<_type>()}

#define END_REFLECTION_INFO(_class) };} SFieldInfo_t* _class::g_fieldInfo = (SFieldInfo_t*)C__## _class ## __wrapper::__g__ ## _class ## _field_info;

#define BEGIN_METHOD_REFLECTION_INFO(_class) namespace C__##_class##__wrapper {\
typedef _class BaseClass; \
constexpr char* BaseClassString2 = #_class;\
static constexpr SMethodInfo_t __g__ ## _class ## _method_info[] = {

#define METHOD(_x) {#_x, BaseClassString2}

#define END_METHOD_REFLECTION_INFO(_class) };} SMethodInfo_t* _class::g_methodInfo = (SMethodInfo_t*)C__##_class##__wrapper::__g__##_class##_method_info;

class CClass : public IObject
{
public:
	DECLARE_CLASS();
	bool m_bBool;
	void TestFunc() {};
};

BEGIN_REFLECTION_INFO(CClass)
	FIELD(bool, m_bBool),
END_REFLECTION_INFO(CClass)

BEGIN_METHOD_REFLECTION_INFO(CClass)
	METHOD(TestFunc)
END_METHOD_REFLECTION_INFO(CClass)