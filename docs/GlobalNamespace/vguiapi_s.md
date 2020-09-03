# struct vguiapi_s

*Defined at line 184 of ./engine/vgui_int.h*

## Members

public qboolean initialized

public void (*)(void) DrawInit

public void (*)(void) DrawShutdown

public void (*)(int *) SetupDrawingText

public void (*)(int *) SetupDrawingRect

public void (*)(int *) SetupDrawingImage

public void (*)(int) BindTexture

public void (*)(qboolean) EnableTexture

public void (*)(int, int, int) CreateTexture

public void (*)(int, const char *, int, int) UploadTexture

public void (*)(int, int, int, const byte *, int, int) UploadTextureBlock

public void (*)(const vpoint_t *, const vpoint_t *) DrawQuad

public void (*)(int *, int *) GetTextureSizes

public int (*)(void) GenerateTexture

public void *(*)(size_t) EngineMalloc

public void (*)(enum VGUI_DefaultCursor) CursorSelect

public byte (*)(int, int) GetColor

public qboolean (*)(void) IsInGame

public void (*)(qboolean) SetVisible

public void (*)(int *, int *) GetCursorPos

public int (*)(int) ProcessUtfChar

public void (*)(int, int) Startup

public void (*)(void) Shutdown

public void *(*)(void) GetPanel

public void (*)(void) Paint

public void (*)(enum VGUI_MouseAction, int) Mouse

public void (*)(enum VGUI_KeyAction, enum VGUI_KeyCode) Key

public void (*)(int, int) MouseMove



