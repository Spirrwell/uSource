# struct mobile_engfuncs_s

*Defined at line 39 of ./common/../engine/mobility_int.h*

## Members

public int version

public void (*)(float, char) pfnVibrate

public void (*)(int) pfnEnableTextInput

public void (*)(const char *, const char *, const char *, float, float, float, float, unsigned char *, int, float, int) pfnTouchAddClientButton

public void (*)(const char *, const char *, const char *, float, float, float, float, unsigned char *, int, float, int) pfnTouchAddDefaultButton

public void (*)(const char *, unsigned char) pfnTouchHideButtons

public void (*)(const char *) pfnTouchRemoveButton

public void (*)(unsigned char) pfnTouchSetClientOnly

public void (*)(void) pfnTouchResetDefaultButtons

public int (*)(int, int, int, int, int, int, float) pfnDrawScaledCharacter

public void (*)(const char *, ...) pfnSys_Warn

public void *(*)(const char *) pfnGetNativeObject

public void (*)(const char *) pfnSetCustomClientID



