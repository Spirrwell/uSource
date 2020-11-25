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

/*

 MAINUI VERSION 2 DESIGN

 v2 of mainui has been redesigned to use Nuklear as the ui library.
 Nuklear is pretty nice, it's immediate mode and it's beautiful out
 of the box. However, since this is being redesigned around am immediate
 mode UI, we're going to partially destroy the OOP design method mainui
 already uses.

 Since Nuklear operates on a simple buffer and literally just inserts draw
 calls into a queue, we can do all UI "rendering" in a separate thread.
 So there will be a new design for controls and rendering things:

 Each frame, UpdateState() will be called from the MAIN thread of the engine.
 This will be used to grab important values from the game, engine, whatever.
 Anything that's in the main thread that cannot be safely accessed from
 a separate thread. This should also be used to update control sizes
 and such.

 After UpdateState is called the rendering of the UI in a separate thread will begin.
 UpdateState() will ALWAYS be called before Draw

 Draw(ui_state_t) is called in it's own thread. You should only be issuing draw calls here, no state
 access unless it's absolutely 100% safe. Draw calls are then accumulated into a buffer
 and rendered by the Nuklear renderer.



 */




#define BEGIN_MAINUI_NAMESPACE namespace ui {
#define END_MAINUI_NAMESPACE }
#define MAINUI_SOURCEFILE using namespace ui

namespace ui
{
	typedef int Font;
	typedef int Image;

	/* State passed to each widget/control/frame during draw time */
	/* this struct should have only basic types or classes */
	/* no pointers or references are allowed, unless they are 100% thread safe */
	struct ui_state_t
	{
		double curtime; // current time
		double dt; // time between this frame and last
		unsigned long long framecount; // Number of rendered frames
	};

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