# struct tdefl_compressor

*Defined at line 698 of ./engine/common/miniz.h*

 tdefl's compression state structure. 



## Members

public tdefl_put_buf_func_ptr m_pPut_buf_func

public void * m_pPut_buf_user

public mz_uint m_flags

public mz_uint [2] m_max_probes

public int m_greedy_parsing

public mz_uint m_adler32

public mz_uint m_lookahead_pos

public mz_uint m_lookahead_size

public mz_uint m_dict_size

public mz_uint8 * m_pLZ_code_buf

public mz_uint8 * m_pLZ_flags

public mz_uint8 * m_pOutput_buf

public mz_uint8 * m_pOutput_buf_end

public mz_uint m_num_flags_left

public mz_uint m_total_lz_bytes

public mz_uint m_lz_code_buf_dict_pos

public mz_uint m_bits_in

public mz_uint m_bit_buffer

public mz_uint m_saved_match_dist

public mz_uint m_saved_match_len

public mz_uint m_saved_lit

public mz_uint m_output_flush_ofs

public mz_uint m_output_flush_remaining

public mz_uint m_finished

public mz_uint m_block_index

public mz_uint m_wants_to_finish

public tdefl_status m_prev_return_status

public const void * m_pIn_buf

public void * m_pOut_buf

public size_t * m_pIn_buf_size

public size_t * m_pOut_buf_size

public tdefl_flush m_flush

public const mz_uint8 * m_pSrc

public size_t m_src_buf_left

public size_t m_out_buf_ofs

public mz_uint8 [33025] m_dict

public mz_uint16 [3][288] m_huff_count

public mz_uint16 [3][288] m_huff_codes

public mz_uint8 [3][288] m_huff_code_sizes

public mz_uint8 [65536] m_lz_code_buf

public mz_uint16 [32768] m_next

public mz_uint16 [32768] m_hash

public mz_uint8 [85196] m_output_buf



