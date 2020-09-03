# struct UI_FUNCTIONS

*Defined at line 175 of ./engine/menu_int.h*

## Members

public int (*)(void) pfnVidInit

public void (*)(void) pfnInit

public void (*)(void) pfnShutdown

public void (*)(float) pfnRedraw

public void (*)(int, int) pfnKeyEvent

public void (*)(int, int) pfnMouseMove

public void (*)(int) pfnSetActiveMenu

public void (*)(struct netadr_s, const char *) pfnAddServerToList

public void (*)(int *, int *) pfnGetCursorPos

public void (*)(int, int) pfnSetCursorPos

public void (*)(int) pfnShowCursor

public void (*)(int) pfnCharEvent

public int (*)(void) pfnMouseInRect

public int (*)(void) pfnIsVisible

public int (*)(void) pfnCreditsActive

public void (*)(void) pfnFinalCredits



