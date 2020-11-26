/*
 *
 * itriapi.h - GL1-esque triangle api
 *
 */
#pragma once

#include "rendersystem_common.h"

#include "common.h"
#include "triangleapi.h"
#include "const.h"
#include "gl_local.h"

BEGIN_RENDERSYSTEM_NAMESPACE

class ITriangleAPI
{
public:
	virtual void RenderMode( int mode ) = 0;
	virtual void Begin( int mode ) = 0;
	virtual void End( void ) = 0;
	virtual void TexCoord2f( float u, float v ) = 0;
	virtual void Vertex3fv( const float *v ) = 0;
	virtual void Vertex3f( float x, float y, float z ) = 0;
	virtual void Color4f( float r, float g, float b, float a ) = 0;
	virtual void Color4ub( byte r, byte g, byte b, byte a ) = 0;
	virtual void Brightness( float brightness ) = 0;
	virtual int WorldToScreen( const float *world, float *screen ) = 0;
	virtual int SpriteTexture( model_t *pSpriteModel, int frame ) = 0;
	virtual void Fog( float flFogColor[3], float flStart, float flEnd, int bOn ) = 0;
	virtual void GetMatrix( const int pname, float *matrix ) = 0;
	virtual void FogParams( float flDensity, int iFogSkybox ) = 0;
	virtual void CullFace( TRICULLSTYLE mode ) = 0;
};

END_RENDERSYSTEM_NAMESPACE