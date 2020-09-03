# struct SDL_RWops

*Defined at line 52 of /usr/include/SDL2/SDL_rwops.h*

 This is the read/write operation structure -- very basic.



## Members

public Sint64 (*)(struct SDL_RWops *) size

public Sint64 (*)(struct SDL_RWops *, Sint64, int) seek

public size_t (*)(struct SDL_RWops *, void *, size_t, size_t) read

public size_t (*)(struct SDL_RWops *, const void *, size_t, size_t) write

public int (*)(struct SDL_RWops *) close

public Uint32 type

public  hidden



## Records





