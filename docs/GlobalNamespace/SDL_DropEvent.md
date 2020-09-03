# struct SDL_DropEvent

*Defined at line 487 of /usr/include/SDL2/SDL_events.h*



**brief** An event used to request a file open by the system (event.drop.*)         This event is enabled by default, you can disable it with SDL_EventState().

**note** If this event is enabled, you must free the filename in the event.



## Members

public Uint32 type

public Uint32 timestamp

public char * file

public Uint32 windowID



