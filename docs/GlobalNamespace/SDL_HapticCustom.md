# struct SDL_HapticCustom

*Defined at line 704 of /usr/include/SDL2/SDL_haptic.h*



**brief** A structure containing a template for the ::SDL_HAPTIC_CUSTOM effect.

  This struct is exclusively for the ::SDL_HAPTIC_CUSTOM effect.

  A custom force feedback effect is much like a periodic effect, where the  application can define its exact shape.  You will have to allocate the  data yourself.  Data should consist of channels * samples Uint16 samples.

  If channels is one, the effect is rotated using the defined direction.  Otherwise it uses the samples in data for the different axes.



**sa** SDL_HAPTIC_CUSTOM

**sa** SDL_HapticEffect



## Members

public Uint16 type

SDL_HapticDirection direction

public Uint32 length

public Uint16 delay

public Uint16 button

public Uint16 interval

public Uint8 channels

public Uint16 period

public Uint16 samples

public Uint16 * data

public Uint16 attack_length

public Uint16 attack_level

public Uint16 fade_length

public Uint16 fade_level



