#include <squirrel.h>
#include "../scriptsystem.h"

#include <memory.h>

using namespace scriptsystem;

struct script_internal_data_sq
{
	uint32_t id;
	char *file;
};

uint32_t g_CurrentID = 0;
Array<class CSquirrelScriptSystem *> g_SQEnvs;
#if 0
/* Forward decls */
void
Squirrel_CompileErrorCallback(HSQUIRRELVM vm, const SQChar *desc, const SQChar *source, SQInteger line, SQInteger col);

class CSquirrelScriptSystem : public IScriptEnvironment
{
public:
	HSQUIRRELVM m_vm;
	uint64_t m_features;
	bool m_initialized = false;

	/* Holds the last debug info */
	char m_lastErrorDesc[4096];
	char m_lastErrorSrc[4096];
	int m_lastErrorLine;
	int m_lastErrorCol;

	/* Initializes the script env. The feature bits specified in features are the things we need to enable. It's computed
		based on the GetEnvFeatures() bits */
	virtual bool Init(ScriptEnvSettings_t settings, uint64_t features) override
	{
		/* Set features, open VM */
		m_features = features;
		m_vm = sq_open(settings.stack_size);
		m_initialized = true;

		/* Set error handlers */
		sq_setcompilererrorhandler(m_vm, Squirrel_CompileErrorCallback);

		/* Clear out the debug info */
		m_lastErrorDesc[0] = m_lastErrorSrc[0] = 0;
		m_lastErrorLine = m_lastErrorCol = 0;

		/* Add to global list of Squirrel envs, needed for proper error callbacks */
		g_SQEnvs.push_back(this);
	}

	virtual void Shutdown() override
	{
		m_initialized = false;
		sq_close(m_vm);
	}

	/* Returns a list of supported features by this environment */
	virtual uint64_t GetEnvFeatures() override
	{
		uint64_t features = 0;
		features |= (uint64_t) EScriptEnvFeatures::GC_RC;
		features |= (uint64_t) EScriptEnvFeatures::GC_SWEEP;
		features |= (uint64_t) EScriptEnvFeatures::DEBUG_BACKTRACE;
		features |= (uint64_t) EScriptEnvFeatures::DEBUG_BREAK;
		features |= (uint64_t) EScriptEnvFeatures::DEBUG_ENUM_LOCALS;
		features |= (uint64_t) EScriptEnvFeatures::DEBUG_SWITCH_LEVELS;
		// features |= (uint64_t)EScriptEnvFeatures::DEBUG_WATCH;
		return features;
	}

	/**
	 * @brief Compiles a script from the buffer
	 * @param buf Pointer to UTF-8 buffer
	 * @param buf_size size of buffer. Should be NULL terminated anyway
	 * @param settings Settings to compile with
	 * @return If the compile succeeded, returns a pointer to a new script, otherwise, NULL
	 */
	virtual Script_t *
	CompileScript(const char *file, const char *buf, size_t buf_size, ScriptCompileSettings_t settings) override
	{
		sq_enabledebuginfo(m_vm, settings.debuginfo);

		if (SQ_FAILED(sq_compilebuffer(m_vm, buf, buf_size, file, true)))
		{
			return NULL;
		}
		/* Allocate and return the script handle */
		Script_t *script = (Script_t *) malloc(sizeof(Script_t));
		script->script_data = malloc(sizeof(script_internal_data_sq));

		script_internal_data_sq idat;
		idat.id = g_CurrentID++;
		idat.file = strdup(file);

		memcpy(script->script_data, &idat, sizeof(script_internal_data_sq));

		return script;
	}

	/**
	 * @brief Delete a script object
	 */
	virtual void FreeScript(Script_t *scr) override
	{
		script_internal_data_sq *idat = (script_internal_data_sq *) scr->script_data;
		free(idat->file);
		free(scr->script_data);
		free(scr);
	}

	/**
	 * @brief Returns the script compile log
	 */
	virtual ScriptCompileResult_t GetCompileLog() override
	{
		ScriptCompileResult_t res;
		res.col = m_lastErrorCol;
		res.line = m_lastErrorLine;
		res.source = m_lastErrorSrc;
		res.error_desc = m_lastErrorDesc;
		res.error = true;
		return res;
	}

	/**
	 * @brief Sets a breakpoint in the script
	 */
	virtual void SetBreakpoint(const Script_t &script, const char *file, int line) = 0;

	/**
	 * @brief Clears a breakpoint in the script
	 */
	virtual void ClearBreakpoint(Script_t &script, const ScriptBreakpoint_t &bp) = 0;

	virtual void ClearAllBreakpoints(Script_t &script) = 0;

	/**
	 * @brief Returns a list of all script variables for this stack
	 */
	virtual Array<ScriptDebugVar_t> GetScriptVariables(Script_t &scr, int level) = 0;

	/**
	 * @brief Sets the value of a stack variable.
	 */
	virtual void SetScriptVariableValue(Script_t &scr, ScriptDebugVar_t &var, EDataType type, void *value) = 0;

	/**
	 * @brief Changes the runtime state of the VM
	 * Suspend will cause execution to halt and resume will cause it to resume.
	 * Always call GetEnvironmentState after calling Suspend/Resume to verify the state
	 * has indeed changed.
	 */
	virtual void Suspend() override
	{
		sq_suspendvm(m_vm);
	}

	virtual void Resume() override
	{
		sq_resume(m_vm, false, true);
	}

	virtual EScriptEnvState GetEnvironmentState() = 0;

	/**
	 * Returns a list of the functions defined in the script, along with their info
	 */
	virtual Array<ScriptFunction_t> GetScriptFunctions(const Script_t &scr) override
	{
	}

	/**
	 * Puts function info about the named function into funcinfo. Returns true if the function is found (and thus funcinfo was modified)
	 * If the function is not found, returns false and funcinfo is not modified.
	 */
	virtual bool GetScriptFunctionInfo(const Script_t &scr, const char *func, ScriptFunction_t &funcinfo) override
	{
	}

	virtual ScriptValue_t CallFunctionInternal(Script_t &script, const char *function, EDataType expected_return,
	                                           std::initializer_list<ScriptValue_t> params)
	{
		sq_pushroottable(m_vm);
		sq_pushstring(m_vm, function, -1); // Push function string, -1 means compute the length yourself
		sq_get(m_vm, -2);                   // Get function from root table
		sq_pushroottable(m_vm);                   // 'this' object

		/* Push all of our arguments */
		for (auto arg : params)
		{
			switch (arg.type)
			{
				case EDataType::BOOL:
					sq_pushbool(m_vm, arg.bval);
					break;
				case EDataType::INTEGER:
					sq_pushinteger(m_vm, arg.ival);
					break;
				case EDataType::USERPOINTER:
					sq_pushuserpointer(m_vm, arg.vval);
					break;
				case EDataType::FLOAT:
					sq_pushfloat(m_vm, (SQFloat) arg.fval);
					break;
				case EDataType::USERDATA:
					sq_pushuserpointer(m_vm, arg.vval);
					break;
				case EDataType::STRING:
					sq_pushstring(m_vm, arg.sval, -1);
					break;
				default:
					break;
			}
		}

		/* Call the function finally */
		if(SQ_FAILED(sq_call(m_vm, params.size() + 1, expected_return != EDataType::NONE, true)))
		{

		}

		/* save return value */
		if (expected_return != EDataType::NONE)
		{
			ScriptValue_t ret;
			SQInteger top = sq_gettop(m_vm);
			switch (expected_return)
			{
				case EDataType::BOOL:
				{
					SQBool _out;
					if(SQ_FAILED(sq_getbool(m_vm, top, &_out))){

					}
					ret.bval = _out;
					break;
				}
				case EDataType::INTEGER:
				{
					SQInteger _out;
					if(SQ_FAILED(sq_getinteger(m_vm, top, &_out))) {

					}
					ret.ival = _out;
					break;
				}
				case EDataType::USERPOINTER:
				{
					SQUserPointer _out;
					if(SQ_FAILED(sq_getuserpointer(m_vm, top, &_out))){

					}
					ret.vval = _out;
					break;
				}
				case EDataType::FLOAT:
				{
					SQFloat _out;
					if(SQ_FAILED(sq_getfloat(m_vm, top, &_out))) {

					}
					ret.fval = _out;
					break;
				}
				case EDataType::USERDATA:
				{
					SQUserPointer _usrPtr;
					SQUserPointer _typeTag;
					if(SQ_FAILED(sq_getuserdata(m_vm, top, &_usrPtr, &_typeTag))) {

					}
					ret.vval = _usrPtr;
					break;
				}
				default:
				{
					break;
				}
			}
			sq_pop(m_vm, 1);
		}

		/* Pop roottable and function name */
		sq_pop(m_vm, 2);
	}
};

void
Squirrel_CompileErrorCallback(HSQUIRRELVM vm, const SQChar *desc, const SQChar *source, SQInteger line, SQInteger col)
{
	/* Try to find the script env to use */
	CSquirrelScriptSystem *env = NULL;
	for (auto x : g_SQEnvs)
	{
		if (x->m_vm == vm)
		{
			env = x;
			break;
		}
	}
	// Did we somehow not find an env??
	if (!env)
		return;

	strncpy(env->m_lastErrorDesc, desc, sizeof(env->m_lastErrorDesc));
	strncpy(env->m_lastErrorSrc, source, sizeof(env->m_lastErrorSrc));
	env->m_lastErrorLine = line;
	env->m_lastErrorCol = col;
}
#endif