# namespace dbg



## Records

CAssert



## Functions

### Init

*void Init()*

*Defined at line 51 of ./public/debug.cpp*

### FireAssertion

*_Bool FireAssertion(const char * file, int line, const char * exp)*

*Defined at line 152 of ./public/debug.cpp*

 Called to fire an assertion. Returns true if the assertion is enabled and a message should be printed 

### CreateAssert

*void CreateAssert(const char * file, int line, const char * exp)*

*Defined at line 145 of ./public/debug.cpp*

 Creates a new assertion 

### FindOrCreateAssert

*CAssert FindOrCreateAssert(const char * file, int line, const char * exp)*

*Defined at line 99 of ./public/debug.cpp*

 Finds or creates a new assertion, always returns a valid pointer 

### DisableAssert

*void DisableAssert(const char * file, int line)*

*Defined at line 106 of ./public/debug.cpp*

 Disables the assertion at the specified line and file 

### EnableAssert

*void EnableAssert(const char * file, int line)*

*Defined at line 116 of ./public/debug.cpp*

### FindAssert

*CAssert FindAssert(const char * file, int line)*

*Defined at line 126 of ./public/debug.cpp*

 Tries to find an assertion that's already registered. Returns nullptr if not found 

### IsAssertEnabled

*_Bool IsAssertEnabled(const char * file, int line)*

*Defined at line 135 of ./public/debug.cpp*

 Returns true if an assertion is enabled 

### BreakAssert

*void BreakAssert(const char * file, int line)*

*Defined at line 174 of ./public/debug.cpp*

 Causes a break into debugger when the specified assertion is hit 

### UnBreakAssert

*void UnBreakAssert(const char * file, int line)*

*Defined at line 183 of ./public/debug.cpp*

### WasAssertHit

*_Bool WasAssertHit(const char * file, int line)*

*Defined at line 192 of ./public/debug.cpp*

 Returns true if the assertion was hit 

### GetAssertList

*Array<class dbg::CAssert> GetAssertList()*

*Defined at line 202 of ./public/debug.cpp*

 Returns a list of assertions 

### EnableAssertOnce

*void EnableAssertOnce()*

*Defined at line 219 of ./public/debug.cpp*

 Enable/Disable features globally 

 These act on ALL asserts 

### DisableAssertOnce

*void DisableAssertOnce()*

*Defined at line 224 of ./public/debug.cpp*

### EnableAssertBreak

*void EnableAssertBreak()*

*Defined at line 209 of ./public/debug.cpp*

### DisableAssertBreak

*void DisableAssertBreak()*

*Defined at line 214 of ./public/debug.cpp*

### EnableAsserts

*void EnableAsserts()*

*Defined at line 229 of ./public/debug.cpp*

### DisableAsserts

*void DisableAsserts()*

*Defined at line 234 of ./public/debug.cpp*



