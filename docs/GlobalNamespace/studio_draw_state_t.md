# struct studio_draw_state_t

*Defined at line 61 of ./rendersystem/r_studio.cpp*

## Members

public double time

public double frametime

public int framecount

public qboolean interpolate

public int rendermode

public float blend

public matrix3x4 rotationmatrix

public matrix3x4 [128] bonestransform

public matrix3x4 [128] lighttransform

public matrix3x4 [128] worldtransform

public matrix3x4 [128] cached_bonestransform

public matrix3x4 [128] cached_lighttransform

public char [128][32] cached_bonenames

public int cached_numbones

public sortedmesh_t [256] meshes

public vec3_t [16384] verts

public vec3_t [16384] norms

public float ambientlight

public float shadelight

public vec3_t lightvec

public vec3_t lightspot

public vec3_t lightcolor

public vec3_t [128] blightvec

public vec3_t [16384] lightvalues

public vec3_t chrome_origin

public vec2_t [16384] chrome

public vec3_t [128] chromeright

public vec3_t [128] chromeup

public int [128] chromeage

public int [16384] normaltable

public int numlocallights

public int [128] lightage

public dlight_t *[4] locallight

public color24 [4] locallightcolor

public vec4_t [16384][4] lightpos

public vec3_t [128][4] lightbonepos

public float [4] locallightR2

public player_model_t [32] player_models

public vec3_t [16384] arrayverts

public vec2_t [16384] arraycoord

public unsigned short [98304] arrayelems

public GLubyte [16384][4] arraycolor

public uint numverts

public uint numelems



