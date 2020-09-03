# class CMenuTouchButtons

*Defined at line 34 of ./mainui/menus/TouchButtons.cpp*

Inherits from CMenuFramework



## Members

public HIMAGE textureid

public char [256] selectedName

public int curflags

CMenuPicButton done

CMenuPicButton cancel

CMenuSlider red

CMenuSlider green

CMenuSlider blue

CMenuSlider alpha

CMenuCheckBox hide

CMenuCheckBox sp

CMenuCheckBox mp

CMenuCheckBox lock

CMenuCheckBox additive

CMenuCheckBox precision

CMenuPicButton reset

CMenuPicButton remove

CMenuPicButton save

CMenuPicButton select

CMenuPicButton editor

CMenuField command

CMenuField texture

CMenuField name

public CMenuColor color

public CMenuButtonPreview preview

public CButtonListModel model

CMenuTable buttonList

CMenuYesNoMessageBox msgBox



## Records

CMenuColor

CMenuButtonPreview

CButtonListModel



## Functions

### CMenuTouchButtons

*public void CMenuTouchButtons()*

*Defined at line 37 of ./mainui/menus/TouchButtons.cpp*

### _Init

*private void _Init()*

*Defined at line 373 of ./mainui/menus/TouchButtons.cpp*

=================UI_TouchButtons_Init=================

### _VidInit

*private void _VidInit()*

*Defined at line 497 of ./mainui/menus/TouchButtons.cpp*

### DeleteButton

*public void DeleteButton()*

*Defined at line 197 of ./mainui/menus/TouchButtons.cpp*

### ResetButtons

*public void ResetButtons()*

*Defined at line 207 of ./mainui/menus/TouchButtons.cpp*

### OpenFileDialog

*public void OpenFileDialog()*

*Defined at line 239 of ./mainui/menus/TouchButtons.cpp*

### UpdateTexture

*public void UpdateTexture()*

*Defined at line 257 of ./mainui/menus/TouchButtons.cpp*

### UpdateSP

*public void UpdateSP()*

*Defined at line 266 of ./mainui/menus/TouchButtons.cpp*

### UpdateMP

*public void UpdateMP()*

*Defined at line 280 of ./mainui/menus/TouchButtons.cpp*

### SaveButton

*public void SaveButton()*

*Defined at line 294 of ./mainui/menus/TouchButtons.cpp*

### RemoveMsgBox

*public void RemoveMsgBox()*

*Defined at line 337 of ./mainui/menus/TouchButtons.cpp*

### ResetMsgBox

*public void ResetMsgBox()*

*Defined at line 344 of ./mainui/menus/TouchButtons.cpp*

### UpdateFields

*public void UpdateFields()*

*Defined at line 214 of ./mainui/menus/TouchButtons.cpp*

### ExitMenuCb

*public void ExitMenuCb(class CMenuBaseItem * pSelf, void * pExtra)*

*Defined at line 360 of ./mainui/menus/TouchButtons.cpp*

### FileDialogCallback

*public void FileDialogCallback(_Bool success)*

*Defined at line 351 of ./mainui/menus/TouchButtons.cpp*

 Use an event system here! Don't make this static method cry.



