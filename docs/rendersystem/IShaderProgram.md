# class IShaderProgram

*Defined at line 128 of ./rendersystem/ishader.h*

 Roughly corresponds to OpenGL's program objects. This is basically a pipeline in practice. You bind shaders to individual slots here and then bind the program object to a mesh for rendering.



## Functions

### GetName

*public const char * GetName()*

 The program will be referenced by this name 

### BindVertexShader

*public void BindVertexShader(class rendersystem::IVertexShader * pShader)*

### BindFragShader

*public void BindFragShader(class rendersystem::IFragShader * pShader)*

### BindGeometryShader

*public void BindGeometryShader(class rendersystem::IGeomShader * pShader)*

### UnbindVertexShader

*public void UnbindVertexShader()*

### UnbindFragShader

*public void UnbindFragShader()*

### UnbindGeometryShader

*public void UnbindGeometryShader()*

### Link

*public _Bool Link()*

 Links the shaders together. This is another thing basically ripped from Gl. 

### SetupParams

*public void SetupParams(const char ** params, size_t length)*

 Resolves shader parameters in the GLSL 

### SetupUniforms

*public void SetupUniforms(const char ** params, size_t length)*

### SetupOutputs

*public void SetupOutputs(const char ** outputs, size_t length)*

### SetupTextureUniforms

*public void SetupTextureUniforms(const char ** outputs, size_t length)*

### AddRenderTarget

*public void AddRenderTarget(const char * param, int & index, class rendersystem::ITexture * pTexture)*

 Adds a fragment shader output, aka render target 

 param should corrsepond to the output param's name 

 Index should line up with the output layout in the shader. If index is -1, we will assign one 

### ClearRenderTargets

*public void ClearRenderTargets()*

### PreDraw

*public void PreDraw()*

 Pre-draw event. Do all setup here 

### PostDraw

*public void PostDraw()*

 Post draw callback 

### GetInfoLog

*public const char * GetInfoLog()*

 Returns the info log if the operation failed 

### EnableDepthWrite

*public void EnableDepthWrite(_Bool b)*

### SetFloatParam

*public void SetFloatParam(const char * param, float f)*

 Lots of parameter setting functions here, oh well! 

### SetFloat2Param

*public void SetFloat2Param(const char * param, float [2] v)*

### SetFloat3Param

*public void SetFloat3Param(const char * param, float [3] v)*

### SetFloat4Param

*public void SetFloat4Param(const char * param, float [4] v)*

### SetDoubleParam

*public void SetDoubleParam(const char * param, double f)*

### SetDouble2Param

*public void SetDouble2Param(const char * param, double [2] v)*

### SetDouble3Param

*public void SetDouble3Param(const char * param, double [3] v)*

### SetDouble4Param

*public void SetDouble4Param(const char * param, double [4] v)*

### SetIntParam

*public void SetIntParam(const char * param, int f)*

### SetInt2Param

*public void SetInt2Param(const char * param, int [2] v)*

### SetInt3Param

*public void SetInt3Param(const char * param, int [3] v)*

### SetInt4Param

*public void SetInt4Param(const char * param, int [4] v)*

### SetShortParam

*public void SetShortParam(const char * param, short f)*

### SetShort2Param

*public void SetShort2Param(const char * param, short [2] v)*

### SetShort3Param

*public void SetShort3Param(const char * param, short [3] v)*

### SetShort4Param

*public void SetShort4Param(const char * param, short [4] v)*

### SetMat2x2Uniform

*public void SetMat2x2Uniform(const char * param, float [2][2] mat)*

 Uniform param setting 

### SetMat3x3Uniform

*public void SetMat3x3Uniform(const char * param, float [3][3] mat)*

### SetMat4x4Uniform

*public void SetMat4x4Uniform(const char * param, float [4][4] mat)*

### SetMat2x3Uniform

*public void SetMat2x3Uniform(const char * param, float [2][3] mat)*

### SetMat3x2Uniform

*public void SetMat3x2Uniform(const char * param, float [3][2] mat)*

### SetMat3x4Uniform

*public void SetMat3x4Uniform(const char * param, float [3][4] mat)*

### SetMat4x3Uniform

*public void SetMat4x3Uniform(const char * param, float [4][3] mat)*

### SetMat2x4Uniform

*public void SetMat2x4Uniform(const char * param, float [2][4] mat)*

### SetMat4x2Uniform

*public void SetMat4x2Uniform(const char * param, float [4][2] mat)*

### SetIntUniform

*public void SetIntUniform(const char * param, int f)*

### SetInt2Uniform

*public void SetInt2Uniform(const char * param, int [2] v)*

### SetInt3Uniform

*public void SetInt3Uniform(const char * param, int [3] v)*

### SetInt4Uniform

*public void SetInt4Uniform(const char * param, int [4] v)*

### SetFloatUniform

*public void SetFloatUniform(const char * param, float f)*

### SetFloat2Uniform

*public void SetFloat2Uniform(const char * param, float [2] v)*

### SetFloat3Uniform

*public void SetFloat3Uniform(const char * param, float [3] v)*

### SetFloat4Uniform

*public void SetFloat4Uniform(const char * param, float [4] v)*

### SetDoubleUniform

*public void SetDoubleUniform(const char * param, double d)*

### SetDouble2Uniform

*public void SetDouble2Uniform(const char * param, double [2] d)*

### SetDouble3Uniform

*public void SetDouble3Uniform(const char * param, double [3] d)*

### SetDouble4Uniform

*public void SetDouble4Uniform(const char * param, double [4] d)*

### SetTextureUniform

*public void SetTextureUniform(const char * param, class rendersystem::ITexture * pTex)*



