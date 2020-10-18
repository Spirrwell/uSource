/**
 *
 * gl_shader.cpp - OpenGL implementation of the shader backend
 *
 */
#include <GL/glew.h>

#include "public/containers/array.h"
#include "public/containers/list.h"
#include "public/containers/string.h"
#include "rendersystem/ishader.h"
#include "tier1/dbg.h"
#include "rendersystemgl.h"
#include <memory.h>
#include "gl_material.h"

BEGIN_RENDERSYSTEM_NAMESPACE

/* Avoiding a bit of code duplication here */
class CGenericShader_GL
{
public:
	GLuint m_shaderIndex;
	bool m_init : 1;
	bool m_compiled : 1;
	GLenum m_type;

	/* Shader source code */
	const char** m_sourceCode;
	unsigned long m_numLines;
	unsigned long* m_lineLengths;

	CGenericShader_GL(GLenum type);
	~CGenericShader_GL();
	bool GLCompile();
	void GLSetSourceCode(void* pbuf, size_t buflen, ESourceCodeType type = ESourceCodeType::GLSL);
	const char* GLGetInfoLog();

	void GLSetGLSL(const char* buf, size_t len);
};

class CVertexShader_GL : public IVertexShader, CGenericShader_GL
{
public:
	GLint m_shaderIndex;
	bool m_init : 1;
	bool m_compiled : 1;


	CVertexShader_GL() : CGenericShader_GL(GL_VERTEX_SHADER) {};
	~CVertexShader_GL() {};
	virtual void SetSourceCode(void* pbuf, size_t buflen, ESourceCodeType type = ESourceCodeType::GLSL) override
	{
		CGenericShader_GL::GLSetSourceCode(pbuf, buflen, type);
	}

	virtual bool Compile() override { return CGenericShader_GL::GLCompile(); };
	virtual const char* GetInfoLog() override { return CGenericShader_GL::GLGetInfoLog(); };
};

class CFragShader_GL : public IFragShader, CGenericShader_GL
{
public:
	GLint m_shaderIndex;
	bool m_init : 1;
	bool m_compiled : 1;

	CFragShader_GL() : CGenericShader_GL(GL_FRAGMENT_SHADER) {};
	~CFragShader_GL() {};

	virtual void SetSourceCode(void* pbuf, size_t buflen, ESourceCodeType type = ESourceCodeType::GLSL) override
	{
		CGenericShader_GL::GLSetSourceCode(pbuf, buflen, type);
	}

	virtual bool Compile() override { return CGenericShader_GL::GLCompile(); };
	virtual const char* GetInfoLog() override { return CGenericShader_GL::GLGetInfoLog(); };
};


class CGeomShader_GL : public IGeomShader, CGenericShader_GL
{
public:
	GLint m_shaderIndex;
	bool m_init : 1;
	bool m_compiled : 1;

	CGeomShader_GL() : CGenericShader_GL(GL_GEOMETRY_SHADER) {};
	~CGeomShader_GL() {};

	virtual void SetSourceCode(void* pbuf, size_t buflen, ESourceCodeType type = ESourceCodeType::GLSL) override
	{
		CGenericShader_GL::GLSetSourceCode(pbuf, buflen, type);
	}

	virtual bool Compile() override { return CGenericShader_GL::GLCompile(); };
	virtual const char* GetInfoLog() override { return CGenericShader_GL::GLGetInfoLog(); };
};

class CShaderProgram_GL : public IShaderProgram
{
public:
	CFragShader_GL* m_fragShader;
	CVertexShader_GL* m_vertShader;
	CGeomShader_GL* m_geomShader;
	GLint m_programIndex;
	GLint m_maxRenderTargets;
	char* m_name;
	bool m_linked : 1;
	bool m_depth : 1; // do we have a depth attachment already??
	bool m_stencil : 1; // do we have a stencil attachment??
	GLint m_currentColorBuffer;
	IShaderShadow* m_shadow;

	struct rendertarget_t
	{
		String name;
		GLenum buffer;
		GLint index;
	} m_depthTarget, m_stencilTarget;
	List<rendertarget_t> m_renderTargets;

	struct shader_params_t
	{
		String name;
		GLint index;
	};
	Array<shader_params_t> m_shaderParams;
	Array<shader_params_t> m_shaderOutputs;
	Array<shader_params_t> m_shaderUniforms;

	struct texture_uniform_t
	{
		String name;
		GLint index;
		GLint unit;
	};
	Array<texture_uniform_t> m_shaderTextures;

	GLint FindParamIndex(const char* s);
	GLint FindOutputIndex(const char* s);
	GLint FindUniformIndex(const char* s);
	texture_uniform_t FindTexParam(const char* s);

	CShaderProgram_GL(const char* m_name);
	~CShaderProgram_GL();

	/* The program will be referenced by this name */
	virtual const char* GetName() const;

	virtual void BindVertexShader(IVertexShader* pShader);
	virtual void BindFragShader(IFragShader* pShader);
	virtual void BindGeometryShader(IGeomShader* pShader);
	virtual void UnbindVertexShader();
	virtual void UnbindFragShader();
	virtual void UnbindGeometryShader();

	/* Links the shaders together. This is another thing basically ripped from Gl. */
	virtual bool Link();

	/* Returns the info log if the operation failed */
	virtual const char* GetInfoLog();

	virtual void SetupParams(const char** params, size_t length);
	virtual void SetupOutputs(const char** outputs, size_t length);
	virtual void SetupUniforms(const char** outputs, size_t length);
	virtual void SetupTextureUniforms(const char** uniforms, size_t length);
	virtual void AddRenderTarget(const char* param, int &index, ITexture* pTexture);
	virtual void ClearRenderTargets();

	virtual void Init();
	virtual void PostDraw(IMesh* pmesh);
	virtual void PreDraw(IMesh* pMesh);

	virtual void EnableDepthWrite(bool enable);

	inline bool CheckParamType(GLint param, GLenum type);
	inline bool CheckUniformType(GLint param, GLenum type);

	/* Lots of parameter setting functions here, oh well! */
	virtual void SetFloatParam(const char* param, float f);
	virtual void SetFloat2Param(const char* param, float v[2]);
	virtual void SetFloat3Param(const char* param, float v[3]);
	virtual void SetFloat4Param(const char* param, float v[4]);
	virtual void SetDoubleParam(const char* param, double f);
	virtual void SetDouble2Param(const char* param, double v[2]);
	virtual void SetDouble3Param(const char* param, double v[3]);
	virtual void SetDouble4Param(const char* param, double v[4]);
	virtual void SetIntParam(const char* param, int f);
	virtual void SetInt2Param(const char* param, int v[2]);
	virtual void SetInt3Param(const char* param, int v[3]);
	virtual void SetInt4Param(const char* param, int v[4]);
	virtual void SetShortParam(const char* param, short f);
	virtual void SetShort2Param(const char* param, short v[2]);
	virtual void SetShort3Param(const char* param, short v[3]);
	virtual void SetShort4Param(const char* param, short v[4]);

	/* Uniform param setting */
	virtual void SetMat2x2Uniform(const char* param, float mat[2][2]);
	virtual void SetMat3x3Uniform(const char* param, float mat[3][3]);
	virtual void SetMat4x4Uniform(const char* param, float mat[4][4]);
	virtual void SetMat2x3Uniform(const char* param, float mat[2][3]);
	virtual void SetMat3x2Uniform(const char* param, float mat[3][2]);
	virtual void SetMat3x4Uniform(const char* param, float mat[3][4]);
	virtual void SetMat4x3Uniform(const char* param, float mat[4][3]);
	virtual void SetMat2x4Uniform(const char* param, float mat[2][4]);
	virtual void SetMat4x2Uniform(const char* param, float mat[4][2]);
	virtual void SetIntUniform(const char* param, int f);
	virtual void SetInt2Uniform(const char* param, int v[2]);
	virtual void SetInt3Uniform(const char* param, int v[3]);
	virtual void SetInt4Uniform(const char* param, int v[4]);
	virtual void SetFloatUniform(const char* param, float f);
	virtual void SetFloat2Uniform(const char* param, float v[2]);
	virtual void SetFloat3Uniform(const char* param, float v[3]);
	virtual void SetFloat4Uniform(const char* param, float v[4]);
	virtual void SetDoubleUniform(const char* param, double d);
	virtual void SetDouble2Uniform(const char* param, double d[2]);
	virtual void SetDouble3Uniform(const char* param, double d[3]);
	virtual void SetDouble4Uniform(const char* param, double d[4]);

	virtual void SetTextureUniform(const char* param, ITexture* pTex);

	virtual void SetShaderShadow(class IShaderShadow* pShadow);
};

//=============================================================================================================================================//
// CGenericShader_GL

CGenericShader_GL::CGenericShader_GL(GLenum type) :
	m_shaderIndex(0),
	m_init(false),
	m_compiled(false),
	m_type(type),
	m_lineLengths(nullptr),
	m_numLines(0),
	m_sourceCode(nullptr)
{
	this->m_shaderIndex = glCreateShader(type);
	m_init = true;
}

CGenericShader_GL::~CGenericShader_GL()
{
	glDeleteShader(m_shaderIndex);
	m_init = false;

	if(m_sourceCode)
	{
		for(int i = 0; i < m_numLines; i++)
		{
			free((void *) m_sourceCode[i]);
		}
	}
	if(m_lineLengths) free(m_lineLengths);
}

bool CGenericShader_GL::GLCompile()
{
	glCompileShader(m_shaderIndex);
	GLint status;
	glGetShaderiv(m_shaderIndex, GL_COMPILE_STATUS, &status);
	m_compiled = (status == GL_TRUE);
	return m_compiled;
}

void CGenericShader_GL::GLSetSourceCode(void *pbuf, size_t buflen, ESourceCodeType _type)
{
	switch(_type)
	{
		case ESourceCodeType::GLSL:
			GLSetGLSL((const char*)pbuf, buflen);
		case ESourceCodeType::FXC:
		case ESourceCodeType::HLSL:
		case ESourceCodeType::SPIRV:
		default:
			AssertMsg(0, "FXC, HLSL and SPIRV shader loading backends are not implemented.");
			break;
	}
}

void CGenericShader_GL::GLSetGLSL(const char *buf, size_t len)
{
	/* Loop through the code in search of newlines */
	m_numLines = 0;
	for(size_t i = 0; i < len; i++)
		if(buf[i] == '\n') m_numLines++;

	/* Allocate the number of lines */
	m_lineLengths = static_cast<unsigned long *>(malloc(sizeof(unsigned long) * m_numLines));

	size_t prevpos = 0;
	size_t curpos = 0;
	size_t curline = 0;
	for(size_t i = 0; i < len; i++, curpos++)
	{
		if (buf[i] == '\n')
		{
			m_sourceCode[curline] = (char*)malloc(sizeof(char) * (curpos-prevpos + 1));
			memcpy((void *) m_sourceCode[curline], &buf[prevpos], curpos - prevpos + 1);
			prevpos = curpos+1;
			m_lineLengths[curline] = curpos - prevpos;
			curline++;
		}
	}
}

const char *CGenericShader_GL::GLGetInfoLog()
{
	static GLchar log[8192];
	GLsizei outsize = 0;
	glGetShaderInfoLog(m_shaderIndex, sizeof(log), &outsize, log);
	return log;
}
//=============================================================================================================================================//

//=============================================================================================================================================//
// CShaderProgram_GL

IShaderProgram* CRenderSystem_GL::CreateShaderProgram(const char *name)
{
	return new CShaderProgram_GL(name);
}

CShaderProgram_GL::CShaderProgram_GL(const char* name) :
	m_fragShader(nullptr),
	m_vertShader(nullptr),
	m_geomShader(nullptr),
	m_programIndex(0),
	m_linked(false),
	m_stencil(false),
	m_currentColorBuffer(0),
	m_depth(0),
	m_maxRenderTargets(0),
	m_shadow(nullptr)
{
	m_name = strdup(name);
	m_programIndex = glCreateProgram();
}

CShaderProgram_GL::~CShaderProgram_GL()
{
	if(m_name) free(m_name);
	glDeleteProgram(m_programIndex);
}

GLint CShaderProgram_GL::FindOutputIndex(const char* s)
{
	for(const auto& x : m_shaderOutputs)
	{
		if(x.name.equals(s))
			return x.index;
	}
	return -1;
}

GLint CShaderProgram_GL::FindParamIndex(const char* s)
{
	for(const auto& x : m_shaderParams)
	{
		if(x.name.equals(s))
			return x.index;
	}
	return -1;
}

GLint CShaderProgram_GL::FindUniformIndex(const char* s)
{
	for(const auto& x : m_shaderUniforms)
	{
		if(x.name.equals(s))
			return x.index;
	}
	return -1;
}

CShaderProgram_GL::texture_uniform_t CShaderProgram_GL::FindTexParam(const char* s)
{
	for(auto x : m_shaderTextures)
	{
		if(x.name.equals(s))
			return x;
	}
	return texture_uniform_t();
}

bool CShaderProgram_GL::CheckParamType(GLint param, GLenum type)
{
	return false;
}

bool CShaderProgram_GL::CheckUniformType(GLint param, GLenum type)
{
	return false;
}

const char *CShaderProgram_GL::GetName() const
{
	return m_name;
}

void CShaderProgram_GL::BindVertexShader(IVertexShader *pShader)
{
	glAttachShader(m_programIndex, ((CVertexShader_GL*)pShader)->m_shaderIndex);
}

void CShaderProgram_GL::BindFragShader(IFragShader *pShader)
{
	glAttachShader(m_programIndex, ((CFragShader_GL*)pShader)->m_shaderIndex);
}

void CShaderProgram_GL::BindGeometryShader(IGeomShader *pShader)
{
	glAttachShader(m_programIndex, ((CGeomShader_GL*)pShader)->m_shaderIndex);
}

void CShaderProgram_GL::UnbindVertexShader()
{
	Assert(m_vertShader);
	if(!m_vertShader) return;
	glDetachShader(m_programIndex, m_vertShader->m_init);
	m_vertShader = nullptr;
}

void CShaderProgram_GL::UnbindFragShader()
{
	Assert(m_fragShader);
	if(!m_fragShader) return;
	glDetachShader(m_programIndex, m_fragShader->m_init);
	m_fragShader = nullptr;
}

void CShaderProgram_GL::UnbindGeometryShader()
{
	Assert(m_geomShader);
	if(!m_geomShader) return;
	glDetachShader(m_programIndex, m_geomShader->m_init);
	m_geomShader = nullptr;
}

bool CShaderProgram_GL::Link()
{
	glLinkProgram(m_programIndex);
	GLint status;
	glGetProgramiv(m_programIndex, GL_LINK_STATUS, &status);
	m_linked = (status == GL_TRUE);
	return m_linked;
}

void CShaderProgram_GL::SetupOutputs(const char **outputs, size_t length)
{
	for(int i = 0; i < length; i++)
	{
		shader_params_t output;
		Assert(outputs[i]);
		output.index = glGetFragDataIndex(m_programIndex, outputs[i]);
		output.name = outputs[i];
		m_shaderOutputs.push_back(output);
	}
}

void CShaderProgram_GL::SetupParams(const char** params, size_t length)
{
	for(int i = 0; i < length; i++)
	{
		shader_params_t param;
		Assert(params[i]);
		param.index = glGetAttribLocation(m_programIndex, params[i]);
		param.name = params[i];
		m_shaderParams.push_back(param);
	}
}

void CShaderProgram_GL::ClearRenderTargets()
{
	m_renderTargets.clear();
	m_depth = false;
	m_stencil = false;
	m_currentColorBuffer = 0;
}

void CShaderProgram_GL::EnableDepthWrite(bool enable)
{

}

void CShaderProgram_GL::AddRenderTarget(const char* param, int& index, ITexture* pTexture)
{
	/* Note: requires GL3 or higher */
	static GLenum colorbuffer_map[] = {
		GL_COLOR_ATTACHMENT0,
		GL_COLOR_ATTACHMENT1,
		GL_COLOR_ATTACHMENT2,
		GL_COLOR_ATTACHMENT3,
		GL_COLOR_ATTACHMENT4,
		GL_COLOR_ATTACHMENT5,
		GL_COLOR_ATTACHMENT6,
		GL_COLOR_ATTACHMENT7
	};

	if(index == -1)
	{
		index = FindOutputIndex(param);
		if(index == -1) return;
	}

	unsigned int flags = pTexture->Flags();
	if(flags & TEXFLAGS_DEPTH)
	{
		Assert(!m_depth);
		m_depth = true;
		m_depthTarget.buffer = GL_DEPTH_ATTACHMENT;
		m_depthTarget.index = index;
		m_depthTarget.name = param;
	}
	else if(flags & TEXFLAGS_STENCIL)
	{
		Assert(!m_stencil);
		m_stencil = true;
		m_stencilTarget.buffer = GL_STENCIL_ATTACHMENT;
		m_stencilTarget.index = index;
		m_stencilTarget.name = param;
	}
	else if(flags & TEXFLAGS_RENDERBUFFER)
	{
		Assert(m_currentColorBuffer < 8);
		rendertarget_t tgt;
		tgt.buffer = colorbuffer_map[m_currentColorBuffer];
		tgt.name = param;
		tgt.index = index;
		m_currentColorBuffer++;
		m_renderTargets.push_back(tgt);
	}

}

const char *CShaderProgram_GL::GetInfoLog()
{
	static GLchar log[8192];
	GLsizei outsize;
	glGetProgramInfoLog(m_programIndex, sizeof(log), &outsize, log);
	return log;
}

void CShaderProgram_GL::PostDraw(IMesh* pMesh)
{
	if(m_shadow)
		m_shadow->PostDraw(pMesh, this);
}

void CShaderProgram_GL::PreDraw(IMesh* pMesh)
{
	/* Call into the shadow state manager */
	if(m_shadow)
		m_shadow->PreDraw(pMesh, this);

	/* Setup the render targets */
	Assert(m_renderTargets.size() < 8);
	GLenum targets[10];
	memset(targets, 0, sizeof(GLenum) * 10);
	for(const auto& x : m_renderTargets)
	{
		AssertMsg(x.index < 10, "Index of output buffer was greater than 10! Max of 8 color attachments, 1 depth attachment and 1 stencil attachment supported!");
		if(x.index < 10)
			targets[x.index] = x.buffer;
	}
	glDrawBuffers(m_renderTargets.size(), targets);
}

void CShaderProgram_GL::SetFloatParam(const char *param, float f)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttrib1f(iparam, f);
}

void CShaderProgram_GL::SetFloat2Param(const char *param, float *v)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttrib2fv(iparam, v);
}

void CShaderProgram_GL::SetFloat3Param(const char *param, float *v)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttrib3fv(iparam, v);
}

void CShaderProgram_GL::SetFloat4Param(const char *param, float *v)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttrib4fv(iparam, v);
}

void CShaderProgram_GL::SetDoubleParam(const char *param, double f)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttrib1d(iparam, f);
}

void CShaderProgram_GL::SetDouble2Param(const char *param, double *v)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttrib2dv(iparam, v);
}

void CShaderProgram_GL::SetDouble3Param(const char *param, double *v)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttrib3dv(iparam, v);
}

void CShaderProgram_GL::SetDouble4Param(const char *param, double *v)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttrib4dv(iparam, v);
}

void CShaderProgram_GL::SetIntParam(const char *param, int f)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttribI1i(iparam, f);
}

void CShaderProgram_GL::SetInt2Param(const char *param, int *v)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttribI2iv(iparam, v);
}

void CShaderProgram_GL::SetInt3Param(const char *param, int *v)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttribI3iv(iparam, v);
}

void CShaderProgram_GL::SetInt4Param(const char *param, int *v)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttrib4iv(iparam, v);
}

void CShaderProgram_GL::SetShortParam(const char *param, short f)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttrib1s(iparam, f);
}

void CShaderProgram_GL::SetShort2Param(const char *param, short *v)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttrib2sv(iparam, v);
}

void CShaderProgram_GL::SetShort3Param(const char *param, short *v)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttrib3sv(iparam, v);
}

void CShaderProgram_GL::SetShort4Param(const char *param, short *v)
{
	GLint iparam = FindParamIndex(param);
	Assert(iparam != -1);
	glVertexAttrib4sv(iparam, v);
}

void CShaderProgram_GL::SetMat2x2Uniform(const char *param, float (*mat)[2])
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniformMatrix2fv(iparam, 1, true, reinterpret_cast<const GLfloat *>(mat));
}

void CShaderProgram_GL::SetMat3x3Uniform(const char *param, float (*mat)[3])
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniformMatrix3fv(iparam, 1, true, reinterpret_cast<const GLfloat *>(mat));
}

void CShaderProgram_GL::SetMat4x4Uniform(const char *param, float (*mat)[4])
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniformMatrix4fv(iparam, 1, true, reinterpret_cast<const GLfloat *>(mat));
}

void CShaderProgram_GL::SetMat2x3Uniform(const char *param, float (*mat)[3])
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniformMatrix2x3fv(iparam, 1, true, reinterpret_cast<const GLfloat *>(mat));
}

void CShaderProgram_GL::SetMat3x2Uniform(const char *param, float (*mat)[2])
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniformMatrix3x2fv(iparam, 1, true, reinterpret_cast<const GLfloat *>(mat));
}

void CShaderProgram_GL::SetMat3x4Uniform(const char *param, float (*mat)[4])
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniformMatrix3x4fv(iparam, 1, true, reinterpret_cast<const GLfloat *>(mat));
}

void CShaderProgram_GL::SetMat4x3Uniform(const char *param, float (*mat)[3])
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniformMatrix4x3fv(iparam, 1, true, reinterpret_cast<const GLfloat *>(mat));
}

void CShaderProgram_GL::SetMat2x4Uniform(const char *param, float (*mat)[4])
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniformMatrix2x4fv(iparam, 1, true, reinterpret_cast<const GLfloat *>(mat));
}

void CShaderProgram_GL::SetMat4x2Uniform(const char *param, float (*mat)[2])
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniformMatrix4x2fv(iparam, 1, true, reinterpret_cast<const GLfloat *>(mat));
}

void CShaderProgram_GL::SetIntUniform(const char *param, int f)
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniform1i(iparam, f);
}

void CShaderProgram_GL::SetInt2Uniform(const char *param, int *v)
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniform2iv(iparam, 1, v);
}

void CShaderProgram_GL::SetInt3Uniform(const char *param, int *v)
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniform3iv(iparam, 1, v);
}

void CShaderProgram_GL::SetInt4Uniform(const char *param, int *v)
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniform4iv(iparam, 1, v);
}

void CShaderProgram_GL::SetFloatUniform(const char *param, float f)
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniform1f(iparam, f);
}

void CShaderProgram_GL::SetFloat2Uniform(const char *param, float *v)
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniform2fv(iparam, 1, v);
}

void CShaderProgram_GL::SetFloat3Uniform(const char *param, float *v)
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniform3fv(iparam, 1, v);
}

void CShaderProgram_GL::SetFloat4Uniform(const char *param, float *v)
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniform4fv(iparam, 1, v);
}

void CShaderProgram_GL::SetDoubleUniform(const char *param, double d)
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniform1d(iparam, d);
}

void CShaderProgram_GL::SetDouble2Uniform(const char *param, double *d)
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniform2dv(iparam, 1, d);
}

void CShaderProgram_GL::SetDouble3Uniform(const char *param, double *d)
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniform3dv(iparam, 1, d);
}

void CShaderProgram_GL::SetDouble4Uniform(const char *param, double *d)
{
	GLint iparam = FindUniformIndex(param);
	Assert(iparam != -1);
	glUniform4dv(iparam, 1, d);
}

void CShaderProgram_GL::SetTextureUniform(const char *param, ITexture *pTex)
{
	CShaderProgram_GL::texture_uniform_t texparam = FindTexParam(param);
	Assert(texparam.index != -1);
	Assert(pTex);
	CTexture_GL* pTexture = (CTexture_GL*)pTex;
	AssertMsg(pTexture->IsTexture(), "Texture passed to function is NOT a texture!");

	static GLint tex_unit_map[] = {
		GL_TEXTURE0,
		GL_TEXTURE1,
		GL_TEXTURE2,
		GL_TEXTURE3,
		GL_TEXTURE4,
		GL_TEXTURE5,
		GL_TEXTURE6,
		GL_TEXTURE7,
		GL_TEXTURE8,
		GL_TEXTURE9,
		GL_TEXTURE10,
		GL_TEXTURE11,
		GL_TEXTURE12,
		GL_TEXTURE13,
		GL_TEXTURE14,
		GL_TEXTURE15,
		GL_TEXTURE16,
		GL_TEXTURE17,
		GL_TEXTURE18,
		GL_TEXTURE19,
		GL_TEXTURE20,
		GL_TEXTURE21,
		GL_TEXTURE22,
		GL_TEXTURE23,
		GL_TEXTURE24,
		GL_TEXTURE25,
		GL_TEXTURE26,
		GL_TEXTURE27,
		GL_TEXTURE28,
		GL_TEXTURE29,
		GL_TEXTURE30,
		GL_TEXTURE31,
	};
	glActiveTexture(tex_unit_map[texparam.unit]);
	glBindTexture(GL_TEXTURE_2D, pTexture->m_texture);
	glUniform1i(texparam.index, texparam.unit);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void CShaderProgram_GL::SetupUniforms(const char **outputs, size_t length)
{
	Assert(outputs);
	for(int i = 0; i < length; i++)
	{
		shader_params_t param;
		Assert(outputs[i]);
		param.name = outputs[i];
		param.index = glGetUniformLocation(m_programIndex, outputs[i]);
		m_shaderUniforms.push_back(param);
	}
}

void CShaderProgram_GL::SetupTextureUniforms(const char **uniforms, size_t length)
{
	Assert(uniforms);
	GLint active_unit = 0;
	for(int i = 0; i < length; i++)
	{
		texture_uniform_t param;
		Assert(uniforms[i]);
		param.name = uniforms[i];
		param.index = glGetUniformLocation(m_programIndex, uniforms[i]);
		param.unit = active_unit;
		active_unit++;
		m_shaderTextures.push_back(param);
	}
}

void CShaderProgram_GL::SetShaderShadow(struct IShaderShadow *pShadow)
{
	m_shadow = pShadow;
}

void CShaderProgram_GL::Init()
{
	if(m_shadow)
		m_shadow->Init(this);
}


//=============================================================================================================================================//

END_RENDERSYSTEM_NAMESPACE