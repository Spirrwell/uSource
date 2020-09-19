/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/


#include "Framework.h"
#include "Action.h"
#include "Bitmap.h"
#include "PicButton.h"
#include "YesNoMessageBox.h"
#include "keydefs.h"
#include "MenuStrings.h"
#include "PlayerIntroduceDialog.h"
#include "FontManager.h"

#include "public/containers/array.h"
#include "tier1/concommand.h"
#include "crtlib.h"
#include "tier1/vfs.h"

#define ART_MINIMIZE_N	"gfx/shell/min_n"
#define ART_MINIMIZE_F	"gfx/shell/min_f"
#define ART_MINIMIZE_D	"gfx/shell/min_d"
#define ART_CLOSEBTN_N	"gfx/shell/cls_n"
#define ART_CLOSEBTN_F	"gfx/shell/cls_f"
#define ART_CLOSEBTN_D	"gfx/shell/cls_d"

struct main_menu_button_t
{
	CMenuPicButton* btn;
	bool gameonly;
	bool singleonly;
	bool developer;
	bool connected;
	bool ingame;
};

class CMenuMain: public CMenuFramework
{
public:
	CMenuMain() : CMenuFramework( "CMenuMain" ) { }

	bool KeyDown( int key ) override;

public:
	void _Init() override;
	void _VidInit( ) override;

	void VidInit(bool connected);

	void QuitDialog( void *pExtra = NULL );
	void DisconnectCb();
	void DisconnectDialogCb();
	void HazardCourseDialogCb();
	void HazardCourseCb();

	class CMenuMainBanner : public CMenuBannerBitmap
	{
	public:
		virtual void Draw();
	} banner;

	Array<main_menu_button_t> m_buttons;

	// buttons on top right. Maybe should be drawn if fullscreen == 1?
	CMenuBitmap	minimizeBtn;
	CMenuBitmap	quitButton;

	// quit dialog
	CMenuYesNoMessageBox dialog;

	bool bTrainMap;
	bool bCustomGame;

	KeyValues* pMainMenuScheme;
	KeyValues* pMainMenuSection;
};

static CMenuMain uiMain;

void CMenuMain::CMenuMainBanner::Draw()
{
	if( !uiMain.background.ShouldDrawLogoMovie() )
		return; // no logos for steam background

	if( EngFuncs::GetLogoLength() <= 0.05f || EngFuncs::GetLogoWidth() <= 32 )
		return;	// don't draw stub logo (GoldSrc rules)

	float	logoWidth, logoHeight, logoPosY;
	float	scaleX, scaleY;

	scaleX = ScreenWidth / 640.0f;
	scaleY = ScreenHeight / 480.0f;

	// a1ba: multiply by height scale to look better on widescreens
	logoWidth = EngFuncs::GetLogoWidth() * scaleX;
	logoHeight = EngFuncs::GetLogoHeight() * scaleY * uiStatic.scaleY;
	logoPosY = 70 * scaleY * uiStatic.scaleY;	// 70 it's empirically determined value (magic number)

	EngFuncs::DrawLogo( "logo.avi", 0, logoPosY, logoWidth, logoHeight );
}

void CMenuMain::QuitDialog(void *pExtra)
{
	if( CL_IsActive() && EngFuncs::GetCvarFloat( "host_serverstate" ) && EngFuncs::GetCvarFloat( "maxplayers" ) == 1.0f )
		dialog.SetMessage( L( "StringsList_235" ) );
	else
		dialog.SetMessage( L( "GameUI_QuitConfirmationText" ) );

	dialog.onPositive.SetCommand( FALSE, "quit\n" );
	dialog.Show();
}

void CMenuMain::DisconnectCb()
{
	EngFuncs::ClientCmd( FALSE, "disconnect\n" );
	VidInit( false );
}

void CMenuMain::DisconnectDialogCb()
{
	dialog.onPositive = VoidCb( &CMenuMain::DisconnectCb );
	dialog.SetMessage( L( "Really disconnect?" ) );
	dialog.Show();
}

void CMenuMain::HazardCourseDialogCb()
{
	dialog.onPositive = VoidCb( &CMenuMain::HazardCourseCb );;
	dialog.SetMessage( L( "StringsList_234" ) );
	dialog.Show();
}

/*
=================
CMenuMain::Key
=================
*/
bool CMenuMain::KeyDown( int key )
{
	if( UI::Key::IsEscape( key ) )
	{
		if ( CL_IsActive( ))
		{
			if( !dialog.IsVisible() )
				UI_CloseMenu();
		}
		else
		{
			QuitDialog( );
		}
		return true;
	}
	return CMenuFramework::KeyDown( key );
}

/*
=================
UI_Main_HazardCourse
=================
*/
void CMenuMain::HazardCourseCb()
{
	if( EngFuncs::GetCvarFloat( "host_serverstate" ) && EngFuncs::GetCvarFloat( "maxplayers" ) > 1 )
		EngFuncs::HostEndGame( "end of the game" );

	EngFuncs::CvarSetValue( "skill", 1.0f );
	EngFuncs::CvarSetValue( "deathmatch", 0.0f );
	EngFuncs::CvarSetValue( "teamplay", 0.0f );
	EngFuncs::CvarSetValue( "pausable", 1.0f ); // singleplayer is always allowing pause
	EngFuncs::CvarSetValue( "coop", 0.0f );
	EngFuncs::CvarSetValue( "maxplayers", 1.0f ); // singleplayer

	EngFuncs::PlayBackgroundTrack( NULL, NULL );

	EngFuncs::ClientCmd( FALSE, "hazardcourse\n" );
}

void CMenuMain::_Init( void )
{
	this->pMainMenuScheme = new KeyValues();
	
	/* Try to parse the main menu scheme */
	char* fileBuf = fs::ReadFileToBuffer("resource/GameMenu.res");
	this->pMainMenuScheme->ParseString(fileBuf);
	fs::DestroyReadBuffer(fileBuf);

	Assert(this->pMainMenuScheme->IsGood());

	if( gMenu.m_gameinfo.trainmap[0] && stricmp( gMenu.m_gameinfo.trainmap, gMenu.m_gameinfo.startmap ) != 0 )
		bTrainMap = true;
	else bTrainMap = false;

	if( EngFuncs::GetCvarFloat( "host_allow_changegame" ))
		bCustomGame = true;
	else bCustomGame = false;

	dialog.Link( this );

	AddItem( background );
	AddItem( banner );

	/* Add each item from the res file */
	if((this->pMainMenuSection = this->pMainMenuScheme->GetChild("GameMenu")))
	{
		KeyValues* section = this->pMainMenuSection->GetChild("1");
		const char* pMainMenuFont = this->pMainMenuSection->GetString("Font", "Default");
		for(int i = 1; section; i++)
		{
			char buf[8];
			Q_snprintf(buf, sizeof(buf), "%u", i);
			section = this->pMainMenuSection->GetChild(buf);
			if(!section) break;
			const char* localized = section->GetString("label");
			const char* cmd = section->GetString("command");
			
			main_menu_button_t btndesc;
			CMenuPicButton* btn = new CMenuPicButton();

			/* Try to set the font through the keyvalues */
			btn->SetFont(pMainMenuFont);
			btn->SetBaseColor(255, 255, 255, 255);

			btn->SetNameAndStatus(L(localized ? localized : ""), "");
			btn->SetPicture(PC_DISCONNECT); // ?
			btn->iFlags |= QMF_NOTIFY;
			btn->onReleased.SetCommand(TRUE, cmd);
			btndesc.btn = btn;
			btndesc.singleonly = section->GetBool("notmulti");
			btndesc.gameonly = section->GetBool("OnlyInGame", false);
			btndesc.developer = section->GetBool("devonly");
			this->m_buttons.push_back(btndesc);
			AddItem(*btn);
		}
	}

}

/*
=================
UI_Main_Init
=================
*/
void CMenuMain::VidInit( bool connected )
{
	CMenuPicButton::ClearButtonStack();

	bool isGameLoaded = EngFuncs::GetCvarFloat( "host_gameloaded" ) != 0.0f;
	bool isSingle = EngFuncs::GetCvarFloat( "maxplayers" ) <= 1.0f;
	bool isDev = EngFuncs::GetCvarFloat( "developer" ) != 0.0f;

	/* Do a first pass to figure out how many buttons are really enabled */
	int enabled_buttons = 0;
	for(auto btn : this->m_buttons)
	{
		if(!isGameLoaded && btn.gameonly)
			btn.btn->Hide();
		else if(!isSingle && btn.singleonly)
			btn.btn->Hide();
		else if(!isDev && btn.developer)
			btn.btn->Hide();
		else if(!connected && btn.connected)
			btn.btn->Hide();
		else
		{
			btn.btn->Show();
			enabled_buttons++;
		}
	}

	/* Try to get the height of the button font */
	int fontHeight = g_FontMgr->GetFontTall(m_buttons.size() > 0 ? m_buttons[0].btn->font : uiStatic.hDefaultFont);
	int iheight = 640 - enabled_buttons * (fontHeight / (ScreenHeight / 640));
	for(auto btn : this->m_buttons)
	{
		int w, h;
		g_FontMgr->GetTextSize(this->font, btn.btn->szName, &w, &h);
		if(!isGameLoaded && btn.gameonly) continue;
		btn.btn->SetCoord(25, iheight);
		btn.btn->SetRect(25, iheight, w, h);
		iheight += fontHeight / (ScreenHeight / 640) + 10;
		btn.btn->CalcPosition();
	}
}

void CMenuMain::_VidInit()
{
	VidInit( CL_IsActive() );
}

/*
=================
UI_Main_Precache
=================
*/
void UI_Main_Precache( void )
{
	EngFuncs::PIC_Load( ART_MINIMIZE_N );
	EngFuncs::PIC_Load( ART_MINIMIZE_F );
	EngFuncs::PIC_Load( ART_MINIMIZE_D );
	EngFuncs::PIC_Load( ART_CLOSEBTN_N );
	EngFuncs::PIC_Load( ART_CLOSEBTN_F );
	EngFuncs::PIC_Load( ART_CLOSEBTN_D );

	// precache .avi file and get logo width and height
	EngFuncs::PrecacheLogo( "logo.avi" );
}

CONCOMMAND(ResumeGame, "Resumes the game", 0)
{
	UI_CloseMenu();
}

CONCOMMAND(Disconnect, "Disconnects from the server", 0)
{
	uiMain.DisconnectDialogCb();
}

CONCOMMAND(OpenNewGameDialog, "Opens the new game dialog", 0)
{
	UI_NewGame_Menu();
}

CONCOMMAND(OpenLoadGameDialog, "Opens the load game dialog", 0)
{
	UI_LoadGame_Menu();
}

CONCOMMAND(OpenSaveGameDialog, "Opens the save game dialog", 0)
{
}

CONCOMMAND(OpenServerBrowser, "Opens the server browser", 0)
{
	UI_MultiPlayer_Menu();
}

CONCOMMAND(OpenCreateMultiplayerGameDialog, "Opens the multiplayer game dialog", 0)
{
	UI_CustomGame_Menu();
}

CONCOMMAND(OpenChangeGameDialog, "", 0)
{

}

CONCOMMAND(OpenOptionsDialog, "", 0)
{
	UI_Options_Menu();
}

CONCOMMAND(QuitGame, "", 0)
{
	uiMain.QuitDialog();
}

CONCOMMAND(ShowConsole, "", 0)
{
	UI_SetActiveMenu( FALSE );
	EngFuncs::KEY_SetDest( KEY_CONSOLE );
}

CONCOMMAND(StartHazardCourse, "", 0)
{
	uiMain.HazardCourseCb();
}

/*
=================
UI_Main_Menu
=================
*/
void UI_Main_Menu( void )
{
	uiMain.Show();
}
ADD_MENU( menu_main, UI_Main_Precache, UI_Main_Menu );
