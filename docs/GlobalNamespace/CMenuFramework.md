# class CMenuFramework

*Defined at line 26 of ./mainui/controls/Framework.h*

 WON-style menu framework



Inherits from CMenuBaseWindow



## Members

CMenuBannerBitmap banner

protected class CMenuPicButton *[16] m_apBtns

protected int m_iBtnsNum



## Functions

### CMenuFramework

*public void CMenuFramework(const char * name)*

*Defined at line 18 of ./mainui/controls/Framework.cpp*

### ~CMenuFramework

*public void ~CMenuFramework()*

*Defined at line 24 of ./mainui/controls/Framework.cpp*

### Show

*public void Show()*

*Defined at line 34 of ./mainui/controls/Framework.cpp*

### Draw

*public void Draw()*

*Defined at line 40 of ./mainui/controls/Framework.cpp*

### Init

*public void Init()*

*Defined at line 87 of ./mainui/controls/Framework.cpp*

### VidInit

*public void VidInit()*

*Defined at line 96 of ./mainui/controls/Framework.cpp*

### Hide

*public void Hide()*

*Defined at line 77 of ./mainui/controls/Framework.cpp*

### IsRoot

*public _Bool IsRoot()*

*Defined at line 39 of ./mainui/controls/Framework.h*

### AddButton

*public class CMenuPicButton * AddButton(const char * szName, const char * szStatus, enum EDefaultBtns iButton, CEventCallback onReleased, int iFlags)*

*Defined at line 105 of ./mainui/controls/Framework.cpp*

### AddButton

*public class CMenuPicButton * AddButton(const char * szName, const char * szStatus, const char * szButtonPath, CEventCallback onReleased, int iFlags)*

*Defined at line 127 of ./mainui/controls/Framework.cpp*

### DrawAnimation

*public _Bool DrawAnimation()*

*Defined at line 150 of ./mainui/controls/Framework.cpp*



