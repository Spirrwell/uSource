# struct netchan_s

*Defined at line 193 of ./engine/common/netchan.h*

 Network Connection Channel



## Members

public netsrc_t sock

netadr_s remote_address

public int qport

public double last_received

public double connect_time

public double rate

public double cleartime

public int incoming_sequence

public int incoming_acknowledged

public int incoming_reliable_acknowledged

public int incoming_reliable_sequence

public int outgoing_sequence

public int reliable_sequence

public int last_reliable_sequence

public void * client

public int (*)(void *, fragsize_t) pfnBlockSize

sizebuf_s message

public byte [131120] message_buf

public int reliable_length

public byte [131120] reliable_buf

public fragbufwaiting_t *[2] waitlist

public int [2] reliable_fragment

public uint [2] reliable_fragid

public fragbuf_t *[2] fragbufs

public int [2] fragbufcount

public int [2] frag_startpos

public int [2] frag_length

public fragbuf_t *[2] incomingbufs

public qboolean [2] incomingready

public char [260] incomingfilename

public void * tempbuffer

public int tempbuffersize

public flow_t [2] flow

public size_t total_sended

public size_t total_received

public qboolean split

public unsigned int maxpacket

public unsigned int splitid

netsplit_s netsplit



