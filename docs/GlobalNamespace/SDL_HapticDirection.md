# struct SDL_HapticDirection

*Defined at line 450 of /usr/include/SDL2/SDL_haptic.h*



**brief** Structure that represents a haptic direction.

  This is the direction where the force comes from,  instead of the direction in which the force is exerted.

  Directions can be specified by:   - ::SDL_HAPTIC_POLAR : Specified by polar coordinates.   - ::SDL_HAPTIC_CARTESIAN : Specified by cartesian coordinates.   - ::SDL_HAPTIC_SPHERICAL : Specified by spherical coordinates.

  Cardinal directions of the haptic device are relative to the positioning  of the device.  North is considered to be away from the user.

  The following diagram represents the cardinal directions:

                 .--.

                 |__| .-------.

                 |=.| |.-----.|

                 |--| ||     ||

                 |  | |'-----'|

                 |__|~')_____('

                   [ COMPUTER ]





                     North (0,-1)

                         ^

                         |

                         |

   (-1,0)  West <----[ HAPTIC ]----> East (1,0)

                         |

                         |

                         v

                      South (0,1)





                      [ USER ]

                        \|||/

                        (o o)

                  ---ooO-(_)-Ooo---

  If type is ::SDL_HAPTIC_POLAR, direction is encoded by hundredths of a  degree starting north and turning clockwise.  ::SDL_HAPTIC_POLAR only uses  the first **c**  parameter.  The cardinal directions would be:   - North: 0 (0 degrees)   - East: 9000 (90 degrees)   - South: 18000 (180 degrees)   - West: 27000 (270 degrees)

  If type is ::SDL_HAPTIC_CARTESIAN, direction is encoded by three positions  (X axis, Y axis and Z axis (with 3 axes)).  ::SDL_HAPTIC_CARTESIAN uses  the first three **c**  parameters.  The cardinal directions would be:   - North:  0,-1, 0   - East:   1, 0, 0   - South:  0, 1, 0   - West:  -1, 0, 0

  The Z axis represents the height of the effect if supported, otherwise  it's unused.  In cartesian encoding (1, 2) would be the same as (2, 4), you  can use any multiple you want, only the direction matters.

  If type is ::SDL_HAPTIC_SPHERICAL, direction is encoded by two rotations.  The first two **c**  parameters are used.  The **c**  parameters are as  follows (all values are in hundredths of degrees):   - Degrees from (1, 0) rotated towards (0, 1).   - Degrees towards (0, 0, 1) (device needs at least 3 axes).

  Example of force coming from the south with all encodings (force coming  from the south means the user will have to pull the stick to counteract):

  SDL_HapticDirection direction;



  // Cartesian directions

  direction.type = SDL_HAPTIC_CARTESIAN; // Using cartesian direction encoding.

  direction.dir[0] = 0; // X position

  direction.dir[1] = 1; // Y position

  // Assuming the device has 2 axes, we don't need to specify third parameter.



  // Polar directions

  direction.type = SDL_HAPTIC_POLAR; // We'll be using polar direction encoding.

  direction.dir[0] = 18000; // Polar only uses first parameter



  // Spherical coordinates

  direction.type = SDL_HAPTIC_SPHERICAL; // Spherical encoding

  direction.dir[0] = 9000; // Since we only have two axes we don't need more parameters.



**sa** SDL_HAPTIC_POLAR

**sa** SDL_HAPTIC_CARTESIAN

**sa** SDL_HAPTIC_SPHERICAL

**sa** SDL_HapticEffect

**sa** SDL_HapticNumAxes



## Members

public Uint8 type

public Sint32 [3] dir



