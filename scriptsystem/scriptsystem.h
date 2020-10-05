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

#include "containers/string.h"
#include "containers/array.h"

#define BEGIN_SCRIPTSYS_NAMESPACE namespace scriptsystem {
#define END_SCRIPTSYS_NAMESPACE }

BEGIN_SCRIPTSYS_NAMESPACE

/*
====================================================

General structures

====================================================
*/

typedef struct
{
	bool debuginfo;
} script_compile_settings_t;

typedef struct
{
	size_t stack_size;

} script_env_settings_t;

typedef struct
{
	void* script_data;
} script_t;

typedef struct
{
	uint32_t exit_code;
} script_result_t;

typedef struct
{
	bool error;
	const char* error_desc;
	const char* source;
	int line, col;
} script_compile_result_t;

/*
====================================================

Debugging structures and info

====================================================
*/

typedef struct
{
	script_t* script;
	const char* file;
	int line;
} script_breakpoint_t;

typedef struct
{
	const char* name;
	size_t stack_index;
} script_debug_var_t;

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

typedef struct
{
	EDataType type;
	union {
		bool bval;
		const char* sval;
		void* vval; // userdata
		long long ival;
		double fval;
	};
} script_value_t;

/* Functions defined by the script itself */
typedef struct
{
	const char* name;
	EDataType return_type;
	Array<EDataType> params;
} script_function_t;

/*
====================================================

Binding types

====================================================
*/

/* Fields may only reside inside of classes */
class CFieldBinding
{
public:
	EDataType m_dataType;
	uint16_t m_flags;
	const char* m_name;
	class CClassBinding* m_class;
	size_t m_offset;
};

/* Functions are either static member functions or functions that reside in some namespace */
class CFunctionBinding
{
public:
	const char* m_name;
	Array<EDataType> m_params;
	EDataType m_returnType;
};

/* Method bindings are for member functions */
class CMethodBinding
{
public:
	const char* m_name;
	Array<EDataType> m_params;
	EDataType m_returnType;
};

class CClassBinding
{
public:
	const char* m_name;
	Array<CFieldBinding> m_fields;
	Array<CMethodBinding> m_methods;
};

/* Variables only reside outside of classes in namespaces */
class CVariableBinding
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

Script Environment Class
	Handles execution of scripts

====================================================
*/

class IScriptEnvironment
{
public:
	/* Initializes the script env. The feature bits specified in features are the things we need to enable. It's computed
		based on the GetEnvFeatures() bits */
	virtual bool Init(script_env_settings_t settings, uint64_t features) = 0;

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
	virtual script_t* CompileScript(const char* source_file, const char* buf, size_t buf_size, script_compile_settings_t settings) = 0;

	/**
	 * @brief Delete a script object
	 */
	virtual void FreeScript(script_t* scr) = 0;

	/**
	 * @brief Returns the script compile log
	 */
	virtual script_compile_result_t GetCompileLog() = 0;

	/**
	 * @brief Sets a breakpoint in the script
	 */
	virtual void SetBreakpoint(const script_t& script, const char* file, int line) = 0;

	/**
	 * @brief Clears a breakpoint in the script
	 */
	virtual void ClearBreakpoint(script_t& script, const script_breakpoint_t& bp) = 0;
	virtual void ClearAllBreakpoints(script_t& script) = 0;

	/**
	 * @brief Returns a list of all script variables for this stack
	 */
	virtual Array<script_debug_var_t> GetScriptVariables(script_t& scr, int level) = 0;

	/**
	 * @brief Sets the value of a stack variable.
	 */
	virtual void SetScriptVariableValue(script_t& scr, script_debug_var_t& var, EDataType type, void* value) = 0;


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
	 * Returns a list of the functions defined in the script, along with their info
	 * ONLY ENABLED IF SCRIPT WAS COMPILED WITH DEBUG INFO
	 */
	virtual Array<script_function_t> GetScriptFunctions(const script_t& scr) = 0;

	/**
	 * Puts function info about the named function into funcinfo. Returns true if the function is found (and thus funcinfo was modified)
	 * If the function is not found, returns false and funcinfo is not modified.
	 * ONLY ENABLED IF SCRIPT WAS COMPILED WITH DEBUG INFO
	 */
	virtual bool GetScriptFunctionInfo(const script_t& scr, const char* func, script_function_t& funcinfo) = 0;

	virtual script_value_t CallFunctionInternal(script_t& script, const char* function, EDataType expected_return, std::initializer_list<script_value_t> params) = 0;


	/*
	====================================================

	Implemented in script_main.cpp
		These functions are shared between ALL
		script VMs

	====================================================
	*/

	template<class R, class...T>
	void BindFunction(const char* name, R(*fn)(T...));

	/**
	 * Executes the specified function in the script with the specified args.
	 * This will verify the argument types are indeed correct before calling.
	 * This will return a script_value_t, containing the returned value from the script.
	 */
	template<class...T>
	script_value_t CallFunction(script_t& scr, const char* name, T...args);



};

END_SCRIPTSYS_NAMESPACE
