# class CTexture_GL

*Defined at line 8 of ./rendersystem/rendersystemgl/gl_material.h*

Inherits from ITexture



## Members

public enum rendersystem::ETextureFlags m_flags

public enum rendersystem::ETextureFormat m_format

public GLuint m_renderBuffer

public GLuint m_texture

public GLenum m_internalFormat

public int m_width

public int m_height

public int m_mipLevels

public void * m_data



## Functions

### CTexture_GL

*public void CTexture_GL(int w, int h, enum rendersystem::ETextureFlags flags, enum rendersystem::ETextureFormat fmt)*

*Defined at line 72 of ./rendersystem/rendersystemgl/gl_material.cpp*

=============================================================================================================================================// CTexture_GL

### ~CTexture_GL

*public void ~CTexture_GL()*

*Defined at line 120 of ./rendersystem/rendersystemgl/gl_material.cpp*

### Create

*public class rendersystem::CTexture_GL * Create(int w, int h, enum rendersystem::ETextureFlags , enum rendersystem::ETextureFormat )*

*Defined at line 15 of ./rendersystem/rendersystemgl/gl_material.cpp*

### Flags

*public enum rendersystem::ETextureFlags Flags()*

*Defined at line 126 of ./rendersystem/rendersystemgl/gl_material.cpp*

### GetFormat

*public enum rendersystem::ETextureFormat GetFormat()*

*Defined at line 131 of ./rendersystem/rendersystemgl/gl_material.cpp*

### Convert

*public class rendersystem::ITexture * Convert(enum rendersystem::ETextureFormat fmt)*

*Defined at line 136 of ./rendersystem/rendersystemgl/gl_material.cpp*

### ConvertInPlace

*public void ConvertInPlace(enum rendersystem::ETextureFormat fmt)*

*Defined at line 141 of ./rendersystem/rendersystemgl/gl_material.cpp*

### CopyToBuffer

*public void CopyToBuffer(void * buf, enum rendersystem::ETextureFormat fmt, int mip)*

*Defined at line 165 of ./rendersystem/rendersystemgl/gl_material.cpp*

### Height

*public int Height()*

*Defined at line 31 of ./rendersystem/rendersystemgl/gl_material.h*

### Width

*public int Width()*

*Defined at line 32 of ./rendersystem/rendersystemgl/gl_material.h*

### LoadFromImage

*public void LoadFromImage(int w, int h, enum rendersystem::ETextureFormat fmt, void * buffer)*

*Defined at line 146 of ./rendersystem/rendersystemgl/gl_material.cpp*

### LoadFromCompressedImage

*public void LoadFromCompressedImage(int w, int h, enum rendersystem::ETextureFormat fmt, void * buffer)*

*Defined at line 160 of ./rendersystem/rendersystemgl/gl_material.cpp*

### GenerateMips

*public void GenerateMips(int level)*

*Defined at line 183 of ./rendersystem/rendersystemgl/gl_material.cpp*

### IsTexture

*public _Bool IsTexture()*

*Defined at line 36 of ./rendersystem/rendersystemgl/gl_material.h*

### IsRenderTarget

*public _Bool IsRenderTarget()*

*Defined at line 37 of ./rendersystem/rendersystemgl/gl_material.h*

### SetTextureWrapParams

*public void SetTextureWrapParams(enum rendersystem::ETextureDimension dim, enum rendersystem::ETextureWrapFlags flags)*

*Defined at line 191 of ./rendersystem/rendersystemgl/gl_material.cpp*



