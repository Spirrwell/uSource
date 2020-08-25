/*
 *
 * debug.h - Support code for in-engine debugging
 *
 */
#pragma once

#include "build.h"

#define BEGIN_DBG_NAMESPACE namespace dbg {
#define END_DBG_NAMESPACE }

BEGIN_DBG_NAMESPACE

class CAssert
{
public:
	int m_line;
	const char* m_file;
	const char* m_exp;
	bool m_ignored : 1;
	bool m_break : 1;
	int m_timesHit;

public:
	CAssert(int line, const char* file, const char* exp);
	~CAssert();

	bool Enabled() const { return !m_ignored; }
	const char* File() const { return m_file; }
	int Line() const { return m_line; }
};

/* Called to fire an assertion. Returns true if the assertion is enabled and a message should be printed */
bool FireAssertion(const char* file, int line, const char* exp);

/* Creates a new assertion */
void CreateAssert(const char* file, int line, const char* exp);

/* Finds or creates a new assertion, always returns a valid pointer */
CAssert FindOrCreateAssert(const char* file, int line, const char* exp);

/* Disables the assertion at the specified line and file */
void DisableAssert(const char* file, int line);
void EnableAssert(const char* file, int line);

/* Tries to find an assertion that's already registered. Returns nullptr if not found */
CAssert FindAssert(const char* file, int line);

/* Returns true if an assertion is enabled */
bool IsAssertEnabled(const char* file, int line);

/* Causes a break into debugger when the specified assertion is hit */
void BreakAssert(const char* file, int line);
void UnBreakAssert(const char* file, int line);

/* Returns true if the assertion was hit */
bool WasAssertHit(const char* file, int line);

END_DBG_NAMESPACE