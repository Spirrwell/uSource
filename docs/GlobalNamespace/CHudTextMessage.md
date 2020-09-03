# class CHudTextMessage

*Defined at line 479 of ./game/client/hud.h*

-----------------------------------------------------



Inherits from CHudBase



## Functions

### Init

*public int Init()*

*Defined at line 31 of ./game/client/text_message.cpp*

### LocaliseTextString

*public char * LocaliseTextString(const char * msg, char * dst_buffer, int buffer_size)*

*Defined at line 45 of ./game/client/text_message.cpp*

 Searches through the string for any msg names (indicated by a '#') any found are looked up in titles.txt and the new message substituted the new value is pushed into dst_buffer

### BufferedLocaliseTextString

*public char * BufferedLocaliseTextString(const char * msg)*

*Defined at line 91 of ./game/client/text_message.cpp*

 As above, but with a local static buffer

### LookupString

*public const char * LookupString(const char * msg_name, int * msg_dest)*

*Defined at line 99 of ./game/client/text_message.cpp*

 Simplified version of LocaliseTextString;  assumes string is only one word

### MsgFunc_TextMsg

*public int MsgFunc_TextMsg(const char * pszName, int iSize, void * pbuf)*

*Defined at line 159 of ./game/client/text_message.cpp*

 Message handler for text messages displays a string, looking them up from the titles.txt file, which can be localised parameters:   byte:   message direction  ( HUD_PRINTCONSOLE, HUD_PRINTNOTIFY, HUD_PRINTCENTER, HUD_PRINTTALK )   string: message optional parameters:   string: message parameter 1   string: message parameter 2   string: message parameter 3   string: message parameter 4 any string that starts with the character '#' is a message name, and is used to look up the real message in titles.txt the next (optional) one to four strings are parameters for that string (which can also be message names if they begin with '#')



