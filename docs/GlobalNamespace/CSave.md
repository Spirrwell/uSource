# class CSave

*Defined at line 51 of ./game/server/saverestore.h*

 #include "saverestore.h"



Inherits from CSaveRestoreBuffer



## Functions

### CSave

*public void CSave(SAVERESTOREDATA * pdata)*

*Defined at line 54 of ./game/server/saverestore.h*

### WriteShort

*public void WriteShort(const char * pname, const short * value, int count)*

*Defined at line 1807 of ./game/server/util.cpp*

### WriteInt

*public void WriteInt(const char * pname, const int * value, int count)*

*Defined at line 1812 of ./game/server/util.cpp*

### WriteFloat

*public void WriteFloat(const char * pname, const float * value, int count)*

*Defined at line 1817 of ./game/server/util.cpp*

### WriteTime

*public void WriteTime(const char * pname, const float * value, int count)*

*Defined at line 1822 of ./game/server/util.cpp*

### WriteData

*public void WriteData(const char * pname, int size, const char * pdata)*

*Defined at line 1802 of ./game/server/util.cpp*

### WriteString

*public void WriteString(const char * pname, const char * pstring)*

*Defined at line 1842 of ./game/server/util.cpp*

### WriteString

*public void WriteString(const char * pname, const int * stringId, int count)*

*Defined at line 1852 of ./game/server/util.cpp*

### WriteVector

*public void WriteVector(const char * pname, const class Vector & value)*

*Defined at line 1877 of ./game/server/util.cpp*

### WriteVector

*public void WriteVector(const char * pname, const float * value, int count)*

*Defined at line 1882 of ./game/server/util.cpp*

### WritePositionVector

*public void WritePositionVector(const char * pname, const class Vector & value)*

*Defined at line 1888 of ./game/server/util.cpp*

### WritePositionVector

*public void WritePositionVector(const char * pname, const float * value, int count)*

*Defined at line 1899 of ./game/server/util.cpp*

### WriteFunction

*public void WriteFunction(const char * pname, void ** value, int count)*

*Defined at line 1917 of ./game/server/util.cpp*

### WriteEntVars

*public int WriteEntVars(const char * pname, entvars_t * pev)*

*Defined at line 1972 of ./game/server/util.cpp*

### WriteFields

*public int WriteFields(const char * pname, void * pBaseData, TYPEDESCRIPTION * pFields, int fieldCount)*

*Defined at line 1977 of ./game/server/util.cpp*

### DataEmpty

*private int DataEmpty(const char * pdata, int size)*

*Defined at line 2091 of ./game/server/util.cpp*

### BufferField

*private void BufferField(const char * pname, int size, const char * pdata)*

*Defined at line 2101 of ./game/server/util.cpp*

### BufferString

*private void BufferString(char * pdata, int len)*

*Defined at line 2083 of ./game/server/util.cpp*

### BufferData

*private void BufferData(const char * pdata, int size)*

*Defined at line 2116 of ./game/server/util.cpp*

### BufferHeader

*private void BufferHeader(const char * pname, int size)*

*Defined at line 2107 of ./game/server/util.cpp*



