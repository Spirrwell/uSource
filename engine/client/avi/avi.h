/*
avi.h -- common avi support header
Copyright (C) 2018 a1batross, Uncle Mike

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/
#ifndef AVI_H
#define AVI_H

#include "common.h"

//
// avikit.c
//
typedef struct movie_state_s movie_state_t;
EXPORT int			    AVI_GetVideoFrameNumber(movie_state_t* Avi, float time);
byte*   AVI_GetVideoFrame(movie_state_t* Avi, int frame);
EXPORT qboolean AVI_GetVideoInfo(movie_state_t* Avi, int* xres, int* yres, float* duration);
EXPORT qboolean AVI_GetAudioInfo(movie_state_t* Avi, wavdata_t* snd_info);
EXPORT int	AVI_GetAudioChunk(movie_state_t* Avi, char* audiodata, int offset, int length);
EXPORT void	AVI_OpenVideo(movie_state_t* Avi, const char* filename, qboolean load_audio, int quiet);
EXPORT movie_state_t* AVI_LoadVideo(const char* filename, qboolean load_audio);
EXPORT int	      AVI_TimeToSoundPosition(movie_state_t* Avi, int time);
EXPORT int	      AVI_GetVideoFrameCount(movie_state_t* Avi);
EXPORT void	      AVI_CloseVideo(movie_state_t* Avi);
EXPORT qboolean	      AVI_IsActive(movie_state_t* Avi);
EXPORT void	      AVI_FreeVideo(movie_state_t* Avi);
EXPORT movie_state_t* AVI_GetState(int num);
EXPORT qboolean	      AVI_Initailize(void);
EXPORT void	      AVI_Shutdown(void);

#endif // AVI_H
