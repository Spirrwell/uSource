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
	struct rendertarget_t
	{
		String name;
		GLenum buffer;
		GLint index;
	} m_depthTarget, m_stencilTarget;
	List<rendertarget_t> m_renderTargets;

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
	virtual void AddRenderTarget(const char* param, int &index, ITexture* pTexture);
	virtual void ClearRenderTargets();
	virtual void PostDraw();
	virtual void PreDraw();

	virtual void EnableDepthWrite(bool enable);

	/* Lots of parameter setting functions here, oh well! */
	virtual void SetTextureParam(const char* param, ITexture* pTex);
	virtual void SetFloatParam(const char* param, float f);
	virtual void SetFloat2Param(const char* param, float v[2]);
	virtual void SetFloat3Param(const char* param, float v[3]);
	virtual void SetFloat4Param(const char* param, float v[4]);
	virtual void SetDoubleParam(const char* param, float f);
	virtual void SetDouble2Param(const char* param, float v[2]);
	virtual void SetDouble3Param(const char* param, float v[3]);
	virtual void SetDouble4Param(const char* param, float v[4]);
	virtual void SetIntParam(const char* param, float f);
	virtual void SetInt2Param(const char* param, float v[2]);
	virtual void SetInt3Param(const char* param, float v[3]);
	virtual void SetInt4Param(const char* param, float v[4]);
	virtual void SetShortParam(const char* param, float f);
	virtual void SetShort2Param(const char* param, float v[2]);
	virtual void SetShort3Param(const char* param, float v[3]);
	virtual void SetShort4Param(const char* param, float v[4]);

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
	virtual void SetIntUniform(const char* param, float f);
	virtual void SetInt2Uniform(const char* param, float v[2]);
	virtual void SetInt3Uniform(const char* param, float v[3]);
	virtual void SetInt4Uniform(const char* param, float v[4]);
	virtual void SetFloatUniform(const char* param, float f);
	virtual void SetFloat2Uniform(const char* param, float v[2]);
	virtual void SetFloat3Uniform(const char* param, float v[3]);
	virtual void SetFloat4Uniform(const char* param, float v[4]);
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
	m_maxRenderTargets(0)
{
	m_name = strdup(name);
	m_programIndex = glCreateProgram();
}

CShaderProgram_GL::~CShaderProgram_GL()
{
	if(m_name) free(m_name);
	glDeleteProgram(m_programIndex);
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

void CShaderProgram_GL::SetupParams(const char** params, size_t length)
{

}

void CShaderProgram_GL::ClearRenderTargets()
{

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
	else if(flags & TEXFLAGS_FRAMEBUFFER)
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

void CShaderProgram_GL::PostDraw()
{

}

void CShaderProgram_GL::PreDraw()
{
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

void CShaderProgram_GL::SetTextureParam(const char *param, ITexture *pTex)
{

}

void CShaderProgram_GL::SetFloatParam(const char *param, float f)
{

}

void CShaderProgram_GL::SetFloat2Param(const char *param, float *v)
{

}

void CShaderProgram_GL::SetFloat3Param(const char *param, float *v)
{

}

void CShaderProgram_GL::SetFloat4Param(const char *param, float *v)
{

}

void CShaderProgram_GL::SetDoubleParam(const char *param, float f)
{

}

void CShaderProgram_GL::SetDouble2Param(const char *param, float *v)
{

}

void CShaderProgram_GL::SetDouble3Param(const char *param, float *v)
{

}

void CShaderProgram_GL::SetDouble4Param(const char *param, float *v)
{

}

void CShaderProgram_GL::SetIntParam(const char *param, float f)
{

}

void CShaderProgram_GL::SetInt2Param(const char *param, float *v)
{

}

void CShaderProgram_GL::SetInt3Param(const char *param, float *v)
{

}

void CShaderProgram_GL::SetInt4Param(const char *param, float *v)
{

}

void CShaderProgram_GL::SetShortParam(const char *param, float f)
{

}

void CShaderProgram_GL::SetShort2Param(const char *param, float *v)
{

}

void CShaderProgram_GL::SetShort3Param(const char *param, float *v)
{

}

void CShaderProgram_GL::SetShort4Param(const char *param, float *v)
{

}

void CShaderProgram_GL::SetMat2x2Uniform(const char *param, float (*mat)[2])
{

}

void CShaderProgram_GL::SetMat3x3Uniform(const char *param, float (*mat)[3])
{

}

void CShaderProgram_GL::SetMat4x4Uniform(const char *param, float (*mat)[4])
{

}

void CShaderProgram_GL::SetMat2x3Uniform(const char *param, float (*mat)[3])
{

}

void CShaderProgram_GL::SetMat3x2Uniform(const char *param, float (*mat)[2])
{

}

void CShaderProgram_GL::SetMat3x4Uniform(const char *param, float (*mat)[4])
{

}

void CShaderProgram_GL::SetMat4x3Uniform(const char *param, float (*mat)[3])
{

}

void CShaderProgram_GL::SetMat2x4Uniform(const char *param, float (*mat)[4])
{

}

void CShaderProgram_GL::SetMat4x2Uniform(const char *param, float (*mat)[2])
{

}

void CShaderProgram_GL::SetIntUniform(const char *param, float f)
{

}

void CShaderProgram_GL::SetInt2Uniform(const char *param, float *v)
{

}

void CShaderProgram_GL::SetInt3Uniform(const char *param, float *v)
{

}

void CShaderProgram_GL::SetInt4Uniform(const char *param, float *v)
{

}

void CShaderProgram_GL::SetFloatUniform(const char *param, float f)
{

}

void CShaderProgram_GL::SetFloat2Uniform(const char *param, float *v)
{

}

void CShaderProgram_GL::SetFloat3Uniform(const char *param, float *v)
{

}

void CShaderProgram_GL::SetFloat4Uniform(const char *param, float *v)
{

}
//=============================================================================================================================================//
