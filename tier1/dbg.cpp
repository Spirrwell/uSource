#include "dbg.h"

#include <stdarg.h>
#include <stdlib.h>

static unsigned char g_color_red[3] = {255, 0, 0};
static unsigned char g_color_yellow[3] = {255, 255, 0};

const char* _vpaste(const char* fmt, ...)
{
	static thread_local char tmpbuf[8192];

	va_list val;
	va_start(val, fmt);
	vsnprintf(tmpbuf, sizeof(tmpbuf), fmt, val);
	va_end(val);

	return tmpbuf;
}

void Msg(const char* fmt, ...)
{
	// msg functions should be much more thread-safe
	char tmp[4096];
	va_list va;
	va_start(va, fmt);
	vsnprintf(tmp, sizeof(tmp), fmt, va);
	va_end(va);
	g_pLogSystem->Log(LOGCHAN_GENERAL, 0, tmp);

}

void Warn(const char* fmt, ...)
{
	char tmp[4096];
	//g_pLogSystem->SetColor(g_color_red);
	va_list va;
	va_start(va, fmt);
	vsnprintf(tmp, sizeof(tmp), fmt, va);
	va_end(va);
	g_pLogSystem->Log(LOGCHAN_WARN, LOGVERBO_HIGHEST, tmp);
	//g_pLogSystem->ClearColor();
}

void Error(const char* fmt, ...)
{
	char tmp[4096];
	//g_pLogSystem->SetColor(g_color_red);
	va_list va;
	va_start(va, fmt);
	vsnprintf(tmp, sizeof(tmp), fmt, va);
	va_end(va);
	g_pLogSystem->Log(LOGCHAN_ERROR, LOGVERBO_HIGHEST, tmp);
	//g_pLogSystem->ClearColor();
}

void FatalError(const char* fmt, ...)
{
	char tmp[8192];
	va_list va;
	va_start(va, fmt);
	vsnprintf(tmp, sizeof(tmp), fmt, va);
	va_end(va);
	g_pEngineDebug->HostError(tmp);
}

void MsgC(const char color[3], const char* fmt, ...)
{
	char tmp[4096];
	g_pLogSystem->SetColor(color);
	va_list va;
	va_start(va, fmt);
	vsnprintf(tmp, sizeof(tmp), fmt, va);
	va_end(va);
	g_pLogSystem->Log(LOGCHAN_GENERAL, 0, tmp);
	g_pLogSystem->ClearColor();
}
