# class Frame

*Defined at line 28 of ./mainui/controls/Frame.h*

Inherits from CMenuBaseWindow



## Members

private enum EDockMode m_dockMode

private _Bool m_roundedCorners

CColor m_backgroundColor

CColor m_outlineColor

CColor m_titleColor

String m_titleText

private HFont m_titleFont

private int m_margin

private _Bool resizing

private _Bool m_resizable

private _Bool m_draggable

private _Bool m_dragging

Point m_startPoint

Point m_exitBtnPos

Point m_resizeBtnPos

private int m_cornerRadius

Size m_minSize

Size m_usableArea



## Functions

### Frame

*public void Frame(const char * name)*

*Defined at line 13 of ./mainui/controls/Frame.cpp*

### SetBackgroundColor

*public void SetBackgroundColor(int r, int g, int b, int a)*

*Defined at line 56 of ./mainui/controls/Frame.h*

### SetTitleColor

*public void SetTitleColor(int r, int g, int b, int a)*

*Defined at line 57 of ./mainui/controls/Frame.h*

### SetOutlineColor

*public void SetOutlineColor(int r, int g, int b, int a)*

*Defined at line 58 of ./mainui/controls/Frame.h*

### ShouldDrawRoundedCorners

*public void ShouldDrawRoundedCorners(_Bool yesorno)*

*Defined at line 59 of ./mainui/controls/Frame.h*

### SetDockMode

*public void SetDockMode(enum EDockMode mode)*

*Defined at line 60 of ./mainui/controls/Frame.h*

### SetResizable

*public void SetResizable(_Bool r)*

*Defined at line 62 of ./mainui/controls/Frame.h*

### SetDraggable

*public void SetDraggable(_Bool d)*

*Defined at line 63 of ./mainui/controls/Frame.h*

### SetCornerRadius

*public void SetCornerRadius(int r)*

*Defined at line 64 of ./mainui/controls/Frame.h*

### SetMinimumSize

*public void SetMinimumSize(Size s)*

*Defined at line 65 of ./mainui/controls/Frame.h*

### SetTitle

*public void SetTitle(const char * title)*

*Defined at line 67 of ./mainui/controls/Frame.h*

### Draw

*public void Draw()*

*Defined at line 29 of ./mainui/controls/Frame.cpp*

### Init

*public void Init()*

*Defined at line 82 of ./mainui/controls/Frame.cpp*

### KeyUp

*public _Bool KeyUp(int key)*

*Defined at line 141 of ./mainui/controls/Frame.cpp*

### KeyDown

*public _Bool KeyDown(int key)*

*Defined at line 115 of ./mainui/controls/Frame.cpp*

### Think

*public void Think()*

*Defined at line 97 of ./mainui/controls/Frame.cpp*

### UpdateLayout

*public void UpdateLayout()*

*Defined at line 77 of ./mainui/controls/Frame.cpp*

 Recomputes all sizes and positions after a resize operation 



