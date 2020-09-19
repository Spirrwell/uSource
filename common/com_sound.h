
#pragma once

#include "types.h"

#include <stddef.h>

typedef struct
{
	word	rate;		// num samples per second (e.g. 11025 - 11 khz)
	byte	width;		// resolution - bum bits divided by 8 (8 bit is 1, 16 bit is 2)
	byte	channels;		// num channels (1 - mono, 2 - stereo)
	int	loopStart;	// offset at this point sound will be looping while playing more than only once
	int	samples;		// total samplecount in wav
	uint	type;		// compression type
	uint	flags;		// misc sound flags
	byte	*buffer;		// sound buffer
	size_t	size;		// for bounds checking
} wavdata_t;