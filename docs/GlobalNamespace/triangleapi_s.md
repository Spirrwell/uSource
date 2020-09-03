# struct triangleapi_s

*Defined at line 36 of ./common/triangleapi.h*

## Members

public int version

public void (*)(int) RenderMode

public void (*)(int) Begin

public void (*)(void) End

public void (*)(float, float, float, float) Color4f

public void (*)(unsigned char, unsigned char, unsigned char, unsigned char) Color4ub

public void (*)(float, float) TexCoord2f

public void (*)(const float *) Vertex3fv

public void (*)(float, float, float) Vertex3f

public void (*)(float) Brightness

public void (*)(TRICULLSTYLE) CullFace

public int (*)(struct model_s *, int) SpriteTexture

public int (*)(const float *, float *) WorldToScreen

public void (*)(float *, float, float, int) Fog

public void (*)(const float *, float *) ScreenToWorld

public void (*)(const int, float *) GetMatrix

public int (*)(float *, float *) BoxInPVS

public void (*)(float *, float *) LightAtPoint

public void (*)(float, float, float, float, int) Color4fRendermode

public void (*)(float, int) FogParams



