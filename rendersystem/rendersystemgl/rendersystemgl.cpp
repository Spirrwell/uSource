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


void rendersystem::CRenderSystem_GL::Init()
{

}

void rendersystem::CRenderSystem_GL::Shutdown()
{

}

void rendersystem::CRenderSystem_GL::SetRequestedAPI(rendersystem::RenderAPIInfo_t apiInfo)
{

}

int rendersystem::CRenderSystem_GL::NumRenderDevices()
{
	return 0;
}

rendersystem::RenderDeviceInfo_t rendersystem::CRenderSystem_GL::DeviceInfo(int index)
{
	return RenderDeviceInfo_t();
}

rendersystem::IRenderDevice *rendersystem::CRenderSystem_GL::CreateRenderDevice(int index)
{
	return nullptr;
}

void rendersystem::CRenderSystem_GL::DestroyRenderDevice(rendersystem::IRenderDevice *dev)
{

}

END_RENDERSYSTEM_NAMESPACE
