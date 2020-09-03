# class String

*Defined at line 16 of ./public/containers/string.h*

## Members

private char * m_string

private unsigned long long m_length



## Functions

### String

*public void String()*

*Defined at line 15 of ./public/containers/string.cpp*

### String

*public void String(const class String & other)*

*Defined at line 21 of ./public/containers/string.cpp*

### String

*public void String(class String && other)*

*Defined at line 27 of ./public/containers/string.cpp*

### String

*public void String(const char * str)*

*Defined at line 35 of ./public/containers/string.cpp*

### ~String

*public void ~String()*

*Defined at line 41 of ./public/containers/string.cpp*

### c_str

*public const char * c_str()*

*Defined at line 46 of ./public/containers/string.cpp*

### length

*public size_t length()*

*Defined at line 51 of ./public/containers/string.cpp*

### empty

*public _Bool empty()*

*Defined at line 110 of ./public/containers/string.cpp*

### equals

*public _Bool equals(const class String & other)*

*Defined at line 56 of ./public/containers/string.cpp*

 Equality tests 

### equals

*public _Bool equals(const class StringView & other)*

*Defined at line 176 of ./public/containers/string.cpp*

### equals

*public _Bool equals(const char * other)*

*Defined at line 62 of ./public/containers/string.cpp*

### iequals

*public _Bool iequals(const class String & other)*

*Defined at line 68 of ./public/containers/string.cpp*

 Inequality tests 

### iequals

*public _Bool iequals(const class StringView & other)*

*Defined at line 181 of ./public/containers/string.cpp*

### iequals

*public _Bool iequals(const char * other)*

*Defined at line 74 of ./public/containers/string.cpp*

### contains

*public _Bool contains(const char * subst)*

*Defined at line 161 of ./public/containers/string.cpp*

### contains

*public _Bool contains(const class String & subst)*

*Defined at line 166 of ./public/containers/string.cpp*

### contains

*public _Bool contains(const class StringView & subst)*

*Defined at line 171 of ./public/containers/string.cpp*

### startswith

*public _Bool startswith(const char * subst)*

*Defined at line 222 of ./public/containers/string.cpp*

### startswith

*public _Bool startswith(const class String & subst)*

*Defined at line 227 of ./public/containers/string.cpp*

### startswith

*public _Bool startswith(const class StringView & subst)*

*Defined at line 232 of ./public/containers/string.cpp*

### endswith

*public _Bool endswith(const char * subst)*

*Defined at line 237 of ./public/containers/string.cpp*

### endswith

*public _Bool endswith(const class String & subst)*

*Defined at line 242 of ./public/containers/string.cpp*

### endswith

*public _Bool endswith(const class StringView & subst)*

*Defined at line 247 of ./public/containers/string.cpp*

### to_lower

*public void to_lower()*

*Defined at line 80 of ./public/containers/string.cpp*

### to_upper

*public void to_upper()*

*Defined at line 87 of ./public/containers/string.cpp*

### replace

*public size_t replace(char c, char n, size_t max)*

*Defined at line 94 of ./public/containers/string.cpp*

### substr

*public String substr(size_t start, size_t end)*

*Defined at line 115 of ./public/containers/string.cpp*

### operator const char *

*public const char * operator const char *()*

*Defined at line 65 of ./public/containers/string.h*

### operator char *

*public char * operator char *()*

*Defined at line 66 of ./public/containers/string.h*

### operator[]

*public char operator[](size_t i)*

*Defined at line 120 of ./public/containers/string.cpp*

### operator=

*public class String & operator=(const class String & other)*

*Defined at line 126 of ./public/containers/string.cpp*

### operator=

*public class String & operator=(class String && other)*

*Defined at line 134 of ./public/containers/string.cpp*

### operator=

*public class String & operator=(const char * other)*

*Defined at line 194 of ./public/containers/string.cpp*

### operator=

*public class String & operator=(const class StringView & other)*

*Defined at line 186 of ./public/containers/string.cpp*

### operator==

*public _Bool operator==(const class String & other)*

*Defined at line 141 of ./public/containers/string.cpp*

### operator==

*public _Bool operator==(const char * other)*

*Defined at line 217 of ./public/containers/string.cpp*

### operator==

*public _Bool operator==(const class StringView & other)*

*Defined at line 212 of ./public/containers/string.cpp*

### operator!=

*public _Bool operator!=(const class String & other)*

*Defined at line 146 of ./public/containers/string.cpp*

### operator!=

*public _Bool operator!=(const char * other)*

*Defined at line 202 of ./public/containers/string.cpp*

### operator!=

*public _Bool operator!=(const class StringView & other)*

*Defined at line 207 of ./public/containers/string.cpp*

### operator StringView

*public StringView operator StringView()*

*Defined at line 151 of ./public/containers/string.cpp*

### string_view

*public StringView string_view()*

*Defined at line 156 of ./public/containers/string.cpp*



