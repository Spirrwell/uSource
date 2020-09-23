/*
xprof.h - Realtime profiling
*/
#pragma once

#include "containers/list.h"
#include "containers/array.h"
#include "platformspec.h"
#include "threadtools.h"

#include <initializer_list>
#include <stdio.h>
#include <stack>

#define MAX_NODESTACK_DEPTH 32
#define MAX_NODESTACKS 64

#define XPROF_CATEGORY_OTHER "Other"
#define XPROF_CATEGORY_MATH "MathFuncs"
#define XPROF_CATEGORY_RENDERING "Rendering"
#define XPROF_CATEGORY_MAINUI "MainUI"
#define XPROF_CATEGORY_PHYSICS "PhysicsLoading"
#define XPROF_CATEGORY_SOUND "SoundLoading"
#define XPROF_CATEGORY_MAPLOAD "MapLoading"
#define XPROF_CATEGORY_TEXLOAD "TextureLoading"
#define XPROF_CATEGORY_MODELOAD "ModelLoading"
#define XPROF_CATEGORY_SOUNDLOAD "SoundLoading"
#define XPROF_CATEGORY_FILESYSTEM "Filesystem"
#define XPROF_CATEGORY_CRTFUNC "CrtFunctions"
#define XPROF_CATEGORY_NETWORK "Network"
#define XPROF_CATEGORY_CVAR "ConsoleVar"
#define XPROF_CATEGORY_CONCOMMAND "ConsoleCommand"
#define XPROF_CATEGORY_SCRIPTING "Scripting"
#define XPROF_CATEGORY_KVPARSE "KeyValuesParsing"
#define XPROF_CATEGORY_PARSING "FileParsing"
#define XPROF_CATEGORY_GAME_CLIENT_INIT "ClientInit"
#define XPROF_CATEGORY_GAME_SERVER_INIT "ServerInit"
#define XPROF_CATEGORY_CLIENT_THINK "ClientThink"
#define XPROF_CATEGORY_SERVER_THINK "ServerThink"
#define XPROF_CATEGORY_UNZIP "Unzip"
#define XPROF_CATEGORY_LZSS "LZSS"
#define XPROF_CATEGORY_COMMON "Common"
#define XPROF_CATEGORY_FRAME "Frame"

/* XProf Flags */
#define XPROF_DUMP_ON_EXIT (1<<0)

#undef GetCurrentTime

namespace xprof
{
	constexpr inline unsigned long long SecondsToNs(unsigned long long sec)
	{
		return sec * 1000000000;
	}

	constexpr inline unsigned long long SecondsToUs(unsigned long long sec)
	{
		return sec * 1000000;
	}

	constexpr inline unsigned long long SecondsToMs(unsigned long long sec)
	{
		return sec * 1000;
	}

	constexpr inline unsigned long long MsToNs(unsigned long long sec)
	{
		return sec * 1000000;
	}

	constexpr inline unsigned long long FpsToNs(unsigned long long fps)
	{
		return (1000/fps) * 1000000;
	}

	constexpr inline float NsToMsF(unsigned long long ns)
	{
		return (ns / (float)1000000);
	}
}

class EXPORT CXProf
{
private:
	List<class CXProfNode*> m_nodes;
	std::stack<class CXProfNode*> m_nodeStack[MAX_NODESTACKS];
	unsigned long long m_nodeStackThreads[MAX_NODESTACKS];
	bool m_enabled;
	mutable CThreadMutex m_mutex;
	platform::time_t m_lastFrameTime;
	unsigned int m_flags;

public:
	CXProf();
	~CXProf();

	/* Creates a new node category */
	/* THREAD SAFE */
	void AddCategoryNode(const char* name, unsigned long long budget);

	class CXProfNode* CreateNode(const char* category, const char* func, const char* file, unsigned long long budget);
	void PushNode(class CXProfNode* node);
	void PopNode();

	/* Returns a pointer to the current node.
	 * NOT thread-safe. Lock before calling this! */
	class CXProfNode* CurrentNode();

	platform::time_t LastFrameTime() const { return m_lastFrameTime; };

	/* Use to report memory allocations/frees */
	/* Thread-safe without locks */
	void ReportAlloc(size_t sz);
	void ReportRealloc(size_t oldsize, size_t newsize);
	void ReportFree();

	class CXProfNode* FindCategory(const char* name);

	void SetFlag(unsigned int flag) { m_flags |= flag; };
	void ClearFlag(unsigned int flag) { m_flags &= ~flag; };

	/* Returns a list of category nodes */
	/* THREAD SAFE */
	List<class CXProfNode*> Nodes()
	{
		auto lock = m_mutex.RAIILock();
		return m_nodes;
	};

	/* Tree dump functions */
	/* NOT THREAD SAFE */
	void DumpAllNodes(int(*printFn)(const char*,...) = printf);
	void DumpCategoryTree(const char* cat, int(*printFn)(const char*,...) = printf);

	/* A "frame". Resets all per-frame budgets */
	/* THREAD SAFE */
	void Frame(float dt = 0.0f);

	/* Enables or disables xprof */
	/* THREAD SAFE */
	bool Enabled() const;
	void Enable();
	void Disable();

	void ClearNodes();
private:
	void DumpNodeTreeInternal(class CXProfNode* node, int indent, int(*printFn)(const char*,...) = printf);
};

class EXPORT CXProfNode
{
private:
	CXProfNode* m_parent; /* Pointer to the node that is one above this, or null */
	CXProfNode* m_root; /* Pointer to the "category" node. Aka the absolute root. Nullptr if this is the category */
	List<CXProfNode*> m_children;
	const char* m_function;
	bool m_added;
	unsigned long long m_timeBudget;
	unsigned long long m_totalTime; /* Total time for THIS NODE */
	unsigned long long m_absTotal; /* Total time absolute. Not per-frame */
	unsigned long long m_avgTime; /* Average per-frame time */
	bool m_logTests;
	unsigned int m_testQueueSize;
	Array<class CXProfTest> m_testQueue;
	const char* m_file;
	const char* m_category;
	mutable CThreadSpinlock m_mutex;
	platform::time_t m_lastSampleTime; /* Used to record the last sample time of the node, which is used to determine if this was sampled in the last frame or not */

	unsigned long long m_numFrames; // Total number of frames

	/* Stuff for malloc tracking */
	unsigned long long m_allocBudget; /* Per-frame malloc budget */
	unsigned long long m_freeBudget; /* Per-frame free budget */

	unsigned long long m_frameAllocs; /* Number of allocations per frame */
	unsigned long long m_frameAllocBytes; /* Number of bytes allocated in this frame */
	unsigned long long m_frameFrees; /* Number of calls to free */

	unsigned long long m_totalAllocs;
	unsigned long long m_totalAllocBytes;
	unsigned long long m_totalFrees;

	/* Averages for allocs and such */
	unsigned int m_avgAllocs;
	unsigned int m_avgAllocBytes;
	unsigned int m_avgFrees;

	friend class CXProf;

	/**
	 * Counter reports for the memory allocators and such
	 * These will be called by CXProf
	 */
	void ReportAlloc(size_t size);
	void ReportFree();
	void ReportRealloc(size_t old, size_t newsize);

public:
	CXProfNode(const char* category, const char* function, const char* file, unsigned long long budget);
	~CXProfNode();

	CXProfNode(const CXProfNode& other)
	{
		/* Copy all-nontrivial types */
		memcpy(this, &other, sizeof(CXProfNode));
		/* Copy trivial types */
		m_children = other.m_children;
		m_testQueue = other.m_testQueue;
		m_lastSampleTime = other.m_lastSampleTime;
	}

	/* Returns a copy of this node for reading */
	/* Also note that this will intentionally unset fields like m_parent, m_root and m_children */
	/* THREAD SAFE */
	CXProfNode LockRead()
	{
		auto lock = m_mutex.RAIILock();
		/* Make a copy of the node and then clear all fields out that we do not want the accessor to use */
		CXProfNode copy = *this;
		copy.m_parent = copy.m_root = nullptr;
		copy.m_testQueue.clear();
		copy.m_children.clear();
		return *this;
	}

	/**
	 * @brief Submit a new XProf time test to the node
	 */
	void SubmitTest(class CXProfTest* test);

	void SetBudget(unsigned long long time);
	unsigned long long GetBudget() const;

	/**
	 * @brief Get or reset the remaining budget constraints
	 */
	unsigned long long GetRemainingBudget() const;
	void ResetBudget();

	/**
	 * @brief Resets anything that might need to be reset
	 */
	void DoFrame();

	/* Accessors */
	/* THREAD SAFE */
	const char* Name() const { return m_function; };
	const char* File() const { return m_file; };
	const char* Category() const { return m_category; };
	CXProfNode* Parent() const { return m_parent; };
	List<CXProfNode*> Children() const;
	void AddChild(CXProfNode* node);
	Array<CXProfTest> TestQueue() const;
};

#ifdef LIBPUBLIC
EXPORT extern CXProf* g_pXProf;
#else
IMPORT extern CXProf* g_pXProf;
#endif

EXPORT CXProf& GlobalXProf();

/* defined in header to avoid cross DLL calls */
class EXPORT CXProfTest
{
public:
	CXProfNode* node;
	platform::time_t start, stop;
	bool m_disabled;

	CXProfTest(CXProfNode* node) :
		m_disabled(false)
	{
		m_disabled = !g_pXProf->Enabled();
		this->node = node;
		start = platform::GetCurrentTime();
		g_pXProf->PushNode(node);
	}

	~CXProfTest()
	{
		if(m_disabled) return;
		stop = platform::GetCurrentTime();
		this->node->SubmitTest(this);
		g_pXProf->PopNode();
	}
};

#ifdef ENABLE_XPROF

#ifndef _MSC_VER

#define XPROF_NODE(category) \
static CXProfNode* __xprof_node = new CXProfNode((category), __PRETTY_FUNCTION__, __FILE__, 0); \
CXProfTest __xprof_test(__xprof_node);

#else

#define XPROF_NODE(category) \
static CXProfNode* __xprof_node = new CXProfNode((category), __FUNCSIG__, __FILE__, 0); \
CXProfTest __xprof_test(__xprof_node);

#endif // msc

#else

#define XPROF_NODE(c)

#endif
