# union SDL_HapticEffect

*Defined at line 800 of /usr/include/SDL2/SDL_haptic.h*



**brief** The generic template for any haptic effect.

  All values max at 32767 (0x7FFF).  Signed values also can be negative.  Time values unless specified otherwise are in milliseconds.

  You can also pass ::SDL_HAPTIC_INFINITY to length instead of a 0-32767  value.  Neither delay, interval, attack_length nor fade_length support  ::SDL_HAPTIC_INFINITY.  Fade will also not be used since effect never ends.

  Additionally, the ::SDL_HAPTIC_RAMP effect does not support a duration of  ::SDL_HAPTIC_INFINITY.

  Button triggers may not be supported on all devices, it is advised to not  use them if possible.  Buttons start at index 1 instead of index 0 like  the joystick.

  If both attack_length and fade_level are 0, the envelope is not used,  otherwise both values are used.

  Common parts:

  // Replay - All effects have this

  Uint32 length;        // Duration of effect (ms).

  Uint16 delay;         // Delay before starting effect.



  // Trigger - All effects have this

  Uint16 button;        // Button that triggers effect.

  Uint16 interval;      // How soon before effect can be triggered again.



  // Envelope - All effects except condition effects have this

  Uint16 attack_length; // Duration of the attack (ms).

  Uint16 attack_level;  // Level at the start of the attack.

  Uint16 fade_length;   // Duration of the fade out (ms).

  Uint16 fade_level;    // Level at the end of the fade.

  Here we have an example of a constant effect evolution in time:

    Strength

    ^

    |

    |    effect level -->  _________________

    |                     /                 \

    |                    /                   \

    |                   /                     \

    |                  /                       \

    | attack_level --> |                        \

    |                  |                        |  <---  fade_level

    |

    +--------------------------------------------------> Time

                       [--]                 [---]

                       attack_length        fade_length



    [------------------][-----------------------]

    delay               length

  Note either the attack_level or the fade_level may be above the actual  effect level.



**sa** SDL_HapticConstant

**sa** SDL_HapticPeriodic

**sa** SDL_HapticCondition

**sa** SDL_HapticRamp

**sa** SDL_HapticLeftRight

**sa** SDL_HapticCustom



## Members

public Uint16 type

SDL_HapticConstant constant

SDL_HapticPeriodic periodic

SDL_HapticCondition condition

SDL_HapticRamp ramp

SDL_HapticLeftRight leftright

SDL_HapticCustom custom



