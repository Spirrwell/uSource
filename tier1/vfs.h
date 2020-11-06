#pragma once

#define BEGIN_FS_NAMESPACE namespace fs {
#define END_FS_NAMESPACE }

#include "common.h"
#include "engine_int.h"

#include "public/keyvalues.h"

#include "containers/string.h"

BEGIN_FS_NAMESPACE

IEngineFilesystem& GlobalFileSystem();

/* Reads the file into a string */
char* ReadFileToString(const char* file, size_t& sz, bool gamedironly = false);
void* ReadFileToBuffer(const char* file, size_t& sz, bool gamedironly = false);
void DestroyReadBuffer(char* buf);
KeyValues ReadKeyValues(const char* file, bool gamedironly = false);

END_FS_NAMESPACE
