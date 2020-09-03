# class StringView

*Defined at line 87 of ./public/containers/string.h*

 Simply maintains a pointer to a character string 

 Useful if you don't want to be doing malloc and stuff constantly 



## Members

private const char * m_string

private unsigned long long m_length



## Functions

### StringView

*public void StringView(const class StringView & other)*

*Defined at line 253 of ./public/containers/string.cpp*

### StringView

*public void StringView(const class StringView && other)*

*Defined at line 260 of ./public/containers/string.cpp*

### StringView

*public void StringView(const char * str)*

*Defined at line 267 of ./public/containers/string.cpp*

### StringView

*public void StringView(const class String & str)*

*Defined at line 274 of ./public/containers/string.cpp*

### ~StringView

*public void ~StringView()*

*Defined at line 281 of ./public/containers/string.cpp*

### empty

*public _Bool empty()*

*Defined at line 285 of ./public/containers/string.cpp*

### to_string

*public String to_string()*

*Defined at line 290 of ./public/containers/string.cpp*

 Returns a modifyable string 

### copy

*public String copy()*

*Defined at line 399 of ./public/containers/string.cpp*

### string

*public const char * string()*

*Defined at line 295 of ./public/containers/string.cpp*

 Returns a pointer to the internal string buffer 

### c_str

*public const char * c_str()*

*Defined at line 300 of ./public/containers/string.cpp*

### length

*public size_t length()*

*Defined at line 113 of ./public/containers/string.h*

 returns the length 

### equals

*public _Bool equals(const class StringView & other)*

*Defined at line 305 of ./public/containers/string.cpp*

 Equality tests 

### equals

*public _Bool equals(const class String & other)*

*Defined at line 310 of ./public/containers/string.cpp*

### equals

*public _Bool equals(const char * other)*

*Defined at line 315 of ./public/containers/string.cpp*

### iequals

*public _Bool iequals(const class StringView & other)*

*Defined at line 320 of ./public/containers/string.cpp*

 Case insensitive equality tests 

### iequals

*public _Bool iequals(const class String & other)*

*Defined at line 325 of ./public/containers/string.cpp*

### iequals

*public _Bool iequals(const char * other)*

*Defined at line 330 of ./public/containers/string.cpp*

### contains

*public _Bool contains(const char * subst)*

*Defined at line 404 of ./public/containers/string.cpp*

### contains

*public _Bool contains(const class String & subst)*

*Defined at line 409 of ./public/containers/string.cpp*

### contains

*public _Bool contains(const class StringView & subst)*

*Defined at line 414 of ./public/containers/string.cpp*

### startswith

*public _Bool startswith(const char * subst)*

*Defined at line 419 of ./public/containers/string.cpp*

### startswith

*public _Bool startswith(const class String & subst)*

*Defined at line 424 of ./public/containers/string.cpp*

### startswith

*public _Bool startswith(const class StringView & subst)*

*Defined at line 429 of ./public/containers/string.cpp*

### endswith

*public _Bool endswith(const char * subst)*

*Defined at line 434 of ./public/containers/string.cpp*

### endswith

*public _Bool endswith(const class String & subst)*

*Defined at line 439 of ./public/containers/string.cpp*

### endswith

*public _Bool endswith(const class StringView & subst)*

*Defined at line 444 of ./public/containers/string.cpp*

### operator const char *

*public const char * operator const char *()*

*Defined at line 138 of ./public/containers/string.h*

 Casting operators 

### operator String

*public String operator String()*

*Defined at line 335 of ./public/containers/string.cpp*

### operator[]

*public char operator[](size_t i)*

*Defined at line 340 of ./public/containers/string.cpp*

### operator=

*public class StringView & operator=(const class String & other)*

*Defined at line 346 of ./public/containers/string.cpp*

 Assignment operators 

### operator=

*public class StringView & operator=(const class StringView & other)*

*Defined at line 353 of ./public/containers/string.cpp*

### operator=

*public class StringView & operator=(class StringView && other)*

*Defined at line 360 of ./public/containers/string.cpp*

### operator==

*public _Bool operator==(const class StringView & other)*

*Defined at line 369 of ./public/containers/string.cpp*

 Equality tests 

### operator==

*public _Bool operator==(const class String & other)*

*Defined at line 374 of ./public/containers/string.cpp*

### operator==

*public _Bool operator==(const char * other)*

*Defined at line 379 of ./public/containers/string.cpp*

### operator!=

*public _Bool operator!=(const class StringView & other)*

*Defined at line 384 of ./public/containers/string.cpp*

### operator!=

*public _Bool operator!=(const class String & other)*

*Defined at line 389 of ./public/containers/string.cpp*

### operator!=

*public _Bool operator!=(const char * other)*

*Defined at line 394 of ./public/containers/string.cpp*



