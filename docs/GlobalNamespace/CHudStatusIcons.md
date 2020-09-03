# class CHudStatusIcons

*Defined at line 529 of ./game/client/hud.h*

Inherits from CHudBase



## Members

private CHudStatusIcons::icon_sprite_t [4] m_IconList



## Records

icon_sprite_t



## Functions

### Init

*public int Init()*

*Defined at line 32 of ./game/client/status_icons.cpp*

### VidInit

*public int VidInit()*

*Defined at line 43 of ./game/client/status_icons.cpp*

### Reset

*public void Reset()*

*Defined at line 48 of ./game/client/status_icons.cpp*

### Draw

*public int Draw(float flTime)*

*Defined at line 55 of ./game/client/status_icons.cpp*

 Draw status icons along the left-hand side of the screen

### MsgFunc_StatusIcon

*public int MsgFunc_StatusIcon(const char * pszName, int iSize, void * pbuf)*

*Defined at line 85 of ./game/client/status_icons.cpp*

 Message handler for StatusIcon message accepts five values:		byte   : TRUE = ENABLE icon, FALSE = DISABLE icon		string : the sprite name to display		byte   : red		byte   : green		byte   : blue

### EnableIcon

*public void EnableIcon(const char * pszIconName, unsigned char red, unsigned char green, unsigned char blue)*

*Defined at line 108 of ./game/client/status_icons.cpp*

 add the icon to the icon list, and set it's drawing color

had to make these public so CHud could access them (to enable concussion icon)could use a friend declaration instead...

### DisableIcon

*public void DisableIcon(const char * pszIconName)*

*Defined at line 153 of ./game/client/status_icons.cpp*



## Enums

| enum  |

--

| MAX_ICONSPRITENAME_LENGTH |
| MAX_ICONSPRITES |


*Defined at line 538 of ./game/client/hud.h*



