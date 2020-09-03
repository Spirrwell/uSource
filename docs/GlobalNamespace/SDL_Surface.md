# struct SDL_Surface

*Defined at line 70 of /usr/include/SDL2/SDL_surface.h*



**brief** A collection of pixels used in software blitting.



**note**  This structure should be treated as read-only, except for **c**         which, if not NULL, contains the raw pixel data for the surface.



## Members

public Uint32 flags

public SDL_PixelFormat * format

public int w

public int h

public int pitch

public void * pixels

public void * userdata

public int locked

public void * lock_data

SDL_Rect clip_rect

public struct SDL_BlitMap * map

public int refcount



