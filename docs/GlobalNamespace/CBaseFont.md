# class CBaseFont

*Defined at line 36 of ./mainui/font/BaseFontBackend.h*

## Members

protected char [32] m_szName

protected int m_iTall

protected int m_iWeight

protected int m_iFlags

protected int m_iHeight

protected int m_iMaxCharWidth

protected int m_iAscent

protected _Bool m_bAdditive

protected int m_iBlur

protected float m_fBrighten

protected int m_iScanlineOffset

protected float m_fScanlineScale

protected int m_iOutlineSize

protected int m_iEllipsisWide

CUtlRBTree m_glyphs



## Records

glyph_t



## Functions

### CBaseFont

*public void CBaseFont()*

*Defined at line 20 of ./mainui/font/BaseFontBackend.cpp*

### ~CBaseFont

*public void ~CBaseFont()*

*Defined at line 226 of ./mainui/font/BaseFontBackend.cpp*

### Create

*public _Bool Create(const char * name, int tall, int weight, int blur, float brighten, int outlineSize, int scanlineOffset, float scanlineScale, int flags)*

### GetCharRGBA

*public void GetCharRGBA(int ch, Point pt, Size sz, byte * rgba, struct Size & drawSize)*

### GetCharABCWidths

*public void GetCharABCWidths(int ch, int & a, int & b, int & c)*

### HasChar

*public _Bool HasChar(int ch)*

### UploadGlyphsForRanges

*public void UploadGlyphsForRanges(struct charRange_t * range, int rangeSize)*

*Defined at line 76 of ./mainui/font/BaseFontBackend.cpp*

### DrawCharacter

*public int DrawCharacter(int ch, Point pt, int charH, const unsigned int color, _Bool forceAdditive)*

*Defined at line 446 of ./mainui/font/BaseFontBackend.cpp*

### GetHeight

*public int GetHeight()*

*Defined at line 55 of ./mainui/font/BaseFontBackend.h*

### GetTall

*public int GetTall()*

*Defined at line 56 of ./mainui/font/BaseFontBackend.h*

### GetName

*public const char * GetName()*

*Defined at line 57 of ./mainui/font/BaseFontBackend.h*

### GetAscent

*public int GetAscent()*

*Defined at line 58 of ./mainui/font/BaseFontBackend.h*

### GetMaxCharWidth

*public int GetMaxCharWidth()*

*Defined at line 59 of ./mainui/font/BaseFontBackend.h*

### GetFlags

*public int GetFlags()*

*Defined at line 60 of ./mainui/font/BaseFontBackend.h*

### GetWeight

*public int GetWeight()*

*Defined at line 61 of ./mainui/font/BaseFontBackend.h*

### GetEfxOffset

*public int GetEfxOffset()*

*Defined at line 62 of ./mainui/font/BaseFontBackend.h*

### IsEqualTo

*public _Bool IsEqualTo(const char * name, int tall, int weight, int blur, int flags)*

*Defined at line 233 of ./mainui/font/BaseFontBackend.cpp*

### DebugDraw

*public void DebugDraw()*

*Defined at line 253 of ./mainui/font/BaseFontBackend.cpp*

### GetTextureName

*public void GetTextureName(char * dst, size_t len)*

*Defined at line 38 of ./mainui/font/BaseFontBackend.cpp*

=========================CBaseFont::GetTextureName

Mangle texture name, so using same font names with different attributes will not confuse engine or font renderer=========================+

### GetEllipsisWide

*public int GetEllipsisWide()*

*Defined at line 73 of ./mainui/font/BaseFontBackend.h*

### ApplyBlur

*protected void ApplyBlur(Size rgbaSz, byte * rgba)*

*Defined at line 304 of ./mainui/font/BaseFontBackend.cpp*

### ApplyOutline

*protected void ApplyOutline(Point pt, Size rgbaSz, byte * rgba)*

*Defined at line 368 of ./mainui/font/BaseFontBackend.cpp*

### ApplyScanline

*protected void ApplyScanline(Size rgbaSz, byte * rgba)*

*Defined at line 410 of ./mainui/font/BaseFontBackend.cpp*

### ApplyStrikeout

*protected void ApplyStrikeout(Size rgbaSz, byte * rgba)*

*Defined at line 430 of ./mainui/font/BaseFontBackend.cpp*

### GetBlurValueForPixel

*private void GetBlurValueForPixel(float * distribution, byte * src, Point srcPt, Size srcSz, byte * dest)*

*Defined at line 341 of ./mainui/font/BaseFontBackend.cpp*



