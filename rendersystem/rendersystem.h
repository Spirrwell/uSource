/**
 * 
 * rendersystem.h
 * 
 * Rendersystem is an advanced rendering backend for xash3d. It's based off of xash3d's original ref_gl renderer, but with some pretty significant changes.
 * 
 * The rendersystem abstracts graphics API calls in such a way that you can write platform agnostic rendering code
 * quite easily. The goal of this is primarily to ease shader creation and make extending the graphics system much much easier. 
 * 
 */
#pragma once

#include "rendersystem_common.h"

#include "imesh.h"
#include "ishader.h"
#include "ibuffer.h"
#include "imaterial.h"

BEGIN_RENDERSYSTEM_NAMESPACE

struct render_params_t
{
	int width;
	int height;
	int bpp;
	int refresh_rate;
};

/**
 * Enum containing features that can be supported by each individual render API
 */
enum class EShaderAPIFeatures
{
	/**
	 * If set, the render API implementation will support dynamic meshes, or meshes that can be modified in host memory
	 */
	SUPPORTS_DYNAMIC_MESH,

	/**
	 * If set, the render API implementation will support tesselation and tesselation shaders
	 */
	SUPPORTS_TESSELATION,

	/**
	 * If set, the render API supports geometry shaders
	 */
	SUPPORTS_GEOM_SHADERS,

	/*
	 * If set, the render API supports dxt5 compression
	 */
	SUPPORTS_DXT5_COMPRESSION,

	/* DXT1 compression */
	SUPPORTS_DXT1_COMPRESSION,

	/* ATI2N */
	SUPPORTS_ATI2N_COMPRESSION,

	/* Is the render API fixed-function? e.g. OpenGL1 or DirectX 7 */
	IS_FIXED_FUNCTION,
};


enum class EShaderDepthFunc
{
	NEVER = 0,
	NEARER,
	EQUAL,
	NEAREROREQUAL,
	FARTHER,
	NOTEQUAL,
	FARTHEROREQUAL,
	ALWAYS
};

enum class EShaderBlendFunc
{
	ZERO = 0,
	ONE,
	DST_COLOR,
	ONE_MINUS_DST_COLOR,
	SRC_ALPHA,
	ONE_MINUS_SRC_ALPHA,
	DST_ALPHA,
	ONE_MINUS_DST_ALPHA,
	SRC_ALPHA_SATURATE,
	SRC_COLOR,
	ONE_MINUS_SRC_COLOR
};

enum class EShaderBlendEq
{
	ADD = 0,
	SUBTRACT,
	REVSUBTRACT,
	MIN,
	MAX
};

enum class EShaderAlphaFunc
{
	NEVER = 0,
	LESS,
	EQUAL,
	LEQUAL,
	GREATER,
	NOTEQUAL,
	GEQUAL,
	ALWAYS
};

enum class EShaderStencilFunc
{
	NEVER = 0,
	LESS,
	EQUAL,
	LEQUAL,
	GREATER,
	NOTEQUAL,
	GEQUAL,
	ALWAYS
};

enum class EShaderStencilOp
{
	KEEP = 0,
	ZERO,
	SET_TO_REFERENCE,
	INCREMENT_CLAMP,
	DECREMENT_CLAMP,
	INVERT,
	INCREMENT_WRAP,
	DECREMENT_WRAP,
};

/* You must implement this in your own backend */
class IRenderSystem
{
public:
	virtual void Init(const render_params_t& params) = 0;
	virtual void Shutdown() = 0;

	virtual void OnParamsChanged(const render_params_t& params) = 0;

	virtual IVertexBuffer* CreateEmptyVertexBuffer(EVertexFormat fmt, EBufferType type) = 0;
	virtual IIndexBuffer* CreateEmptyIndexBuffer(EIndexFormat fmt, EBufferType type) = 0;
	virtual IBuffer* CreateEmptyBuffer(EBufferType type) = 0;
	virtual ITexture* CreateEmptyTexture(ETextureFormat fmt) = 0;

	/* Creates a new image from the rgb data that has been specified */
	/* This won't be using the same buffers as the rgbdata, so you will want to call FreeImage on the rgbdata after this */
	virtual ITexture* CreateTextureFromImage(const void* img) = 0;

	/* Creates a new render target which will reside in shared memory */
	virtual ITexture* CreateRenderTarget(const char* name, ETextureFormat fmt, int width, int height, int flags) = 0;

	/* Creates a new shader program */
	virtual IShaderProgram* CreateProgram(const char* name) = 0;

	/* Creates new shaders */
	virtual IGeomShader* CreateGeometryShader() = 0;
	virtual IVertexShader* CreateVertexShader() = 0;
	virtual IFragShader* CreateFragShader() = 0;
	virtual IShaderProgram* CreateShaderProgram(const char* name) = 0;

	/* API Accessors */
	virtual class ITriangleAPI* GetTriAPI() = 0;

	virtual void SetDepthFunc(EShaderDepthFunc func) = 0;
	virtual void SetBlendEquation(EShaderBlendEq func) = 0;
	virtual void SetBlendFunc(EShaderBlendFunc func) = 0;
	virtual void SetAlphaFunc(EShaderAlphaFunc func) = 0;
	virtual void SetStencilFunc(EShaderStencilFunc func) = 0;
	virtual void SetStencilOp(EShaderStencilOp op) = 0;
};

/* This is the only function you must implement within your backend implementation */
/* Internally you'll need to implement the Ixxxx classes, but those implementations should not be exposed */
IRenderSystem* CreateRenderSystem();

END_RENDERSYSTEM_NAMESPACE