# class CMenuSpinControl

*Defined at line 23 of ./mainui/controls/SpinControl.h*

Inherits from CMenuEditable



## Members

private const char * m_szBackground

private const char * m_szLeftArrow

private const char * m_szRightArrow

private const char * m_szLeftArrowFocus

private const char * m_szRightArrowFocus

private float m_flMinValue

private float m_flMaxValue

private float m_flCurValue

private float m_flRange

private class CMenuBaseArrayModel * m_pModel

private short m_iFloatPrecision

private char [64] m_szDisplay



## Functions

### CMenuSpinControl

*public void CMenuSpinControl()*

*Defined at line 23 of ./mainui/controls/SpinControl.cpp*

### VidInit

*public void VidInit()*

*Defined at line 45 of ./mainui/controls/SpinControl.cpp*

=================CMenuSpinControl::Init=================

### KeyUp

*public _Bool KeyUp(int key)*

*Defined at line 92 of ./mainui/controls/SpinControl.cpp*

=================CMenuSpinControl::Key=================

### KeyDown

*public _Bool KeyDown(int key)*

*Defined at line 52 of ./mainui/controls/SpinControl.cpp*

### Draw

*public void Draw()*

*Defined at line 144 of ./mainui/controls/SpinControl.cpp*

=================CMenuSpinControl::Draw=================

### UpdateEditable

*public void UpdateEditable()*

*Defined at line 277 of ./mainui/controls/SpinControl.cpp*

### Setup

*public void Setup(class CMenuBaseArrayModel * model)*

*Defined at line 297 of ./mainui/controls/SpinControl.cpp*

### Setup

*public void Setup(float minValue, float maxValue, float range)*

*Defined at line 290 of ./mainui/controls/SpinControl.cpp*

### SetDisplayPrecision

*public void SetDisplayPrecision(short precision)*

*Defined at line 338 of ./mainui/controls/SpinControl.cpp*

### SetCurrentValue

*public void SetCurrentValue(const char * stringValue)*

*Defined at line 311 of ./mainui/controls/SpinControl.cpp*

### SetCurrentValue

*public void SetCurrentValue(float curValue)*

*Defined at line 305 of ./mainui/controls/SpinControl.cpp*

### GetCurrentValue

*public float GetCurrentValue()*

*Defined at line 44 of ./mainui/controls/SpinControl.h*

### GetCurrentString

*public const char * GetCurrentString()*

*Defined at line 45 of ./mainui/controls/SpinControl.h*

### ForceDisplayString

*public void ForceDisplayString(const char * display)*

*Defined at line 366 of ./mainui/controls/SpinControl.cpp*

### MoveLeft

*private const char * MoveLeft()*

*Defined at line 245 of ./mainui/controls/SpinControl.cpp*

### MoveRight

*private const char * MoveRight()*

*Defined at line 261 of ./mainui/controls/SpinControl.cpp*

### Display

*private void Display()*

*Defined at line 343 of ./mainui/controls/SpinControl.cpp*



