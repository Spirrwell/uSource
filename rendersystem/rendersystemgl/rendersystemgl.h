#pragma once

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
	virtual void Init(const render_params_t& params) override;
	virtual void Shutdown() override;

	virtual void OnParamsChanged(const render_params_t& params) override;

	virtual IVertexBuffer* CreateEmptyVertexBuffer(EVertexFormat fmt, EBufferType type) override;
	virtual IIndexBuffer* CreateEmptyIndexBuffer(EIndexFormat fmt, EBufferType type) override;
	virtual IBuffer* CreateEmptyBuffer(EBufferType type) override;
	virtual ITexture* CreateEmptyTexture(ETextureFormat fmt) override;

	/* Creates a new image from the rgb data that has been specified */
	/* This won't be using the same buffers as the rgbdata, so you will want to call FreeImage on the rgbdata after this */
	virtual ITexture* CreateTextureFromImage(const void* img) override;

	/* Creates a new render target which will reside in shared memory */
	virtual ITexture* CreateRenderTarget(const char* name, ETextureFormat fmt, int width, int height, int flags) override;

	/* Creates a new shader program */
	virtual IShaderProgram* CreateProgram(const char* name) override { return nullptr; };

	/* Creates new shaders */
	virtual IGeomShader* CreateGeometryShader() override;
	virtual IVertexShader* CreateVertexShader() override;
	virtual IFragShader* CreateFragShader() override;
	virtual IShaderProgram* CreateShaderProgram(const char* name) override;

	/* API Accessors */
	virtual class ITriangleAPI* GetTriAPI() override;

	virtual void SetDepthFunc(EShaderDepthFunc func) override;
	virtual void SetBlendEquation(EShaderBlendEq func) override;
	virtual void SetBlendFunc(EShaderBlendFunc func) override;
	virtual void SetAlphaFunc(EShaderAlphaFunc func) override;
	virtual void SetStencilFunc(EShaderStencilFunc func) override;
	virtual void SetStencilOp(EShaderStencilOp op) override;

private:
	EShaderDepthFunc m_depthFunc;
	EShaderBlendEq m_blendEquation;
	EShaderBlendFunc m_blendFunc;
	EShaderAlphaFunc m_alphaFunc;
	EShaderStencilFunc m_stencilFunc;
	EShaderStencilOp m_stencilOp;

	int m_stencilRef;
	unsigned int m_stencilMask;
};

namespace GL
{
	unsigned int GetParam(unsigned long param);
}

END_RENDERSYSTEM_NAMESPACE