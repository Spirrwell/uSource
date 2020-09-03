# struct SDL_HapticPeriodic

*Defined at line 549 of /usr/include/SDL2/SDL_haptic.h*



**brief** A structure containing a template for a Periodic effect.

  The struct handles the following effects:   - ::SDL_HAPTIC_SINE   - ::SDL_HAPTIC_LEFTRIGHT   - ::SDL_HAPTIC_TRIANGLE   - ::SDL_HAPTIC_SAWTOOTHUP   - ::SDL_HAPTIC_SAWTOOTHDOWN

  A periodic effect consists in a wave-shaped effect that repeats itself  over time.  The type determines the shape of the wave and the parameters  determine the dimensions of the wave.

  Phase is given by hundredth of a degree meaning that giving the phase a value  of 9000 will displace it 25% of its period.  Here are sample values:   -     0: No phase displacement.   -  9000: Displaced 25% of its period.   - 18000: Displaced 50% of its period.   - 27000: Displaced 75% of its period.   - 36000: Displaced 100% of its period, same as 0, but 0 is preferred.

  Examples:

    SDL_HAPTIC_SINE

      __      __      __      __

     /  \    /  \    /  \    /

    /    \__/    \__/    \__/



    SDL_HAPTIC_SQUARE

     __    __    __    __    __

    |  |  |  |  |  |  |  |  |  |

    |  |__|  |__|  |__|  |__|  |



    SDL_HAPTIC_TRIANGLE

      /\    /\    /\    /\    /\

     /  \  /  \  /  \  /  \  /

    /    \/    \/    \/    \/



    SDL_HAPTIC_SAWTOOTHUP

      /|  /|  /|  /|  /|  /|  /|

     / | / | / | / | / | / | / |

    /  |/  |/  |/  |/  |/  |/  |



    SDL_HAPTIC_SAWTOOTHDOWN

    \  |\  |\  |\  |\  |\  |\  |

     \ | \ | \ | \ | \ | \ | \ |

      \|  \|  \|  \|  \|  \|  \|



**sa** SDL_HAPTIC_SINE

**sa** SDL_HAPTIC_LEFTRIGHT

**sa** SDL_HAPTIC_TRIANGLE

**sa** SDL_HAPTIC_SAWTOOTHUP

**sa** SDL_HAPTIC_SAWTOOTHDOWN

**sa** SDL_HapticEffect



## Members

public Uint16 type

SDL_HapticDirection direction

public Uint32 length

public Uint16 delay

public Uint16 button

public Uint16 interval

public Uint16 period

public Sint16 magnitude

public Sint16 offset

public Uint16 phase

public Uint16 attack_length

public Uint16 attack_level

public Uint16 fade_length

public Uint16 fade_level



