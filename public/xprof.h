/*
xprof.h - Realtime profiling
*/
#pragma once

#include "containers/list.h"
#include "containers/array.h"
#include "platformspec.h"

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
#define XPROF_CATEGROY_CRTFUNC "CrtFunctions"
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

class CXProf
{
private:
	List<class CXProfNode*> m_nodes;
	std::stack<class CXProfNode*> m_nodeStack[MAX_NODESTACKS];
	unsigned long long m_nodeStackThreads[MAX_NODESTACKS];
public:
	CXProf();
	~CXProf();

	void AddCategoryNode(const char* name, unsigned long long budget);
	
	class CXProfNode* CreateNode(const char* category, const char* func, const char* file, unsigned long long budget);
	void PushNode(class CXProfNode* node);
	void PopNode();

	class CXProfNode* FindCategory(const char* name);

	/* Returns a list of category nodes */
	const List<class CXProfNode*>& Nodes() const { return m_nodes; };

	/**
	 * @brief attempts to find a parent node for the current thread
	 * @return pointer to the parent node, or nullptr if there are no parents
	 */ 
	class CXProfNode* FindParent();

	void DumpCategoryTree(const char* cat);

private:
	void DumpNodeTreeInternal(class CXProfNode* node, int indent);
};

class CXProfNode
{
private:
	CXProfNode* m_parent; /* Pointer to the node that is one above this, or null */
	CXProfNode* m_root; /* Pointer to the "category" node. Aka the absolute root. Nullptr if this is the category */
	List<CXProfNode*> m_children;
	const char* m_function;
	bool m_added;
	unsigned long long m_timeBudget;
	unsigned long long m_totalTime; /* Total time for THIS NODE */
	bool m_logTests;
	unsigned int m_testQueueSize;
	Array<class CXProfTest> m_testQueue;
	const char* m_file;
	const char* m_category;

	friend class CXProf;

public:
	CXProfNode(const char* category, const char* function, const char* file, unsigned long long budget);
	~CXProfNode();

	/**
	 * @brief Submit a new XProf time test to the node
	 */ 
	void SubmitTest(class CXProfTest* test);

	void SetBudget(unsigned long long time) { m_timeBudget = time; };
	unsigned long long GetBudget(unsigned long long time) const { return m_timeBudget; };

	/**
	 * @brief Get or reset the remaining budget constraints
	 */ 
	unsigned long long GetRemainingBudget() const;
	void ResetBudget();

	const char* Name() const { return m_function; };

	CXProfNode* Parent() const { return m_parent; };

	const List<CXProfNode*>& Children() const { return m_children; };
	void AddChild(CXProfNode* node) { m_children.push_back(node); };

	const Array<CXProfTest>& TestQueue() const { return m_testQueue; };
};

extern CXProf* g_pXProf;

/* defined in header to avoid cross DLL calls */
class CXProfTest
{
public:
	CXProfNode* node;
	platform::time_t start, stop;

	CXProfTest(CXProfNode* node)
	{
		this->node = node;
		start = platform::GetCurrentTime();
		g_pXProf->PushNode(node);
	}

	~CXProfTest()
	{
		stop = platform::GetCurrentTime();
		this->node->SubmitTest(this);
		g_pXProf->PopNode();
	}
};

#ifndef _MSC_VER

#define XPROF_NODE(category) \
static CXProfNode* __xprof_node = new CXProfNode((category), __PRETTY_FUNCTION__, __FILE__, 0); \
CXProfTest __xprof_test(__xprof_node); 

#else

#define XPROF_NODE(category) \
static CXProfNode* __xprof_node = new CXProfNode((category), __FUNCSIG__, __FILE__, 0); \
CXProfTest __xprof_test(__xprof_node); 


#endif // _MSC_VER