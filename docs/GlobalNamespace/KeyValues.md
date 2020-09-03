# class KeyValues

*Defined at line 19 of ./public/keyvalues.h*

## Members

public char * name

public _Bool good

public _Bool quoted

vector child_sections

vector keys

private KeyValues::pfnErrorCallback_t pCallback



## Records

key_t



## Functions

### KeyValues

*public void KeyValues(const char * name)*

*Defined at line 23 of ./public/keyvalues.cpp*

### KeyValues

*public void KeyValues()*

*Defined at line 31 of ./public/keyvalues.cpp*

### ~KeyValues

*public void ~KeyValues()*

*Defined at line 37 of ./public/keyvalues.cpp*

### GetBool

*public _Bool GetBool(const char * key, _Bool _default)*

*Defined at line 335 of ./public/keyvalues.cpp*

 Getters 

### GetInt

*public int GetInt(const char * key, int _default)*

*Defined at line 350 of ./public/keyvalues.cpp*

### GetFloat

*public float GetFloat(const char * key, float _default)*

*Defined at line 365 of ./public/keyvalues.cpp*

### GetString

*public const char * GetString(const char * key, const char * _default)*

*Defined at line 395 of ./public/keyvalues.cpp*

### GetDouble

*public double GetDouble(const char * key, double _default)*

*Defined at line 380 of ./public/keyvalues.cpp*

### GetChild

*public class KeyValues * GetChild(const char * name)*

*Defined at line 497 of ./public/keyvalues.cpp*

### HasKey

*public _Bool HasKey(const char * key)*

*Defined at line 405 of ./public/keyvalues.cpp*

### SetBool

*public void SetBool(const char * key, _Bool v)*

*Defined at line 509 of ./public/keyvalues.cpp*

 Setters 

### SetInt

*public void SetInt(const char * key, int v)*

*Defined at line 522 of ./public/keyvalues.cpp*

### SetFloat

*public void SetFloat(const char * key, float v)*

*Defined at line 535 of ./public/keyvalues.cpp*

### SetString

*public void SetString(const char * key, const char * v)*

*Defined at line 548 of ./public/keyvalues.cpp*

### ParseFile

*public void ParseFile(const char * file, _Bool use_escape_codes)*

*Defined at line 79 of ./public/keyvalues.cpp*

 Parse from a file 

### ParseFile

*public void ParseFile(FILE * f, _Bool use_escape_codes)*

*Defined at line 53 of ./public/keyvalues.cpp*

### ParseString

*public void ParseString(const char * string, _Bool use_escape_codes, long long len)*

*Defined at line 108 of ./public/keyvalues.cpp*

### ClearKey

*public void ClearKey(const char * key)*

*Defined at line 562 of ./public/keyvalues.cpp*

 Clears a key's value setting it to "" 

### RemoveKey

*public void RemoveKey(const char * key)*

*Defined at line 576 of ./public/keyvalues.cpp*

 Completely removes a key 

### DumpToStream

*public void DumpToStream(FILE * fs)*

*Defined at line 294 of ./public/keyvalues.cpp*

 Dumps this to stdout 

### DumpToStreamInternal

*public void DumpToStreamInternal(FILE * fs, int indent)*

*Defined at line 299 of ./public/keyvalues.cpp*

### IsGood

*public _Bool IsGood()*

*Defined at line 91 of ./public/keyvalues.h*

 Set Good bit is set if parsing went OK 

### SetErrorCallback

*public void SetErrorCallback(KeyValues::pfnErrorCallback_t callback)*

*Defined at line 588 of ./public/keyvalues.cpp*

 Sets the error reporting callback 

### ReportError

*private void ReportError(int line, int _char, enum KeyValues::EError err)*

*Defined at line 287 of ./public/keyvalues.cpp*



## Enums

| enum class EError |

--

| NONE |
| UNEXPECTED_EOF |
| MISSING_BRACKET |
| MISSING_QUOTE |
| UNNAMED_SECTION |
| UNTERMINATED_SECTION |


*Defined at line 93 of ./public/keyvalues.h*



