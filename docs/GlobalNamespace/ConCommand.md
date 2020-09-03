# class ConCommand

*Defined at line 11 of ./tier1/concommand.h*

## Members

private const char *const name

private const char *const desc

private const unsigned int flags

private void (*)(void) command



## Functions

### ConCommand

*public void ConCommand(const char * _name, const char * _desc, unsigned int _flags, void (*)(void) _command)*

*Defined at line 7 of ./tier1/concommand.cpp*

### RegisterAllCommands

*public void RegisterAllCommands()*

*Defined at line 18 of ./tier1/concommand.cpp*



