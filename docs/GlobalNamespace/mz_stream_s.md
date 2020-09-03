# struct mz_stream_s

*Defined at line 282 of ./engine/common/miniz.h*

 Compression/decompression stream struct. 



## Members

public const unsigned char * next_in

public unsigned int avail_in

public mz_ulong total_in

public unsigned char * next_out

public unsigned int avail_out

public mz_ulong total_out

public char * msg

public struct mz_internal_state * state

public mz_alloc_func zalloc

public mz_free_func zfree

public void * opaque

public int data_type

public mz_ulong adler

public mz_ulong reserved



