# class CSaveRestoreBuffer

*Defined at line 22 of ./game/server/saverestore.h*

## Members

protected SAVERESTOREDATA * m_pdata



## Functions

### CSaveRestoreBuffer

*public void CSaveRestoreBuffer()*

*Defined at line 1641 of ./game/server/util.cpp*

 Base class includes common SAVERESTOREDATA pointer, and manages the entity table

### CSaveRestoreBuffer

*public void CSaveRestoreBuffer(SAVERESTOREDATA * pdata)*

*Defined at line 1646 of ./game/server/util.cpp*

### ~CSaveRestoreBuffer

*public void ~CSaveRestoreBuffer()*

*Defined at line 1651 of ./game/server/util.cpp*

### EntityIndex

*public int EntityIndex(entvars_t * pevLookup)*

*Defined at line 1662 of ./game/server/util.cpp*

### EntityIndex

*public int EntityIndex(edict_t * pentLookup)*

*Defined at line 1675 of ./game/server/util.cpp*

### EntityIndex

*public int EntityIndex(EOFFSET eoLookup)*

*Defined at line 1669 of ./game/server/util.cpp*

### EntityIndex

*public int EntityIndex(class CBaseEntity * pEntity)*

*Defined at line 1655 of ./game/server/util.cpp*

### EntityFlags

*public int EntityFlags(int entityIndex, int flags)*

*Defined at line 34 of ./game/server/saverestore.h*

### EntityFlagsSet

*public int EntityFlagsSet(int entityIndex, int flags)*

*Defined at line 1709 of ./game/server/util.cpp*

### EntityFromIndex

*public edict_t * EntityFromIndex(int entityIndex)*

*Defined at line 1692 of ./game/server/util.cpp*

### TokenHash

*public unsigned short TokenHash(const char * pszToken)*

*Defined at line 1766 of ./game/server/util.cpp*

### BufferRewind

*protected void BufferRewind(int size)*

*Defined at line 1721 of ./game/server/util.cpp*

### HashString

*protected unsigned int HashString(const char * pszToken)*

*Defined at line 1756 of ./game/server/util.cpp*

### operator=

*private void operator=(class CSaveRestoreBuffer & )*

 effc++ rule 11

### CSaveRestoreBuffer

*private void CSaveRestoreBuffer(const class CSaveRestoreBuffer & )*



