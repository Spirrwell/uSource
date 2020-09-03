# class CMenuYesNoMessageBox

*Defined at line 24 of ./mainui/controls/YesNoMessageBox.h*

Inherits from CMenuBaseWindow



## Members

CEventCallback onPositive

CEventCallback onNegative

public _Bool bAutoHide

CMenuAction dlgMessage1

CMenuPicButton yes

CMenuPicButton no

private _Bool m_bSetYes

private _Bool m_bSetNo

private _Bool m_bIsAlert



## Functions

### CMenuYesNoMessageBox

*public void CMenuYesNoMessageBox(_Bool alert)*

*Defined at line 25 of ./mainui/controls/YesNoMessageBox.cpp*

### _Init

*public void _Init()*

*Defined at line 74 of ./mainui/controls/YesNoMessageBox.cpp*

==============CMenuYesNoMessageBox::Init==============

### _VidInit

*public void _VidInit()*

*Defined at line 104 of ./mainui/controls/YesNoMessageBox.cpp*

==============CMenuYesNoMessageBox::VidInit==============

### Draw

*public void Draw()*

*Defined at line 122 of ./mainui/controls/YesNoMessageBox.cpp*

==============CMenuYesNoMessageBox::Draw==============

### KeyDown

*public _Bool KeyDown(int key)*

*Defined at line 133 of ./mainui/controls/YesNoMessageBox.cpp*

==============CMenuYesNoMessageBox::Key==============

### SetMessage

*public void SetMessage(const char * msg)*

*Defined at line 151 of ./mainui/controls/YesNoMessageBox.cpp*

==============CMenuYesNoMessageBox::SetMessage==============

### SetPositiveButton

*public void SetPositiveButton(const char * msg, enum EDefaultBtns buttonPic, int extrawidth)*

*Defined at line 161 of ./mainui/controls/YesNoMessageBox.cpp*

==============CMenuYesNoMessageBox::SetPositiveButton==============

### SetNegativeButton

*public void SetNegativeButton(const char * msg, enum EDefaultBtns buttonPic, int extrawidth)*

*Defined at line 174 of ./mainui/controls/YesNoMessageBox.cpp*

==============CMenuYesNoMessageBox::SetNegativeButton==============

### HighlightChoice

*public void HighlightChoice(enum CMenuYesNoMessageBox::EHighlight ch)*

*Defined at line 187 of ./mainui/controls/YesNoMessageBox.cpp*

==============CMenuYesNoMessageBox::HighlightChoice==============

### MakeOpenEvent

*public CEventCallback MakeOpenEvent()*

*Defined at line 200 of ./mainui/controls/YesNoMessageBox.cpp*

 Pass pointer to messagebox to extra of calling object

### OpenCb

*private void OpenCb(class CMenuBaseItem * , void * pExtra)*

*Defined at line 211 of ./mainui/controls/YesNoMessageBox.cpp*

==============CMenuYesNoMessageBox::ToggleInactiveCb==============



## Enums

| enum EHighlight |

--

| NO_HIGHLIGHT |
| HIGHLIGHT_YES |
| HIGHLIGHT_NO |


*Defined at line 37 of ./mainui/controls/YesNoMessageBox.h*



