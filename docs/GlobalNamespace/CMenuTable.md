# class CMenuTable

*Defined at line 45 of ./mainui/controls/Table.h*

 CMenuTable

 In order to keep simplicity, there is some limitations. If you will keep them in mind, you will find tables simple, easy and fast to add on your window

 1. CMenuTable uses a very simple MVC pattern, but there controller is merged with model(OnDelete, OnActivate) It means, that you have to inherit from CMenuBaseModel, implement all pure methods and only then you can put your data on table.

 2. CMenuTable will call Update() only when you will pass a model pointer to table.

 3. Adding table on items holder before you have passed a model pointer is PROHIBITED and will lead to crash.

 4. You can't use columns more than MAX_TABLE_COLUMNS

 5. Header text is set per Table instance.

 6. Column widths are constant(at this moment). You should not exceed 1.0 in total columns width





Inherits from CMenuBaseItem



## Members

public _Bool bFramedHintText

public _Bool bAllowSorting

public _Bool bShowScrollBar

CColor iStrokeFocusedColor

CColor iBackgroundColor

CColor iHeaderColor

private const char *[16] szHeaderTexts

private struct (anonymous struct at ../mainui/controls/Table.h:144:2) [16] columns

private float flFixedSumm

private float flDynamicSumm

private const char * szBackground

private const char * szUpArrow

private const char * szUpArrowFocus

private const char * szUpArrowPressed

private const char * szDownArrow

private const char * szDownArrowFocus

private const char * szDownArrowPressed

private int iTopItem

private int iNumRows

Point sbarPos

Size sbarSize

private _Bool iScrollBarSliding

private int iHighlight

private int iCurItem

private int m_iLastItemMouseChange

private int m_iSortingColumn

private _Bool m_bAscend

Size headerSize

Point upArrow

Point downArrow

Size arrow

Point boxPos

Size boxSize

private class CMenuBaseModel * m_pModel



## Records





## Functions

### CMenuTable

*public void CMenuTable()*

*Defined at line 25 of ./mainui/controls/Table.cpp*

### KeyUp

*public _Bool KeyUp(int key)*

*Defined at line 176 of ./mainui/controls/Table.cpp*

### KeyDown

*public _Bool KeyDown(int key)*

*Defined at line 291 of ./mainui/controls/Table.cpp*

### Draw

*public void Draw()*

*Defined at line 569 of ./mainui/controls/Table.cpp*

### VidInit

*public void VidInit()*

*Defined at line 45 of ./mainui/controls/Table.cpp*

### MoveView

*public _Bool MoveView(int delta)*

*Defined at line 117 of ./mainui/controls/Table.cpp*

### MoveCursor

*public _Bool MoveCursor(int delta)*

*Defined at line 138 of ./mainui/controls/Table.cpp*

### GetCurrentIndex

*public int GetCurrentIndex()*

*Defined at line 59 of ./mainui/controls/Table.h*

### SetCurrentIndex

*public void SetCurrentIndex(int idx)*

*Defined at line 155 of ./mainui/controls/Table.cpp*

### GetSortingColumn

*public int GetSortingColumn()*

*Defined at line 61 of ./mainui/controls/Table.h*

### IsAscend

*public _Bool IsAscend()*

*Defined at line 62 of ./mainui/controls/Table.h*

### SetSortingColumn

*public void SetSortingColumn(int column, _Bool ascend)*

*Defined at line 63 of ./mainui/controls/Table.h*

### SetSortingColumn

*public void SetSortingColumn(int column)*

*Defined at line 70 of ./mainui/controls/Table.h*

### SwapOrder

*public void SwapOrder()*

*Defined at line 74 of ./mainui/controls/Table.h*

### DisableSorting

*public void DisableSorting()*

*Defined at line 79 of ./mainui/controls/Table.h*

### SetUpArrowPicture

*public void SetUpArrowPicture(const char * upArrow, const char * upArrowFocus, const char * upArrowPressed)*

*Defined at line 84 of ./mainui/controls/Table.h*

### SetDownArrowPicture

*public void SetDownArrowPicture(const char * downArrow, const char * downArrowFocus, const char * downArrowPressed)*

*Defined at line 91 of ./mainui/controls/Table.h*

### SetModel

*public void SetModel(class CMenuBaseModel * model)*

*Defined at line 98 of ./mainui/controls/Table.h*

### SetHeaderText

*public void SetHeaderText(int num, const char * text)*

*Defined at line 104 of ./mainui/controls/Table.h*

### SetColumnWidth

*public void SetColumnWidth(int num, float width, _Bool fixed)*

*Defined at line 114 of ./mainui/controls/Table.h*

 widths are in [0.0; 1.0] Total of all widths should be 1.0f, but not necessary. to keep everything simple, if first few columns exceeds 1.0, the other will not be shown if you have set fixed == true, then column size is set in logical units

### SetupColumn

*public void SetupColumn(int num, const char * text, float width, _Bool fixed)*

*Defined at line 124 of ./mainui/controls/Table.h*

 shortcut for SetHeaderText && SetColumnWidth

### DrawLine

*private void DrawLine(Point p, const char ** psz, size_t size, uint textColor, _Bool forceCol, uint fillColor)*

*Defined at line 399 of ./mainui/controls/Table.cpp*

### DrawLine

*private void DrawLine(Point p, int line, uint textColor, _Bool forceCol, uint fillColor)*

*Defined at line 457 of ./mainui/controls/Table.cpp*



