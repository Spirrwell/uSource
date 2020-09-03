# class Convar

*Defined at line 12 of ./tier1/convar.h*

## Members

private const char *const name

private const char *const _default

private const unsigned int flags

private const char *const desc

private void (*)(const char *, const char *) m_callback



## Functions

### Convar

*public void Convar(const char * name, const char * _default, unsigned int flags, const char * description, void (*)(const char *, const char *) callback)*

*Defined at line 28 of ./tier1/convar.cpp*

### GetFloat

*public float GetFloat()*

*Defined at line 40 of ./tier1/convar.cpp*

### GetInt

*public int GetInt()*

*Defined at line 47 of ./tier1/convar.cpp*

### GetString

*public const char * GetString()*

*Defined at line 54 of ./tier1/convar.cpp*

### GetBool

*public _Bool GetBool()*

*Defined at line 60 of ./tier1/convar.cpp*

### SetFloat

*public void SetFloat(float f)*

*Defined at line 69 of ./tier1/convar.cpp*

### SetInt

*public void SetInt(int i)*

*Defined at line 77 of ./tier1/convar.cpp*

### SetString

*public void SetString(const char * s)*

*Defined at line 85 of ./tier1/convar.cpp*

### Set

*public void Set(const char * s)*

*Defined at line 91 of ./tier1/convar.cpp*

### SetBool

*public void SetBool(_Bool b)*

*Defined at line 97 of ./tier1/convar.cpp*

### Reset

*public void Reset()*

*Defined at line 103 of ./tier1/convar.cpp*

 Resets to default 

### Default

*public const char * Default()*

*Defined at line 37 of ./tier1/convar.h*

### Name

*public const char * Name()*

*Defined at line 38 of ./tier1/convar.h*

### Description

*public const char * Description()*

*Defined at line 39 of ./tier1/convar.h*

### Flags

*public unsigned int Flags()*

*Defined at line 40 of ./tier1/convar.h*

### RegisterAllCvars

*public void RegisterAllCvars()*

*Defined at line 17 of ./tier1/convar.cpp*



