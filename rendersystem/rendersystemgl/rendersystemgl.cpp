#include <GL/glew.h>
#include "rendersystemgl.h"
#include "tier1/tier1.h"
#include "tier1/dbg.h"
#include "gl_util.h"

BEGIN_RENDERSYSTEM_NAMESPACE

using namespace GL;

byte* g_pGLPool = nullptr;

IRenderSystem* CreateRenderSystem()
{
	return new CRenderSystem_GL();
}

void CRenderSystem_GL::Init(const render_params_t &params)
{
	//g_pGLPool = g_pEngineMalloc->Mem_AllocPool("RendersystemGL", __FILE__, __LINE__);

	/* GLEW Initialization */
	glewExperimental = true;
	GLenum res = glewInit();

	if(res != GLEW_OK)
	{
		MsgC(red, "RendersystemGL: GLEW failed to init: %s\n", glewGetErrorString(res));
		g_pEngineDebug->HostError("RendersystemGL: GLEW failed to init\n");
	}

	Assert(g_pEngineDebug);

	if(!GLEW_VERSION_3_0)
	{
		MsgC(red, "RendersystemGL: Your device doesn't support OpenGL 3!! This is required for this render API implementation");
		g_pEngineDebug->HostError("RendersystemGL: Your device doesn't support OpenGL 3!! This is required for this render API implementation");
	}

	/* Setup basic opengl params */
	glViewport(0, 0, params.width, params.height);


}

void CRenderSystem_GL::Shutdown()
{
	//g_pEngineMalloc->Mem_FreePool(&g_pGLPool, __FILE__, __LINE__);
}

unsigned int GetParam(unsigned long param)
{
	GLint out;
	glGetIntegerv(param, &out);
	return out;
}


void CRenderSystem_GL::OnParamsChanged(const render_params_t &params)
{
	glViewport(0, 0, params.width, params.height);
}

IVertexBuffer *CRenderSystem_GL::CreateEmptyVertexBuffer(EVertexFormat fmt, EBufferType type)
{
	return nullptr;
}

IIndexBuffer *CRenderSystem_GL::CreateEmptyIndexBuffer(EIndexFormat fmt, EBufferType type)
{
	return nullptr;
}

IBuffer *CRenderSystem_GL::CreateEmptyBuffer(EBufferType type)
{
	return nullptr;
}

ITexture *CRenderSystem_GL::CreateEmptyTexture(ETextureFormat fmt)
{
	return nullptr;
}

ITexture *CRenderSystem_GL::CreateTextureFromImage(const void *img)
{
	return nullptr;
}

ITexture *CRenderSystem_GL::CreateRenderTarget(const char *name, ETextureFormat fmt, int width, int height, int flags)
{
	return nullptr;
}

IGeomShader *CRenderSystem_GL::CreateGeometryShader()
{
	return nullptr;
}

IVertexShader *CRenderSystem_GL::CreateVertexShader()
{
	return nullptr;
}

IFragShader *CRenderSystem_GL::CreateFragShader()
{
	return nullptr;
}

void CRenderSystem_GL::SetDepthFunc(EShaderDepthFunc func)
{
	glDepthFunc(gl::DepthFuncToGL(func));
	m_depthFunc = func;
}

void CRenderSystem_GL::SetBlendEquation(EShaderBlendEq func)
{
	glBlendEquation(gl::BlendEquationToGL(func));
	m_blendEquation = func;
}

void CRenderSystem_GL::SetBlendFunc(EShaderBlendFunc func)
{
	glBlendFunc(GL_ONE, gl::BlendFuncToGL(func));
	m_blendFunc = func;
}

void CRenderSystem_GL::SetAlphaFunc(EShaderAlphaFunc func)
{
	glAlphaFunc(gl::AlphaFuncToGL(func), 0.0f);
	m_alphaFunc = func;
}

void CRenderSystem_GL::SetStencilFunc(EShaderStencilFunc func)
{
	glStencilFunc(gl::StencilFuncToGL(func), m_stencilRef, m_stencilMask);
	m_stencilFunc = func;
}

void CRenderSystem_GL::SetStencilOp(EShaderStencilOp op)
{
	glStencilOp(gl::StencilOpToGL(op), GL_KEEP, GL_KEEP);
	m_stencilOp = op;
}

END_RENDERSYSTEM_NAMESPACE