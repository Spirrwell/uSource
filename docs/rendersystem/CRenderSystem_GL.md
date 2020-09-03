# class CRenderSystem_GL

*Defined at line 13 of ./rendersystem/rendersystemgl/rendersystemgl.h*

Inherits from IRenderSystem



## Functions

### Init

*public void Init(const struct rendersystem::render_params_t & params)*

*Defined at line 17 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

### Shutdown

*public void Shutdown()*

*Defined at line 41 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

### OnParamsChanged

*public void OnParamsChanged(const struct rendersystem::render_params_t & params)*

*Defined at line 54 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

### CreateEmptyVertexBuffer

*public class rendersystem::IVertexBuffer * CreateEmptyVertexBuffer(enum rendersystem::EVertexFormat fmt, enum rendersystem::EBufferType type)*

*Defined at line 59 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

### CreateEmptyIndexBuffer

*public class rendersystem::IIndexBuffer * CreateEmptyIndexBuffer(enum rendersystem::EIndexFormat fmt, enum rendersystem::EBufferType type)*

*Defined at line 64 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

### CreateEmptyBuffer

*public class rendersystem::IBuffer * CreateEmptyBuffer(enum rendersystem::EBufferType type)*

*Defined at line 69 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

### CreateEmptyTexture

*public class rendersystem::ITexture * CreateEmptyTexture(enum rendersystem::ETextureFormat fmt)*

*Defined at line 74 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

### CreateTextureFromImage

*public class rendersystem::ITexture * CreateTextureFromImage(const void * img)*

*Defined at line 79 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

 Creates a new image from the rgb data that has been specified 

 This won't be using the same buffers as the rgbdata, so you will want to call FreeImage on the rgbdata after this 

### CreateRenderTarget

*public class rendersystem::ITexture * CreateRenderTarget(const char * name, enum rendersystem::ETextureFormat fmt, int width, int height, int flags)*

*Defined at line 84 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

 Creates a new render target which will reside in shared memory 

### CreateProgram

*public class rendersystem::IShaderProgram * CreateProgram(const char * name)*

*Defined at line 34 of ./rendersystem/rendersystemgl/rendersystemgl.h*

 Creates a new shader program 

### CreateGeometryShader

*public class rendersystem::IGeomShader * CreateGeometryShader()*

*Defined at line 89 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

 Creates new shaders 

### CreateVertexShader

*public class rendersystem::IVertexShader * CreateVertexShader()*

*Defined at line 94 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

### CreateFragShader

*public class rendersystem::IFragShader * CreateFragShader()*

*Defined at line 99 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

### CreateShaderProgram

*public class rendersystem::IShaderProgram * CreateShaderProgram(const char * name)*

*Defined at line 313 of ./rendersystem/rendersystemgl/gl_shader.cpp*

=============================================================================================================================================// CShaderProgram_GL

### GetTriAPI

*public class ITriangleAPI * GetTriAPI()*

*Defined at line 246 of ./rendersystem/rendersystemgl/gl_triapi.cpp*

 API Accessors 

### SetDepthFunc

*public void SetDepthFunc(enum rendersystem::EShaderDepthFunc func)*

*Defined at line 104 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

### SetBlendEquation

*public void SetBlendEquation(enum rendersystem::EShaderBlendEq func)*

*Defined at line 109 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

### SetBlendFunc

*public void SetBlendFunc(enum rendersystem::EShaderBlendFunc func)*

*Defined at line 114 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

### SetAlphaFunc

*public void SetAlphaFunc(enum rendersystem::EShaderAlphaFunc func)*

*Defined at line 119 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

### SetStencilFunc

*public void SetStencilFunc(enum rendersystem::EShaderStencilFunc func)*

*Defined at line 124 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

### SetStencilOp

*public void SetStencilOp(enum rendersystem::EShaderStencilOp op)*

*Defined at line 129 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*



