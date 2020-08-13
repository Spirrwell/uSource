#pragma once

#include "mathlib/mathlib.h"

enum class ETextureFormat
{
	RGB888 = 0,
	RGB161616,
	RGBA8888,
	RGBA16161616,
	GRAY16, /* 16 bits per pixel grayscale */
	GRAY8,	/* 8 bits per pixel grayscale */
	DXT1,
	DXT5,
	ATI2N,
	ATI1N,
};

enum ETextureFlags
{
	TEXFLAGS_NONE	       = 0,
	TEXFLAGS_RENDERBUFFER  = 0b0001, /* This flag indicates that this is a backbuffer */
	TEXFLAGS_DEPTH	       = 0b0011, /* the texture is a depth buffer */
	TEXFLAGS_STENCIL       = 0b0101, /* The texture is a stencil buffer */
	TEXFLAGS_CUBEMAP       = 0b000000001000,
	TEXFLAGS_CUBEMAP_POS_X = 0b000000011000,
	TEXFLAGS_CUBEMAP_NEG_X = 0b000000101000,
	TEXFLAGS_CUBEMAP_POS_Y = 0b000001001000,
	TEXFLAGS_CUBEMAP_NEG_Y = 0b000010001000,
	TEXFLAGS_CUBEMAP_POS_Z = 0b000100001000,
	TEXFLAGS_CUBEMAP_NEG_Z = 0b001000001000,
};

enum class ETextureDimension
{
	S = 0, // x
	T,     // y
	R,     // z
	MAX_DIMENSIONS
};

enum class ETextureWrapFlags
{
	WRAP_CLAMP_EDGE = 0,
	WRAP_CLAMP_BORDER,
	WRAP_REPEAT,
	WRAP_MIRROR_REPEAT,
	MAX_WRAP_FLAGS,
};

enum class ETextureFiltering
{
	BILINEAR,
	TRILINEAR,
};

class ITexture
{
public:
	virtual ETextureFlags Flags() const = 0;

	virtual ETextureFormat GetFormat() const = 0;

	virtual ITexture* Convert(ETextureFormat fmt) = 0;

	virtual void ConvertInPlace(ETextureFormat fmt) = 0;

	/* Returns the width/height of the render target or texture */
	virtual int Width() const  = 0;
	virtual int Height() const = 0;

	/**
	 * Sets the internal data of this ITexture to the data of buffer.
	 * buffer must be in a simple RGB or RGBA format, and not compressed. If you wish to use a compressed format
	 * use LoadFromCompressedImage
	 */
	virtual void LoadFromImage(int w, int h, ETextureFormat fmt, void* buffer)	     = 0;
	virtual void LoadFromCompressedImage(int w, int h, ETextureFormat fmt, void* buffer) = 0;

	/* Copies the internal data of this texture to an output buffer */
	/* Note: The texture output format must be a simple RGB, RGBA or Grayscale format. No copying into compressed buffers */
	/* the mip param only applies to textures. */
	virtual void CopyToBuffer(void* dst, ETextureFormat dstfmt, int mip = 0) = 0;

	/* Generates mips on this texture if it's not a render target */
	virtual void GenerateMips(int levels = 1) = 0;

	/* Checks if this texture is a normal texture or a render target */
	virtual bool IsTexture() const	    = 0;
	virtual bool IsRenderTarget() const = 0;

	virtual void SetTextureWrapParams(ETextureDimension dim, ETextureWrapFlags flags) = 0;
	virtual void SetTextureFiltering(ETextureFiltering filtering)			  = 0;
};

enum class EMaterialParamType
{
	FLOAT = 0,
	INT,
	VEC3,
	VEC2,
	VEC4,
	TEXTURE,
};

struct material_param_t
{
	char*		   key;
	EMaterialParamType type;
	union
	{
		float	  _float;
		int	  _int;
		vec3_t	  _vec3;
		vec2_t	  _vec2;
		vec4_t	  _vec4;
		ITexture* _texval;
	} value;
};

class IMaterial
{
public:
	virtual const char* GetName() const = 0;

	virtual int AddTexture(ITexture* tex) = 0;

	virtual void AddParam(const material_param_t& param) = 0;

	virtual material_param_t& GetParam(const char* name) const = 0;

	virtual void RemoveTexture(ITexture* tex) = 0;

	virtual void RemoveTexture(int texindex) = 0;

	virtual IMaterial* Copy() const = 0;
};

/* Returns the size of one pixel of the specified format */
static inline unsigned long long GetFormatSize(ETextureFormat fmt)
{
	static unsigned long long size_mapping[] = {
		3, /* RGB888 */
		6, /* RGB161616 */
		4, /* RGBA8888 */
		8, /* RGBA16161616 */
		2, /* 16bit grayscale */
		1, /* 8bit grayscale */

	};
	return 0;
}