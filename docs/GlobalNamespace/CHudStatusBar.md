# class CHudStatusBar

*Defined at line 256 of ./game/client/hud.h*

-----------------------------------------------------



Inherits from CHudBase



## Members

protected char [2][128] m_szStatusText

protected char [2][128] m_szStatusBar

protected int [8] m_iStatusValues

protected int m_bReparseString

protected float *[2] m_pflNameColors



## Functions

### Init

*public int Init()*

*Defined at line 37 of ./game/client/statusbar.cpp*

### VidInit

*public int VidInit()*

*Defined at line 51 of ./game/client/statusbar.cpp*

### Draw

*public int Draw(float flTime)*

*Defined at line 174 of ./game/client/statusbar.cpp*

### Reset

*public void Reset()*

*Defined at line 57 of ./game/client/statusbar.cpp*

### ParseStatusString

*public void ParseStatusString(int line_num)*

*Defined at line 73 of ./game/client/statusbar.cpp*

### MsgFunc_StatusText

*public int MsgFunc_StatusText(const char * pszName, int iSize, void * pbuf)*

*Defined at line 225 of ./game/client/statusbar.cpp*

 Message handler for StatusText message accepts two values:		byte: line number of status bar text 		string: status bar text this string describes how the status bar should be drawn a semi-regular expression: ( slotnum ([a..z] [%pX] [%iX])*)* where slotnum is an index into the Value table (see below) if slotnum is 0, the string is always drawn if StatusValue[slotnum] != 0, the following string is drawn, upto the next newline - otherwise the text is skipped upto next newline %pX, where X is an integer, will substitute a player name here, getting the player index from StatusValue[X] %iX, where X is an integer, will substitute a number here, getting the number from StatusValue[X]

### MsgFunc_StatusValue

*public int MsgFunc_StatusValue(const char * pszName, int iSize, void * pbuf)*

*Defined at line 251 of ./game/client/statusbar.cpp*

 Message handler for StatusText message accepts two values:		byte: index into the status value array		short: value to store



## Enums

| enum  |

--

| MAX_STATUSTEXT_LENGTH |
| MAX_STATUSBAR_VALUES |
| MAX_STATUSBAR_LINES |


*Defined at line 269 of ./game/client/hud.h*



