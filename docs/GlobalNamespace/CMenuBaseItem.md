# class CMenuBaseItem

*Defined at line 22 of ./mainui/controls/BaseItem.h*

## Members

CEventCallback onGotFocus

CEventCallback onLostFocus

CEventCallback onReleased

CEventCallback onChanged

CEventCallback onPressed

CEventCallback onReleasedClActive

public unsigned int iFlags

Point pos

Size size

public int charSize

public const char * szName

public const char * szStatusText

public const char * szTag

CColor colorBase

CColor colorFocus

public unsigned int eTextAlignment

public enum EFocusAnimation eFocusAnimation

public enum ELetterCase eLetterCase

public HFont font

public _Bool bDrawStroke

public _Bool bTransparent

CColor colorStroke

public int iStrokeWidth

public int m_iLastFocusTime

protected class CMenuItemsHolder * m_pParent

protected _Bool m_bPressed

protected _Bool m_bAllocName

Point m_scPos

Size m_scSize

protected int m_scChSize



## Functions

### CMenuBaseItem

*public void CMenuBaseItem()*

*Defined at line 23 of ./mainui/controls/BaseItem.cpp*

 The main constructor

==================CMenuBaseItem::CMenuBaseItem==================

### ~CMenuBaseItem

*public void ~CMenuBaseItem()*

*Defined at line 48 of ./mainui/controls/BaseItem.cpp*

### Init

*public void Init()*

*Defined at line 56 of ./mainui/controls/BaseItem.cpp*

 Init is called when Item is added to Framework Called once by Framework

### VidInit

*public void VidInit()*

*Defined at line 61 of ./mainui/controls/BaseItem.cpp*

 VidInit is called after VidInit method of Framework VidInit can be called multiple times

### Reload

*public void Reload()*

*Defined at line 71 of ./mainui/controls/BaseItem.cpp*

 Reload is called after VidInit item method should be used for reloading internal data, like cvar values

### KeyUp

*public _Bool KeyUp(int key)*

*Defined at line 91 of ./mainui/controls/BaseItem.cpp*

 Key is called every key press returns true if handled or false if ignored

### KeyDown

*public _Bool KeyDown(int key)*

*Defined at line 96 of ./mainui/controls/BaseItem.cpp*

### Draw

*public void Draw()*

*Defined at line 76 of ./mainui/controls/BaseItem.cpp*

 Draw is called when screen must be updated

### Think

*public void Think()*

*Defined at line 81 of ./mainui/controls/BaseItem.cpp*

 Think is called every frame, before drawing

### Char

*public void Char(int key)*

*Defined at line 86 of ./mainui/controls/BaseItem.cpp*

 Char is a special key press event for text input

### MouseMove

*public _Bool MouseMove(int x, int y)*

*Defined at line 59 of ./mainui/controls/BaseItem.h*

 Called every mouse movement got from engine. Should return true, if

### ToggleInactive

*public void ToggleInactive()*

*Defined at line 62 of ./mainui/controls/BaseItem.h*

 Toggle inactivity of item

### SetInactive

*public void SetInactive(_Bool visible)*

*Defined at line 68 of ./mainui/controls/BaseItem.h*

 Direct inacivity set

### Show

*public void Show()*

*Defined at line 77 of ./mainui/controls/BaseItem.h*

 Cause item to be shown. Simple items will be drawn Window will be added to current window stack

### Hide

*public void Hide()*

*Defined at line 82 of ./mainui/controls/BaseItem.h*

 Cause item to be hidden Simple item will be hidden Window will be removed from current window stack

### IsVisible

*public _Bool IsVisible()*

*Defined at line 85 of ./mainui/controls/BaseItem.h*

 Determine, is this item is visible

### KeyValueData

*public _Bool KeyValueData(const char * key, const char * data)*

*Defined at line 226 of ./mainui/controls/BaseItem.cpp*

 Key value data reading, both parameters are zero-terminated string

### ToggleVisibility

*public void ToggleVisibility()*

*Defined at line 91 of ./mainui/controls/BaseItem.h*

 Toggle visibiltiy.

### SetVisibility

*public void SetVisibility(const _Bool show)*

*Defined at line 98 of ./mainui/controls/BaseItem.h*

 Direct visibility set

### SetGrayed

*public void SetGrayed(const _Bool grayed)*

*Defined at line 104 of ./mainui/controls/BaseItem.h*

### ToggleGrayed

*public void ToggleGrayed()*

*Defined at line 110 of ./mainui/controls/BaseItem.h*

### IsCurrentSelected

*public _Bool IsCurrentSelected()*

*Defined at line 148 of ./mainui/controls/BaseItem.cpp*

 Checks item is current selected in parent Framework

### CalcPosition

*public void CalcPosition()*

*Defined at line 155 of ./mainui/controls/BaseItem.cpp*

 Calculate render positions based on relative positions.

### CalcSizes

*public void CalcSizes()*

*Defined at line 189 of ./mainui/controls/BaseItem.cpp*

 Calculate scale size(item size, char size)

### PlayLocalSound

*public void PlayLocalSound(const char * name)*

*Defined at line 125 of ./mainui/controls/BaseItem.h*

 Play sound

### SetBaseColor

*public void SetBaseColor(int r, int g, int b, int a)*

*Defined at line 133 of ./mainui/controls/BaseItem.h*

### SetFocusColor

*public void SetFocusColor(int r, int g, int b, int a)*

*Defined at line 138 of ./mainui/controls/BaseItem.h*

### SetStrokeColor

*public void SetStrokeColor(int r, int g, int b, int a)*

*Defined at line 143 of ./mainui/controls/BaseItem.h*

### SetFont

*public void SetFont(const char * sfont)*

*Defined at line 148 of ./mainui/controls/BaseItem.h*

### SetFont

*public void SetFont(HFont font)*

*Defined at line 156 of ./mainui/controls/BaseItem.h*

### SetCoord

*public void SetCoord(int x, int y)*

*Defined at line 171 of ./mainui/controls/BaseItem.h*

### SetSize

*public void SetSize(int w, int h)*

*Defined at line 172 of ./mainui/controls/BaseItem.h*

### SetRect

*public void SetRect(int x, int y, int w, int h)*

*Defined at line 173 of ./mainui/controls/BaseItem.h*

### GetRenderPosition

*public Point GetRenderPosition()*

*Defined at line 174 of ./mainui/controls/BaseItem.h*

### GetRenderSize

*public Size GetRenderSize()*

*Defined at line 175 of ./mainui/controls/BaseItem.h*

### SetCharSize

*public void SetCharSize(enum EFontSizes fs)*

*Defined at line 101 of ./mainui/controls/BaseItem.cpp*

### SetNameAndStatus

*public void SetNameAndStatus(const char * name, const char * status, const char * tag)*

*Defined at line 179 of ./mainui/controls/BaseItem.h*

### Parent

*public class CMenuItemsHolder * Parent()*

*Defined at line 186 of ./mainui/controls/BaseItem.h*

### Parent

*public T * Parent()*

*Defined at line 187 of ./mainui/controls/BaseItem.h*

### IsPressed

*public _Bool IsPressed()*

*Defined at line 188 of ./mainui/controls/BaseItem.h*

### LastFocusTime

*public int LastFocusTime()*

*Defined at line 189 of ./mainui/controls/BaseItem.h*

### _Event

*public void _Event(int ev)*

*Defined at line 124 of ./mainui/controls/BaseItem.cpp*

 calls specific EventCallback

### IsAbsolutePositioned

*protected _Bool IsAbsolutePositioned()*

*Defined at line 223 of ./mainui/controls/BaseItem.h*

 Determine, is this item is absolute positioned If false, it will be positiond relative to it's parent



