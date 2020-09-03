# class CHudMessage

*Defined at line 493 of ./game/client/hud.h*

-----------------------------------------------------



Inherits from CHudBase



## Members

private client_textmessage_t *[16] m_pMessages

private float [16] m_startTime

message_parms_t m_parms

private float m_gameTitleTime

private client_textmessage_t * m_pGameTitle

private int m_HUD_title_life

private int m_HUD_title_half



## Functions

### Init

*public int Init()*

*Defined at line 35 of ./game/client/message.cpp*

### VidInit

*public int VidInit()*

*Defined at line 47 of ./game/client/message.cpp*

### Draw

*public int Draw(float flTime)*

*Defined at line 308 of ./game/client/message.cpp*

### MsgFunc_HudText

*public int MsgFunc_HudText(const char * pszName, int iSize, void * pbuf)*

*Defined at line 472 of ./game/client/message.cpp*

### MsgFunc_GameTitle

*public int MsgFunc_GameTitle(const char * pszName, int iSize, void * pbuf)*

*Defined at line 490 of ./game/client/message.cpp*

### FadeBlend

*public float FadeBlend(float fadein, float fadeout, float hold, float localTime)*

*Defined at line 64 of ./game/client/message.cpp*

### XPosition

*public int XPosition(float x, int width, int lineWidth)*

*Defined at line 90 of ./game/client/message.cpp*

### YPosition

*public int YPosition(float y, int height)*

*Defined at line 114 of ./game/client/message.cpp*

### MessageAdd

*public void MessageAdd(const char * pName, float time)*

*Defined at line 408 of ./game/client/message.cpp*

### MessageAdd

*public void MessageAdd(client_textmessage_t * newMessage)*

*Defined at line 505 of ./game/client/message.cpp*

### MessageDrawScan

*public void MessageDrawScan(client_textmessage_t * pMessage, float time)*

*Defined at line 239 of ./game/client/message.cpp*

### MessageScanStart

*public void MessageScanStart()*

*Defined at line 199 of ./game/client/message.cpp*

### MessageScanNextChar

*public void MessageScanNextChar()*

*Defined at line 137 of ./game/client/message.cpp*

### Reset

*public void Reset()*

*Defined at line 55 of ./game/client/message.cpp*



