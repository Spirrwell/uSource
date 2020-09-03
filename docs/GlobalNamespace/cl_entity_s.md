# struct cl_entity_s

*Defined at line 66 of ./common/cl_entity.h*

## Members

public int index

public qboolean player

entity_state_s baseline

entity_state_s prevstate

entity_state_s curstate

public int current_position

public position_history_t [64] ph

 mouth

 latched

public float lastmove

public vec3_t origin

public vec3_t angles

public vec3_t [4] attachment

public int trivial_accept

public struct model_s * model

public struct efrag_s * efrag

public struct mnode_s * topnode

public float syncbase

public int visframe

 cvFloorColor



