/*

MATHLIB.H

Mathlib is the replacement for Gold Source's original mathlib with acceleration and more features.

Include this for all mathlib functionality.

*/
#pragma once

#include "vector.h"
#include "matrix.h"
#include <stddef.h>
#include <stdint.h>
#include <math.h>

//==========================================================//
//
// Stuff from the old mathlib.h
//
//=========================================================//
#define PITCH		0
#define YAW			1
#define ROLL		2

#undef M_PI
#define M_PI		(float)3.14159265358979323846

#undef M_PI2
#define M_PI2		(float)6.28318530717958647692

#define M_PI_F		((float)(M_PI))
#define M_PI2_F		((float)(M_PI2))

#define RAD2DEG( x )	((float)(x) * (float)(180.f / M_PI))
#define DEG2RAD( x )	((float)(x) * (float)(M_PI / 180.f))

#define NUMVERTEXNORMALS	162

#define BOGUS_RANGE		((vec_t)114032.64)	// world.size * 1.74

#define SIDE_FRONT		0
#define SIDE_BACK		1
#define SIDE_ON		2
#define SIDE_CROSS		-2

#define PLANE_X		0	// 0 - 2 are axial planes
#define PLANE_Y		1	// 3 needs alternate calc
#define PLANE_Z		2
#define PLANE_NONAXIAL	3

#define EQUAL_EPSILON	0.001f
#define STOP_EPSILON	0.1f
#define ON_EPSILON		0.1f

#define RAD_TO_STUDIO	(32768.0 / M_PI)
#define STUDIO_TO_RAD	(M_PI / 32768.0)

#define INV127F		( 1.0f / 127.0f )
#define INV255F		( 1.0f / 255.0f )
#define MAKE_SIGNED( x )	((( x ) * INV127F ) - 1.0f )

#define Q_min( a, b )	(((a) < (b)) ? (a) : (b))
#define Q_max( a, b )	(((a) > (b)) ? (a) : (b))
#define Q_recip( a )	((float)(1.0f / (float)(a)))
#define Q_floor( a )	((float)(int)(a))
#define Q_ceil( a )		((float)(int)((a) + 1))
#define Q_round( x, y )	(floor( x / y + 0.5 ) * y )
#define Q_rint(x)		((x) < 0 ? ((int)((x)-0.5f)) : ((int)((x)+0.5f)))
#define IS_NAN(x)		(((*(int *)&x) & (255<<23)) == (255<<23))

#define ALIGN( x, a )	((( x ) + (( size_t )( a ) - 1 )) & ~(( size_t )( a ) - 1 ))

float rsqrt( float number );
float anglemod( float a );
uint16_t FloatToHalf( float v );
float HalfToFloat( uint16_t h );
float SimpleSpline( float value );
void RoundUpHullSize( float size[3] );
int SignbitsForPlane( const float normal[3] );
int PlaneTypeForNormal( const float normal[3] );
int NearestPOW( int value, qboolean roundDown );
void SinCos( float radians, float *sine, float *cosine );
float VectorNormalizeLength2( const float v[3], float out[3] );
qboolean VectorCompareEpsilon( const float vec1[3], const float vec2[3], vec_t epsilon );
void VectorVectors( const float forward[3], float right[3], float up[3] );
void VectorAngles( const float *forward, float *angles );
void AngleVectors( const float angles[3], float forward[3], float right[3], float up[3] );
void VectorsAngles( const float forward[3], const float right[3], const float up[3], float angles[3] );
qboolean PlanesGetIntersectionPoint( const struct mplane_s *plane1, const struct mplane_s *plane2, const struct mplane_s *plane3, float out[3] );
void PlaneIntersect( const struct mplane_s *plane, const float p0[3], const float p1[3], float out[3] );

//=============================================================================================//
// Originally in pm_math.cpp
void AngleMatrix( const float *angles, float (*matrix)[4] );
void VectorTransform( const float *in1, float in2[3][4], float *out );
void AngleIMatrix( const float angles[3], float matrix[3][4] );
void InterpolateAngles( float *start, float *end, float *output, float frac );
void NormalizeAngles( float *angles );
//=============================================================================================//

void ClearBounds( float mins[3], float maxs[3] );
void AddPointToBounds( const float v[3], float mins[3], float maxs[3] );
qboolean BoundsIntersect( const float mins1[3], const float maxs1[3], const float mins2[3], const float maxs2[3] );
qboolean BoundsAndSphereIntersect( const float mins[3], const float maxs[3], const float origin[3], float radius );
qboolean SphereIntersect( const float vSphereCenter[3], float fSphereRadiusSquared, const float vLinePt[3], const float vLineDir[3] );
float RadiusFromBounds( const float mins[3], const float maxs[3] );
void ExpandBounds( float mins[3], float maxs[3], float offset );

void AngleQuaternion( const float angles[3], vec4_t q, qboolean studio );
void QuaternionAngle( const vec4_t q, float angles[3] );
void QuaternionSlerp( const vec4_t p, const vec4_t q, float t, vec4_t qt );
float RemapVal( float val, float A, float B, float C, float D );
float ApproachVal( float target, float value, float speed );

void AngleVectorsTranspose (const float angles[3], float forward[3], float right[3], float up[3]);


extern vec3_t		vec3_origin;
extern int		boxpnt[6][4];
extern const matrix3x4	matrix3x4_identity;
extern const matrix4x4	matrix4x4_identity;
extern const float		m_bytenormals[NUMVERTEXNORMALS][3];
