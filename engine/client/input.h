/*
input.h - win32 input devices
Copyright (C) 2007 Uncle Mike

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

#ifndef INPUT_H
#define INPUT_H

/*
==============================================================

INPUT

==============================================================
*/

#include "keydefs.h"

//
// input.c
//
extern qboolean	in_mouseinitialized;
void IN_Init( void );
void Host_InputFrame( void );
void IN_Shutdown( void );
void IN_MouseEvent( void );
void IN_ActivateMouse( qboolean force );
void IN_DeactivateMouse( void );
void IN_MouseSavePos( void );
void IN_MouseRestorePos( void );
void IN_ToggleClientMouse( int newstate, int oldstate );
void IN_SetCursor( void *hCursor );

uint IN_CollectInputDevices( void );
void IN_LockInputDevices( qboolean lock );
void IN_EngineAppendMove( float frametime, void *cmd, qboolean active );

//
// in_touch.c
//
typedef enum
{
	event_down = 0,
	event_up,
	event_motion
} touchEventType;

extern convar_t *touch_enable;
extern convar_t *touch_emulate;

void Touch_Draw( void );
void Touch_SetClientOnly( qboolean state );
void Touch_RemoveButton( const char *name );
void Touch_HideButtons( const char *name, unsigned char hide );
//void IN_TouchSetCommand( const char *name, const char *command );
//void IN_TouchSetTexture( const char *name, const char *texture );
//void IN_TouchSetColor( const char *name, byte *color );
void Touch_AddClientButton( const char *name, const char *texture, const char *command, float x1, float y1, float x2, float y2, byte *color, int round, float aspect, int flags );
void Touch_AddDefaultButton( const char *name, const char *texturefile, const char *command, float x1, float y1, float x2, float y2, byte *color, int round, float aspect, int flags );
void Touch_WriteConfig( void );
void Touch_Init( void );
void Touch_Shutdown( void );
void Touch_GetMove( float * forward, float *side, float *yaw, float *pitch );
void Touch_ResetDefaultButtons( void );
int IN_TouchEvent( touchEventType type, int fingerID, float x, float y, float dx, float dy );
void Touch_KeyEvent( int key, int down );

//
// in_joy.c
//
enum
{
	JOY_HAT_CENTERED = 0,
	JOY_HAT_UP    = BIT(0),
	JOY_HAT_RIGHT = BIT(1),
	JOY_HAT_DOWN  = BIT(2),
	JOY_HAT_LEFT  = BIT(3),
	JOY_HAT_RIGHTUP   = JOY_HAT_RIGHT | JOY_HAT_UP,
	JOY_HAT_RIGHTDOWN = JOY_HAT_RIGHT | JOY_HAT_DOWN,
	JOY_HAT_LEFTUP    = JOY_HAT_LEFT  | JOY_HAT_UP,
	JOY_HAT_LEFTDOWN  = JOY_HAT_LEFT  | JOY_HAT_DOWN
};

qboolean Joy_IsActive( void );
void Joy_HatMotionEvent(int id, byte hat, byte value );
void Joy_AxisMotionEvent(int id, byte axis, short value );
void Joy_BallMotionEvent(int id, byte ball, short xrel, short yrel );
void Joy_ButtonEvent(int id, byte button, byte down );
void Joy_AddEvent( void );
void Joy_RemoveEvent( void );
void Joy_FinalizeMove( float *fw, float *side, float *dpitch, float *dyaw );
void Joy_Init( void );
void Joy_Shutdown( void );
void Joy_EnableTextInput(qboolean enable, qboolean force);

// Public joystick API

#define JOYSTICK_INPUT_TYPE_AXIS 1
#define JOYSTICK_INPUT_TYPE_BALL 2
#define JOYSTICK_INPUT_TYPE_BUTTON 3
#define JOYSTICK_INPUT_TYPE_HAT 4

bool Joy_AdvancedAPISupported();
int Joy_GetCount();
void Joy_Activate(int stick_number);
void Joy_Deactivate(int stick_number);
int Joy_ActiveCount();
const char* Joy_NameForIndex(int stick_number);
int Joy_NumButtons(int stick_number);
int Joy_NumAxes(int stick_number);
int Joy_NumBalls(int stick_number);
int Joy_NumHats(int stick_number);
int Joy_ValueForAxis(int stick_number, int axis);       // Value for an axis
int Joy_ValueForBall(int stick_number, int ball);       // value for a ball
int Joy_ValueForButton(int stick_number, int button);   // value for a button
int Joy_ValueForHat(int stick_number, int hat);         // value for a hat
void Joy_AddBallNotifyFunc(int stick_number, void(*pfnNotify)(int index, short dx, short dy));
void Joy_AddAxisNotifyFunc(int stick_number, void(*pfnNotify)(int index, short old_value, short new_value));
void Joy_AddButtonNotifyFunc(int stick_number, void(*pfnNotify)(int index, bool newval));
void Joy_AddHatNotifyFunc(int stick_number, void(*pfnNotify)(int index, bool newval));

//
// in_evdev.c
//
#ifdef XASH_USE_EVDEV
void Evdev_SetGrab( qboolean grab );
void Evdev_Shutdown( void );
void Evdev_Init( void );
#endif // XASH_USE_EVDEV

#endif//INPUT_H
