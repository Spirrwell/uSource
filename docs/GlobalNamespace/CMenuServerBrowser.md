# class CMenuServerBrowser

*Defined at line 168 of ./mainui/menus/ServerBrowser.cpp*

Inherits from CMenuFramework



## Members

public class CMenuPicButton * joinGame

public class CMenuPicButton * createGame

public class CMenuPicButton * refresh

CMenuSwitch natOrDirect

CMenuYesNoMessageBox msgBox

CMenuTable gameList

CMenuGameListModel gameListModel

CMenuYesNoMessageBox askPassword

CMenuField password

public int refreshTime

public int refreshTime2

public _Bool m_bLanOnly



## Functions

### CMenuServerBrowser

*public void CMenuServerBrowser()*

*Defined at line 171 of ./mainui/menus/ServerBrowser.cpp*

### Draw

*public void Draw()*

*Defined at line 402 of ./mainui/menus/ServerBrowser.cpp*

=================UI_Background_Ownerdraw=================

### Show

*public void Show()*

*Defined at line 548 of ./mainui/menus/ServerBrowser.cpp*

### SetLANOnly

*public void SetLANOnly(_Bool lanOnly)*

*Defined at line 175 of ./mainui/menus/ServerBrowser.cpp*

### GetGamesList

*public void GetGamesList()*

### ClearList

*public void ClearList()*

*Defined at line 370 of ./mainui/menus/ServerBrowser.cpp*

### RefreshList

*public void RefreshList()*

*Defined at line 376 of ./mainui/menus/ServerBrowser.cpp*

### JoinGame

*public void JoinGame()*

*Defined at line 365 of ./mainui/menus/ServerBrowser.cpp*

=================CMenuServerBrowser::JoinGame=================

### ResetPing

*public void ResetPing()*

*Defined at line 183 of ./mainui/menus/ServerBrowser.cpp*

### AddServerToList

*public void AddServerToList(netadr_s adr, const char * info)*

*Defined at line 559 of ./mainui/menus/ServerBrowser.cpp*

### Connect

*public void Connect(struct server_t & server)*

*Defined at line 325 of ./mainui/menus/ServerBrowser.cpp*

### _Init

*private void _Init()*

*Defined at line 423 of ./mainui/menus/ServerBrowser.cpp*

=================CMenuServerBrowser::Init=================

### _VidInit

*private void _VidInit()*

*Defined at line 526 of ./mainui/menus/ServerBrowser.cpp*

=================CMenuServerBrowser::VidInit=================



