#include "vfs.h"
#include "crtlib.h"

extern IEngineFilesystem* g_pFilesystem;

char* fs::ReadFileToString(const char* file, size_t& sz, bool gamedironly)
{
	if(!file) return nullptr;

	size_t fileSize = g_pFilesystem->FileSize(file, "r");
	FileHandle_t handle = g_pFilesystem->OpenFile(file, "r", gamedironly);
	if(!handle) return nullptr;

	char* buf = (char*)Q_malloc(fileSize+1);

	sz = g_pFilesystem->Read(handle, buf, fileSize);
	buf[fileSize] = 0;
	g_pFilesystem->CloseFile(handle);

	return buf;
}

void* fs::ReadFileToBuffer(const char* file, size_t& sz, bool gamedironly)
{
	if(!file) return nullptr;

	size_t fileSize = g_pFilesystem->FileSize(file, "r");
	FileHandle_t handle = g_pFilesystem->OpenFile(file, "r", gamedironly);
	if(!handle) return nullptr;

	void* buf = (char*)Q_malloc(fileSize);

	sz = g_pFilesystem->Read(handle, buf, fileSize);
	g_pFilesystem->CloseFile(handle);

	return buf;
}

void fs::DestroyReadBuffer(char *buf)
{
	if(!buf) return;
	Q_free(buf);
}

KeyValues fs::ReadKeyValues(const char* file, bool gamedironly)
{
	/* Create an empty keyvalues object */
	KeyValues kv;

	if(!file) return kv;

	/* Read buffer */
	size_t sz = 0;
	char* buf = fs::ReadFileToString(file, sz, gamedironly);

	if(!buf) return kv;

	kv.ParseString(buf, false, sz);

	fs::DestroyReadBuffer(buf);

	return kv;
}


IEngineFilesystem* fs::GlobalFileSystem()
{
	return g_pFilesystem;
}
