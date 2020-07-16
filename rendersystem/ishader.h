/**
 * 
 * ishader.h
 * 
 * Basic definitions for an extensible shader framework
 * 
 */ 
#pragma once 

#include "ibuffer.h"
#include "imaterial.h"

struct shader_param_t 
{
	char* name;
	int index;
};

enum class ESourceCodeType
{
	GLSL = 0,
	HLSL,
	SPIRV,
	FXC,		/* FXC (directx) bytecode */
};

/* Uniform shader params */
enum class EUniformType
{
	MAT2 = 0,       /* 2x2 */
	MAT3,           /* 3x3 */
	MAT4,           /* 4x4 */
	MAT23,
	MAT32,
	MAT24,
	MAT42,
	MAT34,
	MAT43,
	FLOAT1,         /* Scalar float */
	FLOAT2,         /* vec2f */
	FLOAT3,
	FLOAT4,
	INT1,           /* Scalar int */
	INT2,           /* vec2i */
	INT3,
	INT4,
	MAX_UNIFORM_TYPE,
};

/* Non-uniform shader params */
enum class EParamType
{
	FLOAT1 = 0, /* Scalar float */
	FLOAT2, /* vec2f */
	FLOAT3,
	FLOAT4,
	DOUBLE1,
	DOUBLE2,
	DOUBLE3,
	DOUBLE4,
	INT1,
	INT2,
	INT3,
	INT4,
	SHORT1,
	SHORT2,
	SHORT3,
	SHORT4,
	BYTE1,
	BYTE2,
	BYTE3,
	BYTE4,
	TEXTURE,
	MAX_PARAM_TYPE
};



/**
 * This is the base class for all shaders. 
 * Note that this is pretty similar to OpenGL's shader pipeline. APIs that use pre-compiled bytecode, 
 * such as Vulkan and DirectX will basically just stub out Compile().
 * SetSourceCode should still be implemented as the rendersystem will still pass it a buffer containing the
 * bytecode. 
 */ 
class IShader
{
public:

	/* For binary code, pbuf will just be raw bytes. if the code type is GLSL, it's gonna be GLSL */
	virtual void SetSourceCode(void* pbuf, size_t buflen, ESourceCodeType type = ESourceCodeType::GLSL) = 0;

	/* For binary code, compilation is not always required. You can optionally stub this guy out */
	virtual bool Compile() = 0;

	/* Returns an info log if the compilation failed. */
	virtual const char* GetInfoLog() = 0;

};

class IVertexShader : public IShader
{
public:
};

class IFragShader : public IShader
{
public:
};

class IGeomShader : public IShader
{
public:
};


/**
 * Roughly corresponds to OpenGL's program objects. This is basically a pipeline in practice.
 * You bind shaders to individual slots here and then bind the program object to a mesh for rendering.
 */
class IShaderProgram
{
public:
	/* The program will be referenced by this name */
	virtual const char* GetName() const = 0;

	virtual void BindVertexShader(IVertexShader* pShader) = 0;
	virtual void BindFragShader(IFragShader* pShader) = 0;
	virtual void BindGeometryShader(IGeomShader* pShader) = 0;
	virtual void UnbindVertexShader() = 0;
	virtual void UnbindFragShader() = 0;
	virtual void UnbindGeometryShader() = 0;

	/* Links the shaders together. This is another thing basically ripped from Gl. */
	virtual bool Link() = 0;

	/* Resolves shader parameters in the GLSL */
	virtual void SetupParams(const char** params, size_t length) = 0;
	virtual void SetupUniforms(const char** params, size_t length) = 0;
	virtual void SetupOutputs(const char** outputs, size_t length) = 0;
	virtual void SetupTextureUniforms(const char** outputs, size_t length) = 0;

	/* Adds a fragment shader output, aka render target */
	/* param should corrsepond to the output param's name */
	/* Index should line up with the output layout in the shader. If index is -1, we will assign one */
	virtual void AddRenderTarget(const char* param, int &index, ITexture* pTexture) = 0;
	virtual void ClearRenderTargets() = 0;

	/* Pre-draw event. Do all setup here */
	virtual void PreDraw() = 0;

	/* Post draw callback */
	virtual void PostDraw() = 0;

	/* Returns the info log if the operation failed */
	virtual const char* GetInfoLog() = 0;

	virtual void EnableDepthWrite(bool b) = 0;

	/* Lots of parameter setting functions here, oh well! */
	virtual void SetFloatParam(const char* param, float f) = 0;
	virtual void SetFloat2Param(const char* param, float v[2]) = 0;
	virtual void SetFloat3Param(const char* param, float v[3]) = 0;
	virtual void SetFloat4Param(const char* param, float v[4]) = 0;
	virtual void SetDoubleParam(const char* param, double f) = 0;
	virtual void SetDouble2Param(const char* param, double v[2]) = 0;
	virtual void SetDouble3Param(const char* param, double v[3]) = 0;
	virtual void SetDouble4Param(const char* param, double v[4]) = 0;
	virtual void SetIntParam(const char* param, int f) = 0;
	virtual void SetInt2Param(const char* param, int v[2]) = 0;
	virtual void SetInt3Param(const char* param, int v[3]) = 0;
	virtual void SetInt4Param(const char* param, int v[4]) = 0;
	virtual void SetShortParam(const char* param, short f) = 0;
	virtual void SetShort2Param(const char* param, short v[2]) = 0;
	virtual void SetShort3Param(const char* param, short v[3]) = 0;
	virtual void SetShort4Param(const char* param, short v[4]) = 0;

	/* Uniform param setting */
	virtual void SetMat2x2Uniform(const char* param, float mat[2][2]) = 0;
	virtual void SetMat3x3Uniform(const char* param, float mat[3][3]) = 0;
	virtual void SetMat4x4Uniform(const char* param, float mat[4][4]) = 0;
	virtual void SetMat2x3Uniform(const char* param, float mat[2][3]) = 0;
	virtual void SetMat3x2Uniform(const char* param, float mat[3][2]) = 0;
	virtual void SetMat3x4Uniform(const char* param, float mat[3][4]) = 0;
	virtual void SetMat4x3Uniform(const char* param, float mat[4][3]) = 0;
	virtual void SetMat2x4Uniform(const char* param, float mat[2][4]) = 0;
	virtual void SetMat4x2Uniform(const char* param, float mat[4][2]) = 0;
	virtual void SetIntUniform(const char* param, int f) = 0;
	virtual void SetInt2Uniform(const char* param, int v[2]) = 0;
	virtual void SetInt3Uniform(const char* param, int v[3]) = 0;
	virtual void SetInt4Uniform(const char* param, int v[4]) = 0;
	virtual void SetFloatUniform(const char* param, float f) = 0;
	virtual void SetFloat2Uniform(const char* param, float v[2]) = 0;
	virtual void SetFloat3Uniform(const char* param, float v[3]) = 0;
	virtual void SetFloat4Uniform(const char* param, float v[4]) = 0;
	virtual void SetDoubleUniform(const char* param, double d) = 0;
	virtual void SetDouble2Uniform(const char* param, double d[2]) = 0;
	virtual void SetDouble3Uniform(const char* param, double d[3]) = 0;
	virtual void SetDouble4Uniform(const char* param, double d[4]) = 0;

	virtual void SetTextureUniform(const char* param, ITexture* pTex) = 0;
};

/**
 * IShaderShadow
 * 	Backend management class that goes with each shader.
 * 	The rendersystem calls each of the internal methods. Ideally this will only be called in one thread, so maintaining
 * 	state should be OK. However, this isn't 100% guaranteed in the future.
 */
class IShaderShadow
{
public:
	/**
	 * Called to initialize the shader program. This is only called once.
	 * In here, you'll want to call SetupParams, SetupUniforms, SetupOutputs and SetupTextureUniforms
	 * @param pShader
	 */
	virtual void Init(IShaderProgram* pShader) = 0;

	/**
	 * Called immediately before drawing with the shader. Here you'll want to be setting the uniforms and other params.
	 * @param pDrawMesh Pointer to the mesh we will be drawing
	 * @param pShader
	 */
	virtual void PreDraw(class IMesh* pDrawMesh, IShaderProgram* pShader) = 0;

	/**
	 * Called after drawing with the shader.
	 * @param pDrawMesh Pointer to the mesh we drew
	 * @param pShader
	 */
	virtual void PostDraw(class IMesh* pDrawMesh, IShaderProgram* pShader) = 0;

	/**
	 * Called to destroy the shader. Cleanup goes here
	 */
	virtual void Shutdown() = 0;
};