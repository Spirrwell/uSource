/*
dll_int.cpp - dll entry point
Copyright (C) 2010 Uncle Mike

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/


#include "ExtDllMenu.h"
#include "BaseMenu.h"
#include "Utils.h"

ui_enginefuncs_t EngFuncs::engfuncs;
ui_extendedfuncs_t EngFuncs::textfuncs;
ui_globalvars_t	*gpGlobals;
CMenu gMenu;
bool g_bIsForkedEngine;

static UI_FUNCTIONS gFunctionTable = 
{
	UI_VidInit,
	UI_Init,
	UI_Shutdown,
	UI_UpdateMenu,
	UI_KeyEvent,
	UI_MouseMove,
	UI_SetActiveMenu,
	UI_AddServerToList,
	UI_GetCursorPos,
	UI_SetCursorPos,
	UI_ShowCursor,
	UI_CharEvent,
	UI_MouseInRect,
	UI_IsVisible,
	UI_CreditsActive,
	UI_FinalCredits
};

//=======================================================================
//			GetApi
//=======================================================================
extern "C" EXPORT int GetMenuAPI(UI_FUNCTIONS *pFunctionTable, ui_enginefuncs_t* pEngfuncsFromEngine, ui_globalvars_t *pGlobals)
{
	if( !pFunctionTable || !pEngfuncsFromEngine )
	{
		return FALSE;
	}

	// copy HUD_FUNCTIONS table to engine, copy engfuncs table from engine
	memcpy( pFunctionTable, &gFunctionTable, sizeof( UI_FUNCTIONS ));
	memcpy( &EngFuncs::engfuncs, pEngfuncsFromEngine, sizeof( ui_enginefuncs_t ));
	memset( &EngFuncs::textfuncs, 0, sizeof( ui_extendedfuncs_t ));

	gpGlobals = pGlobals;

	// can be hijacked, but please, don't do it
	const char *version = EngFuncs::GetCvarString( "host_ver" );

	g_bIsForkedEngine = version && version[0];

	return TRUE;
}

static UI_EXTENDED_FUNCTIONS gExtendedTable =
{
	AddTouchButtonToList,
	UI_MenuResetPing_f,
	UI_ConnectionWarning_f,
	UI_UpdateDialog,
	UI_ShowMessageBox,
	UI_ConnectionProgress_Disconnect,
	UI_ConnectionProgress_Download,
	UI_ConnectionProgress_DownloadEnd,
	UI_ConnectionProgress_Precache,
	UI_ConnectionProgress_Connect,
	UI_ConnectionProgress_ChangeLevel,
	UI_ConnectionProgress_ParseServerInfo
};

extern "C" EXPORT int GetExtAPI( int version, UI_EXTENDED_FUNCTIONS *pFunctionTable, ui_extendedfuncs_t *pEngfuncsFromEngine )
{
	if( !pFunctionTable || !pEngfuncsFromEngine )
	{
		return FALSE;
	}

	if( version != MENU_EXTENDED_API_VERSION )
	{
		Con_Printf( "Error: failed to initialize extended menu API. Expected by DLL: %d. Got from engine: %d\n", MENU_EXTENDED_API_VERSION, version );
		return FALSE;
	}

	memcpy( &EngFuncs::textfuncs, pEngfuncsFromEngine, sizeof( ui_extendedfuncs_t ) );
	memcpy( pFunctionTable, &gExtendedTable, sizeof( UI_EXTENDED_FUNCTIONS ));

	return TRUE;
}

class CMainUI001 : public IMainUIInterface
{
public:
	const char* GetParentInterface() override { return IMAINUI_INTERFACE; };
	const char* GetName() override { return "CMainUI001"; };
	bool PreInit() override { return true; };
	bool Init() override { return true; };
	void Shutdown() override {};

	int VidInit( void ) override;
	void UIInit( void ) override;
	void UIShutdown( void ) override;
	void Redraw( float flTime ) override;
	void KeyEvent( int key, int down ) override;
	void MouseMove( int x, int y ) override;
	void SetActiveMenu( int active ) override;
	void AddServerToList( struct netadr_s adr, const char *info ) override;
	void GetCursorPos( int *pos_x, int *pos_y ) override;
	void SetCursorPos( int pos_x, int pos_y ) override;
	void ShowCursor( int show ) override;
	void CharEvent( int key ) override;
	int MouseInRect( void ) override;
	int IsVisible( void ) override;
	int CreditsActive( void ) override;
	void FinalCredits( void ) override;
	void ResetPing( void ) override;
	void ShowConnectionWarning( void ) override;
	void ShowUpdateDialog( int preferStore ) override;
	void ShowMessageBox( const char *text ) override;
	void ConnectionProgress_Disconnect( void ) override;
	void ConnectionProgress_Download( const char *pszFileName, const char *pszServerName, int iCurrent, int iTotal, const char *comment ) override;
	void ConnectionProgress_DownloadEnd( void ) override;
	void ConnectionProgress_Precache( void ) override;
	void ConnectionProgress_Connect( const char *server ) override;
	void ConnectionProgress_ChangeLevel( void ) override;
	void ConnectionProgress_ParseServerInfo( const char *server ) override;
	void EnableTextInput( int enable ) override;
	int UtfProcessChar( int ch ) override;
	int UtfMoveLeft( char *str, int pos ) override;
	int UtfMoveRight( char *str, int pos, int length ) override;
};

EXPOSE_INTERFACE(CMainUI001);
MODULE_INTERFACE_IMPL();

int CMainUI001::VidInit(void)
{
	return UI_VidInit();
}

void CMainUI001::UIInit(void)
{
	UI_Init();
}

void CMainUI001::UIShutdown(void)
{
	UI_Shutdown();
}

void CMainUI001::Redraw(float flTime)
{
	UI_UpdateMenu(flTime);
}

void CMainUI001::KeyEvent(int key, int down)
{
	UI_KeyEvent(key, down);
}

void CMainUI001::MouseMove(int x, int y)
{
	UI_MouseMove(x, y);
}

void CMainUI001::SetActiveMenu(int active)
{
	UI_SetActiveMenu(active);
}

void CMainUI001::AddServerToList(struct netadr_s adr, const char *info)
{
	UI_AddServerToList(adr, info);
}

void CMainUI001::GetCursorPos(int *pos_x, int *pos_y)
{
	UI_GetCursorPos(pos_x, pos_y);
}

void CMainUI001::SetCursorPos(int pos_x, int pos_y)
{
	UI_SetCursorPos(pos_x, pos_y);
}

void CMainUI001::ShowCursor(int show)
{
	UI_ShowCursor(show);
}

void CMainUI001::CharEvent(int key)
{
	UI_CharEvent(key);
}

int CMainUI001::MouseInRect(void)
{
	return UI_MouseInRect();
}

int CMainUI001::IsVisible(void)
{
	return UI_IsVisible();
}

int CMainUI001::CreditsActive(void)
{
	return UI_CreditsActive();
}

void CMainUI001::FinalCredits(void)
{
	UI_FinalCredits();
}

void CMainUI001::ResetPing(void)
{
	UI_MenuResetPing_f();
}

void CMainUI001::ShowConnectionWarning(void)
{
	UI_ConnectionWarning_f();
}

void CMainUI001::ShowUpdateDialog(int preferStore)
{
	UI_UpdateDialog(preferStore);
}

void CMainUI001::ShowMessageBox(const char *text)
{
	UI_ShowMessageBox(text);
}

void CMainUI001::ConnectionProgress_Disconnect(void)
{
	UI_ConnectionProgress_Disconnect();
}

void
CMainUI001::ConnectionProgress_Download(const char *pszFileName, const char *pszServerName, int iCurrent, int iTotal,
                                        const char *comment)
{
	UI_ConnectionProgress_Download(pszFileName, pszServerName, iCurrent, iTotal, comment);
}

void CMainUI001::ConnectionProgress_DownloadEnd(void)
{
	UI_ConnectionProgress_DownloadEnd();
}

void CMainUI001::ConnectionProgress_Precache(void)
{
	UI_ConnectionProgress_Precache();
}

void CMainUI001::ConnectionProgress_Connect(const char *server)
{
	UI_ConnectionProgress_Connect(server);
}

void CMainUI001::ConnectionProgress_ChangeLevel(void)
{
	UI_ConnectionProgress_ChangeLevel();
}

void CMainUI001::ConnectionProgress_ParseServerInfo(const char *server)
{
	UI_ConnectionProgress_ParseServerInfo(server);
}

void CMainUI001::EnableTextInput(int enable)
{
	UI_EnableTextInput(enable);
}

int CMainUI001::UtfProcessChar(int ch)
{
	return Con_UtfProcessChar(ch);
}

int CMainUI001::UtfMoveLeft(char *str, int pos)
{
	return Con_UtfMoveLeft(str, pos);
}

int CMainUI001::UtfMoveRight(char *str, int pos, int length)
{
	return Con_UtfMoveRight(str, pos, length);
}