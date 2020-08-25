#include "debug.h"
#include "threadtools.h"
#include "crtlib.h"
#include "containers/array.h"

#include <signal.h>


using namespace dbg;

/* TODO: Organize this by file to speed up searches */
Array<CAssert>* g_passertions = nullptr;

CThreadMutex* g_passert_mutex = nullptr;

static void DbgInit()
{
	static bool binit = false;
	if(binit) return;
	if(!g_passert_mutex)
		g_passert_mutex = new CThreadMutex();
	if(!g_passertions)
		g_passertions = new Array<CAssert>();
	binit = true;
}

/* Internal functions (No locking done) */
static CAssert& _FindOrCreateAssert(const char* file, int line, const char* exp)
{
	for(auto& x : *g_passertions)
	{
		if(Q_strcmp(file, x.File()) == 0)
			return x;
	}
	CAssert assert(line, file, "");
	g_passertions->push_back(assert);
	return (*g_passertions)[g_passertions->size()-1];
}

static CAssert& _CreateAssert(const char* file, int line, const char* exp)
{
	CAssert assert(line, file, exp);
	g_passertions->push_back(assert);
	return (*g_passertions)[g_passertions->size()-1];
}

static CAssert* _FindAssert(const char* file, int line)
{
	for(auto& x : *g_passertions)
	{
		if(Q_strcmp(file, x.m_file) == 0 && x.m_line == line)
			return &x;
	}
	return nullptr;
}

CAssert dbg::FindOrCreateAssert(const char *file, int line, const char* exp)
{
	DbgInit();
	auto lock = g_passert_mutex->RAIILock();
	return _FindOrCreateAssert(file, line, exp);
}

void dbg::DisableAssert(const char *file, int line)
{
	DbgInit();
	auto lock = g_passert_mutex->RAIILock();

	CAssert* ass = _FindAssert(file, line);
	if(ass)
		ass->m_ignored = true;
}

void dbg::EnableAssert(const char *file, int line)
{
	DbgInit();
	auto lock = g_passert_mutex->RAIILock();

	CAssert* ass = _FindAssert(file, line);
	if(ass)
		ass->m_ignored = false;
}

CAssert dbg::FindAssert(const char *file, int line)
{
	DbgInit();
	auto lock = g_passert_mutex->RAIILock();
	CAssert* ass = _FindAssert(file, line);
	if(!ass) return CAssert(0, "", "");
	return *ass;
}

bool dbg::IsAssertEnabled(const char *file, int line)
{
	DbgInit();
	auto lock = g_passert_mutex->RAIILock();

	CAssert* ass = _FindAssert(file, line);
	if(!ass) return false;
	return !ass->m_ignored;
}

void dbg::CreateAssert(const char *file, int line, const char *exp)
{
	DbgInit();
	auto lock = g_passert_mutex->RAIILock();
	_CreateAssert(file, line, exp);
}

bool dbg::FireAssertion(const char *file, int line, const char* exp)
{
	DbgInit();
	auto lock = g_passert_mutex->RAIILock();

	CAssert& ass = _FindOrCreateAssert(file, line, exp);
	ass.m_timesHit++; // The assertion's hit counter will be marked each and every time, even if the assert is ignored
	ass.m_exp = exp; // Just going to update the expression here as it might not be set before the assert is actually hit

	if(ass.m_break)
		raise(SIGINT);

	return !ass.m_ignored;
}

void dbg::BreakAssert(const char *file, int line)
{
	DbgInit();
	auto lock = g_passert_mutex->RAIILock();

	CAssert& ass = _FindOrCreateAssert(file, line, "");
	ass.m_break = true;
}

void dbg::UnBreakAssert(const char *file, int line)
{
	DbgInit();
	auto lock = g_passert_mutex->RAIILock();

	CAssert& ass = _FindOrCreateAssert(file, line, "");
	ass.m_break = false;
}

bool dbg::WasAssertHit(const char *file, int line)
{
	DbgInit();
	auto lock = g_passert_mutex->RAIILock();

	CAssert* ass = _FindAssert(file, line);
	if(!ass) return false;
	return ass->m_timesHit != 0;
}

CAssert::CAssert(int line, const char* file, const char* exp) :
	m_file(""),
	m_line(0),
	m_ignored(false),
	m_exp(exp),
	m_timesHit(0),
	m_break(false)
{
}

CAssert::~CAssert()
{
}
