# class CInput

*Defined at line 24 of ./game/client/input_mouse.h*

Inherits from AbstractInput



## Members

protected float ac_forwardmove

protected float ac_sidemove

protected int ac_movecount

protected float rel_yaw

protected float rel_pitch



## Functions

### IN_ClientMoveEvent

*public void IN_ClientMoveEvent(float forwardmove, float sidemove)*

*Defined at line 127 of ./game/client/input_xash3d.cpp*

### IN_ClientLookEvent

*public void IN_ClientLookEvent(float relyaw, float relpitch)*

*Defined at line 136 of ./game/client/input_xash3d.cpp*

### IN_Move

*public void IN_Move(float frametime, usercmd_t * cmd)*

*Defined at line 143 of ./game/client/input_xash3d.cpp*

 Rotate camera and add move values to usercmd

### IN_MouseEvent

*public void IN_MouseEvent(int mstate)*

*Defined at line 227 of ./game/client/input_xash3d.cpp*

### IN_ClearStates

*public void IN_ClearStates()*

*Defined at line 249 of ./game/client/input_xash3d.cpp*

 Stubs

### IN_ActivateMouse

*public void IN_ActivateMouse()*

*Defined at line 254 of ./game/client/input_xash3d.cpp*

### IN_DeactivateMouse

*public void IN_DeactivateMouse()*

*Defined at line 259 of ./game/client/input_xash3d.cpp*

### IN_Accumulate

*public void IN_Accumulate()*

*Defined at line 264 of ./game/client/input_xash3d.cpp*

### IN_Commands

*public void IN_Commands()*

*Defined at line 269 of ./game/client/input_xash3d.cpp*

### IN_Shutdown

*public void IN_Shutdown()*

*Defined at line 274 of ./game/client/input_xash3d.cpp*

### IN_Init

*public void IN_Init()*

*Defined at line 279 of ./game/client/input_xash3d.cpp*

 Register cvars and reset data



