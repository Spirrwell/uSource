# struct LONGPACKET

*Defined at line 128 of ./engine/common/net_ws.cpp*

 split long packets. Anything over 1460 is failing on some routers.



## Members

public int current_sequence

public int split_count

public int total_size

public char [65536] buffer



