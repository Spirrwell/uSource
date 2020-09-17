/*

common.h

Common definitions and such 

*/
#pragma once

#ifndef Q_min
#undef Q_min
#define Q_min(a,b)  (((a) < (b)) ? (a) : (b))
#endif
#ifndef Q_max
#undef Q_max
#define Q_max(a,b)  (((a) > (b)) ? (a) : (b))
#endif

#ifdef _WIN32
#include <wchar.h> // off_t
#endif // _WIN32

#include <sys/types.h> // off_t

/* For the vector types and stuff */
#include "../mathlib/matrix.h"
#include "../mathlib/vector.h"

/* Basic types */
#include "common/types.h"

/*============================
Disable warnings 
==============================*/
// Silence certain warnings
#ifdef _MSC_VER
#	pragma warning(disable : 4244)		// int or float down-conversion
#	pragma warning(disable : 4305)		// int or float data truncation
#	pragma warning(disable : 4201)		// nameless struct/union
#	pragma warning(disable : 4514)		// unreferenced inline function removed
#	pragma warning(disable : 4100)		// unreferenced formal parameter
#endif


#define MAX_STRING		256	// generic string
#define MAX_INFO_STRING	256	// infostrings are transmitted across network
#define MAX_SERVERINFO_STRING	512	// server handles too many settings. expand to 1024?
#define MAX_LOCALINFO_STRING	32768	// localinfo used on server and not sended to the clients
#define MAX_SYSPATH		1024	// system filepath
#define MAX_PRINT_MSG	8192	// how many symbols can handle single call of Con_Printf or Con_DPrintf
#define MAX_TOKEN		2048	// parse token length
#define MAX_MODS		512	// environment games that engine can keep visible
#define MAX_USERMSG_LENGTH	2048	// don't modify it's relies on a client-side definitions

#define BIT( n )		( 1U << ( n ))
#define GAMMA		( 2.2 )		// Valve Software gamma
#define INVGAMMA		( 1.0 / 2.2 )	// back to 1.0
#define TEXGAMMA		( 0.9 )		// compensate dim textures

#undef SetBits
#undef ClearBits
#undef FBitSet

template<class T, class U>
static void SetBits(T& iBitVector, U bits)
{
	uint64_t _iBitVector = (uint64_t)iBitVector;
	uint64_t _bits = (uint64_t)bits;
	iBitVector = (T)(_iBitVector | _bits);
}

template<class T, class U>
static void ClearBits(T& iBitVector, U bits)
{
	uint64_t _iBitVector = (uint64_t)iBitVector;
	uint64_t _bits = (uint64_t)bits;
	iBitVector = (T)((_iBitVector) & ~_bits);
}

template<class T, class U>
static bool FBitSet(T iBitVec, U bit)
{
	uint64_t _iBitVector = (uint64_t)iBitVec;
	uint64_t _bits = (uint64_t)bit;
	return _iBitVector & _bits;
}

#ifndef __cplusplus
#ifdef NULL
#undef NULL
#endif

#define NULL		((void *)0)
#endif

static bool IsColorString(const char* p) { return (( p && *( p ) == '^' && *(( p ) + 1) && *(( p ) + 1) >= '0' && *(( p ) + 1 ) <= '9' )); };
static bool ColorIndex(char c) { return (c - '0') & 7; };

#if defined(__GNUC__)
#ifdef __i386__
#define EXPORT __attribute__ ((visibility ("default"),force_align_arg_pointer))
#define GAME_EXPORT __attribute((force_align_arg_pointer))
#else
#define EXPORT __attribute__ ((visibility ("default")))
#define GAME_EXPORT
#endif
#elif defined(_MSC_VER)
#define EXPORT          __declspec( dllexport )
#define IMPORT          __declspec( dllimport )
#define GAME_EXPORT
#else
#define EXPORT
#define IMPORT
#define GAME_EXPORT
#endif


#ifdef XASH_BIG_ENDIAN
#define LittleLong(x) (((int)(((x)&255)<<24)) + ((int)((((x)>>8)&255)<<16)) + ((int)(((x)>>16)&255)<<8) + (((x) >> 24)&255))
#define LittleLongSW(x) (x = LittleLong(x) )
#define LittleShort(x) ((short)( (((short)(x) >> 8) & 255) + (((short)(x) & 255) << 8)))
#define LittleShortSW(x) (x = LittleShort(x) )
_inline float LittleFloat( float f )
{
	union
	{
		float f;
		unsigned char b[4];
	} dat1, dat2;

	dat1.f = f;
	dat2.b[0] = dat1.b[3];
	dat2.b[1] = dat1.b[2];
	dat2.b[2] = dat1.b[1];
	dat2.b[3] = dat1.b[0];

	return dat2.f;
}

template<class T>
T ToLittleEndian(T& x)
{
	if(sizeof(T) == 1) return x;
	T y = x;
	x = 0;
	for(int i = 0; i < sizeof(T); i++)
	{
		x += (y&255) << (i*8);
		y >>= 8;
	}
	return x;
}

template<class T>
T ToBigEndian(T& x)
{
	return x;
}

#else
#define LittleLong(x) (x)
#define LittleLongSW(x)
#define LittleShort(x) (x)
#define LittleShortSW(x)
#define LittleFloat(x) (x)

template<class T>
T ToLittleEndian(T& x)
{
	return x;
}

template<class T>
T ToBigEndian(T& x)
{
	if(sizeof(T) == 1) return x;
	T y = x;
	x = 0;
	for(int i = 0; i < sizeof(T); i++)
	{
		x += (y&255) >> (i*8);
		y <<= 8;
	}
	return x;
}


#endif

typedef char		string[MAX_STRING];
typedef struct file_s	file_t;		// normal file
typedef struct wfile_s	wfile_t;		// wad file
typedef struct stream_s	stream_t;		// sound stream for background music playing
typedef off_t fs_offset_t;

typedef struct dllfunc_s
{
	const char	*name;
	void		**func;
} dllfunc_t;

typedef struct dll_info_s
{
	const char	*name;	// name of library
	const dllfunc_t	*fcts;	// list of dll exports
	qboolean		crash;	// crash if dll not found
	void		*link;	// hinstance of loading library
} dll_info_t;

typedef void (*setpair_t)( const char *key, const void *value, void *buffer, void *numpairs );

// config strings are a general means of communication from
// the server to all connected clients.
// each config string can be at most CS_SIZE characters.
#define MAX_QPATH		64	// max length of a game pathname
#define MAX_OSPATH		260	// max length of a filesystem pathname
#define CS_SIZE		64	// size of one config string
#define CS_TIME		16	// size of time string

/* 

pulled from the server extdll.h

*/
typedef unsigned int func_t;
typedef int string_t;				// from engine's pr_comp.h;
