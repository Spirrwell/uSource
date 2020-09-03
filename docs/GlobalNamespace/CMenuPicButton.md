# class CMenuPicButton

*Defined at line 31 of ./mainui/controls/PicButton.h*

Inherits from CMenuBaseItem



## Members

public _Bool bEnableTransitions

public _Bool bPulse

private _Bool bRollOver

private HIMAGE hPic

private int button_id

private int iFocusStartTime

private int iOldState

private struct CMenuPicButton::Quad [2] TitleLerpQuads

private HIMAGE TransPic

private rgba_t color



## Records

Quad



## Functions

### CMenuPicButton

*public void CMenuPicButton()*

*Defined at line 31 of ./mainui/controls/PicButton.cpp*

### KeyUp

*public _Bool KeyUp(int key)*

*Defined at line 69 of ./mainui/controls/PicButton.cpp*

=================CMenuPicButton::Key=================

### KeyDown

*public _Bool KeyDown(int key)*

*Defined at line 91 of ./mainui/controls/PicButton.cpp*

### Draw

*public void Draw()*

*Defined at line 132 of ./mainui/controls/PicButton.cpp*

=================CMenuPicButton::Draw=================

### SetPicture

*public void SetPicture(enum EDefaultBtns ID)*

*Defined at line 292 of ./mainui/controls/PicButton.cpp*

### SetPicture

*public void SetPicture(const char * filename)*

*Defined at line 304 of ./mainui/controls/PicButton.cpp*

### DrawTitleAnim

*public _Bool DrawTitleAnim(class CMenuBaseWindow::EAnimation anim)*

*Defined at line 478 of ./mainui/controls/PicButton.cpp*

### ClearButtonStack

*public void ClearButtonStack()*

*Defined at line 523 of ./mainui/controls/PicButton.cpp*

### GetTitleTransFraction

*public float GetTitleTransFraction()*

*Defined at line 356 of ./mainui/controls/PicButton.cpp*

### SetupTitleQuadForLast

*public void SetupTitleQuadForLast(int x, int y, int w, int h)*

*Defined at line 437 of ./mainui/controls/PicButton.cpp*

### SetTransPicForLast

*public void SetTransPicForLast(HIMAGE pic)*

*Defined at line 449 of ./mainui/controls/PicButton.cpp*

### SetupTitleQuad

*public void SetupTitleQuad(int x, int y, int w, int h)*

*Defined at line 461 of ./mainui/controls/PicButton.cpp*

 TODO: Find CMenuBannerBitmap in next menu page and correct

### SetTransPic

*public void SetTransPic(HIMAGE pic)*

*Defined at line 471 of ./mainui/controls/PicButton.cpp*

### RootChanged

*public void RootChanged(_Bool isForward)*

*Defined at line 411 of ./mainui/controls/PicButton.cpp*

### SetTitleAnim

*private void SetTitleAnim(int state)*

*Defined at line 366 of ./mainui/controls/PicButton.cpp*

### TACheckMenuDepth

*private void TACheckMenuDepth()*

### PushPButtonStack

*private void PushPButtonStack()*

*Defined at line 341 of ./mainui/controls/PicButton.cpp*

 Opened new menu, awaiting Quad from Banner

### PopPButtonStack

*private void PopPButtonStack()*

*Defined at line 315 of ./mainui/controls/PicButton.cpp*

 Pressed cancel, done or ESC in menu

### GetLastButtonText

*private const char * GetLastButtonText()*

*Defined at line 328 of ./mainui/controls/PicButton.cpp*

### DrawButton

*private void DrawButton(int r, int g, int b, int a, wrect_t * rects, int state)*

*Defined at line 114 of ./mainui/controls/PicButton.cpp*

=================CMenuPicButton::DrawButton=================

### LerpQuad

*private Quad LerpQuad(Quad a, Quad b, float frac)*

*Defined at line 425 of ./mainui/controls/PicButton.cpp*



## Enums

| enum animState_e |

--

| AS_TO_TITLE |
| AS_TO_BUTTON |


*Defined at line 61 of ./mainui/controls/PicButton.h*



