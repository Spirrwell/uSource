# class ITexture

*Defined at line 59 of ./rendersystem/imaterial.h*

## Functions

### Flags

*public enum rendersystem::ETextureFlags Flags()*

### GetFormat

*public enum rendersystem::ETextureFormat GetFormat()*



**brief** Returns the texture format of this texture

**return**

### Convert

*public class rendersystem::ITexture * Convert(enum rendersystem::ETextureFormat fmt)*

 Converts the texture to this format. Does not modify the texture object. Instead it creates a new one

**fmt**

**return** Pointer to a new texture

### ConvertInPlace

*public void ConvertInPlace(enum rendersystem::ETextureFormat fmt)*

 Converts the texture to a new format, in place.

**fmt**

### Width

*public int Width()*

 Returns the width/height of the render target or texture 

### Height

*public int Height()*

### LoadFromImage

*public void LoadFromImage(int w, int h, enum rendersystem::ETextureFormat fmt, void * buffer)*

 Loads the texture from an image with the specified format. If you're trying to use a compressed format, such as DXT5, use LoadFromCompressedImage

**w**

**h**

**fmt**

**buffer**

### LoadFromCompressedImage

*public void LoadFromCompressedImage(int w, int h, enum rendersystem::ETextureFormat fmt, void * buffer)*

### CopyToBuffer

*public void CopyToBuffer(void * dst, enum rendersystem::ETextureFormat dstfmt, int mip)*

 Copies the internal data of this texture to an output buffer 

 Note: The texture output format must be a simple RGB, RGBA or Grayscale format. No copying into compressed buffers 

 the mip param only applies to textures. 

 Copies the internal data of this texture into a destination buffer with the specified format You cannot copy into a compressed buffer

**dst**

**dstfmt**

**mip**

### GenerateMips

*public void GenerateMips(int levels)*

 Generates mips on this target. Will NOT work if this is a rendertarget

**levels**

### IsTexture

*public _Bool IsTexture()*

 Returns if this is a texture

**return**

### IsRenderTarget

*public _Bool IsRenderTarget()*

 Returns if this is a rendertarget

**return**

### SetTextureWrapParams

*public void SetTextureWrapParams(enum rendersystem::ETextureDimension dim, enum rendersystem::ETextureWrapFlags flags)*

 Sets the texture wrapping flags

**dim**

**flags**

### SetTextureFiltering

*public void SetTextureFiltering(enum rendersystem::ETextureFiltering filtering)*

 Sets the filtering type on this texture

**filtering**



