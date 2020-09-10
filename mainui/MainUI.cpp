#include "MainUI.h"
#include "BaseMenu.h"
#include "tier1/dbg.h"

void ui::DrawFilledRect(int x, int y, int w, int h, colorRGBA color)
{
	EngFuncs::FillRGBA(x, y, w, h, color.r, color.g, color.b, color.a);
}

void ui::DrawRect(int x, int y, int w, int h, colorRGBA color, int border_width)
{
	if(border_width <= 0) return;

}

void ui::DrawFilledRectRounded(int x, int y, int w, int h, int corner_radius, colorRGBA color)
{

	// GlobalUI()->FillRect(x, y, w, h, color.r, color.g, color.b, color.a, corner_radius);
}

void ui::DrawFilledCircle(int x, int y, int radius, colorRGBA color)
{

}

void ui::DrawFilledCircle(int x, int y, int w, int h, colorRGBA color)
{
	// GlobalUI()->FillCircle(x, y, w, h, color.r, color.g, color.b, color.a);
}

void ui::DrawCircle(int x, int y, int radius, colorRGBA color)
{

}

void ui::DrawLine(int x1, int y1, int x2, int y2, colorRGBA color, int width)
{

}

void ui::DrawText(ui::Font font, int x, int y, int w, int h, const char *str, colorRGBA color, int charH, ui::ETextJustify justify, unsigned int flags)
{
	// GlobalUI()->DrawText(font, x, y, w, h, str, color, charH, 0, flags);

}

ui::Font ui::RegisterFont(const char *name, int size_tall, int weight, int outline, int blur, float brighten, bool italic,
                          bool underline, bool bold, bool strike)
{
	unsigned int flags = 0;
	flags |= (italic ? FONT_ITALIC : 0);
	flags |= (underline ? FONT_UNDERLINE : 0);
	flags |= (strike ? FONT_STRIKEOUT : 0);
	return CFontBuilder(name, size_tall, weight).SetBlurParams(blur, brighten).SetFlags(flags).Create();
}

ui::Font ui::GetFont(const char *name)
{
	return FindFontByName(name);
}

List<ui::Font> ui::GetFontList()
{
	return List<Font>();
}

void ui::GetScreenSize(int &w, int &h)
{
	w = ScreenWidth;
	h = ScreenHeight;
}

int ui::GetScreenWidth()
{
	return ScreenWidth;
}

int ui::GetScreenHeight()
{
	return ScreenHeight;
}

void ui::DrawTextSize(ui::Font font, const char *str, int &w, int &h)
{
	g_FontMgr->GetTextSize(font, str, &w, &h);
}

ui::Image ui::LoadImage(const char *szPicName, int flags)
{
	return EngFuncs::PIC_Load(szPicName, flags);
}

void ui::FreeImage(const char *szPicName)
{
	EngFuncs::PIC_Free(szPicName);
}

int ui::ImageWidth(ui::Image hPic)
{
	Assert(hPic);
	if(!hPic) return 0;
	return EngFuncs::PIC_Width(hPic);
}

int ui::ImageHeight(ui::Image hPic)
{
	Assert(hPic);
	if(!hPic) return 0;
	return EngFuncs::PIC_Height(hPic);
}

void ui::ImageSize(ui::Image hPIC, int &w, int &h)
{
	auto sz = EngFuncs::PIC_Size(hPIC);
	w = sz.w;
	h = sz.h;
}

void ui::DrawImage(ui::Image img, int x, int y, int w, int h, colorRGBA color, ui::EImageDrawMode mode)
{
	if(!img) return;
	EngFuncs::PIC_Set(img, color.r, color.g, color.b, color.a);
	switch(mode)
	{
		case ui::EImageDrawMode::Additive:
			EngFuncs::PIC_DrawAdditive(x, y, w, h);
			break;
		case ui::EImageDrawMode::Normal:
			EngFuncs::PIC_Draw(x, y, w, h, NULL);
			break;
		case ui::EImageDrawMode::Translucent:
			EngFuncs::PIC_DrawTrans(x, y, w, h, NULL);
			break;
		default:
			Assert(0);
	}
}

ui::Font ui::GetDefaultFont()
{
	return uiStatic.hDefaultFont;
}

ui::Font ui::GetSmallFont()
{
	return uiStatic.hSmallFont;
}

ui::Font ui::GetBigFont()
{
	return uiStatic.hBigFont;
}

ui::Font ui::GetConsoleFont()
{
	return uiStatic.hConsoleFont;
}

ui::Font ui::GetBoldFont()
{
	return uiStatic.hBoldFont;
}


void ui::GetCursorPos(int& x, int& y)
{
	UI_GetCursorPos(&x, &y);
}

void ui::SetCursorPos(int x, int y)
{
	UI_SetCursorPos(x, y);
}

void ui::PixelsToUIPos(int &x, int &y)
{

}

colorRGBA ui::GetColor(const char *name)
{
	return FindColorByName(name);
}