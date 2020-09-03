# struct extra_player_info_t

*Defined at line 321 of ./game/client/hud.h*

-----------------------------------------------------

 REMOVED: Vgui has replaced this.

class CHudScoreboard : public CHudBase{public:	int Init( void );	void InitHUDData( void );	int VidInit( void );	int Draw( float flTime );	int DrawPlayers( int xoffset, float listslot, int nameoffset = 0, char *team = NULL ); // returns the ypos where it finishes drawing	void UserCmd_ShowScores( void );	void UserCmd_HideScores( void );	int MsgFunc_ScoreInfo( const char *pszName, int iSize, void *pbuf );	int MsgFunc_TeamInfo( const char *pszName, int iSize, void *pbuf );	int MsgFunc_TeamScore( const char *pszName, int iSize, void *pbuf );	void DeathMsg( int killer, int victim );

	int m_iNumTeams;

	int m_iLastKilledBy;	int m_fLastKillTime;	int m_iPlayerNum;	int m_iShowscoresHeld;

	void GetAllPlayersInfo( void );

private:	struct cvar_s *cl_showpacketloss;};



## Members

public short frags

public short deaths

public short playerclass

public short teamnumber

public char [16] teamname



