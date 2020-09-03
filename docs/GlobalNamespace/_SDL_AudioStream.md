# struct _SDL_AudioStream

 SDL_AudioStream is a new audio conversion interface.   The benefits vs SDL_AudioCVT:    - it can handle resampling data in chunks without generating      artifacts, when it doesn't have the complete buffer available.    - it can handle incoming data in any variable size.    - You push data as you have it, and pull it when you need it

 this is opaque to the outside world. 



