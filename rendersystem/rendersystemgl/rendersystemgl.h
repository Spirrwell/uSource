#pragma once

#include "rendersystem/ibuffer.h"
#include "rendersystem/imesh.h"
#include "rendersystem/ishader.h"
#include "rendersystem/material.h"
#include "rendersystem/rendersystem.h"

extern byte* g_pGLPool;

class CRenderSystem_GL : public IRenderSystem
{
public:
	virtual void Init(const render_params_t& params) override;
	virtual void Shutdown() override;

	virtual class ITriangleAPI* GetTriAPI() override;
	virtual IShaderProgram*	    CreateShaderProgram(const char* name) override;
};

namespace GL
{
unsigned int GetParam(unsigned long param);
}