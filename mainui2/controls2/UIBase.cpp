#include "UIBase.h"
#include <atomic>

MAINUI_SOURCEFILE;


std::atomic<unsigned long long> g_IDCounter;

UIBase::UIBase() :
	m_fixed(false),
	m_font(0),
	m_id(0),
	m_parent(nullptr)
{
	m_id = g_IDCounter++;
}

void ui::UIBase::UpdateState(ui::ui_state_t state)
{

}

void ui::UIBase::Draw(ui::ui_state_t state)
{
	for(auto& child : m_children)
	{
		child.Draw(state);
	}
}

ui::UIBase *ui::UIBase::Parent() const
{
	return nullptr;
}

void ui::UIBase::AddChild(ui::UIBase &element)
{
	m_children.push_back(element);
}

void ui::UIBase::RemoveChild(ui::UIBase &element)
{

}

const List<UIBase> &ui::UIBase::Children() const
{
	return m_children;
}

ui::Font ui::UIBase::GetFont() const
{
	return m_font;
}

void ui::UIBase::SetFont(ui::Font fnt)
{
	m_font = fnt;
}

bool ui::UIBase::IsFixed() const
{
	return m_fixed;
}

void ui::UIBase::SetFixed(bool fixed)
{
	m_fixed = fixed;
}

Size UIBase::GetSize() const
{
	return m_size;
}

void UIBase::SetSize(Size sz)
{
	m_size = sz;
}

Point UIBase::GetPos() const
{
	return m_pos;
}

void UIBase::SetPos(Point pos)
{
	m_pos = pos;
}

