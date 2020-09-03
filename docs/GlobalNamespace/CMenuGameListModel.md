# class CMenuGameListModel

*Defined at line 99 of ./mainui/menus/ServerBrowser.cpp*

Inherits from CMenuBaseModel



## Members

public float serversRefreshTime

CUtlVector servers

private int m_iSortingColumn

private _Bool m_bAscend



## Functions

### CMenuGameListModel

*public void CMenuGameListModel()*

*Defined at line 102 of ./mainui/menus/ServerBrowser.cpp*

### Update

*public void Update()*

*Defined at line 254 of ./mainui/menus/ServerBrowser.cpp*

=================CMenuServerBrowser::GetGamesList=================

### GetColumns

*public int GetColumns()*

*Defined at line 105 of ./mainui/menus/ServerBrowser.cpp*

### GetRows

*public int GetRows()*

*Defined at line 109 of ./mainui/menus/ServerBrowser.cpp*

### GetCellType

*public enum ECellType GetCellType(int line, int column)*

*Defined at line 113 of ./mainui/menus/ServerBrowser.cpp*

### GetCellText

*public const char * GetCellText(int line, int column)*

*Defined at line 119 of ./mainui/menus/ServerBrowser.cpp*

### GetCellColors

*public _Bool GetCellColors(int line, int column, unsigned int & textColor, _Bool & force)*

*Defined at line 131 of ./mainui/menus/ServerBrowser.cpp*

### OnActivateEntry

*public void OnActivateEntry(int line)*

*Defined at line 283 of ./mainui/menus/ServerBrowser.cpp*

### Flush

*public void Flush()*

*Defined at line 146 of ./mainui/menus/ServerBrowser.cpp*

### IsHavePassword

*public _Bool IsHavePassword(int line)*

*Defined at line 152 of ./mainui/menus/ServerBrowser.cpp*

### AddServerToList

*public void AddServerToList(netadr_s adr, const char * info)*

*Defined at line 288 of ./mainui/menus/ServerBrowser.cpp*

### Sort

*public _Bool Sort(int column, _Bool ascend)*

*Defined at line 218 of ./mainui/menus/ServerBrowser.cpp*



