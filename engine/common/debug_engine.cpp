/*
 *
 * debug_engine.cpp - Engine debugging functions/convars/commands
 *
 */
#include "common.h"
#include "build.h"
#include "tier1/dbg.h"
#include "tier1/concommand.h"
#include "tier1/convar.h"
#include "debug.h"
#include <signal.h>

CONCOMMAND(assert_break_all, "Breaks all assertions", 0)
{
	dbg::EnableAssertBreak();
}

CONCOMMAND(assert_unbreak_all, "Un-breaks all asserts", 0)
{
	dbg::DisableAssertBreak();
}

CONCOMMAND(assert_break, "Breaks the specified assert (file line)", 0)
{
	if(argc < 2)
	{
		Msg("Usage: assert_break <file> <line>\n");
		return;
	}
	int line = Q_atoi(argv[2]);
	dbg::BreakAssert(argv[1], line);
	Msg("Enabled break on assert at %s:%u\n", argv[1], line);
}

CONCOMMAND(assert_unbreak, "Unbreaks the specified assert (file line)", 0)
{
	if(argc < 2)
	{
		Msg("Usage: assert_unbreak <file> <line>\n");
		return;
	}
	int line = Q_atoi(argv[2]);
	dbg::UnBreakAssert(argv[1], line);
	Msg("Disabled break on assert at %s:%u\n", argv[1], line);
}

CONCOMMAND(assert_disable_all, "Disables all asserts", 0)
{
	dbg::DisableAsserts();
}

CONCOMMAND(assert_enable_all, "Enables all asserts", 0)
{
	dbg::EnableAsserts();
}

CONCOMMAND(assert_disable, "Disables the specified assert (file line)", 0)
{
	if(argc < 2)
	{
		Msg("Usage: assert_disable <file> <line>\n");
		return;
	}
	int line = Q_atoi(argv[2]);
	dbg::DisableAssert(argv[1], line);
	Msg("Disabled assert at %s:%u\n", argv[1], line);
}

CONCOMMAND(assert_enable, "Enables the specified assert (file line)", 0)
{
	if(argc < 2)
	{
		Msg("Usage: assert_enable <file> <line>\n");
		return;
	}
	int line = Q_atoi(argv[2]);
	dbg::EnableAssert(argv[1], line);
	Msg("Enabled assert at %s:%u\n", argv[1], line);
}

CONCOMMAND(assert_all_once, "Enables assert once on all asserts", 0)
{
	dbg::EnableAssertOnce();
}

CONCOMMAND(assert_all_unlimited, "Disables assert once on all asserts", 0)
{
	dbg::DisableAssertOnce();
}

CONCOMMAND(assert_list, "Lists out detailed info about all assertsions that have been hit", 0)
{
	Array<dbg::CAssert> assertList = dbg::GetAssertList();

	Msg("Assertion list:\n");
	for(const auto& a : assertList)
		Msg("%s:%u    exp: %s   times hit: %u\n", a.m_file, a.m_line, a.m_exp, a.m_timesHit);
}

CONCOMMAND(assert_test, "Fires a test assertion", 0)
{
	Assert(0);
}

CONCOMMAND(assert_test2, "Fires a test assertion", 0)
{
	Assert(0);
}

CONCOMMAND(raise, "Raises a signal", 0)
{
	if(argc < 2)
	{
		Msg("Usage: raise <sig>\n");
		return;
	}
	const char* sig = argv[1];
	if(!Q_strcmp(sig, "SIGABRT"))
		raise(SIGABRT);
	else if(!Q_strcmp(sig, "SIGSEGV"))
		raise(SIGSEGV);
	else if(!Q_strcmp(sig, "SIGINT"))
		raise(SIGINT);
	else if(!Q_strcmp(sig, "SIGILL"))
		raise(SIGILL);
	else if(!Q_strcmp(sig, "SIGFPE"))
		raise(SIGFPE);
	else if(!Q_strcmp(sig, "SIGTERM"))
		raise(SIGTERM);
#ifndef _WIN32
	else if(!Q_strcmp(sig, "SIGKILL"))
		raise(SIGKILL);
	else if(!Q_strcmp(sig, "SIGTRAP"))
		raise(SIGTRAP);
	else if(!Q_strcmp(sig, "SIGHUP"))
		raise(SIGHUP);
#endif
	else
		Msg("Unknown signal name\n");
}