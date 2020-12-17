/*
snd_vorbis.c - OGG/Vorbis file loading
Copyright (C) 2020 Jeremy Lorelli

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

#include "soundlib.h"

/* vorbis stuff */
#include "vorbis/vorbisfile.h"

class SoundOGGLoader : public SoundFileLoader
{
public:
	explicit  SoundOGGLoader();

	virtual bool LoadSound(const char* name, const byte* buffer, size_t filesize, struct sndlib_s* loadDest);

	/* Feature tests */
	virtual bool SupportsStreamReading();
	virtual bool SupportsLoading();

	virtual stream_t* OpenStream(const char* filename, sndlib_t* sound);
	virtual int ReadStream(stream_t* stream, int bytes, void* buffer);
	virtual int SetStreamPos(stream_t* stream, int newpos);
	virtual int GetStreamPos(stream_t* stream);
	virtual void CloseStream(stream_t* stream);

	/* File extension */
	virtual const char* GetFileExtension();
	virtual const char* GetFormatString();
	virtual const char* GetPrettyName();
};

static SoundOGGLoader gOggLoader;

SoundOGGLoader::SoundOGGLoader() :
	SoundFileLoader()
{

}

bool SoundOGGLoader::LoadSound(const char *name, const byte *buffer, size_t filesize, struct sndlib_s *sound)
{
	size_t packetIndex = 0;
	size_t maxPacketIndex = (filesize/sizeof(ogg_packet));
	ogg_packet* oggData = (ogg_packet*)buffer;

	Con_DPrintf("Loading ogg/vorbis!");

	if(!vorbis_synthesis_idheader(oggData)) {
		return false;
	}

	vorbis_comment v_comment;
	vorbis_comment_init(&v_comment);

	vorbis_info v_info;
	vorbis_info_init(&v_info);

	if(vorbis_synthesis_headerin(&v_info, &v_comment, oggData)) {
		Msg("Failed to read vorbis file\n");
		return false;
	}
	packetIndex = 3; // Header reads exactly 3 vorbis packets

	sound->channels = v_info.channels;
	sound->rate = v_info.rate;
	sound->width = 2; // Always use 16-bit PCM

	vorbis_dsp_state v_dsp_state;
	if(vorbis_synthesis_init(&v_dsp_state, &v_info)) {
		Msg("Failed to init dsp state for vorbis file!\n");
		return false;
	}


	vorbis_block v_block;
	vorbis_block_init(&v_dsp_state, &v_block);

	// Alloc a buffer of samples, hopefully big enough so realloc wont be required
	size_t sampleBufSize = 1024;
	size_t sampleIndex = 0;
	float** sampleBuf = (float**)malloc(sizeof(float**) * sampleBufSize);

	for(;;) {
		ogg_packet packet = oggData[packetIndex];
		packetIndex++;
		if(vorbis_synthesis(&v_block, &packet)) {
			break;
		}
		if(vorbis_synthesis_blockin(&v_dsp_state, &v_block)) {
			break;
		}

		/* Return the number of PCM samples we got in the buffer */
		int samples = vorbis_synthesis_pcmout(&v_dsp_state, nullptr);
		if(!samples) break;
		if(samples > sampleBufSize) {
			sampleBufSize = samples;
			sampleBuf = (float**)realloc(sampleBuf, sampleBufSize * sizeof(float**));
		}

		/* Read the samples */
		vorbis_synthesis_pcmout(&v_dsp_state, &sampleBuf);
		sound->samples += samples;

		/* Horrible, but must be done! We only support 16-bit PCM samples here, so need to actually cast the data to short */
		for(int i = 0; i < samples; i++) {
			float s = *sampleBuf[i];
			((uint16_t*)sound->wav)[sampleIndex++] = (short)s;
		}
	}

	free(sampleBuf);
	return true;
}

bool SoundOGGLoader::SupportsStreamReading()
{
	return false;
}

bool SoundOGGLoader::SupportsLoading()
{
	return true;
}

stream_t *SoundOGGLoader::OpenStream(const char *filename, sndlib_t* sound)
{
	return nullptr;
}

int SoundOGGLoader::ReadStream(stream_t *stream, int bytes, void *buffer)
{
	return 0;
}

int SoundOGGLoader::SetStreamPos(stream_t *stream, int newpos)
{
	return 0;
}

int SoundOGGLoader::GetStreamPos(stream_t *stream)
{
	return 0;
}

void SoundOGGLoader::CloseStream(stream_t *stream)
{

}

const char *SoundOGGLoader::GetFileExtension()
{
	return "ogg";
}

const char *SoundOGGLoader::GetFormatString()
{
	return nullptr;
}

const char *SoundOGGLoader::GetPrettyName()
{
	return nullptr;
}
