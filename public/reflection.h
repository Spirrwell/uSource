/*
 *
 * reflection.h - Reflection for C++!! Primarily designed for serialization of objects
 *
 */
#pragma once

#include "static_helpers.h"

#include <typeinfo>
#include <type_traits>
#include <cstddef>
#include <unordered_map>

template <typename T1, typename T2>
inline size_t constexpr offset_of(T1 T2::*member) {
	constexpr T2 object {};
	return size_t(&(object.*member)) - size_t(&object);
}

struct STypeInfo_t
{
	std::type_info typeinfo;
	unsigned long long size;
};

struct SFieldInfo_t
{
	const char* classname;
	const char* name;
	unsigned long long offset;
	unsigned long long size;
	const std::type_info& info;
	unsigned int flags;
	const char* description; /* Optional description of the fields function. Generally you'll use this for scripting support */
};

class IMethodInfoWrapper
{
public:

};

struct SStructInfo_t
{
	SFieldInfo_t fields[];
};

struct SMethodInfo_t
{
	const char* name;
	const char* classname;
	void* ptr;
	SFieldInfo_t params[];
};

template<class R, class...T>
constexpr SFieldInfo_t* method_param_unpacker(R(*fn)(T...))
{
	return nullptr;
}

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

/**
 * Basic class declaration macro
 * Use this to enable runtime reflection on your classes
 */
#define DECLARE_CLASS() static SFieldInfo_t* g_fieldInfo; \
static SMethodInfo_t* g_methodInfo;\
SFieldInfo_t* GetFieldInfo() override { return g_fieldInfo; }

//=====================================================================================//
/**
 * Use this to declare a primitive "struct" type that you wish to use as a reflected type
 */
extern std::unordered_map<const std::type_info&, SStructInfo_t>* g_pStructFieldInfos;
#define DECLARE_DATA_STRUCT()

#define BEGIN_STRUCT_FIELD_INFO(_struct) \
namespace C__ ## _struct ## __wrapper { \
typedef _struct BaseClass; \
constexpr char* BaseStructString1 = #_struct; \
constexpr static SFieldInfo_t __field_infos[] = {

#define STRUCT_FIELD(_type, _x) {BaseStructString1, #_x, offsetof(BaseClass, _x), sizeof(BaseClass::_x), typeid(_type), ComputeTypeFlags<_type>()}

#define END_STRUCT_FIELD_INFO(_struct) \
static CLambdaStaticInitWrapper __struct_init_wrapper([]() { \
	static SStructInfo_t info; \
	info.fields = __field_infos; \
	g_pStructFieldInfos->insert(std::make_pair<const std::type_info&, SStructInfo_t>(typeid(_struct), &info)); \
}); }

struct TestStruct
{
	DECLARE_DATA_STRUCT();
	bool b_Bitch;
};

BEGIN_STRUCT_FIELD_INFO(TestStruct)
	STRUCT_FIELD(bool, b_Bitch),
END_STRUCT_FIELD_INFO(TestStruct)


//=====================================================================================//
#define BEGIN_FIELD_INFO(_class) namespace C__## _class ## __wrapper {\
typedef _class BaseClass; \
constexpr char* BaseClassString = #_class;\
static constexpr SFieldInfo_t __g__ ## _class ## _field_info[] = {

#define FIELD(_type, _x) { BaseClassString, #_x, offsetof(BaseClass, _x), sizeof(BaseClass::_x), typeid(_type), ComputeTypeFlags<_type>()}

#define END_FIELD_INFO(_class) };} SFieldInfo_t* _class::g_fieldInfo = (SFieldInfo_t*)C__## _class ## __wrapper::__g__ ## _class ## _field_info;
//=====================================================================================//


//=====================================================================================//
#define BEGIN_METHOD_INFO(_class) namespace C__##_class##__wrapper {\
typedef _class BaseClass; \
constexpr char* BaseClassString2 = #_class;\
static constexpr SMethodInfo_t __g__ ## _class ## _method_info[] = {

#define METHOD(_x) {#_x, BaseClassString2, nullptr, {}}

#define END_METHOD_INFO(_class) };} SMethodInfo_t* _class::g_methodInfo = (SMethodInfo_t*)C__##_class##__wrapper::__g__##_class##_method_info;
//=====================================================================================//

//=====================================================================================//
// NOTE: Enums cannot have member functions. So instead, we will store the enum info in
// an internal lookup table
#define BEGIN_ENUM_INFO(_enum)
#define ENUM_VALUE(_value)
#define END_ENUM_INFO(_enum)

//=====================================================================================//

class CClass : public IObject
{
public:
	DECLARE_CLASS();
	bool m_bBool;
	void TestFunc() {};
};

BEGIN_FIELD_INFO(CClass)
	FIELD(bool, m_bBool),
END_FIELD_INFO(CClass)

BEGIN_METHOD_INFO(CClass)
	METHOD(TestFunc)
END_METHOD_INFO(CClass)