#pragma once

#include <itriapi.h>
#include "rendersystem/rendersystem.h"
#include "rendersystem/imesh.h"
#include "rendersystem/ishader.h"
#include "rendersystem/material.h"
#include "rendersystem/ibuffer.h"

BEGIN_RENDERSYSTEM_NAMESPACE

extern byte* g_pGLPool;

class CRenderSystem_GL : public IRenderSystem
{
public:
	void Init() override;

	void Shutdown() override;

	void SetRequestedAPI(RenderAPIInfo_t apiInfo) override;

	int NumRenderDevices() override;

	RenderDeviceInfo_t DeviceInfo(int index) override;

	IRenderDevice *CreateRenderDevice(int index) override;

	void DestroyRenderDevice(IRenderDevice *dev) override;

public:

private:
	EShaderDepthFunc m_depthFunc;
	EShaderBlendEq m_blendEquation;
	EShaderBlendFunc m_blendFunc;
	EShaderAlphaFunc m_alphaFunc;
	EShaderStencilFunc m_stencilFunc;
	EShaderStencilOp m_stencilOp;

	int m_stencilRef;
	unsigned int m_stencilMask;

	rendersystem::ITriangleAPI *GetTriAPI();
};

namespace GL
{
	unsigned int GetParam(unsigned long param);
}

END_RENDERSYSTEM_NAMESPACE