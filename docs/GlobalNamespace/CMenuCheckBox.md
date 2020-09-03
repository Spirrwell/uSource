# class CMenuCheckBox

*Defined at line 28 of ./mainui/controls/CheckBox.h*

Inherits from CMenuEditable



## Members

public _Bool bChecked

public _Bool bInvertMask

public _Bool bChangeOnPressed

public const char * szEmptyPic

public const char * szFocusPic

public const char * szPressPic

public const char * szCheckPic

public const char * szGrayedPic

public unsigned int iMask

CColor colorText

Point m_scTextPos

Size m_scTextSize



## Functions

### CMenuCheckBox

*public void CMenuCheckBox()*

*Defined at line 22 of ./mainui/controls/CheckBox.cpp*

### VidInit

*public void VidInit()*

*Defined at line 46 of ./mainui/controls/CheckBox.cpp*

=================CMenuCheckBox::Init=================

### KeyUp

*public _Bool KeyUp(int key)*

*Defined at line 57 of ./mainui/controls/CheckBox.cpp*

### KeyDown

*public _Bool KeyDown(int key)*

*Defined at line 93 of ./mainui/controls/CheckBox.cpp*

### Draw

*public void Draw()*

*Defined at line 135 of ./mainui/controls/CheckBox.cpp*

=================CMenuCheckBox::Draw=================

### UpdateEditable

*public void UpdateEditable()*

*Defined at line 201 of ./mainui/controls/CheckBox.cpp*

### LinkCvar

*public void LinkCvar(const char * name)*

*Defined at line 39 of ./mainui/controls/CheckBox.h*

### SetPicture

*public void SetPicture(const char * empty, const char * focus, const char * press, const char * check, const char * grayed)*

*Defined at line 44 of ./mainui/controls/CheckBox.h*

### BitMaskCb

*public void BitMaskCb(class CMenuBaseItem * pSelf, void * pExtra)*

*Defined at line 64 of ./mainui/controls/CheckBox.h*



