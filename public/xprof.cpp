#include "xprof.h"
#include "port.h"
#include "xash3d_types.h"
#include "crtlib.h"
#undef min
#undef max
#include <stack>
#include <stdio.h>

CXProf* g_pXProf = NULL;

struct xprof_node_desc_t
{
	const char* name;
	unsigned long long budget;
};

static xprof_node_desc_t g_categories[] =
{
	{XPROF_CATEGORY_OTHER, 0},
	{XPROF_CATEGORY_MATH, 0},
	{XPROF_CATEGORY_RENDERING, 0},
	{XPROF_CATEGORY_MAINUI, 0},
	{XPROF_CATEGORY_PHYSICS, 0},
	{XPROF_CATEGORY_SOUND, 0},
	{XPROF_CATEGORY_MAPLOAD, 0},
	{XPROF_CATEGORY_TEXLOAD, 0},
	{XPROF_CATEGORY_MODELOAD, 0},
	{XPROF_CATEGORY_SOUNDLOAD, 0},
	{XPROF_CATEGORY_FILESYSTEM, 0},
	{XPROF_CATEGORY_CRTFUNC, 0},
	{XPROF_CATEGORY_NETWORK, 0},
	{XPROF_CATEGORY_CVAR, 0},
	{XPROF_CATEGORY_CONCOMMAND, 0},
	{XPROF_CATEGORY_SCRIPTING, 0},
	{XPROF_CATEGORY_KVPARSE, 0},
	{XPROF_CATEGORY_PARSING, 0},
	{XPROF_CATEGORY_GAME_CLIENT_INIT, 0},
	{XPROF_CATEGORY_GAME_SERVER_INIT, 0},
	{XPROF_CATEGORY_CLIENT_THINK, 0},
	{XPROF_CATEGORY_SERVER_THINK, 0},
	{XPROF_CATEGORY_UNZIP, 0},
	{XPROF_CATEGORY_LZSS, 0},
	{XPROF_CATEGORY_COMMON, 0},
	{XPROF_CATEGORY_FRAME, 0}
};


class CXProfInit 
{
public:
	CXProfInit()
	{
		if(!g_pXProf) g_pXProf = new CXProf();
	}

	~CXProfInit()
	{
		delete g_pXProf;
	}
};
static CXProfInit g_xprof_init_wrapper;

CXProf& GlobalXProf()
{
	return *g_pXProf;
}

/* Constructor is NOT thread-safe, obviously! */
CXProf::CXProf() :
	m_enabled(true),
	m_lastFrameTime(),
	m_flags(0)
{
	for(int i = 0; i < MAX_NODESTACKS; i++)
	{
		m_nodeStack[i] = std::stack<CXProfNode*>();
		m_nodeStackThreads[i] = 0;
	}
	for(int i = 0; i < (sizeof(g_categories) / sizeof(xprof_node_desc_t)); i++)
	{
		this->AddCategoryNode(g_categories[i].name, g_categories[i].budget);
	}
}

CXProf::~CXProf()
{
	if(m_flags & XPROF_DUMP_ON_EXIT)
	{
		for(int i = 0; i < (sizeof(g_categories) / sizeof(g_categories[0])); i++)
			this->DumpCategoryTree(g_categories[i].name);
	}
}

void CXProf::AddCategoryNode(const char* name, unsigned long long budget)
{
	auto lock = m_mutex.RAIILock();
	CXProfNode* node = new CXProfNode(name, "", "", budget);
	node->m_parent = nullptr;
	node->m_root = node;
	node->m_category = name;
	node->m_function = name;
	m_nodes.push_back(node);
}

void CXProf::PushNode(CXProfNode* node)
{
	auto lock = m_mutex.RAIILock();

	/* first, get the nodestack index for this thread */
	auto threadid = platform::GetCurrentThreadId();
	int index = -1;
	for(int i = 0; i < MAX_NODESTACKS; i++)
	{
		if(m_nodeStackThreads[i] == threadid)
		{
			index = i;
			break;
		}
	}

	/* Not found? Loop until a free one is found */
	if(index == -1)
	{
		for(index = 0; index < MAX_NODESTACKS; index++)
		{
			if(m_nodeStackThreads[index] == 0)
			{
				m_nodeStackThreads[index] = threadid;
				break;
			}
		}
	}

	std::stack<CXProfNode*>* nodestack = &m_nodeStack[index];

	CXProfNode* parent = nullptr;

	if(nodestack->empty())
		parent = this->FindCategory(node->m_category);
	else
		parent = nodestack->top();
	
	if(!parent)
	{
		printf("Internal error while pushing node %s: Parent was nullptr. Category=%s\n",
			node->Name(), node->m_category);
		return;
	}

	if(!node->m_added)
	{
		node->m_parent = parent;
		node->m_added = true;
		node->m_root = parent->m_root;
		node->m_parent->m_children.push_back(node);
		node->m_timeBudget = node->m_timeBudget ? node->m_timeBudget : parent->m_timeBudget;
		node->m_category = node->m_parent->m_category;
	}
	nodestack->push(node);
}

void CXProf::PopNode()
{
	auto threadid = platform::GetCurrentThreadId();
	for(int i = 0; i < MAX_NODESTACKS; i++)
	{
		if(m_nodeStackThreads[i] == threadid)
		{
			if(m_nodeStack[i].empty()) return;
			m_nodeStack[i].pop();
			return;
		}
	}
}

CXProfNode* CXProf::CreateNode(const char* category, const char* func, const char* file, unsigned long long budget)
{
	CXProfNode* node = new CXProfNode(category, func, file, budget);
	this->PushNode(node);
	return node;
}

void CXProf::DumpAllNodes(int(*printFn)(const char*,...))
{
	for(auto x : m_nodes)
	{
		DumpCategoryTree(x->m_category, printFn);
	}
}

class CXProfNode* CXProf::FindCategory(const char* category)
{
	for(auto x : this->m_nodes)
	{
		if(Q_strcmp(category, x->m_category) == 0)
			return x;
	}
	return nullptr;
}

void CXProf::DumpCategoryTree(const char* cat, int(*printFn)(const char*,...))
{
	for(auto x : m_nodes)
	{
		if(Q_strcmp(x->m_category, cat) == 0)
		{
			this->DumpNodeTreeInternal(x, 0, printFn);
			return;
		}
	}
}

#define FILL_TABS for(int i = 0; i < indent; i++) printFn("\t")

void CXProf::DumpNodeTreeInternal(CXProfNode* node, int indent, int(*printFn)(const char*,...))
{
	/* Print node name */
	FILL_TABS;
	printFn("%s\n", node->Name());

	/* Print total time */
	FILL_TABS;
	printFn("Total time: %llu us\n", node->m_absTotal / 1000);

	/* Print average time */
	FILL_TABS;
	printFn("Average per-frame time: %llu us\n", node->m_avgTime / 1000);

	/* Print total allocs */
	FILL_TABS;
	printFn("Total allocs: %llu for %llu bytes total\n", node->m_totalAllocs, node->m_totalAllocBytes);

	for(auto x : node->Children())
		DumpNodeTreeInternal(x, indent+1);
}

void CXProf::Frame(float dt)
{
	auto lock = m_mutex.RAIILock();
	/* Simply record the last frame time */
	m_lastFrameTime = platform::GetCurrentTime();
}

void CXProf::ClearNodes()
{
	auto lock = m_mutex.RAIILock();
	for(auto x : this->m_nodes)
	{
		/* Only delete the non-category nodes */
		for(auto g : x->m_children)
		{
			delete g;
		}
	}
}

void CXProf::Disable()
{
	auto lock = m_mutex.RAIILock();
	m_enabled = false;
}

void CXProf::Enable()
{
	auto lock = m_mutex.RAIILock();
	m_enabled = true;
}

bool CXProf::Enabled() const
{
	auto lock = m_mutex.RAIILock();
	return  m_enabled;
}

void CXProf::ReportAlloc(size_t sz)
{
	auto lock = m_mutex.RAIILock();
	CXProfNode* node = CurrentNode();
	if(!node) return;
	node->ReportAlloc(sz);
}

void CXProf::ReportRealloc(size_t oldsize, size_t newsize)
{
	auto lock = m_mutex.RAIILock();
	CXProfNode* node = CurrentNode();
	if(!node) return;
	node->ReportRealloc(oldsize, newsize);
}

void CXProf::ReportFree()
{
	auto lock = m_mutex.RAIILock();
	CXProfNode* node = CurrentNode();
	if(!node) return;
	node->ReportFree();
}

class CXProfNode *CXProf::CurrentNode()
{
	auto threadid = platform::GetCurrentThreadId();
	int index = -1;
	for(int i = 0; i < MAX_NODESTACKS; i++)
	{
		if(m_nodeStackThreads[i] == threadid)
		{
			index = i;
			break;
		}
	}

	if(index == -1) return nullptr;
	if(m_nodeStack[index].empty()) return nullptr;

	return m_nodeStack[index].top();
}

/*=======================================================
 *
 *      CXProfNode
 *
 *======================================================= */

CXProfNode::CXProfNode(const char* category, const char* function, const char* file, unsigned long long budget) :
	m_timeBudget(budget),
	m_function(function),
	m_file(file),
	m_logTests(false),
	m_parent(nullptr),
	m_root(nullptr),
	m_testQueueSize(0),
	m_category(category),
	m_totalTime(0),
	m_added(false),
	m_lastSampleTime(),
	m_absTotal(0),
	m_totalAllocBytes(0),
	m_allocBudget(0),
	m_frameAllocBytes(0),
	m_frameAllocs(0),
	m_frameFrees(0),
	m_totalAllocs(0),
	m_totalFrees(0),
	m_freeBudget(0),
	m_avgFrees(0),
	m_avgAllocBytes(0),
	m_avgAllocs(0),
	m_numFrames(0),
	m_avgTime(0)
{

}

CXProfNode::~CXProfNode()
{

}

unsigned long long CXProfNode::GetRemainingBudget() const
{
	auto lock = m_mutex.RAIILock();
	unsigned long long remaining = m_totalTime;
	for(auto node : this->m_children)
		remaining += node->m_totalTime;
	return remaining;
}

void CXProfNode::ResetBudget()
{
	auto lock = m_mutex.RAIILock();
	this->m_totalTime = 0;
	for(auto node : this->m_children)
	{
		node->ResetBudget();
	}
}

void CXProfNode::SubmitTest(CXProfTest* test)
{
	auto lock = m_mutex.RAIILock();
	this->m_lastSampleTime = platform::GetCurrentTime();

	unsigned long long elapsed = (test->stop.to_ns() - test->start.to_ns());
	this->m_totalTime += elapsed;
	this->m_absTotal += elapsed;
	DoFrame();
}

void CXProfNode::SetBudget(unsigned long long int time)
{
	auto lock = m_mutex.RAIILock();
	m_timeBudget = time;
}

unsigned long long CXProfNode::GetBudget() const
{
	auto lock = m_mutex.RAIILock();
	return m_timeBudget;
}

List<CXProfNode *> CXProfNode::Children() const
{
	auto lock = this->m_mutex.RAIILock();
	return this->m_children;
}

void CXProfNode::AddChild(CXProfNode *node)
{
	auto lock = this->m_mutex.RAIILock();
	m_children.push_back(node);
}

Array<CXProfTest> CXProfNode::TestQueue() const
{
	auto lock = this->m_mutex.RAIILock();
	return m_testQueue;
}

void CXProfNode::DoFrame()
{
	/* Check if the last frame reset time has taken place after our last sample. If so, reset the per-frame budget time and stuff */
	if(GlobalXProf().LastFrameTime() > this->m_lastSampleTime)
	{
		m_numFrames++;

		/* Update the average allocations and stuff */
		this->m_avgFrees = ((m_numFrames-1) * m_avgFrees + m_frameFrees) / m_numFrames;
		this->m_avgAllocs = ((m_numFrames-1) * m_avgAllocs + m_frameAllocs) / m_numFrames;
		this->m_avgAllocBytes = ((m_numFrames-1) * m_avgAllocBytes + m_frameAllocBytes) / m_numFrames;

		/* Update frame time average */
		this->m_avgTime = ((m_numFrames-1) * m_avgTime + m_totalTime) / m_numFrames;

		this->m_totalTime = 0;
		this->m_frameAllocs = 0;
		this->m_frameAllocBytes = 0;
		this->m_frameFrees = 0;
	}
}

void CXProfNode::ReportAlloc(size_t size)
{
	auto lock = this->m_mutex.RAIILock();
	m_totalAllocs++;
	m_frameAllocs++;
	m_frameAllocBytes += size;
	m_totalAllocBytes += size;
	DoFrame();
}

void CXProfNode::ReportFree()
{
	auto lock = this->m_mutex.RAIILock();
	m_totalFrees++;
	m_frameFrees++;
	DoFrame();
}

void CXProfNode::ReportRealloc(size_t old, size_t newsize)
{
	auto lock = this->m_mutex.RAIILock();
	int ds = newsize - old;
	m_totalAllocs++;
	m_frameAllocs++;
	m_totalFrees++; // Gonna count this as a free too. Need a better way to detect this
	m_totalAllocBytes += ds;
	m_frameAllocBytes += ds;
	DoFrame();
}
