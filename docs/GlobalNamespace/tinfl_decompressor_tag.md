# struct tinfl_decompressor_tag

*Defined at line 891 of ./engine/common/miniz.h*

## Members

public mz_uint32 m_state

public mz_uint32 m_num_bits

public mz_uint32 m_zhdr0

public mz_uint32 m_zhdr1

public mz_uint32 m_z_adler32

public mz_uint32 m_final

public mz_uint32 m_type

public mz_uint32 m_check_adler32

public mz_uint32 m_dist

public mz_uint32 m_counter

public mz_uint32 m_num_extra

public mz_uint32 [3] m_table_sizes

public tinfl_bit_buf_t m_bit_buf

public size_t m_dist_from_out_buf_start

public tinfl_huff_table [3] m_tables

public mz_uint8 [4] m_raw_header

public mz_uint8 [457] m_len_codes



