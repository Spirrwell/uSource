#include "xprof.h"
#include "port.h"
#include "xash3d_types.h"
#include "crtlib.h"
#undef min
#undef max
#include <stack>
#include <stdio.h>

CXProf* g_pXProf = NULL;

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

CXProf::CXProf()
{
	for(int i = 0; i < MAX_NODESTACKS; i++)
	{
		m_nodeStack[i] = std::stack<CXProfNode*>();
		m_nodeStackThreads[i] = 0;
	}
	this->AddCategoryNode(XPROF_CATEGORY_OTHER, 1e6);
}

CXProf::~CXProf()
{
	this->DumpCategoryTree(XPROF_CATEGORY_OTHER);
}

void CXProf::AddCategoryNode(const char* name, unsigned long long budget)
{
	CXProfNode* node = new CXProfNode(name, "", "", budget);
	node->m_parent = nullptr;
	node->m_root = node;
	node->m_category = name;
	node->m_function = name;
	m_nodes.push_back(node);
}

void CXProf::PushNode(CXProfNode* node)
{
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

class CXProfNode* CXProf::FindCategory(const char* category)
{
	for(auto x : this->m_nodes)
	{
		if(Q_strcmp(category, x->m_category) == 0)
			return x;
	}
	return nullptr;
}

void CXProf::DumpCategoryTree(const char* cat)
{
	for(auto x : m_nodes)
	{
		if(Q_strcmp(x->m_category, cat) == 0)
		{
			this->DumpNodeTreeInternal(x, 0);
			return;
		}
	}
}

void CXProf::DumpNodeTreeInternal(CXProfNode* node, int indent)
{
	for(int i = indent; i > 0; i--) printf("\t");
	printf("%s\n", node->Name());
	for(int i = indent; i >= 0; i--) printf("\t");
	printf("Total time: %llu us\n", node->GetRemainingBudget() / 1000);
	for(auto x : node->Children())
		DumpNodeTreeInternal(x, indent+1);
}

CXProfNode::CXProfNode(const char* category, const char* function, const char* file, unsigned long long budget) :
	m_timeBudget(budget),
	m_function(function),
	m_file(file),
	m_logTests(false),
	m_parent(nullptr),
	m_root(nullptr),
	m_testQueueSize(0),
	m_category(category),
	m_totalTime(0)
{

}

unsigned long long CXProfNode::GetRemainingBudget() const
{
	unsigned long long remaining = m_totalTime;
	for(auto node : this->m_children)
		remaining += node->m_totalTime;
	return remaining;
}

void CXProfNode::ResetBudget()
{
	this->m_totalTime = 0;
	for(auto node : this->m_children)
		node->m_totalTime = 0; 
}

void CXProfNode::SubmitTest(CXProfTest* test)
{
	this->m_totalTime += (test->stop.to_ns() - test->start.to_ns());
}