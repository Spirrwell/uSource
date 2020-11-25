#include <squirrel.h>
#include <sqstdaux.h>
#include <sqstdio.h>
#include "../scriptsystem.h"

#include <memory.h>
#include <list>

using namespace scriptsystem;

class SquirrelScript : public IScript
{
public:
	class SquirrelEnvironment* m_env;
	SQInteger m_script;
public:
	SquirrelScript(class SquirrelEnvironment* env);
	~SquirrelScript();

	ScriptBreakpoint_t SetBreakpoint(const char *file, int line) override;

	void ClearBreakpoint(const ScriptBreakpoint_t &bp) override;

	void ClearAllBreakpoints() override;

	Array<ScriptDebugVar_t> GetStackVariables(int level) override;

	void SetStackVariable(ScriptDebugVar_t &var, ScriptValue_t value) override;

	Array<ScriptFunction_t> GetScriptFunctions() override;

	bool GetScriptFunctionInfo(const char *func, ScriptFunction_t &funcinfo) override;

	ScriptValue_t InvokeFunction(const char *function, EDataType expected_return,
	                             const std::vector<ScriptValue_t>& params) override;

	ScriptClass_t *GetExtensionClasses(IScript &script, int &num) override;

	IScriptEnvironment &Environment() const override;

public:
	/* Non override methods */
	void unload();
};


class SquirrelEnvironment : public IScriptEnvironment
{
public:
	ScriptEnvSettings_t m_settings;
	uint64_t m_features;
	bool m_init;
	HSQUIRRELVM m_vm;
	std::list<SquirrelScript*> m_scripts;
	EScriptEnvState m_state;
	std::vector<FunctionBinding> m_functions;
public:
	SquirrelEnvironment();
	~SquirrelEnvironment();

	bool Init(ScriptEnvSettings_t settings, uint64_t features) override;

	void Shutdown() override;

	uint64_t GetEnvFeatures() override;

	IScript *
	CompileScript(const char *source_file, const char *buf, size_t buf_size, ScriptCompileSettings_t settings,
	              ScriptCompileResult_t &result) override;

	IScript *LoadModule(const char *file_path, const void *data, size_t data_len, ScriptCompileSettings_t settings,
	                    ScriptCompileResult_t &result) override;

	void FreeScript(IScript *scr) override;

	void UnloadScript(IScript *scr) override;

	void ReloadScript(IScript *scr) override;

	void Suspend() override;

	void Resume() override;

	EScriptEnvState GetEnvironmentState() override;

	bool InvokeEvent(const char *eventName, std::initializer_list<ScriptValue_t> params) override;

	bool BindFunction(FunctionBinding &binding) override;

	bool BindClass(ClassBinding &binding) override;

	bool BindExtensionClass(ClassBinding &binding) override;

public:
	bool PushArgs(const std::vector<ScriptValue_t>& a);
	ScriptValue_t GetTop(EDataType type);
};

/*
====================================================

Script Environment Class
	Handles execution of scripts

====================================================
*/

static void SquirrelEnvironmentCompilerHandler(HSQUIRRELVM,const SQChar * /*desc*/,const SQChar * /*source*/,SQInteger /*line*/,SQInteger /*column*/);

bool SquirrelEnvironment::Init(ScriptEnvSettings_t settings, uint64_t features)
{
	m_settings = settings;

	if((features ^ GetEnvFeatures()) != 0)
	{
		m_init = false;
		return false;
	}

	m_vm = sq_open(settings.stack_size);

	if(!m_vm)
		 return false;

	sq_setcompilererrorhandler(m_vm, SquirrelEnvironmentCompilerHandler);
	sq_enabledebuginfo(m_vm, true);
	sqstd_register_iolib(m_vm);

	return true;
}

void SquirrelEnvironment::Shutdown()
{
	for(auto x : m_scripts)
	{
		((SquirrelScript*)x)->unload();
		delete x;
	}
	m_scripts.clear();
	sq_close(m_vm);
}

uint64_t SquirrelEnvironment::GetEnvFeatures()
{
	uint64_t features;
	features |= (uint64_t)EScriptEnvFeatures::DEBUG_BACKTRACE;
	features |= (uint64_t)EScriptEnvFeatures::DEBUG_BREAK;
	features |= (uint64_t)EScriptEnvFeatures::DEBUG_ENUM_LOCALS;
	features |= (uint64_t)EScriptEnvFeatures::DEBUG_SWITCH_LEVELS;
	features |= (uint64_t)EScriptEnvFeatures::DEBUG_WATCH;
	features |= (uint64_t)EScriptEnvFeatures::DYNAMIC_RELOAD;
	features |= (uint64_t)EScriptEnvFeatures::GC_RC;
	return features;
}

IScript *SquirrelEnvironment::CompileScript(const char *source_file, const char *buf, size_t buf_size,
                                            ScriptCompileSettings_t settings, ScriptCompileResult_t &result)
{
	SQRESULT res = sq_compilebuffer(m_vm, buf, buf_size, source_file, true);
	if(SQ_FAILED(res))
	{
		return nullptr;
	}

	SquirrelScript* script = new SquirrelScript(this);
	script->m_script = sq_gettop(m_vm);
	m_scripts.push_back(script);
	return script;

}

IScript *SquirrelEnvironment::LoadModule(const char *file_path, const void *data, size_t data_len,
                                         ScriptCompileSettings_t settings, ScriptCompileResult_t &result)
{
	/* Should never be called for us */
	return nullptr;
}

void SquirrelEnvironment::FreeScript(IScript *scr)
{
	if(!scr) return;
	for(auto it = m_scripts.begin(); it != m_scripts.end(); ++it)
	{
		if(*it == scr)
		{
			m_scripts.erase(it);
			((SquirrelScript*)scr)->unload();
			delete scr;
		}
	}
}

void SquirrelEnvironment::UnloadScript(IScript *scr)
{
	((SquirrelScript*)scr)->unload();
}

void SquirrelEnvironment::ReloadScript(IScript *scr)
{

}

void SquirrelEnvironment::Suspend()
{
	if(!SQ_FAILED(sq_suspendvm(m_vm))) {
		m_state = EScriptEnvState::SUSPENDED;
	}
}

void SquirrelEnvironment::Resume()
{
	if(!SQ_FAILED(sq_resume(m_vm, false, false))) {
		m_state = EScriptEnvState::RUNNING;
	}
}

EScriptEnvState SquirrelEnvironment::GetEnvironmentState()
{
	return EScriptEnvState::SUSPENDED;
}

bool SquirrelEnvironment::InvokeEvent(const char *eventName, std::initializer_list<ScriptValue_t> params)
{
	return false;
}

bool SquirrelEnvironment::BindFunction(FunctionBinding &binding)
{
	m_functions.push_back(binding);
	return true;
}

bool SquirrelEnvironment::BindClass(ClassBinding &binding)
{
	return false;
}

bool SquirrelEnvironment::BindExtensionClass(ClassBinding &binding)
{
	return false;
}

bool SquirrelEnvironment::PushArgs(const std::vector<ScriptValue_t>& a)
{
	for(const auto& x : a)
	{
		switch(x.type)
		{
			case EDataType::BOOL:
				sq_pushbool(m_vm, x.bval);
				break;
			case EDataType::USERPOINTER:
				sq_pushuserpointer(m_vm, x.vval);
				break;
			case EDataType::INTEGER:
				sq_pushinteger(m_vm, x.ival);
				break;
			case EDataType::FLOAT:
				sq_pushfloat(m_vm, x.fval);
				break;
			case EDataType::USERDATA:
				sq_pushuserpointer(m_vm, x.vval);
				break;
			case EDataType::STRING:
				sq_pushstring(m_vm, x.sval, strlen(x.sval));
				break;
			default:
				break;
		}
	}
	return true;
}

ScriptValue_t SquirrelEnvironment::GetTop(EDataType type)
{
	return ScriptValue_t();
}

static void SquirrelEnvironmentCompilerHandler(HSQUIRRELVM vm, const SQChar * desc, const SQChar * source, SQInteger line, SQInteger column)
{

}



/*
====================================================

Script Class

====================================================
*/

ScriptBreakpoint_t SquirrelScript::SetBreakpoint(const char *file, int line)
{
	return ScriptBreakpoint_t();
}

void SquirrelScript::ClearBreakpoint(const ScriptBreakpoint_t &bp)
{

}

void SquirrelScript::ClearAllBreakpoints()
{

}

Array<ScriptDebugVar_t> SquirrelScript::GetStackVariables(int level)
{
	return Array<ScriptDebugVar_t>();
}

void SquirrelScript::SetStackVariable(ScriptDebugVar_t &var, ScriptValue_t value)
{

}

Array<ScriptFunction_t> SquirrelScript::GetScriptFunctions()
{
	return Array<ScriptFunction_t>();
}

bool SquirrelScript::GetScriptFunctionInfo(const char *func, ScriptFunction_t &funcinfo)
{
	return false;
}

ScriptValue_t SquirrelScript::InvokeFunction(const char *function, EDataType expected_return,
                                             const std::vector<ScriptValue_t>& params)
{
	m_env->PushArgs(params);
	if(SQ_FAILED(sq_call(m_env->m_vm, params.size(), expected_return != EDataType::NONE, true))) {
		ScriptValue_t v = {};
		v.type = EDataType::BAD;
		return v;
	}
	if(expected_return != EDataType::NONE) {
		return m_env->GetTop(expected_return);
	}
	ScriptValue_t v = {};
	v.type = EDataType::NONE;
	return v;
}

ScriptClass_t *SquirrelScript::GetExtensionClasses(IScript &script, int &num)
{
	return nullptr;
}

IScriptEnvironment &SquirrelScript::Environment() const
{
	return *m_env;
}

SquirrelScript::SquirrelScript(struct SquirrelEnvironment *env) :
	m_env(env),
	m_script(0)
{

}

SquirrelScript::~SquirrelScript()
{

}

void SquirrelScript::unload()
{

}

static SQInteger GenericSquirrelFunction(HSQUIRRELVM vm)
{
	return 0;
}