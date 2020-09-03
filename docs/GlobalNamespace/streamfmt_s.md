# struct streamfmt_s

*Defined at line 31 of ./engine/common/soundlib/soundlib.h*

## Members

public const char * formatstring

public const char * ext

public stream_t *(*)(const char *) openfunc

public int (*)(stream_t *, int, void *) readfunc

public int (*)(stream_t *, int) setposfunc

public int (*)(stream_t *) getposfunc

public void (*)(stream_t *) freefunc



