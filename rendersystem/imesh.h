#pragma once

#include "ibuffer.h"

enum EMeshFlags
{
	MESH_STATIC = 0,
	MESH_DYNAMIC,
};

/**
 * Simple mesh class. Contains both an index buffer and vertex buffer
 */
class IMesh
{
public:
	virtual IIndexBuffer* IndexBuffer() const = 0;

	virtual IVertexBuffer* VertexBuffer() const = 0;

	/**
	 * Internally, this will lookup the corresponding shader backend and call those funcs
	 * @param pShader
	 */
	virtual void Draw(class IShaderProgram* pShader) = 0;

	virtual EMeshFlags Flags() const = 0;
};