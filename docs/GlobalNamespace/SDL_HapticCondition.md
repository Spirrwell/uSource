# struct SDL_HapticCondition

*Defined at line 602 of /usr/include/SDL2/SDL_haptic.h*



**brief** A structure containing a template for a Condition effect.

  The struct handles the following effects:   - ::SDL_HAPTIC_SPRING: Effect based on axes position.   - ::SDL_HAPTIC_DAMPER: Effect based on axes velocity.   - ::SDL_HAPTIC_INERTIA: Effect based on axes acceleration.   - ::SDL_HAPTIC_FRICTION: Effect based on axes movement.

  Direction is handled by condition internals instead of a direction member.  The condition effect specific members have three parameters.  The first  refers to the X axis, the second refers to the Y axis and the third  refers to the Z axis.  The right terms refer to the positive side of the  axis and the left terms refer to the negative side of the axis.  Please  refer to the ::SDL_HapticDirection diagram for which side is positive and  which is negative.



**sa** SDL_HapticDirection

**sa** SDL_HAPTIC_SPRING

**sa** SDL_HAPTIC_DAMPER

**sa** SDL_HAPTIC_INERTIA

**sa** SDL_HAPTIC_FRICTION

**sa** SDL_HapticEffect



## Members

public Uint16 type

SDL_HapticDirection direction

public Uint32 length

public Uint16 delay

public Uint16 button

public Uint16 interval

public Uint16 [3] right_sat

public Uint16 [3] left_sat

public Sint16 [3] right_coeff

public Sint16 [3] left_coeff

public Uint16 [3] deadband

public Sint16 [3] center



