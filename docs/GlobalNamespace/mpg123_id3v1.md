# struct mpg123_id3v1

*Defined at line 232 of ./engine/common/soundlib/libmpg/mpg123.h*

 Data structure for ID3v1 tags (the last 128 bytes of a file). Don't take anything for granted (like string termination)! Also note the change ID3v1.1 did: comment[28] = 0; comment[29] = track_number It is your task to support ID3v1 only or ID3v1.1 ...



## Members

public char [3] tag

public char [30] title

public char [30] artist

public char [30] album

public char [4] year

public char [30] comment

public byte genre



