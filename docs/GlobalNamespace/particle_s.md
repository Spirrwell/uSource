# struct particle_s

*Defined at line 34 of ./common/particledef.h*

 cl_tent.c



## Members

public vec3_t org

public short color

public short packedColor

public struct particle_s * next

public vec3_t vel

public float ramp

public float die

public ptype_t type

public void (*)(struct particle_s *) deathfunc

public void (*)(struct particle_s *, float) callback

public unsigned char context



