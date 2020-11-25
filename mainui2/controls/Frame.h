/**
 * 
 * Frame.h
 * 
 * vgui2-style frame
 * 
 */
#pragma once

#include "BaseItem.h"
#include "BaseWindow.h"
#include "public/containers/string.h"

enum class EDockMode
{
	NONE = 0,
	FILL,
};

namespace Images
{
	static HIMAGE g_Resizer = 0;
	static HIMAGE g_Exit = 0;
} 

namespace UI
{
	class Frame : public CMenuBaseWindow
	{
	private:
		EDockMode m_dockMode;
		bool m_roundedCorners;
		CColor m_backgroundColor;
		CColor m_outlineColor;
		CColor m_titleColor;
		String m_titleText;
		HFont m_titleFont;
		int m_margin;
		bool resizing;
		bool m_resizable;
		bool m_draggable;
		bool m_dragging;
		Point m_startPoint;
		Point m_exitBtnPos;
		Point m_resizeBtnPos;
		int m_cornerRadius;
		Size m_minSize;

		Size m_usableArea;

		typedef CMenuBaseItem BaseClass;

	public:
		Frame(const char *name);

		void SetBackgroundColor(int r, int g, int b, int a = 255) { m_backgroundColor.Set(PackRGBA(r, g, b, a)); };
		void SetTitleColor(int r, int g, int b, int a = 255) { m_titleColor.Set(PackRGBA(r, g, b, a)); };
		void SetOutlineColor(int r, int g, int b, int a = 255) { m_outlineColor.Set(PackRGBA(r, g, b, a)); };
		void ShouldDrawRoundedCorners(bool yesorno) { m_roundedCorners = yesorno; };
		void SetDockMode(EDockMode mode) { m_dockMode = mode; };

		void SetResizable(bool r) { m_resizable = r; };
		void SetDraggable(bool d) { m_draggable = d; };
		void SetCornerRadius(int r) { m_cornerRadius = r; };
		void SetMinimumSize(Size s) { m_minSize = s; };

		void SetTitle(const char *title) { this->m_titleText = title; };

		void Draw() override;
		void Init() override;
		bool KeyUp(int key) override;
		bool KeyDown(int key) override;
		void Think() override;

		/* Recomputes all sizes and positions after a resize operation */
		void UpdateLayout();
	};
} 
