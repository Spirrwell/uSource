# class CFontManager

*Defined at line 28 of ./mainui/font/FontManager.h*

 Font manager is used for creating and operating with fonts



## Members

CUtlVector m_Fonts



## Functions

### CFontManager

*public void CFontManager()*

*Defined at line 44 of ./mainui/font/FontManager.cpp*

### ~CFontManager

*public void ~CFontManager()*

*Defined at line 52 of ./mainui/font/FontManager.cpp*

### VidInit

*public void VidInit()*

*Defined at line 61 of ./mainui/font/FontManager.cpp*

### DeleteAllFonts

*public void DeleteAllFonts()*

*Defined at line 132 of ./mainui/font/FontManager.cpp*

### DeleteFont

*public void DeleteFont(HFont hFont)*

*Defined at line 141 of ./mainui/font/FontManager.cpp*

### GetFontByName

*public HFont GetFontByName(const char * name)*

*Defined at line 192 of ./mainui/font/FontManager.cpp*

### GetCharABCWide

*public void GetCharABCWide(HFont font, int ch, int & a, int & b, int & c)*

*Defined at line 167 of ./mainui/font/FontManager.cpp*

### GetFontTall

*public int GetFontTall(HFont font)*

*Defined at line 202 of ./mainui/font/FontManager.cpp*

### GetFontAscent

*public int GetFontAscent(HFont font)*

*Defined at line 210 of ./mainui/font/FontManager.cpp*

### GetFontUnderlined

*public _Bool GetFontUnderlined(HFont font)*

*Defined at line 218 of ./mainui/font/FontManager.cpp*

### GetCharacterWidthScaled

*public int GetCharacterWidthScaled(HFont font, int ch, int charH)*

*Defined at line 183 of ./mainui/font/FontManager.cpp*

### GetTextSize

*public void GetTextSize(HFont font, const char * text, int * wide, int * tall, int size)*

*Defined at line 226 of ./mainui/font/FontManager.cpp*

### GetTextHeight

*public int GetTextHeight(HFont font, const char * text, int size)*

*Defined at line 406 of ./mainui/font/FontManager.cpp*

 simplified version, counts only newlines

### GetTextHeightExt

*public int GetTextHeightExt(HFont font, const char * text, int height, int visibleWidth, int size)*

*Defined at line 429 of ./mainui/font/FontManager.cpp*

### CutText

*public int CutText(HFont fontHandle, const char * text, int height, int visibleSize, _Bool reverse, _Bool stopAtWhitespace, int * width, _Bool * remaining)*

*Defined at line 282 of ./mainui/font/FontManager.cpp*

 Determine how text should be cut, to fit in "visibleWidth" NOTE: this function DOES NOT work with multi-line strings

 If reverse is set, return value will indicate starting index, because ending index is always at string index If reverse is NOT set, return value will indicate ending index, because starting index is always at 0

### GetTextWideScaled

*public int GetTextWideScaled(HFont font, const char * text, const int height, int size)*

*Defined at line 454 of ./mainui/font/FontManager.cpp*

### DrawCharacter

*public int DrawCharacter(HFont font, int ch, Point pt, int charH, const unsigned int color, _Bool forceAdditive)*

*Defined at line 484 of ./mainui/font/FontManager.cpp*

### DebugDraw

*public void DebugDraw(HFont font)*

*Defined at line 494 of ./mainui/font/FontManager.cpp*

### GetIFontFromHandle

*public class CBaseFont * GetIFontFromHandle(HFont font)*

*Defined at line 152 of ./mainui/font/FontManager.cpp*

### GetEllipsisWide

*public int GetEllipsisWide(HFont font)*

*Defined at line 160 of ./mainui/font/FontManager.cpp*

### GetCharacterWidth

*private int GetCharacterWidth(HFont font, int ch)*

*Defined at line 176 of ./mainui/font/FontManager.cpp*

### GetTextWide

*private int GetTextWide(HFont font, const char * text, int size)*

*Defined at line 397 of ./mainui/font/FontManager.cpp*

### UploadTextureForFont

*private void UploadTextureForFont(class CBaseFont * font)*

*Defined at line 469 of ./mainui/font/FontManager.cpp*



