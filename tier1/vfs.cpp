#include "vfs.h"
#include "crtlib.h"

extern IEngineFilesystem* g_pFilesystem;

char* fs::ReadFileToBuffer(const char* file, bool gamedironly)
{
	size_t fileSize = g_pFilesystem->FileSize(file, "r");
	FileHandle_t handle = g_pFilesystem->OpenFile(file, "r", gamedironly);
	if(!handle) return nullptr;

	char* buf = (char*)Q_malloc(fileSize+1);

	g_pFilesystem->Read(handle, buf, fileSize);
	buf[fileSize] = 0;
	g_pFilesystem->CloseFile(handle);

	return buf;
}

void fs::DestroyReadBuffer(char *buf)
{
	if(!buf) return;
	Q_free(buf);
}


IEngineFilesystem* fs::GlobalFileSystem()
{
	return g_pFilesystem;
}