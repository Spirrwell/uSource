/**
 *
 * ui.h
 *
 * User Inteerface functions
 *
 */
#pragma once

#include "common.h"
#include "const.h"
#include "cvardef.h"
#include "ref_int.h"
#include "gui_int.h"

#include "containers/list.h"

namespace ui
{
	typedef int Font;
	typedef int Image;

	enum class EImageDrawMode
	{
		Normal = 0,
		Additive,
		Translucent,
	};

	enum class ETextJustify
	{
		/* Matches the definition in Mainui's primitive.h */
		CENTER	 = 0,
		TOP           = BIT( 0 ),
		BOTTOM        = BIT( 1 ),
		LEFT          = BIT( 2 ),
		RIGHT         = BIT( 3 ),
	};

	namespace color
	{
		constexpr static colorRGBA Red = {255, 0, 0, 255};
		constexpr static colorRGBA Blue = {0, 0, 255, 255};
		constexpr static colorRGBA Green = {0, 255, 0, 255};
		constexpr static colorRGBA Black = {0, 0, 0, 255};
		constexpr static colorRGBA Gray = {100, 100, 100, 255};
		constexpr static colorRGBA White = {255, 255, 255, 255};
	}

	void DrawFilledRect(int x, int y, int w, int h, colorRGBA color);
	void DrawRect(int x, int y, int w, int h, colorRGBA color, int border_width = 1);

	/* Draws a filled rect with rounded corners with the specified corner radius */
	void DrawFilledRectRounded(int x, int y, int w, int h, int corner_radius, colorRGBA color);

	/* Draws a filled circle on the screen */
	void DrawFilledCircle(int x, int y, int radius, colorRGBA color);
	void DrawFilledCircle(int x, int y, int w, int h, colorRGBA color);

	/* Draws a normal circle on the screen */
	void DrawCircle(int x, int y, int radius, colorRGBA color);

	void DrawLine(int x1, int y1, int x2, int y2, colorRGBA color, int width = 1);

	/* Draws some text on the screen */
	void DrawText(Font font, int x, int y, int w, int h, const char *str, colorRGBA color, int charH, ETextJustify justify, unsigned int flags = 0 );

	/* Registers a font and returns a handle to it */
	Font RegisterFont(const char* name, int size_tall, int weight, int outline, int blur, float brighten, bool italic, bool underline, bool bold, bool strike);

	/* Returns a font by the name */
	Font GetFont(const char* name);

	/* Returns a list of all registered fonts */
	List<Font> GetFontList();

	/* Returns a color by name */
	/* Colors are added via the schema */
	colorRGBA GetColor(const char* name);

	/* Gets the screen size */
	void GetScreenSize(int& w, int& h);
	int GetScreenWidth();
	int GetScreenHeight();

	/* Returns cursor pos */
	void GetCursorPos(int& x, int& y);
	void SetCursorPos(int x, int y);

	/* Scales window pos in pixels to the UI units */
	void PixelsToUIPos(int& x, int& y);

	/* Returns the size of the string if it were drawn to the screen */
	/* w is the drawn width in pixels, h is the drawn height in pixels */
	void DrawTextSize(Font font, const char* str, int& w, int& h);

	/* Loads an image and returns a handle to it */
	Image LoadImage( const char *szPicName, int flags = 0 );
	void FreeImage( const char *szPicName );
	int ImageWidth( Image hPic );
	int ImageHeight( Image hPic );
	void ImageSize(Image hPIC, int& w, int& h);
	void DrawImage(Image img, int x, int y, int w, int h, colorRGBA color, EImageDrawMode mode = EImageDrawMode::Additive);

	/* Returns various fonts */
	Font GetDefaultFont();
	Font GetSmallFont();
	Font GetBigFont();
	Font GetConsoleFont();
	Font GetBoldFont();
}