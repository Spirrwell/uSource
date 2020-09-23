/**
 *
 * xprof_engine.cpp - Engine component of the profiler
 *
 */

#ifdef _WIN32
// i seriously don't understand windows, we need to include this here, otherwise we get a bunch of junk syntax errors later
#include <winsock2.h>
#endif

#include "xprof.h"
#include <stddef.h>
#include "common.h"
#include "common/common.h"

#include "tier1/concommand.h"
#include "tier1/convar.h"
#include "tier1/tier1.h"

void xprof_enabled_callback(const char* old, const char* _new);
void xprof_frame_time_callback(const char* old, const char* _new);

Convar xprof_enabled("xprof_enabled", "1", FCVAR_ARCHIVE, "Enables or disables xprof", xprof_enabled_callback);
Convar xprof_frame_time("xprof_frame_time", "1000", FCVAR_ARCHIVE, "Time between budget resets in ms", xprof_frame_time_callback);

CONCOMMAND(xprof_show_budget, "Displays a budget (name_budget)", 0)
{
	if(Cmd_Argc() < 2)
	{
		Con_Printf("Usage: xprof_show_budget <budget>\n");
		return;
	}
	const char* category = Cmd_Argv(1);
	CXProfNode* pCategory = g_pXProf->FindCategory(category);

	if(!pCategory)
	{
		Con_Printf("No such category '%s'\n", category);
		return;
	}
	unsigned long long remaining = pCategory->GetRemainingBudget();
	remaining = remaining ? remaining : 1;
	Con_Printf("%s: [%f ms]/[%f ms] (usage/max)          %f%% used\n", category, xprof::NsToMsF(pCategory->GetRemainingBudget()),
		xprof::NsToMsF(pCategory->GetBudget()), (pCategory->GetBudget() / (float)remaining));
}

CONCOMMAND(xprof_list_categories, "Lists all registered categories", 0)
{
	for(auto x : g_pXProf->Nodes())
	{
		Con_Printf("%s\n", x->Category());
	}
}

CONCOMMAND(xprof_set_budget, "Sets the node's budget", 0)
{

}

CONCOMMAND(xprof_get_budget, "Gets the category's budget", 0)
{

}

CONCOMMAND(xprof_dump_nodes, "Dumps all xprof nodes", 0)
{

}

CONCOMMAND(xprof_reset_budgets, "Resets all budget groups", 0)
{
	g_pXProf->Frame();
}


void xprof_enabled_callback(const char* old, const char* _new)
{
	if(Q_atoi(_new))
	{
		g_pXProf->Enable();
		Con_Printf("XProf enabled.\n");
	}
	else
	{
		g_pXProf->Disable();
		Con_Printf("XProf disabled.\n");
	}
}

void xprof_frame_time_callback(const char* old, const char* _new)
{
}