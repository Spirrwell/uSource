# class CShaderProgram_GL

*Defined at line 100 of ./rendersystem/rendersystemgl/gl_shader.cpp*

Inherits from IShaderProgram



## Members

public class rendersystem::CFragShader_GL * m_fragShader

public class rendersystem::CVertexShader_GL * m_vertShader

public class rendersystem::CGeomShader_GL * m_geomShader

public GLint m_programIndex

public GLint m_maxRenderTargets

public char * m_name

public _Bool m_linked

public _Bool m_depth

public _Bool m_stencil

public GLint m_currentColorBuffer

public rendertarget_t m_depthTarget

public rendertarget_t m_stencilTarget

List m_renderTargets

Array m_shaderParams

Array m_shaderOutputs

Array m_shaderUniforms

Array m_shaderTextures



## Records

rendertarget_t

shader_params_t

texture_uniform_t



## Functions

### FindParamIndex

*public GLint FindParamIndex(const char * s)*

*Defined at line 349 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### FindOutputIndex

*public GLint FindOutputIndex(const char * s)*

*Defined at line 339 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### FindUniformIndex

*public GLint FindUniformIndex(const char * s)*

*Defined at line 359 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### FindTexParam

*public texture_uniform_t FindTexParam(const char * s)*

*Defined at line 369 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### CShaderProgram_GL

*public void CShaderProgram_GL(const char * m_name)*

*Defined at line 318 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### ~CShaderProgram_GL

*public void ~CShaderProgram_GL()*

*Defined at line 333 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### GetName

*public const char * GetName()*

*Defined at line 389 of ./rendersystem/rendersystemgl/gl_shader.cpp*

 The program will be referenced by this name 

### BindVertexShader

*public void BindVertexShader(class rendersystem::IVertexShader * pShader)*

*Defined at line 394 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### BindFragShader

*public void BindFragShader(class rendersystem::IFragShader * pShader)*

*Defined at line 399 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### BindGeometryShader

*public void BindGeometryShader(class rendersystem::IGeomShader * pShader)*

*Defined at line 404 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### UnbindVertexShader

*public void UnbindVertexShader()*

*Defined at line 409 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### UnbindFragShader

*public void UnbindFragShader()*

*Defined at line 417 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### UnbindGeometryShader

*public void UnbindGeometryShader()*

*Defined at line 425 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### Link

*public _Bool Link()*

*Defined at line 433 of ./rendersystem/rendersystemgl/gl_shader.cpp*

 Links the shaders together. This is another thing basically ripped from Gl. 

### GetInfoLog

*public const char * GetInfoLog()*

*Defined at line 529 of ./rendersystem/rendersystemgl/gl_shader.cpp*

 Returns the info log if the operation failed 

### SetupParams

*public void SetupParams(const char ** params, size_t length)*

*Defined at line 454 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetupOutputs

*public void SetupOutputs(const char ** outputs, size_t length)*

*Defined at line 442 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetupUniforms

*public void SetupUniforms(const char ** outputs, size_t length)*

*Defined at line 864 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetupTextureUniforms

*public void SetupTextureUniforms(const char ** uniforms, size_t length)*

*Defined at line 877 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### AddRenderTarget

*public void AddRenderTarget(const char * param, int & index, class rendersystem::ITexture * pTexture)*

*Defined at line 479 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### ClearRenderTargets

*public void ClearRenderTargets()*

*Defined at line 466 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### PostDraw

*public void PostDraw()*

*Defined at line 537 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### PreDraw

*public void PreDraw()*

*Defined at line 542 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### EnableDepthWrite

*public void EnableDepthWrite(_Bool enable)*

*Defined at line 474 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### CheckParamType

*public _Bool CheckParamType(GLint param, GLenum type)*

*Defined at line 379 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### CheckUniformType

*public _Bool CheckUniformType(GLint param, GLenum type)*

*Defined at line 384 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetFloatParam

*public void SetFloatParam(const char * param, float f)*

*Defined at line 557 of ./rendersystem/rendersystemgl/gl_shader.cpp*

 Lots of parameter setting functions here, oh well! 

### SetFloat2Param

*public void SetFloat2Param(const char * param, float [2] v)*

*Defined at line 564 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetFloat3Param

*public void SetFloat3Param(const char * param, float [3] v)*

*Defined at line 571 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetFloat4Param

*public void SetFloat4Param(const char * param, float [4] v)*

*Defined at line 578 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetDoubleParam

*public void SetDoubleParam(const char * param, double f)*

*Defined at line 585 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetDouble2Param

*public void SetDouble2Param(const char * param, double [2] v)*

*Defined at line 592 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetDouble3Param

*public void SetDouble3Param(const char * param, double [3] v)*

*Defined at line 599 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetDouble4Param

*public void SetDouble4Param(const char * param, double [4] v)*

*Defined at line 606 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetIntParam

*public void SetIntParam(const char * param, int f)*

*Defined at line 613 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetInt2Param

*public void SetInt2Param(const char * param, int [2] v)*

*Defined at line 620 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetInt3Param

*public void SetInt3Param(const char * param, int [3] v)*

*Defined at line 627 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetInt4Param

*public void SetInt4Param(const char * param, int [4] v)*

*Defined at line 634 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetShortParam

*public void SetShortParam(const char * param, short f)*

*Defined at line 641 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetShort2Param

*public void SetShort2Param(const char * param, short [2] v)*

*Defined at line 648 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetShort3Param

*public void SetShort3Param(const char * param, short [3] v)*

*Defined at line 655 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetShort4Param

*public void SetShort4Param(const char * param, short [4] v)*

*Defined at line 662 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetMat2x2Uniform

*public void SetMat2x2Uniform(const char * param, float [2][2] mat)*

*Defined at line 669 of ./rendersystem/rendersystemgl/gl_shader.cpp*

 Uniform param setting 

### SetMat3x3Uniform

*public void SetMat3x3Uniform(const char * param, float [3][3] mat)*

*Defined at line 676 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetMat4x4Uniform

*public void SetMat4x4Uniform(const char * param, float [4][4] mat)*

*Defined at line 683 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetMat2x3Uniform

*public void SetMat2x3Uniform(const char * param, float [2][3] mat)*

*Defined at line 690 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetMat3x2Uniform

*public void SetMat3x2Uniform(const char * param, float [3][2] mat)*

*Defined at line 697 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetMat3x4Uniform

*public void SetMat3x4Uniform(const char * param, float [3][4] mat)*

*Defined at line 704 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetMat4x3Uniform

*public void SetMat4x3Uniform(const char * param, float [4][3] mat)*

*Defined at line 711 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetMat2x4Uniform

*public void SetMat2x4Uniform(const char * param, float [2][4] mat)*

*Defined at line 718 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetMat4x2Uniform

*public void SetMat4x2Uniform(const char * param, float [4][2] mat)*

*Defined at line 725 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetIntUniform

*public void SetIntUniform(const char * param, int f)*

*Defined at line 732 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetInt2Uniform

*public void SetInt2Uniform(const char * param, int [2] v)*

*Defined at line 739 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetInt3Uniform

*public void SetInt3Uniform(const char * param, int [3] v)*

*Defined at line 746 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetInt4Uniform

*public void SetInt4Uniform(const char * param, int [4] v)*

*Defined at line 753 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetFloatUniform

*public void SetFloatUniform(const char * param, float f)*

*Defined at line 760 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetFloat2Uniform

*public void SetFloat2Uniform(const char * param, float [2] v)*

*Defined at line 767 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetFloat3Uniform

*public void SetFloat3Uniform(const char * param, float [3] v)*

*Defined at line 774 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetFloat4Uniform

*public void SetFloat4Uniform(const char * param, float [4] v)*

*Defined at line 781 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetDoubleUniform

*public void SetDoubleUniform(const char * param, double d)*

*Defined at line 788 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetDouble2Uniform

*public void SetDouble2Uniform(const char * param, double [2] d)*

*Defined at line 795 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetDouble3Uniform

*public void SetDouble3Uniform(const char * param, double [3] d)*

*Defined at line 802 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetDouble4Uniform

*public void SetDouble4Uniform(const char * param, double [4] d)*

*Defined at line 809 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### SetTextureUniform

*public void SetTextureUniform(const char * param, class rendersystem::ITexture * pTex)*

*Defined at line 816 of ./rendersystem/rendersystemgl/gl_shader.cpp*



