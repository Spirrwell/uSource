# class EngFuncs

*Defined at line 25 of ./mainui/enginecallback_menu.h*

## Functions

### PIC_Load

*public HIMAGE PIC_Load(const char * szPicName, const byte * ucRawImage, long ulRawImageSize, long flags)*

*Defined at line 29 of ./mainui/enginecallback_menu.h*

 image handlers

### PIC_Load

*public HIMAGE PIC_Load(const char * szPicName, long flags)*

*Defined at line 31 of ./mainui/enginecallback_menu.h*

### PIC_Free

*public void PIC_Free(const char * szPicName)*

*Defined at line 33 of ./mainui/enginecallback_menu.h*

### PIC_Width

*public int PIC_Width(HIMAGE hPic)*

*Defined at line 35 of ./mainui/enginecallback_menu.h*

### PIC_Height

*public int PIC_Height(HIMAGE hPic)*

*Defined at line 37 of ./mainui/enginecallback_menu.h*

### PIC_Size

*public Size PIC_Size(HIMAGE hPic)*

*Defined at line 39 of ./mainui/enginecallback_menu.h*

### PIC_Set

*public void PIC_Set(HIMAGE hPic, int r, int g, int b, int a)*

*Defined at line 20 of ./mainui/EngineCallback.cpp*

### PIC_Draw

*public void PIC_Draw(int x, int y, int width, int height, const wrect_t * prc)*

*Defined at line 45 of ./mainui/enginecallback_menu.h*

### PIC_DrawHoles

*public void PIC_DrawHoles(int x, int y, int width, int height, const wrect_t * prc)*

*Defined at line 47 of ./mainui/enginecallback_menu.h*

### PIC_DrawTrans

*public void PIC_DrawTrans(int x, int y, int width, int height, const wrect_t * prc)*

*Defined at line 49 of ./mainui/enginecallback_menu.h*

### PIC_DrawAdditive

*public void PIC_DrawAdditive(int x, int y, int width, int height, const wrect_t * prc)*

*Defined at line 51 of ./mainui/enginecallback_menu.h*

### PIC_Draw

*public void PIC_Draw(int x, int y, const wrect_t * prc)*

*Defined at line 53 of ./mainui/enginecallback_menu.h*

### PIC_DrawHoles

*public void PIC_DrawHoles(int x, int y, const wrect_t * prc)*

*Defined at line 55 of ./mainui/enginecallback_menu.h*

### PIC_DrawTrans

*public void PIC_DrawTrans(int x, int y, const wrect_t * prc)*

*Defined at line 57 of ./mainui/enginecallback_menu.h*

### PIC_DrawAdditive

*public void PIC_DrawAdditive(int x, int y, const wrect_t * prc)*

*Defined at line 59 of ./mainui/enginecallback_menu.h*

### PIC_Draw

*public void PIC_Draw(Point p, Size s, const wrect_t * prc)*

*Defined at line 62 of ./mainui/enginecallback_menu.h*

### PIC_DrawHoles

*public void PIC_DrawHoles(Point p, Size s, const wrect_t * prc)*

*Defined at line 64 of ./mainui/enginecallback_menu.h*

### PIC_DrawTrans

*public void PIC_DrawTrans(Point p, Size s, const wrect_t * prc)*

*Defined at line 66 of ./mainui/enginecallback_menu.h*

### PIC_DrawAdditive

*public void PIC_DrawAdditive(Point p, Size s, const wrect_t * prc)*

*Defined at line 68 of ./mainui/enginecallback_menu.h*

### PIC_Draw

*public void PIC_Draw(Point p, const wrect_t * prc)*

*Defined at line 70 of ./mainui/enginecallback_menu.h*

### PIC_DrawHoles

*public void PIC_DrawHoles(Point p, const wrect_t * prc)*

*Defined at line 72 of ./mainui/enginecallback_menu.h*

### PIC_DrawAdditive

*public void PIC_DrawAdditive(Point p, const wrect_t * prc)*

*Defined at line 74 of ./mainui/enginecallback_menu.h*

### PIC_DrawTrans

*public void PIC_DrawTrans(Point p, const wrect_t * prc)*

*Defined at line 76 of ./mainui/enginecallback_menu.h*

### PIC_EnableScissor

*public void PIC_EnableScissor(int x, int y, int width, int height)*

*Defined at line 79 of ./mainui/enginecallback_menu.h*

### PIC_DisableScissor

*public void PIC_DisableScissor()*

*Defined at line 82 of ./mainui/enginecallback_menu.h*

### FillRGBA

*public void FillRGBA(int x, int y, int width, int height, int r, int g, int b, int a)*

*Defined at line 28 of ./mainui/EngineCallback.cpp*

 screen handlers

### CvarRegister

*public cvar_t * CvarRegister(const char * szName, const char * szValue, int flags)*

*Defined at line 89 of ./mainui/enginecallback_menu.h*

 cvar handlers

### GetCvarFloat

*public float GetCvarFloat(const char * szName)*

*Defined at line 92 of ./mainui/enginecallback_menu.h*

### GetCvarString

*public const char * GetCvarString(const char * szName)*

*Defined at line 94 of ./mainui/enginecallback_menu.h*

### CvarSetString

*public void CvarSetString(const char * szName, const char * szValue)*

*Defined at line 96 of ./mainui/enginecallback_menu.h*

### CvarSetValue

*public void CvarSetValue(const char * szName, float flValue)*

*Defined at line 98 of ./mainui/enginecallback_menu.h*

### Cmd_AddCommand

*public int Cmd_AddCommand(const char * cmd_name, void (void) function)*

*Defined at line 102 of ./mainui/enginecallback_menu.h*

 command handlers

### ClientCmd

*public void ClientCmd(int execute_now, const char * szCmdString)*

*Defined at line 104 of ./mainui/enginecallback_menu.h*

### Cmd_RemoveCommand

*public void Cmd_RemoveCommand(const char * cmd_name)*

*Defined at line 106 of ./mainui/enginecallback_menu.h*

### CmdArgc

*public int CmdArgc()*

*Defined at line 108 of ./mainui/enginecallback_menu.h*

### CmdArgv

*public const char * CmdArgv(int argi)*

*Defined at line 110 of ./mainui/enginecallback_menu.h*

### CmdArgs

*public const char * CmdArgs()*

*Defined at line 112 of ./mainui/enginecallback_menu.h*

### PlayLocalSound

*public void PlayLocalSound(const char * szSound)*

*Defined at line 116 of ./mainui/enginecallback_menu.h*

 sound handlers

### DrawLogo

*public void DrawLogo(const char * filename, float x, float y, float width, float height)*

*Defined at line 36 of ./mainui/EngineCallback.cpp*

 cinematic handlers

### PrecacheLogo

*public void PrecacheLogo(const char * filename)*

*Defined at line 121 of ./mainui/enginecallback_menu.h*

### GetLogoWidth

*public int GetLogoWidth()*

*Defined at line 123 of ./mainui/enginecallback_menu.h*

### GetLogoHeight

*public int GetLogoHeight()*

*Defined at line 125 of ./mainui/enginecallback_menu.h*

### GetLogoLength

*public float GetLogoLength()*

*Defined at line 127 of ./mainui/enginecallback_menu.h*

### DrawCharacter

*public void DrawCharacter(int x, int y, int width, int height, int ch, int ulRGBA, HIMAGE hFont)*

*Defined at line 45 of ./mainui/EngineCallback.cpp*

 text message system

### DrawConsoleString

*public int DrawConsoleString(int x, int y, const char * string)*

*Defined at line 57 of ./mainui/EngineCallback.cpp*

### DrawSetTextColor

*public void DrawSetTextColor(int r, int g, int b, int alpha)*

*Defined at line 52 of ./mainui/EngineCallback.cpp*

### ConsoleStringLen

*public void ConsoleStringLen(const char * string, int * length, int * height)*

*Defined at line 71 of ./mainui/EngineCallback.cpp*

### ConsoleCharacterHeight

*public int ConsoleCharacterHeight()*

*Defined at line 76 of ./mainui/EngineCallback.cpp*

### DrawConsoleString

*public int DrawConsoleString(Point coord, const char * string)*

*Defined at line 137 of ./mainui/enginecallback_menu.h*

### SetConsoleDefaultColor

*public void SetConsoleDefaultColor(int r, int g, int b)*

*Defined at line 140 of ./mainui/enginecallback_menu.h*

### GetPlayerModel

*public struct cl_entity_s * GetPlayerModel()*

*Defined at line 148 of ./mainui/enginecallback_menu.h*

 custom rendering (for playermodel preview)

### SetModel

*public void SetModel(struct cl_entity_s * ed, const char * path)*

*Defined at line 150 of ./mainui/enginecallback_menu.h*

### ClearScene

*public void ClearScene()*

*Defined at line 152 of ./mainui/enginecallback_menu.h*

### RenderScene

*public void RenderScene(const struct ref_viewpass_s * fd)*

*Defined at line 154 of ./mainui/enginecallback_menu.h*

### CL_CreateVisibleEntity

*public int CL_CreateVisibleEntity(int type, struct cl_entity_s * ent)*

*Defined at line 156 of ./mainui/enginecallback_menu.h*

### FileExists

*public int FileExists(const char * filename, int gamedironly)*

*Defined at line 161 of ./mainui/enginecallback_menu.h*

 misc handlers static inline void	HostError( const char *szFmt, ... );

### GetGameDir

*public void GetGameDir(char * szGetGameDir)*

*Defined at line 163 of ./mainui/enginecallback_menu.h*

### CreateMapsList

*public int CreateMapsList(int iRefresh)*

*Defined at line 167 of ./mainui/enginecallback_menu.h*

 gameinfo handlers

### ClientInGame

*public int ClientInGame()*

*Defined at line 169 of ./mainui/enginecallback_menu.h*

### ClientJoin

*public void ClientJoin(netadr_s adr)*

*Defined at line 171 of ./mainui/enginecallback_menu.h*

### COM_LoadFile

*public byte * COM_LoadFile(const char * filename, int * pLength)*

*Defined at line 175 of ./mainui/enginecallback_menu.h*

 parse txt files

### COM_ParseFile

*public char * COM_ParseFile(char * data, char * token)*

*Defined at line 177 of ./mainui/enginecallback_menu.h*

### COM_FreeFile

*public void COM_FreeFile(void * buffer)*

*Defined at line 179 of ./mainui/enginecallback_menu.h*

### KEY_ClearStates

*public void KEY_ClearStates()*

*Defined at line 183 of ./mainui/enginecallback_menu.h*

 keyfuncs

### KEY_SetDest

*public void KEY_SetDest(int dest)*

*Defined at line 185 of ./mainui/enginecallback_menu.h*

### KeynumToString

*public const char * KeynumToString(int keynum)*

*Defined at line 187 of ./mainui/enginecallback_menu.h*

### KEY_GetBinding

*public const char * KEY_GetBinding(int keynum)*

*Defined at line 189 of ./mainui/enginecallback_menu.h*

### KEY_SetBinding

*public void KEY_SetBinding(int keynum, const char * binding)*

*Defined at line 191 of ./mainui/enginecallback_menu.h*

### KEY_IsDown

*public int KEY_IsDown(int keynum)*

*Defined at line 193 of ./mainui/enginecallback_menu.h*

### KEY_GetOverstrike

*public int KEY_GetOverstrike()*

*Defined at line 195 of ./mainui/enginecallback_menu.h*

### KEY_SetOverstrike

*public void KEY_SetOverstrike(int fActive)*

*Defined at line 198 of ./mainui/enginecallback_menu.h*

### KEY_GetState

*public void * KEY_GetState(const char * name)*

*Defined at line 200 of ./mainui/enginecallback_menu.h*

### MemAlloc

*public void * MemAlloc(size_t cb, const char * filename, const int fileline)*

*Defined at line 204 of ./mainui/enginecallback_menu.h*

 engine memory manager

### MemFree

*public void MemFree(void * mem, const char * filename, const int fileline)*

*Defined at line 206 of ./mainui/enginecallback_menu.h*

### GetGameInfo

*public int GetGameInfo(GAMEINFO * pgameinfo)*

*Defined at line 210 of ./mainui/enginecallback_menu.h*

 collect info from engine

### GetGamesList

*public GAMEINFO ** GetGamesList(int * numGames)*

*Defined at line 212 of ./mainui/enginecallback_menu.h*

### GetFilesList

*public char ** GetFilesList(const char * pattern, int * numFiles, int gamedironly)*

*Defined at line 214 of ./mainui/enginecallback_menu.h*

### GetSaveComment

*public int GetSaveComment(const char * savename, char * comment)*

*Defined at line 216 of ./mainui/enginecallback_menu.h*

### GetDemoComment

*public int GetDemoComment(const char * demoname, char * comment)*

*Defined at line 218 of ./mainui/enginecallback_menu.h*

### CheckGameDll

*public int CheckGameDll()*

*Defined at line 220 of ./mainui/enginecallback_menu.h*

### GetClipboardData

*public char * GetClipboardData()*

*Defined at line 222 of ./mainui/enginecallback_menu.h*

### ShellExecute

*public void ShellExecute(const char * name, const char * args, int closeEngine)*

*Defined at line 226 of ./mainui/enginecallback_menu.h*

 engine launcher

### WriteServerConfig

*public void WriteServerConfig(const char * name)*

*Defined at line 228 of ./mainui/enginecallback_menu.h*

### ChangeInstance

*public void ChangeInstance(const char * newInstance, const char * szFinalMessage)*

*Defined at line 230 of ./mainui/enginecallback_menu.h*

### PlayBackgroundTrack

*public void PlayBackgroundTrack(const char * introName, const char * loopName)*

*Defined at line 232 of ./mainui/enginecallback_menu.h*

### StopBackgroundTrack

*public void StopBackgroundTrack()*

*Defined at line 234 of ./mainui/enginecallback_menu.h*

### HostEndGame

*public void HostEndGame(const char * szFinalMessage)*

*Defined at line 236 of ./mainui/enginecallback_menu.h*

### RandomFloat

*public float RandomFloat(float flLow, float flHigh)*

*Defined at line 241 of ./mainui/enginecallback_menu.h*

 menu interface is freezed at version 0.75 new functions starts here

### RandomLong

*public int RandomLong(int lLow, int lHigh)*

*Defined at line 243 of ./mainui/enginecallback_menu.h*

### SetCursor

*public void SetCursor(void * hCursor)*

*Defined at line 246 of ./mainui/enginecallback_menu.h*

### IsMapValid

*public int IsMapValid(const char * filename)*

*Defined at line 248 of ./mainui/enginecallback_menu.h*

### ProcessImage

*public void ProcessImage(int texnum, float gamma, int topColor, int bottomColor)*

*Defined at line 250 of ./mainui/enginecallback_menu.h*

### CompareFileTime

*public int CompareFileTime(char * filename1, char * filename2, int * iCompare)*

*Defined at line 252 of ./mainui/enginecallback_menu.h*

### GetModeString

*public const char * GetModeString(int mode)*

*Defined at line 254 of ./mainui/enginecallback_menu.h*

### COM_SaveFile

*public int COM_SaveFile(const char * filename, const void * buffer, int len)*

*Defined at line 256 of ./mainui/enginecallback_menu.h*

### DeleteFile

*public int DeleteFile(const char * filename)*

*Defined at line 258 of ./mainui/enginecallback_menu.h*

### EnableTextInput

*public void EnableTextInput(int enable)*

*Defined at line 264 of ./mainui/enginecallback_menu.h*

### UtfProcessChar

*public int UtfProcessChar(int ch)*

*Defined at line 82 of ./mainui/EngineCallback.cpp*

 We have full unicode support now

### UtfMoveLeft

*public int UtfMoveLeft(const char * str, int pos)*

*Defined at line 87 of ./mainui/EngineCallback.cpp*

### UtfMoveRight

*public int UtfMoveRight(const char * str, int pos, int length)*

*Defined at line 92 of ./mainui/EngineCallback.cpp*

### GetRenderers

*public _Bool GetRenderers(int num, char * sz1, size_t s1, char * sz2, size_t s2)*

*Defined at line 271 of ./mainui/enginecallback_menu.h*



