# class CRestore

*Defined at line 86 of ./game/server/saverestore.h*

Inherits from CSaveRestoreBuffer



## Members

private int m_global

private BOOL m_precache



## Functions

### CRestore

*public void CRestore(SAVERESTOREDATA * pdata)*

*Defined at line 89 of ./game/server/saverestore.h*

### ReadEntVars

*public int ReadEntVars(const char * pname, entvars_t * pev)*

*Defined at line 2317 of ./game/server/util.cpp*

### ReadFields

*public int ReadFields(const char * pname, void * pBaseData, TYPEDESCRIPTION * pFields, int fieldCount)*

*Defined at line 2322 of ./game/server/util.cpp*

### ReadField

*public int ReadField(void * pBaseData, TYPEDESCRIPTION * pFields, int fieldCount, int startField, int size, char * pName, void * pData)*

*Defined at line 2138 of ./game/server/util.cpp*

 --------------------------------------------------------------

 CRestore

 --------------------------------------------------------------

### ReadInt

*public int ReadInt()*

*Defined at line 2383 of ./game/server/util.cpp*

### ReadShort

*public short ReadShort()*

*Defined at line 2374 of ./game/server/util.cpp*

### ReadNamedInt

*public int ReadNamedInt(const char * pName)*

*Defined at line 2392 of ./game/server/util.cpp*

### ReadNamedString

*public char * ReadNamedString(const char * pName)*

*Defined at line 2400 of ./game/server/util.cpp*

### Empty

*public int Empty()*

*Defined at line 97 of ./game/server/saverestore.h*

### SetGlobalMode

*public void SetGlobalMode(int global)*

*Defined at line 98 of ./game/server/saverestore.h*

### PrecacheMode

*public void PrecacheMode(BOOL mode)*

*Defined at line 99 of ./game/server/saverestore.h*

### BufferPointer

*private char * BufferPointer()*

*Defined at line 2412 of ./game/server/util.cpp*

### BufferReadBytes

*private void BufferReadBytes(char * pOutput, int size)*

*Defined at line 2420 of ./game/server/util.cpp*

### BufferSkipBytes

*private void BufferSkipBytes(int bytes)*

*Defined at line 2440 of ./game/server/util.cpp*

### BufferSkipZString

*private int BufferSkipZString()*

*Defined at line 2445 of ./game/server/util.cpp*

### BufferCheckZString

*private int BufferCheckZString(const char * string)*

*Defined at line 2467 of ./game/server/util.cpp*

### BufferReadHeader

*private void BufferReadHeader(HEADER * pheader)*

*Defined at line 2364 of ./game/server/util.cpp*



