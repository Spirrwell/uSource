# class IGuiInterface

*Defined at line 22 of ./engine/gui_int.h*

Inherits from IAppInterface



## Functions

### RegisterFont

*public int RegisterFont(const char * name, int size_tall, int weight, int outline, int blur, float brighten, _Bool italic, _Bool underline, _Bool bold, _Bool strike)*

### DrawString

*public int DrawString(int font, int x, int y, int w, int h, const char * str, int r, int g, int b, int a, int charH, unsigned int intjustify, unsigned int flags)*

### DrawPic

*public void DrawPic(int x, int y, int w, int h, int r, int g, int b, int a, const char * pic, enum EGuiRenderMode mode)*

### FillRect

*public void FillRect(int x, int y, int w, int h, int r, int g, int b, int a, int corner_radius)*

### FillCircle

*public void FillCircle(int x, int y, int w, int h, int r, int g, int b, int a)*

### GetScreenSize

*public void GetScreenSize(int & w, int & h)*



