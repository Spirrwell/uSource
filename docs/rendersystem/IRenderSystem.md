# class IRenderSystem

*Defined at line 139 of ./rendersystem/rendersystem.h*

 You must implement this in your own backend 



## Functions

### Init

*public void Init(const struct rendersystem::render_params_t & params)*

### Shutdown

*public void Shutdown()*

### OnParamsChanged

*public void OnParamsChanged(const struct rendersystem::render_params_t & params)*

### CreateEmptyVertexBuffer

*public class rendersystem::IVertexBuffer * CreateEmptyVertexBuffer(enum rendersystem::EVertexFormat fmt, enum rendersystem::EBufferType type)*

### CreateEmptyIndexBuffer

*public class rendersystem::IIndexBuffer * CreateEmptyIndexBuffer(enum rendersystem::EIndexFormat fmt, enum rendersystem::EBufferType type)*

### CreateEmptyBuffer

*public class rendersystem::IBuffer * CreateEmptyBuffer(enum rendersystem::EBufferType type)*

### CreateEmptyTexture

*public class rendersystem::ITexture * CreateEmptyTexture(enum rendersystem::ETextureFormat fmt)*

### CreateTextureFromImage

*public class rendersystem::ITexture * CreateTextureFromImage(const void * img)*

 Creates a new image from the rgb data that has been specified 

 This won't be using the same buffers as the rgbdata, so you will want to call FreeImage on the rgbdata after this 

### CreateRenderTarget

*public class rendersystem::ITexture * CreateRenderTarget(const char * name, enum rendersystem::ETextureFormat fmt, int width, int height, int flags)*

 Creates a new render target which will reside in shared memory 

### CreateProgram

*public class rendersystem::IShaderProgram * CreateProgram(const char * name)*

 Creates a new shader program 

### CreateGeometryShader

*public class rendersystem::IGeomShader * CreateGeometryShader()*

 Creates new shaders 

### CreateVertexShader

*public class rendersystem::IVertexShader * CreateVertexShader()*

### CreateFragShader

*public class rendersystem::IFragShader * CreateFragShader()*

### CreateShaderProgram

*public class rendersystem::IShaderProgram * CreateShaderProgram(const char * name)*

### GetTriAPI

*public class ITriangleAPI * GetTriAPI()*

 API Accessors 

### SetDepthFunc

*public void SetDepthFunc(enum rendersystem::EShaderDepthFunc func)*

### SetBlendEquation

*public void SetBlendEquation(enum rendersystem::EShaderBlendEq func)*

### SetBlendFunc

*public void SetBlendFunc(enum rendersystem::EShaderBlendFunc func)*

### SetAlphaFunc

*public void SetAlphaFunc(enum rendersystem::EShaderAlphaFunc func)*

### SetStencilFunc

*public void SetStencilFunc(enum rendersystem::EShaderStencilFunc func)*

### SetStencilOp

*public void SetStencilOp(enum rendersystem::EShaderStencilOp op)*



