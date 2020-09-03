# class CCommandLine

*Defined at line 8 of ./public/cmdline.h*

## Members

private char ** m_argv

private int m_argc



## Functions

### CCommandLine

*private void CCommandLine()*

*Defined at line 5 of ./public/cmdline.cpp*

### ~CCommandLine

*private void ~CCommandLine()*

*Defined at line 12 of ./public/cmdline.cpp*

### Set

*public void Set(int argc, char ** argv)*

*Defined at line 17 of ./public/cmdline.cpp*

### Find

*public _Bool Find(const char * arg)*

*Defined at line 23 of ./public/cmdline.cpp*

### FindString

*public const char * FindString(const char * arg)*

*Defined at line 33 of ./public/cmdline.cpp*

### FindInt

*public int FindInt(const char * arg, int _default)*

*Defined at line 46 of ./public/cmdline.cpp*

### FindFloat

*public float FindFloat(const char * arg, float _default)*

*Defined at line 65 of ./public/cmdline.cpp*

### ArgCount

*public int ArgCount()*

*Defined at line 24 of ./public/cmdline.h*

### argc

*public int argc()*

*Defined at line 25 of ./public/cmdline.h*

### argv

*public const char *const * argv()*

*Defined at line 26 of ./public/cmdline.h*

### Args

*public const char *const * Args()*

*Defined at line 27 of ./public/cmdline.h*



