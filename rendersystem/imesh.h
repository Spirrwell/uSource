#pragma once

#include "ibuffer.h"
#include "ishader.h"

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

	virtual void Draw(IShaderProgram* pShader) = 0;

	virtual EMeshFlags Flags() const = 0;
};