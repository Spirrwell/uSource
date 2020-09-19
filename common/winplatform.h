// Main header for Windows. Undefines all crappy Windows macros

#ifdef _WIN32

// Do not define min or max macros
#define NOMINMAX

// For mingw: explicitly define the windows version to get symbols like CreateSemaphoreEx, etc.
#ifdef __GNUC__

#define _WIN32_WINNT 0x601

#endif

#include <synchapi.h>
#include <windows.h>

// Macros we want to undefine
#undef min
#undef max
#undef CreateEvent
#undef GetCurrentTime
#undef LoadLibrary
#undef


#endif // _WIN32