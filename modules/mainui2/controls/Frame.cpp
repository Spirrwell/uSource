#include "Frame.h"
#include "FontManager.h"

#include "tier1/concommand.h"
#include "tier1/dbg.h"

static const Size exitButtonSize = Size(15, 15);
static const Size resizeButtonSize = Size(15, 15);
static const int cornerRadius = 10;

using namespace UI;

Frame::Frame(const char* name) :
	CMenuBaseWindow(name),
	m_titleText("Frame"),
	m_titleColor(PackRGBA(255, 255, 255, 255)),
	m_titleFont(FindFontByName("DefaultVerySmall")),
	m_dockMode(EDockMode::NONE),
	m_margin(5),
	resizing(false),
	m_roundedCorners(true),
	m_dragging(false)
{
	this->bAllowDrag = true;
	EnableTransition(EAnimation::ANIM_IN);
	EnableTransition(EAnimation::ANIM_OUT);
}

void Frame::Draw()
{
	BaseClass::Draw();

	/* Draw the background */
	if(m_roundedCorners)
	{
		EngFuncs::FillRGBA(this->m_scPos.x, this->m_scPos.y + cornerRadius, this->m_scSize.w, this->m_scSize.h - (cornerRadius*2), 
			m_backgroundColor.r, m_backgroundColor.g, m_backgroundColor.b, m_backgroundColor.a);
		EngFuncs::FillRGBA(this->m_scPos.x + cornerRadius, this->m_scPos.y, this->m_scSize.w - (cornerRadius*2), cornerRadius,
			m_backgroundColor.r, m_backgroundColor.g, m_backgroundColor.b, m_backgroundColor.a);
		EngFuncs::FillRGBA(this->m_scPos.x + cornerRadius, this->m_scPos.y + (m_scSize.h - cornerRadius), this->m_scSize.w - (cornerRadius*2), cornerRadius,
			m_backgroundColor.r, m_backgroundColor.g, m_backgroundColor.b, m_backgroundColor.a);
		Size cornerSize(cornerRadius, cornerRadius);
		UI_DrawPic(this->m_scPos, cornerSize, m_backgroundColor.rgba, "resource/icon_corner90", QM_DRAWTRANS);
		UI_DrawPic(this->m_scPos + Point(m_scSize.w - cornerRadius, 0), cornerSize, m_backgroundColor.rgba, "resource/icon_corner0", QM_DRAWTRANS);
		UI_DrawPic(this->m_scPos + Point(0, m_scSize.h - cornerRadius), cornerSize, m_backgroundColor.rgba, "resource/icon_corner180", QM_DRAWTRANS);
		UI_DrawPic(this->m_scPos + Point(m_scSize.w - cornerRadius, m_scSize.h - cornerRadius), cornerSize, m_backgroundColor.rgba, "resource/icon_corner270", QM_DRAWTRANS);
	}
	else
	{
		EngFuncs::FillRGBA(this->m_scPos.x, this->m_scPos.y, this->m_scSize.w, this->m_scSize.h, m_backgroundColor.r, m_backgroundColor.g, 
			m_backgroundColor.b, m_backgroundColor.a);
	}

	/* Draw the frame title */
	EngFuncs::DrawSetTextColor(m_titleColor.r, m_titleColor.g, m_titleColor.b, m_titleColor.a);
	
	int w, h;
	g_FontMgr->GetTextSize(this->m_titleFont, this->m_titleText.c_str(), &w, &h);
	Point titlePos = this->m_scPos + Point((this->m_scSize.w / 2) - (w/2), 0);
	UI_DrawString(this->m_titleFont, titlePos, Size(w, h), this->m_titleText.c_str(), this->m_titleColor.rgba, h, ETextAlignment::QM_CENTER);

	/* Draw a little separator under the window title */
	EngFuncs::FillRGBA(this->m_scPos.x + m_margin, this->m_scPos.y + (h + m_margin), m_scSize.w - (m_margin*2), 1, 100, 100, 100, 100);

	/* Draw the x button */
	m_exitBtnPos.x = this->m_scPos.x + this->m_scSize.w - exitButtonSize.w - m_margin;
	m_exitBtnPos.y = this->m_scPos.y + m_margin;
	UI_DrawPic(m_exitBtnPos, exitButtonSize, PackRGBA(100, 100, 100, 255), "resource/icon_exit", QM_DRAWTRANS);

	/* Draw the resizer */
	m_resizeBtnPos.x = (this->m_scPos.x + this->m_scSize.w) - resizeButtonSize.w;
	m_resizeBtnPos.y = (this->m_scPos.y + this->m_scSize.h) - resizeButtonSize.h;
	UI_DrawPic(m_resizeBtnPos, resizeButtonSize, PackRGBA(255, 255, 255, 255), "resource/icon_resizer", QM_DRAWTRANS);

}

void Frame::UpdateLayout()
{

}

void Frame::Init()
{
	BaseClass::Init();

	if(this->m_dockMode == EDockMode::FILL)
	{
		Assert(this->m_pParent);
		if(this->m_pParent)
		{
			this->m_scSize = this->m_pParent->GetRenderSize();
		}
	}

}

void Frame::Think()
{
	BaseClass::Think();
	printf("SCR: %u %u\n", gpGlobals->scrWidth, gpGlobals->scrHeight);
	/* Check if we're moving or not */
	if(m_dragging)
	{
		this->Hide();
		int x = uiStatic.cursorX;
		int y = uiStatic.cursorY;
		UI_ScaleCoords(x, y);
		this->SetCoord(m_scPos.x + (x - this->m_startPoint.x), m_scPos.y + (y - this->m_startPoint.y));
		this->CalcSizes();
		this->UpdateLayout();
		this->Show();
	}
}

bool Frame::KeyDown(int key)
{
	BaseClass::KeyDown(key);
	if(UI::Key::IsLeftMouse(key))
	{
		int x,y;
		UI_GetCursorPos(&x, &y);
		if(UI_CursorInRect(this->m_exitBtnPos, exitButtonSize))
		{
			this->Hide();
			BaseClass::KeyDown(K_ESCAPE);
		}
		if(UI_CursorInRect(this->m_resizeBtnPos, resizeButtonSize))
		{
			this->resizing = true;
			this->m_dragging = true;
			int x = uiStatic.cursorX;
			int y = uiStatic.cursorY;
			UI_ScaleCoords(x, y);
			printf("cur: %f %f", uiStatic.cursorX * uiStatic.scaleX, uiStatic.cursorY * uiStatic.scaleY);
			this->m_startPoint = Point(x, y);
		}
	}
	return false;
}

bool Frame::KeyUp(int key)
{
	if(this->resizing && UI::Key::IsLeftMouse(key))
		this->resizing = false;
	if(this->m_dragging && UI::Key::IsLeftMouse(key))
		this->m_dragging = false;
	return BaseClass::KeyUp(key);
}

CONCOMMAND(FrameTest, "", 0)
{
	static UI::Frame *test = new UI::Frame("Test");
	test->SetBackgroundColor(175, 175, 175, 255);
	test->bTransparent = true;
	test->SetSize(200, 200);
	test->SetCoord(200, 200 + (rand() % 50));
	test->Show();
}