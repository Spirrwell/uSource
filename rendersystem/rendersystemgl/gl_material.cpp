/*
 *
 * gl_material.cpp - Material and texture implementation for OpenGL
 *
 */
#include <GL/glew.h>

#include "rendersystemgl.h"
#include "rendersystem/imaterial.h"
#include "gl_material.h"
#include "tier1/dbg.h"

BEGIN_RENDERSYSTEM_NAMESPACE

CTexture_GL* CTexture_GL::Create(int w, int h, ETextureFlags flags, ETextureFormat fmt)
{
	return nullptr;
}

static void GetGLTexFormat(ETextureFormat fmt, GLenum& outfmt, GLenum& outpixdat)
{
	switch(fmt)
	{
		case ETextureFormat::RGB888:
			outpixdat = GL_UNSIGNED_BYTE;
			outfmt = GL_RGB;
		case ETextureFormat::RGB161616:
			outpixdat = GL_UNSIGNED_SHORT;
			outfmt = GL_RGB;
		case ETextureFormat::RGBA8888:
			outpixdat = GL_UNSIGNED_BYTE;
			outfmt = GL_RGBA;
		case ETextureFormat::RGBA16161616:
			outpixdat = GL_UNSIGNED_SHORT;
			outfmt = GL_RGBA;
		default:
			outfmt = GL_RGBA;
			outpixdat = GL_UNSIGNED_SHORT;
	}
}

static void GetGLOutputTexFormat(ETextureFormat fmt, GLenum& outfmt, GLenum& outpixdat)
{
	switch(fmt)
	{
		case ETextureFormat::RGB888:
			outpixdat = GL_UNSIGNED_BYTE;
			outfmt = GL_RGB_INTEGER;
		case ETextureFormat::RGB161616:
			outpixdat = GL_UNSIGNED_SHORT;
			outfmt = GL_RGB_INTEGER;
		case ETextureFormat::RGBA8888:
			outpixdat = GL_UNSIGNED_BYTE;
			outfmt = GL_RGBA_INTEGER;
		case ETextureFormat::RGBA16161616:
			outpixdat = GL_UNSIGNED_SHORT;
			outfmt = GL_RGBA_INTEGER;
		case ETextureFormat::GRAY8:
			outpixdat = GL_UNSIGNED_BYTE;
			outfmt = GL_DEPTH_COMPONENT;
		case ETextureFormat::GRAY16:
			outpixdat = GL_UNSIGNED_SHORT;
			outfmt = GL_DEPTH_COMPONENT;
		default:
			outfmt = GL_RGBA;
			outpixdat = GL_UNSIGNED_SHORT;
	}
}

//=============================================================================================================================================//
// CTexture_GL
CTexture_GL::CTexture_GL(int w, int h, ETextureFlags flags, ETextureFormat fmt) :
	m_flags(TEXFLAGS_NONE),
	m_renderBuffer(0),
	m_format(fmt),
	m_width(w),
	m_height(h),
	m_data(nullptr),
	m_texture(0)
{
	/* TODO: Add support for ATI2N and ATI1N formats */
	static GLenum renderbuffer_storage_map[] = {
		GL_RGB8,
		GL_RGB16,
		GL_RGBA8,
		GL_RGBA8,
		GL_DEPTH_COMPONENT,
		GL_DEPTH_COMPONENT16,
		GL_COMPRESSED_RGB_S3TC_DXT1_EXT,
		GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,
		0,
		0,
	};

	static GLenum texture_format_map[] = {
		GL_RGB,
		GL_RGB,
		GL_RGBA,
		GL_RGBA,
		GL_RED,
		GL_RED,
		GL_RGBA,
		GL_RGBA,
	};

	if(flags & TEXFLAGS_RENDERBUFFER)
	{
		glGenRenderbuffers(1, &m_renderBuffer);
		glBindRenderbuffer(GL_RENDERBUFFER, m_renderBuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, renderbuffer_storage_map[(int)fmt], w, h);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
	}
	else
	{
		glGenTextures(1, &m_texture);
	}
	m_internalFormat = renderbuffer_storage_map[(int)fmt];
}

CTexture_GL::~CTexture_GL()
{
	if(m_renderBuffer != 0)
		glDeleteRenderbuffers(1, &m_renderBuffer);
}

ETextureFlags CTexture_GL::Flags() const
{
	return TEXFLAGS_STENCIL;
}

ETextureFormat CTexture_GL::GetFormat() const
{
	return ETextureFormat::RGB888;
}

ITexture *CTexture_GL::Convert(ETextureFormat fmt)
{
	return nullptr;
}

void CTexture_GL::ConvertInPlace(ETextureFormat fmt)
{

}

void CTexture_GL::LoadFromImage(int w, int h, ETextureFormat fmt, void *buffer)
{
	Assert(buffer);
	if(m_renderBuffer) return;


	GLenum format, pixdata;
	GetGLTexFormat(fmt, format, pixdata);

	glBindTexture(GL_TEXTURE_2D, m_texture);
	glTexImage2D(m_texture, 0, m_internalFormat, w, h, 0, format, pixdata, buffer);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void CTexture_GL::LoadFromCompressedImage(int w, int h, ETextureFormat fmt, void *buffer)
{
	Assert(buffer);
}

void CTexture_GL::CopyToBuffer(void *buf, ETextureFormat fmt, int mip)
{
	Assert(buf);

	if(m_texture)
	{
		GLenum pixfmt, format;
		GetGLOutputTexFormat(fmt, format, pixfmt);
		glBindBuffer(GL_TEXTURE_2D, m_texture);
		glGetTexImage(GL_TEXTURE_2D, mip, format, pixfmt, buf);
		glBindBuffer(GL_TEXTURE_2D, 0);
	}
	else
	{
		// TODO: Support copying of renderbuffers
	}
}

void CTexture_GL::GenerateMips(int level)
{
	Assert(level >= 0);
	if(m_renderBuffer) return;
	m_mipLevels = level;
	glGenerateMipmap(m_texture);
}

void CTexture_GL::SetTextureWrapParams(ETextureDimension dim, ETextureWrapFlags flags)
{
	if(!m_texture) return;
	Assert((int)dim < (int)ETextureDimension::MAX_DIMENSIONS);
	Assert((int)flags < (int)ETextureWrapFlags::MAX_WRAP_FLAGS);

	static GLenum tex_dim_map[] = {
		GL_TEXTURE_WRAP_S,
		GL_TEXTURE_WRAP_T,
		GL_TEXTURE_WRAP_R,
	};

	static GLenum tex_flag_map[] = {
		GL_CLAMP_TO_EDGE,
		GL_CLAMP_TO_BORDER,
		GL_REPEAT,
		GL_MIRRORED_REPEAT,
	};

	glTexParameteri(m_texture, tex_dim_map[(int)dim], tex_flag_map[(int)flags]);
}

//=============================================================================================================================================//

END_RENDERSYSTEM_NAMESPACE