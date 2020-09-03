# struct httpfile_s

*Defined at line 1791 of ./engine/common/net_ws.cpp*

## Members

public struct httpfile_s * next

public httpserver_t * server

public char [1024] path

public file_t * file

public int socket

public int size

public int downloaded

public int lastchecksize

public float checktime

public float blocktime

public int id

public enum connectionstate state

public qboolean process

public char [8192] buf

public int header_size

public int query_length

public int bytes_sent



