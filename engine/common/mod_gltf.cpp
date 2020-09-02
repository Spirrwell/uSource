/**
 *
 * mod_gltf.cpp
 *
 * Model loader for glTf models
 *
 */
#include "common.h"
#include "mod_local.h"
#include "imagelib/imagelib.h"
#include "mem.h"

/* cgltf includes */
#define CGLTF_IMPLEMENTATION
#include "cgltf/cgltf.h"

/* glTf extensions */
const char* g_gltf_extensions[] = {
	"glb",
	"gltf",
};

/* GLTF memory pool */
byte* g_gltf_mem_pool = nullptr;

class CGlTfLoader : public IModelLoader
{
public:
	CGlTfLoader();
	virtual ~CGlTfLoader() {};

	virtual bool LoadModel(model_t* mod, const void* buffer, size_t length);

	virtual bool CheckBuffer(const void* buf, size_t len) { return true; }

private:
	void* Alloc(size_t sz) { return GlobalAllocator()._Mem_Alloc(g_gltf_mem_pool, sz, false, __FILE__, __LINE__); }
	void Free(void* ptr) { GlobalAllocator()._Mem_Free(ptr, __FILE__, __LINE__); }
	bool LoadMesh(model_t* mod, cgltf_data* data);

};
/* Singleton */
static CGlTfLoader g_glTfLoader;

CGlTfLoader::CGlTfLoader() :
	IModelLoader(g_gltf_extensions, ARRAYSIZE(g_gltf_extensions))
{
	if(!g_gltf_mem_pool)
	{
		g_gltf_mem_pool = GlobalAllocator()._Mem_AllocPool("GLTF Loader Pool", __FILE__, __LINE__);
	}
}

bool CGlTfLoader::LoadModel(model_t *mod, const void *buffer, size_t length)
{
	cgltf_options options = {};
	options.memory = {
		[](void* pvt, cgltf_size sz) -> void* {
			return GlobalAllocator()._Mem_Alloc(g_gltf_mem_pool, sz, false, __FILE__, __LINE__);
		},
		[](void* pvt, void* ptr) {
			GlobalAllocator()._Mem_Free(ptr, __FILE__, __LINE__);
		}
	};

	cgltf_data* data = NULL;
	cgltf_result result = cgltf_parse(&options, buffer, 0, &data);

	if(result != cgltf_result_success)
	{
		Con_DPrintf(S_ERROR "GLTF: Failed to load model %s: %u\n", mod->name, result);
		return false;
	}

	/* Just loads the internal buffers */
	cgltf_load_buffers(&options, data, mod->name);

	this->LoadMesh(mod, data);



	cgltf_free(data);

	return false;
}

bool CGlTfLoader::LoadMesh(model_t *mod, cgltf_data *data)
{
	/* Read each mesh */
	for(int i = 0; i < data->meshes_count; i++)
	{
		const cgltf_mesh* mesh = &data->meshes[i];

		/* Read each primitive */
		for(int j = 0; j < mesh->primitives_count; j++)
		{
			const cgltf_primitive* prim = &mesh->primitives[i];
		}
	}
	return false;
}
