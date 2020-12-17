/*
snd_main.c - load & save various sound formats
Copyright (C) 2010 Uncle Mike

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

#include "containers/array.h"

// global sound variables
sndlib_t	sound;
List<SoundFileLoader*>* gSoundLoaders;
const char* const g_PathsToTry[] = {"sound", ""};

void Sound_Reset( void )
{
	// reset global variables
	sound.width = sound.rate = 0;
	sound.channels = sound.loopstart = 0;
	sound.samples = sound.flags = 0;
	sound.type = WF_UNKNOWN;

	sound.wav = NULL;
	sound.size = 0;
}

wavdata_t *SoundPack( void )
{
	wavdata_t	*pack = static_cast<wavdata_t *>(Mem_Calloc(host.soundpool, sizeof(wavdata_t)));

	pack->buffer = sound.wav;
	pack->width = sound.width;
	pack->rate = sound.rate;
	pack->type = sound.type;
	pack->size = sound.size;
	pack->loopStart = sound.loopstart;
	pack->samples = sound.samples;
	pack->channels = sound.channels;
	pack->flags = sound.flags;

	return pack;
}

SoundFileLoader::SoundFileLoader()
{
	if(!gSoundLoaders)
		gSoundLoaders = new List<SoundFileLoader*>();
	gSoundLoaders->push_back(this);
}

SoundFileLoader *SoundFileLoader::GetLoader(const char *ext)
{
	if(!gSoundLoaders) return nullptr;
	for(auto l : *gSoundLoaders)
	{
		if(Q_stricmp(ext, l->GetFileExtension()) == 0)
			return l;
	}
	return nullptr;
}


/*
================
FS_LoadSound

loading and unpack to wav any known sound
================
*/
wavdata_t *FS_LoadSound( const char *filename, const byte *buffer, size_t size )
{
	const char	*ext = COM_FileExtension( filename );
	string		path, loadname;
	qboolean		anyformat = true;
	fs_offset_t		filesize = 0;
	const loadwavfmt_t	*format;
	byte		*f;

	Sound_Reset(); // clear old sounddata
	Q_strncpy( loadname, filename, sizeof( loadname ));

	if( Q_stricmp( ext, "" ))
	{
		// we needs to compare file extension with list of supported formats
		// and be sure what is real extension, not a filename with dot
		for(auto loader : *gSoundLoaders)
		{
			if(!Q_stricmp(loader->GetFileExtension(), ext))
			{
				COM_StripExtension( loadname );
				anyformat = false;
				break;
			}
		}
	}

	// special mode: skip any checks, load file from buffer
	if( filename[0] == '#' && buffer && size )
		goto load_internal;

	for(auto loader : *gSoundLoaders)
	{
		if(anyformat || !Q_stricmp(ext, loader->GetFileExtension()))
		{
			Q_sprintf( path, "%s.%s", loadname, loader->GetFileExtension() );
			f = FS_LoadFile( path, &filesize, false );
			if(!f)
			{
				Q_sprintf(path, "sound/%s.%s", loadname, loader->GetFileExtension());
				f = FS_LoadFile(path, &filesize, false);
			}

			if( f && filesize > 0 )
			{
				if(loader->LoadSound(path, f, filesize, &sound))
				{
					Mem_Free(f); // release buffer
					return SoundPack(); // loaded
				}
				else Mem_Free(f); // release buffer
			}
		}
	}

load_internal:
	for(auto loader : *gSoundLoaders)
	{
		if(anyformat || !Q_stricmp(loader->GetFileExtension(), ext))
		{
			if(buffer && size > 0)
			{
				if(loader->LoadSound(loadname, buffer, size, &sound))
					return SoundPack();

			}
		}
	}

	if( filename[0] != '#' )
		Con_DPrintf( S_WARN "FS_LoadSound: couldn't load \"%s\"\n", loadname );

	return nullptr;
}

/*
================
Sound_FreeSound

free WAV buffer
================
*/
void FS_FreeSound( wavdata_t *pack )
{
	if( !pack ) return;
	if( pack->buffer ) Mem_Free( pack->buffer );
	Mem_Free( pack );
}

/*
================
FS_OpenStream

open and reading basic info from sound stream 
================
*/
stream_t *FS_OpenStream( const char *filename )
{
	const char	*ext = COM_FileExtension( filename );
	string		path, loadname;
	qboolean		anyformat = true;
	const streamfmt_t	*format;
	stream_t		*stream;

	Sound_Reset(); // clear old streaminfo
	Q_strncpy( loadname, filename, sizeof( loadname ));

	if( Q_stricmp( ext, "" ))
	{
		// we needs to compare file extension with list of supported formats
		// and be sure what is real extension, not a filename with dot
		for(auto loader : *gSoundLoaders)
		{
			if(!Q_stricmp(loader->GetFileExtension(), ext))
			{
				COM_StripExtension(loadname);
				anyformat = false;
				break;
			}
		}
	}

	for(auto loader : *gSoundLoaders)
	{
		if(anyformat || !Q_stricmp(ext, loader->GetFileExtension()))
		{
			Q_sprintf(path, "sound/%s.%s", loadname, loader->GetFileExtension());
			if((stream = loader->OpenStream(path, &sound)))
			{
				stream->format->loader = loader;
				return stream;
			}
		}
	}

	Con_Reportf( "FS_OpenStream: couldn't open \"%s\"\n", loadname );

	return NULL;
}

/*
================
FS_StreamInfo

get basic stream info
================
*/
wavdata_t *FS_StreamInfo( stream_t *stream )
{
	static wavdata_t	info;

	if( !stream ) return NULL;

	// fill structure
	info.loopStart = -1;
	info.rate = stream->rate;
	info.width = stream->width;
	info.channels = stream->channels;
	info.flags = SOUND_STREAM; 
	info.size = stream->size;
	info.buffer = NULL;
	info.samples = 0;	// not actual for streams
	info.type = stream->type;

	return &info;
}

/*
================
FS_ReadStream

extract stream as wav-data and put into buffer, move file pointer
================
*/
int FS_ReadStream( stream_t *stream, int bytes, void *buffer )
{
	if( !stream || !stream->format || !stream->format->loader )
		return 0;

	if( bytes <= 0 || buffer == NULL )
		return 0;

	return stream->format->loader->ReadStream(stream, bytes, buffer);
}

/*
================
FS_GetStreamPos

get stream position (in bytes)
================
*/
int FS_GetStreamPos( stream_t *stream )
{
	if( !stream || !stream->format || !stream->format->loader )
		return -1;

	return stream->format->loader->GetStreamPos(stream);
}

/*
================
FS_SetStreamPos

set stream position (in bytes)
================
*/
int FS_SetStreamPos( stream_t *stream, int newpos )
{
	if( !stream || !stream->format || !stream->format->loader )
		return -1;

	return stream->format->loader->SetStreamPos(stream, newpos);
}

/*
================
FS_FreeStream

close sound stream
================
*/
void FS_FreeStream( stream_t *stream )
{
	if( !stream || !stream->format || !stream->format->loader )
		return;

	stream->format->loader->CloseStream(stream);
}
