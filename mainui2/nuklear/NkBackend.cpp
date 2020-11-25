/**

 Backend renderer for Nuklear UI

 */
#include "NkBackend.h"
#include "EngineCallback.h"

/* Crt includes */
#include "crtlib.h"

#define NK_IMPLEMENTATION
#include "nuklear.h"


// Allocate 16MB for now
#define NUKLEAR_MEMORY (16384*1024)

/* Dirty dirty globals... */
nk_context g_NuklearContext;

/* Prototypes */
void NkDrawArc          (const nk_command* cmd);
void NkDrawArcFilled    (const nk_command* cmd);
void NkDrawCircle       (const nk_command* cmd);
void NkDrawCircleFilled (const nk_command* cmd);
void NkDrawCurve        (const nk_command* cmd);
void NkDrawCustom       (const nk_command* cmd);
void NkDrawImage        (const nk_command* cmd);
void NkDrawLine         (const nk_command* cmd);
void NkDrawPolygon      (const nk_command* cmd);
void NkDrawPolygonFilled(const nk_command* cmd);
void NkDrawPolyline     (const nk_command* cmd);
void NkDrawRect         (const nk_command* cmd);
void NkDrawRectFilled   (const nk_command* cmd);
void NkDrawRectMultiColor(const nk_command* cmd);
void NkDrawScissor      (const nk_command* cmd);
void NkDrawText         (const nk_command* cmd);
void NkDrawTriangle     (const nk_command* cmd);
void NkDrawTriangleFilled(const nk_command* cmd);


void NkInit()
{
	nk_user_font fnt;

	nk_init_fixed(&g_NuklearContext, Q_malloc(NUKLEAR_MEMORY), NUKLEAR_MEMORY, &fnt);

}

// MUST be called from main thread
void NkFrame()
{
	/* Update input events */


	const nk_command* cmd;
	nk_foreach(cmd, &g_NuklearContext)
	{
		switch(cmd->type)
		{
			case NK_COMMAND_ARC: NkDrawArc(cmd); break;
			case NK_COMMAND_ARC_FILLED: NkDrawArcFilled(cmd); break;
			case NK_COMMAND_CIRCLE: NkDrawCircle(cmd); break;
			case NK_COMMAND_CIRCLE_FILLED: NkDrawCircleFilled(cmd); break;
			case NK_COMMAND_CURVE: NkDrawCurve(cmd); break;
			case NK_COMMAND_CUSTOM: NkDrawCustom(cmd); break;
			case NK_COMMAND_IMAGE: NkDrawImage(cmd); break;
			case NK_COMMAND_LINE: NkDrawLine(cmd); break;
			case NK_COMMAND_NOP: break;
			case NK_COMMAND_POLYGON: NkDrawPolygon(cmd); break;
			case NK_COMMAND_POLYGON_FILLED: NkDrawPolygonFilled(cmd); break;
			case NK_COMMAND_POLYLINE: NkDrawPolyline(cmd); break;
			case NK_COMMAND_RECT: NkDrawRect(cmd); break;
			case NK_COMMAND_RECT_FILLED: NkDrawRectFilled(cmd); break;
			case NK_COMMAND_RECT_MULTI_COLOR: NkDrawRectMultiColor(cmd); break;
			case NK_COMMAND_SCISSOR: NkDrawScissor(cmd); break;
			case NK_COMMAND_TEXT: NkDrawText(cmd); break;
			case NK_COMMAND_TRIANGLE: NkDrawTriangle(cmd); break;
			case NK_COMMAND_TRIANGLE_FILLED: NkDrawTriangleFilled(cmd); break;
			default: break;
		}
	}




}

void NkShutdown()
{

}


void NkDrawArc(const nk_command *cmd)
{

}

void NkDrawArcFilled(const nk_command *cmd)
{

}

void NkDrawCircle(const nk_command *cmd)
{

}

void NkDrawCircleFilled(const nk_command *cmd)
{

}

void NkDrawCurve(const nk_command *cmd)
{

}

void NkDrawCustom(const nk_command *cmd)
{

}

void NkDrawImage(const nk_command *cmd)
{
	auto pCmd = (const nk_command_image*)cmd;
}

void NkDrawLine(const nk_command *cmd)
{

}

void NkDrawPolygon(const nk_command *cmd)
{

}

void NkDrawPolygonFilled(const nk_command *cmd)
{

}

void NkDrawPolyline(const nk_command *cmd)
{

}

void NkDrawRect(const nk_command *cmd)
{

}

void NkDrawRectFilled(const nk_command *cmd)
{
	const nk_command_rect_filled* pCmd = (const nk_command_rect_filled*)cmd;
	EngFuncs::FillRGBA(pCmd->x, pCmd->y, pCmd->w, pCmd->h, pCmd->color.r, pCmd->color.g, pCmd->color.b, pCmd->color.a);
}

void NkDrawRectMultiColor(const nk_command *cmd)
{

}

void NkDrawScissor(const nk_command *cmd)
{

}

void NkDrawText(const nk_command *cmd)
{

}

void NkDrawTriangle(const nk_command *cmd)
{

}

void NkDrawTriangleFilled(const nk_command *cmd)
{

}
