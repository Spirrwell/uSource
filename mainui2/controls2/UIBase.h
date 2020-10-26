#pragma once

/**
 *
 * BaseControl for all other control types
 *
 * See MainUI.h for design info
 *
 */

#include "MainUI.h"
#include "Coord.h"
#include "EventSystem2.h"

#include "containers/array.h"
#include "containers/list.h"

BEGIN_MAINUI_NAMESPACE

class UIBase
{
protected:

private:
	List<UIBase> m_children;
	UIBase* m_parent;
	Font m_font;
	bool m_fixed;
	Point m_pos;
	Point m_size;
	unsigned long long m_id;
public:

	UIBase();

	/**
	 * Updates the state of this element.
	 * This function is called from the main thread so you can access
	 * anything you want. Since this is synchronous, don't take so long
	 * in there, if possible. Do not maintain pointers or other non-thread safe
	 * state after this call exits.
	 * @param state
	 */
	virtual void UpdateState(ui_state_t state);

	/**
	 * Draws the element. This will generate draw calls for Nuklear and add them
	 * to the queue. Draw calls are drawn to the screen after the renderer
	 * finishes drawing the screen. This is called in a SEPARATE thread, so
	 * do NOT try to access anything in the main thread. You should only be doing
	 * basic drawing here.
	 * @param state
	 */
	virtual void Draw(ui_state_t state);

	/**
	 * @brief Returns the parent or NULL if not found
	 */
	virtual UIBase* Parent() const;

	/**
	 * @brief Adds a child to this element
	 * @param element
	 */
	virtual void AddChild(UIBase& element);

	/**
	 * @brief Removes a child
	 * @param element
	 */
	virtual void RemoveChild(UIBase& element);

	/**
	 * @return List of children to this ui element
	 */
	virtual const List<UIBase>& Children() const;

	/* NOTE: Marking some methods as virtual final to ensure they are not hidden by accident */

	virtual Font GetFont() const final;
	virtual void SetFont(Font fnt) final;

	virtual bool IsFixed() const final;
	virtual void SetFixed(bool fixed) final;

	virtual Size GetSize() const final;
	virtual void SetSize(Size sz) final;

	virtual Point GetPos() const final;
	virtual void SetPos(Point pos) final;


	/* Events */

	/* Called when the element is resized. Param 1 is the old size, param 2 is the new size */
	Delegate<void, Size, Size> OnResize;

	/* Called when the element is moved to a new position. Param 1 is old pos, param 2 is new pos */
	Delegate<void, Point, Point> OnMoved;


};

END_MAINUI_NAMESPACE