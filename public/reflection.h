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
#include <typeindex>

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
	SFieldInfo_t *fields;
	unsigned int nfields;
};

struct SMethodInfo_t
{
	const char* name;
	const char* classname;
	void* ptr;
	SFieldInfo_t params[];
};

namespace reflection
{
	enum ETypeFlags {
		TYPEFLAGS_CONST                 = 0b0000000000000001,
		TYPEFLAGS_NONTRIVIAL            = 0b0000000000000010,
		TYPEFLAGS_CLASS                 = 0b0000000000000110,
		TYPEFLAGS_UNION                 = 0b0000000000001010,
	};

	template<typename T1, typename T2>
	inline size_t constexpr offset_of(T1 T2::*member)
	{
		constexpr T2 object{};
		return size_t(&(object.*member)) - size_t(&object);
	}

	template<class T>
	constexpr unsigned int ComputeTypeFlags()
	{
		unsigned int fl = 0;
		if(std::is_const<T>::value) fl |= TYPEFLAGS_CONST;
		if(std::is_class<T>::value) fl |= TYPEFLAGS_CLASS;
		if(std::is_union<T>::value) fl |= TYPEFLAGS_UNION;
		return fl;
	}
}

//=====================================================================================//
/**
 * Use this to declare a primitive "struct" type that you wish to use as a reflected type
 */
namespace reflection
{
	extern std::unordered_map<std::type_index, SStructInfo_t *> *g_pStructFieldInfos;
}

#define DECLARE_DATA_STRUCT()

#define BEGIN_STRUCT_FIELD_INFO(_struct) \
namespace C__ ## _struct ## __wrapper { \
typedef _struct BaseClass; \
constexpr char* BaseStructString1 = #_struct; \
constexpr static SFieldInfo_t __field_infos[] = {

#define STRUCT_FIELD(_type, _x) {BaseStructString1, #_x, offsetof(BaseClass, _x), sizeof(BaseClass::_x), typeid(_type), reflection::ComputeTypeFlags<_type>()}

#define END_STRUCT_FIELD_INFO(_struct) \
}; \
static CLambdaStaticInitWrapper __struct_init_wrapper([]() { \
	using namespace reflection; \
	static SStructInfo_t info = { (SFieldInfo_t*)__field_infos, (sizeof(__field_infos) / sizeof(SFieldInfo_t))}; \
	g_pStructFieldInfos->insert({std::type_index(typeid(_struct)), &info}); \
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
/**
 * Basic class declaration macro
 * Use this to enable runtime reflection on your classes
 */
#define DECLARE_CLASS(_class) \
static constexpr char* BaseClassString = #_class;\
static SFieldInfo_t* g_fieldInfo; unsigned long g_fieldInfoCount; \
static SMethodInfo_t* g_methodInfo; unsigned long g_methodInfoCount; \
virtual SFieldInfo_t* GetFieldInfo(unsigned long long& num) { num = g_fieldInfoCount; return g_fieldInfo; } \
virtual SMethodInfo_t* GetMethodInfo(unsigned long long& num) { num = g_methodInfoCount; return g_methodInfo; } \

#define _DECLARE_CLASS_SAVABLE_INTERNAL(_class) \
static SFieldInfo_t* g_saveInfo; \
unsigned long g_saveInfoCount; \
virtual SFieldInfo_t* GetSaveInfo(unsigned long long& num) { num = g_saveInfoCount; return g_saveInfo;}

#define _DECLARE_CLASS_NETWORKED_INTERNAL(_class) \
static SFieldInfo_t* g_networkedFields; \
unsigned long g_networkedFieldsCount; \
virtual SFieldInfo_t* GetSaveInfo(unsigned long long& num) { num = g_networkedFieldsCount; return g_networkedFields; };

#define DECLARE_CLASS_SAVEABLE(_class) \
DECLARE_CLASS(_class) \
_DECLARE_CLASS_SAVABLE_INTERNAL(_class)

#define DECLARE_CLASS_NETWORKED(_class) \
DECLARE_CLASS(_class) \
_DECLARE_CLASS_NETWORKED_INTERNAL(_class)

/* Classes that are both networkable and saveable */
#define DECLARE_CLASS_NETWORKED_SAVEABLE(_class) \

//=====================================================================================//

#define _BEGIN_FIELD_INFO_INTERNAL_(_class, _tablename, _countname) namespace C__## _class ## __wrapper {\
typedef _class BaseClass; \
static constexpr SFieldInfo_t __g__ ## _class ## _field_info ## _tablename [] = {

#define _END_FIELD_INFO_INTERNAL(_class, _tablename, _countname) };} SFieldInfo_t* _class::_tablename = (SFieldInfo_t*)C__## _class ## __wrapper::__g__ ## _class ## _field_info ## _tablename;

//=====================================================================================//
#define BEGIN_FIELD_INFO(_class) _BEGIN_FIELD_INFO_INTERNAL_(_class, g_fieldInfo, g_fieldInfoCount)

#define FIELD(_type, _x) { BaseClass::BaseClassString, #_x, offsetof(BaseClass, _x), sizeof(BaseClass::_x), typeid(_type), reflection::ComputeTypeFlags<_type>()}

#define END_FIELD_INFO(_class) _END_FIELD_INFO_INTERNAL(_class, g_fieldInfo, g_fieldInfoCount)

//=====================================================================================//

//=====================================================================================//
#define BEGIN_SAVE_INFO(_class) _BEGIN_FIELD_INFO_INTERNAL_(_class, g_saveInfo, g_saveInfoCount)

#define END_SAVE_INFO(_class) _END_FIELD_INFO_INTERNAL(_class, g_saveInfo, g_saveInfoCount)
//=====================================================================================//

//=====================================================================================//
#define BEGIN_METHOD_INFO(_class) namespace C__##_class##__wrapper {\
typedef _class BaseClass; \
static constexpr SMethodInfo_t __g__ ## _class ## _method_info[] = {

#define METHOD(_x) {#_x, BaseClass::BaseClassString, nullptr, {}}

#define END_METHOD_INFO(_class) };} SMethodInfo_t* _class::g_methodInfo = (SMethodInfo_t*)C__##_class##__wrapper::__g__##_class##_method_info;
//=====================================================================================//

//=====================================================================================//
// NOTE: Enums cannot have member functions. So instead, we will store the enum info in
// an internal lookup table
#define BEGIN_ENUM_INFO(_enum)
#define ENUM_VALUE(_value)
#define END_ENUM_INFO(_enum)

//=====================================================================================//

class CClass
{
public:
	DECLARE_CLASS_SAVEABLE(CClass);
	bool m_bBool;
	void TestFunc() {};
};

BEGIN_FIELD_INFO(CClass)
	FIELD(bool, m_bBool),
END_FIELD_INFO(CClass)

BEGIN_METHOD_INFO(CClass)
	METHOD(TestFunc)
END_METHOD_INFO(CClass)

BEGIN_SAVE_INFO(CClass)

END_SAVE_INFO(CClass)