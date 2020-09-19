#pragma once

#define BEGIN_FS_NAMESPACE namespace fs {
#define END_FS_NAMESPACE }

#include "common.h"
#include "engine_int.h"

#include "containers/string.h"

BEGIN_FS_NAMESPACE

IEngineFilesystem* GlobalFileSystem();

char* ReadFileToBuffer(const char* file, bool gamedironly = false);
void DestroyReadBuffer(char* buf);

END_FS_NAMESPACE