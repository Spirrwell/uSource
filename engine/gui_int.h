/*
 *
 * gui_int.h - Higher level 2d rendering API exported by mainui
 *
 */
#pragma once

#include "appframework.h"

#define IGUI_001 "IGui001"
#define IGUI_INTERFACE IGUI_001

/* Redefined from Primitive.h in mainui */
enum class EGuiRenderMode
{
	DRAWNORMAL = 0,
	DRAWHOLES,
	DRAWTRANS,
	DRAWADDITIVE
};

class IGuiInterface : public IAppInterface
{
public:
	virtual int RegisterFont(const char* name, int size_tall, int weight, int outline, int blur, float brighten, bool italic, bool underline, bool bold, bool strike) = 0;
	virtual int DrawString(int font, int x, int y, int w, int h, const char *str, int r, int g, int b, int a, int charH, unsigned intjustify, unsigned int flags = 0 ) = 0;
	virtual void DrawPic(int x, int y, int w, int h, int r, int g, int b, int a, const char *pic, EGuiRenderMode mode = EGuiRenderMode::DRAWTRANS ) = 0;
	virtual void FillRect(int x, int y, int w, int h, int r, int g, int b, int a = 255, int corner_radius = -1) = 0;
	virtual void FillCircle(int x, int y, int w, int h, int r, int g, int b, int a = 255) = 0;
	virtual void GetScreenSize(int &w, int &h) = 0;

	virtual int FindFont(const char* name) = 0;
	virtual colorRGBA FindColor(const char* color) = 0;
	virtual void DrawTextSize(int font, const char* str, int& w, int& h) = 0;
	virtual void DrawText(int font, int x, int y, int w, int h, const char *str, colorRGBA color, int charH, unsigned int intjustify, unsigned int flags) = 0;

	/* Cursor functions */
	virtual void GetCursorPos(int& x, int& y) = 0;
	virtual void SetCursorPos(int x, int y) = 0;
};