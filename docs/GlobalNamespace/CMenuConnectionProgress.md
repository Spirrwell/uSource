# class CMenuConnectionProgress

*Defined at line 46 of ./mainui/menus/ConnectionProgress.cpp*

Inherits from CMenuBaseWindow



## Members

public enum EState m_iState

public enum ESource m_iSource

CMenuProgressBar commonProgress

CMenuProgressBar downloadProgress

CMenuPicButton consoleButton

CMenuPicButton disconnectButton

CMenuPicButton skipButton

CMenuYesNoMessageBox dialog

CMenuAction title

CMenuAction downloadText

CMenuAction commonText

private char [256] sTitleString

private char [512] sDownloadString

private char [512] sCommonString



## Functions

### CMenuConnectionProgress

*public void CMenuConnectionProgress()*

*Defined at line 139 of ./mainui/menus/ConnectionProgress.cpp*

### _Init

*public void _Init()*

*Defined at line 217 of ./mainui/menus/ConnectionProgress.cpp*

### _VidInit

*public void _VidInit()*

*Defined at line 271 of ./mainui/menus/ConnectionProgress.cpp*

### Draw

*public void Draw()*

*Defined at line 328 of ./mainui/menus/ConnectionProgress.cpp*

### DrawAnimation

*public _Bool DrawAnimation()*

*Defined at line 322 of ./mainui/menus/ConnectionProgress.cpp*

### KeyDown

*public _Bool KeyDown(int key)*

*Defined at line 147 of ./mainui/menus/ConnectionProgress.cpp*

### Disconnect

*public void Disconnect()*

*Defined at line 205 of ./mainui/menus/ConnectionProgress.cpp*

### HandleDisconnect

*public void HandleDisconnect()*

*Defined at line 168 of ./mainui/menus/ConnectionProgress.cpp*

### HandlePrecache

*public void HandlePrecache()*

*Defined at line 57 of ./mainui/menus/ConnectionProgress.cpp*

### HandleStufftext

*public void HandleStufftext(float flProgress, const char * pszText)*

*Defined at line 63 of ./mainui/menus/ConnectionProgress.cpp*

### HandleDownload

*public void HandleDownload(const char * pszFileName, const char * pszServerName, int iCurrent, int iTotal, const char * comment)*

*Defined at line 69 of ./mainui/menus/ConnectionProgress.cpp*

### HandleConnect

*public void HandleConnect(const char * pszText)*

*Defined at line 78 of ./mainui/menus/ConnectionProgress.cpp*

### SetCommonText

*public void SetCommonText(const char * pszText)*

*Defined at line 96 of ./mainui/menus/ConnectionProgress.cpp*

### SetServer

*public void SetServer(const char * pszName)*

*Defined at line 101 of ./mainui/menus/ConnectionProgress.cpp*



