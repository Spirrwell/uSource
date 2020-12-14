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
#include <array>

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

class _ScriptArrayBase {};

/* Used to pass arrays of data */

template<class T>
class ScriptArrayView : public _ScriptArrayBase
{
private:
	T* m_mem;
	size_t m_len;
public:
	ScriptArrayView() = delete;

	explicit ScriptArrayView(std::vector<T> array)
	{
		m_len = array.size();
		m_mem = array.data();
	}

	template<size_t N>
	explicit ScriptArrayView(T dat[N])
	{
		m_len = N;
		m_mem = dat;
	}

	const T& at(size_t n) const
	{
		return m_mem[n];
	}

	T& at(size_t n)
	{
		return m_mem[n];
	}

	size_t length() const { return m_len; };

	T* data() const { return m_mem; };
};


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
	size_t m_offset;
};

/* Functions are either static member functions or functions that reside in some namespace */
class FunctionBinding
{
public:
	const char* m_name;
	Array<EDataType> m_params;
	EDataType m_returnType;
	class _FunctionBinderBase* m_binder;
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
	virtual ~IScript() = 0;
	/* === DEBUGGING API === */

	virtual ScriptBreakpoint_t SetBreakpoint(const char* file, int line) = 0;
	virtual void ClearBreakpoint(const ScriptBreakpoint_t& bp) = 0;
	virtual void ClearAllBreakpoints() = 0;
	virtual Array<ScriptDebugVar_t> GetStackVariables(int level) = 0;
	virtual void SetStackVariable(ScriptDebugVar_t& var, ScriptValue_t value) = 0;
	virtual Array<ScriptFunction_t> GetScriptFunctions() = 0;
	virtual bool GetScriptFunctionInfo(const char* func, ScriptFunction_t& funcinfo) = 0;

	/* === GENERAL API === */

	virtual ScriptValue_t InvokeFunction(const char* function, EDataType expected_return, const std::vector<ScriptValue_t>& params) = 0;
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
	virtual ~IScriptEnvironment() = 0;
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
constexpr ScriptValue_t ObjectToScriptValue(T arg)
{
	ScriptValue_t sv = {};
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
	else if(std::is_void<T>::value)
	{
		sv.type = EDataType::NONE;
	}
	else
	{
		sv.type = EDataType::BAD;
		sv.ival = 0;
	}
	return sv;
}

template<class T>
constexpr EDataType TypeToScriptType()
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
constexpr void ArgsToScriptValueArray_Recurse(int& index, ScriptValue_t* argArray, A a1, T...args)
{
	argArray[index] = ObjectToScriptValue(a1);
	index++;
	ArgsToScriptValueArray_Recurse(index, args...);
}

template<class A>
constexpr void ArgsToScriptValueArray_Recurse(int& index, ScriptValue_t* argArray, A a1)
{
	argArray[index] = ObjectToScriptValue(a1);
	index++;
}

template<class...T>
constexpr void ArgsToScriptValueArray(ScriptValue_t* argArray, T...args)
{
	int i = 0;
	ArgsToScriptValueArray_Recurse(0, argArray, args...);
}

template<class A, class...T>
constexpr void TypeToScriptTypeArray_Recurse(int& index, EDataType* typeArray);
template<class A>
constexpr void TypeToScriptTypeArray_Recurse(int& index, EDataType* typeArray);
constexpr void TypeToScriptTypeArray_Recurse(int& index, EDataType* typeArray);

template<class A, class...T>
constexpr void TypeToScriptTypeArray_Recurse(int& index, EDataType* typeArray)
{
	typeArray[index] = TypeToScriptType<A>();
	index++;
	TypeToScriptTypeArray_Recurse<T...>(index, typeArray);
}


template<class A>
constexpr void TypeToScriptTypeArray_Recurse(int& index, EDataType* typeArray)
{
	typeArray[index] = TypeToScriptType<A>();
	index++;
}

constexpr void TypeToScriptTypeArray_Recurse(int& index, EDataType* typeArray)
{
}

template<class...T>
constexpr void TypeToScriptTypeArray(EDataType* typeArray)
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

template<class T>
static T ValueFromScriptValue(const ScriptValue_t& v)
{
	return T();
};

template<>
long long ValueFromScriptValue<long long>(const ScriptValue_t& v)
{
	return v.ival;
}
template<>
long ValueFromScriptValue<long>(const ScriptValue_t& v)
{
	return v.ival;
}
template<>
int ValueFromScriptValue<int>(const ScriptValue_t& v)
{
	return v.ival;
}
template<>
short ValueFromScriptValue<short>(const ScriptValue_t& v)
{
	return v.ival;
}
template<>
unsigned short ValueFromScriptValue<unsigned short>(const ScriptValue_t& v)
{
	return v.ival;
}
template<>
unsigned int ValueFromScriptValue<unsigned int>(const ScriptValue_t& v)
{
	return v.ival;
}
template<>
unsigned long ValueFromScriptValue<unsigned long>(const ScriptValue_t& v)
{
	return v.ival;
}
template<>
unsigned long long ValueFromScriptValue<unsigned long long>(const ScriptValue_t& v)
{
	return v.ival;
}
template<>
float ValueFromScriptValue<float>(const ScriptValue_t& v)
{
	return v.fval;
}
template<>
double ValueFromScriptValue<double>(const ScriptValue_t& v)
{
	return v.fval;
}
template<>
void* ValueFromScriptValue<void*>(const ScriptValue_t& v)
{
	return v.vval;
}
template<>
const char* ValueFromScriptValue<const char*>(const ScriptValue_t& v)
{
	return v.sval;
}
template<>
bool ValueFromScriptValue<bool>(const ScriptValue_t& v)
{
	return v.bval;
}

class _FunctionBinderBase
{
public:
	virtual ScriptValue_t Invoke(const Array<ScriptValue_t>& values) = 0;
};

template<class R>
class FunctionBinder0 : public _FunctionBinderBase
{
public:
	R(*m_function)();
	ScriptValue_t Invoke(const Array<ScriptValue_t>& values) override
	{
		return ObjectToScriptValue<R>(m_function());
	}
};

template<class R, class A1>
class FunctionBinder1 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(m_function(ValueFromScriptValue<A1>(v[0])));
	}
};

template<class R, class A1, class A2>
class FunctionBinder2 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1, A2);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(
			m_function(ValueFromScriptValue<A1>(v[0]), ValueFromScriptValue<A2>(v[1]))
		);
	}
};

template<class R, class A1, class A2, class A3>
class FunctionBinder3 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1, A2, A3);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(
			m_function(ValueFromScriptValue<A1>(v[0]), ValueFromScriptValue<A2>(v[1]), ValueFromScriptValue<A3>(v[2]))
		);
	}
};
template<class R, class A1, class A2, class A3, class A4>
class FunctionBinder4 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1, A2, A3, A4);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(
			m_function(ValueFromScriptValue<A1>(v[0]), ValueFromScriptValue<A2>(v[1]), ValueFromScriptValue<A3>(v[2]), ValueFromScriptValue<A4>(v[3]))
		);
	}
};
template<class R, class A1, class A2, class A3, class A4, class A5>
class FunctionBinder5 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1, A2, A3, A4, A5);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(
			m_function(
				ValueFromScriptValue<A1>(v[0]),
				ValueFromScriptValue<A2>(v[1]),
				ValueFromScriptValue<A3>(v[2]),
				ValueFromScriptValue<A4>(v[3]),
				ValueFromScriptValue<A5>(v[4])
			)
		);
	}
};
template<class R, class A1, class A2, class A3, class A4, class A5, class A6>
class FunctionBinder6 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1, A2, A3, A4, A5, A6);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(
			m_function(
				ValueFromScriptValue<A1>(v[0]),
				ValueFromScriptValue<A2>(v[1]),
				ValueFromScriptValue<A3>(v[2]),
				ValueFromScriptValue<A4>(v[3]),
				ValueFromScriptValue<A5>(v[4]),
				ValueFromScriptValue<A6>(v[5])
			)
		);
	}
};
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class FunctionBinder7 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1, A2, A3, A4, A5, A6, A7);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(
			m_function(
				ValueFromScriptValue<A1>(v[0]),
				ValueFromScriptValue<A2>(v[1]),
				ValueFromScriptValue<A3>(v[2]),
				ValueFromScriptValue<A4>(v[3]),
				ValueFromScriptValue<A5>(v[4]),
				ValueFromScriptValue<A6>(v[5]),
				ValueFromScriptValue<A7>(v[6])
			)
		);
	}
};
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class FunctionBinder8 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1, A2, A3, A4, A5, A6, A7, A8);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(
			m_function(
				ValueFromScriptValue<A1>(v[0]),
				ValueFromScriptValue<A2>(v[1]),
				ValueFromScriptValue<A3>(v[2]),
				ValueFromScriptValue<A4>(v[3]),
				ValueFromScriptValue<A5>(v[4]),
				ValueFromScriptValue<A6>(v[5]),
				ValueFromScriptValue<A7>(v[6]),
				ValueFromScriptValue<A8>(v[7])
			)
		);
	}
};
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class FunctionBinder9 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1, A2, A3, A4, A5, A6, A7, A8, A9);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(
			m_function(
				ValueFromScriptValue<A1>(v[0]),
				ValueFromScriptValue<A2>(v[1]),
				ValueFromScriptValue<A3>(v[2]),
				ValueFromScriptValue<A4>(v[3]),
				ValueFromScriptValue<A5>(v[4]),
				ValueFromScriptValue<A6>(v[5]),
				ValueFromScriptValue<A7>(v[6]),
				ValueFromScriptValue<A8>(v[7]),
				ValueFromScriptValue<A9>(v[8])
			)
		);
	}
};
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class FunctionBinder10 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(
			m_function(
				ValueFromScriptValue<A1>(v[0]),
				ValueFromScriptValue<A2>(v[1]),
				ValueFromScriptValue<A3>(v[2]),
				ValueFromScriptValue<A4>(v[3]),
				ValueFromScriptValue<A5>(v[4]),
				ValueFromScriptValue<A6>(v[5]),
				ValueFromScriptValue<A7>(v[6]),
				ValueFromScriptValue<A8>(v[7]),
				ValueFromScriptValue<A9>(v[8]),
				ValueFromScriptValue<A10>(v[9])
			)
		);
	}
};
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class FunctionBinder11 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(
			m_function(
				ValueFromScriptValue<A1>(v[0]),
				ValueFromScriptValue<A2>(v[1]),
				ValueFromScriptValue<A3>(v[2]),
				ValueFromScriptValue<A4>(v[3]),
				ValueFromScriptValue<A5>(v[4]),
				ValueFromScriptValue<A6>(v[5]),
				ValueFromScriptValue<A7>(v[6]),
				ValueFromScriptValue<A8>(v[7]),
				ValueFromScriptValue<A9>(v[8]),
				ValueFromScriptValue<A10>(v[9]),
				ValueFromScriptValue<A11>(v[10])
			)
		);
	}
};
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class FunctionBinder12 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(
			m_function(
				ValueFromScriptValue<A1>(v[0]),
				ValueFromScriptValue<A2>(v[1]),
				ValueFromScriptValue<A3>(v[2]),
				ValueFromScriptValue<A4>(v[3]),
				ValueFromScriptValue<A5>(v[4]),
				ValueFromScriptValue<A6>(v[5]),
				ValueFromScriptValue<A7>(v[6]),
				ValueFromScriptValue<A8>(v[7]),
				ValueFromScriptValue<A9>(v[8]),
				ValueFromScriptValue<A10>(v[9]),
				ValueFromScriptValue<A11>(v[10]),
				ValueFromScriptValue<A12>(v[11])
			)
		);
	}
};
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class FunctionBinder13 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(
			m_function(
				ValueFromScriptValue<A1>(v[0]),
				ValueFromScriptValue<A2>(v[1]),
				ValueFromScriptValue<A3>(v[2]),
				ValueFromScriptValue<A4>(v[3]),
				ValueFromScriptValue<A5>(v[4]),
				ValueFromScriptValue<A6>(v[5]),
				ValueFromScriptValue<A7>(v[6]),
				ValueFromScriptValue<A8>(v[7]),
				ValueFromScriptValue<A9>(v[8]),
				ValueFromScriptValue<A10>(v[9]),
				ValueFromScriptValue<A11>(v[10]),
				ValueFromScriptValue<A12>(v[11]),
				ValueFromScriptValue<A13>(v[12])
			)
		);
	}
};
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class FunctionBinder14 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(
			m_function(
				ValueFromScriptValue<A1>(v[0]),
				ValueFromScriptValue<A2>(v[1]),
				ValueFromScriptValue<A3>(v[2]),
				ValueFromScriptValue<A4>(v[3]),
				ValueFromScriptValue<A5>(v[4]),
				ValueFromScriptValue<A6>(v[5]),
				ValueFromScriptValue<A7>(v[6]),
				ValueFromScriptValue<A8>(v[7]),
				ValueFromScriptValue<A9>(v[8]),
				ValueFromScriptValue<A10>(v[9]),
				ValueFromScriptValue<A11>(v[10]),
				ValueFromScriptValue<A12>(v[11]),
				ValueFromScriptValue<A13>(v[12]),
				ValueFromScriptValue<A14>(v[13])
			)
		);
	}
};
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class FunctionBinder15 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(
			m_function(
				ValueFromScriptValue<A1>(v[0]),
				ValueFromScriptValue<A2>(v[1]),
				ValueFromScriptValue<A3>(v[2]),
				ValueFromScriptValue<A4>(v[3]),
				ValueFromScriptValue<A5>(v[4]),
				ValueFromScriptValue<A6>(v[5]),
				ValueFromScriptValue<A7>(v[6]),
				ValueFromScriptValue<A8>(v[7]),
				ValueFromScriptValue<A9>(v[8]),
				ValueFromScriptValue<A10>(v[9]),
				ValueFromScriptValue<A11>(v[10]),
				ValueFromScriptValue<A12>(v[11]),
				ValueFromScriptValue<A13>(v[12]),
				ValueFromScriptValue<A14>(v[13]),
				ValueFromScriptValue<A15>(v[14])
			)
		);
	}
};
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class FunctionBinder16 : public _FunctionBinderBase
{
public:
	R(*m_function)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16);
	ScriptValue_t Invoke(const Array<ScriptValue_t>& v) override
	{
		return ObjectToScriptValue<R>(
			m_function(
				ValueFromScriptValue<A1>(v[0]),
				ValueFromScriptValue<A2>(v[1]),
				ValueFromScriptValue<A3>(v[2]),
				ValueFromScriptValue<A4>(v[3]),
				ValueFromScriptValue<A5>(v[4]),
				ValueFromScriptValue<A6>(v[5]),
				ValueFromScriptValue<A7>(v[6]),
				ValueFromScriptValue<A8>(v[7]),
				ValueFromScriptValue<A9>(v[8]),
				ValueFromScriptValue<A10>(v[9]),
				ValueFromScriptValue<A11>(v[10]),
				ValueFromScriptValue<A12>(v[11]),
				ValueFromScriptValue<A13>(v[12]),
				ValueFromScriptValue<A14>(v[13]),
				ValueFromScriptValue<A15>(v[14]),
				ValueFromScriptValue<A16>(v[15])
			)
		);
	}
};

template<class R>
_FunctionBinderBase* CreateBinder(R(*fn)())
{
	auto b = new FunctionBinder0<R>();
	b->m_function = fn;
	return b;
}

template<class R, class A1>
_FunctionBinderBase* CreateBinder(R(*fn)(A1))
{
	auto b = new FunctionBinder1<R, A1>();
	b->m_function = fn;
	return b;
}

template<class R, class A1, class A2>
_FunctionBinderBase* CreateBinder(R(*fn)(A1, A2))
{
	auto b = new FunctionBinder2<R, A1, A2>();
	b->m_function = fn;
	return b;
}
template<class R, class A1, class A2, class A3>
_FunctionBinderBase* CreateBinder(R(*fn)(A1, A2, A3))
{
	auto b = new FunctionBinder3<R, A1, A2, A3>();
	b->m_function = fn;
	return b;
}
template<class R, class A1, class A2, class A3, class A4>
_FunctionBinderBase* CreateBinder(R(*fn)(A1, A2, A3, A4))
{
	auto b = new FunctionBinder4<R, A1, A2, A3, A4>();
	b->m_function = fn;
	return b;
}
template<class R, class A1, class A2, class A3, class A4, class A5>
_FunctionBinderBase* CreateBinder(R(*fn)(A1, A2, A3, A4, A5))
{
	auto b = new FunctionBinder5<R, A1, A2, A3, A4, A5>();
	b->m_function = fn;
	return b;
}
template<class R, class A1, class A2, class A3, class A4, class A5, class A6>
_FunctionBinderBase* CreateBinder(R(*fn)(A1, A2, A3, A4, A5, A6))
{
	auto b = new FunctionBinder6<R, A1, A2, A3, A4, A5, A6>();
	b->m_function = fn;
	return b;
}
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
_FunctionBinderBase* CreateBinder(R(*fn)(A1, A2, A3, A4, A5, A6, A7))
{
	auto b = new FunctionBinder7<R, A1, A2, A3, A4, A5, A6, A7>();
	b->m_function = fn;
	return b;
}
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
_FunctionBinderBase* CreateBinder(R(*fn)(A1, A2, A3, A4, A5, A6, A7, A8))
{
	auto b = new FunctionBinder8<R, A1, A2, A3, A4, A5, A6, A7, A8>();
	b->m_function = fn;
	return b;
}
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
_FunctionBinderBase* CreateBinder(R(*fn)(A1, A2, A3, A4, A5, A6, A7, A8, A9))
{
	auto b = new FunctionBinder9<R, A1, A2, A3, A4, A5, A6, A7, A8, A9>();
	b->m_function = fn;
	return b;
}
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
_FunctionBinderBase* CreateBinder(R(*fn)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10))
{
	auto b = new FunctionBinder10<R, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10>();
	b->m_function = fn;
	return b;
}
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
_FunctionBinderBase* CreateBinder(R(*fn)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11))
{
	auto b = new FunctionBinder11<R, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11>();
	b->m_function = fn;
	return b;
}
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
_FunctionBinderBase* CreateBinder(R(*fn)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12))
{
	auto b = new FunctionBinder12<R, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12>();
	b->m_function = fn;
	return b;
}
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
_FunctionBinderBase* CreateBinder(R(*fn)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13))
{
	auto b = new FunctionBinder13<R, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13>();
	b->m_function = fn;
	return b;
}
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
_FunctionBinderBase* CreateBinder(R(*fn)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14))
{
	auto b = new FunctionBinder14<R, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14>();
	b->m_function = fn;
	return b;
}
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
_FunctionBinderBase* CreateBinder(R(*fn)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15))
{
	auto b = new FunctionBinder15<R, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15>();
	b->m_function = fn;
	return b;
}
template<class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
_FunctionBinderBase* CreateBinder(R(*fn)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16))
{
	auto b = new FunctionBinder16<R, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16>();
	b->m_function = fn;
	return b;
}

template<class R, class...T>
void BindFunction(IScriptEnvironment* env, R(*function)(T...), const char* name)
{
	FunctionBinding binding;
	binding.m_returnType = TypeToScriptType<R>();
	binding.m_name = name;
	binding.m_params.reserve(sizeof...(T));
	binding.m_binder = CreateBinder(function);
	TypeToScriptTypeArray<T...>(binding.m_params.data());
	env->BindFunction(binding);
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
