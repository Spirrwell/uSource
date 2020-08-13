/**
 *
 * OptionsMenu.cpp
 *
 * Updated options menu
 *
 */
#include "BaseItem.h"
#include "Framework.h"
#include "PicButton.h"
#include "TabView.h"

#include "tier1/concommand.h"

class COptionsMenu : public CMenuBaseWindow
{
public:
	COptionsMenu() : CMenuBaseWindow("Test"){};

	static void UI_Precache();
	static void UI_ShowOptionsMenu();

protected:
	void _Init() override;
	void _VidInit() override;

	CMenuPicButton testbtn;
	CMenuTabView   tabview;
};

static COptionsMenu uiOptionsMenu;

void COptionsMenu::_Init()
{
	this->SetSize(200, 200);
	this->SetCoord(200, 200);
	this->SetStrokeColor(255, 0, 0, 255);
	this->background.SetStrokeColor(0, 255, 0, 255);
	this->background.bForceColor = true;
	this->background.bDrawStroke = true;
}

void COptionsMenu::_VidInit() { this->background.Show(); }

void COptionsMenu::UI_Precache() {}

void COptionsMenu::UI_ShowOptionsMenu() { uiOptionsMenu.Show(); }

CONCOMMAND(ShowNewOptionsMenu, "", 0) { uiOptionsMenu.Show(); }

ADD_MENU(menu_options_main, COptionsMenu::UI_Precache, COptionsMenu::UI_ShowOptionsMenu);
