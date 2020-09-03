# class CMenuEditable

*Defined at line 21 of ./mainui/controls/Editable.h*

Inherits from CMenuBaseItem



## Members

CEventCallback onCvarWrite

CEventCallback onCvarChange

CEventCallback onCvarGet

public _Bool bUpdateImmediately

protected const char * m_szCvarName

protected enum CMenuEditable::cvarType_e m_eType

protected _Bool m_bForceUpdate

protected char [64] m_szString

protected char [64] m_szOriginalString

protected float m_flValue

protected float m_flOriginalValue



## Functions

### CMenuEditable

*public void CMenuEditable()*

*Defined at line 18 of ./mainui/controls/Editable.cpp*

### Reload

*public void Reload()*

*Defined at line 43 of ./mainui/controls/Editable.cpp*

### UpdateEditable

*public void UpdateEditable()*

 Every derived class can define how it will work with cvars

### LinkCvar

*public void LinkCvar(const char * name, enum CMenuEditable::cvarType_e type)*

*Defined at line 31 of ./mainui/controls/Editable.cpp*

 setup editable

### CvarName

*public const char * CvarName()*

*Defined at line 43 of ./mainui/controls/Editable.h*

 Getters

### CvarValue

*public float CvarValue()*

*Defined at line 44 of ./mainui/controls/Editable.h*

### CvarString

*public const char * CvarString()*

*Defined at line 45 of ./mainui/controls/Editable.h*

### CvarType

*public enum CMenuEditable::cvarType_e CvarType()*

*Defined at line 46 of ./mainui/controls/Editable.h*

### SetCvarValue

*public void SetCvarValue(float value)*

*Defined at line 50 of ./mainui/controls/Editable.cpp*

 Set cvar value/string and emit an event(does not written to engine)

### SetCvarString

*public void SetCvarString(const char * string)*

*Defined at line 58 of ./mainui/controls/Editable.cpp*

### SetOriginalValue

*public void SetOriginalValue(float val)*

*Defined at line 79 of ./mainui/controls/Editable.cpp*

 Set last got engine cvar values

### SetOriginalString

*public void SetOriginalString(const char * psz)*

*Defined at line 70 of ./mainui/controls/Editable.cpp*

### ResetCvar

*public void ResetCvar()*

*Defined at line 126 of ./mainui/controls/Editable.cpp*

 Reset editable to last got engine values

### WriteCvar

*public void WriteCvar()*

*Defined at line 141 of ./mainui/controls/Editable.cpp*

 Send cvar value/string to engine

### DiscardChanges

*public void DiscardChanges()*

*Defined at line 135 of ./mainui/controls/Editable.cpp*

 Discard any changes and immediately send them to engine

### UpdateCvar

*public void UpdateCvar()*

*Defined at line 86 of ./mainui/controls/Editable.cpp*

 Update cvar values from engine

### WriteCvarCb

*public void WriteCvarCb(class CMenuBaseItem * pSelf, void * )*

*Defined at line 73 of ./mainui/controls/Editable.h*

### DiscardChangesCb

*public void DiscardChangesCb(class CMenuBaseItem * pSelf, void * )*

*Defined at line 74 of ./mainui/controls/Editable.h*

### ResetCvarCb

*public void ResetCvarCb(class CMenuBaseItem * pSelf, void * )*

*Defined at line 75 of ./mainui/controls/Editable.h*

### UpdateCvarCb

*public void UpdateCvarCb(class CMenuBaseItem * pSelf, void * )*

*Defined at line 76 of ./mainui/controls/Editable.h*

### LinkCvar

*private void LinkCvar(const char * name)*

*Defined at line 26 of ./mainui/controls/Editable.cpp*

 A possible shortcut for derived class, that support only one cvar type derived class can move it to public and implement



## Enums

| enum cvarType_e |

--

| CVAR_STRING |
| CVAR_VALUE |


*Defined at line 33 of ./mainui/controls/Editable.h*

 Engine allow only string and value cvars



