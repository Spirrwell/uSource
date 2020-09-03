# struct reader_s

*Defined at line 99 of ./engine/common/soundlib/libmpg/reader.h*

 start to use mpg_off_t to properly do LFS in future ... used to be long



## Members

public int (*)(mpg123_handle_t *) init

public void (*)(mpg123_handle_t *) close

public mpg_ssize_t (*)(mpg123_handle_t *, byte *, mpg_ssize_t) fullread

public int (*)(mpg123_handle_t *, ulong *) head_read

public int (*)(mpg123_handle_t *, ulong *) head_shift

public mpg_off_t (*)(mpg123_handle_t *, mpg_off_t) skip_bytes

public int (*)(mpg123_handle_t *, byte *, int) read_frame_body

public int (*)(mpg123_handle_t *, mpg_off_t) back_bytes

public int (*)(mpg123_handle_t *, mpg_off_t) seek_frame

public mpg_off_t (*)(mpg123_handle_t *) tell

public void (*)(mpg123_handle_t *) rewind

public void (*)(mpg123_handle_t *) forget



