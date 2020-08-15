#pragma once

#include "rendersystem/imaterial.h"
#include <GL/glew.h>

class CTexture_GL : public ITexture
{
public:
	ETextureFlags m_flags;
	ETextureFormat m_format;
	GLuint m_renderBuffer;
	GLuint m_texture;
	GLenum m_internalFormat;
	int m_width;
	int m_height;
	int m_mipLevels;
	void* m_data;

	CTexture_GL(int w, int h, ETextureFlags flags, ETextureFormat fmt);
	~CTexture_GL();

	static CTexture_GL* Create(int w, int h, ETextureFlags,ETextureFormat);

	virtual ETextureFlags Flags() const;
	virtual ETextureFormat GetFormat() const;
	virtual ITexture* Convert(ETextureFormat fmt);
	virtual void ConvertInPlace(ETextureFormat fmt);
	virtual void CopyToBuffer(void* buf, ETextureFormat fmt, int mip = 0);
	virtual int Height() const { return m_height; }
	virtual int Width() const { return m_width; }
	virtual void LoadFromImage(int w, int h, ETextureFormat fmt, void* buffer);
	virtual void LoadFromCompressedImage(int w, int h, ETextureFormat fmt, void* buffer);
	virtual void GenerateMips(int level = 1);
	virtual bool IsTexture() const { return m_texture != 0; };
	virtual bool IsRenderTarget() const { return m_renderBuffer != 0; };
	virtual void SetTextureWrapParams(ETextureDimension dim, ETextureWrapFlags flags);
};