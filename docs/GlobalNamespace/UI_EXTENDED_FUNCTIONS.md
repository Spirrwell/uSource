# struct UI_EXTENDED_FUNCTIONS

*Defined at line 212 of ./engine/menu_int.h*

## Members

public ADDTOUCHBUTTONTOLIST pfnAddTouchButtonToList

public void (*)(void) pfnResetPing

public void (*)(void) pfnShowConnectionWarning

public void (*)(int) pfnShowUpdateDialog

public void (*)(const char *) pfnShowMessageBox

public void (*)(void) pfnConnectionProgress_Disconnect

public void (*)(const char *, const char *, int, int, const char *) pfnConnectionProgress_Download

public void (*)(void) pfnConnectionProgress_DownloadEnd

public void (*)(void) pfnConnectionProgress_Precache

public void (*)(const char *) pfnConnectionProgress_Connect

public void (*)(void) pfnConnectionProgress_ChangeLevel

public void (*)(const char *) pfnConnectionProgress_ParseServerInfo



