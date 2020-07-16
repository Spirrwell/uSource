/*
 *
 * gl_material.cpp - Material and texture implementation for OpenGL
 *
 */
#include <GL/glew.h>

#include "rendersystemgl.h"
#include "rendersystem/imaterial.h"

class CTexture_GL : public ITexture
{
public:
	ETextureFlags m_flags;
	ETextureFormat m_format;
	GLuint m_renderBuffer;

	CTexture_GL(ETextureFlags flags, ETextureFormat fmt);
	~CTexture_GL();

	static CTexture_GL* Create(ETextureFlags,ETextureFormat);

	virtual ETextureFlags Flags() const;
	virtual ETextureFormat GetFormat() const;
	virtual ITexture* Convert(ETextureFormat fmt);
	virtual void ConvertInPlace(ETextureFormat fmt);
	virtual void* GetData();
	virtual size_t GetSize() const;
};

CTexture_GL* CTexture_GL::Create(ETextureFlags flags, ETextureFormat fmt)
{
	return new CTexture_GL(flags, fmt);
}
//=============================================================================================================================================//
// CTexture_GL
CTexture_GL::CTexture_GL(ETextureFlags flags, ETextureFormat fmt) :
	m_flags(TEXFLAGS_NONE),
	m_renderBuffer(0),
	m_format(fmt)
{
	if(flags & TEXFLAGS_RENDERBUFFER)
	{
		glGenRenderbuffers(1, &m_renderBuffer);
	}
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

void *CTexture_GL::GetData()
{
	return nullptr;
}

size_t CTexture_GL::GetSize() const
{
	return 0;
}
//=============================================================================================================================================//