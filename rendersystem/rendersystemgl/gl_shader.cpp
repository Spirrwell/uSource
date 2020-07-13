#include "rendersystem/ishader.h"
#include "rendersystemgl.h"
#include "rendersystem/gl_export.h"
#include "rendersystem/gl_local.h"

class CVertexShader_GL : public IVertexShader
{
public:
	GLint m_shaderIndex;
	bool m_init : 1;
	bool m_compiled : 1;


	CVertexShader_GL();
	~CVertexShader_GL();
	virtual void SetSourceCode(void* pbuf, size_t buflen, ESourceCodeType type = ESourceCodeType::GLSL) override;
	virtual bool Compile() override;
	virtual const char* GetInfoLog() override;
};

class CFragShader_GL : public IFragShader
{
public:
	GLint m_shaderIndex;
	bool m_init : 1;
	bool m_compiled : 1;

	CFragShader_GL();
	~CFragShader_GL();
	virtual void SetSourceCode(void* pbuf, size_t buflen, ESourceCodeType type = ESourceCodeType::GLSL) override;
	virtual bool Compile() override;
	virtual const char* GetInfoLog() override;
};


class CGeomShader_GL : public IGeomShader
{
public:
	GLint m_shaderIndex;
	bool m_init : 1;
	bool m_compiled : 1;

	CGeomShader_GL();
	~CGeomShader_GL();
	virtual void SetSourceCode(void* pbuf, size_t buflen, ESourceCodeType type = ESourceCodeType::GLSL) override;
	virtual bool Compile() override;
	virtual const char* GetInfoLog() override;
};

//===============================================================================================================//
// Vertex Shader
CVertexShader_GL::CVertexShader_GL()
{

}

CVertexShader_GL::~CVertexShader_GL()
{

}

void CVertexShader_GL::SetSourceCode(void *pbuf, size_t buflen, ESourceCodeType type)
{

}

bool CVertexShader_GL::Compile()
{
	return false;
}

const char *CVertexShader_GL::GetInfoLog()
{
	return nullptr;
}
//===============================================================================================================//


//===============================================================================================================//
// Fragment Shader
CFragShader_GL::CFragShader_GL()
{

}

CFragShader_GL::~CFragShader_GL()
{

}

void CFragShader_GL::SetSourceCode(void *pbuf, size_t buflen, ESourceCodeType type)
{

}

bool CFragShader_GL::Compile()
{
	return false;
}

const char *CFragShader_GL::GetInfoLog()
{
	return nullptr;
}
//===============================================================================================================//


//===============================================================================================================//
// Geometry Shader
CGeomShader_GL::CGeomShader_GL()
{

}

CGeomShader_GL::~CGeomShader_GL()
{

}

void CGeomShader_GL::SetSourceCode(void *pbuf, size_t buflen, ESourceCodeType type)
{

}

bool CGeomShader_GL::Compile()
{
	return false;
}

const char *CGeomShader_GL::GetInfoLog()
{
	return nullptr;
}
//===============================================================================================================//
