# class CBitmapFont

*Defined at line 21 of ./mainui/font/BitmapFont.h*

Inherits from CBaseFont



## Members

private HIMAGE hImage

private int iImageWidth

private int iImageHeight



## Functions

### CBitmapFont

*public void CBitmapFont()*

*Defined at line 20 of ./mainui/font/BitmapFont.cpp*

### ~CBitmapFont

*public void ~CBitmapFont()*

*Defined at line 21 of ./mainui/font/BitmapFont.cpp*

### Create

*public _Bool Create(const char * name, int tall, int weight, int blur, float brighten, int outlineSize, int scanlineOffset, float scanlineScale, int flags)*

*Defined at line 30 of ./mainui/font/BitmapFont.cpp*

### GetCharRGBA

*public void GetCharRGBA(int ch, Point pt, Size sz, byte * rgba, struct Size & drawSize)*

*Defined at line 63 of ./mainui/font/BitmapFont.cpp*

### GetCharABCWidths

*public void GetCharABCWidths(int ch, int & a, int & b, int & c)*

*Defined at line 69 of ./mainui/font/BitmapFont.cpp*

### HasChar

*public _Bool HasChar(int ch)*

*Defined at line 81 of ./mainui/font/BitmapFont.cpp*

### UploadGlyphsForRanges

*public void UploadGlyphsForRanges(struct charRange_t * range, int rangeSize)*

*Defined at line 89 of ./mainui/font/BitmapFont.cpp*

### DrawCharacter

*public int DrawCharacter(int ch, Point pt, int charH, const unsigned int color, _Bool forceAdditive)*

*Defined at line 95 of ./mainui/font/BitmapFont.cpp*



