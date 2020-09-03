# class CHudSayText

*Defined at line 389 of ./game/client/hud.h*

-----------------------------------------------------



Inherits from CHudBase



## Members

private struct cvar_s * m_HUD_saytext

private struct cvar_s * m_HUD_saytext_time



## Functions

### Init

*public int Init()*

*Defined at line 48 of ./game/client/saytext.cpp*

### InitHUDData

*public void InitHUDData()*

*Defined at line 64 of ./game/client/saytext.cpp*

### VidInit

*public int VidInit()*

*Defined at line 71 of ./game/client/saytext.cpp*

### Draw

*public int Draw(float flTime)*

*Defined at line 94 of ./game/client/saytext.cpp*

### MsgFunc_SayText

*public int MsgFunc_SayText(const char * pszName, int iSize, void * pbuf)*

*Defined at line 150 of ./game/client/saytext.cpp*

### SayTextPrint

*public void SayTextPrint(const char * pszBuf, int iBufSize, int clientIndex)*

*Defined at line 160 of ./game/client/saytext.cpp*

### EnsureTextFitsInOneLineAndWrapIfHaveTo

*public void EnsureTextFitsInOneLineAndWrapIfHaveTo(int line)*

*Defined at line 220 of ./game/client/saytext.cpp*



