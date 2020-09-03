# class CBMP

*Defined at line 54 of ./mainui/BMPUtils.h*

## Members

private byte * data



## Functions

### LoadFile

*public class CBMP * LoadFile(const char * filename)*

*Defined at line 384 of ./mainui/Utils.cpp*

void *operator new( size_t a ){	return MALLOC( a );}

void *operator new[]( size_t a ){	return MALLOC( a );}

void operator delete( void *ptr ){	if( ptr ) FREE( ptr );}

void operator delete[]( void *ptr ){	if( ptr ) FREE( ptr );}

### CBMP

*public void CBMP(uint w, uint h)*

*Defined at line 59 of ./mainui/BMPUtils.h*

### ~CBMP

*public void ~CBMP()*

*Defined at line 89 of ./mainui/BMPUtils.h*

### Increase

*public void Increase(uint w, uint h)*

*Defined at line 91 of ./mainui/BMPUtils.h*

### RemapLogo

*public void RemapLogo(int r, int g, int b)*

*Defined at line 130 of ./mainui/BMPUtils.h*

### GetBitmap

*public byte * GetBitmap()*

*Defined at line 149 of ./mainui/BMPUtils.h*

### GetBitmapHdr

*public struct bmp_t * GetBitmapHdr()*

*Defined at line 154 of ./mainui/BMPUtils.h*

### GetTextureData

*public byte * GetTextureData()*

*Defined at line 159 of ./mainui/BMPUtils.h*

### GetTextureDataSize

*public uint GetTextureDataSize()*

*Defined at line 164 of ./mainui/BMPUtils.h*

### GetPaletteData

*public struct rgbquad_t * GetPaletteData()*

*Defined at line 169 of ./mainui/BMPUtils.h*



