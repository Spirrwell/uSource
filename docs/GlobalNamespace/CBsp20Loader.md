# class CBsp20Loader

*Defined at line 22 of ./engine/common/mod_bsp20.cpp*

Inherits from IMapLoader



## Members

public vec3_t mins

public vec3_t maxs



## Functions

### CBsp20Loader

*public void CBsp20Loader()*

*Defined at line 61 of ./engine/common/mod_bsp20.cpp*

### ~CBsp20Loader

*public void ~CBsp20Loader()*

*Defined at line 26 of ./engine/common/mod_bsp20.cpp*

### CheckBuffer

*public _Bool CheckBuffer(const void * buf, size_t len)*

*Defined at line 67 of ./engine/common/mod_bsp20.cpp*

 Check the version of the map 

### LoadMap

*public _Bool LoadMap(model_t * mod, const void * buffer, size_t length)*

*Defined at line 74 of ./engine/common/mod_bsp20.cpp*

### AddPointToVolume

*public void AddPointToVolume(vec3_t point)*

*Defined at line 273 of ./engine/common/mod_bsp20.cpp*

### LoadEntityLump

*public void LoadEntityLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 95 of ./engine/common/mod_bsp20.cpp*

 Lump loading functions 

### LoadPlaneLump

*public void LoadPlaneLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 102 of ./engine/common/mod_bsp20.cpp*

### LoadTexDatLump

*public void LoadTexDatLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 130 of ./engine/common/mod_bsp20.cpp*

### LoadVertexLump

*public void LoadVertexLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 134 of ./engine/common/mod_bsp20.cpp*

### LoadVisLump

*public void LoadVisLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 146 of ./engine/common/mod_bsp20.cpp*

### LoadNodeLump

*public void LoadNodeLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 151 of ./engine/common/mod_bsp20.cpp*

### LoadTexInfoLump

*public void LoadTexInfoLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 183 of ./engine/common/mod_bsp20.cpp*

### LoadFaceLump

*public void LoadFaceLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 188 of ./engine/common/mod_bsp20.cpp*

### LoadLightingLump

*public void LoadLightingLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 193 of ./engine/common/mod_bsp20.cpp*

### LoadOcclusionLump

*public void LoadOcclusionLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 198 of ./engine/common/mod_bsp20.cpp*

### LoadLeafLump

*public void LoadLeafLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 203 of ./engine/common/mod_bsp20.cpp*

### LoadFaceIdLump

*public void LoadFaceIdLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 49 of ./engine/common/mod_bsp20.cpp*

### LoadEdgeLump

*public void LoadEdgeLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 220 of ./engine/common/mod_bsp20.cpp*

### LoadSurfEdgeLump

*public void LoadSurfEdgeLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 225 of ./engine/common/mod_bsp20.cpp*

### LoadModelLump

*public void LoadModelLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 230 of ./engine/common/mod_bsp20.cpp*

### LoadWLightLump

*public void LoadWLightLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 253 of ./engine/common/mod_bsp20.cpp*

### LoadLeafFaceLump

*public void LoadLeafFaceLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 258 of ./engine/common/mod_bsp20.cpp*

### LoadLeafBrushLump

*public void LoadLeafBrushLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 263 of ./engine/common/mod_bsp20.cpp*

### LoadBrushLump

*public void LoadBrushLump(lump_t lump, const void * buf, size_t length)*

*Defined at line 268 of ./engine/common/mod_bsp20.cpp*



