# class CHudMenu

*Defined at line 368 of ./game/client/hud.h*

-----------------------------------------------------



Inherits from CHudBase



## Members

public int m_fMenuDisplayed

public int m_bitsValidSlots

public float m_flShutoffTime

public int m_fWaitingForMore



## Functions

### Init

*public int Init()*

*Defined at line 35 of ./game/client/menu.cpp*

### InitHUDData

*public void InitHUDData()*

*Defined at line 46 of ./game/client/menu.cpp*

### VidInit

*public int VidInit()*

*Defined at line 59 of ./game/client/menu.cpp*

### Reset

*public void Reset()*

*Defined at line 53 of ./game/client/menu.cpp*

### Draw

*public int Draw(float flTime)*

*Defined at line 64 of ./game/client/menu.cpp*

### MsgFunc_ShowMenu

*public int MsgFunc_ShowMenu(const char * pszName, int iSize, void * pbuf)*

*Defined at line 132 of ./game/client/menu.cpp*

 Message handler for ShowMenu message takes four values:		short: a bitfield of keys that are valid input		char : the duration, in seconds, the menu should stay up. -1 means is stays until something is chosen.		byte : a boolean, TRUE if there is more string yet to be received before displaying the menu, FALSE if it's the last string		string: menu string to display if this message is never received, then scores will simply be the combined totals of the players.

### SelectMenuItem

*public void SelectMenuItem(int menu_item)*

*Defined at line 110 of ./game/client/menu.cpp*

 selects an item from the menu



