/*

VECTOR.H

Replacement for Valve's vector types.

*/
#pragma once

/* Redefs of stuff from good ol gold source */
typedef float vec_t;

#include <stdint.h>
#include <stdio.h>
#include <math.h>

#ifdef NEW_VEC_TYPES

//=========================================================
// 2DVector - used for many pathfinding and many other
// operations that are treated as planar rather than 3d.
//=========================================================
class Vector2D
{
public:
	inline Vector2D(void): x( 0.0f ), y( 0.0f )						{ }
	inline Vector2D(float X, float Y): x( 0.0f ), y( 0.0f )				{ x = X; y = Y; }
	inline Vector2D operator+(const Vector2D& v)	const	{ return Vector2D( x + v.x, y + v.y );	}
	inline Vector2D operator-(const Vector2D& v)	const	{ return Vector2D( x - v.x, y - v.y );	}
	inline Vector2D operator*(float fl)		const	{ return Vector2D( x * fl, y * fl );	}
	inline Vector2D operator/(float fl)		const	{ return Vector2D( x / fl, y / fl );	}

	inline float Length(void)			const	{ return sqrt(x * x + y * y );		}

	inline Vector2D Normalize ( void ) const
	{
		//Vector2D vec2;

		float flLen = Length();
		if( flLen == 0 )
		{
			return Vector2D( 0, 0 );
		}
		else
		{
			flLen = 1 / flLen;
			return Vector2D( x * flLen, y * flLen );
		}
	}

	vec_t	x, y;
};

inline float DotProduct( const Vector2D& a, const Vector2D& b ) { return( a.x * b.x + a.y * b.y ); }
inline Vector2D operator*( float fl, const Vector2D& v ) { return v * fl; }

//=========================================================
// 3D Vector
//=========================================================
class Vector						// same data-layout as engine's vec3_t,
{								//		which is a vec_t[3]
public:
	// Construction/destruction
	inline Vector( void ): x( 0.0f ), y( 0.0f ), z( 0.0f )								{ }
	inline Vector( float X, float Y, float Z ): x( 0.0f ), y( 0.0f ), z( 0.0f )	{ x = X; y = Y; z = Z;				}
	//inline Vector( double X, double Y, double Z )		{ x = (float)X; y = (float)Y; z = (float)Z;	}
	//inline Vector( int X, int Y, int Z )			{ x = (float)X; y = (float)Y; z = (float)Z;	}
	inline Vector( const Vector& v ): x( 0.0f ), y( 0.0f ), z( 0.0f )	{ x = v.x; y = v.y; z = v.z;			}
	inline Vector( float rgfl[3] ): x( 0.0f ), y( 0.0f ), z( 0.0f )	{ x = rgfl[0]; y = rgfl[1]; z = rgfl[2];	}

	/* Operators */
	inline Vector operator-( void ) const			{ return Vector( -x, -y, -z );			}
	inline int operator==( const Vector& v ) const		{ return x==v.x && y==v.y && z==v.z;		}
	inline int operator!=( const Vector& v ) const		{ return !( *this==v );				}
	inline Vector operator+( const Vector& v ) const	{ return Vector( x + v.x, y + v.y, z + v.z );	}
	inline Vector operator-( const Vector& v ) const	{ return Vector( x - v.x, y - v.y, z - v.z );	}
	inline Vector operator*( float fl) const		{ return Vector( x * fl, y * fl, z * fl );	}
	inline Vector operator/( float fl) const		{ return Vector( x / fl, y / fl, z / fl );	}
	inline Vector& operator=(const Vector& v)               { x = v.x; y = v.y; z = v.z; return *this; };

	// Methods
	inline void CopyToArray( float* rgfl ) const		{ rgfl[0] = x, rgfl[1] = y, rgfl[2] = z; }
	inline float Length( void ) const			{ return sqrt( x * x + y * y + z * z ); }
	operator float *()					{ return &x; } // Vectors will now automatically convert to float * when needed
	operator const float *() const				{ return &x; } // Vectors will now automatically convert to float * when needed

	inline Vector Normalize( void ) const
	{
		float flLen = Length();
		if( flLen == 0 ) return Vector( 0, 0, 1 ); // ????
		flLen = 1 / flLen;
		return Vector( x * flLen, y * flLen, z * flLen );
	}

	inline Vector2D Make2D( void ) const
	{
		Vector2D	Vec2;

		Vec2.x = x;
		Vec2.y = y;

		return Vec2;
	}

	inline float Length2D( void ) const		{ return sqrt( x * x + y * y ); }

	// Members
	vec_t x, y, z;
};

inline Vector operator*( float fl, const Vector& v ) { return v * fl; }
inline float DotProduct( const Vector& a, const Vector& b ) { return( a.x * b.x + a.y * b.y + a.z * b.z); }
inline Vector CrossProduct( const Vector& a, const Vector& b ) { return Vector( a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x ); }

#endif

/* Alias these types to be used in engine code/game code */
#ifdef NEW_VEC_TYPES
#define vec3_t Vector
typedef vec_t vec4_t[4];
#define vec2_t Vector2D
#else
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];
typedef vec_t vec2_t[2];
#endif

#if !defined(NO_VECTOR_FUNCTIONS)

#define VectorIsNAN(v) (IS_NAN(v[0]) || IS_NAN(v[1]) || IS_NAN(v[2]))
#define DotProduct(x,y) ((x)[0]*(y)[0]+(x)[1]*(y)[1]+(x)[2]*(y)[2])
#define DotProductAbs(x,y) (abs((x)[0]*(y)[0])+abs((x)[1]*(y)[1])+abs((x)[2]*(y)[2]))
#define DotProductFabs(x,y) (fabs((x)[0]*(y)[0])+fabs((x)[1]*(y)[1])+fabs((x)[2]*(y)[2]))
#define CrossProduct(a,b,c) ((c)[0]=(a)[1]*(b)[2]-(a)[2]*(b)[1],(c)[1]=(a)[2]*(b)[0]-(a)[0]*(b)[2],(c)[2]=(a)[0]*(b)[1]-(a)[1]*(b)[0])
#define Vector2Subtract(a,b,c) ((c)[0]=(a)[0]-(b)[0],(c)[1]=(a)[1]-(b)[1])
#define VectorSubtract(a,b,c) ((c)[0]=(a)[0]-(b)[0],(c)[1]=(a)[1]-(b)[1],(c)[2]=(a)[2]-(b)[2])
#define Vector2Add(a,b,c) ((c)[0]=(a)[0]+(b)[0],(c)[1]=(a)[1]+(b)[1])
#define VectorAdd(a,b,c) ((c)[0]=(a)[0]+(b)[0],(c)[1]=(a)[1]+(b)[1],(c)[2]=(a)[2]+(b)[2])
#define VectorAddScalar(a,b,c) ((c)[0]=(a)[0]+(b),(c)[1]=(a)[1]+(b),(c)[2]=(a)[2]+(b))
#define Vector2Copy(a,b) ((b)[0]=(a)[0],(b)[1]=(a)[1])
#define VectorCopy(a,b) ((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2])
#define Vector4Copy(a,b) ((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2],(b)[3]=(a)[3])
#define VectorScale(in, scale, out) ((out)[0] = (in)[0] * (scale),(out)[1] = (in)[1] * (scale),(out)[2] = (in)[2] * (scale))
#define VectorCompare(v1,v2)	((v1)[0]==(v2)[0] && (v1)[1]==(v2)[1] && (v1)[2]==(v2)[2])
#define VectorDivide( in, d, out ) VectorScale( in, (1.0f / (d)), out )
#define VectorMax(a) ( max((a)[0], max((a)[1], (a)[2])) )
#define VectorAvg(a) ( ((a)[0] + (a)[1] + (a)[2]) / 3 )
#define VectorLength(a) ( sqrt( DotProduct( a, a )))
#define VectorLength2(a) (DotProduct( a, a ))
#define VectorDistance(a, b) (sqrt( VectorDistance2( a, b )))
#define VectorDistance2(a, b) (((a)[0] - (b)[0]) * ((a)[0] - (b)[0]) + ((a)[1] - (b)[1]) * ((a)[1] - (b)[1]) + ((a)[2] - (b)[2]) * ((a)[2] - (b)[2]))
#define Vector2Average(a,b,o)	((o)[0]=((a)[0]+(b)[0])*0.5f,(o)[1]=((a)[1]+(b)[1])*0.5f)
#define VectorAverage(a,b,o)	((o)[0]=((a)[0]+(b)[0])*0.5f,(o)[1]=((a)[1]+(b)[1])*0.5f,(o)[2]=((a)[2]+(b)[2])*0.5f)
#define Vector2Set(v, x, y) ((v)[0]=(x),(v)[1]=(y))
#define VectorSet(v, x, y, z) ((v)[0]=(x),(v)[1]=(y),(v)[2]=(z))
#define Vector4Set(v, a, b, c, d) ((v)[0]=(a),(v)[1]=(b),(v)[2]=(c),(v)[3] = (d))
#define VectorClear(x) ((x)[0]=(x)[1]=(x)[2]=0)
#define Vector2Lerp( v1, lerp, v2, c ) ((c)[0] = (v1)[0] + (lerp) * ((v2)[0] - (v1)[0]), (c)[1] = (v1)[1] + (lerp) * ((v2)[1] - (v1)[1]))
#define VectorLerp( v1, lerp, v2, c ) ((c)[0] = (v1)[0] + (lerp) * ((v2)[0] - (v1)[0]), (c)[1] = (v1)[1] + (lerp) * ((v2)[1] - (v1)[1]), (c)[2] = (v1)[2] + (lerp) * ((v2)[2] - (v1)[2]))
static float VectorNormalize( vec3_t v ) { float ilength = (float)sqrt(DotProduct(v, v));if (ilength) ilength = 1.0f / ilength;v[0] *= ilength;v[1] *= ilength;v[2] *= ilength; return ilength; }
#define VectorNormalize2( v, dest ) {float ilength = (float)sqrt(DotProduct(v,v));if (ilength) ilength = 1.0f / ilength;dest[0] = v[0] * ilength;dest[1] = v[1] * ilength;dest[2] = v[2] * ilength; }
#define VectorNormalizeFast( v ) {float	ilength = (float)rsqrt(DotProduct(v,v)); v[0] *= ilength; v[1] *= ilength; v[2] *= ilength; }
#define VectorNormalizeLength( v ) VectorNormalizeLength2((v), (v))
#define VectorNegate(x, y) ((y)[0] = -(x)[0], (y)[1] = -(x)[1], (y)[2] = -(x)[2])
#define VectorM(scale1, b1, c) ((c)[0] = (scale1) * (b1)[0],(c)[1] = (scale1) * (b1)[1],(c)[2] = (scale1) * (b1)[2])
#define VectorMA(a, scale, b, c) ((c)[0] = (a)[0] + (scale) * (b)[0],(c)[1] = (a)[1] + (scale) * (b)[1],(c)[2] = (a)[2] + (scale) * (b)[2])
#define VectorMAM(scale1, b1, scale2, b2, c) ((c)[0] = (scale1) * (b1)[0] + (scale2) * (b2)[0],(c)[1] = (scale1) * (b1)[1] + (scale2) * (b2)[1],(c)[2] = (scale1) * (b1)[2] + (scale2) * (b2)[2])
#define VectorMAMAM(scale1, b1, scale2, b2, scale3, b3, c) ((c)[0] = (scale1) * (b1)[0] + (scale2) * (b2)[0] + (scale3) * (b3)[0],(c)[1] = (scale1) * (b1)[1] + (scale2) * (b2)[1] + (scale3) * (b3)[1],(c)[2] = (scale1) * (b1)[2] + (scale2) * (b2)[2] + (scale3) * (b3)[2])
#define VectorIsNull( v ) ((v)[0] == 0.0f && (v)[1] == 0.0f && (v)[2] == 0.0f)
#define MakeRGBA( out, x, y, z, w ) Vector4Set( out, x, y, z, w )
#define PlaneDist(point,plane) ((plane)->type < 3 ? (point)[(plane)->type] : DotProduct((point), (plane)->normal))
#define PlaneDiff(point,plane) (((plane)->type < 3 ? (point)[(plane)->type] : DotProduct((point), (plane)->normal)) - (plane)->dist)
#define bound( min, num, max ) ((num) >= (min) ? ((num) < (max) ? (num) : (max)) : (min))

#define VectorM(scale1, b1, c) ((c)[0] = (scale1) * (b1)[0],(c)[1] = (scale1) * (b1)[1],(c)[2] = (scale1) * (b1)[2])

#define VectorMA(a, scale, b, c) ((c)[0] = (a)[0] + (scale) * (b)[0],(c)[1] = (a)[1] + (scale) * (b)[1],(c)[2] = (a)[2] + (scale) * (b)[2])

#define VectorMAM(scale1, b1, scale2, b2, c) ((c)[0] = (scale1) * (b1)[0] + (scale2) * (b2)[0],(c)[1] = (scale1) * (b1)[1] + (scale2) * (b2)[1],(c)[2] = (scale1) * (b1)[2] + (scale2) * (b2)[2])

#define VectorMAMAM(scale1, b1, scale2, b2, scale3, b3, c) ((c)[0] = (scale1) * (b1)[0] + (scale2) * (b2)[0] + (scale3) * (b3)[0],(c)[1] = (scale1) * (b1)[1] + (scale2) * (b2)[1] + (scale3) * (b3)[1],(c)[2] = (scale1) * (b1)[2] + (scale2) * (b2)[2] + (scale3) * (b3)[2])

#define VectorIsNull( v ) ((v)[0] == 0.0f && (v)[1] == 0.0f && (v)[2] == 0.0f)

#define MakeRGBA( out, x, y, z, w ) Vector4Set( out, x, y, z, w )

#define PlaneDist(point,plane) ((plane)->type < 3 ? (point)[(plane)->type] : DotProduct((point), (plane)->normal))

#define PlaneDiff(point,plane) (((plane)->type < 3 ? (point)[(plane)->type] : DotProduct((point), (plane)->normal)) - (plane)->dist)

#define bound( min, num, max ) ((num) >= (min) ? ((num) < (max) ? (num) : (max)) : (min))

#endif