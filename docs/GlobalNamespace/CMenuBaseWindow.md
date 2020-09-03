# class CMenuBaseWindow

*Defined at line 23 of ./mainui/controls/BaseWindow.h*

 Base class for windows. Should be used for message boxes, dialogs, root menus(e.g. frameworks)



Inherits from CMenuItemsHolder



## Members

public _Bool bAllowDrag

public enum CMenuBaseWindow::EAnimation eTransitionType

CMenuBackgroundBitmap background

protected int m_iTransitionStartTime

protected class CWindowStack * m_pStack

private _Bool m_bHolding

Point m_bHoldOffset



## Functions

### CMenuBaseWindow

*public void CMenuBaseWindow(const char * name, class CWindowStack * pStack)*

*Defined at line 22 of ./mainui/controls/BaseWindow.cpp*

### Hide

*public void Hide()*

*Defined at line 64 of ./mainui/controls/BaseWindow.cpp*

 Overloaded functions Window visibility is switched through window stack

### Show

*public void Show()*

*Defined at line 31 of ./mainui/controls/BaseWindow.cpp*

### IsVisible

*public _Bool IsVisible()*

*Defined at line 75 of ./mainui/controls/BaseWindow.cpp*

### KeyUp

*public _Bool KeyUp(int key)*

*Defined at line 108 of ./mainui/controls/BaseWindow.cpp*

### KeyDown

*public _Bool KeyDown(int key)*

*Defined at line 93 of ./mainui/controls/BaseWindow.cpp*

### Draw

*public void Draw()*

*Defined at line 116 of ./mainui/controls/BaseWindow.cpp*

### KeyValueData

*public _Bool KeyValueData(const char * key, const char * data)*

*Defined at line 160 of ./mainui/controls/BaseWindow.cpp*

### DrawAnimation

*public _Bool DrawAnimation()*

*Defined at line 132 of ./mainui/controls/BaseWindow.cpp*

 Override this method to draw custom animations For example, during transitions Return false when animation is still going Otherwise return true, so window will be marked as "no animation" and this method will not be called anymore(until next menu transition)

### IsRoot

*public _Bool IsRoot()*

*Defined at line 56 of ./mainui/controls/BaseWindow.h*

 Check current window is a root

### SaveAndPopMenu

*public void SaveAndPopMenu()*

*Defined at line 80 of ./mainui/controls/BaseWindow.cpp*

 Hide current window and save changes

### IsWindow

*public _Bool IsWindow()*

*Defined at line 61 of ./mainui/controls/BaseWindow.h*

### EnableTransition

*public void EnableTransition(enum CMenuBaseWindow::EAnimation type)*

*Defined at line 182 of ./mainui/controls/BaseWindow.cpp*

### DisableTransition

*public void DisableTransition()*

*Defined at line 64 of ./mainui/controls/BaseWindow.h*

### IsMaximized

*public _Bool IsMaximized()*

*Defined at line 66 of ./mainui/controls/BaseWindow.h*

### Link

*public void Link(class CMenuItemsHolder * h)*

*Defined at line 77 of ./mainui/controls/BaseWindow.h*

 set parent of window

### WindowStack

*public const class CWindowStack * WindowStack()*

*Defined at line 86 of ./mainui/controls/BaseWindow.h*

### CMenuBaseWindow

*private void CMenuBaseWindow()*

### IsAbsolutePositioned

*private _Bool IsAbsolutePositioned()*

*Defined at line 101 of ./mainui/controls/BaseWindow.h*

### DragDrop

*private void DragDrop(int down)*

*Defined at line 86 of ./mainui/controls/BaseWindow.cpp*



## Enums

| enum EAnimation |

--

| ANIM_NO |
| ANIM_OUT |
| ANIM_IN |


*Defined at line 41 of ./mainui/controls/BaseWindow.h*



