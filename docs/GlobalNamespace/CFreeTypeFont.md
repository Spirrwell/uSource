# class CFreeTypeFont

*Defined at line 44 of ./mainui/font/FreeTypeFont.h*

Inherits from CBaseFont



## Members

CUtlRBTree m_ABCCache

private FT_Face face

private char [4096] m_szRealFontFile



## Functions

### CFreeTypeFont

*public void CFreeTypeFont()*

*Defined at line 29 of ./mainui/font/FreeTypeFont.cpp*

### ~CFreeTypeFont

*public void ~CFreeTypeFont()*

*Defined at line 35 of ./mainui/font/FreeTypeFont.cpp*

### Create

*public _Bool Create(const char * name, int tall, int weight, int blur, float brighten, int outlineSize, int scanlineOffset, float scanlineScale, int flags)*

*Defined at line 128 of ./mainui/font/FreeTypeFont.cpp*

### GetCharRGBA

*public void GetCharRGBA(int ch, Point pt, Size sz, unsigned char * rgba, struct Size & drawSize)*

*Defined at line 164 of ./mainui/font/FreeTypeFont.cpp*

### GetCharABCWidths

*public void GetCharABCWidths(int ch, int & a, int & b, int & c)*

*Defined at line 237 of ./mainui/font/FreeTypeFont.cpp*

### HasChar

*public _Bool HasChar(int ch)*

*Defined at line 287 of ./mainui/font/FreeTypeFont.cpp*

### FindFontDataFile

*private _Bool FindFontDataFile(const char * name, int tall, int weight, int flags, char * dataFile, int dataFileChars)*

*Defined at line 91 of ./mainui/font/FreeTypeFont.cpp*



