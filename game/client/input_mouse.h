#pragma once
#ifndef INPUT_MOUSE_H
#define INPUT_MOUSE_H
#include "cl_dll.h"
#include "usercmd.h"
#include "in_defs.h"

class AbstractInput
{
public:
	virtual void IN_ClientMoveEvent( float forwardmove, float sidemove ) = 0;
	virtual void IN_ClientLookEvent( float relyaw, float relpitch ) = 0;
	virtual void IN_Move( float frametime, usercmd_t *cmd ) = 0;
	virtual void IN_MouseEvent( int mstate ) = 0;
	virtual void IN_ClearStates( void ) = 0;
	virtual void IN_ActivateMouse( void ) = 0;
	virtual void IN_DeactivateMouse( void ) = 0;
	virtual void IN_Accumulate( void ) = 0;
	virtual void IN_Commands( void ) = 0;
	virtual void IN_Shutdown( void ) = 0;
	virtual void IN_Init( void ) = 0;
};

class CInput : public AbstractInput
{
public:
	virtual void IN_ClientMoveEvent( float forwardmove, float sidemove );
	virtual void IN_ClientLookEvent( float relyaw, float relpitch );
	virtual void IN_Move( float frametime, usercmd_t *cmd );
	virtual void IN_MouseEvent( int mstate );
	virtual void IN_ClearStates( void );
	virtual void IN_ActivateMouse( void );
	virtual void IN_DeactivateMouse( void );
	virtual void IN_Accumulate( void );
	virtual void IN_Commands( void );
	virtual void IN_Shutdown( void );
	virtual void IN_Init( void );

protected:
	float ac_forwardmove;
	float ac_sidemove;
	int ac_movecount;
	float rel_yaw;
	float rel_pitch;
};

#endif
