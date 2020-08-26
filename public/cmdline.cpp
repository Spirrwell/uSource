#include "common.h"
#include "crtlib.h"
#include "cmdline.h"

CCommandLine::CCommandLine() :
	m_argc(0),
	m_argv(nullptr)
{

}

CCommandLine::~CCommandLine()
{

}

void CCommandLine::Set(int argc, char **argv)
{
	m_argc = argc;
	m_argv = argv;
}

bool CCommandLine::Find(const char *arg)
{
	for(int i = 0; i < m_argc; i++)
	{
		if(Q_strcmp(arg, m_argv[i]) == 0)
			return true;
	}
	return false;
}

const char *CCommandLine::FindString(const char *arg)
{
	for(int i = 0; i < m_argc; i++)
	{
		if(Q_strcmp(arg, m_argv[i]) == 0)
		{
			if(i < m_argc-1)
				return m_argv[i+1];
		}
	}
	return nullptr;
}

int CCommandLine::FindInt(const char *arg, int _default)
{
	for(int i = 0; i < m_argc; i++)
	{
		if(Q_strcmp(arg, m_argv[i]) == 0)
		{
			if(i < m_argc-1)
			{
				int out;
				if(Q_strint(m_argv[i+1], out))
					return out;
				else
					return _default;
			}
		}
	}
	return _default;
}

float CCommandLine::FindFloat(const char *arg, float _default)
{
	for(int i = 0; i < m_argc; i++)
	{
		if(Q_strcmp(arg, m_argv[i]) == 0)
		{
			if(i < m_argc-1)
			{
				float out;
				if(Q_strfloat(m_argv[i+1], out))
					return out;
				else
					return _default;
			}
		}
	}
	return _default;
}

CCommandLine &GlobalCommandLine()
{
	static CCommandLine g_cmdline;
	return g_cmdline;
}
