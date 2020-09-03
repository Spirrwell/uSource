# class CMenuPlayerModelView

*Defined at line 29 of ./mainui/controls/PlayerModelView.h*

Inherits from CMenuBaseItem



## Members

public HIMAGE hPlayerImage

ref_viewpass_s refdef

public cl_entity_t * ent

public _Bool bDrawAsPlayer

public enum (anonymous enum at ../mainui/controls/PlayerModelView.h:46:2) eOverrideMode

CColor backgroundColor

CColor outlineFocusColor

cl_entity_s ent2

private _Bool mouseYawControl

private int prevCursorX

private int prevCursorY



## Functions

### CMenuPlayerModelView

*public void CMenuPlayerModelView()*

*Defined at line 20 of ./mainui/controls/PlayerModelView.cpp*

### VidInit

*public void VidInit()*

*Defined at line 36 of ./mainui/controls/PlayerModelView.cpp*

### Draw

*public void Draw()*

*Defined at line 144 of ./mainui/controls/PlayerModelView.cpp*

### KeyDown

*public _Bool KeyDown(int key)*

*Defined at line 95 of ./mainui/controls/PlayerModelView.cpp*

### KeyUp

*public _Bool KeyUp(int key)*

*Defined at line 82 of ./mainui/controls/PlayerModelView.cpp*

### CalcFov

*public void CalcFov()*

*Defined at line 233 of ./mainui/controls/PlayerModelView.cpp*

=================UI_PlayerSetup_CalcFov

assume refdef is valid=================



## Enums

| enum  |

--

| PMV_DONTCARE |
| PMV_SHOWMODEL |
| PMV_SHOWIMAGE |


*Defined at line 46 of ./mainui/controls/PlayerModelView.h*



