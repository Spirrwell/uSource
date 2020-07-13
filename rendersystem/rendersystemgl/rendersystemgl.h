#pragma once

#include "rendersystem/rendersystem.h"
#include "rendersystem/imesh.h"
#include "rendersystem/ishader.h"
#include "rendersystem/material.h"
#include "rendersystem/ibuffer.h"
#include "rendersystem/itriapi.h"

class CRenderSystem_GL : public IRenderSystem
{
public:

	virtual ITriangleAPI* GetTriAPI() override;
};