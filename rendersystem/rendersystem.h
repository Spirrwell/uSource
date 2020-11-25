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

class IRenderSystem;
class IRenderDevice;

struct RenderWindow_t
{
	int w, h;
	int x, y;
	int bpp;
	int refreshRate;
	/* When SDL2 is enabled, this is assumed to point to a SDL_Window structure */
	/* For Windows when SDL2 is DISABLED, the type is actually HWND */
	void* windowHandle;
};

struct RenderParams_t
{
	/* This can also be an empty array if you want this to be headless */
	List<RenderWindow_t> windows;
};

/**
 * Enum containing features that can be supported by each individual render API
 */
enum class ERenderDeviceFeatures
{
	/**
	 * If set, the render API implementation will support dynamic meshes, or meshes that can be modified in host memory
	 */
	SUPPORTS_DYNAMIC_MESH   = 1,

	/**
	 * If set, the render API implementation will support tesselation and tesselation shaders
	 */
	SUPPORTS_TESSELATION    = 2,

	/**
	 * If set, the render API supports geometry shaders
	 */
	SUPPORTS_GEOM_SHADERS   = 4,

	/*
	 * If set, the render API supports dxt5 compression
	 */
	SUPPORTS_DXT5_COMPRESSION       = 8,

	/* DXT1 compression */
	SUPPORTS_DXT1_COMPRESSION       = 16,

	/* ATI2N */
	SUPPORTS_ATI2N_COMPRESSION      = 32,

	/* Is the render API fixed-function? e.g. OpenGL1 or DirectX 7 */
	IS_FIXED_FUNCTION       = 64,

	/* If set, the render device can be accessed from multiple threads */
	THREAD_SAFE     = 128,
};

enum class EGraphicsAPI
{
	OPENGL          = 1,
	OPENGLES        = 2,
	OPENGLSC        = 4,
	GCM             = 8,
	GXM             = 16,
	GNM             = 32,
	MANTLE          = 64,
	PSGL            = 128,
	RENDERWARE      = 256,
	VULKAN          = 512,
	METAL           = 1024,
	DIRECTX         = 2048,
	SOFTWARE        = 4092,
	GRAPHICSAPI_LAST,
};


struct RenderAPIInfo_t
{
	EGraphicsAPI api; // This can also be a composition, meaning an OR of EGraphicsAPI objects.
	int versionMajor, versionMinor, versionPatch; // For DX, major will be like 9, 10, 11, 12.
};


struct RenderDeviceInfo_t
{
	char vendor[128]; // Vendor name
	char device[128]; // Device name
	char driver[128]; // Driver name and version
	ERenderDeviceFeatures features;
	RenderAPIInfo_t apiInfo;
};

enum class EShaderFace
{
	FRONT,
	BACK
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

struct ShaderStencilState_t
{
	EShaderStencilOp stencilFailOp;     /* Stencil Fail Op */
	EShaderStencilOp depthFailOp;       /* Stencil passed, depth failed op */
	EShaderStencilOp passOp;            /* Both pass operation */
	EShaderStencilFunc stencilFunc;         /* Stencil function */
	int reference;                          /* Reference value for stencil test */
	unsigned int mask;                      /* Mask ANDed with ref value */
};

struct ShaderBlendState_t
{
	EShaderBlendEq rgbBlendEq;
	EShaderBlendEq alphaBlendEq;
	EShaderBlendFunc rgbBlendFuncSrc;
	EShaderBlendFunc rgbBlendFuncDest;
	EShaderBlendFunc alphaBlendFuncSrc;
	EShaderBlendFunc alphaBlendFuncDest;
};

struct ShaderDepthState_t
{
	bool enableDepthWrite;
	EShaderDepthFunc depthFunc;
};

/* You must implement this in your own backend */
class IRenderSystem
{
public:
	virtual void Init() = 0;
	virtual void Shutdown() = 0;

	/* Render Device Mangement */

	/**
	 * @brief Sets the requested rendering API. If not set, NumRenderDevices will be populated with all supported graphics APIs and versions.
	 * There should only be ONE requested API. Although the apiInfo struct can contain multiple APIs (as a bitwise composition), do NOT do that.
	 * @param apiInfo
	 */
	virtual void SetRequestedAPI(RenderAPIInfo_t apiInfo) = 0;

	/**
	 * @brief Returns the number of supported rendering devices
	 * @return
	 */
	virtual int NumRenderDevices() = 0;

	/**
	 * Returns device info about the render device with the specified index
	 * @param index
	 * @return
	 */
	virtual RenderDeviceInfo_t DeviceInfo(int index) = 0;

	/**
	 * @brief Creates a new render device. Max index is returned by NumRenderDevices
	 * @param index Index of the device
	 * @return New render device
	 */
	virtual IRenderDevice* CreateRenderDevice(int index) = 0;

	/**
	 * @brief Destroys a render device
	 * @param dev
	 */
	virtual void DestroyRenderDevice(IRenderDevice* dev) = 0;

};

/* An abstract rendering device */
/* Corresponds to a GPU generally */
class IRenderDevice
{
public:

	/* Basic device query */
	virtual bool EnableFeatures(unsigned int features) = 0;         // features is a bitwise composition of ERenderDeviceFeatures
	virtual bool DisableFeatures(unsigned int features) = 0;
	virtual ERenderDeviceFeatures EnabledFeatures() const = 0;
	virtual ERenderDeviceFeatures AvailableFeatures() const = 0;


	/* API Accessors */
	virtual class ITriangleAPI* GetTriAPI() = 0;

	//
	// STATE MANAGMENT
	//

	virtual void SetRenderParams(const RenderParams_t& params) = 0;


	/* Shader stencil test stuff */
	virtual void EnableStencilTest(bool enable = true) = 0;
	virtual void SetStencilState(EShaderFace face, ShaderStencilState_t func) = 0;
	virtual ShaderBlendState_t GetStencilState(EShaderFace face) = 0;

	/* Shader blend stuff */
	virtual void EnableBlending(bool enable = true) = 0;
	virtual void SetBlendState(ShaderBlendState_t state) = 0;
	virtual ShaderBlendState_t GetBlendState() = 0;

	/* Depth stuff */
	virtual void EnableDepthTest(bool enable = true) = 0;
	virtual void SetDepthState(ShaderDepthState_t state) = 0;
	virtual ShaderDepthState_t GetDepthState() = 0;

	//
	// BUFFER AND RENDER TARGET CREATION
	//

	virtual IVertexBuffer* CreateEmptyVertexBuffer(EVertexFormat fmt, EBufferType type) = 0;
	virtual IIndexBuffer* CreateEmptyIndexBuffer(EIndexFormat fmt, EBufferType type) = 0;
	virtual IBuffer* CreateEmptyBuffer(EBufferType type) = 0;
	virtual ITexture* CreateEmptyTexture(ETextureFormat fmt) = 0;

	/* Creates a new image from the rgb data that has been specified */
	/* This won't be using the same buffers as the rgbdata, so you will want to call FreeImage on the rgbdata after this */
	virtual ITexture* CreateTextureFromImage(const void* img) = 0;

	/* Creates a new render target which will reside in shared memory */
	virtual ITexture* CreateRenderTarget(const char* name, ETextureFormat fmt, int width, int height, int flags) = 0;

	//
	// SHADER PROGRAMS AND MANAGEMENT
	//

	/* Creates a new shader program */
	virtual IShaderProgram* CreateProgram(const char* name) = 0;

	/* Creates new shaders */
	virtual IGeomShader* CreateGeometryShader() = 0;
	virtual IVertexShader* CreateVertexShader() = 0;
	virtual IFragShader* CreateFragShader() = 0;
	virtual IShaderProgram* CreateShaderProgram(const char* name) = 0;
};

/* This is the only function you must implement within your backend implementation */
/* Internally you'll need to implement the Ixxxx classes, but those implementations should not be exposed */
IRenderSystem* CreateRenderSystem();

END_RENDERSYSTEM_NAMESPACE