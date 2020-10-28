/*
joyinput.c - joystick common input code

Copyright (C) 2016 a1batross

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

#ifndef XASH_DEDICATED

#include "engine/common/common.h"
#include "input.h"
#include "keydefs.h"
#include "client.h"
#include "platform/platform.h"

#include "containers/list.h"
#include "containers/array.h"

#ifdef XASH_SDL
#include <SDL.h>
#endif

#ifndef SHRT_MAX
#define SHRT_MAX 0x7FFF
#endif

/* Absolute max number of joysticks we support at once */
#define MAX_JOYSTICKS 4

typedef enum engineAxis_e
{
        JOY_AXIS_SIDE = 0,
        JOY_AXIS_FWD,
        JOY_AXIS_PITCH,
        JOY_AXIS_YAW,
        JOY_AXIS_RT,
        JOY_AXIS_LT,
        JOY_AXIS_NULL
} engineAxis_t;

#define MAX_AXES JOY_AXIS_NULL

// index - axis num come from event
// value - inner axis
static engineAxis_t joyaxesmap[MAX_AXES] =
{
        JOY_AXIS_SIDE,  // left stick, x
        JOY_AXIS_FWD,   // left stick, y
        JOY_AXIS_PITCH, // right stick, y
        JOY_AXIS_YAW,   // right stick, x
        JOY_AXIS_RT,    // right trigger
        JOY_AXIS_LT     // left trigger
};

static struct joy_axis_s
{
        short val;
        short prevval;
} joyaxis[MAX_AXES] = { 0 };
static byte currentbinding; // add posibility to remap keys, to place it in joykeys[]
convar_t *joy_enable;
static convar_t *joy_pitch;
static convar_t *joy_yaw;
static convar_t *joy_forward;
static convar_t *joy_side;
static convar_t *joy_found;
static convar_t *joy_index;
static convar_t *joy_lt_threshold;
static convar_t *joy_rt_threshold;
static convar_t *joy_side_deadzone;
static convar_t *joy_forward_deadzone;
static convar_t *joy_side_key_threshold;
static convar_t *joy_forward_key_threshold;
static convar_t *joy_pitch_deadzone;
static convar_t *joy_yaw_deadzone;
static convar_t *joy_axis_binding;

static void JoyNew_ProcessHatMotionEvent(int id, byte hat, byte value);
static void JoyNew_ProcessAxisMotionEvent(int id, byte axis, short value);
static void JoyNew_ProcessButtonEvent(int id, byte button, byte down);
static void JoyNew_ProcessBallMotionEvent(int id, byte ball, short xrel, short yrel);


/*
============
Joy_IsActive
============
*/
qboolean Joy_IsActive( void )
{
        return joy_found->value && joy_enable->value;
}

/*
============
Joy_HatMotionEvent

DPad events
============
*/
void Joy_HatMotionEvent(int id, byte hat, byte value)
{
        JoyNew_ProcessHatMotionEvent(id, hat, value);

        struct
        {
                int mask;
                int key;
        } keys[] =
        {
                { JOY_HAT_UP, K_UPARROW },
                { JOY_HAT_DOWN, K_DOWNARROW },
                { JOY_HAT_LEFT, K_LEFTARROW },
                { JOY_HAT_RIGHT, K_RIGHTARROW },
        };
        int i;

        if( !joy_found->value )
                return;

        for( i = 0; i < ARRAYSIZE( keys ); i++ )
        {
                if( value & keys[i].mask )
                {
                        if( !Key_IsDown( keys[i].key ))
                                Key_Event( keys[i].key, true );
                }
                else
                {
                        if( Key_IsDown( keys[i].key ))
                                Key_Event( keys[i].key, false );
                }
        }
}

/*
=============
Joy_ProcessTrigger
=============
*/
static void Joy_ProcessTrigger( const engineAxis_t engineAxis, short value )
{
        int trigButton = 0, trigThreshold = 0;

        switch( engineAxis )
        {
        case JOY_AXIS_RT:
                trigButton = K_JOY2;
                trigThreshold = joy_rt_threshold->value;
                break;
        case JOY_AXIS_LT:
                trigButton = K_JOY1;
                trigThreshold = joy_lt_threshold->value;
                break;
        default:
                Con_Reportf( S_ERROR  "Joy_ProcessTrigger: invalid axis = %i", engineAxis );
                break;
        }

        // update axis values
        joyaxis[engineAxis].prevval = joyaxis[engineAxis].val;
        joyaxis[engineAxis].val = value;

        if( joyaxis[engineAxis].val > trigThreshold &&
                joyaxis[engineAxis].prevval <= trigThreshold ) // ignore random press
        {
                Key_Event( trigButton, true );
        }
        else if( joyaxis[engineAxis].val < trigThreshold &&
                         joyaxis[engineAxis].prevval >= trigThreshold ) // we're unpressing (inverted)
        {
                Key_Event( trigButton, false );
        }
}

static int Joy_GetHatValueForAxis( const engineAxis_t engineAxis )
{
        int threshold, negative, positive;

        switch( engineAxis )
        {
        case JOY_AXIS_SIDE:
                threshold = joy_side_key_threshold->value;
                negative = JOY_HAT_LEFT;
                positive = JOY_HAT_RIGHT;
                break;
        case JOY_AXIS_FWD:
                threshold = joy_side_key_threshold->value;
                negative = JOY_HAT_UP;
                positive = JOY_HAT_DOWN;
                break;
        default:
                ASSERT( false ); // only fwd/side axes can emit key events
                return 0;
        }

        // similar code in Joy_ProcessTrigger
        if( joyaxis[engineAxis].val > threshold &&
                joyaxis[engineAxis].prevval <= threshold ) // ignore random press
        {
                return positive;
        }
        if( joyaxis[engineAxis].val < -threshold &&
                joyaxis[engineAxis].prevval >= -threshold ) // we're unpressing (inverted)
        {
                return negative;
        }
        return 0;
}

/*
=============
Joy_ProcessStick
=============
*/
static void Joy_ProcessStick( const engineAxis_t engineAxis, short value )
{
        int deadzone = 0;

        switch( engineAxis )
        {
        case JOY_AXIS_FWD:   deadzone = joy_forward_deadzone->value; break;
        case JOY_AXIS_SIDE:  deadzone = joy_side_deadzone->value; break;
        case JOY_AXIS_PITCH: deadzone = joy_pitch_deadzone->value; break;
        case JOY_AXIS_YAW:   deadzone = joy_yaw_deadzone->value; break;
        default:
                Con_Reportf( S_ERROR  "Joy_ProcessStick: invalid axis = %i", engineAxis );
                break;
        }

        if( value < deadzone && value > -deadzone )
                value = 0; // caught new event in deadzone, fill it with zero(no motion)

        // update axis values
        joyaxis[engineAxis].prevval = joyaxis[engineAxis].val;
        joyaxis[engineAxis].val = value;

        // fwd/side axis simulate hat movement
        if( ( engineAxis == JOY_AXIS_SIDE || engineAxis == JOY_AXIS_FWD ) &&
                ( CL_IsInMenu() || CL_IsInConsole() ) )
        {
                int val = 0;

                val |= Joy_GetHatValueForAxis( JOY_AXIS_SIDE );
                val |= Joy_GetHatValueForAxis( JOY_AXIS_FWD );

                Joy_HatMotionEvent(-1, 0, val );
        }
}

/*
=============
Joy_AxisMotionEvent

Axis events
=============
*/
void Joy_AxisMotionEvent(int id, byte axis, short value)
{
        JoyNew_ProcessAxisMotionEvent(id, axis, value);

        byte engineAxis;

        if( !joy_found->value )
                return;

        if( axis >= MAX_AXES )
        {
                Con_Reportf( "Only 6 axes is supported\n" );
                return;
        }

        engineAxis = joyaxesmap[axis]; // convert to engine inner axis control

        if( engineAxis == JOY_AXIS_NULL )
                return;

        if( value == joyaxis[engineAxis].val )
                return; // it is not an update

        if( engineAxis >= JOY_AXIS_RT )
                Joy_ProcessTrigger(static_cast<const engineAxis_t>(engineAxis), value );
        else
                Joy_ProcessStick(static_cast<const engineAxis_t>(engineAxis), value );
}

/*
=============
Joy_BallMotionEvent

Trackball events. UNDONE
=============
*/
void Joy_BallMotionEvent(int id, byte ball, short xrel, short yrel)
{
        JoyNew_ProcessBallMotionEvent(id, ball, xrel, yrel);
        //if( !joy_found->value )
        //      return;
}

/*
=============
Joy_ButtonEvent

Button events
=============
*/
void Joy_ButtonEvent(int id, byte button, byte down)
{
        JoyNew_ProcessButtonEvent(id, button, down);

        if( !joy_found->value )
                return;

        // generic game button code.
        if( button > 32 )
        {
                int origbutton = button;
                button = ( button & 31 ) + K_AUX1;

                Con_Reportf( "Only 32 joybuttons is supported, converting %i button ID to %s\n", origbutton, Key_KeynumToString( button ) );
        }
        else button += K_AUX1;

        Key_Event( button, down );
}

/*
=============
Joy_RemoveEvent

Called when joystick is removed. For future expansion
=============
*/
void Joy_RemoveEvent( void )
{
        if( joy_found->value )
                Cvar_FullSet( "joy_found", "0", FCVAR_READ_ONLY );
}

/*
=============
Joy_RemoveEvent

Called when joystick is removed. For future expansion
=============
*/
void Joy_AddEvent( void )
{
        if( joy_enable->value && !joy_found->value )
                Cvar_FullSet( "joy_found", "1", FCVAR_READ_ONLY );
}

/*
=============
Joy_FinalizeMove

Append movement from axis. Called everyframe
=============
*/
void Joy_FinalizeMove( float *fw, float *side, float *dpitch, float *dyaw )
{
        if( !Joy_IsActive() )
                return;

        if( FBitSet( joy_axis_binding->flags, FCVAR_CHANGED ) )
        {
                const char *bind = joy_axis_binding->string;
                size_t i;

                for( i = 0; bind[i]; i++ )
                {
                        switch( bind[i] )
                        {
                        case 's': joyaxesmap[i] = JOY_AXIS_SIDE; break;
                        case 'f': joyaxesmap[i] = JOY_AXIS_FWD; break;
                        case 'y': joyaxesmap[i] = JOY_AXIS_YAW; break;
                        case 'p': joyaxesmap[i] = JOY_AXIS_PITCH; break;
                        case 'r': joyaxesmap[i] = JOY_AXIS_RT; break;
                        case 'l': joyaxesmap[i] = JOY_AXIS_LT; break;
                        default : joyaxesmap[i] = JOY_AXIS_NULL; break;
                        }
                }

                ClearBits( joy_axis_binding->flags, FCVAR_CHANGED );
        }

        *fw     -= joy_forward->value * (float)joyaxis[JOY_AXIS_FWD ].val/(float)SHRT_MAX;  // must be form -1.0 to 1.0
        *side   += joy_side->value    * (float)joyaxis[JOY_AXIS_SIDE].val/(float)SHRT_MAX;
#if !defined(XASH_SDL)
        *dpitch += joy_pitch->value * (float)joyaxis[JOY_AXIS_PITCH].val/(float)SHRT_MAX * host.realframetime;  // abs axis rotate is frametime related
        *dyaw   -= joy_yaw->value   * (float)joyaxis[JOY_AXIS_YAW  ].val/(float)SHRT_MAX * host.realframetime;
#else
        // HACKHACK: SDL have inverted look axis.
        *dpitch -= joy_pitch->value * (float)joyaxis[JOY_AXIS_PITCH].val/(float)SHRT_MAX * host.realframetime;
        *dyaw   += joy_yaw->value   * (float)joyaxis[JOY_AXIS_YAW  ].val/(float)SHRT_MAX * host.realframetime;
#endif
}

/*
=============
Joy_Init

Main init procedure
=============
*/
void Joy_Init( void )
{
        joy_pitch   = Cvar_Get( "joy_pitch",   "100.0", FCVAR_ARCHIVE, "joystick pitch sensitivity" );
        joy_yaw     = Cvar_Get( "joy_yaw",     "100.0", FCVAR_ARCHIVE, "joystick yaw sensitivity" );
        joy_side    = Cvar_Get( "joy_side",    "1.0", FCVAR_ARCHIVE, "joystick side sensitivity. Values from -1.0 to 1.0" );
        joy_forward = Cvar_Get( "joy_forward", "1.0", FCVAR_ARCHIVE, "joystick forward sensitivity. Values from -1.0 to 1.0" );

        joy_lt_threshold = Cvar_Get( "joy_lt_threshold", "-16384", FCVAR_ARCHIVE, "left trigger threshold. Value from -32768 to 32767");
        joy_rt_threshold = Cvar_Get( "joy_rt_threshold", "-16384", FCVAR_ARCHIVE, "right trigger threshold. Value from -32768 to 32767" );

        // emit a key event at 75% axis move
        joy_side_key_threshold = Cvar_Get( "joy_side_key_threshold", "24576", FCVAR_ARCHIVE, "side axis key event emit threshold. Value from 0 to 32767" );
        joy_forward_key_threshold = Cvar_Get( "joy_forward_key_threshold", "24576", FCVAR_ARCHIVE, "forward axis key event emit threshold. Value from 0 to 32767");

        // by default, we rely on deadzone detection come from system, but some glitchy devices report false deadzones
        joy_side_deadzone = Cvar_Get( "joy_side_deadzone", "0", FCVAR_ARCHIVE, "side axis deadzone. Value from 0 to 32767" );
        joy_forward_deadzone = Cvar_Get( "joy_forward_deadzone", "0", FCVAR_ARCHIVE, "forward axis deadzone. Value from 0 to 32767");
        joy_pitch_deadzone = Cvar_Get( "joy_pitch_deadzone", "0", FCVAR_ARCHIVE, "pitch axis deadzone. Value from 0 to 32767");
        joy_yaw_deadzone = Cvar_Get( "joy_yaw_deadzone", "0", FCVAR_ARCHIVE, "yaw axis deadzone. Value from 0 to 32767" );

        joy_axis_binding = Cvar_Get( "joy_axis_binding", "sfpyrl", FCVAR_ARCHIVE, "axis hardware id to engine inner axis binding, "
                "s - side, f - forward, y - yaw, p - pitch, r - left trigger, l - right trigger" );
        joy_found   = Cvar_Get( "joy_found", "0", FCVAR_READ_ONLY, "is joystick is connected" );
        // we doesn't loaded config.cfg yet, so this cvar is not archive.
        // change by +set joy_index in cmdline
        joy_index   = Cvar_Get( "joy_index", "0", FCVAR_READ_ONLY, "current active joystick" );

        joy_enable = Cvar_Get( "joy_enable", "1", FCVAR_ARCHIVE, "enable joystick" );

        if( Sys_CheckParm( "-nojoy" ))
        {
                Cvar_FullSet( "joy_enable", "0", FCVAR_READ_ONLY );
                return;
        }

        Cvar_FullSet( "joy_found", va( "%d", Platform_JoyInit( joy_index->value )), FCVAR_READ_ONLY );
}

/*
===========
Joy_Shutdown

Shutdown joystick code
===========
*/
void Joy_Shutdown( void )
{
        Cvar_FullSet( "joy_found", 0, FCVAR_READ_ONLY );
}

/*
============================================

 NEW JOYSTICK API

============================================
*/

#ifdef XASH_SDL

/* Object oriented approach here, why not */
struct CJoystick
{
        int m_deviceIndex;
        SDL_Joystick* m_stick;
        SDL_JoystickType m_type;
        int m_numAxes, m_numBalls, m_numButtons, m_numHats;
        SDL_JoystickID m_id; // Different than device index!
        bool m_init;

        /* Front Buffers */
        short* m_axisBuffer;
        short* m_ballXBuffer;
        short* m_ballYBuffer;
        byte* m_hatBuffer;
        byte* m_buttonBuffer;

        /* Back buffers */
        short*  m_backAxisBuffer;
        short*  m_backBallXBuffer;
        short*  m_backBallYBuffer;
        byte*   m_backHatBuffer;
        byte*   m_backButtonBuffer;

        List<void(*)(int,short,short)> m_axisDelegates;
        List<void(*)(int,bool)> m_buttonDelegates;
        List<void(*)(int,bool)> m_hatDelegates;
        List<void(*)(int,short,short)> m_ballDelegates;

        CJoystick() :
                m_stick(nullptr),
                m_deviceIndex(0),
                m_numHats(0),
                m_numButtons(0),
                m_numBalls(0),
                m_numAxes(0),
                m_type(SDL_JOYSTICK_TYPE_UNKNOWN),
                m_id(0),
                m_axisBuffer(nullptr),
                m_ballXBuffer(nullptr),
                m_ballYBuffer(nullptr),
                m_buttonBuffer(nullptr),
                m_hatBuffer(nullptr),
                m_init(false)
        {
        }

        explicit CJoystick(int index) :
                m_init(true)
        {
                m_deviceIndex = index;

                m_stick = SDL_JoystickOpen(index);
                if(!m_stick)
                {
                        Con_Printf("Failed to open joystick %i: %s\n", index, SDL_GetError());
                        m_init = false;
                        return;
                }
                m_id = SDL_JoystickInstanceID(m_stick);
                m_type = SDL_JoystickGetType(m_stick);

                m_numAxes = SDL_JoystickNumAxes(m_stick);
                m_numBalls = SDL_JoystickNumBalls(m_stick);
                m_numButtons = SDL_JoystickNumButtons(m_stick);
                m_numHats = SDL_JoystickNumHats(m_stick);

                /* Alloc buffers */
                m_buttonBuffer = static_cast<byte *>(calloc(1, sizeof(byte) * m_numButtons));
                m_ballYBuffer = static_cast<short *>(calloc(1, sizeof(short) * m_numBalls));
                m_ballXBuffer = static_cast<short *>(calloc(1, sizeof(short) * m_numBalls));
                m_hatBuffer = static_cast<byte *>(calloc(1,sizeof(byte) * m_numHats));
                m_axisBuffer = static_cast<short *>(calloc(1,sizeof(short) * m_numAxes));

                m_backButtonBuffer = static_cast<byte *>(calloc(1, sizeof(byte) * m_numButtons));
                m_backBallYBuffer = static_cast<short *>(calloc(1, sizeof(short) * m_numBalls));
                m_backBallXBuffer = static_cast<short *>(calloc(1, sizeof(short) * m_numBalls));
                m_backHatBuffer = static_cast<byte *>(calloc(1,sizeof(byte) * m_numHats));
                m_backAxisBuffer = static_cast<short *>(calloc(1,sizeof(short) * m_numAxes));


        }

        ~CJoystick()
        {
        }

        void close()
        {
                if(m_stick) SDL_JoystickClose(m_stick);
                if(m_buttonBuffer) free(m_buttonBuffer);
                if(m_ballYBuffer) free(m_ballYBuffer);
                if(m_ballXBuffer) free(m_ballXBuffer);
                if(m_hatBuffer) free(m_hatBuffer);
                if(m_axisBuffer) free(m_axisBuffer);
        }

        const char* getName() const
        {
                return SDL_JoystickNameForIndex(m_deviceIndex);
        }

        void resetAxes()
        {
                memset(m_axisBuffer, 0, sizeof(short) * m_numAxes);
                memset(m_backAxisBuffer, 0, sizeof(short) * m_numAxes);
        }

        void resetButtons()
        {
                memset(m_buttonBuffer, 0, sizeof(byte) * m_numButtons);
                memset(m_backButtonBuffer, 0, sizeof(byte) * m_numButtons);
        }

        void resetHats()
        {
                memset(m_hatBuffer, 0, sizeof(byte) * m_numHats);
                memset(m_backHatBuffer, 0, sizeof(byte) * m_numHats);
        }

        void resetBalls()
        {
                memset(m_ballYBuffer, 0, sizeof(short) * m_numBalls);
                memset(m_ballXBuffer, 0, sizeof(short) * m_numBalls);
                memset(m_backBallYBuffer, 0, sizeof(short) * m_numBalls);
                memset(m_backBallXBuffer, 0, sizeof(short) * m_numBalls);
        }

        /* Resets all buffers to 0 */
        void resetInputStates()
        {
                resetAxes();
                resetBalls();
                resetHats();
                resetButtons();
        }

        void frame()
        {
                memcpy(m_backButtonBuffer, m_buttonBuffer, sizeof(byte) * m_numButtons);
                memcpy(m_backAxisBuffer, m_axisBuffer, sizeof(short) * m_numAxes);
                memcpy(m_backBallXBuffer, m_ballXBuffer, sizeof(short) * m_numBalls);
                memcpy(m_backBallYBuffer, m_ballYBuffer, sizeof(short) * m_numBalls);
                memcpy(m_backHatBuffer, m_hatBuffer, sizeof(byte) * m_numHats);

                /* Only reset the ball buffers since they operate in terms of deltas only */
                memset(m_ballXBuffer, 0, sizeof(short) * m_numBalls);
                memset(m_ballYBuffer, 0, sizeof(short) * m_numBalls);

                /* Execute any delegate handlers */
                

                for(int i = 0; i < m_numAxes; i++)
                {
                        if(m_axisBuffer[i] != m_backAxisBuffer[i])
                        {
                                for(auto d : m_axisDelegates)
                                        d(i, m_backAxisBuffer[i], m_axisBuffer[i]);
                        }
                }
                for(int i = 0; i < m_numHats; i++)
                {
                        if(m_backHatBuffer[i] != m_hatBuffer[i])
                        {
                                for(auto d : m_hatDelegates)
                                        d(i, m_hatBuffer[i]);
                        }
                }
                for(int i = 0; i < m_numBalls; i++)
                {
                        if(m_backBallXBuffer[i] || m_backBallYBuffer[i])
                        {
                                for(auto d : m_ballDelegates)
                                        d(i, m_backBallXBuffer[i], m_backBallYBuffer[i]);
                        }
                }
                for(int i = 0; i < m_numButtons; i++)
                {
                        if(m_backButtonBuffer[i] != m_buttonBuffer[i])
                        {
                                for(auto d : m_buttonDelegates)
                                        d(i, m_buttonBuffer[i]);
                        }
                }
        }

        short getAxisValue(int axis) const
        {
                if(axis >= m_numAxes || axis < 0) return 0;
                return m_axisBuffer[axis];
        }

        byte getButtonValue(int button) const
        {
                if(button >= m_numButtons || button < 0) return 0;
                return m_buttonBuffer[button];
        }

        short getHatValue(int hat) const
        {
                if(hat >= m_numHats || hat < 0) return 0;
                return m_hatBuffer[hat];
        }

        void getBallValue(int ball, short& x, short& y) const
        {
                if(ball >= m_numBalls || ball < 0) {
                        x = y = 0;
                        return;
                }
                x = m_ballXBuffer[ball];
                y = m_ballYBuffer[ball];
        }

        void processHatMotionEvent(byte hat, byte value)
        {
                if(!m_init) return;
                if(hat > m_numHats) return;
                m_hatBuffer[hat] = value;
        }

        void processAxisMotionEvent(byte axis, short value)
        {
                if(!m_init) return;
                if(axis > m_numAxes) return;
                m_axisBuffer[axis] = value;
        }

        void processButtonEvent(byte button, byte down)
        {
                if(!m_init) return;
                if(button > m_numButtons) return;
                m_buttonBuffer[button] = down;
        }

        void processBallMotionEvent(byte ball, short xrel, short yrel)
        {
                if(!m_init) return;
                if(ball > m_numBalls) return;
                m_ballXBuffer[ball] += xrel;
                m_ballYBuffer[ball] += yrel;
        }

        /* Delta functions return the change in the values since the last frame */

        short getAxisDelta(int axis) const
        {
                if(axis >= m_numAxes || axis < 0) return 0;
                return m_axisBuffer[axis] - m_backAxisBuffer[axis];
        }

        void getBallDelta(int ball, short& dx, short& dy)
        {
                if(ball >= m_numBalls || ball < 0) {
                        dx = dy = 0;
                        return;
                }
                dx = (short)(m_ballXBuffer[ball] - m_backBallXBuffer[ball]);
                dy = (short)(m_ballYBuffer[ball] - m_backBallYBuffer[ball]);
        }
};

List<CJoystick> g_EnabledJoysticks;

static CJoystick FindJoystick(int num)
{
        // In the event we only have 1 joystick, just use the quicker logic (no iterator creation or any of that crap)
#if MAX_JOYSTICKS > 1
        for(const auto& j : g_EnabledJoysticks)
        {
                if(j.m_deviceIndex == num)
                        return j;
        }
        return CJoystick();
#else
        if(g_EnabledJoysticks.size()) return g_EnabledJoysticks[0];
        return CJoystick();
#endif
}


#endif // XASH_SDL

static void JoyNew_ProcessHatMotionEvent(int id, byte hat, byte value)
{
#ifdef XASH_SDL
        FindJoystick(id).processHatMotionEvent(hat, value);
#endif
}

static void JoyNew_ProcessAxisMotionEvent(int id, byte axis, short value)
{
#ifdef XASH_SDL
        FindJoystick(id).processAxisMotionEvent(axis, value);
#endif
}

static void JoyNew_ProcessButtonEvent(int id, byte button, byte down)
{
#ifdef XASH_SDL
        FindJoystick(id).processButtonEvent(button, down);
#endif
}

static void JoyNew_ProcessBallMotionEvent(int id, byte ball, short xrel, short yrel)
{
#ifdef XASH_SDL
        FindJoystick(id).processBallMotionEvent(ball, xrel, yrel);
#endif
}


bool Joy_AdvancedAPISupported()
{
#ifdef XASH_SDL
        return true;
#else
        return false;
#endif
}

int Joy_GetCount()
{
#ifdef XASH_SDL
        return SDL_NumJoysticks();
#else
        return 0;
#endif
}

void Joy_Activate(int stick_number)
{
#ifdef XASH_SDL

        /* Check if already active */
        for(const auto& j : g_EnabledJoysticks)
        {
                if(j.m_deviceIndex == stick_number)
                {
                        Con_Printf("Attempted to active joystick %i twice!\n", stick_number);
                        Assert(0);
                        return;
                }
        }

        CJoystick stick = CJoystick(stick_number);
        if(!stick.m_init) return;

        g_EnabledJoysticks.push_back(stick);

        Con_DPrintf("Activated joystick %i. \n\tName: %s \n\tVendor: %u\n", stick_number, SDL_JoystickName(stick.m_stick), SDL_JoystickGetVendor(stick.m_stick));

#endif
}

void Joy_Deactivate(int stick_number)
{
#ifdef XASH_SDL
        for(auto it = g_EnabledJoysticks.begin(); it != g_EnabledJoysticks.end(); it++)
        {
                if((*it).m_deviceIndex == stick_number)
                {
                        it->close();
                        g_EnabledJoysticks.erase(it);
                        Con_Printf("Deactivated joystick %i\n", it->m_deviceIndex);
                        return;
                }
        }
        Con_Printf("Could not deactivate joystick %i\n", stick_number);
#endif
}

int Joy_ActiveCount()
{
#ifdef XASH_SDL
        return g_EnabledJoysticks.size();
#endif
}

const char *Joy_NameForIndex(int stick_number)
{
#ifdef XASH_SDL
        return SDL_JoystickNameForIndex(stick_number);
#endif
}

int Joy_NumButtons(int stick_number)
{
#ifdef XASH_SDL
        return FindJoystick(stick_number).m_numButtons;
#else
        return 0;
#endif
}

int Joy_NumAxes(int stick_number)
{
#ifdef XASH_SDL
        return FindJoystick(stick_number).m_numAxes;
#else
        return 0;
#endif
}

int Joy_NumBalls(int stick_number)
{
#ifdef XASH_SDL
        return FindJoystick(stick_number).m_numBalls;
#else
        return 0;
#endif
}

int Joy_NumHats(int stick_number)
{
#ifdef XASH_SDL
        return FindJoystick(stick_number).m_numHats;
#else
        return 0;
#endif
}

int Joy_ValueForAxis(int stick_number, int axis)
{
#ifdef XASH_SDL
	return FindJoystick(stick_number).getAxisValue(axis);
#else
        return 0;
#endif
}

void Joy_ValueForBall(int stick_number, int ball, short& x, short& y)
{
#ifdef XASH_SDL
        return FindJoystick(stick_number).getBallValue(ball, x,y);
#else
        x = y = 0;
#endif
}

int Joy_ValueForButton(int stick_number, int button)
{
#ifdef XASH_SDL
        return FindJoystick(stick_number).getButtonValue(button);
#else
        return 0;
#endif
}

int Joy_ValueForHat(int stick_number, int hat)
{
#ifdef XASH_SDL
        return FindJoystick(stick_number).getHatValue(hat);
#else
        return 0;
#endif
}

void Joy_AddBallNotifyFunc(int stick_number, void(*pfnNotify)(int index, short dx, short dy))
{
#ifdef XASH_SDL
        CJoystick j = FindJoystick(stick_number);
        if(j.m_init) j.m_ballDelegates.push_back(pfnNotify);
#endif 

}

void Joy_AddAxisNotifyFunc(int stick_number, void(*pfnNotify)(int index, short old_value, short new_value))
{
#ifdef XASH_SDL
        CJoystick j = FindJoystick(stick_number);
        if(j.m_init) j.m_axisDelegates.push_back(pfnNotify);
#endif 
}

void Joy_AddButtonNotifyFunc(int stick_number, void(*pfnNotify)(int index, bool newval))
{
#ifdef XASH_SDL
        CJoystick j = FindJoystick(stick_number);
        if(j.m_init) j.m_buttonDelegates.push_back(pfnNotify);
#endif 
}

void Joy_AddHatNotifyFunc(int stick_number, void(*pfnNotify)(int index, bool newval))
{
#ifdef XASH_SDL
        CJoystick j = FindJoystick(stick_number);
        if(j.m_init) j.m_hatDelegates.push_back(pfnNotify);
#endif 
}


#endif // XASH_DEDICATED
