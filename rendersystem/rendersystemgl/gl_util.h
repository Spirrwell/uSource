/*
 *
 * Basic OpenGL utils
 *
 */
#pragma once

#include "rendersystem/rendersystem.h"
#include <GL/gl.h>

namespace gl
{

	static constexpr int ShaderDepthFuncToGL[] = {
		GL_NEVER,
		GL_LESS,
		GL_EQUAL,
		GL_LEQUAL,
		GL_GREATER,
		GL_NOTEQUAL,
		GL_GEQUAL,
		GL_ALWAYS,
	};

	static inline int DepthFuncToGL(rendersystem::EShaderDepthFunc fn)
	{
		return ShaderDepthFuncToGL[(int)fn];
	}

	static constexpr int ShaderBlendFuncToGL[] = {
		GL_ZERO,
		GL_ONE,
		GL_DST_COLOR,
		GL_ONE_MINUS_DST_COLOR,
		GL_SRC_ALPHA,
		GL_ONE_MINUS_SRC_ALPHA,
		GL_DST_ALPHA,
		GL_ONE_MINUS_DST_ALPHA,
		GL_SRC_ALPHA_SATURATE,
		GL_SRC_COLOR,
		GL_ONE_MINUS_SRC_COLOR
	};

	static inline int BlendFuncToGL(rendersystem::EShaderBlendFunc fn)
	{
		return ShaderBlendFuncToGL[(int)fn];
	}

	static constexpr int ShaderBlendEqToGL[] = {
		GL_FUNC_ADD,
		GL_FUNC_SUBTRACT,
		GL_FUNC_REVERSE_SUBTRACT,
		GL_MIN,
		GL_MAX
	};

	static inline int BlendEquationToGL(rendersystem::EShaderBlendEq eq)
	{
		return ShaderBlendEqToGL[(int)eq];
	}

	static constexpr int ShaderAlphaFuncToGL[] = {
		GL_NEVER,
		GL_LESS,
		GL_EQUAL,
		GL_LEQUAL,
		GL_GREATER,
		GL_NOTEQUAL,
		GL_GEQUAL,
		GL_ALWAYS
	};

	static inline int AlphaFuncToGL(rendersystem::EShaderAlphaFunc fn)
	{
		return ShaderAlphaFuncToGL[(int)fn];
	}

	static constexpr int ShaderStencilFuncToGL[] = {
		GL_NEVER,
		GL_LESS,
		GL_EQUAL,
		GL_LEQUAL,
		GL_GREATER,
		GL_NOTEQUAL,
		GL_GEQUAL,
		GL_ALWAYS
	};

	static inline int StencilFuncToGL(rendersystem::EShaderStencilFunc fn)
	{
		return ShaderStencilFuncToGL[(int)fn];
	}

	static constexpr int ShaderStencilOpToGL[] = {
		GL_KEEP,
		GL_ZERO,
		GL_REPLACE,
		GL_INCR_WRAP,
		GL_DECR_WRAP,
		GL_INVERT,
		GL_INCR,
		GL_DECR,
	};

	static inline int StencilOpToGL(rendersystem::EShaderStencilOp op)
	{
		return ShaderStencilOpToGL[(int)op];
	}

}