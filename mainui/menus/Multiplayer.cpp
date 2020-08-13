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

#include "Bitmap.h"
#include "Framework.h"
#include "PlayerIntroduceDialog.h"
#include "YesNoMessageBox.h"
#include "keydefs.h"

#define ART_BANNER "gfx/shell/head_multi"

class CMenuMultiplayer : public CMenuFramework
{
public:
	CMenuMultiplayer() : CMenuFramework("CMenuMultiplayer") {}

	void AskPredictEnable() { msgBox.Show(); }

private:
	void _Init() override;

	// prompt dialog
	CMenuYesNoMessageBox msgBox;
};

static CMenuMultiplayer uiMultiPlayer;

/*
=================
CMenuMultiplayer::Init
=================
*/
void CMenuMultiplayer::_Init(void)
{
	// memset( &uiMultiPlayer, 0, sizeof( CMenuMultiplayer ));
	AddItem(background);

	banner.SetPicture(ART_BANNER);
	AddItem(banner);

	AddButton(L("Internet game"), L("View list of a game internet servers and join the one of your choice"), PC_INET_GAME, UI_InternetGames_Menu,
		  QMF_NOTIFY);
	// AddButton( L( "Spectate game" ), L( "Spectate internet games" ), PC_SPECTATE_GAMES, NoopCb, QMF_GRAYED | QMF_NOTIFY );
	AddButton(L("LAN game"), L("Set up the game on the local area network"), PC_LAN_GAME, UI_LanGame_Menu, QMF_NOTIFY);
	AddButton(L("GameUI_GameMenu_Customize"), L("Choose your player name, and select visual options for your character"), PC_CUSTOMIZE,
		  UI_PlayerSetup_Menu, QMF_NOTIFY);
	AddButton(L("Controls"), L("Change keyboard and mouse settings"), PC_CONTROLS, UI_Controls_Menu, QMF_NOTIFY);
	AddButton(L("Done"), L("Go back to the Main menu"), PC_DONE, VoidCb(&CMenuMultiplayer::Hide), QMF_NOTIFY);

	msgBox.SetMessage(L(
		"It is recomended to enable client movement prediction.\nPress OK to enable it now or enable it later in ^5(Multiplayer/Customize)"));
	msgBox.SetPositiveButton(L("GameUI_OK"), PC_OK);
	msgBox.SetNegativeButton(L("GameUI_Cancel"), PC_CANCEL);
	msgBox.HighlightChoice(CMenuYesNoMessageBox::HIGHLIGHT_YES);
	SET_EVENT_MULTI(msgBox.onPositive, {
		EngFuncs::CvarSetValue("cl_predict", 1.0f);
		EngFuncs::CvarSetValue("menu_mp_firsttime", 0.0f);

		UI_PlayerIntroduceDialog_Show(&uiMultiPlayer);
	});
	SET_EVENT_MULTI(msgBox.onNegative, {
		EngFuncs::CvarSetValue("menu_mp_firsttime", 0.0f);

		UI_PlayerIntroduceDialog_Show(&uiMultiPlayer);
	});
	msgBox.Link(this);
}

/*
=================
CMenuMultiplayer::Precache
=================
*/
void UI_MultiPlayer_Precache(void) { EngFuncs::PIC_Load(ART_BANNER); }

/*
=================
UI_MultiPlayer_Menu
=================
*/
void UI_MultiPlayer_Menu(void)
{
	if (gMenu.m_gameinfo.gamemode == GAME_SINGLEPLAYER_ONLY)
		return;

	uiMultiPlayer.Show();

	if (EngFuncs::GetCvarFloat("menu_mp_firsttime") && !EngFuncs::GetCvarFloat("cl_predict"))
	{
		uiMultiPlayer.AskPredictEnable();
	}
	else if (!UI::Names::CheckIsNameValid(EngFuncs::GetCvarString("name")))
	{
		UI_PlayerIntroduceDialog_Show(&uiMultiPlayer);
	}
}
ADD_MENU(menu_multiplayer, UI_MultiPlayer_Precache, UI_MultiPlayer_Menu);
