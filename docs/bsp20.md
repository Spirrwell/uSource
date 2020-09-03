# namespace bsp20



 Wrap it all in a namespace 



## Records

lump_t

dheader_t

dplane_t

dedge_t

dbrush_t

dbrushside_t

dnode_t

dleaf_t

texinfo_t

dtexdata_t

dmodel_t

dvis_t

dgamelump_t

dgamelumpheader_t



## Functions

### NUM_DISP_POWER_VERTS

*unsigned int NUM_DISP_POWER_VERTS(unsigned int power)*

*Defined at line 83 of ./common/bsp20file.h*

### NUM_DISP_POWER_TRIS

*unsigned int NUM_DISP_POWER_TRIS(unsigned int power)*

*Defined at line 84 of ./common/bsp20file.h*



## Enums

| enum  |

--

| CHILDNODE_UPPER_RIGHT |
| CHILDNODE_UPPER_LEFT |
| CHILDNODE_LOWER_LEFT |
| CHILDNODE_LOWER_RIGHT |


*Defined at line 127 of ./common/bsp20file.h*

| enum  |

--

| CORNER_LOWER_LEFT |
| CORNER_UPPER_LEFT |
| CORNER_UPPER_RIGHT |
| CORNER_LOWER_RIGHT |


*Defined at line 135 of ./common/bsp20file.h*

| enum  |

--

| NEIGHBOREDGE_LEFT |
| NEIGHBOREDGE_TOP |
| NEIGHBOREDGE_RIGHT |
| NEIGHBOREDGE_BOTTOM |


*Defined at line 143 of ./common/bsp20file.h*

| enum  |

--

| CORNER_TO_CORNER |
| CORNER_TO_MIDPOINT |
| MIDPOINT_TO_CORNER |


*Defined at line 151 of ./common/bsp20file.h*

| enum  |

--

| ORIENTATION_CCW_0 |
| ORIENTATION_CCW_90 |
| ORIENTATION_CCW_180 |
| ORIENTATION_CCW_270 |


*Defined at line 158 of ./common/bsp20file.h*

| enum  |

--

| _LUMP_ENTITIES |
| _LUMP_PLANES |
| _LUMP_TEXDATA |
| _LUMP_VERTEXES |
| _LUMP_VISIBILITY |
| _LUMP_NODES |
| _LUMP_TEXINFO |
| _LUMP_FACES |
| _LUMP_LIGHTING |
| _LUMP_OCCLUSION |
| _LUMP_LEAFS |
| _LUMP_FACEIDS |
| _LUMP_EDGES |
| _LUMP_SURFEDGES |
| _LUMP_MODELS |
| _LUMP_WORLDLIGHTS |
| _LUMP_LEAFFACES |
| _LUMP_LEAFBRUSHES |
| _LUMP_BRUSHES |
| _LUMP_BRUSHSIDES |
| _LUMP_AREAS |
| _LUMP_AREAPORTALS |
| _LUMP_UNUSED0 |
| _LUMP_UNUSED1 |
| _LUMP_UNUSED2 |
| _LUMP_UNUSED3 |
| _LUMP_DISPINFO |
| _LUMP_ORIGINALFACES |
| _LUMP_PHYSDISP |
| _LUMP_PHYSCOLLIDE |
| _LUMP_VERTNORMALS |
| _LUMP_VERTNORMALINDICES |
| _LUMP_DISP_LIGHTMAP_ALPHAS |
| _LUMP_DISP_VERTS |
| _LUMP_DISP_LIGHTMAP_SAMPLE_POSITIONS |
| _LUMP_GAME_LUMP |
| _LUMP_LEAFWATERDATA |
| _LUMP_PRIMITIVES |
| _LUMP_PRIMVERTS |
| _LUMP_PRIMINDICES |
| _LUMP_PAKFILE |
| _LUMP_CLIPPORTALVERTS |
| _LUMP_CUBEMAPS |
| _LUMP_TEXDATA_STRING_DATA |
| _LUMP_TEXDATA_STRING_TABLE |
| _LUMP_OVERLAYS |
| _LUMP_LEAFMINDISTTOWATER |
| _LUMP_FACE_MACRO_TEXTURE_INFO |
| _LUMP_DISP_TRIS |
| _LUMP_PHYSCOLLIDESURFACE |
| _LUMP_WATEROVERLAYS |
| _LUMP_LEAF_AMBIENT_INDEX_HDR |
| _LUMP_LEAF_AMBIENT_INDEX |
| _LUMP_LIGHTING_HDR |
| _LUMP_WORLDLIGHTS_HDR |
| _LUMP_LEAF_AMBIENT_LIGHTING_HDR |
| _LUMP_LEAF_AMBIENT_LIGHTING |
| _LUMP_XZIPPAKFILE |
| _LUMP_FACES_HDR |
| _LUMP_MAP_FLAGS |
| _LUMP_OVERLAY_FADES |


*Defined at line 166 of ./common/bsp20file.h*

| enum class EBsp20LumpVersions |

--

| LUMP_LIGHTING_VERSION |
| LUMP_FACES_VERSION |
| LUMP_OCCLUSION_VERSION |
| LUMP_LEAFS_VERSION |
| LUMP_LEAF_AMBIENT_LIGHTING_VERSION |


*Defined at line 231 of ./common/bsp20file.h*

| enum  |

--

| SURF_LIGHT |
| SURF_SKY2D |
| SURF_SKY |
| SURF_WARP |
| SURF_TRANS |
| SURF_NOPORTAL |
| SURF_TRIGGER |
| SURF_NODRAW |
| SURF_HINT |
| SURF_SKIP |
| SURF_NOLIGHT |
| SURF_BUMPLIGHT |
| SURF_NOSHADOWS |
| SURF_NODECALS |
| SURF_NOCHOP |
| SURF_HITBOX |


*Defined at line 314 of ./common/bsp20file.h*

 Flags for texinfo_t::flags 



