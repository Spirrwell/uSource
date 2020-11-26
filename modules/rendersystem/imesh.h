#pragma once

#include "rendersystem_common.h"

#include "ibuffer.h"

BEGIN_RENDERSYSTEM_NAMESPACE

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
	/**
	 * Returns the index buffer used by this shader
	 * @return
	 */
	virtual IIndexBuffer* IndexBuffer() const = 0;

	/**
	 * Returns the vertex buffer used by this shader
	 * @return
	 */
	virtual IVertexBuffer* VertexBuffer() const = 0;

	/**
	 * Internally, this will lookup the corresponding shader backend and call those funcs
	 * @param pShader Shader program to use
	 */
	virtual void Draw(class IShaderProgram* pShader) = 0;

	/**
	 * Returns all set mesh flags
	 * @return
	 */
	virtual EMeshFlags Flags() const = 0;
};

END_RENDERSYSTEM_NAMESPACE