# class HistoryResource

*Defined at line 108 of ./game/client/ammohistory.h*

## Members

private struct HistoryResource::HIST_ITEM [12] rgAmmoHistory

public int iHistoryGap

public int iCurrentHistorySlot



## Records

HIST_ITEM



## Functions

### Init

*public void Init()*

*Defined at line 122 of ./game/client/ammohistory.h*

### Reset

*public void Reset()*

*Defined at line 127 of ./game/client/ammohistory.h*

### AddToHistory

*public void AddToHistory(int iType, int iId, int iCount)*

*Defined at line 46 of ./game/client/ammohistory.cpp*

### AddToHistory

*public void AddToHistory(int iType, const char * szName, int iCount)*

*Defined at line 67 of ./game/client/ammohistory.cpp*

### CheckClearHistory

*public void CheckClearHistory()*

*Defined at line 94 of ./game/client/ammohistory.cpp*

### DrawAmmoHistory

*public int DrawAmmoHistory(float flTime)*

*Defined at line 108 of ./game/client/ammohistory.cpp*

 Draw Ammo pickup history



