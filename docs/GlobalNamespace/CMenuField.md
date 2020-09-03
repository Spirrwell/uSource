# class CMenuField

*Defined at line 24 of ./mainui/controls/Field.h*

Inherits from CMenuEditable



## Members

public _Bool bAllowColorstrings

public _Bool bHideInput

public _Bool bNumbersOnly

public const char * szBackground

public int iMaxLength

private char [256] szBuffer

private int iCursor

private int iScroll

private int iRealWidth

private _Bool m_bOverrideOverstrike



## Functions

### CMenuField

*public void CMenuField()*

*Defined at line 23 of ./mainui/controls/Field.cpp*

### Init

*public void Init()*

*Defined at line 41 of ./mainui/controls/Field.cpp*

### VidInit

*public void VidInit()*

*Defined at line 54 of ./mainui/controls/Field.cpp*

=================CMenuField::Init=================

### KeyDown

*public _Bool KeyDown(int key)*

*Defined at line 139 of ./mainui/controls/Field.cpp*

=================CMenuField::Key=================

### Draw

*public void Draw()*

*Defined at line 376 of ./mainui/controls/Field.cpp*

=================CMenuField::Draw=================

### Char

*public void Char(int key)*

*Defined at line 279 of ./mainui/controls/Field.cpp*

=================CMenuField::Char=================

### UpdateEditable

*public void UpdateEditable()*

*Defined at line 544 of ./mainui/controls/Field.cpp*

### KeyValueData

*public _Bool KeyValueData(const char * key, const char * data)*

*Defined at line 554 of ./mainui/controls/Field.cpp*

### LinkCvar

*public void LinkCvar(const char * name)*

*Defined at line 38 of ./mainui/controls/Field.h*

### Paste

*public void Paste()*

*Defined at line 108 of ./mainui/controls/Field.cpp*

================CMenuField::Paste================

### Clear

*public void Clear()*

*Defined at line 127 of ./mainui/controls/Field.cpp*

================CMenuField::Clear================

### SetBuffer

*public void SetBuffer(const char * buffer)*

*Defined at line 46 of ./mainui/controls/Field.h*

### GetBuffer

*public const char * GetBuffer()*

*Defined at line 53 of ./mainui/controls/Field.h*

### _Event

*protected void _Event(int ev)*

*Defined at line 69 of ./mainui/controls/Field.cpp*

================CMenuField::_Event================



