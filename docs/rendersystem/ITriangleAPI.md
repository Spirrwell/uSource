# class ITriangleAPI

*Defined at line 17 of ./rendersystem/itriapi.h*

## Functions

### RenderMode

*public void RenderMode(int mode)*

### Begin

*public void Begin(int mode)*

### End

*public void End()*

### TexCoord2f

*public void TexCoord2f(float u, float v)*

### Vertex3fv

*public void Vertex3fv(const float * v)*

### Vertex3f

*public void Vertex3f(float x, float y, float z)*

### Color4f

*public void Color4f(float r, float g, float b, float a)*

### Color4ub

*public void Color4ub(byte r, byte g, byte b, byte a)*

### Brightness

*public void Brightness(float brightness)*

### WorldToScreen

*public int WorldToScreen(const float * world, float * screen)*

### SpriteTexture

*public int SpriteTexture(model_t * pSpriteModel, int frame)*

### Fog

*public void Fog(float [3] flFogColor, float flStart, float flEnd, int bOn)*

### GetMatrix

*public void GetMatrix(const int pname, float * matrix)*

### FogParams

*public void FogParams(float flDensity, int iFogSkybox)*

### CullFace

*public void CullFace(TRICULLSTYLE mode)*



