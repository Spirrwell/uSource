# struct SDL_HapticRamp

*Defined at line 639 of /usr/include/SDL2/SDL_haptic.h*



**brief** A structure containing a template for a Ramp effect.

  This struct is exclusively for the ::SDL_HAPTIC_RAMP effect.

  The ramp effect starts at start strength and ends at end strength.  It augments in linear fashion.  If you use attack and fade with a ramp  the effects get added to the ramp effect making the effect become  quadratic instead of linear.



**sa** SDL_HAPTIC_RAMP

**sa** SDL_HapticEffect



## Members

public Uint16 type

SDL_HapticDirection direction

public Uint32 length

public Uint16 delay

public Uint16 button

public Uint16 interval

public Sint16 start

public Sint16 end

public Uint16 attack_length

public Uint16 attack_level

public Uint16 fade_length

public Uint16 fade_level



