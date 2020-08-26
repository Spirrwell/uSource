/*
 *
 * cmdline.h - Commandline handling
 *
 */
#pragma once

class CCommandLine
{
private:
	char** m_argv;
	int m_argc;
	CCommandLine();
	~CCommandLine();
	friend CCommandLine& GlobalCommandLine();
public:
	void Set(int argc, char** argv);

	bool Find(const char* arg);
	const char* FindString(const char* arg);
	int FindInt(const char* arg, int _default = 0);
	float FindFloat(const char* arg, float _default = 0);

	int ArgCount() const { return m_argc; }
	int argc() const { return m_argc; };
	const char* const* argv() const { return m_argv; }
	const char* const* Args() const { return m_argv; }

};

CCommandLine& GlobalCommandLine();