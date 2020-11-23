/**
 * Main header for the scriptsystem.
 *
 * The scriptsystem is a game subsystem that abstracts scripting APIs and provides nice wrappers
 * for adding script functions and exposing classes.
 *
 * In the future, I'd like to add custom automated script binding generation using clang
 */
#pragma once

#include <stddef.h>
#include <stdint.h>

#undef min
#undef max

#include <functional>

#include "containers/string.h"
#include "containers/array.h"

#define BEGIN_SCRIPTSYS_NAMESPACE namespace scriptsystem {
#define END_SCRIPTSYS_NAMESPACE }

BEGIN_SCRIPTSYS_NAMESPACE
/*

 API Design

 UserData is a concept that exists in a few languages like squirrel and lua. The idea is you create an object
 and give it to the script, it's really simple. In both lua and squirrel, UserData objects can have table-like
 behaviour, which is something we want to target here. The script_class_desc_t will describe a class type
 that can have any number of fields and method members. It will be used to both generate a table and the userdata
 definition in the language.




 */


/*
====================================================

General structures

====================================================
*/

typedef struct
{
	bool debuginfo;
} ScriptCompileSettings_t;

typedef struct
{
	size_t stack_size;

} ScriptEnvSettings_t;

//typedef struct
//{
//	void* script_data;
//	class IScriptEnvironment* env;
//} Script_t;

typedef struct
{
	uint32_t exit_code;
} ScriptResult_t;

typedef struct
{
	bool error;
	const char* error_desc;
	const char* source;
	int line, col;
} ScriptCompileResult_t;

/*
====================================================

Debugging structures and info

====================================================
*/

struct ScriptBreakpoint_t
{
	class IScript* script;
	const char* file;
	int line;
};

struct ScriptDebugVar_t
{
	const char* name;
	size_t stack_index;
};

enum class EScriptEnvState
{
	SUSPENDED = 0,
	RUNNING,
};

/*
====================================================

Script environment feature detection

====================================================
*/

/* Features this script environment supports */
enum class EScriptEnvFeatures
{
	GC_RC = 1, /* Reference count garbabe collection */
	GC_SWEEP = 2, /* Mark and sweep GC */
	DEBUG_BREAK = 4, /* Does the scripting system allow us to set breakpoints? */
	DEBUG_ENUM_LOCALS = 8, /* Does the scripting system allow us to enum locals? */
	DEBUG_BACKTRACE = 16, /* Can we get a callstack? */
	DEBUG_SWITCH_LEVELS = 32, /* Can we switch stack levels? */
	DEBUG_WATCH = 64, /* Can we watch variables? */
	MODULE_LOADING = 128, /* Can we load precompiled binary modules? */
	MULTISOURCE_COMPILE = 256, /* Do we support compilation of multiple sources at once? */
	DYNAMIC_RELOAD = 512, /* Do we support dynamic script reloads */
};

/*
====================================================

data type defs

====================================================
*/

enum class EDataType :
	uint8_t
{
	BAD = 0,
	NONE = 0,
	BOOL,
	INTEGER,
	FLOAT,
	USERPOINTER,
	USERDATA,
	STRING
};

enum class EDataTypeFlags :
	uint16_t
{
	NONE = 0,
	CONST = 1,
};

/*
====================================================

Script value boilerplate

====================================================
*/

struct ScriptValue_t
{
	EDataType type;
	union {
		bool bval;
		const char* sval;
		void* vval; // userdata
		long long ival;
		double fval;
	};
};

/* Functions defined by the script itself */
struct ScriptFunction_t
{
	const char* name;
	EDataType return_type;
	Array<EDataType> params;
};

struct ScriptClass_t
{
	String baseclass;
};

/*
====================================================

Binding types

====================================================
*/

/* Fields may only reside inside of classes */
class FieldBinding
{
public:
	EDataType m_dataType;
	uint16_t m_flags;
	const char* m_name;
	ClassBinding* m_class;
	size_t m_offset;
};

/* Functions are either static member functions or functions that reside in some namespace */
class FunctionBinding
{
public:
	const char* m_name;
	Array<EDataType> m_params;
	EDataType m_returnType;
};

/* Method bindings are for member functions */
class MethodBinding
{
public:
	const char* m_name;
	Array<EDataType> m_params;
	EDataType m_returnType;
};

class ClassBinding
{
public:
	const char* m_name;
	Array<FieldBinding> m_fields;
	Array<MethodBinding> m_methods;
};

/* Variables only reside outside of classes in namespaces */
class VariableBinding
{
public:
	EDataType m_dataType;
	uint16_t m_flags;
	const char* m_name;
};

typedef void(*ErrorCallback_t)();
typedef void(*ExceptionCallback_t)();


/*
====================================================

Script Class
	Represents a script itself

====================================================
*/

class IScript
{
public:
	/* === DEBUGGING API === */

	virtual ScriptBreakpoint_t SetBreakpoint(const char* file, int line) = 0;
	virtual void ClearBreakpoint(const ScriptBreakpoint_t& bp) = 0;
	virtual void ClearAllBreakpoints() = 0;
	virtual Array<ScriptDebugVar_t> GetStackVariables(int level) = 0;
	virtual void SetStackVariable(ScriptDebugVar_t& var, ScriptValue_t value) = 0;
	virtual Array<ScriptFunction_t> GetScriptFunctions() = 0;
	virtual bool GetScriptFunctionInfo(const char* func, ScriptFunction_t& funcinfo) = 0;

	/* === GENERAL API === */

	virtual ScriptValue_t InvokeFunction(const char* function, EDataType expected_return, std::initializer_list<ScriptValue_t> params) = 0;
	virtual ScriptClass_t* GetExtensionClasses(IScript& script, int& num) = 0;

	virtual class IScriptEnvironment& Environment() const = 0;

};


/*
====================================================

Script Environment Class
	Handles execution of scripts

====================================================
*/

class IScriptEnvironment
{
public:
	/* Initializes the script env. The feature bits specified in features are the things we need to enable. It's computed
		based on the GetEnvFeatures() bits */
	virtual bool Init(ScriptEnvSettings_t settings, uint64_t features) = 0;

	virtual void Shutdown() = 0;

	/* Returns a list of supported features by this environment */
	virtual uint64_t GetEnvFeatures() = 0;

	/**
	 * @brief Compiles a script from the buffer
	 * @param buf Pointer to UTF-8 buffer
	 * @param buf_size size of buffer. Should be NULL terminated anyway
	 * @param settings Settings to compile with
	 * @return If the compile succeeded, returns a pointer to a new script, otherwise, NULL
	 */
	virtual IScript* CompileScript(const char* source_file, const char* buf, size_t buf_size, ScriptCompileSettings_t settings, ScriptCompileResult_t& result) = 0;

	/**
	 * @brief If direct module loading is supported, this will load the binary specified by the buffer.
	 * @param file_path Path to module
	 * @param data The entirety of the file data
	 * @param data_len Length of data in bytes
	 * @param settings
	 * @return
	 */
	virtual IScript* LoadModule(const char* file_path, const void* data, size_t data_len, ScriptCompileSettings_t settings, ScriptCompileResult_t& result) = 0;

	/**
	 * @brief Delete a script object
	 */
	virtual void FreeScript(IScript* scr) = 0;

	virtual void UnloadScript(IScript* scr) = 0;

	virtual void ReloadScript(IScript* scr) = 0;

	/**
	 * @brief Changes the runtime state of the VM
	 * Suspend will cause execution to halt and resume will cause it to resume.
	 * Always call GetEnvironmentState after calling Suspend/Resume to verify the state
	 * has indeed changed.
	 */
	virtual void Suspend() = 0;
	virtual void Resume() = 0;
	virtual EScriptEnvState GetEnvironmentState() = 0;


	/**
	 * @brief Invokes an event handler that is registered by the script.
	 * @param eventName Name of the event to be handled
	 * @param params List of params
	 * @return true if invoked
	 */
	virtual bool InvokeEvent(const char* eventName, std::initializer_list<ScriptValue_t> params) = 0;

	/**
	 * Register a native function with all scripts
	 * @param binding
	 * @return
	 */
	virtual bool BindFunction(FunctionBinding& binding) = 0;

	/**
	 * Register a class with all scripts
	 * @param binding
	 * @return
	 */
	virtual bool BindClass(ClassBinding& binding) = 0;

	/**
	 * Binds an extension class. These are classes that scripts can extend or implement.
	 * These classes can then be instantiated on the C++ side of things
	 * @param binding
	 * @return
	 */
	virtual bool BindExtensionClass(ClassBinding& binding) = 0;
};

/*
 * Baseclass for object wrappers
 * Serves no real purpose other than being food for std::is_base_of
 */
class _ObjectWrapperBase
{
public:
	virtual void* ObjectPtr() const = 0;
	virtual ClassBinding& Binding() const = 0;
};

/**
 * Wrapper class around reflected types. Always wrap your objects in this when passing to the invoke function.
 * This is really a big giant hack, as there's no real way to pass an object by reference to a function with
 * template parameter packs, so you'll end up invoking the copy constructor on an object when trying to invoke
 * something. Also, since we're supporting userpointers as types, you cant just take the address of an object.
 * std::reference should behave similarly, but I want to be able to bind custom class descriptions to arbitrary
 * objects.
 * @tparam T
 */
template<class T>
class ObjectWrapper : public _ObjectWrapperBase
{
private:
	T& m_obj;
public:
	ObjectWrapper() = delete;
	explicit ObjectWrapper(T& object) :
		m_obj(object)
	{
	}

	~ObjectWrapper() = default;

	T& Object() const { return m_obj; }
	void * ObjectPtr() const override { return m_obj; }
};

template<class T>
class GenericObjectWrapper : public _ObjectWrapperBase
{
private:
	T& m_obj;
	ClassBinding& m_classBinding;

public:
	GenericObjectWrapper() = delete;
	GenericObjectWrapper(T& object, ClassBinding& binding) :
		m_obj(object),
		m_classBinding(binding)
	{
	}
	~GenericObjectWrapper() = default;

	ClassBinding & Binding() const override { return m_classBinding; }
	void * ObjectPtr() const override { return m_obj; };
	T& Object() const { return m_obj; }
};

template<class T>
ScriptValue_t ObjectToScriptValue(T arg)
{
	ScriptValue_t sv;
	if(std::is_same<T, bool>::value)
	{
		sv.bval = arg;
		sv.type = EDataType::BOOL;
	}
	else if(std::is_floating_point<T>::value)
	{
		sv.type = EDataType::FLOAT;
		sv.fval = arg;
	}
	else if(std::is_same<T,const char*>::value)
	{
		sv.sval = arg;
		sv.type = EDataType::STRING;
	}
	else if(std::is_pointer<T>::value)
	{
		sv.vval = arg;
		sv.type = EDataType::USERPOINTER;
	}
	else if(std::is_class<T>::value && std::is_base_of<_ObjectWrapperBase, T>::value)
	{
		sv.vval = ((_ObjectWrapperBase*)&arg)->ObjectPtr();
		sv.type = EDataType::USERDATA;
	}
	else if(std::is_integral<T>::value)
	{
		sv.ival = arg;
		sv.type = EDataType::INTEGER;
	}
	else
	{
		sv.type = EDataType::BAD;
		sv.ival = 0;
	}
	return sv;
}

template<class T>
EDataType TypeToScriptType()
{
	if(std::is_same<T, bool>::value)
		return EDataType::BOOL;
	else if(std::is_floating_point<T>::value)
		return EDataType::FLOAT;
	else if(std::is_same<T,const char*>::value)
		return EDataType::STRING;
	else if(std::is_pointer<T>::value)
		return EDataType::USERPOINTER;
	else if(std::is_class<T>::value && std::is_base_of<_ObjectWrapperBase, T>::value)
		return EDataType::USERDATA;
	else if(std::is_integral<T>::value)
		return EDataType::INTEGER;
	else if(std::is_void<T>::value)
		return EDataType::NONE;
	else
		return EDataType::BAD;
}

template<class A, class...T>
void ArgsToScriptValueArray_Recurse(int& index, ScriptValue_t* argArray, A a1, T...args)
{
	argArray[index] = ObjectToScriptValue(a1);
	index++;
	ArgsToScriptValueArray_Recurse(index, args...);
}

template<class A>
void ArgsToScriptValueArray_Recurse(int& index, ScriptValue_t* argArray, A a1)
{
	argArray[index] = ObjectToScriptValue(a1);
	index++;
}

template<class...T>
void ArgsToScriptValueArray(ScriptValue_t* argArray, T...args)
{
	int i = 0;
	ArgsToScriptValueArray_Recurse(0, argArray, args...);
}

template<class A, class...T>
void TypeToScriptTypeArray_Recurse(int& index, EDataType* typeArray);
template<class A>
void TypeToScriptTypeArray_Recurse(int& index, EDataType* typeArray);
void TypeToScriptTypeArray_Recurse(int& index, EDataType* typeArray);


template<class A, class...T>
void TypeToScriptTypeArray_Recurse(int& index, EDataType* typeArray)
{
	typeArray[index] = TypeToScriptType<A>();
	index++;
	TypeToScriptTypeArray_Recurse<T...>(index, typeArray);
}


template<class A>
void TypeToScriptTypeArray_Recurse(int& index, EDataType* typeArray)
{
	typeArray[index] = TypeToScriptType<A>();
	index++;
}

void TypeToScriptTypeArray_Recurse(int& index, EDataType* typeArray)
{
}

template<class...T>
void TypeToScriptTypeArray(EDataType* typeArray)
{
	int i = 0;
	TypeToScriptTypeArray_Recurse<T...>(i, typeArray);
}

template<class R, class...T>
R Invoke(IScript& script, const char* func, T...args)
{
	ScriptValue_t argsArray[sizeof...(args)];
	ArgsToScriptValueArray(argsArray, args...);
	script.InvokeFunction(func, TypeToScriptType<R>(), argsArray);
}

template<class R, class...T>
void BindFunction(IScriptEnvironment* env, std::function<R(T...)> function, const char* name)
{
	FunctionBinding binding;
	binding.m_returnType = TypeToScriptType<R>();
	binding.m_name = name;
	binding.m_params.reserve(sizeof...(T));
	TypeToScriptTypeArray<T...>(binding.m_params.data());
	env->BindFunction(binding);
}

template<class R, class...T>
FunctionBinding CreateFunctionBinding(std::function<R(T...)> function, const char* name)
{
	FunctionBinding binding;
	binding.m_returnType = TypeToScriptType<R>();
	binding.m_name = name;
	binding.m_params.reserve(sizeof...(T));
	TypeToScriptTypeArray<T...>(binding.m_params.data());
	return binding;
}

template<class R, class...T>
FunctionBinding CreateFunctionBindingWithPtr(R(*function)(T...), const char* name)
{
	FunctionBinding binding;
	binding.m_returnType = TypeToScriptType<R>();
	binding.m_name = name;
	binding.m_params.reserve(sizeof...(T));
	TypeToScriptTypeArray<T...>(binding.m_params.data());
	return binding;
}

template<class R, class C, class...T>
MethodBinding CreateMethodBinding(R(C::*function)(T...), const char* name)
{
	MethodBinding binding;
	binding.m_returnType = TypeToScriptType<R>();
	binding.m_name = name;
	binding.m_params.reserve(sizeof...(T)+1);
	binding.m_params[0] = EDataType::USERPOINTER;
	TypeToScriptTypeArray<T...>(binding.m_params.data() + 1);
	return binding;
}


/* Use this macro to declare a scripted class */
/* It will create a static class binding macro */
#define DECLARE_SCRIPTED_CLASS() \
public:                          \
static scriptsystem::ClassBinding& GetClassBinding();

#define BEGIN_SCRIPTED_CLASS_DESC(_class) \
scriptsystem::ClassBinding& _class::GetClassBinding() { \
using _Class = _class;                                          \
static ClassBinding* binding = nullptr;   \
if(!binding) { binding = new ClassBinding();

#define END_SCRIPTED_CLASS_DESC() } return *binding; }

#define SCRIPTED_CLASS_METHOD(_method) binding->m_methods.push_back(CreateMethodBinding(&_Class::_method, #_method));

END_SCRIPTSYS_NAMESPACE
