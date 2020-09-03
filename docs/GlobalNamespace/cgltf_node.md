# struct cgltf_node

*Defined at line 477 of ./thirdparty/cgltf/cgltf.h*

## Members

public char * name

public struct cgltf_node * parent

public struct cgltf_node ** children

public cgltf_size children_count

public cgltf_skin * skin

public cgltf_mesh * mesh

public cgltf_camera * camera

public cgltf_light * light

public cgltf_float * weights

public cgltf_size weights_count

public cgltf_bool has_translation

public cgltf_bool has_rotation

public cgltf_bool has_scale

public cgltf_bool has_matrix

public cgltf_float [3] translation

public cgltf_float [4] rotation

public cgltf_float [3] scale

public cgltf_float [16] matrix

cgltf_extras extras



