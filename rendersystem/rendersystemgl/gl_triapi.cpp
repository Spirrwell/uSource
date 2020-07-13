#include "rendersystemgl.h"
#include "rendersystem/itriapi.h"

class CTriangleAPI_GL : public ITriangleAPI
{
public:
	virtual void RenderMode( int mode ) override;
	virtual void Begin( int mode ) override;
	virtual void End( void ) override;
	virtual void TexCoord2f( float u, float v ) override;
	virtual void Vertex3fv( const float *v ) override;
	virtual void Vertex3f( float x, float y, float z ) override;
	virtual void Color4f( float r, float g, float b, float a ) override;
	virtual void Color4ub( byte r, byte g, byte b, byte a ) override;
	virtual void Brightness( float brightness ) override;
	virtual int WorldToScreen( const float *world, float *screen ) override;
	virtual int SpriteTexture( model_t *pSpriteModel, int frame ) override;
	virtual void Fog( float flFogColor[3], float flStart, float flEnd, int bOn ) override;
	virtual void GetMatrix( const int pname, float *matrix ) override;
	virtual void FogParams( float flDensity, int iFogSkybox ) override;
	virtual void CullFace( TRICULLSTYLE mode ) override;
};

static struct
{
	int		renderMode;		// override kRenderMode from TriAPI
	vec4_t		triRGBA;
} ds;

void CTriangleAPI_GL::RenderMode(int mode)
{
	ds.renderMode = mode;
	switch( mode )
	{
		case kRenderNormal:
			pglTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
			pglDisable( GL_BLEND );
			pglDepthMask( GL_TRUE );
			break;
		case kRenderTransAlpha:
			pglEnable( GL_BLEND );
			pglTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
			pglBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
			pglDepthMask( GL_FALSE );
			break;
		case kRenderTransColor:
		case kRenderTransTexture:
			pglEnable( GL_BLEND );
			pglBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
			break;
		case kRenderGlow:
		case kRenderTransAdd:
			pglBlendFunc( GL_SRC_ALPHA, GL_ONE );
			pglEnable( GL_BLEND );
			pglDepthMask( GL_FALSE );
			break;
	}
}

void CTriangleAPI_GL::Begin(int mode)
{
	switch( mode )
	{
		case TRI_POINTS:
			mode = GL_POINTS;
			break;
		case TRI_TRIANGLES:
			mode = GL_TRIANGLES;
			break;
		case TRI_TRIANGLE_FAN:
			mode = GL_TRIANGLE_FAN;
			break;
		case TRI_QUADS:
			mode = GL_QUADS;
			break;
		case TRI_LINES:
			mode = GL_LINES;
			break;
		case TRI_TRIANGLE_STRIP:
			mode = GL_TRIANGLE_STRIP;
			break;
		case TRI_QUAD_STRIP:
			mode = GL_QUAD_STRIP;
			break;
		case TRI_POLYGON:
		default:
			mode = GL_POLYGON;
			break;
	}

	pglBegin( mode );
}

void CTriangleAPI_GL::End(void)
{
	pglEnd( );
}

void CTriangleAPI_GL::TexCoord2f(float u, float v)
{
	pglTexCoord2f( u, v );
}

void CTriangleAPI_GL::Vertex3fv(const float *v)
{
	pglVertex3fv( v );
}

void CTriangleAPI_GL::Vertex3f(float x, float y, float z)
{
	pglVertex3f( x, y, z );
}


void _TriColor4f( float r, float g, float b, float a )
{
	pglColor4f( r, g, b, a );
}

void _TriColor4ub( byte r, byte g, byte b, byte a )
{
	pglColor4ub( r, g, b, a );
}


void CTriangleAPI_GL::Color4f(float r, float g, float b, float a)
{
	if( ds.renderMode == kRenderTransAlpha )
		TriColor4ub( r * 255.9f, g * 255.9f, b * 255.9f, a * 255.0f );
	else _TriColor4f( r * a, g * a, b * a, 1.0 );

	ds.triRGBA[0] = r;
	ds.triRGBA[1] = g;
	ds.triRGBA[2] = b;
	ds.triRGBA[3] = a;
}

void CTriangleAPI_GL::Color4ub(byte r, byte g, byte b, byte a)
{
	ds.triRGBA[0] = r * (1.0f / 255.0f);
	ds.triRGBA[1] = g * (1.0f / 255.0f);
	ds.triRGBA[2] = b * (1.0f / 255.0f);
	ds.triRGBA[3] = a * (1.0f / 255.0f);

	_TriColor4f( ds.triRGBA[0], ds.triRGBA[1], ds.triRGBA[2], 1.0f );
}

void CTriangleAPI_GL::Brightness(float brightness)
{
	float	r, g, b;

	r = ds.triRGBA[0] * ds.triRGBA[3] * brightness;
	g = ds.triRGBA[1] * ds.triRGBA[3] * brightness;
	b = ds.triRGBA[2] * ds.triRGBA[3] * brightness;

	_TriColor4f( r, g, b, 1.0f );
}

int CTriangleAPI_GL::WorldToScreen(const float *world, float *screen)
{
	int	retval;

	retval = R_WorldToScreen( world, screen );

	screen[0] =  0.5f * screen[0] * (float)RI.viewport[2];
	screen[1] = -0.5f * screen[1] * (float)RI.viewport[3];
	screen[0] += 0.5f * (float)RI.viewport[2];
	screen[1] += 0.5f * (float)RI.viewport[3];

	return retval;
}

int CTriangleAPI_GL::SpriteTexture(model_t *pSpriteModel, int frame)
{
	int	gl_texturenum;

	if(( gl_texturenum = R_GetSpriteTexture( pSpriteModel, frame )) == 0 )
		return 0;

	if( gl_texturenum <= 0 || gl_texturenum > MAX_TEXTURES )
		gl_texturenum = tr.defaultTexture;

	GL_Bind( XASH_TEXTURE0, gl_texturenum );

	return 1;
}

void CTriangleAPI_GL::Fog(float *flFogColor, float flStart, float flEnd, int bOn)
{
	// overrided by internal fog
	if( RI.fogEnabled ) return;
	RI.fogCustom = bOn;

	// check for invalid parms
	if( flEnd <= flStart )
	{
		glState.isFogEnabled = RI.fogCustom = false;
		pglDisable( GL_FOG );
		return;
	}

	if( RI.fogCustom )
		pglEnable( GL_FOG );
	else pglDisable( GL_FOG );

	// copy fog params
	RI.fogColor[0] = flFogColor[0] / 255.0f;
	RI.fogColor[1] = flFogColor[1] / 255.0f;
	RI.fogColor[2] = flFogColor[2] / 255.0f;
	RI.fogStart = flStart;
	RI.fogColor[3] = 1.0f;
	RI.fogDensity = 0.0f;
	RI.fogSkybox = true;
	RI.fogEnd = flEnd;

	pglFogi( GL_FOG_MODE, GL_LINEAR );
	pglFogfv( GL_FOG_COLOR, RI.fogColor );
	pglFogf( GL_FOG_START, RI.fogStart );
	pglFogf( GL_FOG_END, RI.fogEnd );
	pglHint( GL_FOG_HINT, GL_NICEST );
}

void CTriangleAPI_GL::GetMatrix(const int pname, float *matrix)
{
	pglGetFloatv( pname, matrix );
}

void CTriangleAPI_GL::FogParams(float flDensity, int iFogSkybox)
{
	RI.fogDensity = flDensity;
	RI.fogSkybox = iFogSkybox;
}

void CTriangleAPI_GL::CullFace(TRICULLSTYLE mode)
{
	int glMode;

	switch( mode )
	{
		case TRI_FRONT:
			glMode = GL_FRONT;
			break;
		default:
			glMode = GL_NONE;
			break;
	}

	GL_Cull( mode );
}

CTriangleAPI_GL g_TriAPI;



ITriangleAPI * CRenderSystem_GL::GetTriAPI()
{
	return &g_TriAPI;
}