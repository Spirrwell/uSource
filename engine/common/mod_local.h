/*
mod_local.h - model loader
Copyright (C) 2007 Uncle Mike

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

#ifndef MOD_LOCAL_H
#define MOD_LOCAL_H

//#include "common.h"
#include "edict.h"
#include "eiface.h"
#include "ref_int.h"

#define LM_SAMPLE_SIZE		16
#define LM_SAMPLE_EXTRASIZE		8

#define MAX_MAP_WADS		256	// max wads that can be referenced per one map

#define CHECKVISBIT( vis, b )		((b) >= 0 ? (byte)((vis)[(b) >> 3] & (1 << ((b) & 7))) : (byte)false )
#define SETVISBIT( vis, b )( void )	((b) >= 0 ? (byte)((vis)[(b) >> 3] |= (1 << ((b) & 7))) : (byte)false )
#define CLEARVISBIT( vis, b )( void )	((b) >= 0 ? (byte)((vis)[(b) >> 3] &= ~(1 << ((b) & 7))) : (byte)false )

#define REFPVS_RADIUS		2.0f	// radius for rendering
#define FATPVS_RADIUS		8.0f	// FatPVS use radius smaller than the FatPHS
#define FATPHS_RADIUS		16.0f

#define WORLD_INDEX			(1)	// world index is always 1

typedef struct consistency_s
{
	const char	*filename;
	int		orig_index;
	int		check_type;
	qboolean		issound;
	int		value;
	vec3_t		mins;
	vec3_t		maxs;
} consistency_t;

#define FCRC_SHOULD_CHECKSUM	BIT( 0 )
#define FCRC_CHECKSUM_DONE	BIT( 1 )

typedef struct
{
	int		flags;
	CRC32_t		initialCRC;
} model_info_t;

// values for model_t's needload
#define NL_UNREFERENCED	0		// this model can be freed after sequence precaching is done
#define NL_NEEDS_LOADED	1
#define NL_PRESENT		2

typedef struct hullnode_s
{
	struct hullnode_s	*next;
	struct hullnode_s	*prev;
} hullnode_t;

typedef struct winding_s
{
	const mplane_t	*plane;
	struct winding_s	*pair;
	hullnode_t	chain;
	int		numpoints;
	vec3_t		p[4];		// variable sized
} winding_t;

typedef struct
{
	hullnode_t	polys;
	uint		num_polys;
} hull_model_t;


typedef struct world_static_s
{
	qboolean		loading;		// true if worldmodel is loading
	int		flags;		// misc flags

	// mapstats info
	char		message[2048];	// just for debug
	char		compiler[256];	// map compiler
	char		generator[256];	// map editor

	hull_model_t	*hull_models;
	int		num_hull_models;

	// out pointers to light data
	color24		*deluxedata;	// deluxemap data pointer
	byte		*shadowdata;	// occlusion data pointer

	// visibility info
	size_t		visbytes;		// cluster size
	size_t		fatbytes;		// fatpvs size

	// world bounds
	vec3_t		mins;		// real accuracy world bounds
	vec3_t		maxs;
	vec3_t		size;

	// tree visualization stuff
	int		recursion_level;
	int		max_recursion;
} world_static_t;

#ifndef REF_DLL

/* Custom model loader class */
/* Not actually a pure interface! be sure to call the default constructor! */
class IModelLoader
{
public:
	IModelLoader(const char* const* extensions, int nextensions);

	virtual ~IModelLoader();

	/**
	 * This function should check if the specified buffer is of this format
	 * 	you'll usually want to check signatures and versions in here
	 * 	This is pretty much to remedy issues of files with multiple versions and the same extension
	 * 	(e.g. bsp which has versions 20, 21, 22, etc.)
	 * @param buf Pointer to the buffer
	 * @param len Length of the buffer
	 * @return
	 */
	virtual bool CheckBuffer(const void* buf, size_t len) = 0;

	virtual bool LoadModel(model_t* mod, const void* buffer, size_t length) = 0;
};

/* Custom map loader class */
class IMapLoader
{
public:
	IMapLoader(const char* const* extensions, int nextensions);

	virtual ~IMapLoader();

	/**
	 * This function should check if the specified buffer is of this format
	 * 	you'll usually want to check signatures and versions in here
	 * 	This is pretty much to remedy issues of files with multiple versions and the same extension
	 * 	(e.g. bsp which has versions 20, 21, 22, etc.)
	 * @param buf Pointer to the buffer
	 * @param len Length of the buffer
	 * @return
	 */
	virtual bool CheckBuffer(const void* buf, size_t len) = 0;

	virtual bool LoadMap(model_t* map_model, const void* buffer, size_t length) = 0;
};

/* Model type enums */
enum class EModelType
{
	UNKNOWN = 0,
	NORMAL, /* Everything that isn't a map basically */
	MAP,
};

extern world_static_t	world;
extern byte		*com_studiocache;
extern model_t		*loadmodel;
extern convar_t		*mod_studiocache;
extern convar_t		*r_wadtextures;
extern convar_t		*r_showhull;

//
// model.c
//
void Mod_Init( void );
void Mod_FreeModel( model_t *mod );
void Mod_FreeAll( void );
void Mod_Shutdown( void );
void Mod_ClearUserData( void );
model_t *Mod_LoadWorld( const char *name, qboolean preload );
void *Mod_Calloc( int number, size_t size );
void *Mod_CacheCheck( struct cache_user_s *c );
void Mod_LoadCacheFile( const char *path, struct cache_user_s *cu );
void *Mod_AliasExtradata( model_t *mod );
void *Mod_StudioExtradata( model_t *mod );
model_t *Mod_FindName( const char *name, qboolean trackCRC );
model_t *Mod_LoadModel( model_t *mod, qboolean crash, EModelType type = EModelType::NORMAL );
model_t *Mod_ForName( const char *name, qboolean crash, qboolean trackCRC );
qboolean Mod_ValidateCRC( const char *name, CRC32_t crc );
void Mod_NeedCRC( const char *name, qboolean needCRC );
void Mod_FreeUnused( void );
model_t *Mod_Handle( int handle );

//
// mod_bmodel.c
//
void Mod_LoadBrushModel( model_t *mod, const void *buffer, qboolean *loaded );
qboolean Mod_TestBmodelLumps( const char *name, const byte *mod_base, qboolean silent );
qboolean Mod_HeadnodeVisible( mnode_t *node, const byte *visbits, int *lastleaf );
int Mod_FatPVS( const vec3_t org, float radius, byte *visbuffer, int visbytes, qboolean merge, qboolean fullvis );
qboolean Mod_BoxVisible( const vec3_t mins, const vec3_t maxs, const byte *visbits );
int Mod_CheckLump( const char *filename, const int lump, int *lumpsize );
int Mod_ReadLump( const char *filename, const int lump, void **lumpdata, int *lumpsize );
int Mod_SaveLump( const char *filename, const int lump, void *lumpdata, int lumpsize );
mleaf_t *Mod_PointInLeaf( const vec3_t p, mnode_t *node );
void Mod_AmbientLevels( const vec3_t p, byte *pvolumes );
int Mod_SampleSizeForFace( msurface_t *surf );
byte *Mod_GetPVSForPoint( const vec3_t p );
void Mod_UnloadBrushModel( model_t *mod );
void Mod_PrintWorldStats_f( void );

//
// mod_dbghulls.c
//
void Mod_InitDebugHulls( void );
void Mod_CreatePolygonsForHull( int hullnum );
void Mod_ReleaseHullPolygons( void );

//
// mod_studio.c
//
typedef struct studiohdr_s studiohdr_t;
typedef struct mstudioseqdesc_s mstudioseqdesc_t;
typedef struct mstudiobone_s mstudiobone_t;
typedef struct mstudioanim_s mstudioanim_t;
void Mod_LoadStudioModel( model_t *mod, const void *buffer, qboolean *loaded );
void Mod_UnloadStudioModel( model_t *mod );
void Mod_InitStudioAPI( void );
void Mod_InitStudioHull( void );
void Mod_ResetStudioAPI( void );
const char *Mod_StudioTexName( const char *modname );
qboolean Mod_GetStudioBounds( const char *name, vec3_t mins, vec3_t maxs );
void Mod_StudioGetAttachment( const edict_t *e, int iAttachment, float *org, float *ang );
void Mod_GetBonePosition( const edict_t *e, int iBone, float *org, float *ang );
hull_t *Mod_HullForStudio( model_t *m, float frame, int seq, vec3_t ang, vec3_t org, vec3_t size, byte *pcnt, byte *pbl, int *hitboxes, edict_t *ed );
void R_StudioSlerpBones( int numbones, vec4_t q1[], float pos1[][3], vec4_t q2[], float pos2[][3], float s );
void R_StudioCalcBoneQuaternion( int frame, float s, mstudiobone_t *pbone, mstudioanim_t *panim, float *adj, vec4_t q );
void R_StudioCalcBonePosition( int frame, float s, mstudiobone_t *pbone, mstudioanim_t *panim, vec3_t adj, vec3_t pos );
void *R_StudioGetAnim( studiohdr_t *m_pStudioHeader, model_t *m_pSubModel, mstudioseqdesc_t *pseqdesc );
void Mod_StudioComputeBounds( void *buffer, vec3_t mins, vec3_t maxs, qboolean ignore_sequences );
int Mod_HitgroupForStudioHull( int index );
void Mod_ClearStudioCache( void );

//
// mod_sprite.c
//
void Mod_LoadSpriteModel( model_t *mod, const void *buffer, qboolean *loaded, uint texFlags );
#endif

#endif//MOD_LOCAL_H
