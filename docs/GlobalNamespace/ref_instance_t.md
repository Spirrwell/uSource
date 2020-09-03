# struct ref_instance_t

*Defined at line 132 of ./ref_gl/gl_local.h*

## Members

public int params

public qboolean drawWorld

public qboolean isSkyVisible

public qboolean onlyClientDraw

public qboolean drawOrtho

public float fov_x

public float fov_y

public cl_entity_t * currententity

public model_t * currentmodel

public cl_entity_t * currentbeam

public int [4] viewport

gl_frustum_s frustum

public mleaf_t * viewleaf

public mleaf_t * oldviewleaf

public vec3_t pvsorigin

public vec3_t vieworg

public vec3_t viewangles

public vec3_t vforward

public vec3_t vright

public vec3_t vup

public vec3_t cullorigin

public vec3_t cull_vforward

public vec3_t cull_vright

public vec3_t cull_vup

public float farClip

public qboolean fogCustom

public qboolean fogEnabled

public qboolean fogSkybox

public vec4_t fogColor

public float fogDensity

public float fogStart

public float fogEnd

public int cached_contents

public int cached_waterlevel

public float [2][6] skyMins

public float [2][6] skyMaxs

public matrix4x4 objectMatrix

public matrix4x4 worldviewMatrix

public matrix4x4 modelviewMatrix

public matrix4x4 projectionMatrix

public matrix4x4 worldviewProjectionMatrix

public byte [4096] visbytes

public float viewplanedist

mplane_s clipPlane



