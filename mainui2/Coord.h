/*
Coord.h -- simple coordinate and size management
Copyright (C) 2017 a1batross


This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#pragma once

#include "MainUI.h"

#if 0
struct Point
{
	Point() { x = y = 0; }
	Point( int x, int y ) : x(x), y(y) {}

	int x, y;
	Point Scale();
	friend Point operator +( Point &a, Point &b ) { return Point( a.x + b.x, a.y + b.y ); }
	friend Point operator -( Point &a, Point &b ) { return Point( a.x - b.x, a.y - b.y ); }

	Point& operator+=( Point &a )
	{
		x += a.x;
		y += a.y;
		return *this;
	}

	Point& operator-=( Point &a )
	{
		x -= a.x;
		y -= a.y;
		return *this;
	}

	Point operator *( float scale ) { return Point( x * scale, y * scale );	}
	Point operator /( float scale ) { return Point( x / scale, y / scale );	}
};
#endif

#if 0
struct Size
{
	Size() { w = h = 0; }
	Size( int w, int h ) : w(w), h(h) {}

	int w, h;
	Size Scale();
};
#endif

BEGIN_MAINUI_NAMESPACE

struct Size
{
	float w, h;
	enum class Type {
		PX,
		PT,
		PERCENT,
		MM, // millimeters
	} type;

	Size() : w(0), h(0), type(Type::PX) {};
	Size(float _w, float _h) : w(_w), h(_h), type(Size::Type::PX) {};
	Size(float _w, float _h, Size::Type _type) : w(_w), h(_h), type(_type) {};

	/* Converts the value stored in here to pixels */
	void pixels(float& _w, float& _h) const
	{
		switch(type)
		{
			case Type::PX:
			{
				_w = w;
				_h = h;
				return;
			}
			case Type::PT:
			{

			}
			case Type::PERCENT:
			{
				int sw, sh;
				GetScreenSize(sw, sh);
				_w = (w / 100.0f) * sw;
				_h = (h / 100.0f) * sh;
			}
			case Type::MM:
			{

			}
		}
	}

	/* Converts the value stored into percent */
	void percent(float& px, float& py) const
	{
		switch(type)
		{
			case Type::PX:
			{

			}
			case Type::PT:
			{

			}
			case Type::PERCENT:
			{
				px = w;
				py = h;
			}
			case Type::MM:
			{

			}
		}
	}

	/* Converts the stored value into point */
	void point(float& px, float& py) const
	{
		switch(type)
		{
			case Type::PX:
			{

			}
			case Type::PT:
			{
				px = w;
				py = h;
			}
			case Type::PERCENT:
			{

			}
			case Type::MM:
			{

			}
		}
	}

	/* Converts the stored value into millimeters  */
	void millimeters(float& mmw, float& mmh) const
	{
		switch(type)
		{
			case Type::PX:
			{

			}
			case Type::PT:
			{
			}
			case Type::PERCENT:
			{

			}
			case Type::MM:
			{
				mmw = w;
				mmh = h;
			}
		}
	}
};

using Point = Size;

END_MAINUI_NAMESPACE