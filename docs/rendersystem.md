# namespace rendersystem



## Namespaces

GL



## Records

CBufferFormatType

CBufferFormatT

IBufferFormat

CBufferFormat

CBufferAccessor

IBuffer

IVertexBuffer

IIndexBuffer

IMesh

IShaderProgram

ITexture

material_param_t

IMaterial

shader_param_t

IShader

IVertexShader

IFragShader

IGeomShader

IComputeShader

IShaderShadow

render_params_t

IRenderSystem

ITriangleAPI

CTexture

CMaterial

CRenderSystem_GL

CTriangleAPI_GL



CTexture_GL

CGenericShader_GL

CVertexShader_GL

CFragShader_GL

CGeomShader_GL

CShaderProgram_GL



## Functions

### GetFormatSize

*unsigned long long GetFormatSize(enum rendersystem::ETextureFormat fmt)*

*Defined at line 186 of ./rendersystem/imaterial.h*

 Returns the size of one pixel of the specified format 

### CreateRenderSystem

*class rendersystem::IRenderSystem * CreateRenderSystem()*

*Defined at line 12 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

 This is the only function you must implement within your backend implementation 

 Internally you'll need to implement the Ixxxx classes, but those implementations should not be exposed 

### GetParam

*unsigned int GetParam(unsigned long param)*

*Defined at line 46 of ./rendersystem/rendersystemgl/rendersystemgl.cpp*

### GetGLTexFormat

*void GetGLTexFormat(enum rendersystem::ETextureFormat fmt, GLenum & outfmt, GLenum & outpixdat)*

*Defined at line 20 of ./rendersystem/rendersystemgl/gl_material.cpp*

### GetGLOutputTexFormat

*void GetGLOutputTexFormat(enum rendersystem::ETextureFormat fmt, GLenum & outfmt, GLenum & outpixdat)*

*Defined at line 42 of ./rendersystem/rendersystemgl/gl_material.cpp*



## Enums

| enum class EBufferType |

--

| HOST |
| SHARED |
| CLIENT |


*Defined at line 13 of ./rendersystem/ibuffer.h*

 Defines the type of buffer 

| enum class EBufferFormatType |

--

| VEC2F |
| VEC3F |
| VEC4F |
| VEC2D |
| VEC3D |
| VEC4D |
| I8 |
| I16 |
| I32 |
| I64 |
| U8 |
| U16 |
| U32 |
| U64 |
| F16 |
| F32 |
| F64 |
| F80 |
| MAT2 |
| MAT3 |
| MAT4 |
| OTHER |


*Defined at line 21 of ./rendersystem/ibuffer.h*

 Various supported types by CBufferFormat 

| enum class EVertexFormat |

--

| INT2 |
| FLOAT2 |
| DOUBLE2 |
| INT3 |
| FLOAT3 |
| DOUBLE3 |
| INT4 |
| FLOAT4 |
| DOUBLE4 |


*Defined at line 248 of ./rendersystem/ibuffer.h*

Vertex formats are quite simple. They're intended to be tightly packed arrays of verticies for GL rendering

| enum class EIndexFormat |

--

| BYTE |
| SHORT |
| INT |


*Defined at line 261 of ./rendersystem/ibuffer.h*

| enum EMeshFlags |

--

| MESH_STATIC |
| MESH_DYNAMIC |


*Defined at line 9 of ./rendersystem/imesh.h*

| enum class ETextureFormat |

--

| RGB888 |
| RGB161616 |
| RGBA8888 |
| RGBA16161616 |
| GRAY16 |
| GRAY8 |
| DXT1 |
| DXT5 |
| ATI2N |
| ATI1N |


*Defined at line 7 of ./rendersystem/imaterial.h*

| enum ETextureFlags |

--

| TEXFLAGS_NONE |
| TEXFLAGS_RENDERBUFFER |
| TEXFLAGS_DEPTH |
| TEXFLAGS_STENCIL |
| TEXFLAGS_CUBEMAP |
| TEXFLAGS_CUBEMAP_POS_X |
| TEXFLAGS_CUBEMAP_NEG_X |
| TEXFLAGS_CUBEMAP_POS_Y |
| TEXFLAGS_CUBEMAP_NEG_Y |
| TEXFLAGS_CUBEMAP_POS_Z |
| TEXFLAGS_CUBEMAP_NEG_Z |


*Defined at line 21 of ./rendersystem/imaterial.h*

| enum class ETextureDimension |

--

| S |
| T |
| R |
| MAX_DIMENSIONS |


*Defined at line 36 of ./rendersystem/imaterial.h*

| enum class ETextureWrapFlags |

--

| WRAP_CLAMP_EDGE |
| WRAP_CLAMP_BORDER |
| WRAP_REPEAT |
| WRAP_MIRROR_REPEAT |
| MAX_WRAP_FLAGS |


*Defined at line 44 of ./rendersystem/imaterial.h*

| enum class ETextureFiltering |

--

| BILINEAR |
| TRILINEAR |


*Defined at line 53 of ./rendersystem/imaterial.h*

| enum class EMaterialParamType |

--

| FLOAT |
| INT |
| VEC3 |
| VEC2 |
| VEC4 |
| TEXTURE |


*Defined at line 143 of ./rendersystem/imaterial.h*

| enum class ESourceCodeType |

--

| GLSL |
| HLSL |
| SPIRV |
| FXC |


*Defined at line 21 of ./rendersystem/ishader.h*

| enum class EUniformType |

--

| MAT2 |
| MAT3 |
| MAT4 |
| MAT23 |
| MAT32 |
| MAT24 |
| MAT42 |
| MAT34 |
| MAT43 |
| FLOAT1 |
| FLOAT2 |
| FLOAT3 |
| FLOAT4 |
| INT1 |
| INT2 |
| INT3 |
| INT4 |
| MAX_UNIFORM_TYPE |


*Defined at line 30 of ./rendersystem/ishader.h*

 Uniform shader params 

| enum class EParamType |

--

| FLOAT1 |
| FLOAT2 |
| FLOAT3 |
| FLOAT4 |
| DOUBLE1 |
| DOUBLE2 |
| DOUBLE3 |
| DOUBLE4 |
| INT1 |
| INT2 |
| INT3 |
| INT4 |
| SHORT1 |
| SHORT2 |
| SHORT3 |
| SHORT4 |
| BYTE1 |
| BYTE2 |
| BYTE3 |
| BYTE4 |
| TEXTURE |
| MAX_PARAM_TYPE |


*Defined at line 53 of ./rendersystem/ishader.h*

 Non-uniform shader params 

| enum class ERenderDeviceFeatures |

--

| SUPPORTS_DYNAMIC_MESH |
| SUPPORTS_TESSELATION |
| SUPPORTS_GEOM_SHADERS |
| SUPPORTS_DXT5_COMPRESSION |
| SUPPORTS_DXT1_COMPRESSION |
| SUPPORTS_ATI2N_COMPRESSION |
| IS_FIXED_FUNCTION |


*Defined at line 33 of ./rendersystem/rendersystem.h*

 Enum containing features that can be supported by each individual render API

| enum class EShaderDepthFunc |

--

| NEVER |
| NEARER |
| EQUAL |
| NEAREROREQUAL |
| FARTHER |
| NOTEQUAL |
| FARTHEROREQUAL |
| ALWAYS |


*Defined at line 66 of ./rendersystem/rendersystem.h*

| enum class EShaderBlendFunc |

--

| ZERO |
| ONE |
| DST_COLOR |
| ONE_MINUS_DST_COLOR |
| SRC_ALPHA |
| ONE_MINUS_SRC_ALPHA |
| DST_ALPHA |
| ONE_MINUS_DST_ALPHA |
| SRC_ALPHA_SATURATE |
| SRC_COLOR |
| ONE_MINUS_SRC_COLOR |


*Defined at line 78 of ./rendersystem/rendersystem.h*

| enum class EShaderBlendEq |

--

| ADD |
| SUBTRACT |
| REVSUBTRACT |
| MIN |
| MAX |


*Defined at line 93 of ./rendersystem/rendersystem.h*

| enum class EShaderAlphaFunc |

--

| NEVER |
| LESS |
| EQUAL |
| LEQUAL |
| GREATER |
| NOTEQUAL |
| GEQUAL |
| ALWAYS |


*Defined at line 102 of ./rendersystem/rendersystem.h*

| enum class EShaderStencilFunc |

--

| NEVER |
| LESS |
| EQUAL |
| LEQUAL |
| GREATER |
| NOTEQUAL |
| GEQUAL |
| ALWAYS |


*Defined at line 114 of ./rendersystem/rendersystem.h*

| enum class EShaderStencilOp |

--

| KEEP |
| ZERO |
| SET_TO_REFERENCE |
| INCREMENT_CLAMP |
| DECREMENT_CLAMP |
| INVERT |
| INCREMENT_WRAP |
| DECREMENT_WRAP |


*Defined at line 126 of ./rendersystem/rendersystem.h*



