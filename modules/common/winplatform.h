// Main header for Windows. Undefines all crappy Windows macros
#pragma once

#ifdef _WIN32

// Do not define min or max macros
#define NOMINMAX

// For mingw: explicitly define the windows version to get symbols like CreateSemaphoreEx, etc.
#ifdef __GNUC__

#define _WIN32_WINNT 0x601

#endif

#include <windows.h>
#include <synchapi.h>

// Macros we want to undefine
#undef min
#undef max
#undef CreateEvent
#undef GetCurrentTime
#undef LoadLibrary


#endif // _WIN32
