# class CMenuItemsHolder

*Defined at line 21 of ./mainui/controls/ItemsHolder.h*

Inherits from CMenuBaseItem



## Members

protected int m_iCursor

protected int m_iCursorPrev

CUtlVector m_pItems

CUtlVector m_events

protected _Bool m_bInit

protected _Bool m_bWrapCursor

protected const char * m_szResFile

private class CMenuBaseItem * m_pItemAtCursorOnDown



## Functions

### CMenuItemsHolder

*public void CMenuItemsHolder()*

*Defined at line 23 of ./mainui/controls/ItemsHolder.cpp*

### Init

*public void Init()*

*Defined at line 262 of ./mainui/controls/ItemsHolder.cpp*

 Overload _Init, _VidInit instead of these methods

### VidInit

*public void VidInit()*

*Defined at line 276 of ./mainui/controls/ItemsHolder.cpp*

### Reload

*public void Reload()*

*Defined at line 285 of ./mainui/controls/ItemsHolder.cpp*

### KeyUp

*public _Bool KeyUp(int key)*

*Defined at line 162 of ./mainui/controls/ItemsHolder.cpp*

### KeyDown

*public _Bool KeyDown(int key)*

*Defined at line 157 of ./mainui/controls/ItemsHolder.cpp*

### Char

*public void Char(int key)*

*Defined at line 167 of ./mainui/controls/ItemsHolder.cpp*

### ToggleInactive

*public void ToggleInactive()*

*Defined at line 297 of ./mainui/controls/ItemsHolder.cpp*

### SetInactive

*public void SetInactive(_Bool visible)*

*Defined at line 303 of ./mainui/controls/ItemsHolder.cpp*

### Draw

*public void Draw()*

*Defined at line 309 of ./mainui/controls/ItemsHolder.cpp*

### Think

*public void Think()*

*Defined at line 331 of ./mainui/controls/ItemsHolder.cpp*

### MouseMove

*public _Bool MouseMove(int x, int y)*

*Defined at line 200 of ./mainui/controls/ItemsHolder.cpp*

### KeyValueData

*public _Bool KeyValueData(const char * key, const char * data)*

*Defined at line 652 of ./mainui/controls/ItemsHolder.cpp*

### GetPositionOffset

*public Point GetPositionOffset()*

*Defined at line 657 of ./mainui/controls/ItemsHolder.cpp*

 returns a position where actual items holder is located

### IsWindow

*public _Bool IsWindow()*

*Defined at line 47 of ./mainui/controls/ItemsHolder.h*

### CursorMoved

*public void CursorMoved()*

*Defined at line 480 of ./mainui/controls/ItemsHolder.cpp*

### SetCursor

*public void SetCursor(int newCursor, _Bool notify)*

*Defined at line 465 of ./mainui/controls/ItemsHolder.cpp*

### SetCursorToItem

*public void SetCursorToItem(class CMenuBaseItem & item, _Bool notify)*

*Defined at line 441 of ./mainui/controls/ItemsHolder.cpp*

### AdjustCursor

*public _Bool AdjustCursor(int dir)*

*Defined at line 347 of ./mainui/controls/ItemsHolder.cpp*

=================UI_AdjustCursor

This functiont takes the given menu, the direction, and attempts toadjust the menu's cursor so that it's at the next available slot=================

### AddItem

*public void AddItem(class CMenuBaseItem & item)*

*Defined at line 508 of ./mainui/controls/ItemsHolder.cpp*

### RemoveItem

*public void RemoveItem(class CMenuBaseItem & item)*

*Defined at line 517 of ./mainui/controls/ItemsHolder.cpp*

### ItemAtCursor

*public class CMenuBaseItem * ItemAtCursor()*

*Defined at line 397 of ./mainui/controls/ItemsHolder.cpp*

### ItemAtCursorPrev

*public class CMenuBaseItem * ItemAtCursorPrev()*

*Defined at line 409 of ./mainui/controls/ItemsHolder.cpp*

### FindItemByTag

*public class CMenuBaseItem * FindItemByTag(const char * tag)*

*Defined at line 421 of ./mainui/controls/ItemsHolder.cpp*

### GetItemByIndex

*public class CMenuBaseItem * GetItemByIndex(int idx)*

*Defined at line 59 of ./mainui/controls/ItemsHolder.h*

### CalcItemsPositions

*public void CalcItemsPositions()*

*Defined at line 453 of ./mainui/controls/ItemsHolder.cpp*

### CalcItemsSizes

*public void CalcItemsSizes()*

*Defined at line 459 of ./mainui/controls/ItemsHolder.cpp*

### AddItem

*public void AddItem(class CMenuBaseItem * item)*

*Defined at line 69 of ./mainui/controls/ItemsHolder.h*

### GetCursor

*public int GetCursor()*

*Defined at line 70 of ./mainui/controls/ItemsHolder.h*

### GetCursorPrev

*public int GetCursorPrev()*

*Defined at line 71 of ./mainui/controls/ItemsHolder.h*

### ItemCount

*public int ItemCount()*

*Defined at line 72 of ./mainui/controls/ItemsHolder.h*

### WasInit

*public _Bool WasInit()*

*Defined at line 73 of ./mainui/controls/ItemsHolder.h*

### SetResourceFilename

*public void SetResourceFilename(const char * filename)*

*Defined at line 75 of ./mainui/controls/ItemsHolder.h*

### RegisterNamedEvent

*public void RegisterNamedEvent(CEventCallback ev, const char * name)*

*Defined at line 632 of ./mainui/controls/ItemsHolder.cpp*

### FindEventByName

*public CEventCallback FindEventByName(const char * name)*

*Defined at line 641 of ./mainui/controls/ItemsHolder.cpp*

### _Init

*protected void _Init()*

*Defined at line 81 of ./mainui/controls/ItemsHolder.h*

### _VidInit

*protected void _VidInit()*

*Defined at line 82 of ./mainui/controls/ItemsHolder.h*

### VidInitItems

*protected void VidInitItems()*

*Defined at line 291 of ./mainui/controls/ItemsHolder.cpp*

### LoadRES

*protected _Bool LoadRES(const char * filename)*

*Defined at line 556 of ./mainui/controls/ItemsHolder.cpp*

### Key

*private _Bool Key(const int key, const _Bool down)*

*Defined at line 31 of ./mainui/controls/ItemsHolder.cpp*



