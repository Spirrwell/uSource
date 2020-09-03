# class CMenuSwitch

*Defined at line 25 of ./mainui/controls/Switch.h*

Inherits from CMenuEditable



## Members

public _Bool bMouseToggle

public _Bool bKeepToggleWidth

public _Bool bChangeOnPressed

CColor iSelectColor

CColor iBackgroundColor

CColor iFgTextColor

CColor iBgTextColor

public float fTextOffsetX

public float fTextOffsetY

private int m_iSwitches

private int m_iState

private const char *[64] m_szNames

private struct Point [64] m_Points

private struct Size [64] m_Sizes

Point m_scTextPos

Size m_scTextSize



## Functions

### CMenuSwitch

*public void CMenuSwitch()*

*Defined at line 24 of ./mainui/controls/Switch.cpp*

### KeyDown

*public _Bool KeyDown(int key)*

*Defined at line 161 of ./mainui/controls/Switch.cpp*

### KeyUp

*public _Bool KeyUp(int key)*

*Defined at line 120 of ./mainui/controls/Switch.cpp*

### VidInit

*public void VidInit()*

*Defined at line 78 of ./mainui/controls/Switch.cpp*

### Draw

*public void Draw()*

*Defined at line 200 of ./mainui/controls/Switch.cpp*

### UpdateEditable

*public void UpdateEditable()*

*Defined at line 264 of ./mainui/controls/Switch.cpp*

### LinkCvar

*public void LinkCvar(const char * name)*

*Defined at line 37 of ./mainui/controls/Switch.h*

### AddSwitch

*public void AddSwitch(const char * text)*

*Defined at line 48 of ./mainui/controls/Switch.cpp*

### GetState

*public int GetState()*

*Defined at line 43 of ./mainui/controls/Switch.h*

### IsNewStateByMouseClick

*private int IsNewStateByMouseClick()*

*Defined at line 53 of ./mainui/controls/Switch.cpp*



