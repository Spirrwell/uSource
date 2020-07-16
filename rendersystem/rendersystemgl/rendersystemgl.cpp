#include <GL/glew.h>
#include "rendersystemgl.h"
#include "tier1/tier1.h"
#include "tier1/dbg.h"

using namespace GL;

byte* g_pGLPool = nullptr;

void CRenderSystem_GL::Init(const render_params_t &params)
{
	//g_pGLPool = g_pEngineMalloc->Mem_AllocPool("RendersystemGL", __FILE__, __LINE__);
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