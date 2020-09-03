# struct mextrasurf_s

*Defined at line 209 of ./common/com_model.h*

 surface extradata



## Members

public vec3_t mins

public vec3_t maxs

public vec3_t origin

public struct msurface_s * surf

public int dlight_s

public int dlight_t

public short [2] lightmapmins

public short [2] lightextents

public float [2][4] lmvecs

public color24 * deluxemap

public byte * shadowmap

public struct msurface_s * lightmapchain

public struct mextrasurf_s * detailchain

public mfacebevel_t * bevel

public struct mextrasurf_s * lumachain

public struct cl_entity_s * parent

public int mirrortexturenum

public float [4][4] mirrormatrix

public struct grasshdr_s * grass

public unsigned short grasscount

public unsigned short numverts

public int firstvertex

public int [32] reserved



