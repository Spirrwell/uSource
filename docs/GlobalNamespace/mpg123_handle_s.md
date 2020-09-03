# struct mpg123_handle_s

*Defined at line 246 of ./engine/common/soundlib/libmpg/mpg123.h*

## Members

public int fresh

public int new_format

public float [2][2][576] hybrid_block

public int [2] hybrid_blc

public short *[2][2] short_buffs

public float *[2][2] float_buffs

public byte * rawbuffs

public int rawbuffss

public int bo

public byte * rawdecwin

public int rawdecwins

public float * decwin

public byte [34] ssave

public int halfphase

public int [9][23] longLimit

public int [9][14] shortLimit

public float [378] gainpow2

synth_s synths

public int verbose

public const al_table_t * alloc

public func_synth synth

public func_synth_stereo synth_stereo

public func_synth_mono synth_mono

public void (*)(mpg123_handle_t *) make_decode_tables

public int stereo

public int jsbound

public int single

public int II_sblimit

public int down_sample_sblimit

public int lsf

public int mpeg25

public int down_sample

public int header_change

public int lay

public long spf

public int (*)(mpg123_handle_t *) do_layer

public int error_protection

public int bitrate_index

public int sampling_frequency

public int padding

public int extension

public int mode

public int mode_ext

public int copyright

public int original

public int emphasis

public int framesize

public int freesize

public int vbr

public mpg_off_t num

public mpg_off_t input_offset

public mpg_off_t playnum

public mpg_off_t audio_start

public int state_flags

public char silent_resync

public byte * xing_toc

public int freeformat

public long freeformat_framesize

public int bitindex

public byte * wordpointer

public ulong ultmp

public byte uctmp

public double maxoutburst

public double lastscale

public  rva

public mpg_off_t track_frames

public mpg_off_t track_samples

public double mean_framesize

public mpg_off_t mean_frames

public int fsizeold

public int ssize

public uint bitreservoir

public byte [2][3968] bsspace

public byte * bsbuf

public byte * bsbufold

public int bsnum

public ulong oldhead

public ulong firsthead

public int abr_rate

frame_index_s index

outbuffer_s buffer

audioformat_s af

public int own_buffer

public size_t outblock

public int to_decode

public int to_ignore

public mpg_off_t firstframe

public mpg_off_t lastframe

public mpg_off_t ignoreframe

public mpg_off_t gapless_frames

public mpg_off_t firstoff

public mpg_off_t lastoff

public mpg_off_t begin_s

public mpg_off_t begin_os

public mpg_off_t end_s

public mpg_off_t end_os

public mpg_off_t fullend_os

public uint crc

public reader_t * rd

reader_data_s rdat

mpg123_parm_s p

public int err

public int decoder_change

public int delayed_change

public long clip

public int metaflags

public byte [128] id3buf

public float * layerscratch

public  layer3

public void * wrapperdata

public void (*)(void *) wrapperclean



## Records







