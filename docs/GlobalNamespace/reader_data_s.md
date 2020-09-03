# struct reader_data_s

*Defined at line 63 of ./engine/common/soundlib/libmpg/reader.h*

## Members

public mpg_off_t filelen

public mpg_off_t filepos

public int filept

public void * iohandle

public int flags

public long timeout_sec

public mpg_ssize_t (*)(mpg123_handle_t *, void *, size_t) fdread

public mpg_ssize_t (*)(int, void *, size_t) r_read

public mpg_off_t (*)(int, mpg_off_t, int) r_lseek

public mpg_ssize_t (*)(void *, void *, size_t) r_read_handle

public mpg_off_t (*)(void *, mpg_off_t, int) r_lseek_handle

public void (*)(void *) cleanup_handle

public mpg_ssize_t (*)(int, void *, size_t) read

public mpg_off_t (*)(int, mpg_off_t, int) lseek

public mpg_ssize_t (*)(mpg123_handle_t *, byte *, mpg_ssize_t) fullread

bufferchain_s buffer



