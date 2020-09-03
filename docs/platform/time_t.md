# struct time_t

*Defined at line 18 of ./public/platformspec.h*

 Format of the time_t structure: 	sec corresponds to the number of seconds since UNIX epoch 	ns corresponds to the number of nano-seconds within the current second. Meaning, ns will always be less than 		1e9, as once it reaches 1e9 it will be reset and sec will be incremented



## Members

public unsigned long long sec

public unsigned long long ns



## Functions

### to_ns

*public unsigned long long to_ns()*

*Defined at line 23 of ./public/platformspec.h*

### operator<

*public _Bool operator<(const struct platform::time_t & )*

*Defined at line 80 of ./public/platform.cpp*

### operator<=

*public _Bool operator<=(const struct platform::time_t & )*

*Defined at line 85 of ./public/platform.cpp*

### operator>

*public _Bool operator>(const struct platform::time_t & )*

*Defined at line 90 of ./public/platform.cpp*

### operator>=

*public _Bool operator>=(const struct platform::time_t & )*

*Defined at line 95 of ./public/platform.cpp*

### operator==

*public _Bool operator==(const struct platform::time_t & )*

*Defined at line 100 of ./public/platform.cpp*

### operator!=

*public _Bool operator!=(const struct platform::time_t & )*

*Defined at line 105 of ./public/platform.cpp*



