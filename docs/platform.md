# namespace platform



## Records

time_t



## Functions

### GetCurrentTime

*time_t GetCurrentTime()*

*Defined at line 26 of ./public/platform.cpp*

### GetCurrentThreadId

*unsigned long long GetCurrentThreadId()*

*Defined at line 50 of ./public/platform.cpp*

### HookFatalError

*void HookFatalError(void (*)(const char *) fnHook)*

*Defined at line 62 of ./public/platform.cpp*

 Allows the engine to hook basic printing and error functions for log to console operations 

### FatalError

*void FatalError(const char * fmt)*

*Defined at line 67 of ./public/platform.cpp*

 Fatal error function 



