# struct SDL_AudioSpec

*Defined at line 178 of /usr/include/SDL2/SDL_audio.h*

  The calculated values in this structure are calculated by SDL_OpenAudio().

  For multi-channel audio, the default SDL channel mapping is:  2:  FL FR                       (stereo)  3:  FL FR LFE                   (2.1 surround)  4:  FL FR BL BR                 (quad)  5:  FL FR FC BL BR              (quad + center)  6:  FL FR FC LFE SL SR          (5.1 surround - last two can also be BL BR)  7:  FL FR FC LFE BC SL SR       (6.1 surround)  8:  FL FR FC LFE BL BR SL SR    (7.1 surround)



## Members

public int freq

public SDL_AudioFormat format

public Uint8 channels

public Uint8 silence

public Uint16 samples

public Uint16 padding

public Uint32 size

public SDL_AudioCallback callback

public void * userdata



