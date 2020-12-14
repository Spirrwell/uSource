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
#include "static_helpers.h"

#include "tier1/concommand.h"
#include "tier1/convar.h"
#include "tier1/tier1.h"

#undef min
#undef max
#include <fstream>

/* Cvar callbacks */
void xprof_enabled_callback(const char* old, const char* _new);
void xprof_frame_time_callback(const char* old, const char* _new);
void xprof_output_file_callback(const char* old, const char* _new);
void xprof_frame_time_sample_callback(const char* old, const char* _new);
void xprof_frame_time_buffer_callback(const char* old, const char* _new);
void xprof_enable_frame_time_sampler_callback(const char* old, const char* _new);

/* Static init and shutdown callbacks */
void xprof_engine_static_init();
void xprof_engine_init();
void xprof_engine_shutdown(CXProf&);

/* (kinda) global props */
String g_outputFileName;

Convar xprof_enabled("xprof_enabled", "1", FCVAR_ARCHIVE, "Enables or disables xprof", xprof_enabled_callback);
Convar xprof_frame_time("xprof_frame_time", "1000", FCVAR_ARCHIVE, "Time between budget resets in ms", xprof_frame_time_callback);
Convar xprof_output_file("xprof_output_file", "xprof.json", FCVAR_ARCHIVE, "The file in which to output xprof data", xprof_output_file_callback);

/* For frame time recording */
Convar xprof_enable_frame_time_sampler("xprof_enable_frame_time_sampler", "1", FCVAR_ARCHIVE, "Enables the frame time counter", xprof_enable_frame_time_sampler_callback);
Convar xprof_frame_time_sample("xprof_frame_time_sample_interval", "1", FCVAR_ARCHIVE, "Time between frame time samples in the buffer.", xprof_frame_time_sample_callback);
Convar xprof_frame_time_buffer_size("xprof_frame_time_buffer_size", "4096", FCVAR_ARCHIVE, "Number of samples to store in the ring buffer. One unit corresponds to one xprof_frame_time_interval, so 4096 here and a 1 second log interval means 4096 seconds",
				    xprof_frame_time_buffer_callback);

static CStaticInitWrapper<xprof_engine_static_init> g_xprofStaticInitWrapper;

CONCOMMAND(xprof_show_budget, "Displays a budget (name_budget)", 0)
{
	if(Cmd_Argc() < 2)
	{
		Con_Printf("Usage: xprof_show_budget <budget>\n");
		return;
	}
	const char* category = Cmd_Argv(1);
	CXProfNode* pCategory = GlobalXProf().FindCategory(category);

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
	for(auto x : GlobalXProf().Nodes())
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
	GlobalXProf().EndFrame();
}



void xprof_enabled_callback(const char* old, const char* _new)
{
	if(Q_atoi(_new))
	{
		GlobalXProf().Enable();
		Con_Printf("XProf enabled.\n");
	}
	else
	{
		GlobalXProf().Disable();
		Con_Printf("XProf disabled.\n");
	}
}

void xprof_frame_time_callback(const char* old, const char* _new)
{
}


void xprof_output_file_callback(const char* old, const char* _new)
{
	g_outputFileName = _new;
}

void xprof_frame_time_sample_callback(const char* old, const char* _new)
{
	if(Q_strcmp(old, _new) != 0)
	{
		GlobalXProf().SetFrameSampleInterval(Q_atof(_new));
	}
}

void xprof_frame_time_buffer_callback(const char* old, const char* _new)
{
	if(Q_strcmp(old,_new) != 0)
	{
		int size = Q_atoi(_new);
		if(size > 0)
		{
			GlobalXProf().SetFrameCountBufferSize(size);
			Con_Printf("Set XProf frame sample buffer to %i\n", size);
		}
		else
			Con_Printf("Frame sample buffer size should be positive, and must be a number.");
	}
}

void xprof_enable_frame_time_sampler_callback(const char* old, const char* _new)
{
	if(Q_strcmp(old, _new) != 0)
	{
		XProfFeatures features = GlobalXProf().Features();
		features.EnableFrameTimeCounter = (Q_atoi(_new) == 1);
		GlobalXProf().SetFeatures(features);
	}
}

void xprof_engine_init()
{
	/* XPROF SETUP */
	GlobalXProf().Enable();
	XProfFeatures xprofFeatures = GlobalXProf().Features();
	xprofFeatures.EnableFrameTimeCounter = xprof_enable_frame_time_sampler.GetBool();
	xprofFeatures.EnableThreadSafety = true;
	GlobalXProf().SetFeatures(xprofFeatures);

	GlobalXProf().SetFrameCountBufferSize(xprof_frame_time_buffer_size.GetInt());
	GlobalXProf().SetFrameSampleInterval(xprof_frame_time_sample.GetFloat());
}

void xprof_engine_shutdown(CXProf& xprof)
{
	std::ofstream fs;
	fs.open(g_outputFileName.c_str());

	if(fs.good())
	{
		GlobalXProf().DumpToJSON(fs);
		fs.close();
	}
}

void xprof_engine_static_init()
{
	GlobalXProf().HookShutdown(xprof_engine_shutdown);
	g_outputFileName = "xprof.json";
}